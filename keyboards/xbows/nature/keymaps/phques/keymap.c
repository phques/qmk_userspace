
#include QMK_KEYBOARD_H
#include <keycodes.h>

#include "phques.h"
#include "processCombo.h"

// this defines the actual layout, as far as main keys go, see diagram below.
#include LAYOUT_HEADER_H
#include "layouts/configLayer.h"
#include "layouts/symbolsLayer.h"
#include "layouts/navLayer.h"
#include "layouts/funLayer.h"

//  *  You can use _______ in place for KC_TRNS (transparent)
//  *  Or you can use XXXXXXX for KC_NO (NOOP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Keymap VANILLA: (Base Layer) Default Layer (PQ: from default keymap.c for xbows nature)
   *
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Esc |  F1  |  F2  |  F3  |  F4  |      F5  |  F6  |  F7  |  F8  |      F9  |  F10 |  F11 |  F12 |   Delete   |    Prtsc    |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |  ~  |     1   |   2   |   3   |   4   |    5      |       6    |    7    |    8   |   9  |   0  |   -  |  =  |  Backspace  |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Tab |   Q    |    W   |   E  |   R  |   T  |            |    Y   |    U   |    I  |   O  |   P  |   [  |  ]  |   \  | PgUp |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * | Ctl |   A   |   S   |   D  |   F  |   G  |      Bksp      |    H  |    J   |   K  |   L  |   ;  |  '"  |    Enter   | PgDn |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Shift|   Z  |   X  |   C  |   V  |   B  |       Enter       |    N  |    M   |  ,  |   .  |  /?  | Shift|      |  Up |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   * |Ctrl | GUI |     Alter   |    Space   |   Ctrl   |   Shift   |     Space     |    Alter   |  FN  | Ctrl | Lft  |  Dn |  Rig |
   * |---------------------------------------------------------------------------------------------------------------------------------|
   */
#ifdef HAS_QWERTY_LAYER
[L_QWERTY] = LAYOUT(
		KC_ESC,  KC_F1,   KC_F2, KC_F3,  KC_F4,  KC_F5,   KC_F6,   KC_F7, KC_F8,  KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_DEL,  KC_PSCR,
		KC_GRV,  KC_1,    KC_2,  KC_3,   KC_4,   KC_5,             KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,  KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,  KC_I,   KC_O,    KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,  KC_D,   KC_F,   KC_G,    KC_BSPC, KC_H,  KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,  KC_C,   KC_V,   KC_B,    KC_ENT,  KC_N,  KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
        SK_LCTL, SK_LGUI, KC_LALT,       KC_SPC, SK_LCTL, KC_LSFT, KC_SPC,        KC_RALT, MO(L_CFG),SK_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
#endif
//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTB │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5
[L_HD] = LAYOUT(
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_DEL,           KC_PSCR,
    KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,

    HD_LT5,  HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,             HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,  HD_RT5,  KC_HOME, KC_END, KC_PGUP,
    HD_LM5,  HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,   HD_LMA,   HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,  HD_RM5,  KC_ENT,          KC_PGDN,
    HD_LB5,  HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0,   HD_LBA,   HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,  HD_RB5,           KC_UP,
    HD_LH5,  HD_LH4,     HD_LH3,         HD_LH2,   HD_LH1, HD_RH1,   HD_RH2,         HD_RH3,     HD_RH4,  HD_RH5,  KC_LEFT, KC_DOWN, KC_RGHT
),

[L_SYM] = LAYOUT(
    KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_DEL,           KC_PSCR,
    KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,

    LS_LT5,  LS_LT4, LS_LT3, LS_LT2, LS_LT1, LS_LT0,             LS_RT0, LS_RT1, LS_RT2, LS_RT3, LS_RT4,  LS_RT5,  KC_RBRC, KC_BSLS, KC_PGUP,
    LS_LM5,  LS_LM4, LS_LM3, LS_LM2, LS_LM1, LS_LM0,   LS_LMA,   LS_RM0, LS_RM1, LS_RM2, LS_RM3, LS_RM4,  LS_RM5,  KC_ENT,           KC_PGDN,
    LS_LB5,  LS_LB4, LS_LB3, LS_LB2, LS_LB1, LS_LB0,   LS_LBA,   LS_RB0, LS_RB1, LS_RB2, LS_RB3, LS_RB4,  LS_RB5,           KC_UP,
    LS_LH5,  LS_LH4,     LS_LH3,         LS_LH2,   LS_LH1, LS_RH1,   LS_RH2,         LS_RH3,     LS_RH4,  LS_RH5,  KC_LEFT, KC_DOWN, KC_RGHT
),

[L_FUN] = LAYOUT(
    KC_ESC,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_DEL,           KC_PSCR,
    KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,

    LF_LT5,  LF_LT4, LF_LT3, LF_LT2, LF_LT1, LF_LT0,             LF_RT0, LF_RT1, LF_RT2, LF_RT3, LF_RT4,  LF_RT5,  KC_RBRC, KC_BSLS, KC_PGUP,
    LF_LM5,  LF_LM4, LF_LM3, LF_LM2, LF_LM1, LF_LM0,   LF_LMA,   LF_RM0, LF_RM1, LF_RM2, LF_RM3, LF_RM4,  LF_RM5,  KC_ENT,           KC_PGDN,
    LF_LB5,  LF_LB4, LF_LB3, LF_LB2, LF_LB1, LF_LB0,   LF_LBA,   LF_RB0, LF_RB1, LF_RB2, LF_RB3, LF_RB4,  LF_RB5,           KC_UP,
    LF_LH5,  LF_LH4,     LF_LH3,         LF_LH2,   LF_LH1, LF_RH1,   LF_RH2,         LF_RH3,     LF_RH4,  LF_RH5,  KC_LEFT, KC_DOWN, KC_RGHT
),

[L_NAV] = LAYOUT(
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_DEL,           KC_PSCR,
    KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,

    LV_LT5,  LV_LT4, LV_LT3, LV_LT2, LV_LT1, LV_LT0,             LV_RT0, LV_RT1, LV_RT2, LV_RT3, LV_RT4,  LV_RT5,  KC_RBRC, KC_BSLS, KC_HOME,
    LV_LM5,  LV_LM4, LV_LM3, LV_LM2, LV_LM1, LV_LM0,   LV_LMA,   LV_RM0, LV_RM1, LV_RM2, LV_RM3, LV_RM4,  LV_RM5,  KC_ENT,           KC_END,
    LV_LB5,  LV_LB4, LV_LB3, LV_LB2, LV_LB1, LV_LB0,   LV_LBA,   LV_RB0, LV_RB1, LV_RB2, LV_RB3, LV_RB4,  LV_RB5,           KC_UP,
    LV_LH5,  LV_LH4,     LV_LH3,         LV_LH2,   LV_LH1, LV_RH1,   LV_RH2,         LV_RH3,     LV_RH4,  LV_RH5,  KC_LEFT, KC_DOWN, KC_RGHT
),

[L_CFG] = LAYOUT(
    // keep QK_BOOT in the Esc spot for easy reset, as it is in the default keymap.c for xbows nature.
    QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_DEL,          KC_PSCR,
    KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,

    LC_LT5,  LC_LT4, LC_LT3, LC_LT2, LC_LT1, LC_LT0,             LC_RT0, LC_RT1, LC_RT2, LC_RT3, LC_RT4,  LC_RT5,  KC_RBRC, KC_BSLS, KC_HOME,
    LC_LM5,  LC_LM4, LC_LM3, LC_LM2, LC_LM1, LC_LM0,   LC_LMA,   LC_RM0, LC_RM1, LC_RM2, LC_RM3, LC_RM4,  LC_RM5,  KC_ENT,           KC_END,
    LC_LB5,  LC_LB4, LC_LB3, LC_LB2, LC_LB1, LC_LB0,   LC_LBA,   LC_RB0, LC_RB1, LC_RB2, LC_RB3, LC_RB4,  LC_RB5,           KC_UP,
    LC_LH5,  LC_LH4,     LC_LH3,         LC_LH2,   LC_LH1, LC_RH1,   LC_RH2,         LC_RH3,     LC_RH4,  LC_RH5,  KC_LEFT, KC_DOWN, KC_RGHT
),

};

// not certain if this is needed/works!?
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'
    );


#ifdef COMBO_ENABLE
#include HD_combo_def
#endif



