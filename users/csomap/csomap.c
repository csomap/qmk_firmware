#include QMK_KEYBOARD_H

#include "i3wm.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    print("Processing record user");
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif
    if(!process_i3wm_keycode(keycode, record)) {
        return false;
    }
    return true;
}
