#pragma once

// non-shift, shifted pairs
const uint16_t keyOverrides[][2] PROGMEM = {
    {KC_HASH,  KC_DOLLAR},      // # $  OVK_HASH  
    {KC_DOT,   KC_COLON},       // . :  OVK_DOT 
    {KC_SLASH, KC_ASTERISK},    // / *  OVK_SLASH
    {KC_DQUO,  KC_LT},          // “ <  OVK_DQUO
    {KC_QUOTE, KC_GT},          // ‘ >  OVK_QUOTE
    {KC_COMMA, KC_SEMICOLON},   // , ;  OVK_COMMA
    {KC_MINUS, KC_PLUS},        // - +  OVK_MINUS
};
