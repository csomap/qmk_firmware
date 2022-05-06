#include "custom_keycodes.h"
#include "i3wm.h"

#define HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_NAME)\
    case KC_##I3WM_NAME: \
        process_i3wm_event(I3WM_NAME, record->event.pressed);\
        return false;

bool process_custom_keycodes(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        // I3WM movement keycodes are handled by process_custom_autoshift
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_LAUNCHER);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_TERMINAL);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_LOCK_SCREEN);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_FULL_SCREEN);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_STACK);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_V_SPLIT);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_H_SPLIT);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_FORCECLOSE);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_SHUTDOWN_MENU);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_RESIZE);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_RELOAD_CONFIG);
        HANDLE_I3WM_CUSTOM_KEYCODE(I3WM_RESTART_WM);
    }
    return true;
}

bool can_autoshift_custom_kc(uint16_t keycode) {
    switch(keycode) {
        case KC_I3WM_L:
        case KC_I3WM_R:
        case KC_I3WM_U:
        case KC_I3WM_D:
        case KC_I3WM_0:
        case KC_I3WM_1:
        case KC_I3WM_2:
        case KC_I3WM_3:
        case KC_I3WM_4:
        case KC_I3WM_5:
        case KC_I3WM_6:
        case KC_I3WM_7:
        case KC_I3WM_8:
        case KC_I3WM_9:
            return true;
    }

    return false;
}

#define HANDLE_I3WM_MOVE_AUTOSHIFT(postfix) \
    case KC_I3WM_##postfix: \
        process_i3wm_event(shifted ? I3WM_MOVE_##postfix : I3WM_##postfix, pressed); \
        return false;

bool process_custom_autoshift(uint16_t keycode, bool shifted, bool pressed, keyrecord_t* record) {
    switch(keycode) {
        HANDLE_I3WM_MOVE_AUTOSHIFT(L);
        HANDLE_I3WM_MOVE_AUTOSHIFT(R);
        HANDLE_I3WM_MOVE_AUTOSHIFT(U);
        HANDLE_I3WM_MOVE_AUTOSHIFT(D);
        HANDLE_I3WM_MOVE_AUTOSHIFT(0);
        HANDLE_I3WM_MOVE_AUTOSHIFT(1);
        HANDLE_I3WM_MOVE_AUTOSHIFT(2);
        HANDLE_I3WM_MOVE_AUTOSHIFT(3);
        HANDLE_I3WM_MOVE_AUTOSHIFT(4);
        HANDLE_I3WM_MOVE_AUTOSHIFT(5);
        HANDLE_I3WM_MOVE_AUTOSHIFT(6);
        HANDLE_I3WM_MOVE_AUTOSHIFT(7);
        HANDLE_I3WM_MOVE_AUTOSHIFT(8);
        HANDLE_I3WM_MOVE_AUTOSHIFT(9);
    }
    return true;
}
