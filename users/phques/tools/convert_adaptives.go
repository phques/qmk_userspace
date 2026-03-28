package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"os"
	"sort"
	"strings"
)

type ruleRow []string

type rule struct {
	trigger string
	output  string
}

var special = map[rune]string{
	'.':  "KC_DOT",
	'/':  "KC_SLASH",
	'"':  "KC_DQUO",
	'\'': "KC_QUOTE",
	'#':  "KC_HASH",
}

func keycodeForChar(ch rune) (string, error) {
	lower := ch
	if 'A' <= lower && lower <= 'Z' {
		lower = lower - 'A' + 'a'
	}

	if 'a' <= lower && lower <= 'z' {
		return "KC_" + strings.ToUpper(string(lower)), nil
	}

	if kc, ok := special[lower]; ok {
		return kc, nil
	}

	return "", fmt.Errorf("unsupported key char: %q", string(ch))
}

func cEscape(s string) string {
	s = strings.ReplaceAll(s, "\\", "\\\\")
	s = strings.ReplaceAll(s, "\"", "\\\"")
	return s
}

func mappingComment(trigger, output string) string {
	return fmt.Sprintf("// %s -> %s", trigger, output)
}

func formatEntry(entry, comment string, width int) string {
	withComma := entry + ","
	if len(withComma) < width+1 {
		withComma += strings.Repeat(" ", width+1-len(withComma))
	}
	return "    " + withComma + " " + comment
}

func parseRules(r io.Reader) ([]rule, error) {
	var data []ruleRow
	dec := json.NewDecoder(bufio.NewReader(r))
	if err := dec.Decode(&data); err != nil {
		return nil, err
	}

	parsed := make([]rule, 0, len(data))
	for _, item := range data {
		if len(item) != 2 {
			return nil, fmt.Errorf("each row must be [trigger, output], got: %v", item)
		}

		trig := item[0]
		out := item[1]

		if len(trig) != 2 && len(trig) != 3 {
			return nil, fmt.Errorf("trigger must be length 2 or 3, got: %q", trig)
		}

		parsed = append(parsed, rule{trigger: trig, output: out})
	}

	return parsed, nil
}

func emitAdaptiveTables(rules []rule, w io.Writer, errw io.Writer) error {
	threeKey := make([]rule, 0)
	twoKey := make([]rule, 0)

	for _, r := range rules {
		if len(r.trigger) == 3 {
			threeKey = append(threeKey, r)
		} else {
			twoKey = append(twoKey, r)
		}
	}

	type formatted struct {
		entry   string
		comment string
	}

	threePrefixes := make(map[string]struct{}, len(threeKey))
	threeEntries := make([]formatted, 0, len(threeKey))
	twoEntries := make([]formatted, 0, len(twoKey))

	for _, r := range threeKey {
		a := []rune(r.trigger)
		if len(a) != 3 {
			return fmt.Errorf("trigger must be 3 chars: %q", r.trigger)
		}

		kc0, err := keycodeForChar(a[0])
		if err != nil {
			return err
		}
		kc1, err := keycodeForChar(a[1])
		if err != nil {
			return err
		}
		kc2, err := keycodeForChar(a[2])
		if err != nil {
			return err
		}

		threePrefixes[string(a[0])+"\x00"+string(a[1])] = struct{}{}
		threeEntries = append(threeEntries, formatted{
			entry:   fmt.Sprintf("{%s, %s, %s, \"%s\"}", kc0, kc1, kc2, cEscape(r.output)),
			comment: mappingComment(r.trigger, r.output),
		})
	}

	for _, r := range twoKey {
		a := []rune(r.trigger)
		if len(a) != 2 {
			return fmt.Errorf("trigger must be 2 chars: %q", r.trigger)
		}

		kc0, err := keycodeForChar(a[0])
		if err != nil {
			return err
		}
		kc1, err := keycodeForChar(a[1])
		if err != nil {
			return err
		}

		twoEntries = append(twoEntries, formatted{
			entry:   fmt.Sprintf("{%s, %s, \"%s\"}", kc0, kc1, cEscape(r.output)),
			comment: mappingComment(r.trigger, r.output),
		})
	}

	threeWidth := 0
	for _, e := range threeEntries {
		if len(e.entry) > threeWidth {
			threeWidth = len(e.entry)
		}
	}

	twoWidth := 0
	for _, e := range twoEntries {
		if len(e.entry) > twoWidth {
			twoWidth = len(e.entry)
		}
	}

	out := bufio.NewWriter(w)
	defer out.Flush()

	fmt.Fprintln(out, "// Auto-generated adaptive key tables. Do not edit directly.")
	fmt.Fprintln(out, "#include <quantum.h>")
	fmt.Fprintln(out)
	fmt.Fprintln(out, "#include \"../../processAdaptive.h\"")
	fmt.Fprintln(out)
	fmt.Fprintln(out, "const adaptive_3key_t adaptive_3keys[] PROGMEM = {")

	for _, e := range threeEntries {
		fmt.Fprintln(out, formatEntry(e.entry, e.comment, threeWidth))
	}

	fmt.Fprintln(out, "    {0, 0, 0, NULL}")
	fmt.Fprintln(out, "};")
	fmt.Fprintln(out)

	fmt.Fprintln(out, "const adaptive_2key_t adaptive_2keys[] PROGMEM = {")
	for _, e := range twoEntries {
		fmt.Fprintln(out, formatEntry(e.entry, e.comment, twoWidth))
	}

	fmt.Fprintln(out, "    {0, 0, NULL}")
	fmt.Fprintln(out, "};")

	conflicts := make([]rule, 0)
	for _, r := range twoKey {
		a := []rune(r.trigger)
		if len(a) != 2 {
			continue
		}
		if _, ok := threePrefixes[string(a[0])+"\x00"+string(a[1])]; ok {
			conflicts = append(conflicts, r)
		}
	}

	if len(conflicts) > 0 {
		sort.Slice(conflicts, func(i, j int) bool {
			return conflicts[i].trigger < conflicts[j].trigger
		})

		fmt.Fprintln(errw)
		fmt.Fprintln(errw, "WARNING: Shared-prefix conflicts found:")
		for _, r := range conflicts {
			fmt.Fprintf(errw, "  2-key trigger %q -> %q shares prefix with a 3-key trigger.\n", r.trigger, r.output)
		}
	}

	return nil
}

func main() {
	rules, err := parseRules(os.Stdin)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Error: %v\n", err)
		os.Exit(1)
	}

	if err := emitAdaptiveTables(rules, os.Stdout, os.Stderr); err != nil {
		fmt.Fprintf(os.Stderr, "Error: %v\n", err)
		os.Exit(1)
	}
}
