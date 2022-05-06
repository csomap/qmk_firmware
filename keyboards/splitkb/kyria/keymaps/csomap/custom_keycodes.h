#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
   KC_I3WM_L = SAFE_RANGE,
   KC_I3WM_R,
   KC_I3WM_U,
   KC_I3WM_D,
   KC_I3WM_0,
   KC_I3WM_1,
   KC_I3WM_2,
   KC_I3WM_3,
   KC_I3WM_4,
   KC_I3WM_5,
   KC_I3WM_6,
   KC_I3WM_7,
   KC_I3WM_8,
   KC_I3WM_9,
   KC_I3WM_MOVE_L,
   KC_I3WM_MOVE_R,
   KC_I3WM_MOVE_U,
   KC_I3WM_MOVE_D,
   KC_I3WM_MOVE_0,
   KC_I3WM_MOVE_1,
   KC_I3WM_MOVE_2,
   KC_I3WM_MOVE_3,
   KC_I3WM_MOVE_4,
   KC_I3WM_MOVE_5,
   KC_I3WM_MOVE_6,
   KC_I3WM_MOVE_7,
   KC_I3WM_MOVE_8,
   KC_I3WM_MOVE_9,
   KC_I3WM_LAUNCHER,
   KC_I3WM_TERMINAL,
   KC_I3WM_LOCK_SCREEN,
   KC_I3WM_FULL_SCREEN,
   KC_I3WM_STACK,
   KC_I3WM_V_SPLIT,
   KC_I3WM_H_SPLIT,
   KC_I3WM_FORCECLOSE,
   KC_I3WM_SHUTDOWN_MENU,
   KC_I3WM_RESIZE,
   KC_I3WM_RELOAD_CONFIG,
   KC_I3WM_RESTART_WM,
};

bool process_custom_keycodes(uint16_t keycode, keyrecord_t* record);

bool can_autoshift_custom_kc(uint16_t keycode);
bool process_custom_autoshift(uint16_t keycode, bool shifted, bool pressed, keyrecord_t* record);
