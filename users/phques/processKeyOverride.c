
#include <quantum.h>
#include "phques.h"
#include "processKeyOverride.h"

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

int8_t keyOverrideIndex(uint16_t keycode) {
    for (uint8_t idx = 0; idx < ARRAY_SIZE(keyOverrides); idx++) {
        uint16_t base_keycode = pgm_read_word(&keyOverrides[idx][0]);

        if (keycode == base_keycode) {
            return idx;
        }
    }
    return -1;
}


// Key overrides for special shifted keys. Process when *only* Shift is held.
// e.g. # produces $ when shifted, but we want to be able to produce # without shift as well.
bool process_keyOverride(uint16_t keycode, keyrecord_t *record) {

    // Determine which override entry to use
    int8_t idx = keyOverrideIndex(keycode);

    // Only handle keys in your override list
    // if QWERTY is the base layer, don't do any overrides.
    if (idx < 0 || user_config.IsQwerty) { // 
        return true;
    }

    // Determine whether Shift is currently active (real + weak + /* oneshot */)
    uint8_t currentMods = get_mods() | get_weak_mods() /* | get_oneshot_mods() */;
    bool shiftHeld = currentMods & MOD_MASK_SHIFT;
    bool cagHeld = currentMods & MOD_MASK_CAG;
    if (!shiftHeld || cagHeld) {
        return true; // only do overrides for Shift, and not if CAGS are held.
    }

    // Determine whether the override keycode itself requires Shift
    uint16_t override_keycode = pgm_read_word(&keyOverrides[idx][1]);
    uint8_t keyMods = QK_MODS_GET_MODS(override_keycode);
    bool    isShiftRequired = (keyMods & MOD_MASK_SHIFT);

    // Shift is held but the override key does NOT need Shift → temporarily remove Shift
    if (!isShiftRequired) {
        del_mods(MOD_MASK_SHIFT);
        send_keyboard_report();
    }

    // --- PRESS ---
    if (record->event.pressed) {
        register_code16(override_keycode);
    }
    else { // --- RELEASE ---
        unregister_code16(override_keycode);
    }

    if (!isShiftRequired) {
        set_mods(currentMods); // restore original mods (including Shift)
        send_keyboard_report();
    }

    return false;
}
