// ** Taken from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)
#pragma once

#include "phques.h"
#include "semantickeys.h"

/*   L_NAV THE NAVIGATION (right hand) LAYER w/ edit & mods on left
   ╭──────────────────────────────────────────╮                  ╭───────────────────────────────────────────────╮
__ │   QUIT     CLOZ    SCAP    SCLP    PSTM  │                  │  DOCBEG     HOME    UP      PGUP    PARAPRV   │ KC_NUM
__ │   LCTL     LALT    LGUI    LSFT    FIND  |                  |  WORDPRV    LEFT    DOWN    RGHT    WORDNXT   │ __
__ │   UNDO     CUT     COPY    PSTE    FAGN  │ ESC TAB   __  __ │  DOCEND     END     DOWN    PGDN    PARANXT   │ __
   ╰──────────────────╮  __     __     __     │ __           __  │  HISTPRV  HISTNXT    __    ╭──────────────────╯
      ZOOMRST ZOOMOUT ╰───────────────────────╯                  ╰────────────────────────────╯ HISTPRV HISTNXT
*/

#define LV_LT5 KC_TRNS
#define LV_LT4 KC_TAB
#define LV_LT3 SK_CLOZ
#define LV_LT2 SK_SCAP
#define LV_LT1 SK_SCLP
#define LV_LT0 SK_PSTM
#define LV_RT0 SK_DOCBEG
#define LV_RT1 KC_HOME
#define LV_RT2 KC_UP
#define LV_RT3 KC_PGUP
#define LV_RT4 SK_PARAPRV
#define LV_RT5 KC_TRNS

#define LV_LM5 KC_VOLU
#define LV_LM4 KC_LCTL
#define LV_LM3 KC_LALT
#define LV_LM2 KC_LGUI
#define LV_LM1 KC_LSFT
#define LV_LM0 SK_FIND
#define LV_LMA QK_LAYER_LOCK
#define LV_RM0 SK_WORDPRV
#define LV_RM1 KC_LEFT
#define LV_RM2 KC_DOWN
#define LV_RM3 KC_RGHT
#define LV_RM4 SK_WORDNXT
#define LV_RM5 KC_TRNS

#define LV_LB5 KC_VOLD
#define LV_LB4 SK_UNDO
#define LV_LB3 SK_CUT
#define LV_LB2 SK_COPY
#define LV_LB1 SK_PSTE
#define LV_LB0 SK_FAGN
#define LV_LBA KC_ESC
#define LV_LBB SK_SALL
#define LV_RBB KC_TAB
#define LV_RBA KC_ESC
#define LV_RB0 SK_DOCEND
#define LV_RB1 KC_END
#define LV_RB2 KC_DOWN
#define LV_RB3 KC_PGDN
#define LV_RB4 SK_PARANXT
#define LV_RB5 KC_TRNS

#define LV_LH5 SK_ZOOMOUT // also left encoder CCW
#define LV_LH4 SK_ZOOMIN // also left encoder CW
#define LV_LH3 KC_TRNS  // typically the app menu
#define LV_LH2 KC_TRNS  //PQ layer access key, leave trans, wasr KC_BSPC
#define LV_LH1 KC_ENTER
#define LV_LH0 SK_ZOOMRST  // also left encoder hat switch
#define LV_LHA G(KC_TAB)
#define LV_RHA TG(L_NAV)
#define LV_RH0 SK_ZOOMRST  // also right encoder hat switch
#define LV_RH1 SK_HISTPRV
#define LV_RH2 SK_HISTNXT
#define LV_RH3 KC_RALT    // PQ xbows nature, wasTG(L_NUM)
#define LV_RH4 SK_PARAPRV // also right encoder CCW
#define LV_RH5 SK_PARANXT // also right encoder CW
