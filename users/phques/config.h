#pragma once

// undef all rgb animations 
#include "rgbUndefs.h"  // IWYU pragma: export

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

// disable a bunch of things to save space
#ifndef NO_ACTION_MACRO
#define NO_ACTION_MACRO
#endif
#ifndef NO_ACTION_FUNCTION
#define NO_ACTION_FUNCTION
#endif
#ifndef NO_ACTION_ONESHOT
#define NO_ACTION_ONESHOT
#endif
#ifndef NO_MUSIC_MODE
#define NO_MUSIC_MODE
#endif
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define TAPPING_TOGGLE 2
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 200 //PQ 170 // Mod TAP VS HOLD timing in milliseconds

// Pick good defaults for enabling homerow modifiers
//#define HOLD_ON_OTHER_KEY_PRESS
//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT

// PQ, having difficulty with HRMs mod-taps triggering when I want to roll, so trying this:
//  doesn't seem to be working!? not for rolls on home row modifiers anyway.
#define CHORDAL_HOLD

#ifdef TAP_CODE_DELAY
#undef TAP_CODE_DELAY
#endif
#define TAP_CODE_DELAY 20 // time between register/unregister (some keycodes go missing/out of sequence)
#define TAP_HOLD_CAPS_DELAY 180 // for Mac

#ifdef COMBO_ENABLE
    #ifdef COMBO_COUNT
        #undef COMBO_COUNT
    #endif

    #define COMBO_ALLOW_ACTION_KEYS
    #define COMBO_STRICT_TIMER
    #define EXTRA_SHORT_COMBOS
    #ifdef COMBO_TERM
        #undef COMBO_TERM
    #endif
// these COMBO_TERM have dilicate interactions with ADAPTIVE_TERM below.
    #define COMBO_TERM (TAPPING_TERM/4) // time to get all combo keys down
    #define COMBO_HOLD (TAPPING_TERM) // time to hold to trigger delayed combo
#endif

//---------

// PQ trying to solve probs on xbows nature.

// I think this is always ON 
#define ENABLE_RGB_MATRIX_SOLID_COLOR

// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_BREATHING

// #undef DEBOUNCE
// #define DEBOUNCE 5

// [---... trying chatgpt fix for xbows nature probs with rgb_matrix + 3-4> layers:

// #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120       //? this impact power impact, not CPU usage:, def=200

#undef RGB_MATRIX_LED_PROCESS_LIMIT
#define RGB_MATRIX_LED_PROCESS_LIMIT 4          // def=18

// ## I think this completly wrong !! 10 makes it Faster, not slower, takes More cpu !??
//#define RGB_MATRIX_LED_FLUSH_LIMIT 10           // def=16, time (ms) to wait before flushing updates to the LEDs.
#define RGB_MATRIX_LED_FLUSH_LIMIT 32           // def=16, time (ms) to wait before flushing updates to the LEDs.

// #define RGB_MATRIX_DISABLE_KEYCODES             //? i'd like to have this : at least :(

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR

// --- MEMORY REDUCTION ---
#define LAYER_STATE_8BIT

// ..----]
