// ** Taken/Adapted from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)
// This file is for handling custom keycodes and other record processing.

#include "action_util.h"
#include "keycodes.h"
#include "phques.h"
#include "processRecord.h"
#include "quantum.h"
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
#ifdef INCLUDE_HD_Lux
                user_config.OSIndex = OS_Lux; // for Linux Semkeys
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
                return_state = false; // stop processing this record.
                saveUserConfig();
                break;
#endif
            case SK_Win: // switch to windows
                user_config.OSIndex = OS_Win; // for Windows Semkeys
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
                return_state = false; // stop processing this record.
                saveUserConfig();
                break;

            case SK_Mac: // Back to default
                user_config.OSIndex = OS_Mac; // for Mac Semkeys
                keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
                return_state = false; // stop processing this record.
                saveUserConfig();
                break;

            case HD_AdaptKeyToggle: // toggle AdaptiveKeys (& LingerKeys, linger combos)
#ifdef ADAPTIVE_ENABLE
                user_config.AdaptiveKeys = !user_config.AdaptiveKeys;
                //#pq debug
                if (user_config.AdaptiveKeys) {
                    dprint("dbg Adaptive Keys On\n");
                }
                else {
                    dprint("dbg Adaptive Keys Off\n");
                }
                saveUserConfig();
#endif
                return_state = false; // stop processing this record.
                break;

#ifdef HAS_QWERTY_LAYER
            case HD_L_QWERTY: // are we changing default layers?
#endif
            case HD_L_ALPHA:
#ifdef ADAPTIVE_ENABLE
                user_config.AdaptiveKeys = keycode != HD_L_QWERTY; // no adaptive keys on QWERTY
#endif  // ADAPTIVE_ENABLE
#ifdef HAS_QWERTY_LAYER
                user_config.BaseLayer = keycode - L_BASELAYER; // set the base layer index (0 or 1)
#else
                user_config.BaseLayer = 0; // only one base layer, so always 0
#endif  // HAS_QWERTY_LAYER
                saveUserConfig();

                return_state = false; // don't do more with this record.
                set_single_persistent_default_layer(keycode-L_BASELAYER);// Remember default layer after powerdown
        }
    }
    else { // (record->event.pressed) / // key up event

        switch (keycode) { // only handling normal, SHFT or ALT cases.
        } // end switch (keycode)

    } // end key up event

    return return_state;
}
