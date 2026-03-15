
#include "phques.h"
#include "sendstr.h"

static char ascii_to_upper(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - ('a' - 'A');
    }

    return ch;
}

void SendCapString(const char* str) {
    if (str == NULL || str[0] == '\0') {
        return;
    }

    send_char(ascii_to_upper(str[0]));
    send_string(str + 1);
}

