// ** Taken from [moutis Hands Down QMK implementation](https://github.com/moutis/HandsDown)

/*
 Combos

 Tailored for Hands Down Neu related variations
 Others have been removed, but I'll try to get everything in here soon enough.
 Finally getting to the last of imagined features that spurred Hands Down design!

 */
#include <quantum.h>
#include "phques.h"
#include "semantickeys.h"
#include "sendstr.h"
#include "processCombo.h"


__attribute__ ((unused))
void process_combo_event(uint16_t combo_index, bool pressed) {

    if (pressed) {

#ifdef ADAPT_SHIFT
        // pseudo-adaptive comma-shift uses 2x ADAPTIVE_TERM, so pre-evaluated
        if (
            (prior_keycode == ADAPT_SHIFT)  // is it shift leader?
//            && ((timer_elapsed(prior_keydown) <= ADAPTIVE_TERM*2))  // within threshold?
//            && ((combo_index >= HC_Q) && (combo_index <= HC_AE)) // followed by alpha combo?
//            && ((combo_index >= HC_Th) && (combo_index <= HC_their_5gram)) // followed by alpha combo?
            )
        {
            tap_code(KC_BSPC);          // get rid of the ADAPT_SHIFT
            register_code16(KC_LSFT);  // This will unregister in matrix_scan_user_process_combo
            prior_keycode = preprior_keycode = prior_keydown = 0; // turn off Adaptives.
        }
#endif        
        switch(combo_index) {
            case PC_STAB ... COMBO_LENGTH:// these may have a hold delay BEFORE triggering
            case HC_AT ... HC_COLN: //
                combo_on = combo_index; // queue for matrix_scan_user_process_combo
                break;

            case HC_Q: //
                if (saved_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) // interested?
                    break;
                tap_code16(KC_Q); //
                unregister_mods(MOD_MASK_SHIFT);  //
                tap_code16(KC_U); //
                combo_on = combo_index; // if held, delete the 'u' in matrix_scan_user_process_combo
                break;

            case HC_ING: //
                if (saved_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) // interested?
                    break;
                SendCapString("ing");
                break;
/*
 * H digraphs here
 */
 #ifdef EN_HDIGRAPH_COMBOS

            case HC_Th: // on first press
                tap_code(KC_T); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Sh:
                tap_code(KC_S); // send "T" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
           case HC_Wh:
                tap_code(KC_W); // send "W" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
/* this conflicts with home row tab, so using adaptive CS -> SC
            case HC_Sc: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S); // send "S"
                unregister_mods(MOD_MASK_SHIFT);  //
                tap_code(KC_C); // send "C"
                combo_on = combo_index; // if held, addd 'h' for "Sch" in matrix_scan_user_process_combo
                break;
*/
//#ifdef EN_HDIGRAPH_COMBOS
            case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                tap_code(KC_S); // send "S"
                unregister_mods(MOD_MASK_SHIFT);  //
            case HC_Ch: // not held
                tap_code(KC_C); // send "C" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Gh: // not held
                tap_code(KC_G); // send "G" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
            case HC_Ph:
                tap_code(KC_P); // send "P" honoring caps
                combo_on = combo_index; // if held, check in matrix_scan_user_process_combo
                break;
#endif // EN_HDIGRAPH_COMBOS

            case HC_ACUT:
                tap_code16(A(KC_E)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_GRV:
                tap_code16(A(KC_GRAVE)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
            case HC_CIRC:
                 tap_code16(A(KC_6)); // this should use semkeys
                combo_on = combo_index; // may add "e" in matrix_scan_user_process_combo
                break;
//            case HC_MACR:
//                tap_code16(A(KC_A)); // this should use semkeys
//                combo_on = combo_index; // may add "o" in matrix_scan_user_process_combo
//                break;
            case HC_DIER:
                tap_code16(A(KC_U)); // this should use semkeys
                combo_on = combo_index; // may add "u" in matrix_scan_user_process_combo
                break;
//            case HC_RING:
//                tap_code16(A(KC_K)); // this should use semkeys
//                combo_on = combo_index; // may add "a" for å in matrix_scan_user_process_combo
//                break;
            case HC_CEDILLE:
                tap_code16(A(KC_C)); // this should use semkeys
                combo_on = combo_index; // may add "c" in matrix_scan_user_process_combo
                break;
            case HC_ENYE:
                tap_code16(A(KC_N)); // this should use semkeys
                combo_on = combo_index; // may add "n" in matrix_scan_user_process_combo
                break;
//            case HC_AE: // Æ
//                tap_code16(A(KC_QUOT)); // this should use semkeys
//                break;
//            case HC_OE: // Œ
//                tap_code16(A(KC_Q)); // this should use semkeys
//                tap_code16(KC_U); // almost always "œu"
//                combo_on = combo_index; // but like qu, we'll take it back if we must.
//                break;
/*
            case HC_1E: // É
                tap_code16(A(KC_E)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_2E: // È
                tap_code16(A(KC_GRAVE)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_3E: // Ê
                tap_code16(A(KC_6)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_4E: // Ë
                tap_code16(A(KC_U)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_5E: // Ē
                tap_code16(A(KC_A)); // this should use semkeys
                tap_code16(KC_E); //
                break;
            case HC_6E: // E̊
                tap_code16(A(KC_K)); // this should use semkeys
                tap_code16(KC_E); //
                break;
*/
/*
            case HC_OSLSH:
                tap_code16(A(KC_O)); // this should use semkeys
                break;
*/
            case HC_NDSH: // delay action until key-up (outside of delay block)
//                register_SemKey(SK_NDSH);  // should be a semkey
                combo_on = combo_index; // hold to replace with m-dash
                break;

#ifdef EN_PRONOUN_COMBOS // the entirely unnecessary pronoun combo shenanigans

            case HC_I:
                tap_code16(S(KC_I));
                unregister_mods(MOD_MASK_SHIFT);  //
                combo_on = combo_index; // may add "'ve " if held
                break;
            case HC_Id:
            case HC_Ill:
            case HC_Im:
            case HC_Iv:
                tap_code16(S(KC_I)); // send "I" CAPITALIZED
                unregister_mods(MOD_MASK_SHIFT);  //
                goto addonsuffix;

#ifdef EN_PRONOUN_COMBOS_ALL

// This group all share a suffix, with a goto addonsuffix,
// so keep together 'cause we're messing with stack frames at the end!

            case HC_they_4gram: // "they"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("hey"); // send "they" right away
                combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                break;
            case HC_your_4gram:
                tap_code(KC_Y);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("our");
                combo_on = combo_index; // may add "'s " in matrix_scan_user_process_combo
                break;
#ifdef EN_W_PRONOUNS
            case HC_wed_4gram:
            case HC_well_5gram:
            case HC_were_5gram:
            case HC_weve_5gram:
                tap_code(KC_W); // send "W" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("e"); // send "We" right away
                goto addonsuffix;
#endif // EN_W_PRONOUNS
            case HC_youd_5gram:
            case HC_youll_6gram:
            case HC_youre_6gram:
            case HC_youve_6gram:
                tap_code(KC_Y); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("ou"); // send "We're" right away
                goto addonsuffix;
            case HC_theyd_6gram: // TYPE "they'd " #23
            case HC_theyll_7gram:
            case HC_theyre_7gram:
            case HC_theyve_7gram: // "they've"
                tap_code(KC_T); // send "Y" honoring caps
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("hey"); // send "they" right away

#endif // #ifdef EN_PRONOUN_COMBOS_ALL

addonsuffix: // sharing this saves about 100 bytes on AVR (10 bytes per instance)
                tap_code(KC_QUOT);
                switch (combo_index) { //
                    case HC_Im:
                        SEND_STRING("m ");
                        break;
#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_wed_4gram: // we'd
#endif // EN_W_PRONOUNS
                    case HC_youd_5gram:
//                    case HC_youdg_5gram:
                    case HC_theyd_6gram: // TYPE "they'd " #23
//                    case HC_theydg_6gram: // TYPE "they'd " #23
#endif // #ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Id: // "I'd " …
                        send_string("d");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;


#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_well_5gram: // we'll
#endif // EN_W_PRONOUNS
                    case HC_youll_6gram:
                    case HC_theyll_7gram: // TYPE "they'll " #23
//                    case HC_theyllg_7gram: // TYPE "they'll " #23
#endif //#ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Ill: // "I'll "
                        send_string("ll");
                        combo_on = combo_index; // may add "'ve " in matrix_scan_user_process_combo
                        break;
#ifdef EN_PRONOUN_COMBOS_ALL
#ifdef EN_W_PRONOUNS
                    case HC_were_5gram: // we're
#endif // EN_W_PRONOUNS
                    case HC_youre_6gram:
                    case HC_theyre_7gram: // "they're"
                        send_string("re ");
                        break;
#ifdef EN_W_PRONOUNS
                    case HC_weve_5gram: // we've
#endif // EN_W_PRONOUNS
                    case HC_youve_6gram:
                    case HC_theyve_7gram: // "they've"
//                    case HC_theyveg_7gram: // "they've"
#endif // #ifdef EN_PRONOUN_COMBOS_ALL
                    case HC_Iv: // "I've " …
                        send_string("ve ");
                        break;
                }
                break;
// END of the common Pronoun suffix group with the goto addonsuffix:

#ifdef EN_PRONOUN_COMBOS_ALL
            case HC_their_5gram: // TYPE "their" #6
                tap_code(KC_T);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("heir");
                combo_on = combo_index; // may add "'s " if held
                break;

            case HC_here_4gram: // TYPE "here" #9
                tap_code(KC_H);
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("ere");
                combo_on = combo_index; // may add "'s " if held
                break;
#ifdef EN_W_PRONOUNS
            case HC_where_5gram: // TYPE "where" // this should be a linger add text?
                tap_code(KC_W);
                goto ADD_HERE;
#endif // EN_W_PRONOUNS
            case HC_there_5gram: // TYPE "there" #7
                tap_code(KC_T);
#ifdef EN_W_PRONOUNS
ADD_HERE:
#endif // EN_W_PRONOUNS
                unregister_mods(MOD_MASK_SHIFT);  //
                send_string("here");
                combo_on = combo_index; // may add "'ve " if held
                break;

#endif // EN_PRONOUN_COMBOS_ALL
#endif // EN_PRONOUN_COMBOS

        } // end switch (combo_index)

        if (combo_on)
                linger_timer = timer_read(); // start timing for linger process
        // should GUARD this with return instead
    } else { // end if (pressed) so this is the key up switch, hold threshold NOT met.
/*
 This is the key up event
*/
        // make this smarter/smaller/faster.
        // lookup keys to output from the key_combos[key_combos] table, bypassing this switch?
        // wrapup the combo and send the underlying keys if necessary
        //
        if (combo_on && !combo_triggered) { // combo NOT triggered in matrix_scan_user_process_combo

            switch(combo_index) {
// the H digraphs
#ifdef EN_HDIGRAPH_COMBOS
                case HC_Sch: // to avoid outward roll on ring->pinky fingers moving in unison is easier
                case HC_Ch:
                case HC_Th:
                case HC_Sh:
                case HC_Wh:
                case HC_Gh:
                case HC_Ph:
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h" honoring CAPSLK state
                    break;
#endif // EN_HDIGRAPH_COMBOS

                case HC_FIND:  // Simple Find if not held
                    tap_SemKey(SK_FIND);
                    break;
                case HC_NEW:
                    tap_SemKey(SK_NEW);
                    break;
                case HC_COPY: // not held, so simple copy
                    tap_SemKey(SK_COPY);
                    break;
                case HC_PSTE: // not held, so simple paste
                    tap_SemKey(SK_PSTE);
                    break;

                case HC_AT:
                    tap_code16(KC_AT); //
                    break;
                case HC_COLN:
                    tap_code16(KC_COLN); //
                    break;
                case HC_NDSH: // Send N-Dash if not held.
                    tap_SemKey(SK_NDSH);  // – N dash
                    break;

                case PC_DASH:
                    tap_code(KC_P1);
                    tap_code(KC_P2);
                    break;
                case PC_TILD:
                    tap_code(KC_P1);
                    tap_code(KC_P3);
                    break;
                case PC_ELIP:
                    tap_code(KC_P2);
                    tap_code(KC_P3);
                    break;
                case PC_LPRN:
                    tap_code(KC_P4);
                    tap_code(KC_P5);
                    break;
                case PC_RPRN:
                    tap_code(KC_P5);
                    tap_code(KC_P6);
                    break;
                case PC_COLN:
                    tap_code(KC_P4);
                    tap_code(KC_P6);
                    break;
                case PC_PERC:
                    tap_code(KC_P6);
                    tap_code(KC_PPLS);
                    break;
                case PC_JYEN:
                    tap_code(KC_SLSH);
                    tap_code(KC_7);
                    break;
                case PC_DOLR:
                    tap_code(KC_7);
                    tap_code(KC_8);
                    break;
                case PC_CENT:
                    tap_code(KC_7);
                    tap_code(KC_9);
                    break;
                case PC_EURO:
                    tap_code(KC_8);
                    tap_code(KC_9);
                    break;

                case HC_TYPE_LEFTCOMBO:
                        send_string(LeftComboTapE); //
                    break;
                case HC_TYPE_RIGHTCOMBO:
                        send_string(RightComboTapE); // send "Japan" right away
                    break;

#ifdef EN_PRONOUN_COMBOS
                case HC_I ... HC_Iv:
#ifdef EN_PRONOUN_COMBOS_ALL
                case HC_wed_4gram ... HC_their_5gram:
#endif
#endif
                    tap_code(KC_SPC); // add space after a composed pronoun
                    combo_on = 0;  // done w/these shenanigans
                    break;
                case HC_Q: //
                    unregister_code16(KC_Q); //
                    linger_key = 0;
                    break;
                case HC_EQL: //
                    tap_code16(KC_EQL); // Not held, so…
                    break;

            }  // end switch(combo_index) {
        } else {
        // Key up, threshold met, so we'll WRAP-UP the combo action if neccessary.
        // unregister_code for repeating keys, etc. that weren't handled in matrix_scan_user
            switch(combo_index) {
            }  // end switch(combo_index) {
        } // else if (threshold met)
        combo_on = combo_triggered = false;
    } // ELSE IF (pressed) meaning keyup

    return;
}

void matrix_scan_user_process_combo() {  // called from matrix_scan_user if combo_on

    // These combos are to be held for COMBO_HOLD term before triggering
    // to avoid accidental triggers while fast typing these common rolls (or on home row).
    // If repeats aren't deemed necessary, use tap_code here, otherwise register_code here
    // and add unregister_code to the !pressed switch in process_combo_event above.
    // Checking combo_triggered above can enable sending untriggered keys
    // and thus allow for longer COMBO_TERM. (recommend < TAPPING_TERM / 2)
    // still, really fast rolls, esp if they can go both ways, are going to be
    // a problem for this (ex er, re; io oi on qwerty), so maybe best to avoid them as
    // combos.
    // I've successfully added COMBO_HOLD Home Row combos without difficulty.
    // To use multiple home row mods, just put them down one at a time...works great.
    //
    if (!combo_triggered) {
        // do simple "on" on held actions and then turn on combo state in process_combo_event above,
        // then handle hold actions here,
        // before resolving in keyup event above.
        // if necessary (like releasing the underlying keys, or other cleanup)
        if (combo_on && (timer_elapsed(linger_timer) > COMBO_HOLD)) {
            saved_mods = get_mods();
            clear_mods();
            switch(combo_on) {  // combo_on is global, set in process_combo above


                case HC_FIND: // Held, so find selection (should work with most apps/platforms)
                    tap_SemKey(SK_COPY); // copy the selection
                    tap_SemKey(SK_FIND); // start find
                    tap_SemKey(SK_PSTE); // paste the copy. will find the selection
//                    tap_code(KC_ENT); // register current find
//                    tap_SemKey(SK_FAGN); // now find the next...
                    break;

                case HC_COPY: // held, so cut
                    tap_SemKey(SK_CUT);
                    break;
                case HC_PSTE: // held, so pastematch
                    tap_SemKey(SK_PSTM);
                    break;

#ifdef EN_HDIGRAPH_COMBOS
                case HC_Sh: // if these H digragh combos are held, then send T/SION instead
                case HC_Th: // TION = by far most common 4-gram, (then THAT/THER/WITH/MENT)
                    unregister_mods(MOD_MASK_SHIFT);
                    send_string("ion");
                    break;
                case HC_Gh: // held, send "ght"
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_T); // add "t" ("ght" is 55% of all "gh" occurrences)
                    break;
                case HC_Sch: //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_W); // add "w" // eliminate SFB schw
                    break;
                case HC_Ch: //
                case HC_Wh: //
                case HC_Ph: //
                    unregister_mods(MOD_MASK_SHIFT);  //
                    tap_code(KC_H); // send "h"
                    tap_code(KC_I); // add "i"
                    break;
//                case HC_Sc: //
//                    tap_code(KC_H); // add "h" (for "Sch", since were already on these keys.)
//                    break;
#endif // EN_HDIGRAPH_COMBOS

                case HC_AT:
                    tap_SemKey(SK_No); // ordinal number symbol
                    break;
                case HC_COLN: // held, so …
                    tap_SemKey(SK_ELPS); //
                    break;
//              case HC_OE:
                case HC_Q:
                    tap_code16(KC_BSPC); // held, so delete u
                    break;
                case HC_EQL:
                    tap_code16(KC_PERC); // Held, so send % (instead of =)
                    break;
                case HC_NDSH: // Held, so send M-Dash (instead of N-Dash).
                    tap_SemKey(SK_MDSH);  // M-Dash
                    break;

                case PC_STAB:
                    tap_code16(S(KC_TAB));
                    break;
                case PC_SENT:
                    tap_code16(S(KC_ENT));
                    break;
                case PC_LPRN:
                    tap_code16(KC_LPRN);
                    break;
                case PC_RPRN:
                    tap_code16(KC_RPRN);
                    break;
                case PC_COLN:
                    tap_code16(KC_COLN);
                    break;
                case PC_PERC:
                    tap_code16(KC_PERC);
                    break;
                case PC_DOLR:
                    tap_code16(S(KC_4));
                    break;
                case PC_TILD:
                    tap_code16(KC_TILD);
                    break;
                case PC_DASH:
                    tap_SemKey(SK_NDSH); // –
                    break;
//                case HC_ELIP:
                case PC_ELIP:
                    tap_SemKey(SK_ELPS); // …
                    break;
                case PC_EURO:
                    tap_SemKey(SK_EURO); // €
                    break;
                case PC_CENT:
                    tap_SemKey(SK_CENT); // ¢
                    break;
                case PC_JYEN:
                    tap_SemKey(SK_JPY); // ¥
                    break;
                case PC_BPND:
                    tap_SemKey(SK_BPND); // £
                    break;
                case PC_NEQL:
                    tap_SemKey(SK_NOTEQ); // ≠
                    break;
                case PC_DIV:
                    tap_SemKey(SK_DIV); // ÷
                    break;
                case PC_PLMN:
                    tap_SemKey(SK_PLMN); // ±
                    break;
                case PC_DEG:
                    tap_SemKey(SK_DEGR); // º
                    break;


// PRONOUN shenanigans
#ifdef EN_PRONOUN_COMBOS
#ifdef EN_PRONOUN_COMBOS_ALL

                case HC_here_4gram:
                case HC_there_5gram: // TYPE "there's" #7
                case HC_where_5gram: //

                case HC_your_4gram: // TYPE "your's"
                case HC_their_5gram: // TYPE "their's" #6

                    tap_code(KC_QUOT);
#endif // EN_PRONOUN_COMBOS_ALL
                    SEND_STRING("s ");
                    break;

//                case HC_ould_4gram: // TYPE "ould " #11
#ifdef EN_PRONOUN_COMBOS_ALL
                case HC_they_4gram: // TYPE "they " #23
                case HC_theyd_6gram: // TYPE "they'd " #23
                case HC_theyll_7gram: // TYPE "they'll " #23
                case HC_wed_4gram:
                case HC_well_5gram:
                case HC_youd_5gram:
                case HC_youll_6gram:
#endif // EN_PRONOUN_COMBOS_ALL
                case HC_I:
                case HC_Id:
                case HC_Ill:
                    unregister_mods(MOD_MASK_SHIFT);  //
                    send_string("'ve "); // or should it be "'nt"?
                    break;
#endif // EN_PRONOUN_COMBOS

// END PRONOUN shenanigans

    // if lingered, these will followup with the most common composed letter (Latinate language mashup stats)
                case HC_ACUT:
                case HC_GRV:
                case HC_CIRC:
                    tap_code16(KC_E); // this should use semkeys? éêè
                    break;
//                case HC_MACR:
//                    tap_code16(KC_O); // this should use semkeys? ō
//                    break;
                case HC_DIER:
                    tap_code16(KC_U); // this should use semkeys? ü
                    break;
//                case HC_RING:
//                    tap_code16(KC_A); // this should use semkeys? å
//                    break;
                case HC_CEDILLE:
                    tap_code16(KC_C); // this should use semkeys? ç
                    break;
                case HC_ENYE:
                    tap_SemKey(SK_ENYE); //
                    break;


                case HC_TYPE_LEFTCOMBO: // already "LeftComboTap" has been sent; if held, undo and send "LeftComboHeld"
                        send_string(LeftComboHeldE); //
                    break;
                case HC_TYPE_RIGHTCOMBO: // already "RightComboTap" has been sent; if held, add "RightComboHeld"
                        send_string(RightComboHeldE); //
                    break;

            } // switch

            set_mods(saved_mods); // Restore mods
            combo_triggered = true;
        } //  if (combo_on) {
    }
}
