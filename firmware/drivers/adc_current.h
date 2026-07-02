#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    float gain_v_per_a;
    float offset_a;
} adc_current_cal_t;

typedef struct {
    adc_current_cal_t cal;
    float ia;
    float ib;
    float ic;
} adc_current_t;

void adc_current_init(adc_current_t *adc, float shunt_ohm, float amp_gain);
void adc_current_sample(adc_current_t *adc, uint16_t raw_a, uint16_t raw_b, uint16_t raw_c);

#ifdef __cplusplus
}
#endif
