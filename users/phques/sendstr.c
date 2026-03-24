
#include "quantum.h"
#include "sendstr.h"

static char ascii_to_upper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - ('a' - 'A');
    }

    return ch;
}

// Send a string, but if Shift is held, capitalize the first character (if it's a letter).
void SendCapString(const char* str) {
    if (str == NULL || str[0] == '\0') {
        return;
    }

    if (get_mods() & MOD_MASK_SHIFT) {
        uint8_t currentMods = get_mods() | get_weak_mods() /* | get_oneshot_mods() */;
        del_mods(MOD_MASK_SHIFT);
        send_keyboard_report();

        send_char(ascii_to_upper(str[0]));
        send_string(str + 1);

        set_mods(currentMods);
        send_keyboard_report();
    } else {
        send_string(str);
    }
}

