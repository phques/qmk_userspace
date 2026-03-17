// ** Taken from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)
#pragma once

#include "phques.h"
#include "semantickeys.h"


/* L_FUN LAYER K-key row (left) and Num row (right)
         ╭──────────────────────────────────────────╮               ╭──────────────────────────────────────────╮
 RM_TOGG │ F13      F7      F8      F9      F10     │               │ /       7       8       9       -        │ RM_NEXT
 RM_VALU │ C_T(F14) A_T(F1) G_T(F2) S_T(F3) F11     |               | *       S_T(1)  G_T(2)  A_T(3)  C_T(+)   │ RM_HUEU
 RM_VALD │ F15      F4      F5      F6      F12     │ __ __   __ __ │ ,       4       5       6       =        │ RM_HUED
         ╰────────────────╮ __      __      INS     │ __         __ │ 0       .       TG(LN)  ╭────────────────╯
              __      __  ╰─────────────────────────╯               ╰─────────────────────────╯ __       __
*/

#define LF_LT5 RM_TOGG // was RGB_TOG
#define LF_LT4 KC_F13
#define LF_LT3 KC_F7
#define LF_LT2 KC_F8
#define LF_LT1 KC_F9
#define LF_LT0 KC_F10
#define LF_RT0 KC_SLSH
#define LF_RT1 KC_7
#define LF_RT2 KC_8
#define LF_RT3 KC_9
#define LF_RT4 KC_MINS
#define LF_RT5 RM_NEXT // was RGB_MOD

#define LF_LM5 RM_VALU // was RGB_VAI
#define LF_LM4 LCTL_T(KC_F14)
#define LF_LM3 LALT_T(KC_F1)
#define LF_LM2 LGUI_T(KC_F2)
#define LF_LM1 LSFT_T(KC_F3)
#define LF_LM0 KC_F11
#define LF_LMA KC_NO
#define LF_RM0 KC_ASTR
#define LF_RM1 RSFT_T(KC_1)
#define LF_RM2 RGUI_T(KC_2)
#define LF_RM3 RALT_T(KC_3)
#define LF_RM4 RCTL_T(KC_PPLS)
#define LF_RM5 RM_HUEU // was RGB_HUI

#define LF_LB5 RM_VALD // was RGB_VAD
#define LF_LB4 KC_F15
#define LF_LB3 KC_F4
#define LF_LB2 KC_F5
#define LF_LB1 KC_F3
#define LF_LB0 KC_F12
#define LF_LBA KC_TRNS
#define LF_LBB KC_TRNS
#define LF_RBB KC_TRNS
#define LF_RBA KC_TRNS
#define LF_RB0 KC_COMM
#define LF_RB1 KC_4
#define LF_RB2 KC_5
#define LF_RB3 KC_6
#define LF_RB4 KC_EQL
#define LF_RB5 RM_HUED // was RGB_HUD

#define LF_LH5 KC_F23 // also left encoder CCW
#define LF_LH4 KC_F24 // also left encoder CW
#define LF_LH3 KC_TRNS
#define LF_LH2 KC_SCLN
#define LF_LH1 KC_TRNS  // PQ layer access key, leave trans, was TG(L_NUM)
#define LF_LH0 KC_INS  // also left encoder hat switch
#define LF_LHA KC_NO
#define LF_RHA KC_NO
#define LF_RH0 KC_TRNS  // also right encoder hat switch
#define LF_RH1 KC_0
#define LF_RH2 KC_DOT
#define LF_RH3 KC_TRNS
#define LF_RH4 KC_MPRV // also right encoder CCW
#define LF_RH5 KC_MNXT // also right encoder CW

