
#include "phques.h"
#include "rgb.h"

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

// key flasher, to figure out mapping of key <=> row/col! see above.

#if false && defined(RGB_MATRIX_ENABLE)

extern led_config_t g_led_config;

#define MATRIX_ROWS 6
#define MATRIX_COLS 15

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

#if defined(MY_RGB) 

// ** XBows Nature **


#include QMK_KEYBOARD_H
#include "is31fl3731.h"
// #include "quantum/rgb_matrix/rgb_matrix_types.h"

#define NO_LED 255

//## copied from vial-qmk/keyboards/xbows/nature/nature.c
 uint8_t g_led_config_matrix_co[6][15] = { 
     {  0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14     },
     {  15,     16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29     },
     {  30,     31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44     },
     {  45,     46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     58,     59     },
     {  60,     61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     71,     72,     73,     NO_LED },
     {  74,     75,     76,     NO_LED, 77,     78,     79,     80,     NO_LED, 81,     82,     83,     84,     85,     86     }
 };

//## copied from vial-qmk/keyboards/xbows/nature/nature.c
 const is31fl3731_led_t PROGMEM g_is31fl3731_leds[IS31FL3731_LED_COUNT] = {
	{0, C1_3, C2_3, C3_3},   // L01
	{0, C1_4, C2_4, C3_4},   // L02
	{0, C1_5, C2_5, C3_5},   // L03
	{0, C1_6, C2_6, C3_6},   // L04
	{0, C1_7, C2_7, C3_7},   // L05
	{0, C1_8, C2_8, C3_8},   // L06
	{1, C1_3, C2_3, C3_3},   // L07
	{1, C1_4, C2_4, C3_4},   // L08
	{1, C1_5, C2_5, C3_5},   // L09
	{1, C1_6, C2_6, C3_6},   // L10
	{1, C1_7, C2_7, C3_7},   // L11
	{1, C1_8, C2_8, C3_8},   // L12
	{2, C1_3, C2_3, C3_3},   // L13
	{2, C1_4, C2_4, C3_4},   // L14
	{2, C1_5, C2_5, C3_5},   // L15

	{0, C6_1, C5_1, C4_1},   // L16
	{0, C6_2, C5_2, C4_2},   // L17
	{0, C6_3, C5_3, C4_3},   // L18
	{0, C6_6, C5_6, C4_6},   // L19
	{0, C6_7, C5_7, C4_7},   // L20
	{0, C6_8, C5_8, C4_8},   // L21
	{1, C6_1, C5_1, C4_1},   // L87
	{1, C6_2, C5_2, C4_2},   // L22
	{1, C6_3, C5_3, C4_3},   // L23
	{1, C6_6, C5_6, C4_6},   // L24
	{1, C6_7, C5_7, C4_7},   // L25
	{1, C6_8, C5_8, C4_8},   // L26
	{2, C6_1, C5_1, C4_1},   // L27
	{2, C6_2, C5_2, C4_2},   // L28
	{2, C6_3, C5_3, C4_3},   // L29

	{0, C9_1, C8_1, C7_1},   // L30
	{0, C9_2, C8_2, C7_2},   // L31
	{0, C9_3, C8_3, C7_3},   // L32
	{0, C9_4, C8_4, C7_4},   // L33
	{0, C9_5, C8_5, C7_5},   // L34
	{0, C9_6, C8_6, C7_6},   // L35
	{2, C6_8, C5_8, C4_8},   // L44
	{1, C9_1, C8_1, C7_1},   // L36
	{1, C9_2, C8_2, C7_2},   // L37
	{1, C9_3, C8_3, C7_3},   // L38
	{1, C9_4, C8_4, C7_4},   // L39
	{1, C9_5, C8_5, C7_5},   // L40
	{1, C9_6, C8_6, C7_6},   // L41
	{2, C6_6, C5_6, C4_6},   // L42
	{2, C6_7, C5_7, C4_7},   // L43


	{0, C1_11, C2_11, C3_11},   // L45
	{0, C1_12, C2_12, C3_12},   // L46
	{0, C1_13, C2_13, C3_13},   // L47
	{0, C1_14, C2_14, C3_14},   // L48
	{0, C1_15, C2_15, C3_15},   // L49
	{0, C1_16, C2_16, C3_16},   // L50
	{1, C9_9, C8_9, C7_9},      // L51
	{1, C1_11, C2_11, C3_11},   // L52
	{1, C1_12, C2_12, C3_12},   // L53
	{1, C1_13, C2_13, C3_13},   // L54
	{1, C1_14, C2_14, C3_14},   // L55
	{1, C1_15, C2_15, C3_15},   // L56
	{1, C1_16, C2_16, C3_16},   // L57
	{2, C9_4, C8_4, C7_4},      // L58
	{2, C9_5, C8_5, C7_5},      // L59

	{0, C6_9, C5_9, C4_9},      // L60
	{0, C6_10, C5_10, C4_10},   // L61
	{0, C6_11, C5_11, C4_11},   // L62
	{0, C6_14, C5_14, C4_14},   // L63
	{0, C6_15, C5_15, C4_15},   // L64
	{0, C6_16, C5_16, C4_16},   // L65
	{1, C9_10, C8_10, C7_10},   // L66
	{1, C6_9, C5_9, C4_9},      // L67
	{1, C6_10, C5_10, C4_10},   // L68
	{1, C6_11, C5_11, C4_11},   // L69
	{1, C6_14, C5_14, C4_14},   // L70
	{1, C6_15, C5_15, C4_15},   // L71
	{1, C6_16, C5_16, C4_16},   // L72
	{2, C9_6, C8_6, C7_6},      // L73

	{0, C9_9, C8_9, C7_9},      // L74
	{0, C9_10, C8_10, C7_10},   // L75
	{0, C9_11, C8_11, C7_11},   // L76
	{0, C9_12, C8_12, C7_12},   // L77
	{0, C9_13, C8_13, C7_13},   // L78
	{0, C9_14, C8_14, C7_14},   // L79
	{1, C9_11, C8_11, C7_11},   // L80
	{1, C9_12, C8_12, C7_12},   // L81
	{1, C9_13, C8_13, C7_13},   // L82
	{1, C9_14, C8_14, C7_14},   // L83
	{2, C1_6, C2_6, C3_6},      // L84
	{2, C1_7, C2_7, C3_7},      // L85
	{2, C1_8, C2_8, C3_8},      // L86
 };

 //-----------

static bool suspend = false;

// Left hand home row
uint8_t LH_HOME[] = {46, 47, 48, 49};

// Right hand home row
uint8_t RH_HOME[] = {53, 54, 55, 56};

static void set_keys(uint8_t *keys, uint8_t size, uint8_t r, uint8_t g, uint8_t b) {
    for (uint8_t i = 0; i < size; i++) {
        is31fl3731_set_color(keys[i], r, g, b);
    }
}

// NB: does not save user config or flush the LEDs, so call is31fl3731_flush() after this to see the changes.
bool rgb_set_indicators(layer_state_t state) {

	if (suspend) {
		// if suspended, don't set any indicators, just return (the background will be turned off in rgb_set_background)
		return true;
	}

    //-- set the home row keys to a blue, to help with orientation
	if (user_config.NightMode) {
        set_keys(LH_HOME, sizeof(LH_HOME), 10, 10, 60);
        set_keys(RH_HOME, sizeof(RH_HOME), 10, 10, 60);
    } else {
        set_keys(LH_HOME, sizeof(LH_HOME), 5,5,35);
        set_keys(RH_HOME, sizeof(RH_HOME), 5,5,35);
    }

    //-- set color of the arrow symbol to indicate the active layer
    uint16_t layer = get_highest_layer(state);

    // the led for the "arrow" symbol in middle column (between '5'-'6' and 'T'-'Y')
    //uint8_t arrowSymbolLed = g_led_config.matrix_co[1][6]; 
    const uint8_t arrowSymbolLed = g_led_config_matrix_co[1][6]; 

    switch (layer) {

        case L_QWERTY: // L_QWERTY / L_HD are both "base layers" = layer 0
            if (user_config.IsQwerty) { 
                // if QWERTY is the base layer, set the arrow symbol color.
                is31fl3731_set_color(arrowSymbolLed, 15, 10, 10);
            } else {
                // if HD is the base layer, set the arrow symbol color.
                is31fl3731_set_color(arrowSymbolLed, 0, 0, 60);
            }
            break;

        case L_SYM:
            is31fl3731_set_color(arrowSymbolLed, 50, 50, 0);
            break;

        case L_FUN:
            is31fl3731_set_color(arrowSymbolLed, 0, 60, 0);
            break;

        case L_NAV:
            is31fl3731_set_color(arrowSymbolLed, 5, 45, 45);
            break;

        case L_CFG:
            is31fl3731_set_color(arrowSymbolLed, 60, 0, 0);
            break;
    }

	//-- Set the led for the "Win" symbol 
	// (my XBows Nature has the Win key in the bottom row, so it's a good candidate for indicating OS mode)
    const uint8_t gui = g_led_config_matrix_co[5][1]; // the "Win" key.
    if (user_config.OSIndex == OS_Mac) {
        is31fl3731_set_color(gui, 0, 0, 0); // off/black for Mac.
    } else {
        is31fl3731_set_color(gui, 45,45,45); // brighter white for Windows/Linux. 
    }


	//-- Set the led for caps lock indicator
	const uint8_t capsLockLed = g_led_config_matrix_co[3][0]; // the "Caps Lock" key.
	if (host_keyboard_led_state().caps_lock) {
		is31fl3731_set_color(capsLockLed, 60, 0, 60); // purple when caps lock is on.
	} else {
		is31fl3731_set_color(capsLockLed, 0, 0, 0); // off/black when caps lock is off.
	}

	return true;
}

// NB: does not save user config or flush the LEDs, so call is31fl3731_flush() after this to see the changes.
void rgb_set_background(void) {
	if (suspend) {
		is31fl3731_set_color_all(0, 0, 0); // turn off all LEDs when suspended
	} else if (user_config.NightMode) {
		// set the background to a dim white
		is31fl3731_set_color_all(15,15,15);
	} else {
		// set the background to a (less) dim white
		is31fl3731_set_color_all(40, 40, 40);
	}
}

void rgb_refresh(void) {
	rgb_set_background(); // update the background immediately
	rgb_set_indicators(layer_state); // update the indicators immediately
	is31fl3731_flush();
}

void rgb_set_suspend(bool is_suspended) {
	suspend = is_suspended;
	rgb_refresh(); // update the LEDs immediately based on the new suspend state
}

#endif

