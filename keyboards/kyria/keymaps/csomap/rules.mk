OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
ENCODER_ENABLE = yes      # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
UNICODEMAP_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
TAP_DANCE_ENABLE = no
COMBO_ENABLE = yes

SRC += unicode.c
SRC += casemodes.c
SRC += custom_autoshift.c
SRC += combos.c
SRC += user_keycodes.c
