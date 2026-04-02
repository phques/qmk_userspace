
//#include QMK_KEYBOARD_H

#include "phques.h"
#include <stdbool.h>
#include <stdint.h>
#include "semantickeys.h"
//#include "print.h"

#if defined(MY_RGB)
#    include QMK_KEYBOARD_H
#    include "is31fl3731.h"
#    include "rgb.h"
// #    include "quantum/rgb_matrix/rgb_matrix_types.h"
#endif

/*
    My globals
*/
user_config_t user_config = {0};
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user

uint16_t linger_key = 0;  // keycode for linger actions (ex. "Qu")
uint32_t linger_timer = 0; // time to hold a key before something else happens.
uint32_t appmenu_timer = 0;  // time to leave appmenu active before shutting it down automatically.
bool appmenu_on = false;  // appmenu triggered (after holding key)
bool mods_held = false;  // need to remember how we entered the appmenu state

uint8_t  combo_on = 0;           // for combo actions with hold behaviors
bool  combo_triggered = false;   // for one-shot-combo-actions

#ifdef ADAPTIVE_ENABLE
uint16_t preprior_keycode = KC_NO;
uint16_t prior_keycode = KC_NO;
uint16_t prior_keydown = 0; // timer of keydown for adaptive threshhold.
#endif

//------------

// Function prototypes
static void initializeUserConfig(void);

//----------

__attribute__ ((unused))
void keyboard_post_init_user(void) {
    // Custom initialization runs after the keyboard starts
    
    // Read the user config from EEPROM to facilitate
    // appropriate platform support
    /*
    user_config.OSIndex use 0 for Mac; 1 for Win
     */
    user_config.raw = eeconfig_read_user();

	// if this is the first time we're running, or if the EEPROM got corrupted, set defaults and save to EEPROM.
	if (user_config.InitialSetupDone == 0) { 
		initializeUserConfig(); // set defaults for new users (or if EEPROM is corrupted)
		saveUserConfig(); // write that to EEPROM so we don't have to do it again.
	} else {
    	eeconfig_read_default_layer(); // get the default layer from eeprom.	
	}

#if defined(MY_RGB)
    // initialize the RGB matrix driver
    // rgb_matrix_driver.init(); 

    is31fl3731_init_drivers();

	rgb_set_background();
    rgb_set_indicators(layer_state);
    
	is31fl3731_flush();

#endif

//   debug_enable=true;
//   debug_matrix=true; // Optional: prints matrix scans to the console
//   debug_keyboard=true; // Optional: prints general keyboard info
}


static void initializeUserConfig(void) {
	selectOS(SK_Mac); // default to Mac Semkeys
	selectLayer(L_BASELAYER);

	user_config.InitialSetupDone = 1; // we've done the initial setup, so set this flag.
	user_config.NightMode = 0; // default to Night Mode off, since it can be hard to see the keys with the dimmed background.

	saveUserConfig(); // write the setings to EEPROM
}

void saveUserConfig(void) {
    eeconfig_update_user(user_config.raw); // write the setings to EEPROM
}


// NB: does not save user config.
void selectLayer(uint16_t keycode) {
    switch (keycode) {
#ifdef HAS_QWERTY_LAYER
        case HD_L_QWERTY:
            user_config.AdaptiveKeys = false; // no adaptive keys on QWERTY
            user_config.IsQwerty = 1;
            combo_disable(); // disable combos for QWERTY layer (and enable for HD)
            break;
#endif
        case HD_L_ALPHA:
            user_config.AdaptiveKeys = true;
            user_config.IsQwerty = 0;
            combo_enable(); // enable combos for HD layer (and disable for QWERTY)
            break;
        default:
            return;
    }

    set_single_persistent_default_layer(keycode - L_BASELAYER); // Remember default layer after powerdown
}

// NB: does not save user config.
void selectOS(uint16_t keycode) {
    switch (keycode) {
        case SK_Lux: // switch to linux (or Win if not defined)
#ifdef INCLUDE_HD_Lux
            user_config.OSIndex          = OS_Lux; // for Linux Semkeys
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
            break;
#endif
        case SK_Win:                               // switch to windows
            user_config.OSIndex          = OS_Win; // for Windows Semkeys
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = true;
            break;

        case SK_Mac:                               // Back to default
            user_config.OSIndex          = OS_Mac; // for Mac Semkeys
            keymap_config.swap_lctl_lgui = keymap_config.swap_rctl_rgui = false;
            break;
    }
}


void refreshIndicators(layer_state_t state) {
	rgb_set_indicators(state);
	is31fl3731_flush();
}

void toggleNightMode(void) {
	user_config.NightMode = !user_config.NightMode; // toggle Night Mode
	rgb_set_background(); // update the background immediately
	is31fl3731_flush();
	saveUserConfig(); // save the setting to EEPROM
}

//----------
layer_state_t layer_state_set_user(layer_state_t state) {
    refreshIndicators(state);
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    refreshIndicators(state);
    return state;
}
bool led_update_user(led_t led_state) {
    if (led_state.caps_lock) {
        // Actions to perform when Caps Lock is ON
        refreshIndicators(layer_state);
    } else {
        // Actions to perform when Caps Lock is OFF
        refreshIndicators(layer_state);
    }
    return true; // Return true to allow the keyboard's default LED behavior
}