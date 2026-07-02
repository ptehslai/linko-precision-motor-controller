#include "encoder_kth7816.h"
#include "board_pins.h"
#include "lks_hal.h"
#include "board.h"

static void ssi_delay_half_bit(uint32_t ssi_clock_hz)
{
    uint32_t us = (ssi_clock_hz > 0U) ? (500000U / ssi_clock_hz) : 1U;
    if (us == 0U) {
        us = 1U;
    }
    uint32_t end = sys_get_us() + us;
    while (sys_get_us() < end) {
    }
}

void encoder_kth7816_init(encoder_kth7816_t *enc, uint32_t ssi_clock_hz)
{
    if (enc == NULL) {
        return;
    }
    enc->ssi_clock_hz = ssi_clock_hz;
    enc->last_raw = 0U;
    enc->valid = false;
}

bool encoder_kth7816_read(encoder_kth7816_t *enc, uint16_t *raw_counts)
{
    if (enc == NULL || raw_counts == NULL) {
        return false;
    }

    uint16_t value = 0U;
    hal_gpio_write(PIN_SSI_CLK_GPIO, false);
    ssi_delay_half_bit(enc->ssi_clock_hz);

    for (uint8_t i = 0; i < 16U; i++) {
        hal_gpio_write(PIN_SSI_CLK_GPIO, true);
        ssi_delay_half_bit(enc->ssi_clock_hz);
        value <<= 1;
        if (hal_gpio_read(PIN_SSI_DI_GPIO)) {
            value |= 1U;
        }
        hal_gpio_write(PIN_SSI_CLK_GPIO, false);
        ssi_delay_half_bit(enc->ssi_clock_hz);
    }

    enc->last_raw = value;
    enc->valid = true;
    *raw_counts = value;
    return true;
}
