#pragma once

#include QMK_KEYBOARD_H

static const uint16_t PROGMEM pointer_combo[]   = {KC_G, KC_H, COMBO_END}; // Print C/C++ style pointer('->')
static const uint16_t PROGMEM vimpaste_combo[]  = {KC_H, KC_J, COMBO_END}; // Paste in Vim insertion mode
static const uint16_t PROGMEM launcher_combo[]  = {KC_D, KC_F, COMBO_END}; // Open I3WM application launcher
static const uint16_t PROGMEM terminalv_combo[] = {KC_D, KC_V, COMBO_END}; // Open terminal in I3WM in vertical split
static const uint16_t PROGMEM terminalh_combo[] = {KC_D, KC_G, COMBO_END}; // Open terminal in I3WM in horizontal split
static const uint16_t PROGMEM vimnl_combo[]     = {KC_J, KC_K, COMBO_END}; // Insert new line above in Vim insertion mode
static const uint16_t PROGMEM fclose_combo[]    = {KC_Q, KC_P, COMBO_END}; // Force close window in I3WM
static const uint16_t PROGMEM fnosl_combo[]     = {KC_V, KC_B, COMBO_END}; // OSL toggle Fn keys layer
static const uint16_t PROGMEM cword_combo[]     = {KC_F, KC_J, COMBO_END}; // Toggle auto-caps

// Combos for printing special hungarian characters
static const uint16_t PROGMEM aa_combo[]        = {KC_A, KC_COMMA, COMBO_END};
static const uint16_t PROGMEM ee_combo[]        = {KC_E, KC_COMMA, COMBO_END};
static const uint16_t PROGMEM ii_combo[]        = {KC_I, KC_F, COMBO_END};
static const uint16_t PROGMEM oo_combo[]        = {KC_O, KC_F, COMBO_END};
static const uint16_t PROGMEM oe_combo[]        = {KC_O, KC_D, COMBO_END};
static const uint16_t PROGMEM oee_combo[]       = {KC_O, KC_S, COMBO_END};
static const uint16_t PROGMEM uu_combo[]        = {KC_U, KC_F, COMBO_END};
static const uint16_t PROGMEM ue_combo[]        = {KC_U, KC_D, COMBO_END};
static const uint16_t PROGMEM uee_combo[]       = {KC_U, KC_S, COMBO_END};
