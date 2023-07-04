OLED_ENABLE = no
ENCODER_ENABLE = no      # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no     # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no
CONSOLE_ENABLE = no
UNICODE_COMMON_ENABLE = yes
UNICODEMAP_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
LTO_ENABLE = yes

SRC += hun_unicode.c
SRC += i3wm.c
SRC += tapdances.c

INTROSPECTION_KEYMAP_C = combos.c
