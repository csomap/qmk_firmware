#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    UC_AA,
    UC_EE,
    UC_II,
    UC_OO,
    UC_OE,
    UC_OEE,
    UC_UU,
    UC_UE,
    UC_UEE,
} uc_names_t;

uint32_t uc_getcode(uc_names_t name, bool uppercase);
