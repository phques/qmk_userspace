#pragma once
// Sunlight layout key definitions.
// Original: https://cyanophage.github.io/index.html#sunlight
// https://cyanophage.github.io/playground.html?layout=vwhgq%3D.%2F%2C%27zsnltk%3Baeicxfbmdj-uoyp%5Cr&mode=ergo&lan=english&thumb=l

#include <keycodes.h>
#include "semantickeys.h"

//
// First, let's define HD alpha keycodes with any hold-taps/custom keycodes
//
// PQ note: mods are CAGS as in moutis HandsDown. i.e. MacOS standard Cmd=GUI, Opt=ALT, Ctrl=Ctrl, Shift=Shift

// ## HD_ALPHA definitions

#define HD_F KC_F
#define HD_W KC_W
#define HD_H KC_H
#define HD_G KC_G
#define HD_K KC_K
#define HD_S LCTL_T(KC_S)
#define HD_N LALT_T(KC_N)
#define HD_L LGUI_T(KC_L)
#define HD_T LSFT_T(KC_T)
#define HD_V KC_V
#define HD_X KC_X
#define HD_B KC_B
#define HD_M KC_M
#define HD_D KC_D
#define HD_Q KC_Q
#define HD_R LT(L_NAV, KC_R)

#define HD_MINS KC_MINUS
#define HD_SPC LT(L_SYM, KC_SPC)
#define HD_BSPC LT(L_FUN, KC_BSPC)
#define HD_ENT LT(L_NAV, KC_ENT)
#define HD_QUOT KC_QUOTE
#define HD_SLSH KC_SLASH
#define HD_DOT KC_DOT
#define HD_COMM KC_COMMA
#define HD_SCLN KC_SCLN
#define HD_EQL KC_EQUAL
#define HD_HASH KC_HASH
#define HD_DQUO KC_DQUO
#define HD_A RSFT_T(KC_A)
#define HD_E RGUI_T(KC_E)
#define HD_I RALT_T(KC_I)
#define HD_C RCTL_T(KC_C)
#define HD_O KC_O
#define HD_U KC_U
#define HD_Y KC_Y
#define HD_P KC_P
#define HD_Z KC_Z
#define HD_J KC_J

// Now let's place these HD keycodes on the keymap
// for variation independent spatial referencing by key position
//
//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTA │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RM0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5
//
// NB: on xbows nature, 'LH', (thumb keys) is bottom row, physically fits like this:
//
// LB5   │ LB4    LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
// LH5   │ LH4    --LH3-- --LH2-- │ LH1          RH1 │ --RH2-- --RH3-- RH4   RH5
// L_CTRL  L_GUI  L_ALT   L_SPC    Ctrl        Shift   R_SPC   R_ALT   Fn    R_CTRL
//
//  Base (alpha) Layer  Sunlight (HRMs /+ thumb mods)
/*
              ╭─────────────────────╮                 ╭─────────────────────╮
      Caps    │  V   W   H   G   Q  │                 │  #$  .:  / *  ,; '> │ Z
      Esc     │  S   N   L   T   K  |      Paste      |  "<   A   E   I   C │ X
      LSHFT   │  F   B   M   D   J  │      Copy       │  -+   U   O   Y   P │ RSHFT
              ╰───────────╮  R  bsp │                 │ ret  spc ╭──────────╯
                          ╰─────────╯                 ╰──────────╯
*/

// ## HD_LTx definitions

#define HD_LT4 HD_V
#define HD_LT3 HD_W
#define HD_LT2 HD_H
#define HD_LT1 HD_G
#define HD_LT0 HD_Q

#define HD_LM4 HD_S
#define HD_LM3 HD_N
#define HD_LM2 HD_L
#define HD_LM1 HD_T
#define HD_LM0 HD_K

#define HD_LB4 HD_F
#define HD_LB3 HD_B
#define HD_LB2 HD_M
#define HD_LB1 HD_D
#define HD_LB0 HD_J

// the middle extra keys
#define HD_LMA SK_PSTE // PQ xbows nature
#define HD_LBA SK_COPY // PQ xbows nature

// the other outlying '5' keys (ie LT5 etc)
#define HD_LT5 KC_CAPS
#define HD_LM5 KC_ESC
#define HD_LB5 KC_LSFT

#define HD_LTA KC_NO // PQ xbows nature
#define HD_RTA KC_NO // PQ xbows nature

#define HD_RT0 HD_HASH
#define HD_RT1 HD_DOT
#define HD_RT2 HD_SLSH
#define HD_RT3 HD_COMM
#define HD_RT4 HD_QUOT
#define HD_RT5 HD_Z

#define HD_RM0 HD_DQUO
#define HD_RM1 HD_A
#define HD_RM2 HD_E
#define HD_RM3 HD_I
#define HD_RM4 HD_C
#define HD_RM5 HD_X

#define HD_RB0 HD_MINS
#define HD_RB1 HD_U
#define HD_RB2 HD_O
#define HD_RB3 HD_Y
#define HD_RB4 HD_P
#define HD_RB5 KC_RSFT

#define HD_RMA KC_NO // PQ xbows nature

#define HD_LBB KC_NO // PQ xbows nature
#define HD_RBB KC_NO // PQ xbows nature
#define HD_RBA KC_NO // PQ xbows nature

// Primary Thumbs 1-3 (others are unique to the board)
#define HD_LH5 SK_LCTL // PQ xbows nature
#define HD_LH4 SK_LGUI // PQ xbows nature
#define HD_LH3 KC_LALT // PQ xbows nature
#define HD_LH2 HD_R
#define HD_LH1 HD_BSPC
#define HD_LH0 KC_NO
#define HD_LHA KC_NO

#define HD_RHA KC_NO
#define HD_RH0 KC_NO
#define HD_RH1 HD_ENT
#define HD_RH2 HD_SPC
#define HD_RH3 KC_RALT   // PQ xbows nature
#define HD_RH4 MO(L_CFG) // PQ xbows nature, Keep Fn key as access to CFG layer
#define HD_RH5 SK_RCTL

// ##PQ copied from HD PM, probably need some adjustments.

//
// We want to be able to define a combo by location
// for variation independent, spatial referencing, or
// by letter for mnemonic/phonetic referencing (variation dependent)
// but this sort of obscures the definitions…so…
//
// BE CAREFUL to not double define a combo!
//
// Combo definitions that rely on phonetics/mnemonics for their locations.
//
// Combos that are spacially organized don't need to be redefined
// to match the base alpha layer, so they are not included here.
//
// These few spatial combos may move to accommodate some mnemonic combos,
// notably the H-digraph combos that inhabit close areas.
//
// SEMANTIC FUNCTIONS  ** uses SemKeys **
// Spatially arranged on the QWERTY ZXCV locations
// independent of the HD Alphas, though since some of
// the above combos may compete for the same locations,
// we'll define them all here.
//
#ifdef COMBO_ENABLE

#    define HD_new_keys HD_LB0, HD_LM0          // new -- Since cmd/ctrl is on middle
#    define HD_open_keys HD_RB0, HD_RM0         // open -- these must be 2 handed, so combo
#    define HD_close_keys HD_RT0, HD_RM0        // close -- not strictly necessary?
#    define HD_quit_keys HD_LT0, HD_LM0         // quit -- because q is on symbol layer
#    define HD_find_keys HD_LM4, HD_LM0         // find selection
#    define HD_sall_keys HD_LB4, HD_LB1         // select all
#    define HD_swrd_keys HD_LB4, HD_LB0         // select word
#    define HD_undo_keys HD_LB4, HD_LB3         // undo
#    define HD_redo_keys HD_LB4, HD_LB3, HD_LB2 // redo
#    define HD_copy_keys HD_LB3, HD_LB2         // copy (hold for cut)
#    define HD_pste_keys HD_LB2, HD_LB1         // paste (hold for paste-match)

#    define HD_tab_keys HD_LT4, HD_LT3          // tab
#    define HD_stab_keys HD_LT4, HD_LT3, HD_LT2 // Shift-tab
#    define HD_spc_keys HD_LM1, HD_LM0          // SPACE
#    define HD_ent_keys HD_LB0, HD_LB1          // ENTER
#    define HD_ent2_keys HD_LB0, HD_LB1, HD_LB2 // hard-ENTER/page break
#    define APPMENU_keys HD_LT1, HD_LT0         // APPMENU on alpha layer
#    define APPMENU_nav_keys LV_LT1, LV_LT0     // APPMENU on Nav layer

// TEXT ENTRY - off map standard alphas (also on Layer L_SYM @ Z=LT4 & Q=LT3)
//
#    define HD_Qu_keys HD_LT3, HD_LT1 // TYPE "q" (Qu & Linger deletes u)
#    define HD_L1_keys HD_LM3, HD_LM1 // ex. TYPE "z"
#    define HD_L1 HD_Z
// #define HD_L2_keys HD_LM3, HD_LM1 // ex. TYPE "x"
// #define HD_L2 HD_X
// #define HD_L3_keys HD_LM3, HD_LM1 // ex. TYPE "j"
// #define HD_L3 HD_J

#    define HD_Ing_keys HD_I, HD_N // TYPE "ing"
//
// H digraph combos -- strictly optional! In fact,
// Promethium was designed to maximize H digraph rolling,
// and thereby reduce demand for the combos.
// try to make these use the lead letter and a neighbor.
// (listed here in order of frequency as per Mayzner: https://norvig.com/mayzner.html)
//
#    define HD_Th_keys HD_LM2, HD_LM1 // TYPE "th"
#    ifndef EN_PRONOUN_COMBOS
#        define HD_Ch_keys HD_RM3, HD_RM4 // TYPE "ch" // same as "I" HD_Icap_keys
#    else
#        define HD_Ch_keys HD_LM3, HD_LM2 // TYPE "ch" // so keep as in Vibranium
#    endif
#    define HD_Wh_keys HD_LT3, HD_LT2 // TYPE "wh"
#    define HD_Sh_keys HD_LM4, HD_LM3 // TYPE "sh"
#    ifndef EN_PRONOUN_COMBOS
#        define HD_Ph_keys HD_RB3, HD_RB4 // TYPE "ph" // default position
#    else
#        define HD_Ph_keys HD_LB3, HD_LB1 // TYPE "ph"  // keep as in Vibranium
#    endif
#    define HD_Gh_keys HD_LT2, HD_LT1          // TYPE "gh"
#    define HD_Sch_keys HD_LM4, HD_LM3, HD_LM2 // TYPE "Sch"

// Should we put all the diacritic keys here?
// or get keep them all in the common area (if they all share
// HD Neu vowel block)?
#    define HD_OE_lig_keys HD_RM2, HD_RB2 // Œ
#    define HD_AE_lig_keys HD_RM1, HD_RB1 // Æ

#    ifdef EN_PRONOUN_COMBOS
// the entirely unnecessary pronoun combo shenanigans

// PRONOUNS Fast 4-7grams
#        define HD_Icap_keys HD_I, HD_C // TYPE "I"
#        define HD_Id_keys HD_I, HD_D   // TYPE "I'd"+"'ve "
#        define HD_Ill_keys HD_I, HD_L  // TYPE "I'll"+"'ve "
#        define HD_Im_keys HD_I, HD_M   // TYPE "I'm "
#        define HD_Iv_keys HD_I, HD_V   // TYPE "I've "

#        ifdef EN_PRONOUN_COMBOS_ALL         // Admittedly of questionable value
#            define HD_youd_keys HD_Y, HD_D  // TYPE "you'd" + 've
#            define HD_youll_keys HD_Y, HD_L // TYPE "you'll" + 've
#            define HD_youre_keys HD_Y, HD_F // TYPE "you're"
#            define HD_youve_keys HD_Y, HD_V // TYPE "you've"
#            define HD_your_keys HD_Y, HD_R  // TYPE "your"

#            define HD_their_keys HD_T, HD_H  // TYPE "their" #6 (R on same finger in Neu)
#            define HD_theyre_keys HD_T, HD_F // "they're"  (R on same finger in Neu)
#            define HD_they_keys HD_T, HD_W   // "they" #23 + 've (near they)
#            define HD_theyll_keys HD_T, HD_M // "they'll" #23 + 've (M is easier to combo, also in We'll)
// PQ DUP! #define HD_theyd_keys HD_T, HD_F  // "they'd" #23 + 've (no rationale for this, but no SFCombo)
#            define HD_theyd_keys HD_T, HD_B // "they'd" #23 + 've (no rationale for this, but no SFCombo)

// deictics. Are these really necessary? (never used them regularly)
// PQ #define HD_there_keys HD_T, HD_F  // TYPE "there" #7 + 's
#            define HD_there_keys HD_T, HD_R // TYPE "there" #7 + 's
#            define HD_here_keys HD_H, HD_R  // TYPE "here" #5 + 's

#            ifdef EN_W_PRONOUNS
#                define HD_where_keys HD_V, HD_R   // "where" + 's
#                define HD_were_keys HD_V, HD_QUOT // TYPE "we're"
#                define HD_wed_keys HD_V, HD_D     // TYPE "we'd" + 've
#                define HD_well_keys HD_V, HD_L    // TYPE "we'll" + 've
#                define HD_weve_keys HD_V, HD_G    // TYPE "we've"
#            endif                                 // EN_W_PRONOUNS

#        endif // EN_PRONOUNS_ALL
#    endif     // EN_PRONOUNS // the entirely unnecessary pronoun combo shenanigans

#endif // COMBO_ENABLE
