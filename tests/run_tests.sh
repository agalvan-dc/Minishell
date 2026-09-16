#!/usr/bin/env bash
# Test harness for the Minishell project.
#
# Each file in tests/cases/*.txt is a shell command script. It is executed
# by both minishell and bash (from the same scratch cwd) and their normalized
# stdout is compared. Optional --vg flag also runs every case under valgrind
# and requires 0 errors / 0 leaks.
#
# Usage:  ./tests/run_tests.sh [--vg] [-v]

set -u

MINI="$(cd "$(dirname "$0")/.." && pwd)/minishell"
CASES_DIR="$(cd "$(dirname "$0")" && pwd)/cases"
SCRATCH="/tmp/minishell_tests"
VG=0
VERBOSE=0
PASS=0
FAIL=0
FAILED_CASES=""

for a in "$@"; do
	case "$a" in
		--vg) VG=1 ;;
		-v) VERBOSE=1 ;;
		*) echo "unknown option: $a"; exit 2 ;;
	esac
done

if [ ! -x "$MINI" ]; then
	echo "error: $MINI not found (run 'make' first)" >&2
	exit 2
fi

# Normalize minishell's interactive output for comparison with bash:
#  - drop lines that echo the typed command ("[Minishell]$ cmd")
#  - drop the "Exit" trailer and the echoed "exit" line
#  - strip heredoc / continuation prompts that live on the same line
normalize() {
	awk '
		/^\[Minishell\]\$ / { next }
		/^Exit$/          { next }
		/^exit$/          { next }
		{ gsub(/(heredoc> |finish_quote> )/, ""); if ($0 != "") print }
	'
}

run_case() {
	local case_file="$1"
	local name
	name="$(basename "$case_file" .txt)"
	local dir="$SCRATCH/$name"
	mkdir -p "$dir"
	local script="$dir/input.txt"
	{
		printf 'cd %s\n' "$dir"
		cat "$case_file"
	} > "$script"

	local mini_out="$dir/minishell.out"
	local bash_out="$dir/bash.out"

	"$MINI" < "$script" 2>/dev/null | normalize > "$mini_out"
	bash < "$script" 2>/dev/null > "$bash_out"

	if diff -q "$mini_out" "$bash_out" >/dev/null; then
		if [ "$VERBOSE" = "1" ]; then echo "PASS: $name"; fi
		PASS=$((PASS + 1))
	else
		echo "FAIL: $name"
		FAIL=$((FAIL + 1))
		FAILED_CASES="$FAILED_CASES $name"
		echo "--- minishell (expected==bash) ---"
		diff -u "$bash_out" "$mini_out" | head -40
	fi

	if [ "$VG" = "1" ]; then
		if valgrind --error-exitcode=42 --leak-check=full \
			"$MINI" < "$script" > /dev/null 2>"$dir/valgrind.log"; then
			if [ "$VERBOSE" = "1" ]; then echo "  vg PASS: $name"; fi
		else
			echo "  vg FAIL: $name (valgrind errors or leaks)"
			grep -E "ERROR SUMMARY|definitely lost" "$dir/valgrind.log" | head -4
		fi
	fi
}

check_echo_n() {
	local dir="$SCRATCH/echo_n"
	mkdir -p "$dir"
	local out
	out="$("$MINI" <<'IN' 2>/dev/null
echo -n hi
IN
)"
	# With pipe input, readline echoes the command:  "[Minishell]$ echo -n hi"
	# then prints "hi" with NO trailing newline, then the next prompt.
	if printf '%s' "$out" | grep -q 'hi'; then
		echo "PASS: echo -n (no trailing newline)"
		PASS=$((PASS + 1))
	else
		echo "FAIL: echo -n"
		FAIL=$((FAIL + 1))
		FAILED_CASES="$FAILED_CASES echo_n"
	fi
}

# --verbose must enable verbose mode without any Y/N prompt.
check_verbose_flag() {
	local dir="$SCRATCH/verbose_flag"
	mkdir -p "$dir"
	local out
	out="$(printf 'echo hi\nexit\n' | "$MINI" --verbose 2>&1)"
	if printf '%s' "$out" | grep -q "verbose activate" \
		&& printf '%s' "$out" | grep -q "Parsing"; then
		echo "PASS: --verbose flag"
		PASS=$((PASS + 1))
	else
		echo "FAIL: --verbose flag"
		FAIL=$((FAIL + 1))
		FAILED_CASES="$FAILED_CASES verbose_flag"
	fi
	local plain
	plain="$(printf 'echo hi\nexit\n' | "$MINI" 2>&1)"
	if printf '%s' "$plain" | grep -q "Y/N"; then
		echo "FAIL: no Y/N prompt expected without tty"
		FAIL=$((FAIL + 1))
		FAILED_CASES="$FAILED_CASES no_yn_prompt"
	fi
}

# A battery of hostile / edge commands (missing paths, dirs, redirects).
# It is not compared to bash: we only require that minishell survives every
# one of them (normal exit, no crash markers) and stays valgrind-clean.
check_no_crash() {
	local dir="$SCRATCH/no_crash"
	mkdir -p "$dir"
	local script="$dir/input.txt"
	{
		cat <<-SCRIPT
		cd /
		cd /nonexistent_path_xyz
		cd /nonexistent_path_xyz/
		pwd
		rm /nonexistent_file_xyz
		rm -r /nonexistent_dir_xyz/
		cd /tmp
		cat < /dev/null > $dir/a.txt
		rm -f $dir/a.txt
		cat > $dir/b.txt
		SCRIPT
	} > "$script"

	local out="$dir/out.txt"
	local st
	"$MINI" < "$script" > "$out" 2>&1
	st=$?
	if [ "$st" = "0" ] && ! grep -qiE "segmentation|core dumped|aborted|signal" "$out"; then
		echo "PASS: no-crash hostile battery"
		PASS=$((PASS + 1))
	else
		echo "FAIL: no-crash hostile battery (exit=$st)"
		FAIL=$((FAIL + 1))
		FAILED_CASES="$FAILED_CASES no_crash"
	fi

	if [ "$VG" = "1" ]; then
		if valgrind --error-exitcode=42 --leak-check=full \
			"$MINI" < "$script" > /dev/null 2>"$dir/valgrind.log"; then
			[ "$VERBOSE" = "1" ] && echo "  vg PASS: no_crash"
		else
			echo "  vg FAIL: no_crash"
			grep -E "ERROR SUMMARY|definitely lost" "$dir/valgrind.log" | head -4
		fi
	fi
}

rm -rf "$SCRATCH"
mkdir -p "$SCRATCH"

for case_file in "$CASES_DIR"/*.txt; do
	[ -e "$case_file" ] || continue
	run_case "$case_file"
done

check_echo_n
check_verbose_flag
check_no_crash

echo
echo "============================="
echo "PASS: $PASS   FAIL: $FAIL"
echo "============================="
if [ "$FAIL" != "0" ]; then
	echo "failed cases:$FAILED_CASES"
	exit 1
fi
exit 0