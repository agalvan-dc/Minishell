#!/usr/bin/env python3
"""Interactive (pty) signal tests for minishell.

Usage: pty_signals.py /path/to/minishell
Prints one line per test:  PASS <name>  |  FAIL <name>: <reason>
Exit code is the number of failed tests (0 == all good).
"""

import fcntl
import os
import pty
import re
import select
import signal
import struct
import sys
import termios
import time

PROMPT = b"[Minishell]$ "
TIMEOUT = 4.0


class Shell:
    """A minishell process attached to a pseudo-terminal."""

    def __init__(self, path):
        self.pid, self.fd = pty.fork()
        if self.pid == 0:
            os.environ["TERM"] = "xterm"
            try:
                os.execv(path, [path])
            except OSError:
                os._exit(127)
        fcntl.ioctl(self.fd, termios.TIOCSWINSZ,
                    struct.pack("HHHH", 40, 120, 0, 0))
        self.buf = b""

    def _read_some(self, timeout):
        if timeout < 0:
            timeout = 0
        try:
            ready, _, _ = select.select([self.fd], [], [], timeout)
        except (OSError, ValueError):
            return False
        if not ready:
            return False
        try:
            data = os.read(self.fd, 4096)
        except OSError:
            return False
        if not data:
            return False
        self.buf += data
        return True

    def expect(self, needle, timeout=TIMEOUT):
        if isinstance(needle, str):
            needle = needle.encode()
        end = time.time() + timeout
        while needle not in self.buf:
            left = end - time.time()
            if left <= 0 or not self._read_some(left):
                return False
        return True

    def expect_prompt(self, timeout=TIMEOUT):
        self.buf = b""
        return self.expect(PROMPT, timeout)

    def expect_status(self, wanted, timeout=TIMEOUT):
        """Type `echo STATUS=$?` and return the reported status (int|None)."""
        self.buf = b""
        self.send("echo STATUS=$?\n")
        end = time.time() + timeout
        while time.time() < end:
            m = re.search(rb"STATUS=(-?\d+)", self.buf)
            if m:
                return int(m.group(1))
            if not self._read_some(end - time.time()):
                time.sleep(0.01)
        m = re.search(rb"STATUS=(-?\d+)", self.buf)
        return int(m.group(1)) if m else None

    def send(self, data):
        if isinstance(data, str):
            data = data.encode()
        os.write(self.fd, data)

    def wait(self, timeout=TIMEOUT):
        end = time.time() + timeout
        while time.time() < end:
            try:
                pid, status = os.waitpid(self.pid, os.WNOHANG)
            except ChildProcessError:
                return 0
            if pid == self.pid:
                return status
            time.sleep(0.02)
        return None

    def alive(self):
        try:
            pid, _ = os.waitpid(self.pid, os.WNOHANG)
        except ChildProcessError:
            return False
        return pid == 0

    def close(self):
        try:
            os.kill(self.pid, signal.SIGKILL)
        except OSError:
            pass
        try:
            os.waitpid(self.pid, 0)
        except OSError:
            pass
        try:
            os.close(self.fd)
        except OSError:
            pass


# --------------------------------------------------------------------------- #
# Tests
# --------------------------------------------------------------------------- #
def t_prompt(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send("exit\n")
        st = sh.wait()
        if st is None:
            return False, "shell did not exit on `exit`"
        return True, ""
    finally:
        sh.close()


def t_ctrl_c_prompt_alive(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send(b"\x03")
        if not sh.expect_prompt():
            return False, "no fresh prompt after Ctrl-C"
        if not sh.alive():
            return False, "shell died on Ctrl-C"
        return True, ""
    finally:
        sh.close()


def t_ctrl_c_prompt_status(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send(b"\x03")
        if not sh.expect_prompt():
            return False, "no fresh prompt after Ctrl-C"
        st = sh.expect_status(130)
        if st != 130:
            return False, f"$? after Ctrl-C is {st}, want 130"
        return True, ""
    finally:
        sh.close()


def t_ctrl_backslash_prompt(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send(b"\x1c")
        time.sleep(0.2)
        if not sh.alive():
            return False, "shell died on Ctrl-\\"
        sh.buf = b""
        sh.send("echo QUIT_ALIVE\n")
        if not sh.expect(b"QUIT_ALIVE"):
            return False, "shell did not run command after Ctrl-\\"
        return True, ""
    finally:
        sh.close()


def t_ctrl_c_sleep(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send("sleep 30\n")
        time.sleep(0.5)
        t0 = time.time()
        sh.send(b"\x03")
        if not sh.expect_prompt():
            return False, "no prompt after interrupting sleep"
        elapsed = time.time() - t0
        if elapsed > 2.5:
            return False, f"sleep was not interrupted ({elapsed:.1f}s)"
        st = sh.expect_status(130)
        if st != 130:
            return False, f"$? after SIGINT on child is {st}, want 130"
        return True, ""
    finally:
        sh.close()


def t_ctrl_backslash_sleep(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send("sleep 30\n")
        time.sleep(0.5)
        sh.send(b"\x1c")
        if not sh.expect_prompt():
            return False, "no prompt after interrupting sleep"
        st = sh.expect_status(131)
        if st != 131:
            return False, f"$? after SIGQUIT on child is {st}, want 131"
        return True, ""
    finally:
        sh.close()


def t_ctrl_d_exit(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send(b"\x04")
        st = sh.wait()
        if st is None:
            return False, "shell did not exit on Ctrl-D"
        return True, ""
    finally:
        sh.close()


def t_ctrl_c_cat(mini):
    sh = Shell(mini)
    try:
        if not sh.expect_prompt():
            return False, "no initial prompt"
        sh.send("cat\n")
        time.sleep(0.4)
        sh.send(b"\x03")
        if not sh.expect_prompt():
            return False, "no prompt after interrupting cat"
        if not sh.alive():
            return False, "shell died after Ctrl-C on cat"
        return True, ""
    finally:
        sh.close()


TESTS = [
    ("prompt", t_prompt),
    ("ctrl_c_at_prompt_alive", t_ctrl_c_prompt_alive),
    ("ctrl_c_at_prompt_status_130", t_ctrl_c_prompt_status),
    ("ctrl_backslash_at_prompt", t_ctrl_backslash_prompt),
    ("ctrl_c_interrupts_sleep", t_ctrl_c_sleep),
    ("ctrl_backslash_interrupts_sleep", t_ctrl_backslash_sleep),
    ("ctrl_d_exits", t_ctrl_d_exit),
    ("ctrl_c_interrupts_cat", t_ctrl_c_cat),
]


def main():
    if len(sys.argv) != 2:
        print("usage: pty_signals.py <minishell>", file=sys.stderr)
        return 2
    mini = sys.argv[1]
    failures = 0
    for name, fn in TESTS:
        try:
            ok, reason = fn(mini)
        except Exception as exc:  # noqa: BLE001
            ok, reason = False, f"exception: {exc!r}"
        if ok:
            print(f"PASS {name}")
        else:
            failures += 1
            print(f"FAIL {name}: {reason}")
    return failures


if __name__ == "__main__":
    sys.exit(main())
