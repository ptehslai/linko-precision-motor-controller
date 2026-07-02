#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t crc32_mpeg2(const uint8_t *data, uint32_t len, uint32_t seed);

#ifdef __cplusplus
}
#endif
