#include "lks_hal.h"
#include "board_pins.h"

#ifdef LKS_SDK_LINK

#include "board_irq.h"
#include "lks_pinmap.h"
#include "lks32mc45x_lib.h"

#include <string.h>

extern uint32_t SystemCoreClock;

static uint32_t s_mcpwm_period;
static bool s_gpio_inited;

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} gpio_map_t;

static bool gpio_lookup(uint32_t logical, gpio_map_t *out)
{
    if (out == NULL) {
        return false;
    }
    switch (logical) {
    case PIN_SSI_CLK_GPIO:
        out->port = LKS_SSI_CLK_PORT;
        out->pin  = LKS_SSI_CLK_PIN;
        return true;
    case PIN_SSI_DI_GPIO:
        out->port = LKS_SSI_DI_PORT;
        out->pin  = LKS_SSI_DI_PIN;
        return true;
    case PIN_LED1_GPIO:
        out->port = LKS_LED1_PORT;
        out->pin  = LKS_LED1_PIN;
        return true;
    case PIN_LED2_GPIO:
        out->port = LKS_LED2_PORT;
        out->pin  = LKS_LED2_PIN;
        return true;
    case PIN_BTN1_GPIO:
        out->port = LKS_BTN1_PORT;
        out->pin  = LKS_BTN1_PIN;
        return true;
    case PIN_BTN2_GPIO:
        out->port = LKS_BTN2_PORT;
        out->pin  = LKS_BTN2_PIN;
        return true;
    default:
        return false;
    }
}

static void gpio_init_all(void)
{
    GPIO_InitTypeDef gpio;

    for (uint8_t ps = LKS_MCPWM_PIN_FIRST; ps <= GPIO_PinSource_9; ps++) {
        GPIO_Config(LKS_MCPWM_GPIO_PORT, ps, GPIO_Mode_OUT, GPIO_AF_MCPWM);
    }

    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin  = LKS_SSI_CLK_PIN;
    gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(LKS_SSI_CLK_PORT, &gpio);

    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_IN;
    gpio.GPIO_Pin  = LKS_SSI_DI_PIN;
    gpio.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(LKS_SSI_DI_PORT, &gpio);

    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_IN;
    gpio.GPIO_Pin  = LKS_CAN_RX_PIN;
    gpio.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(LKS_CAN_RX_PORT, &gpio);

    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin  = LKS_CAN_TX_PIN;
    gpio.GPIO_PuPd = GPIO_PuPd_DOWN;
    GPIO_Init(LKS_CAN_TX_PORT, &gpio);
    GPIO_PinAFConfig(LKS_CAN_TX_PORT, LKS_CAN_TX_AF, GPIO_AF_CAN);
    GPIO_PinAFConfig(LKS_CAN_RX_PORT, LKS_CAN_RX_AF, GPIO_AF_CAN);

    GPIO_Config(LKS_UART_TX_PORT, LKS_UART_TX_AF, GPIO_Mode_OUT, GPIO_AF_UART);
    GPIO_Config(LKS_UART_RX_PORT, LKS_UART_RX_AF, GPIO_Mode_IN, GPIO_AF_UART);

    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    gpio.GPIO_Pin  = LKS_LED1_PIN | LKS_LED2_PIN;
    gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(LKS_LED1_PORT, &gpio);
    GPIO_ResetBits(LKS_LED1_PORT, LKS_LED1_PIN | LKS_LED2_PIN);

    GPIO_StructInit(&gpio);
    gpio.GPIO_Mode = GPIO_Mode_IN;
    gpio.GPIO_Pin  = LKS_BTN1_PIN | LKS_BTN2_PIN;
    gpio.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(LKS_BTN1_PORT, &gpio);
}

static void ensure_gpio_init(void)
{
    if (s_gpio_inited) {
        return;
    }
    SYS_WR_PROTECT = 0x7A83U;
    gpio_init_all();
    SYS_WR_PROTECT = 0U;
    s_gpio_inited = true;
}

static void mcpwm_hw_init(uint32_t pwm_hz)
{
    if (pwm_hz == 0U) {
        pwm_hz = 20000U;
    }

    uint32_t mclk = SystemCoreClock;
    if (mclk == 0U) {
        mclk = SYS_ReadMcuClk();
    }
    s_mcpwm_period = mclk / (2U * pwm_hz);
    if (s_mcpwm_period < 100U) {
        s_mcpwm_period = 100U;
    }

    MCPWM_InitTypeDef mcpwm;
    MCPWM_StructInit(&mcpwm);

    mcpwm.TimeBase0_PERIOD      = (u16)s_mcpwm_period;
    mcpwm.CLK_DIV               = 0;
    mcpwm.MCLK_EN               = ENABLE;
    mcpwm.MCPWM_Cnt0_EN         = ENABLE;
    mcpwm.MCPWM_WorkModeCH0     = MCPWM_CENTRAL_PWM_MODE;
    mcpwm.MCPWM_WorkModeCH1     = MCPWM_CENTRAL_PWM_MODE;
    mcpwm.MCPWM_WorkModeCH2     = MCPWM_CENTRAL_PWM_MODE;
    mcpwm.TriggerPoint0         = (u16)(s_mcpwm_period / 2U);
    mcpwm.DeadTimeCH0N          = 100;
    mcpwm.DeadTimeCH0P          = 100;
    mcpwm.DeadTimeCH1N          = 100;
    mcpwm.DeadTimeCH1P          = 100;
    mcpwm.DeadTimeCH2N          = 100;
    mcpwm.DeadTimeCH2P          = 100;
    mcpwm.MCPWM_Base0T0_UpdateEN = ENABLE;
    mcpwm.AUEN                  = MCPWM_AUEN_TH00 | MCPWM_AUEN_TH01 | MCPWM_AUEN_TH10 |
                                  MCPWM_AUEN_TH11 | MCPWM_AUEN_TH20 | MCPWM_AUEN_TH21;

    MCPWM_Init(LKS_MCPWM, &mcpwm);

    LKS_MCPWM->TH00 = 0;
    LKS_MCPWM->TH01 = 0;
    LKS_MCPWM->TH10 = 0;
    LKS_MCPWM->TH11 = 0;
    LKS_MCPWM->TH20 = 0;
    LKS_MCPWM->TH21 = 0;
}

static void adc_hw_init(void)
{
    ADC_InitTypeDef adc;
    ADC_StructInit(&adc);

    adc.IE    = ADC_IE_SF1;
    adc.Align = ADC_ALIGN_LEFT;
    adc.GAIN  = ADC_GAIN_HIGH_DAT0;
    adc.S1    = ADC_S1_4;
    adc.S2    = ADC_S2_1;
    adc.NSMP  = ADC_NSMP_1;
    adc.TRIG  = ADC_TRIG_MCPWM1_T0_EN;
    ADC_Init(LKS_ADC_UNIT, &adc);

    ADC_SetPChanne(LKS_ADC_UNIT, ADC_DAT_0, LKS_ADC_CH_IA);
    ADC_SetPChanne(LKS_ADC_UNIT, ADC_DAT_1, LKS_ADC_CH_IB);
    ADC_SetPChanne(LKS_ADC_UNIT, ADC_DAT_2, LKS_ADC_CH_IC);
    ADC_SetPChanne(LKS_ADC_UNIT, ADC_DAT_3, LKS_ADC_CH_VBUS);

    LKS_ADC_UNIT->IF = 0xFFU;
    board_irq_init();
}

#endif /* LKS_SDK_LINK */

void hal_systick_config(uint32_t tick_hz)
{
#ifdef LKS_SDK_LINK
    if (tick_hz > 0U) {
        SysTick_Config(SystemCoreClock / tick_hz);
    }
#else
    (void)tick_hz;
#endif
}

void hal_gpio_write(uint32_t pin, bool level)
{
#ifdef LKS_SDK_LINK
    gpio_map_t map;
    if (!gpio_lookup(pin, &map)) {
        return;
    }
    if (level) {
        GPIO_SetBits(map.port, map.pin);
    } else {
        GPIO_ResetBits(map.port, map.pin);
    }
#else
    (void)pin;
    (void)level;
#endif
}

bool hal_gpio_read(uint32_t pin)
{
#ifdef LKS_SDK_LINK
    gpio_map_t map;
    if (!gpio_lookup(pin, &map)) {
        return false;
    }
    return GPIO_ReadInputDataBit(map.port, map.pin) != 0U;
#else
    (void)pin;
    return false;
#endif
}

void hal_mcpwm_init(uint32_t pwm_hz)
{
#ifdef LKS_SDK_LINK
    ensure_gpio_init();
    SYS_WR_PROTECT = 0x7A83U;
    mcpwm_hw_init(pwm_hz);
    adc_hw_init();
    SYS_WR_PROTECT = 0U;
#else
    (void)pwm_hz;
#endif
}

void hal_mcpwm_set_duty(uint32_t phase, float duty01)
{
#ifdef LKS_SDK_LINK
    if (duty01 < 0.0f) {
        duty01 = 0.0f;
    }
    if (duty01 > 1.0f) {
        duty01 = 1.0f;
    }
    uint32_t th = (uint32_t)(duty01 * (float)s_mcpwm_period);
    switch (phase) {
    case 0U:
        LKS_MCPWM->TH00 = (u16)th;
        break;
    case 1U:
        LKS_MCPWM->TH10 = (u16)th;
        break;
    case 2U:
        LKS_MCPWM->TH20 = (u16)th;
        break;
    default:
        break;
    }
#else
    (void)phase;
    (void)duty01;
#endif
}

void hal_mcpwm_enable(bool enable)
{
#ifdef LKS_SDK_LINK
    MCPWM_OutputMode(LKS_MCPWM, MCPWM_OUT_CHN_012, enable ? ENABLE : DISABLE);
#else
    (void)enable;
#endif
}

void hal_adc_init(void)
{
#ifdef LKS_SDK_LINK
    /* ADC + IRQ setup is done from hal_mcpwm_init(); keep for callers that only touch ADC. */
#else
#endif
}

uint16_t hal_adc_read(uint32_t channel)
{
#ifdef LKS_SDK_LINK
    return board_adc_get_raw(channel);
#else
    (void)channel;
    return 2048U;
#endif
}

void hal_can_init(uint32_t bitrate_kbps)
{
#ifdef LKS_SDK_LINK
    ensure_gpio_init();
    if (bitrate_kbps == 0U) {
        bitrate_kbps = 1000U;
    }

    CAN_InitTypeDef can;
    CAN_StructInit(&can);
    can.SBaud = (u16)bitrate_kbps;
    can.FBaud = (u16)bitrate_kbps;
    can.IE    = CAN_RTIE_EIE | CAN_RTIE_RIE;
    CAN_Init(&can);
    IDx_Filter(0, 0U, 0x1FFFFFFFU, IDEFilter_St_Ex);
#else
    (void)bitrate_kbps;
#endif
}

bool hal_can_send(uint32_t id, const uint8_t *data, uint8_t len)
{
#ifdef LKS_SDK_LINK
    if (data == NULL || len > 8U) {
        return false;
    }
    return CAN_Send_Msg((u32)id, 0U, 0U, 0U, 0U, (u8 *)data, len) == CanSend_Succ;
#else
    (void)id;
    (void)data;
    (void)len;
    return true;
#endif
}

bool hal_can_recv(uint32_t *id, uint8_t *data, uint8_t *len)
{
#ifdef LKS_SDK_LINK
    return board_can_take_rx(id, data, len);
#else
    (void)id;
    (void)data;
    if (len != NULL) {
        *len = 0U;
    }
    return false;
#endif
}

void hal_uart_init(uint32_t baud)
{
#ifdef LKS_SDK_LINK
    ensure_gpio_init();
    UART_InitTypeDef uart;
    UART_StructInit(&uart);
    uart.BAUDRATE = baud;
    uart.MD_EN    = DISABLE;
    UART_Init(LKS_UART_UNIT, &uart);
#else
    (void)baud;
#endif
}

void hal_uart_write(const char *s)
{
#ifdef LKS_SDK_LINK
    if (s == NULL) {
        return;
    }
    UART_SendnData(LKS_UART_UNIT, (char *)s, (u32)strlen(s));
#else
    (void)s;
#endif
}

bool hal_flash_write(uint32_t addr, const void *data, uint32_t len)
{
#ifdef LKS_SDK_LINK
    if (data == NULL || len == 0U) {
        return false;
    }

    uint32_t prog_len = (len + 15U) & ~15U;
    if (prog_len > 512U) {
        return false;
    }

    uint32_t buf[16];
    memset(buf, 0xFF, sizeof(buf));
    memcpy(buf, data, len);

    FLASH_EraseSector(addr);
    return FLASH_Program(addr, buf, prog_len) != 0U;
#else
    (void)addr;
    (void)data;
    (void)len;
    return false;
#endif
}
