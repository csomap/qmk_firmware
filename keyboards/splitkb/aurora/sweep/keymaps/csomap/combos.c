#include "hun_unicode.h"

extern const uint16_t PROGMEM aa_combo[];
extern const uint16_t PROGMEM ee_combo[];
extern const uint16_t PROGMEM ii_combo[];
extern const uint16_t PROGMEM oo_combo[];
extern const uint16_t PROGMEM oe_combo[];
extern const uint16_t PROGMEM oee_combo[];
extern const uint16_t PROGMEM uu_combo[];
extern const uint16_t PROGMEM ue_combo[];
extern const uint16_t PROGMEM uee_combo[];

enum combos {
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
    // Combos for hungarian unicode characters
    case COMB_AA: case COMB_EE: case COMB_II: case COMB_OO: case COMB_OE:
    case COMB_OEE: case COMB_UU: case COMB_UE: case COMB_UEE:
        if(pressed) {
			register_unicode(uc_getcode(combos_to_uc[combo_index], (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT));
        }
        break;
	default:
		break;
    }
}
