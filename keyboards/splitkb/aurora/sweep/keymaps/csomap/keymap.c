#include QMK_KEYBOARD_H

#include "layers.h"
#include "i3wm.h"
#include "tapdances.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
        //Default layer
        [_DEFAULT] = LAYOUT(
            KC_Q,         KC_W,               KC_E,            KC_R,                KC_T,              KC_Y, KC_U,               KC_I,                 KC_O,             KC_P,
            LSFT_T(KC_A), LT(_FUNCTION,KC_S), LT(_MOUSE,KC_D), LT(_SYM_RIGHT,KC_F), KC_G,              KC_H, LT(_SYM_LEFT,KC_J), LT(_NAVIGATION,KC_K), LT(_NUMPAD,KC_L), LSFT_T(KC_SCLN),
            KC_Z,         LCTL_T(KC_X),       LALT_T(KC_C),    KC_V,                KC_B,              KC_N, KC_M,               LALT_T(KC_COMM),      LCTL_T(KC_DOT),   KC_SLSH,
                                    LT(_I3WM_CMD, KC_ESC),    LT(_I3WM_NAV, KC_SPC),                   LT(_ALWAYS_ACCESSIBLE, KC_BSPC), LT(_I3WM_CMD, KC_ENT)
        ),
        //Mouse
        [_MOUSE] = LAYOUT(
            _______, _______, _______, _______, _______,         _______, _______, KC_WH_U, _______, _______,
            _______, KC_BTN2, KC_NO,   KC_BTN1, _______,         _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
            _______, _______, _______, _______, _______,         _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,
                                       _______, _______,         _______, _______
        ),
        //Navigation
        [_NAVIGATION] = LAYOUT(
            KC_HOME, _______, KC_UP,   KC_PGUP, _______,          _______, _______, _______, _______,       _______,
            KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, _______,          _______, KC_LGUI, KC_NO,   LCTL(KC_LALT), LCA(KC_LSFT),
            KC_END, _______, _______, KC_PGDN, _______,          _______, _______, _______, _______,       _______,
                                       _______, _______,          _______, _______
        ),
        //I3 navigation
        [_I3WM_NAV] = LAYOUT(
            _______, KC_I3_7, KC_I3_8, KC_I3_9, _______,           _______, _______, _______, _______, _______,
            KC_LSFT, KC_I3_1, KC_I3_2, KC_I3_3, _______,           _______, KC_I3_L, KC_I3_D, KC_I3_U, KC_I3_R,
            _______, KC_I3_4, KC_I3_5, KC_I3_6, _______,           _______, _______, _______, _______, _______,
                                       _______, KC_NO,                          _______, _______
        ),
        //I3 commands
        [_I3WM_CMD] = LAYOUT(
            KC_I3_LOCK_SCREEN,   _______,        KC_I3_SPT_SHOW,             _______,           KC_I3_FORCECLOSE,   _______, _______,       _______,       _______,      KC_I3_RELOAD_CONFIG,
            KC_I3_SHUTDOWN_MENU, KC_I3_LAUNCHER, TD(I3WM_TERMINAL_LAUNCHER), KC_I3_FULL_SCREEN, _______,            _______, KC_I3_V_SPLIT, KC_I3_H_SPLIT, KC_I3_RESIZE, _______,
            _______,             _______,        _______,                    KC_I3_STACK,       _______,            _______, _______,       _______,       _______,      KC_I3_RESTART_WM,
                                                                             KC_NO,             _______,            _______, KC_NO
        ),

        //Layer 3
        [_SYM_RIGHT] = LAYOUT(
            _______, _______, _______, _______, _______,         _______, KC_UNDS, KC_PIPE, KC_QUOT, _______,
            KC_CIRC, KC_ASTR, KC_AMPR, KC_NO,   _______,         KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR,
            _______, _______, _______, _______, _______,         _______, KC_MINS, KC_BSLS, KC_GRV,  _______,
                         KC_I3_SPT_PREV, KC_I3_SPT_NEXT,         _______, KC_I3_SPT_PLAY
        ),
        //Layer 4
        [_SYM_LEFT] = LAYOUT(
            _______, KC_COLN, KC_LT,   KC_GT,   KC_SCLN,          _______, _______, _______, _______, _______,
            KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT,            _______, KC_NO,   KC_EQL,  KC_PLUS, KC_PERC,
            _______, KC_EXLM, KC_LBRC, KC_RBRC, _______,          _______, _______, _______, _______, _______,
                                       KC_I3_VOLD, _______,          _______, KC_I3_VOLU
        ),
        //Layer 5
        [_FUNCTION] = LAYOUT(
            _______, _______, _______,       _______, _______,      QK_DYNAMIC_TAPPING_TERM_PRINT, KC_F7, KC_F8, KC_F9, KC_F10,
            _______, KC_NO,   LCTL(KC_LALT), _______, _______,      QK_DYNAMIC_TAPPING_TERM_UP,    KC_F4, KC_F5, KC_F6, KC_F11,
            _______, _______, _______,       _______, _______,      QK_DYNAMIC_TAPPING_TERM_DOWN,  KC_F1, KC_F2, KC_F3, KC_F12,
                                             _______, _______,      _______, _______
    ),
        //Layer 6
        [_NUMPAD] = LAYOUT(
            KC_PSLS, KC_7, KC_8, KC_9,    KC_PPLS,         _______, _______, _______, _______, _______,
            KC_0,    KC_4, KC_5, KC_6,    KC_PMNS,         _______, _______, KC_LALT,  KC_NO,   _______,
            KC_PAST, KC_1, KC_2, KC_3,    KC_PEQL,         _______, _______, _______, _______, _______,
                                 _______, _______,         _______, _______
    ),
        //Layer 7
        [_ALWAYS_ACCESSIBLE] = LAYOUT(
            _______, _______, KC_COLN, KC_ESC,  _______,                  _______, _______, _______,         _______,        KC_DEL,
            _______, KC_PERC, KC_SLSH, KC_ENT,  _______,                  DF(1),   KC_LGUI, _______,         _______,        _______,
            _______, _______, KC_BSLS, KC_EXLM, _______,                  DF(0),   _______, RALT_T(KC_COMM), RCTL_T(KC_DOT), QK_BOOT,
                                       _______, KC_TAB,                   KC_NO, _______)
};




