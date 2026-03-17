
//#include QMK_KEYBOARD_H

#include "phques.h"

/*
    My globals
*/
user_config_t user_config = {0};
uint8_t  saved_mods = 0; // to pass state between process_record_user and matrix_scan_user

uint16_t linger_key = 0;  // keycode for linger actions (ex. "Qu")
uint32_t linger_timer = 0; // time to hold a key before something else happens.

uint8_t  combo_on = 0;           // for combo actions with hold behaviors
bool  combo_triggered = false;   // for one-shot-combo-actions


//-------------------

__attribute__ ((unused))
void keyboard_post_init_user(void) {
      // Custom initialization runs after the keyboard starts
//   debug_enable=true;
//   debug_matrix=true; // Optional: prints matrix scans to the console
//   debug_keyboard=true; // Optional: prints general keyboard info

    // Read the user config from EEPROM to facilitate
    // appropriate platform support

//    user_config.raw = 0; // reset
//    eeconfig_update_user(user_config.raw); // write the setings to EEPROM
    /*
    user_config.OSIndex use 0 for Mac; 1 for Win
     */
    user_config.raw = eeconfig_read_user();
    eeconfig_read_default_layer(); // get the default layer from eeprom.
}

void saveUserConfig(void) {
    eeconfig_update_user(user_config.raw); // write the setings to EEPROM
}
