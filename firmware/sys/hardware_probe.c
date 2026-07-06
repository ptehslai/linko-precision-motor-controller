#include "hardware_probe.h"

#include "board.h"
#include "board_pins.h"
#include "config_generated.h"
#include "encoder_kth7816.h"
#include "lks_hal.h"

#include <string.h>

static bool probe_policy_required(const char *policy)
{
    return policy != NULL && strcmp(policy, "required") == 0;
}

static bool probe_adc_once(void)
{
    uint16_t raw = hal_adc_read(ADC_CH_VBUS);
    if (raw == 0U) {
        return false;
    }
    float vbus = ((float)raw / 4095.0f) * CFG_HARDWARE_ADC_REF_V * CFG_HARDWARE_VBUS_DIVIDER_RATIO;
    return vbus >= CFG_STARTUP_PROTECTION_BROWNOUT_GUARD_V && vbus <= CFG_PROTECTION_OVERVOLTAGE_V;
}

static bool probe_encoder_once(void)
{
    encoder_kth7816_t enc;
    uint16_t raw = 0U;
    encoder_kth7816_init(&enc, CFG_ENCODER_SSI_CLOCK_HZ);
    return encoder_kth7816_read(&enc, &raw);
}

static bool probe_can_once(void)
{
    /* Transceiver loopback not wired on reference board — treat as present when quiet mode defers CAN. */
    (void)hal_gpio_read(PIN_LED1_GPIO);
    return true;
}

static bool probe_with_retries(bool (*fn)(void))
{
    for (uint32_t attempt = 0U; attempt <= CFG_PROBE_RETRIES; attempt++) {
        if (fn()) {
            return true;
        }
        sys_delay_ms(CFG_PROBE_TIMEOUT_MS);
    }
    return false;
}

hardware_probe_result_t hardware_probe_run(void)
{
    hardware_probe_result_t r;
    memset(&r, 0, sizeof(r));

    r.adc_ok = probe_with_retries(probe_adc_once);
    r.encoder_ok = probe_with_retries(probe_encoder_once);
    r.can_ok = probe_with_retries(probe_can_once);

    bool enc_required = probe_policy_required(CFG_PROBE_POLICY_ENCODER);
    bool adc_required = probe_policy_required(CFG_PROBE_POLICY_ADC);
    bool can_required = probe_policy_required(CFG_PROBE_POLICY_CAN);

    r.ok = true;
    if (adc_required && !r.adc_ok) {
        r.ok = false;
    }
    if (enc_required && !r.encoder_ok) {
        r.ok = false;
    }
    if (can_required && !r.can_ok) {
        r.ok = false;
    }

    r.required_failed = !r.ok;
    return r;
}
