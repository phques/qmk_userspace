module main

import json
import os

struct Rule {
	trigger string
	output  string
}

const special = {
	rune(`.`): 'KC_DOT'
	rune(`/`): 'KC_SLASH'
	rune(`"`): 'KC_DQUO'
	rune(`'`): 'KC_QUOTE'
	rune(`#`): 'KC_HASH'
}

fn keycode_for_char(ch rune) !string {
	mut lower := ch
	if lower >= `A` && lower <= `Z` {
		lower = lower + (`a` - `A`)
	}

	if lower >= `a` && lower <= `z` {
		return 'KC_' + lower.str().to_upper()
	}

	if lower in special {
		return special[lower]
	}

	return error("unsupported key char: '${ch.str()}'")
}

fn c_escape(s string) string {
	return s.replace('\\', '\\\\').replace('"', '\\"')
}

fn mapping_comment(trigger string, output string) string {
	return '// ${trigger} -> ${output}'
}

fn format_entry(entry string, comment string, width int) string {
	mut with_comma := entry + ','
	if with_comma.len < width + 1 {
		with_comma += ' '.repeat(width + 1 - with_comma.len)
	}
	return '    ${with_comma} ${comment}'
}

fn parse_rules(input string) ![]Rule {
	data := json.decode([][]string, input)!
	mut parsed := []Rule{}

	for item in data {
		if item.len != 2 {
			return error('each row must be [trigger, output], got: ${item}')
		}

		trig := item[0]
		out := item[1]
		trig_len := trig.runes().len

		if trig_len != 2 && trig_len != 3 {
			return error("trigger must be length 2 or 3, got: '${trig}'")
		}

		parsed << Rule{
			trigger: trig
			output:  out
		}
	}

	return parsed
}

fn emit_adaptive_tables(rules []Rule) ! {
	mut three_key := []Rule{}
	mut two_key := []Rule{}

	for r in rules {
		if r.trigger.runes().len == 3 {
			three_key << r
		} else {
			two_key << r
		}
	}

	mut three_prefixes := map[string]bool{}
	mut three_entries := []string{}
	mut three_comments := []string{}
	mut two_entries := []string{}
	mut two_comments := []string{}

	for r in three_key {
		a := r.trigger.runes()
		if a.len != 3 {
			return error("trigger must be 3 chars: '${r.trigger}'")
		}

		kc0 := keycode_for_char(a[0])!
		kc1 := keycode_for_char(a[1])!
		kc2 := keycode_for_char(a[2])!

		three_prefixes['${a[0].str()}\x00${a[1].str()}'] = true
		three_entries << '{${kc0}, ${kc1}, ${kc2}, "${c_escape(r.output)}"}'
		three_comments << mapping_comment(r.trigger, r.output)
	}

	for r in two_key {
		a := r.trigger.runes()
		if a.len != 2 {
			return error("trigger must be 2 chars: '${r.trigger}'")
		}

		kc0 := keycode_for_char(a[0])!
		kc1 := keycode_for_char(a[1])!

		two_entries << '{${kc0}, ${kc1}, "${c_escape(r.output)}"}'
		two_comments << mapping_comment(r.trigger, r.output)
	}

	mut three_width := 0
	for entry in three_entries {
		if entry.len > three_width {
			three_width = entry.len
		}
	}

	mut two_width := 0
	for entry in two_entries {
		if entry.len > two_width {
			two_width = entry.len
		}
	}

	println('// Auto-generated adaptive key tables. Do not edit directly.')
	println('#include <quantum.h>')
	println('')
	println('#include "../../processAdaptive.h"')
	println('')
	println('const adaptive_3key_t adaptive_3keys[] PROGMEM = {')

	for i, entry in three_entries {
		println(format_entry(entry, three_comments[i], three_width))
	}

	println('    {0, 0, 0, NULL}')
	println('};')
	println('')

	println('const adaptive_2key_t adaptive_2keys[] PROGMEM = {')
	for i, entry in two_entries {
		println(format_entry(entry, two_comments[i], two_width))
	}

	println('    {0, 0, NULL}')
	println('};')

	mut conflicts := []Rule{}
	for r in two_key {
		a := r.trigger.runes()
		if a.len != 2 {
			continue
		}
		if '${a[0].str()}\x00${a[1].str()}' in three_prefixes {
			conflicts << r
		}
	}

	if conflicts.len > 0 {
		eprintln('')
		eprintln('WARNING: Shared-prefix conflicts found:')
		for r in conflicts {
			eprintln('  2-key trigger "${r.trigger}" -> "${r.output}" shares prefix with a 3-key trigger.')
		}
	}
}

fn main() {
	input := os.get_raw_lines_joined()
	rules := parse_rules(input) or {
		eprintln('Error: ${err.msg()}')
		exit(1)
	}

	emit_adaptive_tables(rules) or {
		eprintln('Error: ${err.msg()}')
		exit(1)
	}
}
