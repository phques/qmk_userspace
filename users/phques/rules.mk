# hardware features (set in each keyboard rules.mk)

# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = no     # Mouse keys
UNICODE_ENABLE = no      # will need this for HD Polyglot
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
AUTO_SHIFT_ENABLE = no  # requires 1936 bytes!
NKRO_ENABLE = no         # USB Nkey Rollover

TAP_DANCE_ENABLE = no

# xbows nature freezes on startup with this!?
# will have to go the moutis way and do it manually.
KEY_OVERRIDE_ENABLE = no 

EXTRAKEY_ENABLE = yes   # Audio control and System control
COMBO_ENABLE = yes      # chording
MAGIC_ENABLE = yes		#  for swap gui/ctrl and more.
CAPS_WORD_ENABLE = yes
LAYER_LOCK_ENABLE = yes

# xbows nature can't handle animations with >3-4 layers, + combos +  adaptives (my own)
RGB_MATRIX_ENABLE =  no
RGB_MATRIX_DRIVER = is31fl3731 # trying out suggested fix from chatgpt
RGBLIGHT_ENABLE = no

# rgb light is not supported at all,
# so try this low level, see if it builds:
# fails too: LED_MATRIX_ENABLE = yes

#pq debugging, must also set debug_enable=true in keyboard_post_init_user
CONSOLE_ENABLE = no
DEBUG_ENABLE = no
KEYCODE_STRING_ENABLE = no

# pq, xbows nature HRMs gettingStuck .. try this suggestion
# also, it is suggested to connect directly to the usb port, not through a hub, to avoid this problem.
# and/or #define DEBOUNCE 5 in config.h
DEBOUNCE_TYPE = sym_eager_pk

LTO_ENABLE = yes		# optimize at link time
EXTRAFLAGS += -flto

SRC += phques.c sendstr.c semantickeys.c 
SRC += processRecord.c processCombo.c processKeyOverride.c processAdaptive.c
SRC += matrixScanUser.c app_menu.c 

CFLAGS += -fcommon

# Manually include the driver
COMMON_VPATH += $(DRIVER_PATH)/led/issi
SRC += is31fl3731.c
I2C_DRIVER_REQUIRED = yes


 