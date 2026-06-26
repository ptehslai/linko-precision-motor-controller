#pragma once

/* Logical pin / channel IDs — board-independent names used by drivers and HAL. */

/* MCPWM phase outputs */
#define PIN_PWM_UH_GPIO 0
#define PIN_PWM_UL_GPIO 1
#define PIN_PWM_VH_GPIO 2
#define PIN_PWM_VL_GPIO 3
#define PIN_PWM_WH_GPIO 4
#define PIN_PWM_WL_GPIO 5

/* SSI encoder (bit-bang) */
#define PIN_SSI_CLK_GPIO 10
#define PIN_SSI_DI_GPIO  11

/* CAN transceiver */
#define PIN_CAN_TX_GPIO 20
#define PIN_CAN_RX_GPIO 21

/* UART debug */
#define PIN_UART2_TX_GPIO 22
#define PIN_UART2_RX_GPIO 23

/* LEDs / buttons */
#define PIN_LED1_GPIO 30
#define PIN_LED2_GPIO 31
#define PIN_BTN1_GPIO 32
#define PIN_BTN2_GPIO 33

/* ADC channels (logical) */
#define ADC_CH_IA 0
#define ADC_CH_IB 1
#define ADC_CH_IC 2
#define ADC_CH_VBUS 3
#define ADC_CH_TEMP 4
