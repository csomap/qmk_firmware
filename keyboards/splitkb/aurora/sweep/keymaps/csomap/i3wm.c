#include "i3wm.h"

#define KC_TO_IDX(KC) (KC - I3WM_KEYCODE_START)

//GUI is implicit in all commands
const uint16_t i3wm_mapping[] = {
   [KC_TO_IDX(KC_I3_L)] = KC_LEFT,
   [KC_TO_IDX(KC_I3_R)] = KC_RIGHT,
   [KC_TO_IDX(KC_I3_U)] = KC_UP,
   [KC_TO_IDX(KC_I3_D)] = KC_DOWN,
   [KC_TO_IDX(KC_I3_0)] = KC_0,
   [KC_TO_IDX(KC_I3_1)] = KC_1,
   [KC_TO_IDX(KC_I3_2)] = KC_2,
   [KC_TO_IDX(KC_I3_3)] = KC_3,
   [KC_TO_IDX(KC_I3_4)] = KC_4,
   [KC_TO_IDX(KC_I3_5)] = KC_5,
   [KC_TO_IDX(KC_I3_6)] = KC_6,
   [KC_TO_IDX(KC_I3_7)] = KC_7,
   [KC_TO_IDX(KC_I3_8)] = KC_8,
   [KC_TO_IDX(KC_I3_9)] = KC_9,
   [KC_TO_IDX(KC_I3_MOVE_L)] = S(KC_LEFT),
   [KC_TO_IDX(KC_I3_MOVE_R)] = S(KC_RIGHT),
   [KC_TO_IDX(KC_I3_MOVE_U)] = S(KC_UP),
   [KC_TO_IDX(KC_I3_MOVE_D)] = S(KC_DOWN),
   [KC_TO_IDX(KC_I3_MOVE_0)] = S(KC_0),
   [KC_TO_IDX(KC_I3_MOVE_1)] = S(KC_1),
   [KC_TO_IDX(KC_I3_MOVE_2)] = S(KC_2),
   [KC_TO_IDX(KC_I3_MOVE_3)] = S(KC_3),
   [KC_TO_IDX(KC_I3_MOVE_4)] = S(KC_4),
   [KC_TO_IDX(KC_I3_MOVE_5)] = S(KC_5),
   [KC_TO_IDX(KC_I3_MOVE_6)] = S(KC_6),
   [KC_TO_IDX(KC_I3_MOVE_7)] = S(KC_7),
   [KC_TO_IDX(KC_I3_MOVE_8)] = S(KC_8),
   [KC_TO_IDX(KC_I3_MOVE_9)] = S(KC_9),
   [KC_TO_IDX(KC_I3_LAUNCHER)] = KC_D,
   [KC_TO_IDX(KC_I3_TERMINAL)] = KC_ENT,
   [KC_TO_IDX(KC_I3_LOCK_SCREEN)] = S(KC_D),
   [KC_TO_IDX(KC_I3_FULL_SCREEN)] = KC_F,
   [KC_TO_IDX(KC_I3_STACK)] = KC_GRV,
   [KC_TO_IDX(KC_I3_V_SPLIT)] = KC_V,
   [KC_TO_IDX(KC_I3_H_SPLIT)] = KC_N,
   [KC_TO_IDX(KC_I3_FORCECLOSE)] = S(KC_Q),
   [KC_TO_IDX(KC_I3_SHUTDOWN_MENU)] = KC_PAUSE,
   [KC_TO_IDX(KC_I3_RESIZE)] = KC_R,
   [KC_TO_IDX(KC_I3_RELOAD_CONFIG)] = S(KC_C),
   [KC_TO_IDX(KC_I3_RESTART_WM)] = S(KC_R),
};

bool is_valid(uint16_t i3wm_code) {
    return i3wm_code >= KC_I3_L && i3wm_code <= KC_I3_RESTART_WM;
}

void register_i3wm_code(uint16_t i3wm_code) {
    if(!is_valid(i3wm_code)) {
        return;
    }
    add_weak_mods(MOD_BIT(KC_LGUI));
    register_code16(i3wm_mapping[KC_TO_IDX(i3wm_code)]);
}

void unregister_i3wm_code(uint16_t i3wm_code) {
    if(!is_valid(i3wm_code)) {
        return;
    }
    unregister_code16(i3wm_mapping[KC_TO_IDX(i3wm_code)]);
}

bool process_i3wm_keycode(uint16_t keycode, keyrecord_t* record) {
    if(!is_valid(keycode)) {
        return true;
    }

    if(record->event.pressed) {
        register_i3wm_code(keycode);
    } else {
        unregister_i3wm_code(keycode);
    }
    return false;
}
