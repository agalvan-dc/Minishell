#!/usr/bin/env bash
# =========================================================================== #
#                MINISHELL -- HARD TEST BATTERY                               #
#                                                                             #
# Compares minishell against bash (stdout + stderr), checks exit-code         #
# encoding, interactive signals (pty), robustness and (with --vg) memory /    #
# fd leaks under valgrind.                                                    #
#                                                                             #
# Usage:  ./tests/hard_tests.sh [--vg] [--color|--no-color] [-v]              #
# =========================================================================== #

set -u
ulimit -c 0 2>/dev/null || true

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
MINI="$ROOT/minishell"
TESTS_DIR="$(cd "$(dirname "$0")" && pwd)"
CASES_FILE="$TESTS_DIR/hard_cases.txt"
PTY_SCRIPT="$TESTS_DIR/pty_signals.py"
SCRATCH="/tmp/minishell_hard"
VG=0
VERBOSE=0
COLOR="auto"

for a in "$@"; do
	case "$a" in
		--vg) VG=1 ;;
		-v) VERBOSE=1 ;;
		--color) COLOR="always" ;;
		--no-color) COLOR="never" ;;
		*) echo "unknown option: $a" >&2; exit 2 ;;
	esac
done

case "$COLOR" in
	always) USE_COLOR=1 ;;
	never) USE_COLOR=0 ;;
	*) [ -t 1 ] && [ -z "${NO_COLOR:-}" ] && USE_COLOR=1 || USE_COLOR=0 ;;
esac

if [ "$USE_COLOR" = "1" ]; then
	BOLD=$'\033[1m'; DIM=$'\033[2m'; RED=$'\033[1;31m'
	GREEN=$'\033[1;32m'; YELLOW=$'\033[1;33m'; CYAN=$'\033[1;36m'
	MAG=$'\033[1;35m'; RESET=$'\033[0m'
else
	BOLD=; DIM=; RED=; GREEN=; YELLOW=; CYAN=; MAG=; RESET=
fi

if [ ! -x "$MINI" ]; then
	printf "${RED}error:${RESET} %s not found (run 'make' first)\n" "$MINI" >&2
	exit 2
fi

PASS_N=0
FAIL_N=0
FAILED=""
CUR_SECTION=""

section() {
	CUR_SECTION="$1"
	printf "\n${BOLD}${CYAN}━━━ %s ${RESET}${DIM}────────────────────────────────────────────${RESET}\n" "$1"
}

pass() {
	PASS_N=$((PASS_N + 1))
	printf "  ${GREEN}✔${RESET} %-44s\n" "$1"
}

fail() {
	FAIL_N=$((FAIL_N + 1))
	FAILED="$FAILED $1"
	printf "  ${RED}✘${RESET} %-44s ${RED}%s${RESET}\n" "$1" "${2:-}"
}

info() {
	[ "$VERBOSE" = "1" ] && printf "  ${DIM}· %s${RESET}\n" "$1"
	return 0
}

# --------------------------------------------------------------------------- #
# Normalization                                                               #
# --------------------------------------------------------------------------- #
scrub() {
	sed "s|$1|DIR|g" | awk '
		/^\[Minishell\]\$ / { next }
		/^Exit$/          { next }
		/^exit$/          { next }
		{ print }
	'
}

scrub_err() {
	sed "s|$1|DIR|g" | awk '
		/^exit$/ { next }
		/Terminated/         { print "Terminated"; next }
		/Killed/             { print "Killed"; next }
		/Segmentation fault/ { print "Segmentation fault"; next }
		/Quit/               { print "Quit"; next }
		{
			sub(/^bash: line [0-9]+: /, "")
			sub(/^bash: /, "")
			sub(/^minishell: /, "")
			if ($0 != "") print
		}
	'
}

# --------------------------------------------------------------------------- #
# Case comparison vs bash                                                     #
# --------------------------------------------------------------------------- #
run_compare() {
	local case_file="$1" name dir
	name="$(basename "$case_file" .txt)"
	dir="$SCRATCH/$name"
	mkdir -p "$dir/mini" "$dir/bash"
	{ printf 'cd %s\n' "$dir/mini"; cat "$case_file"; } > "$dir/mini/in"
	{ printf 'cd %s\n' "$dir/bash"; cat "$case_file"; } > "$dir/bash/in"

	"$MINI" < "$dir/mini/in" > "$dir/mini/raw.out" 2> "$dir/mini/raw.err"
	bash < "$dir/bash/in" > "$dir/bash/raw.out" 2> "$dir/bash/raw.err"
	scrub "$dir/mini" < "$dir/mini/raw.out" > "$dir/mini/out"
	scrub "$dir/bash" < "$dir/bash/raw.out" > "$dir/bash/out"
	scrub_err "$dir/mini" < "$dir/mini/raw.err" > "$dir/mini/err"
	scrub_err "$dir/bash" < "$dir/bash/raw.err" > "$dir/bash/err"

	local ok=1
	diff -q "$dir/mini/out" "$dir/bash/out" >/dev/null 2>&1 || ok=0
	diff -q "$dir/mini/err" "$dir/bash/err" >/dev/null 2>&1 || ok=0

	if [ "$ok" = "1" ]; then
		pass "$name"
	else
		fail "$name" "output differs from bash"
		if [ "$VERBOSE" = "1" ]; then
			if ! diff -q "$dir/mini/out" "$dir/bash/out" >/dev/null 2>&1; then
				printf "    ${DIM}--- stdout (< bash  > minishell) ---${RESET}\n"
				diff -u "$dir/bash/out" "$dir/mini/out" | head -20 | sed 's/^/    /'
			fi
			if ! diff -q "$dir/mini/err" "$dir/bash/err" >/dev/null 2>&1; then
				printf "    ${DIM}--- stderr (< bash  > minishell) ---${RESET}\n"
				diff -u "$dir/bash/err" "$dir/mini/err" | head -20 | sed 's/^/    /'
			fi
		fi
	fi
	return 0
}

run_valgrind() {
	local case_file="$1" name dir
	name="$(basename "$case_file" .txt)"
	dir="$SCRATCH/$name"
	local log="$dir/vg.log"
	if valgrind --error-exitcode=42 --leak-check=full \
		--errors-for-leak-kinds=definite,indirect,possible \
		--track-fds=yes "$MINI" < "$dir/mini/in" \
		> /dev/null 2> "$log"; then
		if grep -qE "already closed|invalid file descriptor" "$log"; then
			fail "vg:$name" "closed fd twice / invalid fd"
		else
			pass "vg:$name"
		fi
	else
		fail "vg:$name" "valgrind errors/leaks (see $log)"
		grep -E "definitely lost|indirectly lost|possibly lost|already closed|ERROR SUMMARY" \
			"$log" | head -4 | sed 's/^/      /'
	fi
	return 0
}

# --------------------------------------------------------------------------- #
# Exit-code encoding                                                          #
# --------------------------------------------------------------------------- #
check_exit_code() {
	local name="$1" input="$2" want="$3"
	local st
	printf '%b' "$input" | "$MINI" >/dev/null 2>&1
	st=$?
	if [ "$st" = "$want" ]; then
		pass "$name"
	else
		fail "$name" "exit=$st want=$want"
	fi
}

check_exit_stderr() {
	local name="$1" input="$2" want="$3" needle="$4"
	local out
	out="$(printf '%b' "$input" | "$MINI" 2>&1 >/dev/null)"
	if printf '%s' "$out" | grep -qi "$needle"; then
		pass "$name"
	else
		fail "$name" "stderr lacks '$needle'"
		printf "      ${DIM}got: %s${RESET}\n" "$out"
	fi
}

check_exit_continues() {
	local name="$1"
	local out
	out="$(printf 'exit 1 2\necho AFTER\n' | "$MINI" 2>/dev/null)"
	if printf '%s' "$out" | grep -q "AFTER"; then
		pass "$name"
	else
		fail "$name" "shell did not continue after 'exit 1 2'"
	fi
}

check_echo_n() {
	local out
	out="$(printf 'echo -n hi\nexit\n' | "$MINI" 2>/dev/null | sed '1d')"
	if printf '%s' "$out" | grep -qF 'hi[Minishell]$'; then
		pass "echo -n (no trailing newline)"
	else
		fail "echo -n (no trailing newline)" "missing byte after prompt"
	fi
}

# --------------------------------------------------------------------------- #
# Interactive signals (pty)                                                   #
# --------------------------------------------------------------------------- #
run_signals() {
	if [ ! -f "$PTY_SCRIPT" ] || ! command -v python3 >/dev/null 2>&1; then
		fail "interactive signals" "python3/pty helper missing"
		return 0
	fi
	local line name verdict detail
	while IFS= read -r line; do
		verdict="${line%% *}"
		rest="${line#* }"
		name="${rest%% *}"
		detail="${rest#* }"
		[ "$detail" = "$rest" ] && detail=""
		if [ "$verdict" = "PASS" ]; then
			pass "$name"
		else
			fail "$name" "$detail"
		fi
	done < <(timeout 90 python3 "$PTY_SCRIPT" "$MINI")
}

# --------------------------------------------------------------------------- #
# Robustness (no crash)                                                       #
# --------------------------------------------------------------------------- #
run_no_crash() {
	local dir="$SCRATCH/no_crash"
	mkdir -p "$dir"
	local script="$dir/in"
	cat > "$script" <<-SCRIPT
	cd /
	cd /nonexistent_path_xyz
	pwd
	rm /nonexistent_file_xyz
	cd /tmp
	cat < /dev/null > $dir/a.txt
	rm -f $dir/a.txt
	nonexistent_zzz
	/a/b/c
	echo \$?
	cat << END
	unterminated heredoc without the delimiter so we hit EOF
	SCRIPT
	local out="$dir/out" st
	"$MINI" < "$script" > "$out" 2>&1
	st=$?
	if [ "$st" -lt 128 ] && ! grep -qiE "segmentation|core dumped|aborted" "$out"; then
		pass "no-crash hostile script"
	else
		fail "no-crash hostile script" "exit=$st"
	fi
}

# =========================================================================== #
#                                                                             #
# =========================================================================== #
printf "\n${BOLD}${MAG}╔══════════════════════════════════════════════════════════╗${RESET}\n"
printf "${BOLD}${MAG}║            MINISHELL  ·  HARD TEST BATTERY               ║${RESET}\n"
printf "${BOLD}${MAG}╚══════════════════════════════════════════════════════════╝${RESET}\n"

rm -rf "$SCRATCH"
mkdir -p "$SCRATCH/cases"

awk -v out="$SCRATCH/cases" '
	/^##### / { name = substr($0, 7); gsub(/[ \t]/, "", name); file = out "/" name ".txt"; next }
	file != "" { print > file }
' "$CASES_FILE"

CASES=("$SCRATCH/cases"/*.txt)

section "COMPARISON vs bash (stdout + stderr)"
for case_file in "${CASES[@]}"; do
	[ -e "$case_file" ] || continue
	run_compare "$case_file"
done

section "EXIT-CODE ENCODING"
check_exit_code "exit (no arg) -> 0"            'exit\n' 0
check_exit_code "exit 42 -> 42"                 'exit 42\n' 42
check_exit_code "exit 256 -> 0"                 'exit 256\n' 0
check_exit_code "exit 300 -> 44"                'exit 300\n' 44
check_exit_code "exit -1 -> 255"                'exit -1\n' 255
check_exit_code "exit 007 -> 7"                 'exit 007\n' 7
check_exit_stderr "exit abc -> numeric error"   'exit abc\n' 2 "numeric argument required"
check_exit_continues "exit 1 2 keeps running"
check_echo_n

section "INTERACTIVE SIGNALS (pty)"
run_signals

section "ROBUSTNESS"
run_no_crash

if [ "$VG" = "1" ]; then
	section "MEMORY / FD LEAKS (valgrind)"
	for case_file in "${CASES[@]}"; do
		[ -e "$case_file" ] || continue
		run_valgrind "$case_file"
	done
fi

TOTAL=$((PASS_N + FAIL_N))
printf "\n${BOLD}${CYAN}═══════════════════════  SUMMARY  ═══════════════════════${RESET}\n"
printf "  Tests run : ${BOLD}%d${RESET}\n" "$TOTAL"
printf "  Passed    : ${GREEN}%d${RESET}\n" "$PASS_N"
printf "  Failed    : ${RED}%d${RESET}\n" "$FAIL_N"
printf "${BOLD}${CYAN}══════════════════════════════════════════════════════════${RESET}\n"

if [ "$FAIL_N" != "0" ]; then
	printf "  ${RED}Failed:${RESET}%s\n" "$FAILED"
	exit 1
fi
printf "  ${GREEN}${BOLD}ALL GREEN ✔${RESET}\n"
exit 0
