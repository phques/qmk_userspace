#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>



// enum my_layers for layout layers
enum my_layers {// must be difined before semantickeys.h
    L_QWERTY,   // QWERTY compatibility layer
    // L_HD,       // Hands Down Alpha layer
    // L_SYM,      // symbols, punctuation, off-map alphas
    // L_FUN,      // function (left) & number rows (right)
    // L_NUM,      // navpad (left) & numpad (right)
    // L_NAV,      // meta keys (left) & nav pad (right)
    L_CFG,      // Media/Consumer controls; Keyboard settings
    L_count
};

#define L_BASELAYER HD_L_QWERTY

enum custom_keycodes {
    PQ_SEND_STR_START = QK_KB_0,

    PQ_SEND_STR_CAPI_1 = PQ_SEND_STR_START,
    PQ_SEND_STR_CAPI_2,

    PQ_SEND_MACRO_1,
};

extern const char* const myStrings[];


