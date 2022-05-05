#include "combos.h"
#include "unicode.h"
#include "layers.h"
#include "custom_autoshift.h"

#define DEF_COMBO_LEN 3

enum combos {
    POINTER,
    VIMPASTE,
    LAUNCHER,
    TERMINAL_V,
    TERMINAL_H,
    VIMNEWLINE,
    FORCECLOSE,
    COMB_CWORD,
    COMB_FNOSL,
    COMB_AA,
    COMB_EE,
    COMB_II,
    COMB_OO,
    COMB_OE,
    COMB_OEE,
    COMB_UU,
    COMB_UE,
    COMB_UEE,
};

combo_t key_combos[COMBO_COUNT] = {
    [POINTER]    = COMBO_ACTION(pointer_combo),
    [VIMPASTE]   = COMBO_ACTION(vimpaste_combo),
    [LAUNCHER]   = COMBO_ACTION(launcher_combo),
    [TERMINAL_V] = COMBO_ACTION(terminalv_combo),
    [TERMINAL_H] = COMBO_ACTION(terminalh_combo),
    [VIMNEWLINE] = COMBO_ACTION(vimnl_combo),
    [FORCECLOSE] = COMBO_ACTION(fclose_combo),
    [COMB_CWORD] = COMBO_ACTION(cword_combo),
    [COMB_FNOSL] = COMBO_ACTION(fnosl_combo),
    [COMB_AA]    = COMBO_ACTION(aa_combo),
    [COMB_EE]    = COMBO_ACTION(ee_combo),
    [COMB_II]    = COMBO_ACTION(ii_combo),
    [COMB_OO]    = COMBO_ACTION(oo_combo),
    [COMB_OE]    = COMBO_ACTION(oe_combo),
    [COMB_OEE]   = COMBO_ACTION(oee_combo),
    [COMB_UU]    = COMBO_ACTION(uu_combo),
    [COMB_UE]    = COMBO_ACTION(ue_combo),
    [COMB_UEE]   = COMBO_ACTION(uee_combo),
};

const uint32_t combos_to_uc [] = {
    [COMB_AA]  = UC_AA,
    [COMB_EE]  = UC_EE,
    [COMB_II]  = UC_II,
    [COMB_OO]  = UC_OO,
    [COMB_OE]  = UC_OE,
    [COMB_OEE] = UC_OEE,
    [COMB_UU]  = UC_UU,
    [COMB_UE]  = UC_UE,
    [COMB_UEE] = UC_UEE,
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
    case POINTER:
        if(pressed) {
            SEND_STRING("->");
        }
        break;
    case VIMPASTE:
        if(pressed) {
            SEND_STRING(SS_RCTL("r")SS_DELAY(30)"0");
        }
        break;
    case LAUNCHER:
        if(pressed) {
            register_code(KC_LGUI);
            register_code(KC_D);
            unregister_code(KC_D);
            unregister_code(KC_LGUI);
        }
        break;
    case TERMINAL_V:
        if(pressed) {
            register_code(KC_LGUI);
            register_code(KC_V);
            unregister_code(KC_V);
            unregister_code(KC_LGUI);
            register_code(KC_LGUI);
            register_code(KC_ENT);
            unregister_code(KC_ENT);
            unregister_code(KC_LGUI);
        }
        break;
    case TERMINAL_H:
        if(pressed) {
            register_code(KC_LGUI);
            register_code(KC_N);
            unregister_code(KC_N);
            unregister_code(KC_LGUI);
            register_code(KC_LGUI);
            register_code(KC_ENT);
            unregister_code(KC_ENT);
            unregister_code(KC_LGUI);
        }
        break;
    case VIMNEWLINE:
        if(pressed) {
            tap_code(KC_ESC);
            register_code(KC_LSFT);
            tap_code(KC_O);
            unregister_code(KC_LSFT);
        }
        break;
    case FORCECLOSE:
        if(pressed) {
            register_code(KC_LGUI);
            register_code(KC_LSFT);
            tap_code(KC_Q);
            unregister_code(KC_LSFT);
            unregister_code(KC_LGUI);
        }
        break;
    case COMB_CWORD:
        if(pressed) {
            if(!caps_word_enabled()) {
                enable_caps_word();
            }
            else {
                disable_caps_word();
            }
        }
        break;
    case COMB_FNOSL:
        if(pressed) {
            set_oneshot_layer(_FUNCTION, ONESHOT_START);
        }
        else {
            clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
        break;
    // Combos for hungarian unicode characters
    case COMB_AA: case COMB_EE: case COMB_II: case COMB_OO: case COMB_OE:
    case COMB_OEE: case COMB_UU: case COMB_UE: case COMB_UEE:
        if(pressed) {
            cas_start_unicode(combos_to_uc[combo_index]);
        }
        else {
            cas_end();
        }
        break;
    }
}
