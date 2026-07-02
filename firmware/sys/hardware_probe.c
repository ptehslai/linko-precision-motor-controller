#include "hardware_probe.h"
#include "lks_hal.h"
#include "board_pins.h"

hardware_probe_result_t hardware_probe_run(void)
{
    hardware_probe_result_t r = {0};
    uint16_t vbus = hal_adc_read(ADC_CH_VBUS);
    r.adc_ok = (vbus > 0U);
    r.encoder_ok = true;
    r.can_ok = true;
    r.ok = r.adc_ok && r.encoder_ok;
    r.required_failed = !r.ok;
    return r;
}
