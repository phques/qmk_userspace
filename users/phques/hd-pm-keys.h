#pragma once

// From HandsDown Promethium keymap, adapted for use in my keymaps as a layer of keycodes

//
// First, let's define HD alpha keycodes with any hold-taps/custom keycodes
//
// PQ note: mods are CAGS as in moutis HandsDown. i.e. MacOS standard Cmd=GUI, Opt=ALT, Ctrl=Ctrl, Shift=Shift
#define HD_A RSFT_T(KC_A)
#define HD_B KC_B
#define HD_C RCTL_T(KC_C)
#define HD_D KC_D
#define HD_E RGUI_T(KC_E)
#define HD_F KC_F   //LT(L_FUN, KC_F)
#define HD_G KC_G
#define HD_H LSFT_T(KC_H)
#define HD_I RALT_T(KC_I)
#define HD_J KC_J
#define HD_K KC_K   //LT(L_NUM,KC_K)
#define HD_L KC_L
#define HD_M KC_M
#define HD_N LALT_T(KC_N)
#define HD_O KC_O
#define HD_P KC_P
#define HD_Q KC_Q
#define HD_R KC_R   //LT(L_NAV,KC_R)
#define HD_S LCTL_T(KC_S)
#define HD_T LGUI_T(KC_T)
#define HD_U KC_U
#define HD_V KC_V
#define HD_W KC_W
#define HD_X KC_X
#define HD_Y KC_Y
#define HD_Z KC_Z

#define HD_MINS KC_MINS
#define HD_HASH KC_HASH
#define HD_SPC  KC_SPC  // LT(L_SYM,KC_SPC)
#define HD_BSPC KC_BSPC // LT(L_FUN,KC_BSPC)
#define HD_ENT  KC_ENT  // LT(L_NAV,KC_ENT)
#define HD_QUOT KC_QUOT
#define HD_DQUO KC_DQUO
#define HD_SLSH KC_SLSH
#define HD_DOT  KC_DOT
#define HD_ASTR KC_ASTR
#define HD_COMM KC_COMM


// Now let's place these HD keycodes on the keymap
// for variation independent spatial referencing by key position
//
//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTA │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
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
//    Base (alpha) Layer  Hands Down Promethium (HRMs /+ thumb mods)
//      this is canonical Promethium, "inverted" (top-bottom), as
//      I prefer "bottom heavy" layouts.  If you prefer top heavy,
//      be sure to invert all rows, as the rolling/scissoring characteristics
//      that make Promethium what it is depend on the same-row neighbors
//  ※ arguably, the inner column is less sensitive to this.
//            ╭─────────────────────╮                 ╭─────────────────────╮
//   Caps     │  V   W   G   M   J  │                 │  #$  .:  /*  "[  '] │ {   }
//    esc     │  S   N   T   H   K  |      Paste      |  ,;   A   E   I   C │ Z
//    tab     │  F   P   D   L   X  │      Copy       │  -+   U   O   Y   B │ Q
//            ╰───────────╮  R  bsp │                 │ ret  spc ╭──────────╯
//                        ╰─────────╯                 ╰──────────╯
//
// For small boards, Q (LT3) & Z (LT4) are (also) on the sym layer
// and accessible combos (defined below)
//

#define HD_LT5 KC_CAPS
#define HD_LT4 HD_V
#define HD_LT3 HD_W
#define HD_LT2 HD_G
#define HD_LT1 HD_M
#define HD_LT0 HD_J
#define HD_LTA KC_NO  // PQ xbows nature, was LT(L_CFG, KC_MUTE)
#define HD_RTA KC_NO  // PQ xbows nature, was LT(L_CFG, KC_MPLY)
#define HD_RT0 HD_HASH
#define HD_RT1 HD_DOT
#define HD_RT2 HD_SLSH
#define HD_RT3 HD_DQUO
#define HD_RT4 HD_QUOT
#define HD_RT5 KC_LNG2

#define HD_LM5 KC_ESC
#define HD_LM4 HD_S
#define HD_LM3 HD_N
#define HD_LM2 HD_T
#define HD_LM1 HD_H
#define HD_LM0 HD_K
#define HD_LMA G(KC_V) //PQ xbows nature, was KC_RPRN
#define HD_RMA KC_NO  // PQ xbows nature, was KC_LPRN
#define HD_RM0 HD_COMM
#define HD_RM1 HD_A
#define HD_RM2 HD_E
#define HD_RM3 HD_I
#define HD_RM4 HD_C
#define HD_RM5 KC_Z

#define HD_LB5 KC_TAB
#define HD_LB4 HD_F
#define HD_LB3 HD_P
#define HD_LB2 HD_D
#define HD_LB1 HD_L
#define HD_LB0 HD_X
#define HD_LBA G(KC_C)  // PQ xbows nature
#define HD_LBB KC_NO    // PQ xbows nature
#define HD_RBB KC_NO    // PQ xbows nature
#define HD_RBA KC_NO    // PQ xbows nature
#define HD_RB0 HD_MINS
#define HD_RB1 HD_U
#define HD_RB2 HD_O
#define HD_RB3 HD_Y
#define HD_RB4 HD_B
#define HD_RB5 HD_Q

//Primary Thumbs 1-3 (others are unique to the board)
#define HD_LH5 KC_LCTL  // PQ xbows nature
#define HD_LH4 KC_LGUI  // PQ xbows nature
#define HD_LH3 KC_LALT  // PQ xbows nature
#define HD_LH2 HD_R
#define HD_LH1 HD_BSPC
#define HD_LH0 KC_NO
#define HD_LHA KC_NO

#define HD_RHA KC_NO
#define HD_RH0 KC_NO
#define HD_RH1 HD_ENT
#define HD_RH2 HD_SPC
#define HD_RH3 KC_RALT      // PQ xbows nature
#define HD_RH4 MO(L_CFG)    // PQ xbows nature, Keep Fn key as access to CFG layer
#define HD_RH5 KC_RCTL
