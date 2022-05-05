#include "custom_autoshift.h"

static bool     cas_in_progress = false;
static uint16_t cas_timer       = 0;

static union {
    struct {
        uint16_t lc_seq[MAX_CAS_SEQ_LEN];
        uint16_t uc_seq[MAX_CAS_SEQ_LEN];
    };
    uc_names_t uc_name;
} cas_data;

static void (*send_function)(char) = 0;

void copy_cas_seq(uint16_t* dst, const uint16_t* src) {
    int8_t last = 0;
    while(src[last] != CAS_SEQ_END && last < MAX_CAS_SEQ_LEN - 1) {
        dst[last] = src[last];
        ++last;
    }
    dst[last] = CAS_SEQ_END;
}

void send_sequence(char is_uppercase) {
    uint16_t* seq = is_uppercase ? cas_data.uc_seq : cas_data.lc_seq;

    int8_t last = 0;
    while(seq[last] != CAS_SEQ_END) {
        register_code(seq[last++]);
    }

    while(--last >= 0) {
        unregister_code(seq[last]);
    }
}

void send_unicode(char is_uppercase) {
    register_unicode(uc_getcode(cas_data.uc_name, is_uppercase));
}

void cas_start_sequence(const uint16_t* keycodes_lc, const uint16_t* keycodes_uc) {
    copy_cas_seq(cas_data.lc_seq, keycodes_lc);
    copy_cas_seq(cas_data.uc_seq, keycodes_uc);
    send_function = send_sequence;
    cas_timer = timer_read();
    cas_in_progress = true;
}

void cas_start_unicode(uc_names_t uc_name) {
    cas_data.uc_name = uc_name;
    send_function = send_unicode;
    cas_timer = timer_read();
    cas_in_progress = true;
}

void cas_end(void) {
    if(!cas_in_progress) {
        return;
    }

    send_function(caps_word_enabled() || timer_elapsed(cas_timer) > AUTO_SHIFT_TIMEOUT);
    cas_in_progress = false;
}

void scan_cas(void) {
    if(cas_in_progress && timer_elapsed(cas_timer) > AUTO_SHIFT_TIMEOUT) {
        cas_end();
    }
}
