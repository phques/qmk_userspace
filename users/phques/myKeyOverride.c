
#include <quantum.h>
#include "semantickeys.h"
#include "myKeyOverride.h"

// non-shift, shifted pairs, for OVK_xx keys. Indexed by OVK_ndx(sk) and shift state (0 or 1)
const uint16_t myKeyOverrides[][2] PROGMEM = {
    {KC_HASH,  KC_DOLLAR},      // # $  OVK_HASH  
    {KC_DOT,   KC_COLON},       // . :  OVK_DOT 
    {KC_SLASH, KC_ASTERISK},    // / *  OVK_SLASH
    {KC_DQUO,  KC_LT},          // “ <  OVK_DQUO
    {KC_QUOTE, KC_GT},          // ‘ >  OVK_QUOTE
    {KC_COMMA, KC_SEMICOLON},   // , ;  OVK_COMMA
    {KC_MINUS, KC_PLUS},        // - +  OVK_MINUS
};


// Key overrides for special shifted keys.
// e.g. # produces $ when shifted, but we want to be able to produce # without shift as well.
bool process_myKeyOverride(uint16_t keycode, keyrecord_t *record) {
    // Only handle keys in your override list
    if (!is_OverKey(keycode)) {
        return true;
    }

    // Determine which override entry to use
    uint8_t idx = OVK_ndx(keycode);

    // Determine whether Shift is currently active (real + weak + /* oneshot */)
    uint8_t mods      = get_mods() | get_weak_mods() /* | get_oneshot_mods() */;
    bool    shiftHeld = mods & MOD_MASK_SHIFT;

    // Pick shifted or unshifted override
    uint8_t  shiftIdx         = shiftHeld ? 1 : 0;
    uint16_t override_keycode = pgm_read_word(&myKeyOverrides[idx][shiftIdx]);

    // Determine whether the override keycode itself requires Shift
    uint8_t keyMods    = QK_MODS_GET_MODS(override_keycode);
    bool    needsShift = keyMods & MOD_MASK_SHIFT;

    // If Shift is held but the override key does NOT need Shift → temporarily remove Shift
    bool needUnshift = shiftHeld && !needsShift;

    if (needUnshift) {
        del_mods(MOD_MASK_SHIFT);
        send_keyboard_report();
    }

    // --- PRESS ---
    if (record->event.pressed) {
        register_code16(override_keycode);
    }

    // --- RELEASE ---
    else {
        unregister_code16(override_keycode);
    }

    if (needUnshift) {
        set_mods(mods); // restore original mods (including Shift)
        send_keyboard_report();
    }
    return false;
}
