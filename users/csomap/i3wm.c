#include "i3wm.h"

#define I3WM_KC_TO_IDX(KC) (KC - I3WM_KEYCODE_START)

//GUI is implicit in all commands
const uint16_t i3wm_mapping[] = {
   [I3WM_KC_TO_IDX(KC_I3_L)] = KC_LEFT,
   [I3WM_KC_TO_IDX(KC_I3_R)] = KC_RIGHT,
   [I3WM_KC_TO_IDX(KC_I3_U)] = KC_UP,
   [I3WM_KC_TO_IDX(KC_I3_D)] = KC_DOWN,
   [I3WM_KC_TO_IDX(KC_I3_0)] = KC_0,
   [I3WM_KC_TO_IDX(KC_I3_1)] = KC_1,
   [I3WM_KC_TO_IDX(KC_I3_2)] = KC_2,
   [I3WM_KC_TO_IDX(KC_I3_3)] = KC_3,
   [I3WM_KC_TO_IDX(KC_I3_4)] = KC_4,
   [I3WM_KC_TO_IDX(KC_I3_5)] = KC_5,
   [I3WM_KC_TO_IDX(KC_I3_6)] = KC_6,
   [I3WM_KC_TO_IDX(KC_I3_7)] = KC_7,
   [I3WM_KC_TO_IDX(KC_I3_8)] = KC_8,
   [I3WM_KC_TO_IDX(KC_I3_9)] = KC_9,
   [I3WM_KC_TO_IDX(KC_I3_MOVE_L)] = S(KC_LEFT),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_R)] = S(KC_RIGHT),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_U)] = S(KC_UP),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_D)] = S(KC_DOWN),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_0)] = S(KC_0),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_1)] = S(KC_1),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_2)] = S(KC_2),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_3)] = S(KC_3),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_4)] = S(KC_4),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_5)] = S(KC_5),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_6)] = S(KC_6),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_7)] = S(KC_7),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_8)] = S(KC_8),
   [I3WM_KC_TO_IDX(KC_I3_MOVE_9)] = S(KC_9),
   [I3WM_KC_TO_IDX(KC_I3_PREV_WS)] = A(KC_LBRC),
   [I3WM_KC_TO_IDX(KC_I3_NEXT_WS)] = A(KC_RBRC),
   [I3WM_KC_TO_IDX(KC_I3_LAUNCHER)] = KC_D,
   [I3WM_KC_TO_IDX(KC_I3_TERMINAL)] = KC_ENT,
   [I3WM_KC_TO_IDX(KC_I3_LOCK_SCREEN)] = S(KC_D),
   [I3WM_KC_TO_IDX(KC_I3_FULL_SCREEN)] = KC_F,
   [I3WM_KC_TO_IDX(KC_I3_STACK)] = KC_GRV,
   [I3WM_KC_TO_IDX(KC_I3_V_SPLIT)] = KC_V,
   [I3WM_KC_TO_IDX(KC_I3_H_SPLIT)] = KC_N,
   [I3WM_KC_TO_IDX(KC_I3_FORCECLOSE)] = S(KC_Q),
   [I3WM_KC_TO_IDX(KC_I3_SHUTDOWN_MENU)] = KC_ESC,
   [I3WM_KC_TO_IDX(KC_I3_RESIZE)] = KC_R,
   [I3WM_KC_TO_IDX(KC_I3_RELOAD_CONFIG)] = S(KC_C),
   [I3WM_KC_TO_IDX(KC_I3_RESTART_WM)] = S(KC_R),
   [I3WM_KC_TO_IDX(KC_I3_SPT_SHOW)] = KC_BSPC,
   [I3WM_KC_TO_IDX(KC_I3_SPT_PLAY)] = S(KC_F11),
   [I3WM_KC_TO_IDX(KC_I3_SPT_PREV)] = S(KC_F10),
   [I3WM_KC_TO_IDX(KC_I3_SPT_NEXT)] = S(KC_F12),
   [I3WM_KC_TO_IDX(KC_I3_VOLD)] = KC_PGDN,
   [I3WM_KC_TO_IDX(KC_I3_VOLU)] = KC_PGUP,
   [I3WM_KC_TO_IDX(KC_I3_PRINTSCR)] = KC_PSCR,
   [I3WM_KC_TO_IDX(KC_I3_PRINTSCR_WINDOW)] = A(KC_PSCR),
};

static bool is_valid(uint16_t i3wm_code) {
    return i3wm_code >= KC_I3_L && i3wm_code < KC_I3_MAX;
}

void register_i3wm_code(uint16_t i3wm_code) {
    if(!is_valid(i3wm_code)) {
        return;
    }
#ifdef CONSOLE_ENABLE
    uprintf("I3WM KC: %u, mapping: %u\n", i3wm_code, I3WM_KC_TO_IDX(i3wm_code));
#endif
    register_code(KC_LGUI);
    register_code16(i3wm_mapping[I3WM_KC_TO_IDX(i3wm_code)]);
    unregister_code16(i3wm_mapping[I3WM_KC_TO_IDX(i3wm_code)]);
    unregister_code(KC_LGUI);
}

bool process_i3wm_keycode(uint16_t keycode, keyrecord_t* record) {
    if(!is_valid(keycode)) {
        return true;
    }

    if(record->event.pressed) {
        register_i3wm_code(keycode);
    }
    return false;
}
