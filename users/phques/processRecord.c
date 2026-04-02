// ** Taken/Adapted from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)
// This file is for handling custom keycodes and other record processing.

#include <quantum.h>
#include "action_util.h"
#include "keycodes.h"
#include "phques.h"
#include "processRecord.h"
#include "processAdaptive.h"
#include "processKeyOverride.h"
#include "quantum.h"
#include "rgb.h"
#include "semantickeys.h"
#include "app_menu.h"


//-----------

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool return_state = true;

    saved_mods = get_mods(); // preserve mods

    // Do we need to filter multi-function keys?
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
#ifdef TAP_DANCE_ENABLE
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
#endif
            if (!record->tap.count) // if not tapped yet...
                return true; // let QMK do that first

            keycode &= QK_BASIC_MAX; // mods & taps have been handled.
    }

    //--------------

#if defined(ADAPTIVE_ENABLE)
    // Should we handle an adaptive key?  (Semkey may send Adaptive?)
    if (record->event.pressed // keyup = not rolling = no adaptive -> return.
        && user_config.AdaptiveKeys // AdaptiveKeys is on
        ) {

        if (!process_adaptive_key(keycode)) {
            preprior_keycode = prior_keycode; // look back 2 keystrokes?
            prior_keycode = keycode; // this keycode is stripped of mods+taps
            prior_keydown = timer_read(); // (re)start prior_key timing
            return false; // took care of that key
        }
    }
#endif // #ifdef ADAPTIVE_ENABLE
    
#if defined(KEYS_OVERRIDE_ENABLE)
    // Do we have a key override for this keycode?
    if (!process_keyOverride(keycode, record)) {
        return false; // took care of that key
    }
#endif // #ifdef KEYS_OVERRIDE_ENABLE

    // Do we handle a semantic key? Combos or adaptives could have sent one.
    if (!process_semkey(keycode, record)) {
        return false; // took care of that key
    }

    // APP_MENU gets special treatment (no adaptive handling, separate timers)
    if  (keycode == KC_APP) {  // mimic windows app key behavior (only better?) also in scan_matrix
        process_APP_MENU(record);
        return false; // took care of that key
    }

    // only process for SHIFT/ALT & no CTRL or GUI mods
    if (saved_mods & MOD_MASK_CG)  // CTRL or GUI/CMD?
        return true; // do default if CTRL or GUI/CMD are down

    // ----------------

    //## PQ, no linger keys for now. Might want to add some later.
    if (record->event.pressed) {

        switch (keycode) { // only handling normal, SHFT or ALT cases.
            case SK_Lux: // switch to linux (or Win if not defined)
            case SK_Win: // switch to windows
            case SK_Mac: // Back to default
                selectOS(keycode);
                refreshIndicators(layer_state);
                saveUserConfig();
                return_state = false; // stop processing this record.
                break;

            case HD_AdaptKeyToggle: // toggle AdaptiveKeys (& LingerKeys, linger combos)
#ifdef ADAPTIVE_ENABLE
                user_config.AdaptiveKeys = !user_config.AdaptiveKeys;
                saveUserConfig();
#endif
                return_state = false; // stop processing this record.
                break;

#ifdef HAS_QWERTY_LAYER
            case HD_L_QWERTY: // are we changing default layers?
#endif
            case HD_L_ALPHA:
                selectLayer(keycode);
                refreshIndicators(layer_state);
                saveUserConfig();
                return_state = false; // don't do more with this record.
                break;

            case RM_TOGG: // toggle RGB night mode
                toggleNightMode();
                return_state = false; // stop processing this record.
                break;
        } // end switch (keycode)

#ifdef ADAPTIVE_ENABLE
        prior_keydown = timer_read(); // (re)start prior_key timing
        preprior_keycode = prior_keycode; // look back 2 keystrokes?
        prior_keycode = keycode; // this keycode is now stripped of mods+taps
#endif
        
    }
    else { // (record->event.pressed) / // key up event

        switch (keycode) { // only handling normal, SHFT or ALT cases.
        } // end switch (keycode)

    } // end key up event

    return return_state;
}
