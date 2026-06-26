#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t ssi_clock_hz;
    uint16_t last_raw;
    bool valid;
} encoder_kth7816_t;

void encoder_kth7816_init(encoder_kth7816_t *enc, uint32_t ssi_clock_hz);
bool encoder_kth7816_read(encoder_kth7816_t *enc, uint16_t *raw_counts);

#ifdef __cplusplus
}
#endif
