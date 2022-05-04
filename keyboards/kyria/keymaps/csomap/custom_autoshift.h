#pragma once

#include "unicode.h"
#include "casemodes.h"

#define MAX_CAS_SEQ_LEN 16
#define CAS_SEQ_END     0x00

// Registers two arrays of keycodes and starts a timer. If cas_end is called before the timer runs out,
// the keycodes_lc are executed, otherwise keycodes_uc is executed.
// The arrays are executed by first registering the keycodes in order until the end (indicated by CAS_SEQ_END)
// is reached, then the keycodes are unregistered in reverse order.
void cas_start_sequence(const uint16_t* keycodes_lc, const uint16_t* keycodes_uc);

// Registers a unicode character and starts a timer. If cas_end is called before the timer runs out,
// the unicode character represented by uc_name is printed. Otherwise its uppercase version is printed.
void cas_start_unicode(uc_names_t uc_name);

void cas_end(void);
void scan_cas(void);

