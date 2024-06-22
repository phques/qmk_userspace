//#include "keycodes.h"
#include QMK_KEYBOARD_H

#include "moutis.h"

#ifdef COMBO_ENABLE
#include HD_combo_def // this has the combo definitions
#endif

#define ____ KC_TRNS
#define _no_ KC_NO


enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     Key Position Names for a 34 (-54) key split form factor
//        Should cover Ferris through Atreus-Kyria-Ergodox
//     ╭─────────────────────╮                  ╭─────────────────────╮
// LT5 │ LT4 LT3 LT2 LT1 LT0 │ LTA          RTB │ RT0 RT1 RT2 RT3 RT4 │ RT5
// LM5 │ LM4 LM3 LM2 LM1 LM0 | LMA          RMA | RT0 RM1 RM2 RM3 RM4 │ RM5
// LB5 │ LB4 LB3 LB2 LB1 LB0 │ LBA LBB  RBB RBA │ RB0 RB1 RB2 RB3 RB4 │ RB5
//     ╰───────────╮ LH2 LH1 │ LH0 LHA  RHA RH0 │ RH1 RH2 ╭───────────╯
//     LH5 LH4 LH3 ╰─────────╯                  ╰─────────╯ RH3 RH4 RH5

[L_QWERTY] = LAYOUT(
    //## pq using default voyager + thumbs & layers access based +- on HandsDown
    //TD(DANCE_0),  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,
    KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,    KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS,

    HD_CAPSWORD, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,  KC_BSLS,
    MT(MOD_LSFT, KC_BSPC),  RCTL_T(KC_A), RALT_T(KC_S), RGUI_T(KC_D), RSFT_T(KC_F), LT(L_NUM,KC_G), LT(L_FUN,KC_H), RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), MT(MOD_RSFT, KC_QUOTE),
    KC_LEFT_GUI, MT(MOD_LALT, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RALT, KC_SLASH), KC_RIGHT_CTRL,
                LT(L_NAV,KC_TAB), LT(L_FUN,KC_BSPC),          LT(L_NAV,KC_ENT), LT(L_SYM,KC_SPC)),
                //LT(L_NAV,KC_TAB), LT(L_FUN,KC_BSPC),          LT(L_CFG,KC_ENT), LT(L_SYM,KC_SPC)),

[L_HD] = LAYOUT(
    KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,     KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,

    TG(L_NUM),  HD_LT4, HD_LT3, HD_LT2, HD_LT1, HD_LT0,  HD_RT0, HD_RT1, HD_RT2, HD_RT3, HD_RT4,  TG(L_FUN),
    TT(L_CFG),  HD_LM4, HD_LM3, HD_LM2, HD_LM1, HD_LM0,  HD_RM0, HD_RM1, HD_RM2, HD_RM3, HD_RM4,  KC_TAB ,
    TG(L_NAV),  HD_LB4, HD_LB3, HD_LB2, HD_LB1, HD_LB0,  HD_RB0, HD_RB1, HD_RB2, HD_RB3, HD_RB4,  TG(L_SYM),
                               HD_LH1, HD_LH2,                  HD_RH2, HD_RH1),

[L_SYM] = LAYOUT(
    KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,     KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,

    _______,    LS_LT4, LS_LT3, LS_LT2, LS_LT1, LS_LT0,  LS_RT0, LS_RT1, LS_RT2, LS_RT3, LS_RT4,   _______,
    _______,    LS_LM4, LS_LM3, LS_LM2, LS_LM1, LS_LM0,  LS_RM0, LS_RM1, LS_RM2, LS_RM3, LS_RM4,   _______,
    TG(L_SYM),  LS_LB4, LS_LB3, LS_LB2, LS_LB1, LS_LB0,  LS_RB0, LS_RB1, LS_RB2, LS_RB3, LS_RB4,   TG(L_SYM),
                                LS_LH2, LS_LH1,                  LS_RH2, LS_RH1),
                                //##pq don't reverse left two thumbs since they are Del word left/right

[L_FUN] = LAYOUT(
    KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,     KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,

    _______,    LF_LT4, LF_LT3, LF_LT2, LF_LT1, LF_LT0,  LF_RT0, LF_RT1, LF_RT2, LF_RT3, LF_RT4,  _______,
    _______,    LF_LM4, LF_LM3, LF_LM2, LF_LM1, LF_LM0,  LF_RM0, LF_RM1, LF_RM2, LF_RM3, LF_RM4,  _______,
    TG(L_FUN),  LF_LB4, LF_LB3, LF_LB2, LF_LB1, LF_LB0,  LF_RB0, LF_RB1, LF_RB2, LF_RB3, LF_RB4,  TG(L_FUN),
                                LF_LH1, LF_LH2,                  LF_RH2, LF_RH1),

[L_NUM] = LAYOUT(
    KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,     KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,

    _______,    LN_LT4, LN_LT3, LN_LT2, LN_LT1, LN_LT0,  LN_RT0, LN_RT1, LN_RT2, LN_RT3, LN_RT4,  _______,
    _______,    LN_LM4, LN_LM3, LN_LM2, LN_LM1, LN_LM0,  LN_RM0, LN_RM1, LN_RM2, LN_RM3, LN_RM4,  _______,
    TG(L_NUM),  LN_LB4, LN_LB3, LN_LB2, LN_LB1, LN_LB0,  LN_RB0, LN_RB1, LN_RB2, LN_RB3, LN_RB4,  TG(L_NUM),
                                LN_LH1, LN_LH2,                  LN_RH2, LN_RH1),

[L_NAV] = LAYOUT(
    KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,     KC_6,  KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,

    _______,    LV_LT4, LV_LT3, LV_LT2, LV_LT1, LV_LT0,  LV_RT0, LV_RT1, LV_RT2, LV_RT3, LV_RT4,  _______,
    _______,    LV_LM4, LV_LM3, LV_LM2, LV_LM1, LV_LM0,  LV_RM0, LV_RM1, LV_RM2, LV_RM3, LV_RM4,  _______,
    TG(L_NAV),  LV_LB4, LV_LB3, LV_LB2, LV_LB1, LV_LB0,  LV_RB0, LV_RB1, LV_RB2, LV_RB3, LV_RB4,  TG(L_NAV),
                                LV_LH1, LV_LH2,                  LV_RH2, LV_RH1),

[L_CFG] = LAYOUT(
    //KC_ESC, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
    RGB_TOG, RGB_MODE_PLAIN, RGB_MODE_FORWARD, RGB_MODE_REVERSE, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, TOGGLE_LAYER_COLOR, _______,

    _______,    LC_LT4, LC_LT3, LC_LT2, LC_LT1, LC_LT0,  LC_RT0, LC_RT1, LC_RT2, LC_RT3, LC_RT4,  _______,
    _______,    LC_LM4, LC_LM3, LC_LM2, LC_LM1, LC_LM0,  LC_RM0, LC_RM1, LC_RM2, LC_RM3, LC_RM4,  _______,
    TG(L_CFG),  LC_LB4, LC_LB3, LC_LB2, LC_LB1, LC_LB0,  LC_RB0, LC_RB1, LC_RB2, LC_RB3, LC_RB4,  TG(L_CFG),
                                LC_LH1, LC_LH2,                  LC_RH2, LC_RH1),
};

// ---------------------------------------

// tap dance code taken from Oryx generated source
#if 0
typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
        tap_code16(KC_EQUAL);
    }
    if(state->count > 3) {
        tap_code16(KC_EQUAL);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_EQUAL); break;
        case SINGLE_HOLD: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_EQUAL); register_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_EQUAL); register_code16(KC_EQUAL);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
        case SINGLE_HOLD: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

#endif
