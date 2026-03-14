#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

// Macro to convert a layer num [0..] to a layer bit.
// Use layer_state_is(...) or layer_state_cmp(...). to check layer state
#define LAYBIT(layer) ((layer_state_t)1 << (layer))


// enum my_layers for layout layers
enum my_layers {// must be difined before semantickeys.h
    L_QWERTY,   // QWERTY compatibility layer
    L_HD,       // Hands Down Alpha layer
    // L_SYM,      // symbols, punctuation, off-map alphas
    // L_FUN,      // function (left) & number rows (right)
    // L_NUM,      // navpad (left) & numpad (right)
    // L_NAV,      // meta keys (left) & nav pad (right)
    L_CFG,      // Media/Consumer controls; Keyboard settings
    L_count
};



// enum for custom keycodes, starting at safe range (QK_KB_0..QK_KB_255)
enum custom_keycodes {
    PQ_SEND_STR_START = QK_KB_0,

    PQ_SEND_STR_CAPI_1 = PQ_SEND_STR_START,
    PQ_SEND_STR_CAPI_2,

    PQ_SEND_MACRO_1,
};

// temp 'strings' for testing string sending via custom keycodes
extern const char* const myStrings[];


// layout definition header
#define LAYOUT_HEADER "hd-pm-keys.h" // HandsDown Promethium
