#pragma once

/*
 * HY_GB4212_DRV_A4 — LKS32MC454NCQ8 pin / analog mapping.
 * Verify against the schematic before production bring-up.
 */

#include "board_pins.h"

/* MCPWM1 → EG3033 (GPIO1.P4–P9, six complementary outputs) */
#define LKS_MCPWM              MCPWM1
#define LKS_MCPWM_GPIO_PORT    GPIO1
#define LKS_MCPWM_PIN_FIRST    GPIO_PinSource_4
#define LKS_MCPWM_PIN_MASK     (GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9)

/* Triple-shunt + bus sense on ADC1 */
#define LKS_ADC_UNIT           ADC1
#define LKS_ADC_CH_IA          ADC_CHN_0
#define LKS_ADC_CH_IB          ADC_CHN_1
#define LKS_ADC_CH_IC          ADC_CHN_2
#define LKS_ADC_CH_VBUS        ADC_CHN_3
#define LKS_ADC_CH_TEMP        ADC_CHN_14

/* CAN transceiver P0.1 TX / P0.2 RX */
#define LKS_CAN_TX_PORT        GPIO0
#define LKS_CAN_TX_PIN         GPIO_Pin_1
#define LKS_CAN_TX_AF          GPIO_PinSource_1
#define LKS_CAN_RX_PORT        GPIO0
#define LKS_CAN_RX_PIN         GPIO_Pin_2
#define LKS_CAN_RX_AF          GPIO_PinSource_2

/* UART2 debug */
#define LKS_UART_UNIT          UART2
#define LKS_UART_TX_PORT       GPIO2
#define LKS_UART_TX_PIN        GPIO_Pin_0
#define LKS_UART_TX_AF         GPIO_PinSource_0
#define LKS_UART_RX_PORT       GPIO2
#define LKS_UART_RX_PIN        GPIO_Pin_1
#define LKS_UART_RX_AF         GPIO_PinSource_1

/* KTH7816 SSI (bit-bang) */
#define LKS_SSI_CLK_PORT       GPIO2
#define LKS_SSI_CLK_PIN        GPIO_Pin_10
#define LKS_SSI_DI_PORT        GPIO2
#define LKS_SSI_DI_PIN         GPIO_Pin_11

/* UI */
#define LKS_LED1_PORT          GPIO3
#define LKS_LED1_PIN           GPIO_Pin_0
#define LKS_LED2_PORT          GPIO3
#define LKS_LED2_PIN           GPIO_Pin_1
#define LKS_BTN1_PORT          GPIO3
#define LKS_BTN1_PIN           GPIO_Pin_2
#define LKS_BTN2_PORT          GPIO3
#define LKS_BTN2_PIN           GPIO_Pin_3
