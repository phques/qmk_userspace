#pragma once

// non-shift, shifted pairs
#include "keycodes.h"
#include "keymap_us.h"
const uint16_t keyOverrides[][2] PROGMEM = {
    {KC_SLASH,      KC_ASTERISK},    // / *  
    {KC_DOT,        KC_COLON},       // . :
    {KC_SEMICOLON,  KC_LT},          // ; <
    {KC_COMMA,      KC_GT},          // , >  
    {KC_MINUS,      KC_PLUS},        // - +  
    {KC_HASH,       KC_DOLLAR},      // # $
};
