
#include <quantum.h>
#include "semantickeys.h"
#include "processKeyOverride.h"

// non-shift, shifted pairs, for OVK_xx keys. Indexed by OVK_ndx(sk) and shift state (0 or 1)
const uint16_t keyOverrides[][2] PROGMEM = {
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
bool process_keyOverride(uint16_t keycode, keyrecord_t *record) {

    uint8_t currentMods = get_mods() | get_weak_mods() /* | get_oneshot_mods() */;

    // Only handle keys in your override list
    if (!is_OverKey(keycode)) {
        return true;
    }


    // Determine which override entry to use
    uint8_t idx = OVK_ndx(keycode);

    // Determine whether Shift is currently active (real + weak + /* oneshot */)
    bool shiftHeld = currentMods & MOD_MASK_SHIFT;
    bool cagHeld = currentMods & MOD_MASK_CAG;

    // Pick shifted or unshifted override
    // If other modifiers are held, we use the non shifted value. 
    // So, for example, for Cmd+Shift+. to have its intended effect on Mac.
    uint8_t  shiftIdx         = shiftHeld && !cagHeld ? 1 : 0;
    uint16_t override_keycode = pgm_read_word(&keyOverrides[idx][shiftIdx]);

    // Determine whether the override keycode itself requires Shift
    uint8_t keyMods    = QK_MODS_GET_MODS(override_keycode);
    bool    needsShift = (keyMods & MOD_MASK_SHIFT);

    // If Shift is held but the override key does NOT need Shift → temporarily remove Shift
    bool needUnshift = shiftHeld && !needsShift && !cagHeld;

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
        set_mods(currentMods); // restore original mods (including Shift)
        send_keyboard_report();
    }
    return false;
}
