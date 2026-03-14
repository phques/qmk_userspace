#pragma once

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

// which rgb animations to keep
#ifdef RGB_MATRIX_ENABLE
/*

 * See https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects for all QMK RGB effects
 * add a #define line below to enable other RGB effect, e.g.,
 #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
*/
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL     // Single hue spinning spiral fades brightness
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
// #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_FLOWER_BLOOMING
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN

#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#endif


#define TAPPING_TOGGLE 2
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 170 // Mod TAP VS HOLD timing in milliseconds
#else
#define TAPPING_TERM 170
#endif

// Pick good defaults for enabling homerow modifiers
//#define HOLD_ON_OTHER_KEY_PRESS
//#define PERMISSIVE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT

// PQ, having difficulty with HRMs mod-taps triggering when I want to roll, so trying these:
// actually try with the default QMK settings first.. cant seem to find a setting that is useable for me :(
//#define CHORDAL_HOLD

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

