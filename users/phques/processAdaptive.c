
#include "phques.h"         // IWYU pragma: keep
#include "processAdaptive.h"    // IWYU pragma: export
#include "sendstr.h"            // IWYU pragma: export
#include "semantickeys.h"       // IWYU pragma: export

// Include the adaptive tables for this layout.
// const adaptive_3key_t adaptive_3keys[] PROGMEM = {..}
// const adaptive_2key_t adaptive_2keys[] PROGMEM = {..}

#ifdef LAYOUT_ADAPTIVE_INC
    #include LAYOUT_ADAPTIVE_INC
#endif

#ifdef ADAPTIVE_ENABLE

bool process_adaptive_key(uint16_t keycode) {
    bool return_state = true; // assume we don't do anything.

    if (!user_config.AdaptiveKeys || user_config.IsQwerty) {
        return true; // no adaptive keys on QWERTY, so return.
    }

    // Are we in an adaptive context? (adaptive on is assumed).
    if (timer_elapsed(prior_keydown) > ADAPTIVE_TERM) { // outside adaptive threshhold
        prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
        return true; // no adaptive conditions, so return.
    }

    // K, this could be adaptive, so process.
    saved_mods = get_mods();

    // if (!caps_word_timer) { // turn off shift, (first-words & Proper nouns)
    //     unregister_mods(MOD_MASK_SHIFT);  //CAPS_WORD/LOCK won't be affected.
    // } // may want more granular control than this…

    for (int i = 0; pgm_read_ptr(&adaptive_3keys[i].output) != NULL; i++) {
        if (keycode          == pgm_read_word(&adaptive_3keys[i].key3) &&
            prior_keycode    == pgm_read_word(&adaptive_3keys[i].key2) &&
            preprior_keycode == pgm_read_word(&adaptive_3keys[i].key1))
        {
            // We have a match! Output the string.
            SEND_STRING("\b\b");
            SendCapString((const char *)pgm_read_ptr(&adaptive_3keys[i].output));
            return_state = false; // we handled this key, so don't let QMK do anything else with it.
            break; // stop looking through the list, we found a match.
        }
    }

    for (int i = 0; return_state && pgm_read_ptr(&adaptive_2keys[i].output) != NULL; i++) {
        if (keycode       == pgm_read_word(&adaptive_2keys[i].key2) &&
            prior_keycode == pgm_read_word(&adaptive_2keys[i].key1))
        {
            // We have a match! Output the string.
            SEND_STRING("\b");
            SendCapString((const char *)pgm_read_ptr(&adaptive_2keys[i].output));
            return_state = false; // we handled this key, so don't let QMK do anything else with it.
            break; // stop looking through the list, we found a match.
        }
    }

    return return_state; // if we didn't handle this key, return true to let QMK do the default.
}

#endif // ADAPTIVE_ENABLE
