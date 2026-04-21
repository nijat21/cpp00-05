#!/bin/bash

# ============================================================
#  Test suite for ./replace  (ex04 – Sed is for losers)
#  Usage: ./run_tests.sh          (from the project root)
#
#  Each test is fully self-contained:
#    name | input content | s1 | s2 | expected output
#
#  For traceability, each run writes:
#    tests/inputs/<name>          ← the input fed to the program
#    tests/outputs/<name>.replace ← the actual output produced
# ============================================================

EXECUTABLE="./replace"
INPUT_DIR="tests/inputs"
OUTPUT_DIR="tests/outputs"
PASS=0
FAIL=0
TOTAL=0

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'

pass()    { echo -e "  ${GREEN}✓ PASS${RESET}  $1"; ((PASS++)); ((TOTAL++)); }
fail()    { echo -e "  ${RED}✗ FAIL${RESET}  $1"; ((FAIL++)); ((TOTAL++)); }
section() { echo -e "\n${CYAN}${BOLD}▶ $1${RESET}"; }

mkdir -p "$INPUT_DIR" "$OUTPUT_DIR"

# ---------------------------------------------------------------------------
# check FILENAME INPUT S1 S2 EXPECTED
#
#   Writes INPUT to tests/inputs/FILENAME, runs ./replace FILENAME S1 S2,
#   moves the output to tests/outputs/FILENAME.replace, then compares
#   against EXPECTED.
#
#   At a glance you can see: what went in, what was searched/replaced,
#   and what should come out — without opening any file.
# ---------------------------------------------------------------------------
check() {
    local filename="$1"
    local input="$2"
    local s1="$3"
    local s2="$4"
    local expected="$5"

    local infile="${INPUT_DIR}/${filename}"
    local outfile="${INPUT_DIR}/${filename}.replace"
    local dest="${OUTPUT_DIR}/${filename}.replace"

    # Write the input file fresh each run
    printf '%s' "$input" > "$infile"
    rm -f "$outfile" "$dest"

    "$EXECUTABLE" "$infile" "$s1" "$s2" >/dev/null 2>&1
    local exit_code=$?

    if [[ ! -f "$outfile" ]]; then
        fail "$filename  (no output file created, exit=${exit_code})"
        return
    fi

    mv "$outfile" "$dest"

    local actual
    actual=$(cat "$dest")
    if [[ "$actual" == "$expected" ]]; then
        pass "$filename"
    else
        fail "$filename"
        echo -e "      ${YELLOW}input:   ${RESET} $(printf '%s' "$input"    | cat -v)"
        echo -e "      ${YELLOW}s1→s2:   ${RESET} '${s1}' → '${s2}'"
        echo -e "      ${YELLOW}expected:${RESET} $(printf '%s' "$expected" | cat -v)"
        echo -e "      ${YELLOW}got:     ${RESET} $(printf '%s' "$actual"   | cat -v)"
    fi
}

# ---------------------------------------------------------------------------
# check_error NAME [args...]
#   Asserts the program exits non-zero and leaves no .replace file behind.
# ---------------------------------------------------------------------------
check_error() {
    local filename="$1"; shift
    local replace_file=""
    [[ -n "$1" ]] && replace_file="${1}.replace"

    "$EXECUTABLE" "$@" >/dev/null 2>&1
    local exit_code=$?

    if [[ $exit_code -ne 0 ]]; then
        if [[ -n "$replace_file" && -f "$replace_file" ]]; then
            fail "$filename  (exit=${exit_code} but .replace file was still created)"
            rm -f "$replace_file"
        else
            pass "$filename  (exit=${exit_code})"
        fi
    else
        fail "$filename  (expected non-zero exit, got 0)"
    fi
}

# ── error cases ──────────────────────────────────────────────────────────────

section "1. Wrong number of arguments"
check_error "no_args"
check_error "one_arg"    "somefile"
check_error "two_args"   "somefile"  "s1"
check_error "four_args"  "somefile"  "s1"  "s2"  "extra"

section "2. File errors"
check_error "nonexistent_file"   "${INPUT_DIR}/does_not_exist"  "a"  "b"

printf 'secret' > "${INPUT_DIR}/no_read_permission"
chmod 000 "${INPUT_DIR}/no_read_permission"
check_error "unreadable_file"    "${INPUT_DIR}/no_read_permission"  "a"  "b"
chmod 644  "${INPUT_DIR}/no_read_permission"

section "3. Empty s1 (must be rejected)"
check_error "empty_s1"  "${INPUT_DIR}/no_read_permission"  ""  "x"

# ── normal cases ─────────────────────────────────────────────────────────────
#         NAME                         INPUT                            S1              S2           EXPECTED

section "4. Basic replacement"
check  basic_single_occurrence        "hello world"                    "world"         "earth"      "hello earth"
check  basic_longer_replacement       "hello world"                    "hello"         "greetings"  "greetings world"
check  basic_shorter_replacement      "hello world"                    "world"         "C++"        "hello C++"

section "5. Multiple occurrences"
check  multi_same_line                "foo foo foo"                    "foo"           "bar"        "bar bar bar"
check  multi_multiline                "$(printf 'line1 foo\nline2 foo\nline3 bar')" \
                                                                       "foo"           "baz"        "$(printf 'line1 baz\nline2 baz\nline3 bar')"

section "6. No match – file copied verbatim"
check  no_match                       "nothing to replace here"        "xyz"           "abc"        "nothing to replace here"

section "7. Deletion (s2 is empty)"
check  delete_one_word                "remove this word please"        "this "         ""           "remove word please"
# "foo foo foo": step1→"foo foo", step2→"foo", step3→no match  ⇒  "foo"
check  delete_all_occurrences         "foo foo foo"                    "foo "          ""           "foo"

section "8. s1 is prefix of s2 – must not loop"
# "aa": pos0 'a'→"aa" skip 2, pos0 'a'→"aa" skip 2  ⇒  "aaaa"
check  no_loop_prefix_short           "aa"                             "a"             "aa"         "aaaa"
check  no_loop_prefix_long            "foo foo foo"                    "foo"           "foobar"     "foobar foobar foobar"

section "9. Empty file"
check  empty_file                     ""                               "foo"           "bar"        ""

section "10. Repeated / back-to-back pattern"
# "abababab" → ab→X  non-overlapping left-to-right  ⇒  "XXXX"
check  repeated_ab                    "abababab"                       "ab"            "X"          "XXXX"
# "aaa" → aa→b: match at 0 → "b", leftover "a" → no match  ⇒  "ba"
check  repeated_aaa                   "aaa"                            "aa"            "b"          "ba"

section "11. Multiword and special characters"
check  special_multiword              "say hello world today"          "hello world"   "hi"         "say hi today"
check  special_dollar                 "cost: 100\$"                    "100"           "200"        "cost: 200\$"

section "12. Prose end-to-end"
check  prose_fox \
    "$(printf 'The quick brown fox jumps over the lazy dog.\nThe fox was very quick.')" \
    "fox"  "cat" \
    "$(printf 'The quick brown cat jumps over the lazy dog.\nThe cat was very quick.')"

# ── summary ──────────────────────────────────────────────────────────────────
echo ""
echo -e "${BOLD}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
echo -e "  Results: ${GREEN}${PASS} passed${RESET}  ${RED}${FAIL} failed${RESET}  (${TOTAL} total)"
echo -e "${BOLD}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RESET}"
if [[ $FAIL -eq 0 ]]; then
    echo -e "  ${GREEN}${BOLD}All tests passed 🎉${RESET}"
else
    echo -e "  ${RED}${BOLD}${FAIL} test(s) failed ✗${RESET}"
fi
echo ""
echo -e "  Inspect any pair:"
echo -e "    diff ${INPUT_DIR}/<name>  ${OUTPUT_DIR}/<name>.replace"
echo ""
exit $FAIL