#include "tapdances.h"
#include "layers.h"
#include "i3wm.h"

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD
} td_state_t;

static td_state_t td_state = TD_NONE;

td_state_t cur_dance(tap_dance_state_t* state) {
    if(state->count == 1) {
        return state->pressed ? TD_SINGLE_HOLD : TD_SINGLE_TAP;
    }
    else if (state->count == 2) {
        return state->pressed ? TD_DOUBLE_HOLD : TD_DOUBLE_TAP;
    }
    return TD_UNKNOWN;
}

void term_finished(tap_dance_state_t* state, void* user_data) {
    td_state = cur_dance(state);

    switch(td_state) {
        case TD_SINGLE_TAP:
            register_i3wm_code(KC_I3_V_SPLIT);
            register_i3wm_code(KC_I3_TERMINAL);
            break;
        case TD_DOUBLE_TAP:
            register_i3wm_code(KC_I3_H_SPLIT);
            register_i3wm_code(KC_I3_TERMINAL);
            break;
        default:
            break;
    }
}

void term_reset(tap_dance_state_t* state, void* user_data) {
    td_state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [I3WM_TERMINAL_LAUNCHER]        = ACTION_TAP_DANCE_FN_ADVANCED(NULL, term_finished, term_reset)
};
