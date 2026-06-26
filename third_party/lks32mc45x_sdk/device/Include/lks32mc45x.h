#ifndef _LKS32MC45x_H_
#define _LKS32MC45x_H_
#define  LKS32MC45X

//-----------------------------------------------------------
#include "basic.h"

#ifndef __NVIC_PRIO_BITS
  #define __NVIC_PRIO_BITS    3               /*!< standard definition for NVIC Priority Bits */
#endif

#ifndef __FPU_PRESENT
  #define __FPU_PRESENT 1U
#endif

typedef enum IRQn
{
/******  Cortex-M4 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn   = -14,    /*!< 2 Non Maskable Interrupt                             */
  HardFault_IRQn        = -13,    /*!< 3 Cortex-M4 Hard Fault Interrupt                     */
  SVCall_IRQn           = -5,     /*!< 11 Cortex-M4 SV Call Interrupt                       */
  PendSV_IRQn           = -2,     /*!< 14 Cortex-M4 Pend SV Interrupt                       */
  SysTick_IRQn          = -1,     /*!< 15 Cortex-M4 System Tick Interrupt                   */

/******  CM4IKMCU Cortex-M4 specific Interrupt Numbers ********************************************/
  I2C0_IRQn             = 0,      /*!< GPIO Interrupt                                       */
  I2C1_IRQn             = 1,
  HALL0_IRQn            = 2,
  HALL1_IRQn            = 3,
  UART0_IRQn            = 4,
  UART1_IRQn            = 5,
  UART2_IRQn            = 6,
  CMP0_IRQn             = 7,
  CMP1_IRQn             = 8,
  CMP2_IRQn             = 9,
  CMP3_IRQn             = 10,
  CMP4_IRQn             = 11,
  CMP5_IRQn             = 12,
  MCPWM00_IRQn          = 13,
  MCPWM01_IRQn          = 14,
  MCPWM10_IRQn          = 15,
  MCPWM11_IRQn          = 16,
  TIMER0_IRQn           = 17,
  TIMER1_IRQn           = 18,
  TIMER2_IRQn           = 19,
  TIMER3_IRQn           = 20,
  TIMER4_IRQn           = 21,
  QEP0_IRQn             = 22,
  QEP1_IRQn             = 23,
  QEP2_IRQn             = 24,
  QEP3_IRQn             = 25,
  EXTI_IRQn             = 26,
  ADC0_IRQn             = 27,
  ADC1_IRQn             = 28,
  ADC2_IRQn             = 29,
  CAN_IRQn              = 30,
  SPI0_IRQn             = 31,
  SPI1_IRQn             = 32,
  WWDG_IRQn             = 33,
  DMA_IRQn              = 34,
  WAKEUP_IRQn           = 35,
  PWRDN_IRQn            = 36,
  FMAC_IRQn             = 37,
  SW_IRQn               = 38,
} IRQn_Type;


#define ROM_TAB_BASE        0xF0000000
//-----------------------------------------------------------
#define SRAM0_BASE          0x20000000
#define SRAM1_BASE          0x20004000
#define SRAM2_BASE          0x20006000
#define SRAM3_BASE          0x20008000

#define I2C0_BASE 	    	0x40011000
#define I2C1_BASE 	    	0x40011400
#define HALL0_BASE 	    	0x40011800
#define HALL1_BASE 	    	0x40011C00
#define UART0_BASE          0x40012000
#define UART1_BASE          0x40012400
#define UART2_BASE          0x40012800
#define CMP_BASE            0x40013000
#define MCPWM0_BASE         0x40013400
#define MCPWM1_BASE         0x40013800
#define TIMER0_BASE         0x40014000
#define TIMER1_BASE         0x40014100
#define TIMER2_BASE         0x40014200
#define TIMER3_BASE         0x40014300
#define TIMER4_BASE         0x40014400
#define QEP0_BASE           0x40014500
#define QEP1_BASE           0x40014600
#define QEP2_BASE           0x40014700
#define QEP3_BASE           0x40014800
#define GPIO0_BASE          0x40016400
#define GPIO1_BASE          0x40016440
#define GPIO2_BASE          0x40016480
#define GPIO3_BASE          0x400164C0
#define GPIO4_BASE          0x40016500
#define GPIO5_BASE          0x40016540
#define EXTI_BASE           0x40016580
#define CRC_BASE            0x40016800
#define CORDIC_BASE         0x40016C00
#define FMAC_BASE           0x40017000
#define ADC0_BASE           0x40017800
#define ADC1_BASE           0x40017C00
#define ADC2_BASE           0x40018000
#define CAN_BASE            0x40018800
#define AFE_BASE            0x40019000
#define MISC_BASE           0x40019800
#define DMA_BASE            0x40019C00
#define FLS_CR_BASE         0x4001A000
#define IO_MASK_BASE        0x4001A400
#define SPI0_BASE 	    	0x4001A800
#define SPI1_BASE 	    	0x4001AC00
#define EXT_FLS_CR_BASE     0x4001B000
#define WWDT_BASE 	    	0x4001B400
#define AON_BASE            0x4001B800




#define FLASH_PASSEN       0xB714AD9C
#define FLASH_PASS_NVR_EN  0x7531FDB9
#define FLASH_PASS_PROG    0x2468ACE0
#define FLASH_PASS_ERASE   0x7654DCBA
#define FLASH_PASS_CONFEN  0x13579BDF


//#define FLASH_CFG           REG32(FLS_CR_BASE + 0x00)
//#define FLASH_ADDR          REG32(FLS_CR_BASE + 0x04)
//#define FLASH_WDATA         REG32(FLS_CR_BASE + 0x08)
//#define FLASH_RDATA         REG32(FLS_CR_BASE + 0x0C)
//
//#define FLASH_ERASE         REG32(FLS_CR_BASE + 0x10)
//#define FLASH_PROTECT       REG32(FLS_CR_BASE + 0x14)
//#define FLASH_READY         REG32(FLS_CR_BASE + 0x18)

#define FSMC_UCMD           REG32(FLS_CR_BASE + 0x00)
#define FSMC_UMOD           REG32(FLS_CR_BASE + 0x04)
#define FSMC_UADR           REG32(FLS_CR_BASE + 0x08)
#define FSMC_UWDA           REG32(FLS_CR_BASE + 0x0C)
#define FSMC_URDA           REG32(FLS_CR_BASE + 0x10)
#define FSMC_UPWT           REG32(FLS_CR_BASE + 0x14)
#define FSMC_UEWT           REG32(FLS_CR_BASE + 0x18)
#define FSMC_URWT           REG32(FLS_CR_BASE + 0x1C)
#define FSMC_UCFG           REG32(FLS_CR_BASE + 0x20)
#define FSMC_UTRG           REG32(FLS_CR_BASE + 0x24)

#define FSMC_FCMD           REG32(FLS_CR_BASE + 0x30)
#define FSMC_FMOD           REG32(FLS_CR_BASE + 0x34)
#define FSMC_FADR           REG32(FLS_CR_BASE + 0x38)
#define FSMC_FWDA           REG32(FLS_CR_BASE + 0x3C)
#define FSMC_FRDA           REG32(FLS_CR_BASE + 0x40)
#define FSMC_FPWT           REG32(FLS_CR_BASE + 0x44)
#define FSMC_FEWT           REG32(FLS_CR_BASE + 0x48)
#define FSMC_FRWT           REG32(FLS_CR_BASE + 0x4C)
#define FSMC_FCFG           REG32(FLS_CR_BASE + 0x50)
#define FSMC_FTRG           REG32(FLS_CR_BASE + 0x54)

#define FSMC_EDIV           REG32(FLS_CR_BASE + 0x60)
#define FSMC_WDAT0          REG32(FLS_CR_BASE + 0x70)
#define FSMC_WDAT1          REG32(FLS_CR_BASE + 0x74)
#define FSMC_WDAT2          REG32(FLS_CR_BASE + 0x78)
#define FSMC_WDAT3          REG32(FLS_CR_BASE + 0x7C)
#define FSMC_ICFG           REG32(FLS_CR_BASE + 0x80)
#define FSMC_ADDR           REG32(FLS_CR_BASE + 0x84)
#define FSMC_WDAT           REG32(FLS_CR_BASE + 0x88)
#define FSMC_RDAT           REG32(FLS_CR_BASE + 0x8C)
#define FSMC_ERAS           REG32(FLS_CR_BASE + 0x90)
#define FSMC_PROT           REG32(FLS_CR_BASE + 0x94)
#define FSMC_REDY           REG32(FLS_CR_BASE + 0x98)
#define FSMC_IDIV           REG32(FLS_CR_BASE + 0x9C)

#define SPI0_CFG            REG32(SPI0_BASE + 0x00)
#define SPI0_IE             REG32(SPI0_BASE + 0x04)
#define SPI0_BAUD           REG32(SPI0_BASE + 0x08)
#define SPI0_TX_DATA        REG32(SPI0_BASE + 0x0C)
#define SPI0_TXDATA         REG32(SPI0_BASE + 0x0C)
#define SPI0_RX_DATA        REG32(SPI0_BASE + 0x10)
#define SPI0_RXDATA         REG32(SPI0_BASE + 0x10)
#define SPI0_SIZE           REG32(SPI0_BASE + 0x14)
#define SPI0_BSIZE          REG32(SPI0_BASE + 0x14)

#define SPI1_CFG            REG32(SPI1_BASE + 0x00)
#define SPI1_IE             REG32(SPI1_BASE + 0x04)
#define SPI1_BAUD           REG32(SPI1_BASE + 0x08)
#define SPI1_TX_DATA        REG32(SPI1_BASE + 0x0C)
#define SPI1_TXDATA         REG32(SPI1_BASE + 0x0C)
#define SPI1_RX_DATA        REG32(SPI1_BASE + 0x10)
#define SPI1_RXDATA         REG32(SPI1_BASE + 0x10)
#define SPI1_SIZE           REG32(SPI1_BASE + 0x14)
#define SPI1_BSIZE          REG32(SPI1_BASE + 0x14)

#define I2C0_ADDR           REG32(I2C0_BASE + 0x00)
#define I2C0_CFG            REG32(I2C0_BASE + 0x04)
#define I2C0_SCR            REG32(I2C0_BASE + 0x08)
#define I2C0_DATA           REG32(I2C0_BASE + 0x0C)
#define I2C0_MSCR           REG32(I2C0_BASE + 0x10)
#define I2C0_BCR            REG32(I2C0_BASE + 0x14)

#define I2C1_ADDR           REG32(I2C1_BASE + 0x00)
#define I2C1_CFG            REG32(I2C1_BASE + 0x04)
#define I2C1_SCR            REG32(I2C1_BASE + 0x08)
#define I2C1_DATA           REG32(I2C1_BASE + 0x0C)
#define I2C1_MSCR           REG32(I2C1_BASE + 0x10)
#define I2C1_BCR            REG32(I2C1_BASE + 0x14)

#define HALL0_CFG           REG32(HALL0_BASE + 0x00)
#define HALL0_INFO          REG32(HALL0_BASE + 0x04)
#define HALL0_WIDTH         REG32(HALL0_BASE + 0x08)
#define HALL0_TH            REG32(HALL0_BASE + 0x0C)
#define HALL0_CNT           REG32(HALL0_BASE + 0x10)

#define HALL1_CFG           REG32(HALL1_BASE + 0x00)
#define HALL1_INFO          REG32(HALL1_BASE + 0x04)
#define HALL1_WIDTH         REG32(HALL1_BASE + 0x08)
#define HALL1_TH            REG32(HALL1_BASE + 0x0C)
#define HALL1_CNT           REG32(HALL1_BASE + 0x10)

#define HALL0               ((HALL_TypeDef *) HALL0_BASE)
#define HALL1               ((HALL_TypeDef *) HALL1_BASE)

#define UART0_CTRL          REG32(UART0_BASE + 0x00)
#define UART0_DIVH          REG32(UART0_BASE + 0x04)
#define UART0_DIVL          REG32(UART0_BASE + 0x08)
#define UART0_BUFF          REG32(UART0_BASE + 0x0C)
#define UART0_ADR           REG32(UART0_BASE + 0x10)
#define UART0_STT           REG32(UART0_BASE + 0x14)
#define UART0_RE            REG32(UART0_BASE + 0x18)
#define UART0_IE            REG32(UART0_BASE + 0x1C)
#define UART0_IF            REG32(UART0_BASE + 0x20)
#define UART0_IOC           REG32(UART0_BASE + 0x24)

#define UART1_CTRL          REG32(UART1_BASE + 0x00)
#define UART1_DIVH          REG32(UART1_BASE + 0x04)
#define UART1_DIVL          REG32(UART1_BASE + 0x08)
#define UART1_BUFF          REG32(UART1_BASE + 0x0C)
#define UART1_ADR           REG32(UART1_BASE + 0x10)
#define UART1_STT           REG32(UART1_BASE + 0x14)
#define UART1_RE            REG32(UART1_BASE + 0x18)
#define UART1_IE            REG32(UART1_BASE + 0x1C)
#define UART1_IF            REG32(UART1_BASE + 0x20)
#define UART1_IOC           REG32(UART1_BASE + 0x24)

#define UART2_CTRL          REG32(UART2_BASE + 0x00)
#define UART2_DIVH          REG32(UART2_BASE + 0x04)
#define UART2_DIVL          REG32(UART2_BASE + 0x08)
#define UART2_BUFF          REG32(UART2_BASE + 0x0C)
#define UART2_ADR           REG32(UART2_BASE + 0x10)
#define UART2_STT           REG32(UART2_BASE + 0x14)
#define UART2_RE            REG32(UART2_BASE + 0x18)
#define UART2_IE            REG32(UART2_BASE + 0x1C)
#define UART2_IF            REG32(UART2_BASE + 0x20)
#define UART2_IOC           REG32(UART2_BASE + 0x24)

#define UART0               ((UART_TypeDef *) UART0_BASE)
#define UART1               ((UART_TypeDef *) UART1_BASE)
#define UART2               ((UART_TypeDef *) UART2_BASE)

#define CMP_IE              REG32(CMP_BASE + 0x00)
#define CMP_IF              REG32(CMP_BASE + 0x04)
#define CMP_TCLK            REG32(CMP_BASE + 0x08)
#define CMP_CFG             REG32(CMP_BASE + 0x0C)
#define CMP_BLCWIN0         REG32(CMP_BASE + 0x10)
#define CMP_BLCWIN1         REG32(CMP_BASE + 0x14)
#define CMP_DATA            REG32(CMP_BASE + 0x18)

#define UTIMER0_CFG         REG32(TIMER0_BASE + 0x00)
#define UTIMER0_TH          REG32(TIMER0_BASE + 0x04)
#define UTIMER0_CNT         REG32(TIMER0_BASE + 0x08)
#define UTIMER0_CMP0        REG32(TIMER0_BASE + 0x0C)
#define UTIMER0_CMP1        REG32(TIMER0_BASE + 0x10)
#define UTIMER0_EVT         REG32(TIMER0_BASE + 0x14)
#define UTIMER0_FLT         REG32(TIMER0_BASE + 0x18)
#define UTIMER0_IE          REG32(TIMER0_BASE + 0x1C)
#define UTIMER0_IF          REG32(TIMER0_BASE + 0x20)

#define UTIMER1_CFG         REG32(TIMER1_BASE + 0x00)
#define UTIMER1_TH          REG32(TIMER1_BASE + 0x04)
#define UTIMER1_CNT         REG32(TIMER1_BASE + 0x08)
#define UTIMER1_CMP0        REG32(TIMER1_BASE + 0x0C)
#define UTIMER1_CMP1        REG32(TIMER1_BASE + 0x10)
#define UTIMER1_EVT         REG32(TIMER1_BASE + 0x14)
#define UTIMER1_FLT         REG32(TIMER1_BASE + 0x18)
#define UTIMER1_IE          REG32(TIMER1_BASE + 0x1C)
#define UTIMER1_IF          REG32(TIMER1_BASE + 0x20)

#define UTIMER2_CFG         REG32(TIMER2_BASE + 0x00)
#define UTIMER2_TH          REG32(TIMER2_BASE + 0x04)
#define UTIMER2_CNT         REG32(TIMER2_BASE + 0x08)
#define UTIMER2_CMP0        REG32(TIMER2_BASE + 0x0C)
#define UTIMER2_CMP1        REG32(TIMER2_BASE + 0x10)
#define UTIMER2_EVT         REG32(TIMER2_BASE + 0x14)
#define UTIMER2_FLT         REG32(TIMER2_BASE + 0x18)
#define UTIMER2_IE          REG32(TIMER2_BASE + 0x1C)
#define UTIMER2_IF          REG32(TIMER2_BASE + 0x20)

#define UTIMER3_CFG         REG32(TIMER3_BASE + 0x00)
#define UTIMER3_TH          REG32(TIMER3_BASE + 0x04)
#define UTIMER3_CNT         REG32(TIMER3_BASE + 0x08)
#define UTIMER3_CMP0        REG32(TIMER3_BASE + 0x0C)
#define UTIMER3_CMP1        REG32(TIMER3_BASE + 0x10)
#define UTIMER3_EVT         REG32(TIMER3_BASE + 0x14)
#define UTIMER3_FLT         REG32(TIMER3_BASE + 0x18)
#define UTIMER3_IE          REG32(TIMER3_BASE + 0x1C)
#define UTIMER3_IF          REG32(TIMER3_BASE + 0x20)

#define UTIMER4_CFG         REG32(TIMER4_BASE + 0x00)
#define UTIMER4_TH          REG32(TIMER4_BASE + 0x04)
#define UTIMER4_CNT         REG32(TIMER4_BASE + 0x08)
#define UTIMER4_CMP0        REG32(TIMER4_BASE + 0x0C)
#define UTIMER4_CMP1        REG32(TIMER4_BASE + 0x10)
#define UTIMER4_EVT         REG32(TIMER4_BASE + 0x14)
#define UTIMER4_FLT         REG32(TIMER4_BASE + 0x18)
#define UTIMER4_IE          REG32(TIMER4_BASE + 0x1C)
#define UTIMER4_IF          REG32(TIMER4_BASE + 0x20)

#define TIMER0              ((TIM_TimerTypeDef *) TIMER0_BASE)
#define TIMER1              ((TIM_TimerTypeDef *) (TIMER1_BASE))
#define TIMER2              ((TIM_TimerTypeDef *) (TIMER2_BASE))
#define TIMER3              ((TIM_TimerTypeDef *) (TIMER3_BASE))
#define TIMER4              ((TIM_TimerTypeDef *) (TIMER4_BASE))


#define QEP0_CFG            REG32(QEP0_BASE + 0x00)
#define QEP0_TH             REG32(QEP0_BASE + 0x04)
#define QEP0_CNT            REG32(QEP0_BASE + 0x08)
#define QEP0_IE             REG32(QEP0_BASE + 0x0C)
#define QEP0_IF             REG32(QEP0_BASE + 0x10)

#define QEP1_CFG            REG32(QEP1_BASE + 0x00)
#define QEP1_TH             REG32(QEP1_BASE + 0x04)
#define QEP1_CNT            REG32(QEP1_BASE + 0x08)
#define QEP1_IE             REG32(QEP1_BASE + 0x0C)
#define QEP1_IF             REG32(QEP1_BASE + 0x10)

#define QEP2_CFG            REG32(QEP2_BASE + 0x00)
#define QEP2_TH             REG32(QEP2_BASE + 0x04)
#define QEP2_CNT            REG32(QEP2_BASE + 0x08)
#define QEP2_IE             REG32(QEP2_BASE + 0x0C)
#define QEP2_IF             REG32(QEP2_BASE + 0x10)

#define QEP3_CFG            REG32(QEP3_BASE + 0x00)
#define QEP3_TH             REG32(QEP3_BASE + 0x04)
#define QEP3_CNT            REG32(QEP3_BASE + 0x08)
#define QEP3_IE             REG32(QEP3_BASE + 0x0C)
#define QEP3_IF             REG32(QEP3_BASE + 0x10)

#define QEP0                ((QEP_TypeDef *) (QEP0_BASE))
#define QEP1                ((QEP_TypeDef *) (QEP1_BASE))
#define QEP2                ((QEP_TypeDef *) (QEP2_BASE))
#define QEP3                ((QEP_TypeDef *) (QEP3_BASE))

#define MCPWM0_TH00         SREG16(MCPWM0_BASE + 0x00)
#define MCPWM0_TH01         SREG16(MCPWM0_BASE + 0x04)
#define MCPWM0_TH10         SREG16(MCPWM0_BASE + 0x08)
#define MCPWM0_TH11         SREG16(MCPWM0_BASE + 0x0C)
#define MCPWM0_TH20         SREG16(MCPWM0_BASE + 0x10)
#define MCPWM0_TH21         SREG16(MCPWM0_BASE + 0x14)
#define MCPWM0_TH30         SREG16(MCPWM0_BASE + 0x18)
#define MCPWM0_TH31         SREG16(MCPWM0_BASE + 0x1C)
#define MCPWM0_TMR0         SREG16(MCPWM0_BASE + 0x20)
#define MCPWM0_TMR1         SREG16(MCPWM0_BASE + 0x24)
#define MCPWM0_TMR2         SREG16(MCPWM0_BASE + 0x28)
#define MCPWM0_TMR3         SREG16(MCPWM0_BASE + 0x2C)
#define MCPWM0_TH0          REG32(MCPWM0_BASE + 0x30)
#define MCPWM0_TH1          REG32(MCPWM0_BASE + 0x34)
#define MCPWM0_CNT0         SREG16(MCPWM0_BASE + 0x38)
#define MCPWM0_CNT1         SREG16(MCPWM0_BASE + 0x3C)
#define MCPWM0_UPDATE       REG32(MCPWM0_BASE + 0x40)
#define MCPWM0_FCNT         REG32(MCPWM0_BASE + 0x44)
#define MCPWM0_EVT0         REG32(MCPWM0_BASE + 0x48)
#define MCPWM0_EVT1         REG32(MCPWM0_BASE + 0x4C)
#define MCPWM0_DTH00        REG32(MCPWM0_BASE + 0x50)
#define MCPWM0_DTH01        REG32(MCPWM0_BASE + 0x54)
#define MCPWM0_DTH10        REG32(MCPWM0_BASE + 0x58)
#define MCPWM0_DTH11        REG32(MCPWM0_BASE + 0x5C)
#define MCPWM0_DTH20        REG32(MCPWM0_BASE + 0x60)
#define MCPWM0_DTH21        REG32(MCPWM0_BASE + 0x64)
#define MCPWM0_DTH30        REG32(MCPWM0_BASE + 0x68)
#define MCPWM0_DTH31        REG32(MCPWM0_BASE + 0x6C)
#define MCPWM0_FLT          REG32(MCPWM0_BASE + 0x70)
#define MCPWM0_SDCFG        REG32(MCPWM0_BASE + 0x74)
#define MCPWM0_AUEN         REG32(MCPWM0_BASE + 0x78)
#define MCPWM0_TCLK         REG32(MCPWM0_BASE + 0x7C)
#define MCPWM0_IE0          REG32(MCPWM0_BASE + 0x80)
#define MCPWM0_IF0          REG32(MCPWM0_BASE + 0x84)
#define MCPWM0_IE1          REG32(MCPWM0_BASE + 0x88)
#define MCPWM0_IF1          REG32(MCPWM0_BASE + 0x8C)
#define MCPWM0_EIE          REG32(MCPWM0_BASE + 0x90)
#define MCPWM0_EIF          REG32(MCPWM0_BASE + 0x94)
#define MCPWM0_RE           REG32(MCPWM0_BASE + 0x98)
#define MCPWM0_PP           REG32(MCPWM0_BASE + 0x9C)
#define MCPWM0_IO01         REG32(MCPWM0_BASE + 0xA0)
#define MCPWM0_IO23         REG32(MCPWM0_BASE + 0xA4)

#define MCPWM0_FAIL012      REG32(MCPWM0_BASE + 0xA8)
#define MCPWM0_FAIL3        REG32(MCPWM0_BASE + 0xAC)
#define MCPWM0_PRT          REG32(MCPWM0_BASE + 0xB0)
#define MCPWM0_CHMSK		REG32(MCPWM0_BASE + 0xB8)

#define MCPWM1_TH00         SREG16(MCPWM1_BASE + 0x00)
#define MCPWM1_TH01         SREG16(MCPWM1_BASE + 0x04)
#define MCPWM1_TH10         SREG16(MCPWM1_BASE + 0x08)
#define MCPWM1_TH11         SREG16(MCPWM1_BASE + 0x0C)
#define MCPWM1_TH20         SREG16(MCPWM1_BASE + 0x10)
#define MCPWM1_TH21         SREG16(MCPWM1_BASE + 0x14)
#define MCPWM1_TH30         SREG16(MCPWM1_BASE + 0x18)
#define MCPWM1_TH31         SREG16(MCPWM1_BASE + 0x1C)
#define MCPWM1_TMR0         SREG16(MCPWM1_BASE + 0x20)
#define MCPWM1_TMR1         SREG16(MCPWM1_BASE + 0x24)
#define MCPWM1_TMR2         SREG16(MCPWM1_BASE + 0x28)
#define MCPWM1_TMR3         SREG16(MCPWM1_BASE + 0x2C)
#define MCPWM1_TH0          REG32(MCPWM1_BASE + 0x30)
#define MCPWM1_TH1          REG32(MCPWM1_BASE + 0x34)
#define MCPWM1_CNT0         SREG16(MCPWM1_BASE + 0x38)
#define MCPWM1_CNT1         SREG16(MCPWM1_BASE + 0x3C)
#define MCPWM1_UPDATE       REG32(MCPWM1_BASE + 0x40)
#define MCPWM1_FCNT         REG32(MCPWM1_BASE + 0x44)
#define MCPWM1_EVT0         REG32(MCPWM1_BASE + 0x48)
#define MCPWM1_EVT1         REG32(MCPWM1_BASE + 0x4C)
#define MCPWM1_DTH00        REG32(MCPWM1_BASE + 0x50)
#define MCPWM1_DTH01        REG32(MCPWM1_BASE + 0x54)
#define MCPWM1_DTH10        REG32(MCPWM1_BASE + 0x58)
#define MCPWM1_DTH11        REG32(MCPWM1_BASE + 0x5C)
#define MCPWM1_DTH20        REG32(MCPWM1_BASE + 0x60)
#define MCPWM1_DTH21        REG32(MCPWM1_BASE + 0x64)
#define MCPWM1_DTH30        REG32(MCPWM1_BASE + 0x68)
#define MCPWM1_DTH31        REG32(MCPWM1_BASE + 0x6C)
#define MCPWM1_FLT          REG32(MCPWM1_BASE + 0x70)
#define MCPWM1_SDCFG        REG32(MCPWM1_BASE + 0x74)
#define MCPWM1_AUEN         REG32(MCPWM1_BASE + 0x78)
#define MCPWM1_TCLK         REG32(MCPWM1_BASE + 0x7C)
#define MCPWM1_IE0          REG32(MCPWM1_BASE + 0x80)
#define MCPWM1_IF0          REG32(MCPWM1_BASE + 0x84)
#define MCPWM1_IE1          REG32(MCPWM1_BASE + 0x88)
#define MCPWM1_IF1          REG32(MCPWM1_BASE + 0x8C)
#define MCPWM1_EIE          REG32(MCPWM1_BASE + 0x90)
#define MCPWM1_EIF          REG32(MCPWM1_BASE + 0x94)
#define MCPWM1_RE           REG32(MCPWM1_BASE + 0x98)
#define MCPWM1_PP           REG32(MCPWM1_BASE + 0x9C)
#define MCPWM1_IO01         REG32(MCPWM1_BASE + 0xA0)
#define MCPWM1_IO23         REG32(MCPWM1_BASE + 0xA4)

#define MCPWM1_FAIL012      REG32(MCPWM1_BASE + 0xA8)
#define MCPWM1_FAIL3        REG32(MCPWM1_BASE + 0xAC)
#define MCPWM1_PRT          REG32(MCPWM1_BASE + 0xB0)
#define MCPWM1_CHMSK		REG32(MCPWM1_BASE + 0xB8)

#define PSW_PRT             0xDEAD
#define PSW_MCPWM_PRT       0xDEAD

#define MCPWM0              ((MCPWM_REG_TypeDef *)MCPWM0_BASE)
#define MCPWM1              ((MCPWM_REG_TypeDef *)MCPWM1_BASE)

#define GPIO0_PIE           REG32(GPIO0_BASE + 0x00)       //0x4001_6400
#define GPIO0_POE           REG32(GPIO0_BASE + 0x04)       //
#define GPIO0_PDI           REG32(GPIO0_BASE + 0x08)
#define GPIO0_PDO           REG32(GPIO0_BASE + 0x0C)
#define GPIO0_PUE           REG32(GPIO0_BASE + 0x10)
#define GPIO0_PDE           REG32(GPIO0_BASE + 0x14)
#define GPIO0_PODE          REG32(GPIO0_BASE + 0x18)
#define GPIO0_PFLT          REG32(GPIO0_BASE + 0x1C)
#define GPIO0_F3210         REG32(GPIO0_BASE + 0x20)
#define GPIO0_F7654         REG32(GPIO0_BASE + 0x24)
#define GPIO0_FBA98         REG32(GPIO0_BASE + 0x28)
#define GPIO0_FFEDC         REG32(GPIO0_BASE + 0x2C)
#define GPIO0_BSRR          REG32(GPIO0_BASE + 0x30)
#define GPIO0_BRR           REG32(GPIO0_BASE + 0x34)

#define GPIO1_PIE           REG32(GPIO1_BASE + 0x00)
#define GPIO1_POE           REG32(GPIO1_BASE + 0x04)
#define GPIO1_PDI           REG32(GPIO1_BASE + 0x08)
#define GPIO1_PDO           REG32(GPIO1_BASE + 0x0C)
#define GPIO1_PUE           REG32(GPIO1_BASE + 0x10)
#define GPIO1_PDE           REG32(GPIO1_BASE + 0x14)
#define GPIO1_PODE          REG32(GPIO1_BASE + 0x18)
#define GPIO1_PFLT          REG32(GPIO1_BASE + 0x1C)
#define GPIO1_F3210         REG32(GPIO1_BASE + 0x20)
#define GPIO1_F7654         REG32(GPIO1_BASE + 0x24)
#define GPIO1_FBA98         REG32(GPIO1_BASE + 0x28)
#define GPIO1_FFEDC         REG32(GPIO1_BASE + 0x2C)
#define GPIO1_BSRR          REG32(GPIO1_BASE + 0x30)
#define GPIO1_BRR           REG32(GPIO1_BASE + 0x34)

#define GPIO2_PIE           REG32(GPIO2_BASE + 0x00)
#define GPIO2_POE           REG32(GPIO2_BASE + 0x04)
#define GPIO2_PDI           REG32(GPIO2_BASE + 0x08)
#define GPIO2_PDO           REG32(GPIO2_BASE + 0x0C)
#define GPIO2_PUE           REG32(GPIO2_BASE + 0x10)
#define GPIO2_PDE           REG32(GPIO2_BASE + 0x14)
#define GPIO2_PODE          REG32(GPIO2_BASE + 0x18)
#define GPIO2_PFLT          REG32(GPIO2_BASE + 0x1C)
#define GPIO2_F3210         REG32(GPIO2_BASE + 0x20)
#define GPIO2_F7654         REG32(GPIO2_BASE + 0x24)
#define GPIO2_FBA98         REG32(GPIO2_BASE + 0x28)
#define GPIO2_FFEDC         REG32(GPIO2_BASE + 0x2C)
#define GPIO2_BSRR          REG32(GPIO2_BASE + 0x30)
#define GPIO2_BRR           REG32(GPIO2_BASE + 0x34)

#define GPIO3_PIE           REG32(GPIO3_BASE + 0x00)
#define GPIO3_POE           REG32(GPIO3_BASE + 0x04)
#define GPIO3_PDI           REG32(GPIO3_BASE + 0x08)
#define GPIO3_PDO           REG32(GPIO3_BASE + 0x0C)
#define GPIO3_PUE           REG32(GPIO3_BASE + 0x10)
#define GPIO3_PDE           REG32(GPIO3_BASE + 0x14)
#define GPIO3_PODE          REG32(GPIO3_BASE + 0x18)
#define GPIO3_PFLT          REG32(GPIO3_BASE + 0x1C)
#define GPIO3_F3210         REG32(GPIO3_BASE + 0x20)
#define GPIO3_F7654         REG32(GPIO3_BASE + 0x24)
#define GPIO3_FBA98         REG32(GPIO3_BASE + 0x28)
#define GPIO3_FFEDC         REG32(GPIO3_BASE + 0x2C)
#define GPIO3_BSRR          REG32(GPIO3_BASE + 0x30)
#define GPIO3_BRR           REG32(GPIO3_BASE + 0x34)

#define GPIO4_PIE           REG32(GPIO4_BASE + 0x00)
#define GPIO4_POE           REG32(GPIO4_BASE + 0x04)
#define GPIO4_PDI           REG32(GPIO4_BASE + 0x08)
#define GPIO4_PDO           REG32(GPIO4_BASE + 0x0C)
#define GPIO4_PUE           REG32(GPIO4_BASE + 0x10)
#define GPIO4_PDE           REG32(GPIO4_BASE + 0x14)
#define GPIO4_PODE          REG32(GPIO4_BASE + 0x18)
#define GPIO4_PFLT          REG32(GPIO4_BASE + 0x1C)
#define GPIO4_F3210         REG32(GPIO4_BASE + 0x20)
#define GPIO4_F7654         REG32(GPIO4_BASE + 0x24)
#define GPIO4_FBA98         REG32(GPIO4_BASE + 0x28)
#define GPIO4_FFEDC         REG32(GPIO4_BASE + 0x2C)
#define GPIO4_BSRR          REG32(GPIO4_BASE + 0x30)
#define GPIO4_BRR           REG32(GPIO4_BASE + 0x34)

#define GPIO5_PIE           REG32(GPIO5_BASE + 0x00)
#define GPIO5_POE           REG32(GPIO5_BASE + 0x04)
#define GPIO5_PDI           REG32(GPIO5_BASE + 0x08)
#define GPIO5_PDO           REG32(GPIO5_BASE + 0x0C)
#define GPIO5_PUE           REG32(GPIO5_BASE + 0x10)
#define GPIO5_PDE           REG32(GPIO5_BASE + 0x14)
#define GPIO5_PODE          REG32(GPIO5_BASE + 0x18)
#define GPIO5_PFLT          REG32(GPIO5_BASE + 0x1C)
#define GPIO5_F3210         REG32(GPIO5_BASE + 0x20)
#define GPIO5_F7654         REG32(GPIO5_BASE + 0x24)
#define GPIO5_FBA98         REG32(GPIO5_BASE + 0x28)
#define GPIO5_FFEDC         REG32(GPIO5_BASE + 0x2C)
#define GPIO5_BSRR          REG32(GPIO5_BASE + 0x30)
#define GPIO5_BRR           REG32(GPIO5_BASE + 0x34)

#define GPIO0               ((GPIO_TypeDef *) GPIO0_BASE)
#define GPIO1               ((GPIO_TypeDef *) GPIO1_BASE)
#define GPIO2               ((GPIO_TypeDef *) GPIO2_BASE)
#define GPIO3               ((GPIO_TypeDef *) GPIO3_BASE)
#define GPIO4               ((GPIO_TypeDef *) GPIO4_BASE)
#define GPIO5               ((GPIO_TypeDef *) GPIO5_BASE)

#define EXTI0_CR0           REG32(EXTI_BASE  + 0x00)
#define EXTI0_CR1           REG32(EXTI_BASE  + 0x04)
#define EXTI1_CR0           REG32(EXTI_BASE  + 0x08)
#define EXTI1_CR1           REG32(EXTI_BASE  + 0x0C)
#define EXTI2_CR0           REG32(EXTI_BASE  + 0x10)
#define EXTI2_CR1           REG32(EXTI_BASE  + 0x14)
#define EXTI3_CR0           REG32(EXTI_BASE  + 0x18)
#define EXTI3_CR1           REG32(EXTI_BASE  + 0x1C)
#define EXTI4_CR0           REG32(EXTI_BASE  + 0x20)
#define EXTI4_CR1           REG32(EXTI_BASE  + 0x24)
#define EXTI5_CR0           REG32(EXTI_BASE  + 0x28)
#define EXTI5_CR1           REG32(EXTI_BASE  + 0x2C)
#define EXTI0_IF            REG32(EXTI_BASE  + 0x30)
#define EXTI1_IF            REG32(EXTI_BASE  + 0x34)
#define EXTI2_IF            REG32(EXTI_BASE  + 0x38)
#define EXTI3_IF            REG32(EXTI_BASE  + 0x3C)
#define EXTI4_IF            REG32(EXTI_BASE  + 0x40)
#define EXTI5_IF            REG32(EXTI_BASE  + 0x44)
#define CLKO_SEL            REG32(EXTI_BASE  + 0x50)
#define LCKR_PRT            REG32(EXTI_BASE  + 0x54)
#define EXTI_REN            REG32(EXTI_BASE  + 0x58)

#define CRC_DR              REG32(CRC_BASE   + 0x00)
#define CRC_CR              REG32(CRC_BASE   + 0x04)
#define CRC_INIT            REG32(CRC_BASE   + 0x08)
#define CRC_POL             REG32(CRC_BASE   + 0x0C)

#define DSP_SC              REG32(CORDIC_BASE + 0x00)
#define DSP_CORDIC_THETA    REG32(CORDIC_BASE + 0x04)
#define DSP_CORDIC_X        REG32(CORDIC_BASE + 0x08)
#define DSP_CORDIC_Y        REG32(CORDIC_BASE + 0x0C)
#define DSP_CORDIC_SIN      REG32(CORDIC_BASE + 0x10)
#define DSP_CORDIC_COS      REG32(CORDIC_BASE + 0x14)
#define DSP_CORDIC_MOD      REG32(CORDIC_BASE + 0x18)
#define DSP_CORDIC_ARCTAN   REG32(CORDIC_BASE + 0x1C)

#define DSP_THETA    		REG32(CORDIC_BASE + 0x04)
#define DSP_X        		REG32(CORDIC_BASE + 0x08)
#define DSP_Y        		REG32(CORDIC_BASE + 0x0C)
#define DSP_SIN      		REG32(CORDIC_BASE + 0x10)
#define DSP_COS      		REG32(CORDIC_BASE + 0x14)
#define DSP_MOD      		REG32(CORDIC_BASE + 0x18)
#define DSP_ARCTAN   		REG32(CORDIC_BASE + 0x1C)

#define FMAC_X1BUFCFG       REG32(FMAC_BASE + 0x00)
#define FMAC_X2BUFCFG       REG32(FMAC_BASE + 0x04)
#define FMAC_YBUFCFG        REG32(FMAC_BASE + 0x08)
#define FMAC_PARAM          REG32(FMAC_BASE + 0x0C)
#define FMAC_CR             REG32(FMAC_BASE + 0x10)
#define FMAC_SR             REG32(FMAC_BASE + 0x14)
#define FMAC_WDATA          REG32(FMAC_BASE + 0x18)
#define FMAC_RDATA          REG32(FMAC_BASE + 0x1C)
#define FMAC_MEM_BASE       (FMAC_BASE + 0x400)

#define ADC0                ((ADC_TypeDef *) ADC0_BASE)
#define ADC0_DAT0           SREG16(ADC0_BASE + 0x00)
#define ADC0_DAT1           SREG16(ADC0_BASE + 0x04)
#define ADC0_DAT2           SREG16(ADC0_BASE + 0x08)
#define ADC0_DAT3           SREG16(ADC0_BASE + 0x0C)
#define ADC0_DAT4           SREG16(ADC0_BASE + 0x10)
#define ADC0_DAT5           SREG16(ADC0_BASE + 0x14)
#define ADC0_DAT6           SREG16(ADC0_BASE + 0x18)
#define ADC0_DAT7           SREG16(ADC0_BASE + 0x1C)
#define ADC0_DAT8           SREG16(ADC0_BASE + 0x20)
#define ADC0_DAT9           SREG16(ADC0_BASE + 0x24)
#define ADC0_DAT10          SREG16(ADC0_BASE + 0x28)
#define ADC0_DAT11          SREG16(ADC0_BASE + 0x2C)
#define ADC0_DAT12          SREG16(ADC0_BASE + 0x30)
#define ADC0_DAT13          SREG16(ADC0_BASE + 0x34)
#define ADC0_DAT14          SREG16(ADC0_BASE + 0x38)
#define ADC0_DAT15          SREG16(ADC0_BASE + 0x3C)

#define ADC0_PCHN0          REG32(ADC0_BASE + 0x40)
#define ADC0_PCHN1          REG32(ADC0_BASE + 0x44)
#define ADC0_PCHN2          REG32(ADC0_BASE + 0x48)
#define ADC0_PCHN3          REG32(ADC0_BASE + 0x4C)
#define ADC0_NCHN0          REG32(ADC0_BASE + 0x50)
#define ADC0_NCHN1          REG32(ADC0_BASE + 0x54)
#define ADC0_NCHN2          REG32(ADC0_BASE + 0x58)
#define ADC0_NCHN3          REG32(ADC0_BASE + 0x5C)
#define ADC0_CHNT           REG32(ADC0_BASE + 0x60)
#define ADC0_GAIN           REG32(ADC0_BASE + 0x70)
#define ADC0_CFG            REG32(ADC0_BASE + 0x74)
#define ADC0_TRIG           REG32(ADC0_BASE + 0x78)
#define ADC0_SWT            REG32(ADC0_BASE + 0x7C)

#define ADC0_DC0            REG32(ADC0_BASE + 0x80)
#define ADC0_AMC0           REG32(ADC0_BASE + 0x84)
#define ADC0_DC1            REG32(ADC0_BASE + 0x88)
#define ADC0_AMC1           REG32(ADC0_BASE + 0x8C)
#define ADC0_IE             REG32(ADC0_BASE + 0x90)
#define ADC0_IF             REG32(ADC0_BASE + 0x94)
#define ADC0_TH0            REG32(ADC0_BASE + 0x98)
#define ADC0_GEN0           REG32(ADC0_BASE + 0x9C)
#define ADC0_TH1            REG32(ADC0_BASE + 0xA0)
#define ADC0_GEN1           REG32(ADC0_BASE + 0xA4)

#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC1_DAT0           SREG16(ADC1_BASE + 0x00)
#define ADC1_DAT1           SREG16(ADC1_BASE + 0x04)
#define ADC1_DAT2           SREG16(ADC1_BASE + 0x08)
#define ADC1_DAT3           SREG16(ADC1_BASE + 0x0C)
#define ADC1_DAT4           SREG16(ADC1_BASE + 0x10)
#define ADC1_DAT5           SREG16(ADC1_BASE + 0x14)
#define ADC1_DAT6           SREG16(ADC1_BASE + 0x18)
#define ADC1_DAT7           SREG16(ADC1_BASE + 0x1C)
#define ADC1_DAT8           SREG16(ADC1_BASE + 0x20)
#define ADC1_DAT9           SREG16(ADC1_BASE + 0x24)
#define ADC1_DAT10          SREG16(ADC1_BASE + 0x28)
#define ADC1_DAT11          SREG16(ADC1_BASE + 0x2C)
#define ADC1_DAT12          SREG16(ADC1_BASE + 0x30)
#define ADC1_DAT13          SREG16(ADC1_BASE + 0x34)
#define ADC1_DAT14          SREG16(ADC1_BASE + 0x38)
#define ADC1_DAT15          SREG16(ADC1_BASE + 0x3C)

#define ADC1_PCHN0          REG32(ADC1_BASE + 0x40)
#define ADC1_PCHN1          REG32(ADC1_BASE + 0x44)
#define ADC1_PCHN2          REG32(ADC1_BASE + 0x48)
#define ADC1_PCHN3          REG32(ADC1_BASE + 0x4C)
#define ADC1_NCHN0          REG32(ADC1_BASE + 0x50)
#define ADC1_NCHN1          REG32(ADC1_BASE + 0x54)
#define ADC1_NCHN2          REG32(ADC1_BASE + 0x58)
#define ADC1_NCHN3          REG32(ADC1_BASE + 0x5C)
#define ADC1_CHNT           REG32(ADC1_BASE + 0x60)
#define ADC1_GAIN           REG32(ADC1_BASE + 0x70)
#define ADC1_CFG            REG32(ADC1_BASE + 0x74)
#define ADC1_TRIG           REG32(ADC1_BASE + 0x78)
#define ADC1_SWT            REG32(ADC1_BASE + 0x7C)

#define ADC1_DC0            REG32(ADC1_BASE + 0x80)
#define ADC1_AMC0           REG32(ADC1_BASE + 0x84)
#define ADC1_DC1            REG32(ADC1_BASE + 0x88)
#define ADC1_AMC1           REG32(ADC1_BASE + 0x8C)
#define ADC1_IE             REG32(ADC1_BASE + 0x90)
#define ADC1_IF             REG32(ADC1_BASE + 0x94)
#define ADC1_TH0            REG32(ADC1_BASE + 0x98)
#define ADC1_GEN0           REG32(ADC1_BASE + 0x9C)
#define ADC1_TH1            REG32(ADC1_BASE + 0xA0)
#define ADC1_GEN1           REG32(ADC1_BASE + 0xA4)

#define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#define ADC2_DAT0           SREG16(ADC2_BASE + 0x00)
#define ADC2_DAT1           SREG16(ADC2_BASE + 0x04)
#define ADC2_DAT2           SREG16(ADC2_BASE + 0x08)
#define ADC2_DAT3           SREG16(ADC2_BASE + 0x0C)
#define ADC2_DAT4           SREG16(ADC2_BASE + 0x10)
#define ADC2_DAT5           SREG16(ADC2_BASE + 0x14)
#define ADC2_DAT6           SREG16(ADC2_BASE + 0x18)
#define ADC2_DAT7           SREG16(ADC2_BASE + 0x1C)
#define ADC2_DAT8           SREG16(ADC2_BASE + 0x20)
#define ADC2_DAT9           SREG16(ADC2_BASE + 0x24)
#define ADC2_DAT10          SREG16(ADC2_BASE + 0x28)
#define ADC2_DAT11          SREG16(ADC2_BASE + 0x2C)
#define ADC2_DAT12          SREG16(ADC2_BASE + 0x30)
#define ADC2_DAT13          SREG16(ADC2_BASE + 0x34)
#define ADC2_DAT14          SREG16(ADC2_BASE + 0x38)
#define ADC2_DAT15          SREG16(ADC2_BASE + 0x3C)

#define ADC2_PCHN0          REG32(ADC2_BASE + 0x40)
#define ADC2_PCHN1          REG32(ADC2_BASE + 0x44)
#define ADC2_PCHN2          REG32(ADC2_BASE + 0x48)
#define ADC2_PCHN3          REG32(ADC2_BASE + 0x4C)
#define ADC2_NCHN0          REG32(ADC2_BASE + 0x50)
#define ADC2_NCHN1          REG32(ADC2_BASE + 0x54)
#define ADC2_NCHN2          REG32(ADC2_BASE + 0x58)
#define ADC2_NCHN3          REG32(ADC2_BASE + 0x5C)
#define ADC2_CHNT           REG32(ADC2_BASE + 0x60)
#define ADC2_GAIN           REG32(ADC2_BASE + 0x70)
#define ADC2_CFG            REG32(ADC2_BASE + 0x74)
#define ADC2_TRIG           REG32(ADC2_BASE + 0x78)
#define ADC2_SWT            REG32(ADC2_BASE + 0x7C)

#define ADC2_DC0            REG32(ADC2_BASE + 0x80)
#define ADC2_AMC0           REG32(ADC2_BASE + 0x84)
#define ADC2_DC1            REG32(ADC2_BASE + 0x88)
#define ADC2_AMC1           REG32(ADC2_BASE + 0x8C)
#define ADC2_IE             REG32(ADC2_BASE + 0x90)
#define ADC2_IF             REG32(ADC2_BASE + 0x94)
#define ADC2_TH0            REG32(ADC2_BASE + 0x98)
#define ADC2_GEN0           REG32(ADC2_BASE + 0x9C)
#define ADC2_TH1            REG32(ADC2_BASE + 0xA0)
#define ADC2_GEN1           REG32(ADC2_BASE + 0xA4)

#define CAN_RBUF_00         REG32(CAN_BASE + 0x0000)
#define CAN_RBUF_01         REG32(CAN_BASE + 0x0004)
#define CAN_RBUF_02         REG32(CAN_BASE + 0x0008)
#define CAN_RBUF_03         REG32(CAN_BASE + 0x000C)
#define CAN_RBUF_04         REG32(CAN_BASE + 0x0010)
#define CAN_RBUF_05         REG32(CAN_BASE + 0x0014)
#define CAN_RBUF_06         REG32(CAN_BASE + 0x0018)
#define CAN_RBUF_07         REG32(CAN_BASE + 0x001C)
#define CAN_RBUF_08         REG32(CAN_BASE + 0x0020)
#define CAN_RBUF_09         REG32(CAN_BASE + 0x0024)
#define CAN_RBUF_10         REG32(CAN_BASE + 0x0028)
#define CAN_RBUF_11         REG32(CAN_BASE + 0x002C)
#define CAN_RBUF_12         REG32(CAN_BASE + 0x0030)
#define CAN_RBUF_13         REG32(CAN_BASE + 0x0034)
#define CAN_RBUF_14         REG32(CAN_BASE + 0x0038)
#define CAN_RBUF_15         REG32(CAN_BASE + 0x003C)
#define CAN_RBUF_16         REG32(CAN_BASE + 0x0040)
#define CAN_RBUF_17         REG32(CAN_BASE + 0x0044)
#define CAN_RBUF_18         REG32(CAN_BASE + 0x0048)
#define CAN_RBUF_19         REG32(CAN_BASE + 0x004C)


#define CAN_TBUF_00         REG32(CAN_BASE + 0x0050)
#define CAN_TBUF_01         REG32(CAN_BASE + 0x0054)
#define CAN_TBUF_02         REG32(CAN_BASE + 0x0058)
#define CAN_TBUF_03         REG32(CAN_BASE + 0x005C)
#define CAN_TBUF_04         REG32(CAN_BASE + 0x0060)
#define CAN_TBUF_05         REG32(CAN_BASE + 0x0064)
#define CAN_TBUF_06         REG32(CAN_BASE + 0x0068)
#define CAN_TBUF_07         REG32(CAN_BASE + 0x006C)
#define CAN_TBUF_08         REG32(CAN_BASE + 0x0070)
#define CAN_TBUF_09         REG32(CAN_BASE + 0x0074)
#define CAN_TBUF_10         REG32(CAN_BASE + 0x0078)
#define CAN_TBUF_11         REG32(CAN_BASE + 0x007C)
#define CAN_TBUF_12         REG32(CAN_BASE + 0x0080)
#define CAN_TBUF_13         REG32(CAN_BASE + 0x0084)
#define CAN_TBUF_14         REG32(CAN_BASE + 0x0088)
#define CAN_TBUF_15         REG32(CAN_BASE + 0x008C)
#define CAN_TBUF_16         REG32(CAN_BASE + 0x0090)
#define CAN_TBUF_17         REG32(CAN_BASE + 0x0094)

#define CAN_TTS_0           REG32(CAN_BASE + 0x0098)
#define CAN_TTS_1           REG32(CAN_BASE + 0x009C)

#define CAN_CFG_STAT        REG8(CAN_BASE  + 0x00A0)
#define CAN_TCMD            REG8(CAN_BASE  + 0x00A1)
#define CAN_TCTRL           REG8(CAN_BASE  + 0x00A2)
#define CAN_RCTRL           REG8(CAN_BASE  + 0x00A3)

#define CAN_RTIE            REG8(CAN_BASE  + 0x00A4)
#define CAN_RTIF            REG8(CAN_BASE  + 0x00A5)
#define CAN_ERRINT          REG8(CAN_BASE  + 0x00A6)
#define CAN_LIMIT           REG8(CAN_BASE  + 0x00A7)
#define CAN_SBAUD           REG32(CAN_BASE + 0x00A8)
#define CAN_FBAUD           REG32(CAN_BASE + 0x00AC)
#define CAN_EALCAP          REG8(CAN_BASE  + 0x00B0)
#define CAN_TDC             REG8(CAN_BASE  + 0x00B1)
#define CAN_RECNT           REG8(CAN_BASE  + 0x00B2)
#define CAN_TECNT           REG8(CAN_BASE  + 0x00B3)
#define CAN_ACFCTRL         REG8(CAN_BASE  + 0x00B4)
#define CAN_TIMECFG         REG8(CAN_BASE  + 0x00B5)
#define CAN_ACFEN           REG16(CAN_BASE + 0x00B6)
#define CAN_ACF             REG32(CAN_BASE + 0x00B8)//same address has different meaning
#define CAN_TBSLOT          REG8(CAN_BASE  + 0x00BE)
#define CAN_TTCFG           REG8(CAN_BASE  + 0x00BF)
#define CAN_REF_MSG         REG32(CAN_BASE + 0x00C0)
#define CAN_TRG_CFG         REG16(CAN_BASE + 0x00C4)
#define CAN_TT_TRIG         REG16(CAN_BASE + 0x00C6)
#define CAN_TT_WTRIG        REG16(CAN_BASE + 0x00C8)

#define CAN_CIAWDAT0        REG32(CAN_BASE + 0x00D0)
#define CAN_CIAWDAT1        REG32(CAN_BASE + 0x00D4)

//#define SCR_SYS_BOOT        REG32(MISC_BASE + 0x00)
#define SYS_AFE_ADC         REG32(MISC_BASE + 0x00)
#define SYS_AFE_INFO        REG32(MISC_BASE + 0x04)
#define SYS_AFE_DBG0		REG32(MISC_BASE + 0x08)
#define SYS_AFE_REG0        REG32(MISC_BASE + 0x10)
#define SYS_AFE_REG1        REG32(MISC_BASE + 0x14)
#define SYS_AFE_REG2        REG32(MISC_BASE + 0x18)
#define SYS_AFE_REG3        REG32(MISC_BASE + 0x1C)
#define SYS_AFE_REG4        REG32(MISC_BASE + 0x20)
#define SYS_AFE_REG5        REG32(MISC_BASE + 0x24)
#define SYS_AFE_REG6        REG32(MISC_BASE + 0x28)
#define SYS_AFE_REG9        REG32(MISC_BASE + 0x34)
#define SYS_AFE_REGA        REG32(MISC_BASE + 0x38)
#define SYS_AFE_REGB        REG32(MISC_BASE + 0x3C)
#define SYS_TMP_A           REG32(MISC_BASE + 0x58)
#define SYS_TMP_B           REG32(MISC_BASE + 0x5C)
#define SYS_AFE_DAC0        REG32(MISC_BASE + 0x60)
#define SYS_AFE_DAC0_AMC    REG32(MISC_BASE + 0x64)
#define SYS_AFE_DAC0_DC     REG32(MISC_BASE + 0x68)
#define SYS_AFE_DAC1        REG32(MISC_BASE + 0x70)
#define SYS_AFE_DAC1_AMC    REG32(MISC_BASE + 0x74)
#define SYS_AFE_DAC1_DC     REG32(MISC_BASE + 0x78)

#define SYS_CLK_CFG         REG32(MISC_BASE + 0x80)
#define SYS_IO_CFG          REG32(MISC_BASE + 0x84)
#define SYS_DBG_CFG         REG32(MISC_BASE + 0x88)
#define SYS_CLK_DIV0        REG32(MISC_BASE + 0x90)  // SPI clock div
#define SYS_CLK_DIV1        REG32(MISC_BASE + 0x94)  // I2C clock div
#define SYS_CLK_DIV2        REG32(MISC_BASE + 0x98)  // UART0/1 clock div
#define SYS_CLK_FEN         REG32(MISC_BASE + 0x9C)  // perapheral clock enable
#define SYS_TRIM            REG32(MISC_BASE + 0xA0)
#define SYS_SFT_RST         REG32(MISC_BASE + 0xA4)
#define SYS_WR_PROTECT      REG32(MISC_BASE + 0xA8)
#define SYS_PROTECT         REG32(MISC_BASE + 0xA8)
#define SYS_PROT            REG32(MISC_BASE + 0xA8)
#define SYS_CACHE_CFG       REG32(MISC_BASE + 0xAC)
#define SYS_SRAM0_RR        REG32(MISC_BASE + 0xB0)
#define SYS_SRAM1_RR        REG32(MISC_BASE + 0xB4)
#define SYS_SRAM2_RR        REG32(MISC_BASE + 0xB8)
#define SYS_SRAM3_RR        REG32(MISC_BASE + 0xBC)
#define SYS_MEM_CFG         REG32(MISC_BASE + 0xC4)
#define SYS_FLSE            REG32(MISC_BASE + 0xD0)
#define SYS_FLSP            REG32(MISC_BASE + 0xD4)
#define SYS_TEST            REG32(MISC_BASE + 0xFC)

#define PSW_SYS_CLR_RST     0xCA40
#define PSW_SYS_CLK_SLP     0xDEAD
#define PSW_SYS_PWR_SLP     0xDAD0
#define PSW_SYS_SET_IAP     0x3720 // lsb must be ZERO
#define PSW_SYS_PROTECT     0x7a83
#define PSW_PROTECT         0x7a83
#define PSW_PROT            0x7a83

// SYS_CLK_FEN
#define MCLK_RCG_B_I2C0     0
#define MCLK_RCG_B_I2C1     1
#define MCLK_RCG_B_HALL0    2
#define MCLK_RCG_B_HALL1    3
#define MCLK_RCG_B_UART0    4
#define MCLK_RCG_B_UART1    5
#define MCLK_RCG_B_UART2    6
#define MCLK_RCG_B_CMP      8
#define MCLK_RCG_B_MCPWM0   9
#define MCLK_RCG_B_MCPWM1   10
#define MCLK_RCG_B_TIMER0   12
#define MCLK_RCG_B_TIMER1   13
#define MCLK_RCG_B_TIMER2   14
#define MCLK_RCG_B_TIMER3   15
#define MCLK_RCG_B_TIMER4   16
#define MCLK_RCG_B_QEP0     17
#define MCLK_RCG_B_QEP1     18
#define MCLK_RCG_B_QEP2     19
#define MCLK_RCG_B_QEP3     20

#define MCLK_RCG_B_GPIO     22
#define MCLK_RCG_B_CRC      23
#define MCLK_RCG_B_CORDIC   24
#define MCLK_RCG_B_FMAC     25
#define MCLK_RCG_B_ADC0     26
#define MCLK_RCG_B_ADC1     27
#define MCLK_RCG_B_ADC2     28
#define MCLK_RCG_B_CAN      30
#define MCLK_RCG_B_SPI0     31

#define DMA_CCR0            REG32(DMA_BASE + 0x00)
#define DMA_REN0            REG32(DMA_BASE + 0x04)
#define DMA_CTMS0           REG32(DMA_BASE + 0x08)
#define DMA_SADR0           REG32(DMA_BASE + 0x0C)
#define DMA_DADR0           REG32(DMA_BASE + 0x10)

#define DMA_CCR1            REG32(DMA_BASE + 0x18)
#define DMA_REN1            REG32(DMA_BASE + 0x1C)
#define DMA_CTMS1           REG32(DMA_BASE + 0x20)
#define DMA_SADR1           REG32(DMA_BASE + 0x24)
#define DMA_DADR1           REG32(DMA_BASE + 0x28)

#define DMA_CCR2            REG32(DMA_BASE + 0x30)
#define DMA_REN2            REG32(DMA_BASE + 0x34)
#define DMA_CTMS2           REG32(DMA_BASE + 0x38)
#define DMA_SADR2           REG32(DMA_BASE + 0x3C)
#define DMA_DADR2           REG32(DMA_BASE + 0x40)

#define DMA_CCR3            REG32(DMA_BASE + 0x48)
#define DMA_REN3            REG32(DMA_BASE + 0x4C)
#define DMA_CTMS3           REG32(DMA_BASE + 0x50)
#define DMA_SADR3           REG32(DMA_BASE + 0x54)
#define DMA_DADR3           REG32(DMA_BASE + 0x58)

#define DMA_CCR4            REG32(DMA_BASE + 0x60)
#define DMA_REN4            REG32(DMA_BASE + 0x64)
#define DMA_CTMS4           REG32(DMA_BASE + 0x68)
#define DMA_SADR4           REG32(DMA_BASE + 0x6C)
#define DMA_DADR4           REG32(DMA_BASE + 0x70)

#define DMA_CCR5            REG32(DMA_BASE + 0x78)
#define DMA_REN5            REG32(DMA_BASE + 0x7C)
#define DMA_CTMS5           REG32(DMA_BASE + 0x80)
#define DMA_SADR5           REG32(DMA_BASE + 0x84)
#define DMA_DADR5           REG32(DMA_BASE + 0x88)

#define DMA_CCR6            REG32(DMA_BASE + 0x90)
#define DMA_REN6            REG32(DMA_BASE + 0x94)
#define DMA_CTMS6           REG32(DMA_BASE + 0x98)
#define DMA_SADR6           REG32(DMA_BASE + 0x9C)
#define DMA_DADR6           REG32(DMA_BASE + 0xA0)

#define DMA_CCR7            REG32(DMA_BASE + 0xA8)
#define DMA_REN7            REG32(DMA_BASE + 0xAC)
#define DMA_CTMS7           REG32(DMA_BASE + 0xB0)
#define DMA_SADR7           REG32(DMA_BASE + 0xB4)
#define DMA_DADR7           REG32(DMA_BASE + 0xB8)

#define DMA_CTRL            REG32(DMA_BASE + 0xC0)
#define DMA_IE              REG32(DMA_BASE + 0xC4)
#define DMA_IF              REG32(DMA_BASE + 0xC8)

#define WWDG_CR             REG32(WWDT_BASE + 0x00)
#define WWDG_CFG            REG32(WWDT_BASE + 0x04)
#define WWDG_IF             REG32(WWDT_BASE + 0x08)

#define AON_BRAM_BASE       AON_BASE
#define AON_PWR_CFG         REG32(AON_BASE + 0x80)
#define AON_EVT_RCD         REG32(AON_BASE + 0x84)
#define AON_IO_WAKE_POL     REG32(AON_BASE + 0x88)
#define AON_IO_WAKE_EN      REG32(AON_BASE + 0x8C)
#define PSW_EVT_CLR         0xCA40

#define IWDG_PSW            REG32(AON_BASE + 0xC0)
#define IWDG_CFG            REG32(AON_BASE + 0xC4)
#define IWDG_CLR            REG32(AON_BASE + 0xC8)
#define IWDG_WTH            REG32(AON_BASE + 0xCC)
#define IWDG_RTH            REG32(AON_BASE + 0xD0)
#define IWDG_CNT            REG32(AON_BASE + 0xD4)
#define PSW_IWDG_PRE        0xA6B4
#define PSW_IWDG_CLR        0x798D

#endif // _LKS32MC45x_H_

#include <core_cm4.h>
