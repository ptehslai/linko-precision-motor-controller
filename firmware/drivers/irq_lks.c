#include "board_irq.h"
#include "board_pins.h"
#include "lks_pinmap.h"

#ifdef LKS_SDK_LINK

#include <stdbool.h>

#include "lks32mc45x_lib.h"

#define ADC_RAW_SLOTS 5U

static volatile uint16_t s_adc_raw[ADC_RAW_SLOTS];

static uint16_t adc_dat_to_u14(s16 dat)
{
    uint16_t v = (uint16_t)(dat >> 2);
    if (v & (1U << 13)) {
        v = 0U;
    }
    return v;
}

void board_irq_init(void)
{
    NVIC_SetPriority(ADC1_IRQn, 1);
    NVIC_EnableIRQ(ADC1_IRQn);

    NVIC_SetPriority(CAN_IRQn, 2);
    NVIC_EnableIRQ(CAN_IRQn);
}

uint16_t board_adc_get_raw(uint32_t logical_channel)
{
    if (logical_channel >= ADC_RAW_SLOTS) {
        return 0U;
    }
    return s_adc_raw[logical_channel];
}

void ADC1_IRQHandler(void)
{
    if (ADC1_IF & ADC_IF_SF1) {
        ADC1_IF = ADC_IF_SF1;
        s_adc_raw[ADC_CH_IA]   = adc_dat_to_u14(ADC1_DAT0);
        s_adc_raw[ADC_CH_IB]   = adc_dat_to_u14(ADC1_DAT1);
        s_adc_raw[ADC_CH_IC]   = adc_dat_to_u14(ADC1_DAT2);
        s_adc_raw[ADC_CH_VBUS] = adc_dat_to_u14(ADC1_DAT3);
    }
}

/* Simple single-frame CAN RX staging for hal_can_recv(). */
static volatile bool s_can_rx_pending;
static volatile uint32_t s_can_rx_id;
static volatile uint8_t s_can_rx_len;
static uint8_t s_can_rx_buf[8];

void CAN_IRQHandler(void)
{
    if (CAN_RTIF & CAN_RTIF_RIF) {
        CAN_RTIF = CAN_RTIF_RIF;
        u32 id = 0U;
        u8 ide = 0U;
        u8 rtr = 0U;
        u8 fdf = 0U;
        u8 len = 0U;
        if (CAN_Recv_Msg((u32 *)&id, &ide, &rtr, &fdf, s_can_rx_buf, &len) == CanRecv_Ok) {
            s_can_rx_id      = id;
            s_can_rx_len     = len;
            s_can_rx_pending = true;
            (void)ide;
            (void)rtr;
            (void)fdf;
        }
    }
}

bool board_can_take_rx(uint32_t *id, uint8_t *data, uint8_t *len)
{
    if (!s_can_rx_pending || id == NULL || data == NULL || len == NULL) {
        return false;
    }
    uint8_t n = s_can_rx_len;
    if (n > 8U) {
        n = 8U;
    }
    *id  = s_can_rx_id;
    *len = n;
    for (uint8_t i = 0; i < n; i++) {
        data[i] = s_can_rx_buf[i];
    }
    s_can_rx_pending = false;
    return true;
}

#endif
