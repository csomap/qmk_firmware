#include "unicode.h"

#include <stdio.h>

const uint32_t unicode_map[] = {}; //Needed for compiling with unicode, but we don't use it

const uint32_t custom_unicode_map[][2] = {
    [UC_AA]      = { 0x00E1, 0x00C1 },
    [UC_EE]      = { 0x00E9, 0x00C9 },
    [UC_II]      = { 0x00ED, 0x00CD },
    [UC_OO]      = { 0x00F3, 0x00D3 },
    [UC_OE]      = { 0x00F6, 0x00D6 },
    [UC_OEE]     = { 0x0151, 0x0150 },
    [UC_UU]      = { 0x00FA, 0x00DA },
    [UC_UE]      = { 0x00FC, 0x00DC },
    [UC_UEE]     = { 0x0171, 0x0170 },
};

uint32_t uc_getcode(uc_names_t name, bool uppercase) {
    return custom_unicode_map[name][uppercase ? 1 : 0] ;
}
