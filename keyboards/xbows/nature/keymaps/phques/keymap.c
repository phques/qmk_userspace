
#include QMK_KEYBOARD_H
#include <keycodes.h>

#include "phques.h"
#include "processCombo.h"

// this defines the actual layout, as far as main keys go, see diagram below.
#include LAYOUT_HEADER_H
#include "layouts/configLayer.h"

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
        KC_LCTL, KC_LGUI, KC_LALT,       KC_SPC, KC_LCTL, KC_LSFT, KC_SPC,        KC_RALT, MO(L_CFG),KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),
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

    HD_LT5,  HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,             HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,  HD_RT5,  KC_RBRC, KC_BSLS, KC_PGUP,
    HD_LM5,  HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,   HD_LMA,   HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,  HD_RM5,  KC_ENT,           KC_PGDN,
    HD_LB5,  HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0,   HD_LBA,   HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,  HD_RB5,           KC_UP,
    HD_LH5,  HD_LH4,     HD_LH3,         HD_LH2,   HD_LH1, HD_RH1,   HD_RH2,         HD_RH3,     HD_RH4,  HD_RH5,  KC_LEFT, KC_DOWN, KC_RGHT
),

[L_CFG] = LAYOUT(
    QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,  KC_F6,      KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,  KC_DEL,           KC_PSCR,
    KC_GRV,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,

    LC_LT5,  LC_LT4, LC_LT3, LC_LT2, LC_LT1, LC_LT0,             LC_RT0, LC_RT1, LC_RT2, LC_RT3, LC_RT4,  LC_RT5,  KC_RBRC, KC_BSLS, KC_PGUP,
    LC_LM5,  LC_LM4, LC_LM3, LC_LM2, LC_LM1, LC_LM0,   LC_LMA,   LC_RM0, LC_RM1, LC_RM2, LC_RM3, LC_RM4,  LC_RM5,  KC_ENT,           KC_PGDN,
    LC_LB5,  LC_LB4, LC_LB3, LC_LB2, LC_LB1, LC_LB0,   LC_LBA,   LC_RB0, LC_RB1, LC_RB2, LC_RB3, LC_RB4,  LC_RB5,           KC_UP,
    LC_LH5,  LC_LH4,     LC_LH3,         LC_LH2,   LC_LH1, LC_RH1,   LC_RH2,         LC_RH3,     LC_RH4,  LC_RH5,  KC_LEFT, KC_DOWN, KC_RGHT
),
//   [L_CFG] = LAYOUT(
//     QK_BOOT,   _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_CALC,   KC_MYCM,  KC_MSEL,   KC_MAIL,   NK_TOGG,   EE_CLR,
//     _______,   _______,  _______,  _______,   _______,  _______,             _______,  _______,  _______,   _______,  _______,   _______,   _______,   KC_NUM,
// //  5          4         3         2         1         0          A         0         1         2         3         4         5          6          7          8
//     RM_TOGG,   RM_NEXT,  RM_VALU,  RM_HUEU,  _______,  _______,   _______,  _______, SK_Win,    SK_Mac,    _______,  _______,   _______,   _______,   KC_HOME,
//     _______,   RM_SPDD,  RM_VALD,  RM_SPDU,  _______,  _______,   _______,  _______, HD_L_QWERTY,HD_L_ALPHA,_______,  _______,   _______,   _______,   KC_END,
//     _______,   _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,   _______,  _______,   KC_MUTE,   KC_VOLU,
//     _______,   _______,  _______,            _______,  _______,   _______,  _______,            _______,   _______,  KC_MPLY,   KC_MPRV,   KC_VOLD,   KC_MNXT),
};

// not certain if this is needed!?
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

#include "keyOverrides.h"

