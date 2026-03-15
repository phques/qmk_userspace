#pragma once

// key overrides for shifted keys to produce different symbols, active layer HD
// PQ will have problems with semanti keys !! (moutis mentions override keys not supporting seman-keys)

#ifdef KEY_OVERRIDE_ENABLE
const key_override_t KOVER_HASH = ko_make_with_layers(MOD_MASK_SHIFT, KC_HASH,  KC_DOLLAR,    LAYBIT(L_HD));  //  #  $
const key_override_t KOVER_DOT = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,   KC_COLON,     LAYBIT(L_HD));   //  .  :
const key_override_t KOVER_SLASH = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLASH, KC_ASTERISK, LAYBIT(L_HD));  //  /  *
const key_override_t KOVER_DQUO = ko_make_with_layers(MOD_MASK_SHIFT, KC_DQUO,  KC_LT,        LAYBIT(L_HD));  //  “  <
const key_override_t KOVER_QUOTE = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOTE, KC_GT,        LAYBIT(L_HD)); //  ‘  >
const key_override_t KOVER_COMMA = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON, LAYBIT(L_HD)); //  ,  ;
const key_override_t KOVER_MINUS = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINUS, KC_PLUS,      LAYBIT(L_HD)); //  -  +

// This globally defines all key overrides to be used
const key_override_t * const key_overrides[] = {
    &KOVER_HASH,
    &KOVER_DOT,
    &KOVER_SLASH,
    &KOVER_DQUO,
    &KOVER_QUOTE,
    &KOVER_COMMA,
    &KOVER_MINUS
};
#endif
