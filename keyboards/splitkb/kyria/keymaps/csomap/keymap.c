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

#include "custom_keycodes.h"
#include "casemodes.h"

enum layers {
    _QWERTY = 0,
    _NAVNUM,
    _SYMBOLS,
    _I3WM,
    _FUNCTION,
    _CLION,
};

const uint16_t PROGMEM pointer_combo[]   = {KC_G, KC_H, COMBO_END}; // Print C/C++ style pointer('->')
const uint16_t PROGMEM vimpaste_combo[]  = {KC_H, KC_J, COMBO_END}; // Paste in Vim insertion mode
const uint16_t PROGMEM launcher_combo[]  = {KC_D, KC_F, COMBO_END}; // Open I3WM application launcher
const uint16_t PROGMEM terminalv_combo[] = {KC_D, KC_V, COMBO_END}; // Open terminal in I3WM in vertical split
const uint16_t PROGMEM terminalh_combo[] = {KC_D, KC_G, COMBO_END}; // Open terminal in I3WM in horizontal split
const uint16_t PROGMEM vimnl_combo[]     = {KC_J, KC_K, COMBO_END}; // Insert new line above in Vim insertion mode
const uint16_t PROGMEM fclose_combo[]    = {KC_Q, KC_P, COMBO_END}; // Force close window in I3WM
const uint16_t PROGMEM cword_combo[]     = {KC_F, KC_J, COMBO_END}; // Toggle auto-caps

// Combos for printing special hungarian characters
const uint16_t PROGMEM aa_combo[]        = {KC_A, KC_COMMA, COMBO_END};
const uint16_t PROGMEM ee_combo[]        = {KC_E, KC_COMMA, COMBO_END};
const uint16_t PROGMEM ii_combo[]        = {KC_I, KC_F, COMBO_END};
const uint16_t PROGMEM oo_combo[]        = {KC_O, KC_F, COMBO_END};
const uint16_t PROGMEM oe_combo[]        = {KC_O, KC_D, COMBO_END};
const uint16_t PROGMEM oee_combo[]       = {KC_O, KC_S, COMBO_END};
const uint16_t PROGMEM uu_combo[]        = {KC_U, KC_F, COMBO_END};
const uint16_t PROGMEM ue_combo[]        = {KC_U, KC_D, COMBO_END};
const uint16_t PROGMEM uee_combo[]       = {KC_U, KC_S, COMBO_END};

void as_combo_scan(void);

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAVNUM, _SYMBOLS, _I3WM);
}

void matrix_scan_user(void) {
    as_combo_scan();
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    if(can_autoshift_custom_kc(keycode)) {
        return true;
    }

    switch(keycode) {
        case KC_ASTR:
        case KC_INS:
            return true;
    }

    return false;
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t* record) {
    if(!process_custom_autoshift(keycode, shifted, true, record)) {
        return;
    }

    switch (keycode) {
        case KC_ASTR:
            register_code16(shifted ? KC_EXLM : KC_ASTR);
            break;
        default:
            if(shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t* record) {
    if(!process_custom_autoshift(keycode, shifted, false, record)) {
        return;
    }

    switch (keycode) {
        case KC_ASTR:
            unregister_code16(shifted ? KC_EXLM : KC_ASTR);
            break;
        default:
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    if (!process_custom_keycodes(keycode, record)) {
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
      _______, KC_Z, KC_X, KC_C, KC_V, KC_B, OSL(_I3WM), KC_I3WM_LOCK_SCREEN,                      KC_SLCK, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, _______,
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
      _______, KC_TILD, KC_CIRC, KC_AT,   KC_LABK, _______,                                       _______,   KC_RABK, KC_AMPR, KC_DLR, _______, _______,
      _______, KC_ASTR, KC_QUOT, KC_LCBR, KC_LPRN, KC_UNDS,                                       KC_MINS, KC_RPRN, KC_RCBR, KC_EQL, _______,  _______,
      _______, _______, _______, KC_HASH, KC_LBRC, _______, _______, _______,   _______, _______, _______,   KC_RBRC, KC_PERC, _______, _______, _______,
                                 _______, _______, _______, _______, S(KC_TAB), _______, _______, _______, _______, _______
    ),
/*
 * I3WM layer
 */
    [_I3WM] = LAYOUT(
      _______,    KC_I3WM_0, KC_I3WM_9, KC_I3WM_8, KC_I3WM_7, KC_I3WM_6,                                      KC_I3WM_RESIZE, _______, _______,   _______, _______, KC_I3WM_SHUTDOWN_MENU,
      KC_I3WM_STACK,  KC_I3WM_4, KC_I3WM_3, KC_I3WM_2, KC_I3WM_1, KC_I3WM_FULL_SCREEN,                        KC_I3WM_L, KC_I3WM_D, KC_I3WM_U, KC_I3WM_R, _______, _______,
      KC_I3WM_RESTART_WM,  _______, _______, _______, KC_I3WM_5, _______, _______, _______, _______, _______, KC_I3WM_H_SPLIT, KC_I3WM_V_SPLIT, _______, _______, _______, KC_I3WM_RELOAD_CONFIG,
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
