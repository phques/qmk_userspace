
//#include QMK_KEYBOARD_H

#include "phques.h"
#include "sendstr.h"


const char* const myStrings[] = {
    "philippe",
    "quesnel"
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case PQ_SEND_STR_CAPI_1:
                SendLocalCapString(keycode);
                return false;

            case PQ_SEND_STR_CAPI_2:
                SendCapString("another string");
                return false;

            case PQ_SEND_MACRO_1:
                SEND_STRING("Your macro string here\n");
                send_word(TAP_CODE_DELAY);
                return false;
        }
    }

    return true;
}
