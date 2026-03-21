
//#include QMK_KEYBOARD_H

#include "phques.h"
#include <stdbool.h>
#include <stdint.h>
#include "print.h"

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

//----------

/*
From /Users/philippe/qmk_userspace/keyboards/xbows/nature/nature.c

For xbows Nature.

6rows x 15cols = 90, 
Used: 87 => 86 LEDs for keys + 1 for the "arrow" symbol in middle column (between '5'-'6' and 'T'-'Y')
Row is from top to bottom
Col is from left to right

 Mostly 1:1 mapping with keys EXCEPT:
+ [1][6]  = 'arrow'
+ [2][6]  = PgUp !!  (which is physically at the end of the row)
+ [4][13] = UpArrow, ([14] no_led)

+ bottom row[5][..]:
   0     1    2 (3)  4      5     6      7 (8)   9    10 ...
   Ctrl  Win  Alt    Space  Ctrl  Shift  Space   Alt  Fn ...

 led_config_t g_led_config = { {
     {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14     },
     {  15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29     },
     {  30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44     },
     {  45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58,     59     },
     {  60,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     71,     72,     73,     NO_LED },
     {  74,     75,     76,     NO_LED, 77,     78,     79,     80,     NO_LED, 81,     82,     83,     84,     85,     86     }
 }, {

*/

#if 0
#define MATRIX_ROWS 6
#define MATRIX_COLS 15
// key flasher, to figure out mapping of key <=> row/col! see above.
bool rgb_matrix_indicators_user(void) {
    static uint8_t row = 0;
    static uint8_t col = 0;
    uint8_t led = 0;
    
    // rgb_matrix_set_color_all(0, 0, 0);

    led = g_led_config.matrix_co[row][col];
    rgb_matrix_set_color(led, 128,128,128);

    col = (col + 1) % MATRIX_COLS;
    if (col == 0) {
        row = (row + 1) % MATRIX_ROWS;
    }

    wait_ms(150);

    return true;
}
#endif

//-------------------

// Left hand home row
uint8_t LH_HOME[] = {46, 47, 48, 49};

// Right hand home row
uint8_t RH_HOME[] = {53, 54, 55, 56};

void set_keys(uint8_t *keys, uint8_t size, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < size; i++) {
        rgb_matrix_set_color(keys[i], r, g, b);
    }
}

bool rgb_matrix_indicators_user(void) {

    // set the home row keys to a dim white, to help with orientation
    // set_keys(LH_HOME, sizeof(LH_HOME), 50, 50, 50);
    // set_keys(RH_HOME, sizeof(RH_HOME), 50, 50, 50);

    uint16_t layer = get_highest_layer(layer_state);

    // set color of the arrow symbol to indicate the active layer

    // the led for the "arrow" symbol in middle column (between '5'-'6' and 'T'-'Y')
    uint8_t arrowSymbolLed = g_led_config.matrix_co[1][6]; 

    switch (layer) {

        case L_QWERTY: // L_QWERTY / L_HD are both "base layers" = layer 0
#ifdef HAS_QWERTY_LAYER
            if (user_config.BaseLayer == 0) { 
                // if QWERTY is the base layer, use only one uniform background color.
                // rgb_matrix_set_color(arrowSymbolLed, 30, 30, 30);
                rgb_matrix_set_color_all(10, 10, 10);
            } else {
                // if HD is the base layer, set the arrow symbol color.
                rgb_matrix_set_color(arrowSymbolLed, 10, 40, 40);
            }
#else
            rgb_matrix_set_color(arrowSymbolLed, 10, 40, 40);
#endif
            break;

        case L_SYM:
            rgb_matrix_set_color(arrowSymbolLed, 60,0,0);
            break;

        case L_FUN:
            rgb_matrix_set_color(arrowSymbolLed, 0,60,0);
            break;

        case L_NAV:
            rgb_matrix_set_color(arrowSymbolLed, 0,0,60);
            break;

        case L_CFG:
            rgb_matrix_set_color(arrowSymbolLed, 50,50,0);
            break;
    }

    // let the normal stuff do its thing (like caps lock indicator, etc.)
    return true;
}


//------------

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
