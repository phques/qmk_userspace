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
// NB: on xbows nature, 'LH', (thumb keys) is bottom row, physically fits like this:
//
// LB5   │ LB4    LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
// LH5   │ LH4    --LH3-- --LH2-- │ LH1          RH1 │ --RH2-- --RH3-- RH4   RH5
// L_CTRL  L_GUI  L_ALT   L_SPC    Ctrl        Shift   R_SPC   R_ALT   Fn    R_CTRL

/*   L_CFG Keyboard Configuration (left) and Media Settings (right)
         ╭───────────────────────────────────────────────╮                ╭────────────────────────────────────────────────╮
 RM_TOGG │  Tab     SK_Win  SK_Mac  QK_RBT      SK_KILL  │                │ SK_ZOOMRST KC_NUM  KC_EJCT KC_LALT (C(A(del))) │ RM_NEXT
 RM_HUEU │  HD_AKTg L_0     L_1     KC_VOLU     KC_BRIU  |     RM_VALU    | SK_ZOOMOUT KC_MPRV KC_MUTE KC_MNXT EE_CLR      │ RM_SATU
 RM_HUED │  QK_BOOT AG_SWAP AG_NORM KC_VOLD     KC_BRID  │     RM_VALD    │ SK_ZOOMIN  KC_MRWD KC_MPLY KC_MFFD QK_BOOT     │ RM_SATD
         ╰──────────────────╮ MUTE  SK_ZOOMOUT SK_ZOOMIN │                │ SK_ZOOMIN  SK_ZOOMOUT  --  ╭───────────────────╯
            RM_SPDD RM_SPDU ╰────────────────────────────╯                ╰────────────────────────────╯   __     __
*/

#define LC_LT5 RM_TOGG
#define LC_LT4 KC_TAB    //SK_Lux
#define LC_LT3 SK_Win
#define LC_LT2 SK_Mac
#define LC_LT1 QK_RBT
#define LC_LT0 SK_KILL
#define LC_RT0 SK_ZOOMRST
#define LC_RT1 KC_NUM
#define LC_RT2 KC_EJCT
#define LC_RT3 KC_LALT
#define LC_RT4 LCA(KC_DEL)
#define LC_RT5 RM_NEXT // was RGB_MOD

#define LC_LM5 RM_HUEU // was RGB_VAI
#define LC_LM4 HD_AdaptKeyToggle
#ifdef HAS_QWERTY_LAYER
#define LC_LM3 HD_L_QWERTY
#define LC_LM2 HD_L_ALPHA
#else  // Only one base alpha, so no switch base layer
#define LC_LM3 KC_NO
#define LC_LM2 KC_NO
#endif
#define LC_LM1 KC_VOLU
#define LC_LM0 KC_BRIU
#define LC_LMA RM_VALU
#define LC_RM0 SK_ZOOMOUT
#define LC_RM1 KC_MPRV
#define LC_RM2 KC_MUTE
#define LC_RM3 KC_MNXT
#define LC_RM4 EE_CLR
#define LC_RM5 RM_SATU // was RGB_SAI

#define LC_LB5 RM_HUED // was RGB_HUI
#define LC_LB4 QK_BOOT
#define LC_LB3 AG_SWAP
#define LC_LB2 AG_NORM
#define LC_LB1 KC_VOLD
#define LC_LB0 KC_BRID
#define LC_LBA RM_VALD // was RGB_VAD
#define LC_LBB SK_ZOOMIN
#define LC_RBB SK_ZOOMOUT
#define LC_RBA KC_NO // was RGB_SAD
#define LC_RB0 SK_ZOOMIN
#define LC_RB1 KC_MRWD
#define LC_RB2 KC_MPLY
#define LC_RB3 KC_MFFD
#define LC_RB4 QK_BOOT
#define LC_RB5 RM_SATD // was RGB_HUD

#define LC_LH5 RM_SPDD
#define LC_LH4 RM_SPDU
#define LC_LH3 KC_MUTE
#define LC_LH2 SK_ZOOMOUT
#define LC_LH1 SK_ZOOMIN
#define LC_LH0 KC_NO
#define LC_LHA KC_NO

#define LC_RHA KC_NO
#define LC_RH0 KC_NO
#define LC_RH1 SK_ZOOMOUT // also right encoder CCW 
#define LC_RH2 SK_ZOOMIN // also right encoder CW 
#define LC_RH3 KC_RALT      // PQ xbows nature, was TG(L_NAV)
#define LC_RH4 KC_TRNS
#define LC_RH5 KC_TRNS

