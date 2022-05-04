#include "user_keycodes.h"
#include "layers.h"

#define PROCESS_I3WM_KC(I3_KC, KC) \
    case I3_KC: \
        if(record->event.pressed) { \
            static const uint16_t cas_##I3_KC##_lc[] = { KC_LGUI, KC, CAS_SEQ_END }; \
            static const uint16_t cas_##I3_KC##_uc[] = { KC_LSFT, KC_LGUI, KC, CAS_SEQ_END }; \
            cas_start_sequence(cas_##I3_KC##_lc, cas_##I3_KC##_uc); \
        } \
        else { \
            cas_end(); \
        } \
        return false;

bool process_user_keycodes(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        PROCESS_I3WM_KC(KC_I3WM_L, KC_LEFT)
        PROCESS_I3WM_KC(KC_I3WM_R, KC_RIGHT)
        PROCESS_I3WM_KC(KC_I3WM_U, KC_UP)
        PROCESS_I3WM_KC(KC_I3WM_D, KC_DOWN)
        PROCESS_I3WM_KC(KC_I3WM_0, KC_0)
        PROCESS_I3WM_KC(KC_I3WM_1, KC_1)
        PROCESS_I3WM_KC(KC_I3WM_2, KC_2)
        PROCESS_I3WM_KC(KC_I3WM_3, KC_3)
        PROCESS_I3WM_KC(KC_I3WM_4, KC_4)
        PROCESS_I3WM_KC(KC_I3WM_5, KC_5)
        PROCESS_I3WM_KC(KC_I3WM_6, KC_6)
        PROCESS_I3WM_KC(KC_I3WM_7, KC_7)
        PROCESS_I3WM_KC(KC_I3WM_8, KC_8)
        PROCESS_I3WM_KC(KC_I3WM_9, KC_9)
    }
    return true;
}

