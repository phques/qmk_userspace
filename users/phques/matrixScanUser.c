// ** Taken from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)
// Moved it to housekeeping_task_user, hoping to avoid problems I've been having.

#include "keyboard.h"
#include "phques.h"
// #include "semantickeys.h"
#include "processCombo.h"

void housekeeping_task_user(void) {
    // Custom code to run on every cycle of the main loop
    // Good for checking status of things or performing regular actions
#if defined(COMBO_ENABLE)
// Is a combo_action being held for delayed action/linger combos)?
    if (combo_on) {
        matrix_scan_user_process_combo();
    }
#endif
}

__attribute__ ((unused))
void __matrix_scan_user(void) {

#if defined(COMBO_ENABLE)
// Is a combo_action being held for delayed action/linger combos)?
    if (combo_on) {
        matrix_scan_user_process_combo();
    }
#endif

//
// prior register_linger_key(kc) needs to be handled here
//
//
//## PQ
#if 0
    if (linger_key && user_config.AdaptiveKeys) { // A linger key is being held down
        if (timer_elapsed(linger_timer) > LINGER_TIME) { // linger triggered
            saved_mods = get_mods();
            clear_mods();
            unregister_mods(MOD_MASK_SHIFT);  // second char isn't shifted. CAPSLOCK UNAFFECTED.
            switch(linger_key) {
                case KC_Q: // already "Q" has been sent; if lingered, add "u"
                    tap_code(KC_U);
                    break;
                case KC_LPRN: //
                    tap_code16(KC_RPRN);
                    tap_code16(KC_LEFT);
                    break;
                case KC_LBRC: //
                    tap_code16(KC_RBRC);
                    tap_code16(KC_LEFT);
                    break;
                case KC_LCBR: //
                    tap_code16(KC_RCBR);
                    tap_code16(KC_LEFT);
                    break;
                case KC_LT: //
                    tap_code16(KC_GT);
                    tap_code16(KC_LEFT);
                    break;

                case KC_QUOT: // ‘|’ single paired quotes
                    tap_code16(KC_BSPC);
                    tap_SemKey(SK_SQUL);
                    tap_SemKey(SK_SQUR);
                    tap_code16(KC_LEFT);
                    break;
//                    case SK_SDQU: // make “|” double paired quotes
                case KC_DQUO: //
                    tap_code16(KC_BSPC); // get rid of prior straight dbl quote
                    clear_keyboard();  // QMK doesn't let go of shift here?
                    tap_SemKey(SK_SDQL); // “
                    tap_SemKey(SK_SDQR); // ”
                    tap_code(KC_LEFT);
                    break;
                case SK_FDQL: //  « | » double French quote
                    tap_SemKey(SK_FDQR);
                    goto goto_pushspaceshere;
                case SK_FSQL: //  ‹ | › single French quote
                    tap_SemKey(SK_FSQR);
goto_pushspaceshere:
                    tap_code(KC_LEFT); // break up 2 dble spc
                    tap_code16(KC_SPACE); // to thwart "smart" EOS.
                    tap_code(KC_LEFT);
                    tap_code16(KC_SPACE);
                    //unregister_SemKey(linger_key);
                    break;

                default:
                    break;
            }
            linger_timer = linger_key = 0; // done lingering
            set_mods(saved_mods); // Restore mods
        }
    }
#endif
}