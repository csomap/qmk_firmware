#pragma once

#include QMK_KEYBOARD_H

typedef enum i3wm_keycode {
   KC_I3_L = I3WM_KEYCODE_START,
   KC_I3_R,
   KC_I3_U,
   KC_I3_D,
   KC_I3_0,
   KC_I3_1,
   KC_I3_2,
   KC_I3_3,
   KC_I3_4,
   KC_I3_5,
   KC_I3_6,
   KC_I3_7,
   KC_I3_8,
   KC_I3_9,
   KC_I3_MOVE_L,
   KC_I3_MOVE_R,
   KC_I3_MOVE_U,
   KC_I3_MOVE_D,
   KC_I3_MOVE_0,
   KC_I3_MOVE_1,
   KC_I3_MOVE_2,
   KC_I3_MOVE_3,
   KC_I3_MOVE_4,
   KC_I3_MOVE_5,
   KC_I3_MOVE_6,
   KC_I3_MOVE_7,
   KC_I3_MOVE_8,
   KC_I3_MOVE_9,
   KC_I3_LAUNCHER,
   KC_I3_TERMINAL,
   KC_I3_LOCK_SCREEN,
   KC_I3_FULL_SCREEN,
   KC_I3_STACK,
   KC_I3_V_SPLIT,
   KC_I3_H_SPLIT,
   KC_I3_FORCECLOSE,
   KC_I3_SHUTDOWN_MENU,
   KC_I3_RESIZE,
   KC_I3_RELOAD_CONFIG,
   KC_I3_RESTART_WM,
   KC_I3_SPT,
   KC_I3_MAX,

   // aliases
   KC_I3_ML = KC_I3_MOVE_L,
   KC_I3_MR = KC_I3_MOVE_R,
   KC_I3_MU = KC_I3_MOVE_U,
   KC_I3_MD = KC_I3_MOVE_D,
   KC_I3_M0 = KC_I3_MOVE_0,
   KC_I3_M1 = KC_I3_MOVE_1,
   KC_I3_M2 = KC_I3_MOVE_2,
   KC_I3_M3 = KC_I3_MOVE_3,
   KC_I3_M4 = KC_I3_MOVE_4,
   KC_I3_M5 = KC_I3_MOVE_5,
   KC_I3_M6 = KC_I3_MOVE_6,
   KC_I3_M7 = KC_I3_MOVE_7,
   KC_I3_M8 = KC_I3_MOVE_8,
   KC_I3_M9 = KC_I3_MOVE_9,
} i3wm_keycode_t;

void register_i3wm_code(uint16_t keycode);
void unregister_i3wm_code(uint16_t keycode);

bool process_i3wm_keycode(uint16_t keycode, keyrecord_t* record);
