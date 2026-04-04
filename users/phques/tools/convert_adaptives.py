#!/usr/bin/env python3
"""Convert JSON adaptive trigger pairs into QMK adaptive_3key_t/adaptive_2key_t tables.

Input format (stdin):
[
  ["mwm", "mpl"],
  ["wm", "lm"]
]

Output format:
const adaptive_3key_t adaptive_3keys[] = {
    {KC_M, KC_W, KC_M, "mpl"},
    {0, 0, 0, NULL}
};

const adaptive_2key_t adaptive_2keys[] = {
    {KC_W, KC_M, "lm"},
    {0, 0, NULL}
};

Rules:
- 3-char triggers are emitted into adaptive_3keys.
- 2-char triggers are emitted into adaptive_2keys.
- Warn if any 2-char trigger shares a prefix with a 3-char trigger.
"""

import json
import string
import sys
from typing import List, Tuple

SPECIAL = {
    ".": "KC_DOT",
    ",": "KC_COMMA",
    "/": "KC_SLASH",
    "=": "KC_EQUAL",
    '"': "KC_DQUO",
    "'": "KC_QUOTE",
    "#": "KC_HASH",
    "-": "KC_MINUS",
}

LETTERS = {c: f"KC_{c.upper()}" for c in string.ascii_lowercase}


def keycode_for_char(ch: str) -> str:
    c = ch.lower()
    if c in LETTERS:
        return LETTERS[c]
    if c in SPECIAL:
        return SPECIAL[c]
    raise ValueError(f"Unsupported key char: {ch!r}")


def c_escape(s: str) -> str:
    return s.replace("\\", "\\\\").replace('"', '\\"')


def mapping_comment(trigger: str, output: str) -> str:
    # Emit block comments to avoid C line-splice issues from trailing backslashes.
    safe_output = output.replace("\n", "\\n").replace("\r", "\\r").replace("*/", "* /")
    return f"/* {trigger} -> {safe_output} */"


def format_entry(entry: str, comment: str, width: int) -> str:
    return f"    {(entry + ',').ljust(width + 1)} {comment}"


def parse_rules(data) -> List[Tuple[str, str]]:
    if not isinstance(data, list):
        raise ValueError("Top-level JSON must be an array")

    parsed: List[Tuple[str, str]] = []
    for item in data:
        if not (isinstance(item, list) and len(item) == 2):
            raise ValueError(f"Each row must be [trigger, output], got: {item!r}")

        trig, out = item
        if not (isinstance(trig, str) and isinstance(out, str)):
            raise ValueError(f"Trigger and output must be strings, got: {item!r}")

        if len(trig) not in (2, 3):
            raise ValueError(f"Trigger must be length 2 or 3, got: {trig!r}")

        parsed.append((trig, out))

    return parsed


def emit_adaptive_tables(rules: List[Tuple[str, str]]) -> None:
    three_key = [(trig, out) for trig, out in rules if len(trig) == 3]
    two_key = [(trig, out) for trig, out in rules if len(trig) == 2]

    three_prefixes = {(trig[0], trig[1]) for trig, _ in three_key}
    three_entries = [
        (
            f'{{{keycode_for_char(trig[0])}, {keycode_for_char(trig[1])}, {keycode_for_char(trig[2])}, "{c_escape(out)}"}}',
            mapping_comment(trig, out),
        )
        for trig, out in three_key
    ]
    two_entries = [
        (
            f'{{{keycode_for_char(trig[0])}, {keycode_for_char(trig[1])}, "{c_escape(out)}"}}',
            mapping_comment(trig, out),
        )
        for trig, out in two_key
    ]
    three_width = max((len(entry) for entry, _ in three_entries), default=0)
    two_width = max((len(entry) for entry, _ in two_entries), default=0)

    print("// Auto-generated adaptive key tables. Do not edit directly.")
    print("#include <quantum.h>\n")
    print("#include \"../../processAdaptive.h\"\n")
    print("const adaptive_3key_t adaptive_3keys[] PROGMEM = {")

    for entry, comment in three_entries:
        print(format_entry(entry, comment, three_width))

    print("    {0, 0, 0, NULL}")
    print("};")
    print("")

    print("const adaptive_2key_t adaptive_2keys[] PROGMEM = {")
    for entry, comment in two_entries:
        print(format_entry(entry, comment, two_width))

    print("    {0, 0, NULL}")
    print("};")

    conflicts = [(trig, out) for trig, out in two_key if (trig[0], trig[1]) in three_prefixes]
    if conflicts:
        print("", file=sys.stderr)
        print("WARNING: Shared-prefix conflicts found:", file=sys.stderr)
        for trig, out in conflicts:
            print(
                f"  2-key trigger {trig!r} -> {out!r} shares prefix with a 3-key trigger.",
                file=sys.stderr,
            )


def main() -> int:
    try:
        data = json.load(sys.stdin)
        rules = parse_rules(data)
        emit_adaptive_tables(rules)
    except Exception as exc:  # keep CLI output simple for shell usage
        print(f"Error: {exc}", file=sys.stderr)
        return 1

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
