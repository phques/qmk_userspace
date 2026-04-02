// ** Taken from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)
#pragma once

#include "phques.h"
#include "semantickeys.h"

//     Key Position Names for a 34 (-54) key split form factor
//        Should cover ergo boards Ferris through Atreus-Kyria-Ergodox
//        and orthos like plank and Naked48
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTB │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5

// LH5, LH4 are also Left encoder CCW, CW
// RH5, RH4 are also Right encoder CCW, CW

/*  L_SYM Symbols and punctuation (Some via SemKeys/unicode for platform independance)
 *  left paired symbols are "linger keys" via hold taps. Tap for left, hold for pair with insertion point between
   ╭────────────────────────────────────────────╮                  ╭──────────────────────────────────────────╮
__ │    Z       Q       ¶        †        ‡     │                  │     ¢        $       #(€)    \(£)    ¥   │ __
__ │    :       [       (        {        •     |                  |     /        =       *       +       -   │ __
__ │    °      ]       )        }         ·     │ __  __   __  __  │     ^        |       &       <       >   │ __
   ╰──────────────────╮ VolD   D_WordL  D_WordR │ --           __  │     _        ¡       ¿     ╭─────────────╯
   KC_PGDN   KC_PGUP  ╰─────────────────────────╯                  ╰────────────────────────────╯ SK_WORDPRV  SK_WORDNXT
*/

#define LS_LT5 KC_TRNS
#define LS_LT4 KC_Z
#define LS_LT3 KC_Q
#define LS_LT2 SK_PARA // ¶
#define LS_LT1 SK_SCRS // †
#define LS_LT0 SK_DCRS // ‡
#define LS_RT0 SK_CENT // ¢
#define LS_RT1 KC_DLR  // $
#define LS_RT2 HD_HASH //PQ SK_EURO €
#define LS_RT3 KC_BSLS //PQ SK_BPND £
#define LS_RT4 SK_JPY  // ¥
#define LS_RT5 KC_TRNS

#define LS_LM5 KC_TRNS
#define LS_LM4 KC_COLN // :   was SK_SECT // §
#define LS_LM3 KC_LBRC
#define LS_LM2 KC_LPRN
#define LS_LM1 KC_LCBR
#define LS_LM0 SK_BBLT // SK_BLLT?
#define LS_LMA KC_NO
#define LS_RM0 KC_PSLS // /
#define LS_RM1 RSFT_T(KC_EQL)  //pq KC_PEQL not working on my Windows RSFT_T(KC_PEQL) // RSFT_T(KC_PAST)
#define LS_RM2 RGUI_T(KC_PAST) // RGUI_T(KC_PEQL)
#define LS_RM3 RALT_T(KC_PPLS)
#define LS_RM4 RCTL_T(KC_PMNS) // RCTL_T(KC_PSLS)
#define LS_RM5 KC_TRNS

#define LS_LB5 KC_TRNS
#define LS_LB4 SK_DEGR // °
#define LS_LB3 KC_RBRC
#define LS_LB2 KC_RPRN
#define LS_LB1 KC_RCBR
#define LS_LB0 SK_SBLT  // ·
#define LS_LBA KC_TRNS
#define LS_LBB KC_TRNS
#define LS_RBB KC_TRNS
#define LS_RBA KC_TRNS
#define LS_RB0 KC_CIRC // ^ // KC_UNDS
#define LS_RB1 KC_PIPE // |
#define LS_RB2 KC_AMPR
#define LS_RB3 KC_LT // KC_CIRC
#define LS_RB4 KC_GT // KC_PERC
#define LS_RB5 KC_TRNS

#define LS_LH5 KC_PGDN // also left encoder CCW
#define LS_LH4 KC_PGUP // also left encoder CW
#define LS_LH3 KC_MUTE
#define LS_LH2 SK_DELWDL
#define LS_LH1 SK_DELWDR
#define LS_LH0 KC_VOLD   // also left encoder hat switch
#define LS_LHA KC_VOLD
#define LS_RHA KC_VOLU
#define LS_RH0 KC_VOLU   // also right encoder hat switch
#define LS_RH1 KC_UNDS // _
#define LS_RH2 KC_TRNS  // PQ layer access key, leave trans, was SK_IEXC // ¡
#define LS_RH3 KC_RALT      // PQ xbows nature, was SK_IQUE // ¿
#define LS_RH4 SK_WORDPRV // also right encoder CCW
#define LS_RH5 SK_WORDNXT // also right encoder CW

