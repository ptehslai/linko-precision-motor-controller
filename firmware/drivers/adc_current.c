#include "adc_current.h"
#include <stddef.h>

void adc_current_init(adc_current_t *adc, float shunt_ohm, float amp_gain)
{
    if (adc == NULL || shunt_ohm <= 0.0f) {
        return;
    }
    adc->cal.gain_v_per_a = shunt_ohm * amp_gain;
    adc->cal.offset_a = 0.0f;
    adc->ia = 0.0f;
    adc->ib = 0.0f;
    adc->ic = 0.0f;
}

static float counts_to_amps(uint16_t raw, const adc_current_cal_t *cal)
{
    float v = ((float)raw - 2048.0f) / 2048.0f * 3.3f;
    if (cal->gain_v_per_a <= 0.0f) {
        return 0.0f;
    }
    return (v / cal->gain_v_per_a) - cal->offset_a;
}

void adc_current_sample(adc_current_t *adc, uint16_t raw_a, uint16_t raw_b, uint16_t raw_c)
{
    if (adc == NULL) {
        return;
    }
    adc->ia = counts_to_amps(raw_a, &adc->cal);
    adc->ib = counts_to_amps(raw_b, &adc->cal);
    adc->ic = counts_to_amps(raw_c, &adc->cal);
}
