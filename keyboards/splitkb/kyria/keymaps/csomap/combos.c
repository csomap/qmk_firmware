#include "casemodes.h"
#include "custom_keycodes.h"
#include "i3wm.h"
#include "unicode.h"

extern const uint16_t i3wm_commands[];

extern const uint16_t PROGMEM pointer_combo[];
extern const uint16_t PROGMEM vimpaste_combo[];
extern const uint16_t PROGMEM launcher_combo[];
extern const uint16_t PROGMEM terminalv_combo[];
extern const uint16_t PROGMEM terminalh_combo[];
extern const uint16_t PROGMEM vimnl_combo[];
extern const uint16_t PROGMEM fclose_combo[];
extern const uint16_t PROGMEM cword_combo[];
extern const uint16_t PROGMEM aa_combo[];
extern const uint16_t PROGMEM ee_combo[];
extern const uint16_t PROGMEM ii_combo[];
extern const uint16_t PROGMEM oo_combo[];
extern const uint16_t PROGMEM oe_combo[];
extern const uint16_t PROGMEM oee_combo[];
extern const uint16_t PROGMEM uu_combo[];
extern const uint16_t PROGMEM ue_combo[];
extern const uint16_t PROGMEM uee_combo[];

static uint16_t as_combo_timer = 0;
static uc_names_t uc_name;

enum combos {
    COMB_CWORD,
    POINTER,
    VIMPASTE,
    VIMNEWLINE,
    LAUNCHER,
    TERMINAL_V,
    TERMINAL_H,
    FORCECLOSE,
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

const combo_t key_combos[COMBO_COUNT] = {
    [COMB_CWORD] = COMBO_ACTION(cword_combo),
    [POINTER]    = COMBO_ACTION(pointer_combo),
    [VIMPASTE]   = COMBO_ACTION(vimpaste_combo),
    [VIMNEWLINE] = COMBO_ACTION(vimnl_combo),
    [LAUNCHER]   = COMBO_ACTION(launcher_combo),
    [TERMINAL_V] = COMBO_ACTION(terminalv_combo),
    [TERMINAL_H] = COMBO_ACTION(terminalh_combo),
    [FORCECLOSE] = COMBO_ACTION(fclose_combo),
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

static const uc_names_t combos_to_uc [] = {
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
    case VIMNEWLINE:
        if(pressed) {
            tap_code(KC_ESC);
            register_code(KC_LSFT);
            tap_code(KC_O);
            unregister_code(KC_LSFT);
        }
        break;
    case LAUNCHER:
        process_i3wm_event(I3WM_LAUNCHER, pressed);
        break;
    case TERMINAL_V:
        if(pressed) {
            process_i3wm_event(I3WM_V_SPLIT, true);
            process_i3wm_event(I3WM_V_SPLIT, false);
        }
        process_i3wm_event(I3WM_TERMINAL, pressed);
        break;
    case TERMINAL_H:
        if(pressed) {
            process_i3wm_event(I3WM_H_SPLIT, true);
            process_i3wm_event(I3WM_H_SPLIT, false);
        }
        process_i3wm_event(I3WM_TERMINAL, pressed);
        break;
    case FORCECLOSE:
        process_i3wm_event(I3WM_FORCECLOSE, pressed);
        break;
    // Combos for hungarian unicode characters
    case COMB_AA: case COMB_EE: case COMB_II: case COMB_OO: case COMB_OE:
    case COMB_OEE: case COMB_UU: case COMB_UE: case COMB_UEE:
        if(pressed) {
            uc_name = combos_to_uc[combo_index];
            as_combo_timer = timer_read();
        }
        else {
            register_unicode(uc_getcode(uc_name, caps_word_enabled() || timer_elapsed(as_combo_timer) > COMBO_AUTOSHIFT_TIMEOUT));
            as_combo_timer = 0;
        }
        break;
    }
}

void as_combo_scan(void) {
    if(as_combo_timer > 0 && timer_elapsed(as_combo_timer) > COMBO_AUTOSHIFT_TIMEOUT) {
        register_unicode(uc_getcode(uc_name, true));
        as_combo_timer = 0;
    }
}
