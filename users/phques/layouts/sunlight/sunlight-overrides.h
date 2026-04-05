#pragma once

// non-shift, shifted pairs
#include "keycodes.h"
#include "keymap_us.h"
const uint16_t keyOverrides[][2] PROGMEM = {
    {KC_SLASH,      KC_ASTERISK},   //  / *  
    {KC_DOT,        KC_COLON},      //  . :
    {KC_COMMA,      KC_SCLN},       //  , ;  
    {KC_MINUS,      KC_PLUS},       //  - +  
    {KC_HASH,       KC_DOLLAR},     //  # $
    {KC_DQUO,       KC_LT},         //  " <
    {KC_QUOT,       KC_GT},         //  ' >
};
