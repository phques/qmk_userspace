# hardware features (set in each keyboard rules.mk)

# QMK software features

LEADER_ENABLE = no       # Enable the Leader Key feature
MOUSEKEY_ENABLE = no     # Mouse keys
UNICODE_ENABLE = no      # will need this for HD Polyglot
CONSOLE_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
AUTO_SHIFT_ENABLE = no  # requires 1936 bytes!

NKRO_ENABLE = no         # USB Nkey Rollover
KEY_OVERRIDE_ENABLE = no
TAP_DANCE_ENABLE = no
EXTRAKEY_ENABLE = yes   # Audio control and System control
COMBO_ENABLE = yes      # chording
MAGIC_ENABLE = no
RGB_MATRIX_ENABLE =yes

LTO_ENABLE = yes		# optimize at link time
EXTRAFLAGS += -flto

SRC += phques.c sendstr.c

CFLAGS += -fcommon


