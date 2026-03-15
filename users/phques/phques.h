#pragma once

#ifndef USERSPACE
    #define USERSPACE
#endif

#include <quantum.h>

// Macro to convert a layer num [0..] to a layer bit.
// Use layer_state_is(...) or layer_state_cmp(...). to check layer state
#define LAYBIT(layer) ((layer_state_t)1 << (layer))


// ---- layers ----

#define HAS_QWERTY_LAYER

// enum my_layers for layout layers
enum my_layers {// must be difined before semantickeys.h
#ifdef HAS_QWERTY_LAYER
    L_QWERTY,   // QWERTY compatibility layer
#endif
    L_HD,       // Hands Down Alpha layer
    // L_SYM,      // symbols, punctuation, off-map alphas
    // L_FUN,      // function (left) & number rows (right)
    // L_NUM,      // navpad (left) & numpad (right)
    // L_NAV,      // meta keys (left) & nav pad (right)
    L_CFG,      // Media/Consumer controls; Keyboard settings
    L_count
};
#ifdef HAS_QWERTY_LAYER
#define L_BASELAYER HD_L_QWERTY
#else
#define L_BASELAYER HD_L_ALPHA
#endif


// ---- platforms ----

enum OS_Platform { // Used for platform support via SemKeys
    OS_Mac,     // Mac with ANSI_US_EXTENDED layout
    OS_Win,     // Win with default English/ANSI layout?
#ifdef INCLUDE_SK_Lux
    OS_Lux,     // Linux (Gnome?/KDE?/Boox Android?)
#endif
//    OS_iOS,     // iOS?
//    OS_And,     // Android (flavors?)
    OS_count
};


// ---- other ----

typedef union {
    uint32_t raw;
    struct {
        uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)? // used by semantickeys
        bool AdaptiveKeys; // Adaptive Keys On? (and advanced combos)
    };
} user_config_t; // used for persistent memory of settings (only 16 bytes avail on AVR?)


//----------

// temp 'strings' for testing string sending via custom keycodes
extern const char* const myStrings[];

// global user config variable, stored in EEPROM
extern user_config_t user_config;

extern void saveUserConfig(void);

// layout definition header
#define LAYOUT_HEADER_H "layouts/hd-pm/hd-pm-keys.h" // HandsDown Promethium

