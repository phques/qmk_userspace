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
enum my_layers {// must be defined before semantickeys.h
#ifdef HAS_QWERTY_LAYER
    L_QWERTY,   // QWERTY compatibility layer
#endif
    L_HD,       // Hands Down Alpha layer
    L_SYM,      // symbols, punctuation, off-map alphas
    L_FUN,      // function (left) & number rows (right)
    // L_NUM,      // navpad (left) & numpad (right)
    L_NAV,      // meta keys (left) & nav pad (right)
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

// typedef union {
//     uint32_t raw;
//     struct {
//         uint8_t OSIndex; // index of platforms (0=mac, 1=win, 2=lux)? // used by semantickeys
//         bool AdaptiveKeys; // Adaptive Keys On? (and advanced combos)
//     };
// } user_config_t; // used for persistent memory of settings (only 16 bytes avail on AVR?)
typedef union {
    uint32_t raw;
    struct {
        uint32_t OSIndex : 2;       // index of platforms (0=mac, 1=win, 2=lux)? // used by semantickeys
        uint32_t AdaptiveKeys : 1;  // Adaptive Keys On? (and advanced combos) 
        uint32_t BaseLayer : 1;     // which is the default (base) layer (0=QWERTY, 1=HD, always 0 if no QWERTY layer)
        uint32_t reserved : 28;     // reserved for future use (padding to fill 32 bits)
    };
} user_config_t; // used for persistent memory of settings (only 16 bytes avail on AVR?)


#define LINGER_TIME TAPPING_TERM * 1.2 // how long to hold before a time-depentant behavior begins
// how long to leave a state active before resetting like APPMENU or CAPSWORD
//#define STATE_RESET_TIME LINGER_TIME * 3
#define STATE_RESET_TIME (1000*3) // 3 seconds, which is long enough for app menu navigation.

// Adaptive (or MAGIC) keys are like a QMK Leader Key, but after (Adaptive Trailer)
#define ADAPTIVE_ENABLE
//#define ADAPT_SHIFT KC_COMM // keycode to precede alpha for one-shot shift (leader)
// PM doesn't use the common vowel block, so…
//#define ADAPT_H // eliminate SFBs AU/UA;EO/OE;LN;MN;NN using H (instead of ')
//#define ADAPT_AE_AU // Use AE->AU (instead of AH->AU, AH is somewhat common)
//#define FR_ADAPTIVES // eliminate 'h SFB for French
//#define DE_ADAPTIVES // alternate AU SFB treatment for German (same as ADAPT_AE_AU)
//#define HD_MAGIC HD_HASH // generic MAGIC_KEY (I use for text macros)
//#define HD_MAGIC_A KC_ENT // MAGIC_KEY dependent on alpha (vowel hand?)
//#define HD_MAGIC_B KC_BSPC // MAGIC_KEY dependent on alpha (consonant hand?)

#ifdef COMBO_HOLD
    #undef ADAPTIVE_TERM
    #define ADAPTIVE_TERM COMBO_HOLD * 1.35  // use COMBO_HOLD time as a standard threshold (same reaction time)
#else
    #define ADAPTIVE_TERM (TAPPING_TERM/4) // rolling threshold
#endif


#define EN_HDIGRAPH_COMBOS // English H-Digraph combos (Th,Ch,Wh,Sh,Gh,Ph,Sch)
#define EN_PRONOUN_COMBOS // English First Person pronoun combos (I, I'm, I've I'd I'll etc) (184 bytes on AVR)
#define EN_PRONOUN_COMBOS_ALL  // combos for you('ve), We('ve), They('ve) etc. (616 bytes on AVR)
#define EN_W_PRONOUNS


#define tap_HDkey(kc) ({is_SemKey(kc) ? tap_SemKey(kc) : tap_code16(kc);})
#define register_HDkey(kc) ({is_SemKey(kc) ? register_SemKey(kc) : register_code16(kc);})
#define unregister_HDkey(kc) ({is_SemKey(kc) ? unregister_SemKey(kc) : unregister_code16(kc);})

#define register_linger_key(kc) ({register_HDkey(kc);linger_key = kc;linger_timer = timer_read();})
#define unregister_linger_key() ({unregister_HDkey(linger_key) ;linger_key = 0;})


//----------

// global user config variable, stored in EEPROM
extern user_config_t user_config;
extern uint8_t  saved_mods; // to pass state between process_record_user and matrix_scan_user

extern uint16_t linger_key;  // keycode for linger actions (ex. "Qu")
extern uint32_t linger_timer; // time to hold a key before something else happens.
extern uint32_t appmenu_timer;  // time to leave appmenu active before shutting it down automatically.
extern bool appmenu_on;  // appmenu triggered (after holding key)
extern bool mods_held;  // need to remember how we entered the appmenu state

extern uint8_t  combo_on;           // for combo actions with hold behaviors
extern bool  combo_triggered;   // for one-shot-combo-actions


extern void saveUserConfig(void);

// layout definition header
#define LAYOUT_HEADER_H "layouts/hd-pm/hd-pm-keys.h" // HandsDown Promethium

