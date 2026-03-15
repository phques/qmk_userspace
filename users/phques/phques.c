
//#include QMK_KEYBOARD_H

#include "phques.h"

/*
    My globals
*/
user_config_t user_config = {0};

//PQ test debug
const char* const myStrings[] = {
    "philippe",
    "quesnel"
};

//-------------------

__attribute__ ((unused))
void keyboard_post_init_user(void) {
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
