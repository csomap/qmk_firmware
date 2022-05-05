/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "layers.h"
#include "combos.h"
#include "custom_autoshift.h"
#include "user_keycodes.h"

const uint16_t PROGMEM cas_ins_lc[]      = { KC_INS, CAS_SEQ_END };
const uint16_t PROGMEM cas_ins_uc[]      = { KC_LSFT, KC_INS, CAS_SEQ_END };
const uint16_t PROGMEM cas_astr_lc[]     = { KC_LSFT, KC_8, CAS_SEQ_END };
const uint16_t PROGMEM cas_astr_uc[]     = { KC_LSFT, KC_1, CAS_SEQ_END };

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAVNUM, _SYMBOLS, _I3WM);
}

void matrix_scan_user(void) {
    scan_cas();
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    if (!process_user_keycodes(keycode, record)) {
        return false;
    }

    switch(keycode) {
    case KC_INS:
        if(record->event.pressed) {
            cas_start_sequence(cas_ins_lc, cas_ins_uc);
        }
        else {
            cas_end();
        }
        return false;
    case KC_ASTR:
        if(record->event.pressed) {
            cas_start_sequence(cas_astr_lc, cas_astr_uc);
        }
        else {
            cas_end();
        }
        return false;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 */
    [_QWERTY] = LAYOUT(
      KC_ASTR, KC_Q, KC_W, KC_E, KC_R, KC_T,                                                          KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSLASH,
      KC_LSPO, KC_A, KC_S, KC_D, KC_F, KC_G,                                                          KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_RSPC,
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, OSL(_I3WM), RSG(KC_D),                      KC_SLCK, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______,
              OSM(MOD_LGUI), KC_LALT, LT(_CLION, KC_DEL), LT(_NAVNUM, KC_SPC), LCTL_T(KC_TAB),  LALT_T(KC_ENT), LT(_SYMBOLS, KC_BSPC), LT(_FUNCTION, KC_ESC), KC_LCTL, _______
    ),
/*
 * Navigation layer
 */
    [_NAVNUM] = LAYOUT(
      _______, _______, KC_7, KC_8, KC_9, _______,                                     KC_HOME, KC_PGUP, _______, RCS(KC_TAB), C(KC_TAB), _______,
      _______, KC_0,    KC_4, KC_5, KC_6, S(KC_G),                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,     _______,   _______,
      _______, _______, KC_1, KC_2, KC_3, _______, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______,     _______,   _______,
                                 _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, _______
    ),
/*
 * Symbol layer
 */
    [_SYMBOLS] = LAYOUT(
      KC_TILD, _______, KC_CIRC, KC_AT,   KC_LABK, _______,                                       _______,   KC_RABK, KC_AMPR, KC_DLR, _______, _______,
      _______, KC_ASTR, KC_QUOT, KC_LCBR, KC_LPRN, KC_UNDS,                                       KC_MINS, KC_RPRN, KC_RCBR, KC_EQL, _______,  _______,
      _______, _______, _______, KC_HASH, KC_LBRC, _______, _______, _______,   _______, _______, _______,   KC_RBRC, KC_PERC, _______, _______, _______,
                                 _______, _______, _______, _______, S(KC_TAB), _______, _______, _______, _______, _______
    ),
/*
 * I3WM layer
 */
    [_I3WM] = LAYOUT(
      _______,    KC_I3WM_0, KC_I3WM_9, KC_I3WM_8, KC_I3WM_7, KC_I3WM_6,                                     G(KC_R), _______, _______,   _______, _______, RGUI(KC_PAUSE),
      G(KC_GRV),  KC_I3WM_4, KC_I3WM_3, KC_I3WM_2, KC_I3WM_1, G(KC_F),                                     KC_I3WM_L, KC_I3WM_D, KC_I3WM_U, KC_I3WM_R, KC_LSFT, _______,
      RSG(KC_R),  _______, _______, _______, KC_I3WM_5, _______, _______, _______, _______, _______, G(KC_N), G(KC_V), _______, _______, _______, RSG(KC_C),
                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * FN keys layer
 */
    [_FUNCTION] = LAYOUT(
      _______, KC_F11, KC_F7, KC_F8,  KC_F9, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_F10, KC_F4, KC_F5,  KC_F6, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_F12, KC_F1, KC_F2,  KC_F3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Clion hotkeys
 */
    [_CLION] = LAYOUT(
      _______, _______, _______, _______, LSFT(KC_F10), LSFT(KC_F9),                            _______, _______, _______, _______, _______, _______,
      _______, _______, LCA(KC_S), _______, _______, _______,                                     LCA(KC_LEFT), LCA(KC_DOWN), LCA(KC_UP), LCA(KC_RIGHT), _______, _______,
      _______, _______, _______, _______, _______, LCTL(KC_F9), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            register_code(KC_LGUI);
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
            unregister_code(KC_LGUI);
        } else {
            register_code(KC_LGUI);
            register_code(KC_PGDOWN);
            unregister_code(KC_PGDOWN);
            unregister_code(KC_LGUI);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_PGDOWN);
            unregister_code(KC_PGDOWN);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            //tap_code(KC_WH_D);
        } else {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
            //tap_code(KC_WH_U);
        }
    }
    return true;
}
#endif
