#pragma once

#include "custom_autoshift.h"

enum user_keycodes {
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
};

bool process_user_keycodes(uint16_t keycode, keyrecord_t* record);
