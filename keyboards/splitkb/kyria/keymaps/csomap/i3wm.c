#include "i3wm.h"

#include <stdio.h>

//GUI is implicit in all commands
const uint16_t i3wm_commands[] = {
   [I3WM_L] = KC_LEFT,
   [I3WM_R] = KC_RIGHT,
   [I3WM_U] = KC_UP,
   [I3WM_D] = KC_DOWN,
   [I3WM_0] = KC_0,
   [I3WM_1] = KC_1,
   [I3WM_2] = KC_2,
   [I3WM_3] = KC_3,
   [I3WM_4] = KC_4,
   [I3WM_5] = KC_5,
   [I3WM_6] = KC_6,
   [I3WM_7] = KC_7,
   [I3WM_8] = KC_8,
   [I3WM_9] = KC_9,
   [I3WM_MOVE_L] = S(KC_LEFT),
   [I3WM_MOVE_R] = S(KC_RIGHT),
   [I3WM_MOVE_U] = S(KC_UP),
   [I3WM_MOVE_D] = S(KC_DOWN),
   [I3WM_MOVE_0] = S(KC_0),
   [I3WM_MOVE_1] = S(KC_1),
   [I3WM_MOVE_2] = S(KC_2),
   [I3WM_MOVE_3] = S(KC_3),
   [I3WM_MOVE_4] = S(KC_4),
   [I3WM_MOVE_5] = S(KC_5),
   [I3WM_MOVE_6] = S(KC_6),
   [I3WM_MOVE_7] = S(KC_7),
   [I3WM_MOVE_8] = S(KC_8),
   [I3WM_MOVE_9] = S(KC_9),
   [I3WM_LAUNCHER] = KC_D,
   [I3WM_TERMINAL] = KC_ENT,
   [I3WM_LOCK_SCREEN] = S(KC_D),
   [I3WM_FULL_SCREEN] = KC_F,
   [I3WM_STACK] = KC_GRV,
   [I3WM_V_SPLIT] = KC_V,
   [I3WM_H_SPLIT] = KC_N,
   [I3WM_FORCECLOSE] = S(KC_Q),
   [I3WM_SHUTDOWN_MENU] = KC_PAUSE,
   [I3WM_RESIZE] = KC_R,
   [I3WM_RELOAD_CONFIG] = S(KC_C),
   [I3WM_RESTART_WM] = S(KC_R),
};

void process_i3wm_event(i3wm_event_t event, bool pressed) {
    if(pressed) {
        //char text[64];
        //sprintf(text, "i3wm_event: %x, command: %x\n", event, i3wm_commands[event]);
        //send_string(text);
        add_weak_mods(MOD_BIT(KC_LGUI));
        register_code16(i3wm_commands[event]);
    } else {
        unregister_code16(i3wm_commands[event]);
    }
}
