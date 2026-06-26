/**
 * @file LKS32MC45x_User_Manual_v1.77
 * @brief 从手册创建的头文件
 * @details 基于文件 LKS32MC45x_User_Manual_v1.77.pdf
 * @note 本文件由自动化系统创建，请勿手动修改
 * @date 2026-01-04 03:00:19
 * @version 1.77
 */
#ifndef __LKS32MC45X_USER_MANUAL_V1_77__
#define __LKS32MC45X_USER_MANUAL_V1_77__
#include "stdint.h"

/* SYS_AFE_INFO 芯片版本信息寄存器 */
#define SYS_AFE_INFO_Version_MAX  ((uint32_t)0xF)                                       // SYS_AFE_INFO_Version最大值
#define SYS_AFE_INFO_Version_POS  0                                                     // SYS_AFE_INFO_Version起始位
#define SYS_AFE_INFO_Version_MASK (uint32_t)((uint32_t)0xF << SYS_AFE_INFO_Version_POS) // SYS_AFE_INFO_Version位掩码
#define SYS_AFE_INFO_Version(x)   (uint32_t)(((x) & 0xF) << SYS_AFE_INFO_Version_POS)   // [3:0] 芯片版本信息

/* SYS_AFE_DBG0 调试寄存器 */
#define SYS_AFE_DBG0_PWR_WEAK_BIT BIT13 // [13] 供电低于掉电监测阈值时为高

/* SYS_AFE_REG0 模拟配置寄存器0 */
#define SYS_AFE_REG0_RES_OPA3_MAX  ((uint32_t)0x7)                                        // SYS_AFE_REG0_RES_OPA3最大值
#define SYS_AFE_REG0_RES_OPA3_POS  12                                                     // SYS_AFE_REG0_RES_OPA3起始位
#define SYS_AFE_REG0_RES_OPA3_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG0_RES_OPA3_POS) // SYS_AFE_REG0_RES_OPA3位掩码
#define SYS_AFE_REG0_RES_OPA3(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG0_RES_OPA3_POS)   // [14:12] 运放3反馈电阻 000: 20k:10k 001: 40k:10k 010: 80k:10k 011:160k:10k 100: 320k:10k 101: 320k:5k
#define SYS_AFE_REG0_RES_OPA2_MAX  ((uint32_t)0x7)                                        // SYS_AFE_REG0_RES_OPA2最大值
#define SYS_AFE_REG0_RES_OPA2_POS  8                                                      // SYS_AFE_REG0_RES_OPA2起始位
#define SYS_AFE_REG0_RES_OPA2_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG0_RES_OPA2_POS) // SYS_AFE_REG0_RES_OPA2位掩码
#define SYS_AFE_REG0_RES_OPA2(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG0_RES_OPA2_POS)   // [10:8] 运放2反馈电阻 000: 20k:10k 001: 40k:10k 010: 80k:10k 011:160k:10k 100: 320k:10k 101: 320k:5k
#define SYS_AFE_REG0_RES_OPA1_MAX  ((uint32_t)0x7)                                        // SYS_AFE_REG0_RES_OPA1最大值
#define SYS_AFE_REG0_RES_OPA1_POS  4                                                      // SYS_AFE_REG0_RES_OPA1起始位
#define SYS_AFE_REG0_RES_OPA1_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG0_RES_OPA1_POS) // SYS_AFE_REG0_RES_OPA1位掩码
#define SYS_AFE_REG0_RES_OPA1(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG0_RES_OPA1_POS)   // [6:4] 运放1反馈电阻 000: 20k:10k 001: 40k:10k 010: 80k:10k 011:160k:10k 100: 320k:10k 101: 320k:5k
#define SYS_AFE_REG0_RES_OPA0_MAX  ((uint32_t)0x7)                                        // SYS_AFE_REG0_RES_OPA0最大值
#define SYS_AFE_REG0_RES_OPA0_POS  0                                                      // SYS_AFE_REG0_RES_OPA0起始位
#define SYS_AFE_REG0_RES_OPA0_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG0_RES_OPA0_POS) // SYS_AFE_REG0_RES_OPA0位掩码
#define SYS_AFE_REG0_RES_OPA0(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG0_RES_OPA0_POS)   // [2:0] 运放0反馈电阻 000: 20k:10k 001: 40k:10k 010: 80k:10k 011:160k:10k 100: 320k:10k 101: 320k:5k

/* SYS_AFE_REG1 模拟配置寄存器1 */
#define SYS_AFE_REG1_XDIV_BIT      BIT10                                                  // [10] 晶体频率除以2 0:使用12MHz外部晶体 1:使用24MHz外部晶体，同时需要将SYS_AFE_REG4.XTRSEL[0]置为1
#define SYS_AFE_REG1_XCSEL_MAX     ((uint32_t)0x3)                                        // SYS_AFE_REG1_XCSEL最大值
#define SYS_AFE_REG1_XCSEL_POS     8                                                      // SYS_AFE_REG1_XCSEL起始位
#define SYS_AFE_REG1_XCSEL_MASK    (uint32_t)((uint32_t)0x3 << SYS_AFE_REG1_XCSEL_POS)    // SYS_AFE_REG1_XCSEL位掩码
#define SYS_AFE_REG1_XCSEL(x)      (uint32_t)(((x) & 0x3) << SYS_AFE_REG1_XCSEL_POS)      // [9:8] 晶体电容调整 00: 9.19pF 01: 10.77pF 10: 6.02pF 11:7.61pF
#define SYS_AFE_REG1_RES_OPA5_MAX  ((uint32_t)0x7)                                        // SYS_AFE_REG1_RES_OPA5最大值
#define SYS_AFE_REG1_RES_OPA5_POS  4                                                      // SYS_AFE_REG1_RES_OPA5起始位
#define SYS_AFE_REG1_RES_OPA5_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG1_RES_OPA5_POS) // SYS_AFE_REG1_RES_OPA5位掩码
#define SYS_AFE_REG1_RES_OPA5(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG1_RES_OPA5_POS)   // [6:4] 运放5反馈电阻 000: 20k:10k 001: 40k:10k 010: 80k:10k 011:160k:10k 100: 320k:10k 101: 320k:5k
#define SYS_AFE_REG1_RES_OPA4_MAX  ((uint32_t)0x7)                                        // SYS_AFE_REG1_RES_OPA4最大值
#define SYS_AFE_REG1_RES_OPA4_POS  0                                                      // SYS_AFE_REG1_RES_OPA4起始位
#define SYS_AFE_REG1_RES_OPA4_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG1_RES_OPA4_POS) // SYS_AFE_REG1_RES_OPA4位掩码
#define SYS_AFE_REG1_RES_OPA4(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG1_RES_OPA4_POS)   // [2:0] 运放4反馈电阻 000: 20k:10k 001: 40k:10k 010: 80k:10k 011:160k:10k 100: 320k:10k 101: 320k:5k

/* SYS_AFE_REG2 模拟配置寄存器2 */
#define SYS_AFE_REG2_LDOOUT_EN_BIT   BIT15                                                    // [15] LDO输出到IO使能 1:使能 0:关闭
#define SYS_AFE_REG2_REF2VDD_BIT     BIT12                                                    // [12] 使用外部输入电源作为ADC REF 1: 使用外部输入电源作为ADC REF; 0: 使用默认内部REF作为ADC基准
#define SYS_AFE_REG2_IT_CMP_BIT      BIT9                                                     // [9] 比较器0~5比较速度选择 0:比较速度150ns 1:比较速度600ns
#define SYS_AFE_REG2_CMP_FT_BIT      BIT8                                                     // [8] 使能比较器快速比较 1:在IT_CMP为默认0的时候，使能比较器比较速度小于30ns 0:不使能
#define SYS_AFE_REG2_OPAOUT1_EN_MAX  ((uint32_t)0x3)                                          // SYS_AFE_REG2_OPAOUT1_EN最大值
#define SYS_AFE_REG2_OPAOUT1_EN_POS  4                                                        // SYS_AFE_REG2_OPAOUT1_EN起始位
#define SYS_AFE_REG2_OPAOUT1_EN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG2_OPAOUT1_EN_POS) // SYS_AFE_REG2_OPAOUT1_EN位掩码
#define SYS_AFE_REG2_OPAOUT1_EN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG2_OPAOUT1_EN_POS)   // [5:4] 使能OPAx(x=3,4,5)输出信号送至IO口 00:不输出 01:输出OPA3信号到IO口P4.6 10:输出OPA4信号到IO口P4.6 11:输出OPA5信号到IO口P4.6
#define SYS_AFE_REG2_OPAOUT0_EN_MAX  ((uint32_t)0x3)                                          // SYS_AFE_REG2_OPAOUT0_EN最大值
#define SYS_AFE_REG2_OPAOUT0_EN_POS  0                                                        // SYS_AFE_REG2_OPAOUT0_EN起始位
#define SYS_AFE_REG2_OPAOUT0_EN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG2_OPAOUT0_EN_POS) // SYS_AFE_REG2_OPAOUT0_EN位掩码
#define SYS_AFE_REG2_OPAOUT0_EN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG2_OPAOUT0_EN_POS)   // [1:0] 使能OPAx(x=0,1,2)输出信号送至IO口 00:不输出 01:输出OPA0信号到IO口P3.11 10:输出OPA1信号到IO口P3.11 11:输出OPA2信号到IO口P3.11

/* SYS_AFE_REG3 模拟配置寄存器3 */
#define SYS_AFE_REG3_ADCCLKSEL_MAX  ((uint32_t)0x3)                                         // SYS_AFE_REG3_ADCCLKSEL最大值
#define SYS_AFE_REG3_ADCCLKSEL_POS  10                                                      // SYS_AFE_REG3_ADCCLKSEL起始位
#define SYS_AFE_REG3_ADCCLKSEL_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG3_ADCCLKSEL_POS) // SYS_AFE_REG3_ADCCLKSEL位掩码
#define SYS_AFE_REG3_ADCCLKSEL(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG3_ADCCLKSEL_POS)   // [11:10] ADC时钟频率选择 01:不允许此配置 00: 32MHz 11: 16MHz 10: 8MHz

/* SYS_AFE_REG4 模拟配置寄存器4 */
#define SYS_AFE_REG4_CMP0_SELN_MAX  ((uint32_t)0x3)                                         // SYS_AFE_REG4_CMP0_SELN最大值
#define SYS_AFE_REG4_CMP0_SELN_POS  14                                                      // SYS_AFE_REG4_CMP0_SELN起始位
#define SYS_AFE_REG4_CMP0_SELN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG4_CMP0_SELN_POS) // SYS_AFE_REG4_CMP0_SELN位掩码
#define SYS_AFE_REG4_CMP0_SELN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG4_CMP0_SELN_POS)   // [15:14] 比较器0信号负端选择 00: CMP0_IN 01: REF 10: DAC0输出 11: CMP0_IP1/2/3的平均值
#define SYS_AFE_REG4_CMP1_SELN_MAX  ((uint32_t)0x3)                                         // SYS_AFE_REG4_CMP1_SELN最大值
#define SYS_AFE_REG4_CMP1_SELN_POS  12                                                      // SYS_AFE_REG4_CMP1_SELN起始位
#define SYS_AFE_REG4_CMP1_SELN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG4_CMP1_SELN_POS) // SYS_AFE_REG4_CMP1_SELN位掩码
#define SYS_AFE_REG4_CMP1_SELN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG4_CMP1_SELN_POS)   // [13:12] 比较器1信号负端选择 00: CMP1_IN 01: REF 10: DAC1输出 11: CMP1_IP1/2/3的平均值
#define SYS_AFE_REG4_XTRSEL_MAX     ((uint32_t)0x3)                                         // SYS_AFE_REG4_XTRSEL最大值
#define SYS_AFE_REG4_XTRSEL_POS     6                                                       // SYS_AFE_REG4_XTRSEL起始位
#define SYS_AFE_REG4_XTRSEL_MASK    (uint32_t)((uint32_t)0x3 << SYS_AFE_REG4_XTRSEL_POS)    // SYS_AFE_REG4_XTRSEL位掩码
#define SYS_AFE_REG4_XTRSEL(x)      (uint32_t)(((x) & 0x3) << SYS_AFE_REG4_XTRSEL_POS)      // [7:6] 晶体起振电路电阻调节 XTRSEL\<1\>=1: N端阻值增加 XTRSEL\<0\>=1: P端电阻减小一倍
#define SYS_AFE_REG4_DAC1_OUTEN_BIT BIT5                                                    // [5] DAC1输出到IO使能 1: 使能DAC1输出到IO P4.7 0: 不输出
#define SYS_AFE_REG4_DAC0_OUTEN_BIT BIT4                                                    // [4] DAC0输出到IO使能 1: 使能DAC0输出到IO P3.4 0: 不输出
#define SYS_AFE_REG4_CMP_HYS_BIT    BIT3                                                    // [3] 比较器回差选择 0: 20mv 1: 0mv
#define SYS_AFE_REG4_DAC1_GAIN_BIT  BIT2                                                    // [2] DAC1量程选择 0: 满量程为3V 1: 满量程为1.2V
#define SYS_AFE_REG4_DAC0_GAIN_BIT  BIT0                                                    // [0] DAC0量程选择 0: 满量程为3V 1: 满量程为1.2V

/* SYS_AFE_REG5 模拟配置寄存器5 */
#define SYS_AFE_REG5_CMP0_SELP_MAX  ((uint32_t)0x7)                                         // SYS_AFE_REG5_CMP0_SELP最大值
#define SYS_AFE_REG5_CMP0_SELP_POS  12                                                      // SYS_AFE_REG5_CMP0_SELP起始位
#define SYS_AFE_REG5_CMP0_SELP_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG5_CMP0_SELP_POS) // SYS_AFE_REG5_CMP0_SELP位掩码
#define SYS_AFE_REG5_CMP0_SELP(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG5_CMP0_SELP_POS)   // [14:12] 比较器0信号正端选择 000: CMP0_IP0 001: OPA0_IP 010: OPA0_OUT_HF，即运放的正输出端VOP，详见运放应用笔记 011: OPA1_OUT_HF 100: CMP0_IP1 101: CMP0_IP2 110: CMP0_IP3 111: AVSS
#define SYS_AFE_REG5_CMP1_SELP_MAX  ((uint32_t)0x7)                                         // SYS_AFE_REG5_CMP1_SELP最大值
#define SYS_AFE_REG5_CMP1_SELP_POS  8                                                       // SYS_AFE_REG5_CMP1_SELP起始位
#define SYS_AFE_REG5_CMP1_SELP_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG5_CMP1_SELP_POS) // SYS_AFE_REG5_CMP1_SELP位掩码
#define SYS_AFE_REG5_CMP1_SELP(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG5_CMP1_SELP_POS)   // [10:8] 比较器1信号正端选择 000: CMP1_IP0 001: OPA1_IP 010: OPA1_OUT_HF 011: OPA2_OUT_HF 100: CMP1_IP1 101: CMP1_IP2 110: CMP1_IP3 111: AVSS
#define SYS_AFE_REG5_CMP4_SELN_MAX  ((uint32_t)0x3)                                         // SYS_AFE_REG5_CMP4_SELN最大值
#define SYS_AFE_REG5_CMP4_SELN_POS  6                                                       // SYS_AFE_REG5_CMP4_SELN起始位
#define SYS_AFE_REG5_CMP4_SELN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG5_CMP4_SELN_POS) // SYS_AFE_REG5_CMP4_SELN位掩码
#define SYS_AFE_REG5_CMP4_SELN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG5_CMP4_SELN_POS)   // [7:6] 比较器4信号负端选择 00: CMP4_IN 01: REF 10: DAC0输出 11: DAC1输出
#define SYS_AFE_REG5_CMP5_SELN_MAX  ((uint32_t)0x3)                                         // SYS_AFE_REG5_CMP5_SELN最大值
#define SYS_AFE_REG5_CMP5_SELN_POS  4                                                       // SYS_AFE_REG5_CMP5_SELN起始位
#define SYS_AFE_REG5_CMP5_SELN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG5_CMP5_SELN_POS) // SYS_AFE_REG5_CMP5_SELN位掩码
#define SYS_AFE_REG5_CMP5_SELN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG5_CMP5_SELN_POS)   // [5:4] 比较器5信号负端选择 00: CMP5_IN 01: REF 10: DAC0输出 11: DAC1输出
#define SYS_AFE_REG5_CMP2_SELN_MAX  ((uint32_t)0x3)                                         // SYS_AFE_REG5_CMP2_SELN最大值
#define SYS_AFE_REG5_CMP2_SELN_POS  2                                                       // SYS_AFE_REG5_CMP2_SELN起始位
#define SYS_AFE_REG5_CMP2_SELN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG5_CMP2_SELN_POS) // SYS_AFE_REG5_CMP2_SELN位掩码
#define SYS_AFE_REG5_CMP2_SELN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG5_CMP2_SELN_POS)   // [3:2] 比较器2信号负端选择 00: CMP2_IN 01: REF 10: DAC0输出 11: DAC1输出
#define SYS_AFE_REG5_CMP3_SELN_MAX  ((uint32_t)0x3)                                         // SYS_AFE_REG5_CMP3_SELN最大值
#define SYS_AFE_REG5_CMP3_SELN_POS  0                                                       // SYS_AFE_REG5_CMP3_SELN起始位
#define SYS_AFE_REG5_CMP3_SELN_MASK (uint32_t)((uint32_t)0x3 << SYS_AFE_REG5_CMP3_SELN_POS) // SYS_AFE_REG5_CMP3_SELN位掩码
#define SYS_AFE_REG5_CMP3_SELN(x)   (uint32_t)(((x) & 0x3) << SYS_AFE_REG5_CMP3_SELN_POS)   // [1:0] 比较器3信号负端选择 00: CMP3_IN 01: REF 10: DAC0输出 11: DAC1输出

/* SYS_AFE_REG6 模拟配置寄存器6 */
#define SYS_AFE_REG6_CMP4_SELP_MAX  ((uint32_t)0x7)                                         // SYS_AFE_REG6_CMP4_SELP最大值
#define SYS_AFE_REG6_CMP4_SELP_POS  12                                                      // SYS_AFE_REG6_CMP4_SELP起始位
#define SYS_AFE_REG6_CMP4_SELP_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG6_CMP4_SELP_POS) // SYS_AFE_REG6_CMP4_SELP位掩码
#define SYS_AFE_REG6_CMP4_SELP(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG6_CMP4_SELP_POS)   // [14:12] 比较器4信号正端选择 000: CMP4_IP0 001: OPA4_IP 010: OPA4_OUT_HF 011: OPA5_OUT_HF 100: CMP4_IP1 101: CMP4_IP2 110: CMP4_IP3 111: AVSS
#define SYS_AFE_REG6_CMP5_SELP_MAX  ((uint32_t)0x7)                                         // SYS_AFE_REG6_CMP5_SELP最大值
#define SYS_AFE_REG6_CMP5_SELP_POS  8                                                       // SYS_AFE_REG6_CMP5_SELP起始位
#define SYS_AFE_REG6_CMP5_SELP_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG6_CMP5_SELP_POS) // SYS_AFE_REG6_CMP5_SELP位掩码
#define SYS_AFE_REG6_CMP5_SELP(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG6_CMP5_SELP_POS)   // [10:8] 比较器5信号正端选择 000: CMP5_IP0 001: OPA5_IP 010: OPA5_OUT_HF 011: OPA0_OUT_HF 100: CMP5_IP1 101: CMP5_IP2 110: CMP5_IP3 111: AVSS
#define SYS_AFE_REG6_CMP2_SELP_MAX  ((uint32_t)0x7)                                         // SYS_AFE_REG6_CMP2_SELP最大值
#define SYS_AFE_REG6_CMP2_SELP_POS  4                                                       // SYS_AFE_REG6_CMP2_SELP起始位
#define SYS_AFE_REG6_CMP2_SELP_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG6_CMP2_SELP_POS) // SYS_AFE_REG6_CMP2_SELP位掩码
#define SYS_AFE_REG6_CMP2_SELP(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG6_CMP2_SELP_POS)   // [6:4] 比较器2信号正端选择 000: CMP2_IP0 001: OPA2_IP 010: OPA2_OUT_HF 011: OPA3_OUT_HF 100: CMP2_IP1 101: CMP2_IP2 110: CMP2_IP3 111: AVSS
#define SYS_AFE_REG6_CMP3_SELP_MAX  ((uint32_t)0x7)                                         // SYS_AFE_REG6_CMP3_SELP最大值
#define SYS_AFE_REG6_CMP3_SELP_POS  0                                                       // SYS_AFE_REG6_CMP3_SELP起始位
#define SYS_AFE_REG6_CMP3_SELP_MASK (uint32_t)((uint32_t)0x7 << SYS_AFE_REG6_CMP3_SELP_POS) // SYS_AFE_REG6_CMP3_SELP位掩码
#define SYS_AFE_REG6_CMP3_SELP(x)   (uint32_t)(((x) & 0x7) << SYS_AFE_REG6_CMP3_SELP_POS)   // [2:0] 比较器3信号正端选择 000: CMP3_IP0 001: OPA3_IP 010: OPA3_OUT_HF 011: OPA4_OUT_HF 100: CMP3_IP1 101: CMP3_IP2 110: CMP3_IP3 111: AVSS

/* SYS_AFE_REG9 模拟配置寄存器9 */
#define SYS_AFE_REG9_ADCPDN_BIT  BIT15 // [15] ADC使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_CMP5PDN_BIT BIT13 // [13] CMP5使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_CMP4PDN_BIT BIT12 // [12] CMP4使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_CMP3PDN_BIT BIT11 // [11] CMP3使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_CMP2PDN_BIT BIT10 // [10] CMP2使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_CMP1PDN_BIT BIT9  // [9] CMP1使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_CMP0PDN_BIT BIT8  // [8] CMP0使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_OPA5PDN_BIT BIT5  // [5] OPA5 使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_OPA4PDN_BIT BIT4  // [4] OPA4 使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_OPA3PDN_BIT BIT3  // [3] OPA3 使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_OPA2PDN_BIT BIT2  // [2] OPA2 使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_OPA1PDN_BIT BIT1  // [1] OPA1 使能 0: 关闭 1: 使能
#define SYS_AFE_REG9_OPA0PDN_BIT BIT0  // [0] OPA0 使能 0: 关闭 1: 使能

/* SYS_AFE_REGA 模拟配置寄存器A */
#define SYS_AFE_REGA_PLLPDN_BIT   BIT7 // [7] PLL使能 0: 关闭 1: 使能
#define SYS_AFE_REGA_XTALPDN_BIT  BIT6 // [6] 晶体起振电路使能 0: 关闭 1: 使能
#define SYS_AFE_REGA_TMPPDN_BIT   BIT5 // [5] 温度传感器使能 0: 关闭 1: 使能
#define SYS_AFE_REGA_LDO2_CTL_BIT BIT4 // [4] 可掉电LDO电源关闭控制信号 0: 开启 1: 关闭
#define SYS_AFE_REGA_DAC1PDN_BIT  BIT3 // [3] DAC1使能 0: 关闭 1: 使能
#define SYS_AFE_REGA_DAC0PDN_BIT  BIT2 // [2] DAC0使能 0: 关闭 1: 使能
#define SYS_AFE_REGA_RCHPD_BIT    BIT1 // [1] RCH模块关闭信号 0: 开启 1: 关闭
#define SYS_AFE_REGA_BGPPD_BIT    BIT0 // [0] BGP模块关闭信号 0: 开启 1: 关闭

/* SYS_AFE_REGB 模拟配置寄存器B */
#define SYS_AFE_REGB_PLLSR_SEL_BIT BIT7                                                 // [7] PLL参考时钟选择 0: PLL使用RCH时钟 1: PLL使用晶体时钟 该信号在不使用晶体时钟的产品或应用下，时钟输出0;在使用晶体时钟且晶体未停振时输出1，如晶体停振则输出0
#define SYS_AFE_REGB_PORFIL_EN_BIT BIT6                                                 // [6] POR滤波使能 0: 关闭 1: 使能
#define SYS_AFE_REGB_PVDSEL_MAX    ((uint32_t)0x3)                                      // SYS_AFE_REGB_PVDSEL最大值
#define SYS_AFE_REGB_PVDSEL_POS    2                                                    // SYS_AFE_REGB_PVDSEL起始位
#define SYS_AFE_REGB_PVDSEL_MASK   (uint32_t)((uint32_t)0x3 << SYS_AFE_REGB_PVDSEL_POS) // SYS_AFE_REGB_PVDSEL位掩码
#define SYS_AFE_REGB_PVDSEL(x)     (uint32_t)(((x) & 0x3) << SYS_AFE_REGB_PVDSEL_POS)   // [3:2] 电源掉电监测阈值选择 00: 3.55V 01: 3.30V 10: 3.10V 11: 2.90V
#define SYS_AFE_REGB_VSR_PDT_BIT   BIT1                                                 // [1] 掉电检测基准源选择 0:选择低功耗基准源 1:选择DAC0的输出
#define SYS_AFE_REGB_PDT_PD_BIT    BIT0                                                 // [0] 掉电检测电路关闭控制信号 0: 开启 1: 关闭

/* SYS_TMP_A 温度传感器系数A寄存器 */
#define SYS_TMP_A_TMP_GAIN_A_MAX  ((uint32_t)0xFFFF)                                       // SYS_TMP_A_TMP_GAIN_A最大值
#define SYS_TMP_A_TMP_GAIN_A_POS  0                                                        // SYS_TMP_A_TMP_GAIN_A起始位
#define SYS_TMP_A_TMP_GAIN_A_MASK (uint32_t)((uint32_t)0xFFFF << SYS_TMP_A_TMP_GAIN_A_POS) // SYS_TMP_A_TMP_GAIN_A位掩码
#define SYS_TMP_A_TMP_GAIN_A(x)   (uint32_t)(((x) & 0xFFFF) << SYS_TMP_A_TMP_GAIN_A_POS)   // [15:0] 温度传感器增益校正系数A

/* SYS_TMP_B 温度传感器系数B寄存器 */
#define SYS_TMP_B_TMP_SIGN_MAX      ((uint32_t)0xF)                                           // SYS_TMP_B_TMP_SIGN最大值
#define SYS_TMP_B_TMP_SIGN_POS      12                                                        // SYS_TMP_B_TMP_SIGN起始位
#define SYS_TMP_B_TMP_SIGN_MASK     (uint32_t)((uint32_t)0xF << SYS_TMP_B_TMP_SIGN_POS)       // SYS_TMP_B_TMP_SIGN位掩码
#define SYS_TMP_B_TMP_SIGN(x)       (uint32_t)(((x) & 0xF) << SYS_TMP_B_TMP_SIGN_POS)         // [15:12] 温度传感器offset校正系数B符号扩展位
#define SYS_TMP_B_TMP_OFFSET_B_MAX  ((uint32_t)0xFFF)                                         // SYS_TMP_B_TMP_OFFSET_B最大值
#define SYS_TMP_B_TMP_OFFSET_B_POS  0                                                         // SYS_TMP_B_TMP_OFFSET_B起始位
#define SYS_TMP_B_TMP_OFFSET_B_MASK (uint32_t)((uint32_t)0xFFF << SYS_TMP_B_TMP_OFFSET_B_POS) // SYS_TMP_B_TMP_OFFSET_B位掩码
#define SYS_TMP_B_TMP_OFFSET_B(x)   (uint32_t)(((x) & 0xFFF) << SYS_TMP_B_TMP_OFFSET_B_POS)   // [11:0] 温度传感器offset校正系数B

/* SYS_AFE_DAC0 DAC0数字量寄存器 */
#define SYS_AFE_DAC0_DAC_IN_MAX  ((uint32_t)0xFFF)                                      // SYS_AFE_DAC0_DAC_IN最大值
#define SYS_AFE_DAC0_DAC_IN_POS  0                                                      // SYS_AFE_DAC0_DAC_IN起始位
#define SYS_AFE_DAC0_DAC_IN_MASK (uint32_t)((uint32_t)0xFFF << SYS_AFE_DAC0_DAC_IN_POS) // SYS_AFE_DAC0_DAC_IN位掩码
#define SYS_AFE_DAC0_DAC_IN(x)   (uint32_t)(((x) & 0xFFF) << SYS_AFE_DAC0_DAC_IN_POS)   // [11:0] DAC0待转换的数字量输入

/* SYS_AFE_DAC0_AMC DAC0增益校正寄存器 */
#define SYS_AFE_DAC0_AMC_DAC_AMC_MAX  ((uint32_t)0x3FF)                                           // SYS_AFE_DAC0_AMC_DAC_AMC最大值
#define SYS_AFE_DAC0_AMC_DAC_AMC_POS  0                                                           // SYS_AFE_DAC0_AMC_DAC_AMC起始位
#define SYS_AFE_DAC0_AMC_DAC_AMC_MASK (uint32_t)((uint32_t)0x3FF << SYS_AFE_DAC0_AMC_DAC_AMC_POS) // SYS_AFE_DAC0_AMC_DAC_AMC位掩码
#define SYS_AFE_DAC0_AMC_DAC_AMC(x)   (uint32_t)(((x) & 0x3FF) << SYS_AFE_DAC0_AMC_DAC_AMC_POS)   // [9:0] DAC增益校正值，10bit无符号定点数，B[9]为整数部分，B[8:0]为小数部分

/* SYS_AFE_DAC0_DC DAC0直流偏置寄存器 */
#define SYS_AFE_DAC0_DC_SIGN_EXT_MAX  ((uint32_t)0x3F)                                           // SYS_AFE_DAC0_DC_SIGN_EXT最大值
#define SYS_AFE_DAC0_DC_SIGN_EXT_POS  10                                                         // SYS_AFE_DAC0_DC_SIGN_EXT起始位
#define SYS_AFE_DAC0_DC_SIGN_EXT_MASK (uint32_t)((uint32_t)0x3F << SYS_AFE_DAC0_DC_SIGN_EXT_POS) // SYS_AFE_DAC0_DC_SIGN_EXT位掩码
#define SYS_AFE_DAC0_DC_SIGN_EXT(x)   (uint32_t)(((x) & 0x3F) << SYS_AFE_DAC0_DC_SIGN_EXT_POS)   // [15:10] 符号位扩展，B[15:10]={6{B[9]}}，即B[15:10]都等于B[9]
#define SYS_AFE_DAC0_DC_DAC_DC_MAX    ((uint32_t)0x3FF)                                          // SYS_AFE_DAC0_DC_DAC_DC最大值
#define SYS_AFE_DAC0_DC_DAC_DC_POS    0                                                          // SYS_AFE_DAC0_DC_DAC_DC起始位
#define SYS_AFE_DAC0_DC_DAC_DC_MASK   (uint32_t)((uint32_t)0x3FF << SYS_AFE_DAC0_DC_DAC_DC_POS)  // SYS_AFE_DAC0_DC_DAC_DC位掩码
#define SYS_AFE_DAC0_DC_DAC_DC(x)     (uint32_t)(((x) & 0x3FF) << SYS_AFE_DAC0_DC_DAC_DC_POS)    // [9:0] DAC直流偏置，10bit有符号数，B[9]为符号位

/* SYS_AFE_DAC1 DAC1数字量寄存器 */
#define SYS_AFE_DAC1_DAC_IN_MAX  ((uint32_t)0xFFF)                                      // SYS_AFE_DAC1_DAC_IN最大值
#define SYS_AFE_DAC1_DAC_IN_POS  0                                                      // SYS_AFE_DAC1_DAC_IN起始位
#define SYS_AFE_DAC1_DAC_IN_MASK (uint32_t)((uint32_t)0xFFF << SYS_AFE_DAC1_DAC_IN_POS) // SYS_AFE_DAC1_DAC_IN位掩码
#define SYS_AFE_DAC1_DAC_IN(x)   (uint32_t)(((x) & 0xFFF) << SYS_AFE_DAC1_DAC_IN_POS)   // [11:0] DAC1待转换的数字量输入

/* SYS_AFE_DAC1_AMC DAC1增益校正寄存器 */
#define SYS_AFE_DAC1_AMC_DAC_AMC_MAX  ((uint32_t)0x3FF)                                           // SYS_AFE_DAC1_AMC_DAC_AMC最大值
#define SYS_AFE_DAC1_AMC_DAC_AMC_POS  0                                                           // SYS_AFE_DAC1_AMC_DAC_AMC起始位
#define SYS_AFE_DAC1_AMC_DAC_AMC_MASK (uint32_t)((uint32_t)0x3FF << SYS_AFE_DAC1_AMC_DAC_AMC_POS) // SYS_AFE_DAC1_AMC_DAC_AMC位掩码
#define SYS_AFE_DAC1_AMC_DAC_AMC(x)   (uint32_t)(((x) & 0x3FF) << SYS_AFE_DAC1_AMC_DAC_AMC_POS)   // [9:0] DAC增益校正值，10bit无符号定点数，B[9]为整数部分，B[8:0]为小数部分

/* SYS_AFE_DAC1_DC DAC1直流偏置寄存器 */
#define SYS_AFE_DAC1_DC_SIGN_EXT_MAX  ((uint32_t)0x3F)                                           // SYS_AFE_DAC1_DC_SIGN_EXT最大值
#define SYS_AFE_DAC1_DC_SIGN_EXT_POS  10                                                         // SYS_AFE_DAC1_DC_SIGN_EXT起始位
#define SYS_AFE_DAC1_DC_SIGN_EXT_MASK (uint32_t)((uint32_t)0x3F << SYS_AFE_DAC1_DC_SIGN_EXT_POS) // SYS_AFE_DAC1_DC_SIGN_EXT位掩码
#define SYS_AFE_DAC1_DC_SIGN_EXT(x)   (uint32_t)(((x) & 0x3F) << SYS_AFE_DAC1_DC_SIGN_EXT_POS)   // [15:10] 符号位扩展，B[15:10]={6{B[9]}}，即B[15:10]都等于B[9]
#define SYS_AFE_DAC1_DC_DAC_DC_MAX    ((uint32_t)0x3FF)                                          // SYS_AFE_DAC1_DC_DAC_DC最大值
#define SYS_AFE_DAC1_DC_DAC_DC_POS    0                                                          // SYS_AFE_DAC1_DC_DAC_DC起始位
#define SYS_AFE_DAC1_DC_DAC_DC_MASK   (uint32_t)((uint32_t)0x3FF << SYS_AFE_DAC1_DC_DAC_DC_POS)  // SYS_AFE_DAC1_DC_DAC_DC位掩码
#define SYS_AFE_DAC1_DC_DAC_DC(x)     (uint32_t)(((x) & 0x3FF) << SYS_AFE_DAC1_DC_DAC_DC_POS)    // [9:0] DAC直流偏置，10bit有符号数，B[9]为符号位

/* SYS_CLK_CFG 时钟控制寄存器 */
#define SYS_CLK_CFG_HSE_FAILED_BIT BIT13                                                 // [13] 晶振时钟在被开启后是否停振过 如果晶振有停振情况，则该位置位，即使晶体后续恢复振荡，仍保持记录为1。写1清零
#define SYS_CLK_CFG_HSE_FAIL_BIT   BIT12                                                 // [12] 晶振时钟当前是否已经停振 0：外部晶体当前正常工作 1：外部晶体当前已经停振
#define SYS_CLK_CFG_CLK_SEL_MAX    ((uint32_t)0x3)                                       // SYS_CLK_CFG_CLK_SEL最大值
#define SYS_CLK_CFG_CLK_SEL_POS    8                                                     // SYS_CLK_CFG_CLK_SEL起始位
#define SYS_CLK_CFG_CLK_SEL_MASK   (uint32_t)((uint32_t)0x3 << SYS_CLK_CFG_CLK_SEL_POS)  // SYS_CLK_CFG_CLK_SEL位掩码
#define SYS_CLK_CFG_CLK_SEL(x)     (uint32_t)(((x) & 0x3) << SYS_CLK_CFG_CLK_SEL_POS)    // [9:8] 系统时钟MCLK的来源选择信号。默认选择HRC 0: HRC 1: PLL 2: LRC 3: XTAL 注意，PLL/XTAL在上电后默认关闭，需要软件来开启。
#define SYS_CLK_CFG_CLK_DIV_MAX    ((uint32_t)0xFF)                                      // SYS_CLK_CFG_CLK_DIV最大值
#define SYS_CLK_CFG_CLK_DIV_POS    0                                                     // SYS_CLK_CFG_CLK_DIV起始位
#define SYS_CLK_CFG_CLK_DIV_MASK   (uint32_t)((uint32_t)0xFF << SYS_CLK_CFG_CLK_DIV_POS) // SYS_CLK_CFG_CLK_DIV位掩码
#define SYS_CLK_CFG_CLK_DIV(x)     (uint32_t)(((x) & 0xFF) << SYS_CLK_CFG_CLK_DIV_POS)   // [7:0] PLL输出分频控制，默认为 0x00: 1/8分频 0x01: 1/8分频 0x11: 1/4分频 0x55: 1/2分频 0xFF: 1/1分频 不推荐其它配置值。

/* SYS_IO_CFG IO控制寄存器 */
#define SYS_IO_CFG_TRACEMUX_BIT BIT7                                              // [7] TRACE复用控制信号，默认配置为TRACE功能 0: P1[3:0]，P0[15:14]作为正常GPIO使用 1: P1[3]复用SWV，{P0[15],P1[0:2]}复用为TRACEDATA[3:0]，P0[14]复用为TRACECLK
#define SYS_IO_CFG_SWDMUX_BIT   BIT6                                              // [6] JTAG/SWD复用控制信号，默认配置为JTAG/SWD 0: IO功能为JTAG/SWD P0.9---\>nTRST P0.10---\>SWDIOTMS P0.11 ---\>TDI P0.12---\>SWCLKTCLK P0.13---\>TDO 1:P0[13:9]作为正常GPIO使用
#define SYS_IO_CFG_RST_IO_BIT   BIT5                                              // [5] RSTn/P0.6复用控制信号，默认配置为RSTn 0:RSTn 1:P0.6 注意，上电后默认是RSTn，后续软件可使能此位，RSTn功能失效
#define SYS_IO_CFG_POR_FIL_BIT  BIT4                                              // [4] 未对用户开放 此寄存器使用SYS_AFE_REG6[11]作为复位，所以需要先配置SYS_AFE_REG6[11]=1，然后才可以使能POR滤波，POR滤波对LPOR和HPOR均有效
#define SYS_IO_CFG_IO_DS_MAX    ((uint32_t)0x3)                                   // SYS_IO_CFG_IO_DS最大值
#define SYS_IO_CFG_IO_DS_POS    0                                                 // SYS_IO_CFG_IO_DS起始位
#define SYS_IO_CFG_IO_DS_MASK   (uint32_t)((uint32_t)0x3 << SYS_IO_CFG_IO_DS_POS) // SYS_IO_CFG_IO_DS位掩码
#define SYS_IO_CFG_IO_DS(x)     (uint32_t)(((x) & 0x3) << SYS_IO_CFG_IO_DS_POS)   // [1:0] IO驱动能力选择 0: 4.5mA 1: 9mA 2: 13.5mA 3: 18mA 上电默认驱动能力为13.5mA

/* SYS_DBG_CFG Debug控制寄存器 */
#define SYS_DBG_CFG_SW_IRQ_TRIG_MAX   ((uint32_t)0xFFFF)                                          // SYS_DBG_CFG_SW_IRQ_TRIG最大值
#define SYS_DBG_CFG_SW_IRQ_TRIG_POS   16                                                          // SYS_DBG_CFG_SW_IRQ_TRIG起始位
#define SYS_DBG_CFG_SW_IRQ_TRIG_MASK  (uint32_t)((uint32_t)0xFFFF << SYS_DBG_CFG_SW_IRQ_TRIG_POS) // SYS_DBG_CFG_SW_IRQ_TRIG位掩码
#define SYS_DBG_CFG_SW_IRQ_TRIG(x)    (uint32_t)(((x) & 0xFFFF) << SYS_DBG_CFG_SW_IRQ_TRIG_POS)   // [31:16] 向此位段写入0x5AA5 触发软件中断，SW_IRQ置1
#define SYS_DBG_CFG_SW_IRQ_BIT        BIT15                                                       // [15] 软件中断标志，对应中断号30，写1清零。
#define SYS_DBG_CFG_SFT_RST_PERI_BIT  BIT14                                                       // [14] Debug软复位是否复位除Flash/SYS_AFE以外的外设寄存器
#define SYS_DBG_CFG_DBG_TIM4_STOP_BIT BIT12                                                       // [12] 调试模式下CPU halt状态Timer4停止 1：Timer4在CPU halt状态时停止计数 0：Timer4在CPU halt状态时继续计数
#define SYS_DBG_CFG_DBG_TIM3_STOP_BIT BIT11                                                       // [11] 调试模式下CPU halt状态Timer3停止 1：Timer3在CPU halt状态时停止计数 0：Timer3在CPU halt状态时继续计数
#define SYS_DBG_CFG_DBG_TIM2_STOP_BIT BIT10                                                       // [10] 调试模式下CPU halt状态Timer2停止 1：Timer2在CPU halt状态时停止计数 0：Timer2在CPU halt状态时继续计数
#define SYS_DBG_CFG_DBG_TIM1_STOP_BIT BIT9                                                        // [9] 调试模式下CPU halt状态Timer1停止 1：Timer1在CPU halt状态时停止计数 0：Timer1在CPU halt状态时继续计数
#define SYS_DBG_CFG_DBG_TIM0_STOP_BIT BIT8                                                        // [8] 调试模式下CPU halt状态Timer0停止 1：Timer0在CPU halt状态时停止计数 0：Timer0在CPU halt状态时继续计数
#define SYS_DBG_CFG_DBG_IWDG_STOP_BIT BIT5                                                        // [5] 调试模式下CPU halt状态独立看门狗停止 1：独立看门狗在CPU halt状态时停止计数 0：独立看门狗在CPU halt状态时继续计数
#define SYS_DBG_CFG_DBG_WWDG_STOP_BIT BIT4                                                        // [4] 调试模式下CPU halt状态窗口看门狗停止 1：窗口看门狗在CPU halt状态时停止计数 0：窗口看门狗在CPU halt状态时继续计数
#define SYS_DBG_CFG_DBG_STDBY_BIT     BIT2                                                        // [2] 调试StandBy模式 0: (FCLK=Off, HCLK=Off) 整个数字电路进入关电状态（除PMU）。从软件角度看，退出Standby休眠与上电复位相同，只是AON_EVT_RCD会指示休眠唤醒等状态位 1: (FCLK=On, HCLK=On) 如果设置了DBG_STDBY=1，数字部分不会掉电，而且内部高速均不关闭。但PMU仍会在退出休眠时产生复位信号，重新开始取指执行。使得执行过程与不设置DBG_STDBY时相同
#define SYS_DBG_CFG_DBG_STOP_BIT      BIT1                                                        // [1] 调试STOP模式 0: (FCLK=Off, HCLK=Off) 在STOP模式下，时钟管理模块关闭HCLK和FCLK，即处理器时钟和所有外设时钟。 当退出STOP模式时，时钟管理模块不经历复位，并保持原有配置，可以恢复到STOP模式前的时钟设置。在STOP模式中，所有外设寄存器均保持，因此退出后无需重新配置。 1: (FCLK=On, HCLK=On) 如果设置DBG_STOP为1，进入STOP模式后HCLK和FCLK均不被关闭。
#define SYS_DBG_CFG_DBG_SLP_BIT       BIT0                                                        // [0] 调试睡眠模式 0: (FCLK=On, HCLK=Off) 在睡眠模式中，FCLK作为所有外设时钟，不关闭； HCLK作为CPU时钟，被关闭。 在睡眠模式中，只有CPU时钟被暂时挂起，而所有外设包括系统时钟管理模块均保持原有配置状态。因此退出睡眠模式时，软件无需重新配置外设寄存器。 1: (FCLK=On, HCLK=On) 如果配置DBG_SLP为1，则当进入睡眠模式时，HCLK不会关闭。 通过__WFI()/___WFE()指令可以令处理器进入睡眠模式

/* SYS_CLK_DIV0 外设时钟分频寄存器0 */
#define SYS_CLK_DIV0_DIV0_MAX  ((uint32_t)0xFFFF)                                    // SYS_CLK_DIV0_DIV0最大值
#define SYS_CLK_DIV0_DIV0_POS  0                                                     // SYS_CLK_DIV0_DIV0起始位
#define SYS_CLK_DIV0_DIV0_MASK (uint32_t)((uint32_t)0xFFFF << SYS_CLK_DIV0_DIV0_POS) // SYS_CLK_DIV0_DIV0位掩码
#define SYS_CLK_DIV0_DIV0(x)   (uint32_t)(((x) & 0xFFFF) << SYS_CLK_DIV0_DIV0_POS)   // [15:0] I2C0/I2C1工作时钟=MCLK/(CLK_DIV0+1)。其中MCLK由SYS_CLK_CFG分频系数决定

/* SYS_CLK_DIV1 外设时钟分频寄存器1 */
#define SYS_CLK_DIV1_DIV1_MAX  ((uint32_t)0xFFFF)                                    // SYS_CLK_DIV1_DIV1最大值
#define SYS_CLK_DIV1_DIV1_POS  0                                                     // SYS_CLK_DIV1_DIV1起始位
#define SYS_CLK_DIV1_DIV1_MASK (uint32_t)((uint32_t)0xFFFF << SYS_CLK_DIV1_DIV1_POS) // SYS_CLK_DIV1_DIV1位掩码
#define SYS_CLK_DIV1_DIV1(x)   (uint32_t)(((x) & 0xFFFF) << SYS_CLK_DIV1_DIV1_POS)   // [15:0] CAN工作时钟=MCLK/(CLK_DIV1+1)。其中MCLK由SYS_CLK_CFG分频系数决定

/* SYS_CLK_DIV2 外设时钟分频寄存器2 */
#define SYS_CLK_DIV2_DIV2_MAX  ((uint32_t)0xFFFF)                                    // SYS_CLK_DIV2_DIV2最大值
#define SYS_CLK_DIV2_DIV2_POS  0                                                     // SYS_CLK_DIV2_DIV2起始位
#define SYS_CLK_DIV2_DIV2_MASK (uint32_t)((uint32_t)0xFFFF << SYS_CLK_DIV2_DIV2_POS) // SYS_CLK_DIV2_DIV2位掩码
#define SYS_CLK_DIV2_DIV2(x)   (uint32_t)(((x) & 0xFFFF) << SYS_CLK_DIV2_DIV2_POS)   // [15:0] UART工作时钟=MCLK/(CLK_DIV2+1)。UART0/UART1/UART2共享此分频配置，波特率根据UART波特率寄存器进一步分频，其中MCLK由SYS_CLK_CFG分频系数决定。

/* SYS_CLK_FEN 外设时钟门控寄存器 */
#define SYS_CLK_FEN_SPI1_CLK_EN_BIT   BIT31 // [31] SPI1模块时钟控制信号，默认关闭SPI0模块时钟 1:使能SPI0模块时钟 0:关闭SPI0模块时钟
#define SYS_CLK_FEN_SPI0_CLK_EN_BIT   BIT30 // [30] SPI0模块时钟控制信号，默认关闭SPI0模块时钟 1:使能SPI0模块时钟 0:关闭SPI0模块时钟
#define SYS_CLK_FEN_CAN_CLK_EN_BIT    BIT29 // [29] CAN模块时钟控制信号，默认关闭CAN模块时钟 1:使能CAN模块时钟 0:关闭CAN模块时钟
#define SYS_CLK_FEN_ADC2_CLK_EN_BIT   BIT28 // [28] ADC2模块时钟控制信号，默认关闭ADC2模块时钟 1:使能ADC2模块时钟 0:关闭ADC2模块时钟
#define SYS_CLK_FEN_ADC1_CLK_EN_BIT   BIT27 // [27] ADC1模块时钟控制信号，默认关闭ADC1模块时钟 1:使能ADC1模块时钟 0:关闭ADC1模块时钟
#define SYS_CLK_FEN_ADC0_CLK_EN_BIT   BIT26 // [26] ADC0模块时钟控制信号，默认关闭ADC0模块时钟 1:使能ADC0模块时钟 0:关闭ADC0模块时钟
#define SYS_CLK_FEN_CORDIC_CLK_EN_BIT BIT24 // [24] CORDIC模块时钟控制信号，默认关闭CORDIC模块时钟 1:使能CORDIC模块时钟 0:关闭CORDIC模块时钟
#define SYS_CLK_FEN_CRC_CLK_EN_BIT    BIT23 // [23] CRC模块时钟控制信号，默认关闭CRC模块时钟 1:使能CRC模块时钟 0:关闭CRC模块时钟
#define SYS_CLK_FEN_GPIO_CLK_EN_BIT   BIT22 // [22] GPIO模块时钟控制信号，默认关闭GPIO模块时钟 1:使能GPIO模块时钟 0:关闭GPIO模块时钟
#define SYS_CLK_FEN_QEP3_CLK_EN_BIT   BIT20 // [20] QEP3模块时钟控制信号，默认关闭QEP3模块时钟 1:使能QEP3模块时钟 0:关闭QEP3模块时钟
#define SYS_CLK_FEN_QEP2_CLK_EN_BIT   BIT19 // [19] QEP2模块时钟控制信号，默认关闭QEP2模块时钟 1:使能QEP2模块时钟 0:关闭QEP2模块时钟
#define SYS_CLK_FEN_QEP1_CLK_EN_BIT   BIT18 // [18] QEP1模块时钟控制信号，默认关闭QEP1模块时钟 1:使能QEP1模块时钟 0:关闭QEP1模块时钟
#define SYS_CLK_FEN_QEP0_CLK_EN_BIT   BIT17 // [17] QEP0模块时钟控制信号，默认关闭QEP0模块时钟 1:使能QEP0模块时钟 0:关闭QEP0模块时钟
#define SYS_CLK_FEN_TIMER4_CKL_EN_BIT BIT16 // [16] TIMER4模块时钟控制信号，默认关闭TIMER4模块时钟 1:使能TIMER4模块时钟 0:关闭TIMER4模块时钟
#define SYS_CLK_FEN_TIMER3_CKL_EN_BIT BIT15 // [15] TIMER3模块时钟控制信号，默认关闭TIMER3模块时钟 1:使能TIMER3模块时钟 0:关闭TIMER3模块时钟
#define SYS_CLK_FEN_TIMER2_CKL_EN_BIT BIT14 // [14] TIMER2模块时钟控制信号，默认关闭TIMER2模块时钟 1:使能TIMER2模块时钟 0:关闭TIMER2模块时钟
#define SYS_CLK_FEN_TIMER1_CKL_EN_BIT BIT13 // [13] TIMER1模块时钟控制信号，默认关闭TIMER1模块时钟 1:使能TIMER1模块时钟 0:关闭TIMER1模块时钟
#define SYS_CLK_FEN_TIMER0_CKL_EN_BIT BIT12 // [12] TIMER0模块时钟控制信号，默认关闭TIMER0模块时钟 1:使能TIMER0模块时钟 0:关闭TIMER0模块时钟
#define SYS_CLK_FEN_MCPWM1_CKL_EN_BIT BIT10 // [10] MCPWM1模块时钟控制信号，默认关闭MCPWM1模块时钟 1:使能MCPWM1模块时钟 0:关闭MCPWM1模块时钟
#define SYS_CLK_FEN_MCPWM0_CKL_EN_BIT BIT9  // [9] MCPWM0模块时钟控制信号，默认关闭MCPWM0模块时钟 1:使能MCPWM0模块时钟 0:关闭MCPWM0模块时钟
#define SYS_CLK_FEN_CMP_CKL_EN_BIT    BIT8  // [8] CMP模块时钟控制信号，默认关闭CMP模块时钟 1:使能CMP模块时钟 0:关闭CMP模块时钟
#define SYS_CLK_FEN_UART2_CLK_EN_BIT  BIT6  // [6] UART2模块时钟控制信号，默认关闭UART2模块时钟 1:使能UART2模块时钟 0:关闭UART2模块时钟
#define SYS_CLK_FEN_UART1_CLK_EN_BIT  BIT5  // [5] UART1模块时钟控制信号，默认关闭UART1模块时钟 1:使能UART1模块时钟 0:关闭UART1模块时钟
#define SYS_CLK_FEN_UART0_CLK_EN_BIT  BIT4  // [4] UART0模块时钟控制信号，默认关闭UART0模块时钟 1:使能UART0模块时钟 0:关闭UART0模块时钟
#define SYS_CLK_FEN_HALL1_CLK_EN_BIT  BIT3  // [3] HALL1模块时钟控制信号，默认关闭HALL1模块时钟 1:使能HALL1模块时钟 0:关闭HALL1模块时钟
#define SYS_CLK_FEN_HALL0_CLK_EN_BIT  BIT2  // [2] HALL0模块时钟控制信号，默认关闭HALL0模块时钟 1:使能HALL0模块时钟 0:关闭HALL0模块时钟
#define SYS_CLK_FEN_I2C1_CLK_EN_BIT   BIT0  // [0] I2C1模块时钟控制信号，默认关闭I2C1模块时钟 1:使能I2C1模块时钟 0:关闭I2C1模块时钟
#define SYS_CLK_FEN_I2C0_CLK_EN_BIT   BIT0  // [0] I2C0模块时钟控制信号，默认关闭I2C0模块时钟 1:使能I2C0模块时钟 0:关闭I2C0模块时钟

/* SYS_SFT_RST 软复位寄存器 */
#define SYS_SFT_RST_SPI1_SFT_RST_BIT   BIT31 // [31] SPI1模块软复位信号，默认不复位SPI0模块 1:复位SPI0模块 0:释放SPI0模块
#define SYS_SFT_RST_SPI0_SFT_RST_BIT   BIT30 // [30] SPI0模块软复位信号，默认不复位SPI0模块 1:复位SPI0模块 0:释放SPI0模块
#define SYS_SFT_RST_CAN_SFT_RST_BIT    BIT29 // [29] CAN模块软复位信号，默认不复位CAN模块 1:复位CAN模块 0:释放CAN模块
#define SYS_SFT_RST_ADC2_SFT_RST_BIT   BIT28 // [28] ADC2模块软复位信号，默认不复位ADC2模块 1:复位ADC2模块 0:释放ADC2模块
#define SYS_SFT_RST_ADC1_SFT_RST_BIT   BIT27 // [27] ADC1模块软复位信号，默认不复位ADC1模块 1:复位ADC1模块 0:释放ADC1模块
#define SYS_SFT_RST_ADC0_SFT_RST_BIT   BIT26 // [26] ADC0模块软复位信号，默认不复位ADC0模块 1:复位ADC0模块 0:释放ADC0模块
#define SYS_SFT_RST_CORDIC_SFT_RST_BIT BIT24 // [24] CORDIC模块软复位信号，默认不复位CORDIC模块 1:复位CORDIC模块 0:释放CORDIC模块
#define SYS_SFT_RST_CRC_SFT_RST_BIT    BIT23 // [23] CRC模块软复位信号，默认不复位CRC模块 1:复位CRC模块 0:释放CRC模块
#define SYS_SFT_RST_GPIO_SFT_RST_BIT   BIT22 // [22] GPIO模块软复位信号，默认不复位GPIO模块 1:复位GPIO模块 0:释放GPIO模块
#define SYS_SFT_RST_DMA_SFT_RST_BIT    BIT21 // [21] DMA模块软复位信号，默认不复位DMA模块 1:复位DMA模块 0:释放DMA模块
#define SYS_SFT_RST_QEP3_SFT_RST_BIT   BIT20 // [20] QEP3模块软复位信号，默认不复位QEP3模块 1:复位QEP3模块 0:释放QEP3模块
#define SYS_SFT_RST_QEP2_SFT_RST_BIT   BIT19 // [19] QEP2模块软复位信号，默认不复位QEP2模块 1:复位QEP2模块 0:释放QEP2模块
#define SYS_SFT_RST_QEP1_SFT_RST_BIT   BIT18 // [18] QEP1模块软复位信号，默认不复位QEP1模块 1:复位QEP1模块 0:释放QEP1模块
#define SYS_SFT_RST_QEP0_SFT_RST_BIT   BIT17 // [17] QEP0模块软复位信号，默认不复位QEP0模块 1:复位QEP0模块 0:释放QEP0模块
#define SYS_SFT_RST_TIMER4_SFT_RST_BIT BIT16 // [16] TIMER4模块软复位信号，默认不复位TIMER4模块 1:复位TIMER4模块 0:释放TIMER4模块
#define SYS_SFT_RST_TIMER3_SFT_RST_BIT BIT15 // [15] TIMER3模块软复位信号，默认不复位TIMER3模块 1:复位TIMER3模块 0:释放TIMER3模块
#define SYS_SFT_RST_TIMER2_SFT_RST_BIT BIT14 // [14] TIMER2模块软复位信号，默认不复位TIMER2模块 1:复位TIMER2模块 0:释放TIMER2模块
#define SYS_SFT_RST_TIMER1_SFT_RST_BIT BIT13 // [13] TIMER1模块软复位信号，默认不复位TIMER1模块 1:复位TIMER1模块 0:释放TIMER1模块
#define SYS_SFT_RST_TIMER0_SFT_RST_BIT BIT12 // [12] TIMER0模块软复位信号，默认不复位TIMER0模块 1:复位TIMER0模块 0:释放TIMER0模块
#define SYS_SFT_RST_MCPWM1_SFT_RST_BIT BIT10 // [10] MCPWM1模块软复位信号，默认不复位MCPWM1模块 1:复位MCPWM1模块 0:释放MCPWM1模块
#define SYS_SFT_RST_MCPWM0_SFT_RST_BIT BIT9  // [9] MCPWM0模块软复位信号，默认不复位MCPWM0模块 1:复位MCPWM0模块 0:释放MCPWM0模块
#define SYS_SFT_RST_CMP_SFT_RST_BIT    BIT8  // [8] CMP模块软复位信号，默认不复位CMP模块 1:复位CMP模块 0:释放CMP模块
#define SYS_SFT_RST_UART2_SFT_RST_BIT  BIT6  // [6] UART2模块软复位信号，默认不复位UART2模块 1:复位UART2模块 0:释放UART2模块
#define SYS_SFT_RST_UART1_SFT_RST_BIT  BIT5  // [5] UART1模块软复位信号，默认不复位UART1模块 1:复位UART1模块 0:释放UART1模块
#define SYS_SFT_RST_UART0_SFT_RST_BIT  BIT4  // [4] UART0模块软复位信号，默认不复位UART0模块 1:复位UART0模块 0:释放UART0模块
#define SYS_SFT_RST_HALL1_SFT_RST_BIT  BIT3  // [3] HALL1模块软复位信号，默认不复位HALL1模块 1:复位HALL1模块 0:释放HALL1模块
#define SYS_SFT_RST_HALL0_SFT_RST_BIT  BIT2  // [2] HALL0模块软复位信号，默认不复位HALL0模块 1:复位HALL0模块 0:释放HALL0模块
#define SYS_SFT_RST_I2C1_SFT_RST_BIT   BIT1  // [1] I2C1模块软复位信号，默认不复位I2C1模块 1:复位I2C1模块 0:释放I2C1模块
#define SYS_SFT_RST_I2C0_SFT_RST_BIT   BIT0  // [0] I2C0模块软复位信号，默认不复位I2C0模块 1:复位I2C0模块 0:释放I2C0模块

/* SYS_PROTECT 写保护寄存器 */
#define SYS_PROTECT_PSW_MAX  ((uint32_t)0xFFFF)                                  // SYS_PROTECT_PSW最大值
#define SYS_PROTECT_PSW_POS  0                                                   // SYS_PROTECT_PSW起始位
#define SYS_PROTECT_PSW_MASK (uint32_t)((uint32_t)0xFFFF << SYS_PROTECT_PSW_POS) // SYS_PROTECT_PSW位掩码
#define SYS_PROTECT_PSW(x)   (uint32_t)(((x) & 0xFFFF) << SYS_PROTECT_PSW_POS)   // [15:0] 除SYS_AFE_DACx、SYS_AFE_DACx_AMC、SYS_AFE_DACx_DC(x=0,1)外，其他系统寄存器均受写保护，写入前需先写入密码解除写保护 写入0x7A83，使能寄存器写操作 写入其它值，禁止寄存器写操作

/* SYS_CACHE_CFG 缓存控制寄存器 */
#define SYS_CACHE_CFG_EN_BIT BIT0 // [0] Cache使能，1：启用Cache，0：禁用Cache

/* SYS_MEM_CFG 内存控制寄存器 */
#define SYS_MEM_CFG_REMAP_MAX    ((uint32_t)0x3)                                      // SYS_MEM_CFG_REMAP最大值
#define SYS_MEM_CFG_REMAP_POS    8                                                    // SYS_MEM_CFG_REMAP起始位
#define SYS_MEM_CFG_REMAP_MASK   (uint32_t)((uint32_t)0x3 << SYS_MEM_CFG_REMAP_POS)   // SYS_MEM_CFG_REMAP位掩码
#define SYS_MEM_CFG_REMAP(x)     (uint32_t)(((x) & 0x3) << SYS_MEM_CFG_REMAP_POS)     // [9:8] 地址空间重映射，用于将SRAM1/2/3映射至0x1FFFFFFF之前的地址空间做为Code RAM使用，Code RAM可用于存放关键代码，由于RAM访问速度更快，可以加速关键代码的的执行。 0：SRAM0/1/2/3均用为Data RAM，无Code RAM 1：SRAM0/1/2用为Data RAM，SRAM3用作Code RAM 2：SRAM0/1用为Data RAM，SRAM2/3用作Code RAM 3：SRAM0用为Data RAM，SRAM1/2/3用作Code RAM 具体地址空间请参考第3章地址空间章节
#define SYS_MEM_CFG_PCK_EN_MAX   ((uint32_t)0xF)                                      // SYS_MEM_CFG_PCK_EN最大值
#define SYS_MEM_CFG_PCK_EN_POS   4                                                    // SYS_MEM_CFG_PCK_EN起始位
#define SYS_MEM_CFG_PCK_EN_MASK  (uint32_t)((uint32_t)0xF << SYS_MEM_CFG_PCK_EN_POS)  // SYS_MEM_CFG_PCK_EN位掩码
#define SYS_MEM_CFG_PCK_EN(x)    (uint32_t)(((x) & 0xF) << SYS_MEM_CFG_PCK_EN_POS)    // [7:4] SRAM3/2/1/0 内存奇偶校验使能
#define SYS_MEM_CFG_PCK_ERR_MAX  ((uint32_t)0xF)                                      // SYS_MEM_CFG_PCK_ERR最大值
#define SYS_MEM_CFG_PCK_ERR_POS  0                                                    // SYS_MEM_CFG_PCK_ERR起始位
#define SYS_MEM_CFG_PCK_ERR_MASK (uint32_t)((uint32_t)0xF << SYS_MEM_CFG_PCK_ERR_POS) // SYS_MEM_CFG_PCK_ERR位掩码
#define SYS_MEM_CFG_PCK_ERR(x)   (uint32_t)(((x) & 0xF) << SYS_MEM_CFG_PCK_ERR_POS)   // [3:0] SRAM3/2/1/0 内存奇偶校验错误，0：无错误发生，1：有错误发生，写1清零

/* SYS_FLSE On-Chip FLASH擦除控制寄存器 */
#define SYS_FLSE_FLSE_MAX  ((uint32_t)0xFFFF)                                // SYS_FLSE_FLSE最大值
#define SYS_FLSE_FLSE_POS  0                                                 // SYS_FLSE_FLSE起始位
#define SYS_FLSE_FLSE_MASK (uint32_t)((uint32_t)0xFFFF << SYS_FLSE_FLSE_POS) // SYS_FLSE_FLSE位掩码
#define SYS_FLSE_FLSE(x)   (uint32_t)(((x) & 0xFFFF) << SYS_FLSE_FLSE_POS)   // [15:0] On-Chip FLASH擦除控制寄存器。本寄存器写入0x8FCA，On-Chip FLASH的擦除功能才能最终生效。写入其他值，On-Chip FLASH的擦除功能均无法生效。为防止误擦除，建议不使用擦除功能时，不生效此寄存器。

/* SYS_FLSP On-Chip FLASH编程控制寄存器 */
#define SYS_FLSP_FLSP_MAX  ((uint32_t)0xFFFF)                                // SYS_FLSP_FLSP最大值
#define SYS_FLSP_FLSP_POS  0                                                 // SYS_FLSP_FLSP起始位
#define SYS_FLSP_FLSP_MASK (uint32_t)((uint32_t)0xFFFF << SYS_FLSP_FLSP_POS) // SYS_FLSP_FLSP位掩码
#define SYS_FLSP_FLSP(x)   (uint32_t)(((x) & 0xFFFF) << SYS_FLSP_FLSP_POS)   // [15:0] On-Chip FLASH编程控制寄存器。本寄存器写入0x8F35，On-Chip FLASH的编程功能才能最终生效。写入其他值，On-Chip FLASH的编程功能均无法生效。为防止误编程，建议不使用编程功能时，不生效此寄存器。

/* FSMC_UCMD Ext-Chip FLASH间接方式访问命令寄存器 */
#define FSMC_UCMD_UCMD_MAX  ((uint32_t)0xFF)                                 // FSMC_UCMD_UCMD最大值
#define FSMC_UCMD_UCMD_POS  0                                                // FSMC_UCMD_UCMD起始位
#define FSMC_UCMD_UCMD_MASK (uint32_t)((uint32_t)0xFF << FSMC_UCMD_UCMD_POS) // FSMC_UCMD_UCMD位掩码
#define FSMC_UCMD_UCMD(x)   (uint32_t)(((x) & 0xFF) << FSMC_UCMD_UCMD_POS)   // [7:0] Ext-Chip FLASH间接方式访问命令寄存器

/* FSMC_UMOD Ext-Chip FLASH间接方式访问模式寄存器 */
#define FSMC_UMOD_UMOD_MAX  ((uint32_t)0xFF)                                 // FSMC_UMOD_UMOD最大值
#define FSMC_UMOD_UMOD_POS  0                                                // FSMC_UMOD_UMOD起始位
#define FSMC_UMOD_UMOD_MASK (uint32_t)((uint32_t)0xFF << FSMC_UMOD_UMOD_POS) // FSMC_UMOD_UMOD位掩码
#define FSMC_UMOD_UMOD(x)   (uint32_t)(((x) & 0xFF) << FSMC_UMOD_UMOD_POS)   // [7:0] Ext-Chip FLASH间接方式访问模式寄存器

/* FSMC_UADR Ext-Chip FLASH间接方式访问地址寄存器 */
#define FSMC_UADR_FSMC_UADR_MAX  ((uint32_t)0xFFFFFF)                                      // FSMC_UADR_FSMC_UADR最大值
#define FSMC_UADR_FSMC_UADR_POS  0                                                         // FSMC_UADR_FSMC_UADR起始位
#define FSMC_UADR_FSMC_UADR_MASK (uint32_t)((uint32_t)0xFFFFFF << FSMC_UADR_FSMC_UADR_POS) // FSMC_UADR_FSMC_UADR位掩码
#define FSMC_UADR_FSMC_UADR(x)   (uint32_t)(((x) & 0xFFFFFF) << FSMC_UADR_FSMC_UADR_POS)   // [23:0] Ext-Chip FLASH间接方式访问地址寄存器

/* FSMC_UWDA Ext-Chip FLASH间接方式访问编程数据寄存器 */
#define FSMC_UWDA_FSMC_UWDA_MAX  ((uint32_t)0xFFFFFFFF)                                      // FSMC_UWDA_FSMC_UWDA最大值
#define FSMC_UWDA_FSMC_UWDA_POS  0                                                           // FSMC_UWDA_FSMC_UWDA起始位
#define FSMC_UWDA_FSMC_UWDA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_UWDA_FSMC_UWDA_POS) // FSMC_UWDA_FSMC_UWDA位掩码
#define FSMC_UWDA_FSMC_UWDA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_UWDA_FSMC_UWDA_POS)   // [31:0] Ext-Chip FLASH间接方式访问编程数据寄存器

/* FSMC_URDA Ext-Chip FLASH间接方式访问读取数据寄存器 */
#define FSMC_URDA_FSMC_URDA_MAX  ((uint32_t)0xFFFFFFFF)                                      // FSMC_URDA_FSMC_URDA最大值
#define FSMC_URDA_FSMC_URDA_POS  0                                                           // FSMC_URDA_FSMC_URDA起始位
#define FSMC_URDA_FSMC_URDA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_URDA_FSMC_URDA_POS) // FSMC_URDA_FSMC_URDA位掩码
#define FSMC_URDA_FSMC_URDA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_URDA_FSMC_URDA_POS)   // [31:0] Ext-Chip FLASH间接方式访问读取数据寄存器

/* FSMC_URWT Ext-Chip FLASH间接方式访问控制寄存器 */
#define FSMC_URWT_FSMC_URWT_MAX  ((uint32_t)0xFFFF)                                      // FSMC_URWT_FSMC_URWT最大值
#define FSMC_URWT_FSMC_URWT_POS  0                                                       // FSMC_URWT_FSMC_URWT起始位
#define FSMC_URWT_FSMC_URWT_MASK (uint32_t)((uint32_t)0xFFFF << FSMC_URWT_FSMC_URWT_POS) // FSMC_URWT_FSMC_URWT位掩码
#define FSMC_URWT_FSMC_URWT(x)   (uint32_t)(((x) & 0xFFFF) << FSMC_URWT_FSMC_URWT_POS)   // [15:0] 上一次写操作或者间接读取操作传输完成后CSB拉高，等待多久可以进行下一次操作。 对于写操作，其中FSMC_URWT[06:00]位作为th0，FSMC_URWT[15:08]位作为th1，等待时间=(th0+1)×(th1+1) ×Clock_Period。 对于间接读取操作，其中FSMC_URWT[01:00]位作为th0，th1恒为0，等待时间=(th0+1)×Clock_Period。

/* FSMC_UCFG Ext-Chip FLASH间接方式访问控制寄存器 */
#define FSMC_UCFG_ORDER_BIT     BIT31                                               // 31 直接方式访问，读取数据大小头设置 0：Ext-Chip FLASH存储的数据，按照大头存放 1：Ext-Chip FLASH存储的数据，按照小头存放
#define FSMC_UCFG_R_CSB_TIM_BIT BIT30                                               // 30 特殊命令下，最后一个字节传输完成后需要延迟一个周期将CSB拉高。默认值为0
#define FSMC_UCFG_DAT_SPD_MAX   ((uint32_t)0x3)                                     // FSMC_UCFG_DAT_SPD最大值
#define FSMC_UCFG_DAT_SPD_POS   28                                                  // FSMC_UCFG_DAT_SPD起始位
#define FSMC_UCFG_DAT_SPD_MASK  (uint32_t)((uint32_t)0x3 << FSMC_UCFG_DAT_SPD_POS)  // FSMC_UCFG_DAT_SPD位掩码
#define FSMC_UCFG_DAT_SPD(x)    (uint32_t)(((x) & 0x3) << FSMC_UCFG_DAT_SPD_POS)    // [29:28] 数据部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_UCFG_DMY_SPD_MAX   ((uint32_t)0x3)                                     // FSMC_UCFG_DMY_SPD最大值
#define FSMC_UCFG_DMY_SPD_POS   26                                                  // FSMC_UCFG_DMY_SPD起始位
#define FSMC_UCFG_DMY_SPD_MASK  (uint32_t)((uint32_t)0x3 << FSMC_UCFG_DMY_SPD_POS)  // FSMC_UCFG_DMY_SPD位掩码
#define FSMC_UCFG_DMY_SPD(x)    (uint32_t)(((x) & 0x3) << FSMC_UCFG_DMY_SPD_POS)    // [27:26] 冗余部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_UCFG_MOD_SPD_MAX   ((uint32_t)0x3)                                     // FSMC_UCFG_MOD_SPD最大值
#define FSMC_UCFG_MOD_SPD_POS   24                                                  // FSMC_UCFG_MOD_SPD起始位
#define FSMC_UCFG_MOD_SPD_MASK  (uint32_t)((uint32_t)0x3 << FSMC_UCFG_MOD_SPD_POS)  // FSMC_UCFG_MOD_SPD位掩码
#define FSMC_UCFG_MOD_SPD(x)    (uint32_t)(((x) & 0x3) << FSMC_UCFG_MOD_SPD_POS)    // [25:24] 模式部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_UCFG_ADR_SPD_MAX   ((uint32_t)0x3)                                     // FSMC_UCFG_ADR_SPD最大值
#define FSMC_UCFG_ADR_SPD_POS   22                                                  // FSMC_UCFG_ADR_SPD起始位
#define FSMC_UCFG_ADR_SPD_MASK  (uint32_t)((uint32_t)0x3 << FSMC_UCFG_ADR_SPD_POS)  // FSMC_UCFG_ADR_SPD位掩码
#define FSMC_UCFG_ADR_SPD(x)    (uint32_t)(((x) & 0x3) << FSMC_UCFG_ADR_SPD_POS)    // [23:22] 地址部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_UCFG_CMD_SPD_MAX   ((uint32_t)0x3)                                     // FSMC_UCFG_CMD_SPD最大值
#define FSMC_UCFG_CMD_SPD_POS   20                                                  // FSMC_UCFG_CMD_SPD起始位
#define FSMC_UCFG_CMD_SPD_MASK  (uint32_t)((uint32_t)0x3 << FSMC_UCFG_CMD_SPD_POS)  // FSMC_UCFG_CMD_SPD位掩码
#define FSMC_UCFG_CMD_SPD(x)    (uint32_t)(((x) & 0x3) << FSMC_UCFG_CMD_SPD_POS)    // [21:20] 指令部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_UCFG_DAT_LEN_MAX   ((uint32_t)0xFF)                                    // FSMC_UCFG_DAT_LEN最大值
#define FSMC_UCFG_DAT_LEN_POS   12                                                  // FSMC_UCFG_DAT_LEN起始位
#define FSMC_UCFG_DAT_LEN_MASK  (uint32_t)((uint32_t)0xFF << FSMC_UCFG_DAT_LEN_POS) // FSMC_UCFG_DAT_LEN位掩码
#define FSMC_UCFG_DAT_LEN(x)    (uint32_t)(((x) & 0xFF) << FSMC_UCFG_DAT_LEN_POS)   // [19:12] 数据部分数据长度，字节为最小单位，0代表无此部分，1代表1个字节，一次类推，最大15个字节
#define FSMC_UCFG_DMY_LEN_MAX   ((uint32_t)0xF)                                     // FSMC_UCFG_DMY_LEN最大值
#define FSMC_UCFG_DMY_LEN_POS   8                                                   // FSMC_UCFG_DMY_LEN起始位
#define FSMC_UCFG_DMY_LEN_MASK  (uint32_t)((uint32_t)0xF << FSMC_UCFG_DMY_LEN_POS)  // FSMC_UCFG_DMY_LEN位掩码
#define FSMC_UCFG_DMY_LEN(x)    (uint32_t)(((x) & 0xF) << FSMC_UCFG_DMY_LEN_POS)    // [11:8] 冗余部分数据长度，字节为最小单位，0代表无此部分，1代表1个字节，一次类推，最大15个字节
#define FSMC_UCFG_MOD_LEN_MAX   ((uint32_t)0xF)                                     // FSMC_UCFG_MOD_LEN最大值
#define FSMC_UCFG_MOD_LEN_POS   4                                                   // FSMC_UCFG_MOD_LEN起始位
#define FSMC_UCFG_MOD_LEN_MASK  (uint32_t)((uint32_t)0xF << FSMC_UCFG_MOD_LEN_POS)  // FSMC_UCFG_MOD_LEN位掩码
#define FSMC_UCFG_MOD_LEN(x)    (uint32_t)(((x) & 0xF) << FSMC_UCFG_MOD_LEN_POS)    // [7:4] 模式部分数据长度，字节为最小单位，0代表无此部分，1代表1个字节，一次类推，最大15个字节

/* FSMC_UTRG Ext-Chip FLASH间接方式访问操作寄存器 */
#define FSMC_UTRG_DMA_EN_BIT BIT2 // [2] Ext-Chip FLASH控制器使能DMA搬移操作
#define FSMC_UTRG_OP_BIT     BIT1 // [1] 通过Ext-Chip FLASH控制器间接方式访问Ext-Chip FLASH，操作类型 1：编程/擦除 0：读取
#define FSMC_UTRG_SEL_BIT    BIT0 // [0] 通过Ext-Chip FLASH控制器间接方式访问Ext-Chip FLASH。同时，此位也是状态位。 1：触发操作，处理中 0：不触发操作，空闲

/* FSMC_FCMD Ext-Chip FLASH直接方式访问命令寄存器 */
#define FSMC_FCMD_FCMD_MAX  ((uint32_t)0xFF)                                 // FSMC_FCMD_FCMD最大值
#define FSMC_FCMD_FCMD_POS  0                                                // FSMC_FCMD_FCMD起始位
#define FSMC_FCMD_FCMD_MASK (uint32_t)((uint32_t)0xFF << FSMC_FCMD_FCMD_POS) // FSMC_FCMD_FCMD位掩码
#define FSMC_FCMD_FCMD(x)   (uint32_t)(((x) & 0xFF) << FSMC_FCMD_FCMD_POS)   // [7:0] Ext-Chip FLASH直接方式访问命令寄存器

/* FSMC_FMOD Ext-Chip FLASH直接方式访问模式寄存器 */
#define FSMC_FMOD_FMOD_MAX  ((uint32_t)0xFF)                                 // FSMC_FMOD_FMOD最大值
#define FSMC_FMOD_FMOD_POS  0                                                // FSMC_FMOD_FMOD起始位
#define FSMC_FMOD_FMOD_MASK (uint32_t)((uint32_t)0xFF << FSMC_FMOD_FMOD_POS) // FSMC_FMOD_FMOD位掩码
#define FSMC_FMOD_FMOD(x)   (uint32_t)(((x) & 0xFF) << FSMC_FMOD_FMOD_POS)   // [7:0] Ext-Chip FLASH直接方式访问模式寄存器

/* FSMC_FRWT Ext-Chip FLASH直接方式访问控制寄存器 */
#define FSMC_FRWT_FSMC_FRWT_MAX  ((uint32_t)0xFFFF)                                      // FSMC_FRWT_FSMC_FRWT最大值
#define FSMC_FRWT_FSMC_FRWT_POS  0                                                       // FSMC_FRWT_FSMC_FRWT起始位
#define FSMC_FRWT_FSMC_FRWT_MASK (uint32_t)((uint32_t)0xFFFF << FSMC_FRWT_FSMC_FRWT_POS) // FSMC_FRWT_FSMC_FRWT位掩码
#define FSMC_FRWT_FSMC_FRWT(x)   (uint32_t)(((x) & 0xFFFF) << FSMC_FRWT_FSMC_FRWT_POS)   // [15:0] 上一次直接读取操作传输完成后CSB拉高，等待多久可以进行下一次操作。 对于直接读取操作，FSMC_URWT[01:00]位作为th0，th1恒为0，等待时间=(th0+1)×Clock_Period。

/* FSMC_FCFG Ext-Chip FLASH直接方式访问控制寄存器 */
#define FSMC_FCFG_ORDER_BIT    BIT27                                               // 27 直接方式访问，读取数据大小头设置 0：Ext-Chip FLASH存储的数据，按照大头存放 1：Ext-Chip FLASH存储的数据，按照小头存放
#define FSMC_FCFG_DAT_SPD_MAX  ((uint32_t)0x3)                                     // FSMC_FCFG_DAT_SPD最大值
#define FSMC_FCFG_DAT_SPD_POS  24                                                  // FSMC_FCFG_DAT_SPD起始位
#define FSMC_FCFG_DAT_SPD_MASK (uint32_t)((uint32_t)0x3 << FSMC_FCFG_DAT_SPD_POS)  // FSMC_FCFG_DAT_SPD位掩码
#define FSMC_FCFG_DAT_SPD(x)   (uint32_t)(((x) & 0x3) << FSMC_FCFG_DAT_SPD_POS)    // [25:24] 数据部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_FCFG_DMY_SPD_MAX  ((uint32_t)0x3)                                     // FSMC_FCFG_DMY_SPD最大值
#define FSMC_FCFG_DMY_SPD_POS  22                                                  // FSMC_FCFG_DMY_SPD起始位
#define FSMC_FCFG_DMY_SPD_MASK (uint32_t)((uint32_t)0x3 << FSMC_FCFG_DMY_SPD_POS)  // FSMC_FCFG_DMY_SPD位掩码
#define FSMC_FCFG_DMY_SPD(x)   (uint32_t)(((x) & 0x3) << FSMC_FCFG_DMY_SPD_POS)    // [23:22] 冗余部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_FCFG_MOD_SPD_MAX  ((uint32_t)0x3)                                     // FSMC_FCFG_MOD_SPD最大值
#define FSMC_FCFG_MOD_SPD_POS  20                                                  // FSMC_FCFG_MOD_SPD起始位
#define FSMC_FCFG_MOD_SPD_MASK (uint32_t)((uint32_t)0x3 << FSMC_FCFG_MOD_SPD_POS)  // FSMC_FCFG_MOD_SPD位掩码
#define FSMC_FCFG_MOD_SPD(x)   (uint32_t)(((x) & 0x3) << FSMC_FCFG_MOD_SPD_POS)    // [21:20] 模式部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_FCFG_ADR_SPD_MAX  ((uint32_t)0x3)                                     // FSMC_FCFG_ADR_SPD最大值
#define FSMC_FCFG_ADR_SPD_POS  18                                                  // FSMC_FCFG_ADR_SPD起始位
#define FSMC_FCFG_ADR_SPD_MASK (uint32_t)((uint32_t)0x3 << FSMC_FCFG_ADR_SPD_POS)  // FSMC_FCFG_ADR_SPD位掩码
#define FSMC_FCFG_ADR_SPD(x)   (uint32_t)(((x) & 0x3) << FSMC_FCFG_ADR_SPD_POS)    // [19:18] 地址部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_FCFG_CMD_SPD_MAX  ((uint32_t)0x3)                                     // FSMC_FCFG_CMD_SPD最大值
#define FSMC_FCFG_CMD_SPD_POS  16                                                  // FSMC_FCFG_CMD_SPD起始位
#define FSMC_FCFG_CMD_SPD_MASK (uint32_t)((uint32_t)0x3 << FSMC_FCFG_CMD_SPD_POS)  // FSMC_FCFG_CMD_SPD位掩码
#define FSMC_FCFG_CMD_SPD(x)   (uint32_t)(((x) & 0x3) << FSMC_FCFG_CMD_SPD_POS)    // [17:16] 指令部分并行发送配置 00：一根线传输 01：两根线传输 11：四根线传输 10：非法配置
#define FSMC_FCFG_DAT_LEN_MAX  ((uint32_t)0xFF)                                    // FSMC_FCFG_DAT_LEN最大值
#define FSMC_FCFG_DAT_LEN_POS  8                                                   // FSMC_FCFG_DAT_LEN起始位
#define FSMC_FCFG_DAT_LEN_MASK (uint32_t)((uint32_t)0xFF << FSMC_FCFG_DAT_LEN_POS) // FSMC_FCFG_DAT_LEN位掩码
#define FSMC_FCFG_DAT_LEN(x)   (uint32_t)(((x) & 0xFF) << FSMC_FCFG_DAT_LEN_POS)   // [15:8] 数据部分数据长度，字节为最小单位，0代表无此部分，1代表1个字节，一次类推，最大15个字节
#define FSMC_FCFG_DMY_LEN_MAX  ((uint32_t)0xF)                                     // FSMC_FCFG_DMY_LEN最大值
#define FSMC_FCFG_DMY_LEN_POS  4                                                   // FSMC_FCFG_DMY_LEN起始位
#define FSMC_FCFG_DMY_LEN_MASK (uint32_t)((uint32_t)0xF << FSMC_FCFG_DMY_LEN_POS)  // FSMC_FCFG_DMY_LEN位掩码
#define FSMC_FCFG_DMY_LEN(x)   (uint32_t)(((x) & 0xF) << FSMC_FCFG_DMY_LEN_POS)    // [7:4] 冗余部分数据长度，字节为最小单位，0代表无此部分，1代表1个字节，一次类推，最大15个字节
#define FSMC_FCFG_MOD_LEN_MAX  ((uint32_t)0xF)                                     // FSMC_FCFG_MOD_LEN最大值
#define FSMC_FCFG_MOD_LEN_POS  0                                                   // FSMC_FCFG_MOD_LEN起始位
#define FSMC_FCFG_MOD_LEN_MASK (uint32_t)((uint32_t)0xF << FSMC_FCFG_MOD_LEN_POS)  // FSMC_FCFG_MOD_LEN位掩码
#define FSMC_FCFG_MOD_LEN(x)   (uint32_t)(((x) & 0xF) << FSMC_FCFG_MOD_LEN_POS)    // [3:0] 模式部分数据长度，字节为最小单位，0代表无此部分，1代表1个字节，一次类推，最大15个字节

/* FSMC_FTRG Ext-Chip FLASH直接方式访问操作寄存器 */
#define FSMC_FTRG_UPDATE_BIT BIT0 // [0] Ext-Chip FLASH控制器直接方式访问寄存器更新。因存在可能MCU一直使用直接方式获取Ext-Chip FLASH的数据，为了安全考虑，需要在空闲期间更新直接访问相关寄存器，此位也相当于一个状态，表明是否更新完毕。 1：触发更新操作/更新过程中 0：不触发更新操作/更新完毕

/* FSMC_EDIV Ext-Chip FLASH波特率寄存器 */
#define FSMC_EDIV_DAT_BAUDL_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_DAT_BAUDL最大值
#define FSMC_EDIV_DAT_BAUDL_POS  18                                                   // FSMC_EDIV_DAT_BAUDL起始位
#define FSMC_EDIV_DAT_BAUDL_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_DAT_BAUDL_POS) // FSMC_EDIV_DAT_BAUDL位掩码
#define FSMC_EDIV_DAT_BAUDL(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_DAT_BAUDL_POS)   // [19:18] 数据部分波特率配置，低电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_DAT_BAUDH_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_DAT_BAUDH最大值
#define FSMC_EDIV_DAT_BAUDH_POS  16                                                   // FSMC_EDIV_DAT_BAUDH起始位
#define FSMC_EDIV_DAT_BAUDH_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_DAT_BAUDH_POS) // FSMC_EDIV_DAT_BAUDH位掩码
#define FSMC_EDIV_DAT_BAUDH(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_DAT_BAUDH_POS)   // [17:16] 数据部分波特率配置，高电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_DMY_BAUDL_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_DMY_BAUDL最大值
#define FSMC_EDIV_DMY_BAUDL_POS  14                                                   // FSMC_EDIV_DMY_BAUDL起始位
#define FSMC_EDIV_DMY_BAUDL_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_DMY_BAUDL_POS) // FSMC_EDIV_DMY_BAUDL位掩码
#define FSMC_EDIV_DMY_BAUDL(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_DMY_BAUDL_POS)   // [15:14] 冗余部分波特率配置，低电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_DMY_BAUDH_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_DMY_BAUDH最大值
#define FSMC_EDIV_DMY_BAUDH_POS  12                                                   // FSMC_EDIV_DMY_BAUDH起始位
#define FSMC_EDIV_DMY_BAUDH_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_DMY_BAUDH_POS) // FSMC_EDIV_DMY_BAUDH位掩码
#define FSMC_EDIV_DMY_BAUDH(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_DMY_BAUDH_POS)   // [13:12] 冗余部分波特率配置，高电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_MOD_BAUDL_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_MOD_BAUDL最大值
#define FSMC_EDIV_MOD_BAUDL_POS  10                                                   // FSMC_EDIV_MOD_BAUDL起始位
#define FSMC_EDIV_MOD_BAUDL_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_MOD_BAUDL_POS) // FSMC_EDIV_MOD_BAUDL位掩码
#define FSMC_EDIV_MOD_BAUDL(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_MOD_BAUDL_POS)   // [11:10] 模式部分波特率配置，低电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_MOD_BAUDH_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_MOD_BAUDH最大值
#define FSMC_EDIV_MOD_BAUDH_POS  8                                                    // FSMC_EDIV_MOD_BAUDH起始位
#define FSMC_EDIV_MOD_BAUDH_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_MOD_BAUDH_POS) // FSMC_EDIV_MOD_BAUDH位掩码
#define FSMC_EDIV_MOD_BAUDH(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_MOD_BAUDH_POS)   // [09:08] 模式部分波特率配置，高电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_ADR_BAUDL_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_ADR_BAUDL最大值
#define FSMC_EDIV_ADR_BAUDL_POS  6                                                    // FSMC_EDIV_ADR_BAUDL起始位
#define FSMC_EDIV_ADR_BAUDL_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_ADR_BAUDL_POS) // FSMC_EDIV_ADR_BAUDL位掩码
#define FSMC_EDIV_ADR_BAUDL(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_ADR_BAUDL_POS)   // [07:06] 地址部分波特率配置，低电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_ADR_BAUDH_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_ADR_BAUDH最大值
#define FSMC_EDIV_ADR_BAUDH_POS  4                                                    // FSMC_EDIV_ADR_BAUDH起始位
#define FSMC_EDIV_ADR_BAUDH_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_ADR_BAUDH_POS) // FSMC_EDIV_ADR_BAUDH位掩码
#define FSMC_EDIV_ADR_BAUDH(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_ADR_BAUDH_POS)   // [05:04] 地址部分波特率配置，高电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_CMD_BAUDL_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_CMD_BAUDL最大值
#define FSMC_EDIV_CMD_BAUDL_POS  2                                                    // FSMC_EDIV_CMD_BAUDL起始位
#define FSMC_EDIV_CMD_BAUDL_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_CMD_BAUDL_POS) // FSMC_EDIV_CMD_BAUDL位掩码
#define FSMC_EDIV_CMD_BAUDL(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_CMD_BAUDL_POS)   // [03:02] 指令部分波特率配置，低电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期
#define FSMC_EDIV_CMD_BAUDH_MAX  ((uint32_t)0x3)                                      // FSMC_EDIV_CMD_BAUDH最大值
#define FSMC_EDIV_CMD_BAUDH_POS  0                                                    // FSMC_EDIV_CMD_BAUDH起始位
#define FSMC_EDIV_CMD_BAUDH_MASK (uint32_t)((uint32_t)0x3 << FSMC_EDIV_CMD_BAUDH_POS) // FSMC_EDIV_CMD_BAUDH位掩码
#define FSMC_EDIV_CMD_BAUDH(x)   (uint32_t)(((x) & 0x3) << FSMC_EDIV_CMD_BAUDH_POS)   // [01:00] 指令部分波特率配置，高电平持续周期数 0：一个系统时钟周期 1：两个系统时钟周期 2：三个系统时钟周期 3：四个系统时钟周期

/* FSMC_WDAT0 On-Chip FLASH编程数据寄存器 */
#define FSMC_WDAT0_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                   // FSMC_WDAT0_WDATA最大值
#define FSMC_WDAT0_WDATA_POS  0                                                        // FSMC_WDAT0_WDATA起始位
#define FSMC_WDAT0_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_WDAT0_WDATA_POS) // FSMC_WDAT0_WDATA位掩码
#define FSMC_WDAT0_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_WDAT0_WDATA_POS)   // [31:0] On-Chip FLASH编程数据寄存器，BIT[031:000]

/* FSMC_WDAT1 On-Chip FLASH编程数据寄存器 */
#define FSMC_WDAT1_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                   // FSMC_WDAT1_WDATA最大值
#define FSMC_WDAT1_WDATA_POS  0                                                        // FSMC_WDAT1_WDATA起始位
#define FSMC_WDAT1_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_WDAT1_WDATA_POS) // FSMC_WDAT1_WDATA位掩码
#define FSMC_WDAT1_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_WDAT1_WDATA_POS)   // [31:0] On-Chip FLASH编程数据寄存器，BIT[063:032]

/* FSMC_WDAT2 On-Chip FLASH编程数据寄存器 */
#define FSMC_WDAT2_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                   // FSMC_WDAT2_WDATA最大值
#define FSMC_WDAT2_WDATA_POS  0                                                        // FSMC_WDAT2_WDATA起始位
#define FSMC_WDAT2_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_WDAT2_WDATA_POS) // FSMC_WDAT2_WDATA位掩码
#define FSMC_WDAT2_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_WDAT2_WDATA_POS)   // [31:0] On-Chip FLASH编程数据寄存器，BIT[095:064]

/* FSMC_WDAT3 On-Chip FLASH编程数据寄存器 */
#define FSMC_WDAT3_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                   // FSMC_WDAT3_WDATA最大值
#define FSMC_WDAT3_WDATA_POS  0                                                        // FSMC_WDAT3_WDATA起始位
#define FSMC_WDAT3_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_WDAT3_WDATA_POS) // FSMC_WDAT3_WDATA位掩码
#define FSMC_WDAT3_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_WDAT3_WDATA_POS)   // [31:0] On-Chip FLASH编程数据寄存器，BIT[127:096]

/* FSMC_ICFG On-Chip FLASH配置寄存器 */
#define FSMC_ICFG_ERS_EN_BIT   BIT31                                            // [31] On-Chip FLASH擦除使能。默认为0。 0：关闭擦除 1：开启擦除
#define FSMC_ICFG_PRG_EN_BIT   BIT27                                            // [27] On-Chip FLASH编程使能。默认为0。 0：关闭编程 1：开启编程
#define FSMC_ICFG_ADR_INC_BIT  BIT23                                            // [23] On-Chip FLASH地址递增使能。默认为0。 0：关闭递增使能 1：开启递增使能 当执行On-Chip FLASH连续读写访问时，开启此功能，可以减少对地址的操作。
#define FSMC_ICFG_SEL_PROT_BIT BIT19                                            // [19] On-Chip FLAS保护字选择 0：选择On-Chip FLASH存储体整体保护策略的保护字 1：选择ROM区域独有保护策略的保护字
#define FSMC_ICFG_REGION_BIT   BIT11                                            // [11] 访问On-Chip FLASH区域选择。默认为0。 0：MAIN/ROM（根据地址不同选择不同区域） 1：NVR
#define FSMC_ICFG_RETRY_EN_BIT BIT7                                             // [7] 快速擦除使能 0：关闭 1：使能
#define FSMC_ICFG_RETRY_MAX    ((uint32_t)0x3)                                  // FSMC_ICFG_RETRY最大值
#define FSMC_ICFG_RETRY_POS    2                                                // FSMC_ICFG_RETRY起始位
#define FSMC_ICFG_RETRY_MASK   (uint32_t)((uint32_t)0x3 << FSMC_ICFG_RETRY_POS) // FSMC_ICFG_RETRY位掩码
#define FSMC_ICFG_RETRY(x)     (uint32_t)(((x) & 0x3) << FSMC_ICFG_RETRY_POS)   // [3:2] 快速擦除计数器

/* FSMC_ADDR On-Chip FLASH地址寄存器 */
#define FSMC_ADDR_ADDR_MAX  ((uint32_t)0x3FFFF)                                 // FSMC_ADDR_ADDR最大值
#define FSMC_ADDR_ADDR_POS  0                                                   // FSMC_ADDR_ADDR起始位
#define FSMC_ADDR_ADDR_MASK (uint32_t)((uint32_t)0x3FFFF << FSMC_ADDR_ADDR_POS) // FSMC_ADDR_ADDR位掩码
#define FSMC_ADDR_ADDR(x)   (uint32_t)(((x) & 0x3FFFF) << FSMC_ADDR_ADDR_POS)   // [17:0] 地址寄存器。读/写/擦除操作对应的地址寄存器。 读取操作，一次读取32-BIT数据，ADDR的最低两位会被On-Chip FLASH控制器忽略。 编程操作，一次编程128-BIT数据，ADDR的最低四位会被On-Chip FLASH控制器忽略。 擦除操作，Sector大小为1024-Byte，执行Sector擦除时，ADDR的最低十位会被On-Chip FLASH控制器忽略。执行Full擦除时，ADDR的值被On-Chip FLASH控制器忽略。

/* FSMC_WDAT On-Chip FLASH编程操作触发寄存器 */
#define FSMC_WDAT_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                  // FSMC_WDAT_WDATA最大值
#define FSMC_WDAT_WDATA_POS  0                                                       // FSMC_WDAT_WDATA起始位
#define FSMC_WDAT_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_WDAT_WDATA_POS) // FSMC_WDAT_WDATA位掩码
#define FSMC_WDAT_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_WDAT_WDATA_POS)   // [31:0] 写入0x7654DCBA，触发On-Chip FLASH编程操作

/* FSMC_RDAT On-Chip FLASH读数据寄存器 */
#define FSMC_RDAT_RDATA_MAX  ((uint32_t)0xFFFFFFFF)                                  // FSMC_RDAT_RDATA最大值
#define FSMC_RDAT_RDATA_POS  0                                                       // FSMC_RDAT_RDATA起始位
#define FSMC_RDAT_RDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_RDAT_RDATA_POS) // FSMC_RDAT_RDATA位掩码
#define FSMC_RDAT_RDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_RDAT_RDATA_POS)   // [31:0] 执行读取操作，读出On-Chip FLASH对应地址的值

/* FSMC_ERAS On-Chip FLASH擦除操作触发寄存器 */
#define FSMC_ERAS_ERASE_MAX  ((uint32_t)0xFFFFFFFF)                                  // FSMC_ERAS_ERASE最大值
#define FSMC_ERAS_ERASE_POS  0                                                       // FSMC_ERAS_ERASE起始位
#define FSMC_ERAS_ERASE_MASK (uint32_t)((uint32_t)0xFFFFFFFF << FSMC_ERAS_ERASE_POS) // FSMC_ERAS_ERASE位掩码
#define FSMC_ERAS_ERASE(x)   (uint32_t)(((x) & 0xFFFFFFFF) << FSMC_ERAS_ERASE_POS)   // [31:0] 写入0x7654DCBA，触发On-Chip FLASH擦除操作

/* FSMC_PROT On-Chip FLASH保护状态寄存器 */
#define FSMC_PROT_RPROT_BIT BIT16 // [16] ROM区域独有保护策略的保护状态 0：未保护 1：保护中
#define FSMC_PROT_PROT_BIT  BIT0  // [0] On-Chip FLASH存储体整体保护策略的保护状态 0：未保护 1：保护中

/* FSMC_REDY On-Chip FLASH工作状态寄存器 */
#define FSMC_REDY_IREADY_BIT BIT8 // [8] S总线访问On-Chip FLASH状态 0：S总线在访问On-Chip FLASH，不接受S总线的发起新请求 1：S总线未访问On-Chip FLASH，可接受S总线的发起新请求
#define FSMC_REDY_READY_BIT  BIT0 // [0] I/D总线访问On-Chip FLASH状态 0：I/D总线在访问On-Chip FLASH，不接受I/D总线的发起新请求 1：I/D总线未访问On-Chip FLASH，可接受I/D总线的发起新请求

/* FSMC_IDIV On-Chip FLASH时基寄存器 */
#define FSMC_IDIV_BCNT1_MAX  ((uint32_t)0xFFFF)                                  // FSMC_IDIV_BCNT1最大值
#define FSMC_IDIV_BCNT1_POS  16                                                  // FSMC_IDIV_BCNT1起始位
#define FSMC_IDIV_BCNT1_MASK (uint32_t)((uint32_t)0xFFFF << FSMC_IDIV_BCNT1_POS) // FSMC_IDIV_BCNT1位掩码
#define FSMC_IDIV_BCNT1(x)   (uint32_t)(((x) & 0xFFFF) << FSMC_IDIV_BCNT1_POS)   // [31:16] On-Chip FLASH编程擦除时基寄存器1。不同系统频率，值可以微调。默认为0x5400，对应192M系统时钟。 192M：0x5400 096M：0x2A00 048M：0x1500 024M：0xA80
#define FSMC_IDIV_BCNT0_MAX  ((uint32_t)0x7F)                                    // FSMC_IDIV_BCNT0最大值
#define FSMC_IDIV_BCNT0_POS  8                                                   // FSMC_IDIV_BCNT0起始位
#define FSMC_IDIV_BCNT0_MASK (uint32_t)((uint32_t)0x7F << FSMC_IDIV_BCNT0_POS)   // FSMC_IDIV_BCNT0位掩码
#define FSMC_IDIV_BCNT0(x)   (uint32_t)(((x) & 0x7F) << FSMC_IDIV_BCNT0_POS)     // [14:08] On-Chip FLASH编程擦除时基寄存器0。默认值为0x40，不同时钟频率下该寄存器值不需要更改。
#define FSMC_IDIV_CKL_MAX    ((uint32_t)0xF)                                     // FSMC_IDIV_CKL最大值
#define FSMC_IDIV_CKL_POS    4                                                   // FSMC_IDIV_CKL起始位
#define FSMC_IDIV_CKL_MASK   (uint32_t)((uint32_t)0xF << FSMC_IDIV_CKL_POS)      // FSMC_IDIV_CKL位掩码
#define FSMC_IDIV_CKL(x)     (uint32_t)(((x) & 0xF) << FSMC_IDIV_CKL_POS)        // [07:04] On-Chip FLASH在读取操作时，内部基准时钟低电平的持续时间，这个值影响了读取操作中时钟信号低电平保持的周期数。该值仅可为0x1和0x2。 0x1：仅当系统频率低于96M，可使用的值，低电平保持2个系统周期。 0x2：默认值，当系统大于等于96M时，低电平保持3个系统时钟周期。
#define FSMC_IDIV_CKH_MAX    ((uint32_t)0xF)                                     // FSMC_IDIV_CKH最大值
#define FSMC_IDIV_CKH_POS    0                                                   // FSMC_IDIV_CKH起始位
#define FSMC_IDIV_CKH_MASK   (uint32_t)((uint32_t)0xF << FSMC_IDIV_CKH_POS)      // FSMC_IDIV_CKH位掩码
#define FSMC_IDIV_CKH(x)     (uint32_t)(((x) & 0xF) << FSMC_IDIV_CKH_POS)        // [03:00] On-Chip FLASH在读取操作时，内部基准时钟高电平的持续时间，这个值影响了读取操作中时钟信号高电平保持的周期数。该值仅可为0x1和0x2。 0x1：仅当系统频率低于96M，可使用的值，高电平保持2个系统周期。 0x2：默认值，当系统大于等于96M时，高电平保持3个系统时钟周期

/* DMA_CTRL DMA控制寄存器 */
#define DMA_CTRL_EN_BIT BIT0 // [0] DMA使能

/* DMA_IE DMA中断使能寄存器 */
#define DMA_IE_CH7_FIE_BIT BIT7 // [7] 通道7完成中断使能
#define DMA_IE_CH6_FIE_BIT BIT6 // [6] 通道6完成中断使能
#define DMA_IE_CH5_FIE_BIT BIT5 // [5] 通道5完成中断使能
#define DMA_IE_CH4_FIE_BIT BIT4 // [4] 通道4完成中断使能
#define DMA_IE_CH3_FIE_BIT BIT3 // [3] 通道3完成中断使能
#define DMA_IE_CH2_FIE_BIT BIT2 // [2] 通道2完成中断使能
#define DMA_IE_CH1_FIE_BIT BIT1 // [1] 通道1完成中断使能
#define DMA_IE_CH0_FIE_BIT BIT0 // [0] 通道0完成中断使能

/* DMA_IF DMA中断标志寄存器 */
#define DMA_IF_CH7_FIF_BIT BIT7 // [7] 通道7完成中断标志，高有效，写1清零
#define DMA_IF_CH6_FIF_BIT BIT6 // [6] 通道6完成中断标志，高有效，写1清零
#define DMA_IF_CH5_FIF_BIT BIT5 // [5] 通道5完成中断标志，高有效，写1清零
#define DMA_IF_CH4_FIF_BIT BIT4 // [4] 通道4完成中断标志，高有效，写1清零
#define DMA_IF_CH3_FIF_BIT BIT3 // [3] 通道3完成中断标志，高有效，写1清零
#define DMA_IF_CH2_FIF_BIT BIT2 // [2] 通道2完成中断标志，高有效，写1清零
#define DMA_IF_CH1_FIF_BIT BIT1 // [1] 通道1完成中断标志，高有效，写1清零
#define DMA_IF_CH0_FIF_BIT BIT0 // [0] 通道0完成中断标志，高有效，写1清零

/* DMA_CCRx (x =0,1,2,3,4,5,6,7) */
#define DMA_CCRx_SBTW_MAX  ((uint32_t)0x3)                                // DMA_CCRx_SBTW最大值
#define DMA_CCRx_SBTW_POS  10                                             // DMA_CCRx_SBTW起始位
#define DMA_CCRx_SBTW_MASK (uint32_t)((uint32_t)0x3 << DMA_CCRx_SBTW_POS) // DMA_CCRx_SBTW位掩码
#define DMA_CCRx_SBTW(x)   (uint32_t)(((x) & 0x3) << DMA_CCRx_SBTW_POS)   // [11:10] 源地址访问位宽 0: Byte 1: Halfword 2: Word 3: 保留
#define DMA_CCRx_DBTW_MAX  ((uint32_t)0x3)                                // DMA_CCRx_DBTW最大值
#define DMA_CCRx_DBTW_POS  8                                              // DMA_CCRx_DBTW起始位
#define DMA_CCRx_DBTW_MASK (uint32_t)((uint32_t)0x3 << DMA_CCRx_DBTW_POS) // DMA_CCRx_DBTW位掩码
#define DMA_CCRx_DBTW(x)   (uint32_t)(((x) & 0x3) << DMA_CCRx_DBTW_POS)   // [9:8] 目的地址访问位宽 0:Byte 1:Halfword 2:Word 3:保留
#define DMA_CCRx_SINC_BIT  BIT6                                           // [6] 源地址递增方式 0:不递增 1:每传输一次，地址按照SBTW对应大小递增1/2/4
#define DMA_CCRx_DINC_BIT  BIT4                                           // [4] 目的地址递增方式 0:不递增 1:每传输一次，地址按照DBTW对应大小递增1/2/4
#define DMA_CCRx_CIRC_BIT  BIT3                                           // [3] 循环模式，高有效
#define DMA_CCRx_RMODE_BIT BIT1                                           // [1] 0:单轮传输，一轮连续传输多次，每收到DMA请求传输一轮，一个DMA请求即传输完毕 1:多轮传输，每轮进行一次数据传输，每收到DMA请求传输一轮，多个DMA请求才传输完毕 不支持多轮×多次传输
#define DMA_CCRx_EN_BIT    BIT0                                           // [0] 通道使能，高有效，软件置1开启通道进行DMA搬运操作，搬运完成后DMA硬件将此位清零

/* DMA_RENx (x = 0,1,2,3,4,5,6,7) */
#define DMA_RENx_SW_TRIG_BIT   BIT31 // [31] 软复位请求使能
#define DMA_RENx_GPIO_TRIG_BIT BIT29 // [29] GPIO请求使能
#define DMA_RENx_FMAC_Y_BIT    BIT28 // [28] FMAC Y
#define DMA_RENx_FMAC_X1_BIT   BIT27 // [27] FMAC X1
#define DMA_RENx_CMP_BIT       BIT26 // [26] 比较器
#define DMA_RENx_HALL1_BIT     BIT25 // [25] HALL1
#define DMA_RENx_HALL0_BIT     BIT24 // [24] HALL0
#define DMA_RENx_I2C1_TX_BIT   BIT23 // [23] I2C1发送
#define DMA_RENx_I2C1_RX_BIT   BIT22 // [22] I2C1接收
#define DMA_RENx_UART2_TX_BIT  BIT21 // [21] UART2发送
#define DMA_RENx_UART2_RX_BIT  BIT20 // [20] UART2接收
#define DMA_RENx_UART1_TX_BIT  BIT19 // [19] UART1发送
#define DMA_RENx_UART1_RX_BIT  BIT18 // [18] UART1接收
#define DMA_RENx_UART0_TX_BIT  BIT17 // [17] UART0发送
#define DMA_RENx_UART0_RX_BIT  BIT16 // [16] UART0接收
#define DMA_RENx_I2C0_TX_BIT   BIT15 // [15] I2C0发送
#define DMA_RENx_I2C0_RX_BIT   BIT14 // [14] I2C0接收
#define DMA_RENx_MCPWM1_BIT    BIT13 // [13] MCPWM1
#define DMA_RENx_MCPWM0_BIT    BIT12 // [12] MCPWM0
#define DMA_RENx_SPI1_TX_BIT   BIT11 // [11] SPI1发送
#define DMA_RENx_SPI1_RX_BIT   BIT10 // [10] SPI1接收
#define DMA_RENx_SPI0_TX_BIT   BIT9  // [9] SPI0发送
#define DMA_RENx_SPI0_RX_BIT   BIT8  // [8] SPI0接收
#define DMA_RENx_TIMER4_BIT    BIT7  // [7] TIMER4
#define DMA_RENx_TIMER3_BIT    BIT6  // [6] TIMER3
#define DMA_RENx_TIMER2_BIT    BIT5  // [5] TIMER2
#define DMA_RENx_TIMER1_BIT    BIT4  // [4] TIMER1
#define DMA_RENx_TIMER0_BIT    BIT3  // [3] TIMER0
#define DMA_RENx_ADC2_BIT      BIT2  // [2] ADC2
#define DMA_RENx_ADC1_BIT      BIT1  // [1] ADC1
#define DMA_RENx_ADC0_BIT      BIT0  // [0] ADC0

/* DMA_CTMSx (x = 0,1,2,3,4,5,6,7) */
#define DMA_CTMSx_TIMES_MAX  ((uint32_t)0xFFFF)                                  // DMA_CTMSx_TIMES最大值
#define DMA_CTMSx_TIMES_POS  0                                                   // DMA_CTMSx_TIMES起始位
#define DMA_CTMSx_TIMES_MASK (uint32_t)((uint32_t)0xFFFF << DMA_CTMSx_TIMES_POS) // DMA_CTMSx_TIMES位掩码
#define DMA_CTMSx_TIMES(x)   (uint32_t)(((x) & 0xFFFF) << DMA_CTMSx_TIMES_POS)   // [15:0] DMA通道x数据搬运次数。此寄存器在该通道使能后变为只读。

/* DMA_SADRx (x = 0,1,2,3,4,5,6,7) */
#define DMA_SADRx_ADDR_MAX  ((uint32_t)0xFFFFFFFF)                                 // DMA_SADRx_ADDR最大值
#define DMA_SADRx_ADDR_POS  0                                                      // DMA_SADRx_ADDR起始位
#define DMA_SADRx_ADDR_MASK (uint32_t)((uint32_t)0xFFFFFFFF << DMA_SADRx_ADDR_POS) // DMA_SADRx_ADDR位掩码
#define DMA_SADRx_ADDR(x)   (uint32_t)(((x) & 0xFFFFFFFF) << DMA_SADRx_ADDR_POS)   // [31:0] DMA通道x源地址

/* DMA_DADRx (x = 0,1,2,3,4,5,6,7) */
#define DMA_DADRx_ADDR_MAX  ((uint32_t)0xFFFFFFFF)                                 // DMA_DADRx_ADDR最大值
#define DMA_DADRx_ADDR_POS  0                                                      // DMA_DADRx_ADDR起始位
#define DMA_DADRx_ADDR_MASK (uint32_t)((uint32_t)0xFFFFFFFF << DMA_DADRx_ADDR_POS) // DMA_DADRx_ADDR位掩码
#define DMA_DADRx_ADDR(x)   (uint32_t)(((x) & 0xFFFFFFFF) << DMA_DADRx_ADDR_POS)   // [31:0] DMA通道x目的地址

/* GPIOx_PIE(x = 0,1,2,3,4,5) */
#define GPIOx_PIE_PIE15_BIT BIT15 // [15] GPIO x[15]/ Px[15]输入使能
#define GPIOx_PIE_PIE14_BIT BIT14 // [14] GPIO x[14]/ Px[14]输入使能
#define GPIOx_PIE_PIE13_BIT BIT13 // [13] GPIO x[13]/ Px[13]输入使能
#define GPIOx_PIE_PIE12_BIT BIT12 // [12] GPIO x[12]/ Px[12]输入使能
#define GPIOx_PIE_PIE11_BIT BIT11 // [11] GPIO x[11]/ Px[11]输入使能
#define GPIOx_PIE_PIE10_BIT BIT10 // [10] GPIO x[10]/ Px[10]输入使能
#define GPIOx_PIE_PIE9_BIT  BIT9  // [9] GPIO x[9]/ Px[9]输入使能
#define GPIOx_PIE_PIE8_BIT  BIT8  // [8] GPIO x[8]/ Px[8]输入使能
#define GPIOx_PIE_PIE7_BIT  BIT7  // [7] GPIO x[7]/ Px[7]输入使能
#define GPIOx_PIE_PIE6_BIT  BIT6  // [6] GPIO x[6]/ Px[6]输入使能
#define GPIOx_PIE_PIE5_BIT  BIT5  // [5] GPIO x[5]/ Px[5]输入使能
#define GPIOx_PIE_PIE4_BIT  BIT4  // [4] GPIO x[4]/ Px[4]输入使能
#define GPIOx_PIE_PIE3_BIT  BIT3  // [3] GPIO x[3]/ Px[3]输入使能
#define GPIOx_PIE_PIE2_BIT  BIT2  // [2] GPIO x[2]/ Px[2]输入使能
#define GPIOx_PIE_PIE1_BIT  BIT1  // [1] GPIO x[1]/ Px[1]输入使能
#define GPIOx_PIE_PIE0_BIT  BIT0  // [0] GPIO x[0]/ Px[0]输入使能

/* GPIOx_POE(x = 0,1,2,3,4,5) */
#define GPIOx_POE_POE15_BIT BIT15 // [15] GPIO x[15]/ Px[15]输出使能
#define GPIOx_POE_POE14_BIT BIT14 // [14] GPIO x[14]/ Px[14]输出使能
#define GPIOx_POE_POE13_BIT BIT13 // [13] GPIO x[13]/ Px[13]输出使能
#define GPIOx_POE_POE12_BIT BIT12 // [12] GPIO x[12]/ Px[12]输出使能
#define GPIOx_POE_POE11_BIT BIT11 // [11] GPIO x[11]/ Px[11]输出使能
#define GPIOx_POE_POE10_BIT BIT10 // [10] GPIO x[10]/ Px[10]输出使能
#define GPIOx_POE_POE9_BIT  BIT9  // [9] GPIO x[9]/ Px[9]输出使能
#define GPIOx_POE_POE8_BIT  BIT8  // [8] GPIO x[8]/ Px[8]输出使能
#define GPIOx_POE_POE7_BIT  BIT7  // [7] GPIO x[7]/ Px[7]输出使能
#define GPIOx_POE_POE6_BIT  BIT6  // [6] GPIO x[6]/ Px[6]输出使能
#define GPIOx_POE_POE5_BIT  BIT5  // [5] GPIO x[5]/ Px[5]输出使能
#define GPIOx_POE_POE4_BIT  BIT4  // [4] GPIO x[4]/ Px[4]输出使能
#define GPIOx_POE_POE3_BIT  BIT3  // [3] GPIO x[3]/ Px[3]输出使能
#define GPIOx_POE_POE2_BIT  BIT2  // [2] GPIO x[2]/ Px[2]输出使能
#define GPIOx_POE_POE1_BIT  BIT1  // [1] GPIO x[1]/ Px[1]输出使能
#define GPIOx_POE_POE0_BIT  BIT0  // [0] GPIO x[0]/ Px[0]输出使能

/* GPIOx_PDI(x = 0,1,2,3,4,5) */
#define GPIOx_PDI_PDI_MAX  ((uint32_t)0xFFFF)                                // GPIOx_PDI_PDI最大值
#define GPIOx_PDI_PDI_POS  0                                                 // GPIOx_PDI_PDI起始位
#define GPIOx_PDI_PDI_MASK (uint32_t)((uint32_t)0xFFFF << GPIOx_PDI_PDI_POS) // GPIOx_PDI_PDI位掩码
#define GPIOx_PDI_PDI(x)   (uint32_t)(((x) & 0xFFFF) << GPIOx_PDI_PDI_POS)   // [15:0] GPIO x输入数据

/* GPIOx_PDO(x = 0,1,2,3,4,5) */
#define GPIOx_PDO_PDO_MAX  ((uint32_t)0xFFFF)                                // GPIOx_PDO_PDO最大值
#define GPIOx_PDO_PDO_POS  0                                                 // GPIOx_PDO_PDO起始位
#define GPIOx_PDO_PDO_MASK (uint32_t)((uint32_t)0xFFFF << GPIOx_PDO_PDO_POS) // GPIOx_PDO_PDO位掩码
#define GPIOx_PDO_PDO(x)   (uint32_t)(((x) & 0xFFFF) << GPIOx_PDO_PDO_POS)   // [15:0] GPIO x输出数据

/* GPIOx_PUE(x = 0,1,2,3,4,5) */
#define GPIOx_PUE_PUE15_BIT BIT15 // [15] GPIO x[15]/ Px[15]上拉使能
#define GPIOx_PUE_PUE14_BIT BIT14 // [14] GPIO x[14]/ Px[14]上拉使能
#define GPIOx_PUE_PUE13_BIT BIT13 // [13] GPIO x[13]/ Px[13]上拉使能
#define GPIOx_PUE_PUE12_BIT BIT12 // [12] GPIO x[12]/ Px[12]上拉使能
#define GPIOx_PUE_PUE11_BIT BIT11 // [11] GPIO x[11]/ Px[11]上拉使能
#define GPIOx_PUE_PUE10_BIT BIT10 // [10] GPIO x[10]/ Px[10]上拉使能
#define GPIOx_PUE_PUE9_BIT  BIT9  // [9] GPIO x[9]/ Px[9]上拉使能
#define GPIOx_PUE_PUE8_BIT  BIT8  // [8] GPIO x[8]/ Px[8]上拉使能
#define GPIOx_PUE_PUE7_BIT  BIT7  // [7] GPIO x[7]/ Px[7]上拉使能
#define GPIOx_PUE_PUE6_BIT  BIT6  // [6] GPIO x[6]/ Px[6]上拉使能
#define GPIOx_PUE_PUE5_BIT  BIT5  // [5] GPIO x[5]/ Px[5]上拉使能
#define GPIOx_PUE_PUE4_BIT  BIT4  // [4] GPIO x[4]/ Px[4]上拉使能
#define GPIOx_PUE_PUE3_BIT  BIT3  // [3] GPIO x[3]/ Px[3]上拉使能
#define GPIOx_PUE_PUE2_BIT  BIT2  // [2] GPIO x[2]/ Px[2]上拉使能
#define GPIOx_PUE_PUE1_BIT  BIT1  // [1] GPIO x[1]/ Px[1]上拉使能
#define GPIOx_PUE_PUE0_BIT  BIT0  // [0] GPIO x[0]/ Px[0]上拉使能

/* GPIOx_PDE(x = 0,1,2,3,4,5) */
#define GPIOx_PDE_PDE15_BIT BIT15 // [15] GPIO x[15]/ Px[15]下拉使能
#define GPIOx_PDE_PDE14_BIT BIT14 // [14] GPIO x[14]/ Px[14]下拉使能
#define GPIOx_PDE_PDE13_BIT BIT13 // [13] GPIO x[13]/ Px[13]下拉使能
#define GPIOx_PDE_PDE12_BIT BIT12 // [12] GPIO x[12]/ Px[12]下拉使能
#define GPIOx_PDE_PDE11_BIT BIT11 // [11] GPIO x[11]/ Px[11]下拉使能
#define GPIOx_PDE_PDE10_BIT BIT10 // [10] GPIO x[10]/ Px[10]下拉使能
#define GPIOx_PDE_PDE9_BIT  BIT9  // [9] GPIO x[9]/ Px[9]下拉使能
#define GPIOx_PDE_PDE8_BIT  BIT8  // [8] GPIO x[8]/ Px[8]下拉使能
#define GPIOx_PDE_PDE7_BIT  BIT7  // [7] GPIO x[7]/ Px[7]下拉使能
#define GPIOx_PDE_PDE6_BIT  BIT6  // [6] GPIO x[6]/ Px[6]下拉使能
#define GPIOx_PDE_PDE5_BIT  BIT5  // [5] GPIO x[5]/ Px[5]下拉使能
#define GPIOx_PDE_PDE4_BIT  BIT4  // [4] GPIO x[4]/ Px[4]下拉使能
#define GPIOx_PDE_PDE3_BIT  BIT3  // [3] GPIO x[3]/ Px[3]下拉使能
#define GPIOx_PDE_PDE2_BIT  BIT2  // [2] GPIO x[2]/ Px[2]下拉使能
#define GPIOx_PDE_PDE1_BIT  BIT1  // [1] GPIO x[1]/ Px[1]下拉使能
#define GPIOx_PDE_PDE0_BIT  BIT0  // [0] GPIO x[0]/ Px[0]下拉使能

/* GPIOx_PODE(x = 0,1,2,3,4,5) */
#define GPIOx_PODE_PODE15_BIT BIT15 // [15] GPIO x[15]/ Px[15]开漏使能
#define GPIOx_PODE_PODE14_BIT BIT14 // [14] GPIO x[14]/ Px[14]开漏使能
#define GPIOx_PODE_PODE13_BIT BIT13 // [13] GPIO x[13]/ Px[13]开漏使能
#define GPIOx_PODE_PODE12_BIT BIT12 // [12] GPIO x[12]/ Px[12]开漏使能
#define GPIOx_PODE_PODE11_BIT BIT11 // [11] GPIO x[11]/ Px[11]开漏使能
#define GPIOx_PODE_PODE10_BIT BIT10 // [10] GPIO x[10]/ Px[10]开漏使能
#define GPIOx_PODE_PODE9_BIT  BIT9  // [9] GPIO x[9]/ Px[9]开漏使能
#define GPIOx_PODE_PODE8_BIT  BIT8  // [8] GPIO x[8]/ Px[8]开漏使能
#define GPIOx_PODE_PODE7_BIT  BIT7  // [7] GPIO x[7]/ Px[7]开漏使能
#define GPIOx_PODE_PODE6_BIT  BIT6  // [6] GPIO x[6]/ Px[6]开漏使能
#define GPIOx_PODE_PODE5_BIT  BIT5  // [5] GPIO x[5]/ Px[5]开漏使能
#define GPIOx_PODE_PODE4_BIT  BIT4  // [4] GPIO x[4]/ Px[4]开漏使能
#define GPIOx_PODE_PODE3_BIT  BIT3  // [3] GPIO x[3]/ Px[3]开漏使能
#define GPIOx_PODE_PODE2_BIT  BIT2  // [2] GPIO x[2]/ Px[2]开漏使能
#define GPIOx_PODE_PODE1_BIT  BIT1  // [1] GPIO x[1]/ Px[1]开漏使能
#define GPIOx_PODE_PODE0_BIT  BIT0  // [0] GPIO x[0]/ Px[0]开漏使能

/* GPIOx_PFLT(x = 0,1,2,3,4,5) */
#define GPIOx_PFLT_PFLT15_BIT BIT15 // [15] GPIO x[15]/ Px[15]配置滤波
#define GPIOx_PFLT_PFLT14_BIT BIT14 // [14] GPIO x[14]/ Px[14]配置滤波
#define GPIOx_PFLT_PFLT13_BIT BIT13 // [13] GPIO x[13]/ Px[13]配置滤波
#define GPIOx_PFLT_PFLT12_BIT BIT12 // [12] GPIO x[12]/ Px[12]配置滤波
#define GPIOx_PFLT_PFLT11_BIT BIT11 // [11] GPIO x[11]/ Px[11]配置滤波
#define GPIOx_PFLT_PFLT10_BIT BIT10 // [10] GPIO x[10]/ Px[10]配置滤波
#define GPIOx_PFLT_PFLT9_BIT  BIT9  // [9] GPIO x[9]/ Px[9]配置滤波
#define GPIOx_PFLT_PFLT8_BIT  BIT8  // [8] GPIO x[8]/ Px[8]配置滤波
#define GPIOx_PFLT_PFLT7_BIT  BIT7  // [7] GPIO x[7]/ Px[7]配置滤波
#define GPIOx_PFLT_PFLT6_BIT  BIT6  // [6] GPIO x[6]/ Px[6]配置滤波
#define GPIOx_PFLT_PFLT5_BIT  BIT5  // [5] GPIO x[5]/ Px[5]配置滤波
#define GPIOx_PFLT_PFLT4_BIT  BIT4  // [4] GPIO x[4]/ Px[4]配置滤波
#define GPIOx_PFLT_PFLT3_BIT  BIT3  // [3] GPIO x[3]/ Px[3]配置滤波
#define GPIOx_PFLT_PFLT2_BIT  BIT2  // [2] GPIO x[2]/ Px[2]配置滤波
#define GPIOx_PFLT_PFLT1_BIT  BIT1  // [1] GPIO x[1]/ Px[1]配置滤波
#define GPIOx_PFLT_PFLT0_BIT  BIT0  // [0] GPIO x[0]/ Px[0]配置滤波

/* GPIOx_F3210(x = 0,1,2,3,4,5) */
#define GPIOx_F3210_F3_MAX  ((uint32_t)0xF)                                 // GPIOx_F3210_F3最大值
#define GPIOx_F3210_F3_POS  12                                              // GPIOx_F3210_F3起始位
#define GPIOx_F3210_F3_MASK (uint32_t)((uint32_t)0xF << GPIOx_F3210_F3_POS) // GPIOx_F3210_F3位掩码
#define GPIOx_F3210_F3(x)   (uint32_t)(((x) & 0xF) << GPIOx_F3210_F3_POS)   // [15:12] GPIO x[3]/ Px[3]功能选择
#define GPIOx_F3210_F2_MAX  ((uint32_t)0xF)                                 // GPIOx_F3210_F2最大值
#define GPIOx_F3210_F2_POS  8                                               // GPIOx_F3210_F2起始位
#define GPIOx_F3210_F2_MASK (uint32_t)((uint32_t)0xF << GPIOx_F3210_F2_POS) // GPIOx_F3210_F2位掩码
#define GPIOx_F3210_F2(x)   (uint32_t)(((x) & 0xF) << GPIOx_F3210_F2_POS)   // [11:8] GPIO x[2]/ Px[2]功能选择
#define GPIOx_F3210_F1_MAX  ((uint32_t)0xF)                                 // GPIOx_F3210_F1最大值
#define GPIOx_F3210_F1_POS  4                                               // GPIOx_F3210_F1起始位
#define GPIOx_F3210_F1_MASK (uint32_t)((uint32_t)0xF << GPIOx_F3210_F1_POS) // GPIOx_F3210_F1位掩码
#define GPIOx_F3210_F1(x)   (uint32_t)(((x) & 0xF) << GPIOx_F3210_F1_POS)   // [7:4] GPIO x[1]/ Px[1]功能选择
#define GPIOx_F3210_F0_MAX  ((uint32_t)0xF)                                 // GPIOx_F3210_F0最大值
#define GPIOx_F3210_F0_POS  0                                               // GPIOx_F3210_F0起始位
#define GPIOx_F3210_F0_MASK (uint32_t)((uint32_t)0xF << GPIOx_F3210_F0_POS) // GPIOx_F3210_F0位掩码
#define GPIOx_F3210_F0(x)   (uint32_t)(((x) & 0xF) << GPIOx_F3210_F0_POS)   // [3:0] GPIO x[0]/ Px[0]功能选择

/* GPIOx_F7654(x = 0,1,2,3,4,5) */
#define GPIOx_F7654_F7_MAX  ((uint32_t)0xF)                                 // GPIOx_F7654_F7最大值
#define GPIOx_F7654_F7_POS  12                                              // GPIOx_F7654_F7起始位
#define GPIOx_F7654_F7_MASK (uint32_t)((uint32_t)0xF << GPIOx_F7654_F7_POS) // GPIOx_F7654_F7位掩码
#define GPIOx_F7654_F7(x)   (uint32_t)(((x) & 0xF) << GPIOx_F7654_F7_POS)   // [15:12] GPIO x[7]/ Px[7]功能选择
#define GPIOx_F7654_F6_MAX  ((uint32_t)0xF)                                 // GPIOx_F7654_F6最大值
#define GPIOx_F7654_F6_POS  8                                               // GPIOx_F7654_F6起始位
#define GPIOx_F7654_F6_MASK (uint32_t)((uint32_t)0xF << GPIOx_F7654_F6_POS) // GPIOx_F7654_F6位掩码
#define GPIOx_F7654_F6(x)   (uint32_t)(((x) & 0xF) << GPIOx_F7654_F6_POS)   // [11:8] GPIO x[6]/ Px[6]功能选择
#define GPIOx_F7654_F5_MAX  ((uint32_t)0xF)                                 // GPIOx_F7654_F5最大值
#define GPIOx_F7654_F5_POS  4                                               // GPIOx_F7654_F5起始位
#define GPIOx_F7654_F5_MASK (uint32_t)((uint32_t)0xF << GPIOx_F7654_F5_POS) // GPIOx_F7654_F5位掩码
#define GPIOx_F7654_F5(x)   (uint32_t)(((x) & 0xF) << GPIOx_F7654_F5_POS)   // [7:4] GPIO x[5]/ Px[5]功能选择
#define GPIOx_F7654_F4_MAX  ((uint32_t)0xF)                                 // GPIOx_F7654_F4最大值
#define GPIOx_F7654_F4_POS  0                                               // GPIOx_F7654_F4起始位
#define GPIOx_F7654_F4_MASK (uint32_t)((uint32_t)0xF << GPIOx_F7654_F4_POS) // GPIOx_F7654_F4位掩码
#define GPIOx_F7654_F4(x)   (uint32_t)(((x) & 0xF) << GPIOx_F7654_F4_POS)   // [3:0] GPIO x[4]/ Px[4]功能选择

/* GPIOx_FBA98(x = 0,1,2,3,4,5) */
#define GPIOx_FBA98_F11_MAX  ((uint32_t)0xF)                                  // GPIOx_FBA98_F11最大值
#define GPIOx_FBA98_F11_POS  12                                               // GPIOx_FBA98_F11起始位
#define GPIOx_FBA98_F11_MASK (uint32_t)((uint32_t)0xF << GPIOx_FBA98_F11_POS) // GPIOx_FBA98_F11位掩码
#define GPIOx_FBA98_F11(x)   (uint32_t)(((x) & 0xF) << GPIOx_FBA98_F11_POS)   // [15:12] GPIO x[11]/ Px[11]功能选择
#define GPIOx_FBA98_F10_MAX  ((uint32_t)0xF)                                  // GPIOx_FBA98_F10最大值
#define GPIOx_FBA98_F10_POS  8                                                // GPIOx_FBA98_F10起始位
#define GPIOx_FBA98_F10_MASK (uint32_t)((uint32_t)0xF << GPIOx_FBA98_F10_POS) // GPIOx_FBA98_F10位掩码
#define GPIOx_FBA98_F10(x)   (uint32_t)(((x) & 0xF) << GPIOx_FBA98_F10_POS)   // [11:8] GPIO x[10]/ Px[10]功能选择
#define GPIOx_FBA98_F9_MAX   ((uint32_t)0xF)                                  // GPIOx_FBA98_F9最大值
#define GPIOx_FBA98_F9_POS   4                                                // GPIOx_FBA98_F9起始位
#define GPIOx_FBA98_F9_MASK  (uint32_t)((uint32_t)0xF << GPIOx_FBA98_F9_POS)  // GPIOx_FBA98_F9位掩码
#define GPIOx_FBA98_F9(x)    (uint32_t)(((x) & 0xF) << GPIOx_FBA98_F9_POS)    // [7:4] GPIO x[9]/ Px[9]功能选择
#define GPIOx_FBA98_F8_MAX   ((uint32_t)0xF)                                  // GPIOx_FBA98_F8最大值
#define GPIOx_FBA98_F8_POS   0                                                // GPIOx_FBA98_F8起始位
#define GPIOx_FBA98_F8_MASK  (uint32_t)((uint32_t)0xF << GPIOx_FBA98_F8_POS)  // GPIOx_FBA98_F8位掩码
#define GPIOx_FBA98_F8(x)    (uint32_t)(((x) & 0xF) << GPIOx_FBA98_F8_POS)    // [3:0] GPIO x[8]/ Px[8]功能选择

/* GPIOx_FFEDC(x = 0,1,2,3,4,5) */
#define GPIOx_FFEDC_F15_MAX  ((uint32_t)0xF)                                  // GPIOx_FFEDC_F15最大值
#define GPIOx_FFEDC_F15_POS  12                                               // GPIOx_FFEDC_F15起始位
#define GPIOx_FFEDC_F15_MASK (uint32_t)((uint32_t)0xF << GPIOx_FFEDC_F15_POS) // GPIOx_FFEDC_F15位掩码
#define GPIOx_FFEDC_F15(x)   (uint32_t)(((x) & 0xF) << GPIOx_FFEDC_F15_POS)   // [15:12] GPIO x[15]/ Px[15]功能选择
#define GPIOx_FFEDC_F14_MAX  ((uint32_t)0xF)                                  // GPIOx_FFEDC_F14最大值
#define GPIOx_FFEDC_F14_POS  8                                                // GPIOx_FFEDC_F14起始位
#define GPIOx_FFEDC_F14_MASK (uint32_t)((uint32_t)0xF << GPIOx_FFEDC_F14_POS) // GPIOx_FFEDC_F14位掩码
#define GPIOx_FFEDC_F14(x)   (uint32_t)(((x) & 0xF) << GPIOx_FFEDC_F14_POS)   // [11:8] GPIO x[14]/ Px[14]功能选择
#define GPIOx_FFEDC_F13_MAX  ((uint32_t)0xF)                                  // GPIOx_FFEDC_F13最大值
#define GPIOx_FFEDC_F13_POS  4                                                // GPIOx_FFEDC_F13起始位
#define GPIOx_FFEDC_F13_MASK (uint32_t)((uint32_t)0xF << GPIOx_FFEDC_F13_POS) // GPIOx_FFEDC_F13位掩码
#define GPIOx_FFEDC_F13(x)   (uint32_t)(((x) & 0xF) << GPIOx_FFEDC_F13_POS)   // [7:4] GPIO x[13]/ Px[13]功能选择
#define GPIOx_FFEDC_F12_MAX  ((uint32_t)0xF)                                  // GPIOx_FFEDC_F12最大值
#define GPIOx_FFEDC_F12_POS  0                                                // GPIOx_FFEDC_F12起始位
#define GPIOx_FFEDC_F12_MASK (uint32_t)((uint32_t)0xF << GPIOx_FFEDC_F12_POS) // GPIOx_FFEDC_F12位掩码
#define GPIOx_FFEDC_F12(x)   (uint32_t)(((x) & 0xF) << GPIOx_FFEDC_F12_POS)   // [3:0] GPIO x[12]/ Px[12]功能选择

/* GPIOx_BSRR(x = 0,1,2,3,4,5) */
#define GPIOx_BSRR_CLR15_BIT BIT31 // [31] 写1将GPIO x[15]清零，写0无作用
#define GPIOx_BSRR_CLR14_BIT BIT30 // [30] 写1将GPIO x[14]清零，写0无作用
#define GPIOx_BSRR_CLR13_BIT BIT29 // [29] 写1将GPIO x[13]清零，写0无作用
#define GPIOx_BSRR_CLR12_BIT BIT28 // [28] 写1将GPIO x[12]清零，写0无作用
#define GPIOx_BSRR_CLR11_BIT BIT27 // [27] 写1将GPIO x[11]清零，写0无作用
#define GPIOx_BSRR_CLR10_BIT BIT26 // [26] 写1将GPIO x[10]清零，写0无作用
#define GPIOx_BSRR_CLR9_BIT  BIT25 // [25] 写1将GPIO x[9]清零，写0无作用
#define GPIOx_BSRR_CLR8_BIT  BIT24 // [24] 写1将GPIO x[8]清零，写0无作用
#define GPIOx_BSRR_CLR7_BIT  BIT23 // [23] 写1将GPIO x[7]清零，写0无作用
#define GPIOx_BSRR_CLR6_BIT  BIT22 // [22] 写1将GPIO x[6]清零，写0无作用
#define GPIOx_BSRR_CLR5_BIT  BIT21 // [21] 写1将GPIO x[5]清零，写0无作用
#define GPIOx_BSRR_CLR4_BIT  BIT20 // [20] 写1将GPIO x[4]清零，写0无作用
#define GPIOx_BSRR_CLR3_BIT  BIT19 // [19] 写1将GPIO x[3]清零，写0无作用
#define GPIOx_BSRR_CLR2_BIT  BIT18 // [18] 写1将GPIO x[2]清零，写0无作用
#define GPIOx_BSRR_CLR1_BIT  BIT17 // [17] 写1将GPIO x[1]清零，写0无作用
#define GPIOx_BSRR_CLR0_BIT  BIT16 // [16] 写1将GPIO x[0]清零，写0无作用
#define GPIOx_BSRR_SET15_BIT BIT15 // [15] 写1将GPIO x[15]置1，写0无作用
#define GPIOx_BSRR_SET14_BIT BIT14 // [14] 写1将GPIO x[14]置1，写0无作用
#define GPIOx_BSRR_SET13_BIT BIT13 // [13] 写1将GPIO x[13]置1，写0无作用
#define GPIOx_BSRR_SET12_BIT BIT12 // [12] 写1将GPIO x[12]置1，写0无作用
#define GPIOx_BSRR_SET11_BIT BIT11 // [11] 写1将GPIO x[11]置1，写0无作用
#define GPIOx_BSRR_SET10_BIT BIT10 // [10] 写1将GPIO x[10]置1，写0无作用
#define GPIOx_BSRR_SET9_BIT  BIT9  // [9] 写1将GPIO x[9]置1，写0无作用
#define GPIOx_BSRR_SET8_BIT  BIT8  // [8] 写1将GPIO x[8]置1，写0无作用
#define GPIOx_BSRR_SET7_BIT  BIT7  // [7] 写1将GPIO x[7]置1，写0无作用
#define GPIOx_BSRR_SET6_BIT  BIT6  // [6] 写1将GPIO x[6]置1，写0无作用
#define GPIOx_BSRR_SET5_BIT  BIT5  // [5] 写1将GPIO x[5]置1，写0无作用
#define GPIOx_BSRR_SET4_BIT  BIT4  // [4] 写1将GPIO x[4]置1，写0无作用
#define GPIOx_BSRR_SET3_BIT  BIT3  // [3] 写1将GPIO x[3]置1，写0无作用
#define GPIOx_BSRR_SET2_BIT  BIT2  // [2] 写1将GPIO x[2]置1，写0无作用
#define GPIOx_BSRR_SET1_BIT  BIT1  // [1] 写1将GPIO x[1]置1，写0无作用
#define GPIOx_BSRR_SET0_BIT  BIT0  // [0] 写1将GPIO x[0]置1，写0无作用

/* GPIOx_BRR(x = 0,1,2,3,4,5) */
#define GPIOx_BRR_CLR15_BIT BIT15 // [15] 写1将GPIO x[15]清零，写0无作用
#define GPIOx_BRR_CLR14_BIT BIT14 // [14] 写1将GPIO x[14]清零，写0无作用
#define GPIOx_BRR_CLR13_BIT BIT13 // [13] 写1将GPIO x[13]清零，写0无作用
#define GPIOx_BRR_CLR12_BIT BIT12 // [12] 写1将GPIO x[12]清零，写0无作用
#define GPIOx_BRR_CLR11_BIT BIT11 // [11] 写1将GPIO x[11]清零，写0无作用
#define GPIOx_BRR_CLR10_BIT BIT10 // [10] 写1将GPIO x[10]清零，写0无作用
#define GPIOx_BRR_CLR9_BIT  BIT9  // [9] 写1将GPIO x[9]清零，写0无作用
#define GPIOx_BRR_CLR8_BIT  BIT8  // [8] 写1将GPIO x[8]清零，写0无作用
#define GPIOx_BRR_CLR7_BIT  BIT7  // [7] 写1将GPIO x[7]清零，写0无作用
#define GPIOx_BRR_CLR6_BIT  BIT6  // [6] 写1将GPIO x[6]清零，写0无作用
#define GPIOx_BRR_CLR5_BIT  BIT5  // [5] 写1将GPIO x[5]清零，写0无作用
#define GPIOx_BRR_CLR4_BIT  BIT4  // [4] 写1将GPIO x[4]清零，写0无作用
#define GPIOx_BRR_CLR3_BIT  BIT3  // [3] 写1将GPIO x[3]清零，写0无作用
#define GPIOx_BRR_CLR2_BIT  BIT2  // [2] 写1将GPIO x[2]清零，写0无作用
#define GPIOx_BRR_CLR1_BIT  BIT1  // [1] 写1将GPIO x[1]清零，写0无作用
#define GPIOx_BRR_CLR0_BIT  BIT0  // [0] 写1将GPIO x[0]清零，写0无作用

/* EXTIx_CR0(x = 0,1,2,3,4,5) */
#define EXTIx_CR0_T7_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T7最大值
#define EXTIx_CR0_T7_POS  14                                            // EXTIx_CR0_T7起始位
#define EXTIx_CR0_T7_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T7_POS) // EXTIx_CR0_T7位掩码
#define EXTIx_CR0_T7(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T7_POS)   // [15:14] GPIO x[7]/ Px[7]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR0_T6_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T6最大值
#define EXTIx_CR0_T6_POS  12                                            // EXTIx_CR0_T6起始位
#define EXTIx_CR0_T6_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T6_POS) // EXTIx_CR0_T6位掩码
#define EXTIx_CR0_T6(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T6_POS)   // [13:12] GPIO x[6]/ Px[6]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR0_T5_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T5最大值
#define EXTIx_CR0_T5_POS  10                                            // EXTIx_CR0_T5起始位
#define EXTIx_CR0_T5_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T5_POS) // EXTIx_CR0_T5位掩码
#define EXTIx_CR0_T5(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T5_POS)   // [11:10] GPIO x[5]/ Px[5]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR0_T4_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T4最大值
#define EXTIx_CR0_T4_POS  8                                             // EXTIx_CR0_T4起始位
#define EXTIx_CR0_T4_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T4_POS) // EXTIx_CR0_T4位掩码
#define EXTIx_CR0_T4(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T4_POS)   // [9:8] GPIO x[4]/ Px[4]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR0_T3_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T3最大值
#define EXTIx_CR0_T3_POS  6                                             // EXTIx_CR0_T3起始位
#define EXTIx_CR0_T3_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T3_POS) // EXTIx_CR0_T3位掩码
#define EXTIx_CR0_T3(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T3_POS)   // [7:6] GPIO x[3]/ Px[3]外部中断触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR0_T2_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T2最大值
#define EXTIx_CR0_T2_POS  4                                             // EXTIx_CR0_T2起始位
#define EXTIx_CR0_T2_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T2_POS) // EXTIx_CR0_T2位掩码
#define EXTIx_CR0_T2(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T2_POS)   // [5:4] GPIO x[2]/ Px[2]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR0_T1_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T1最大值
#define EXTIx_CR0_T1_POS  2                                             // EXTIx_CR0_T1起始位
#define EXTIx_CR0_T1_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T1_POS) // EXTIx_CR0_T1位掩码
#define EXTIx_CR0_T1(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T1_POS)   // [3:2] GPIO x[1]/ Px[1]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR0_T0_MAX  ((uint32_t)0x3)                               // EXTIx_CR0_T0最大值
#define EXTIx_CR0_T0_POS  0                                             // EXTIx_CR0_T0起始位
#define EXTIx_CR0_T0_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR0_T0_POS) // EXTIx_CR0_T0位掩码
#define EXTIx_CR0_T0(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR0_T0_POS)   // [1:0] GPIO x[0]/ Px[0]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发

/* EXTIx_CR1(x = 0,1,2,3,4,5) */
#define EXTIx_CR1_T15_MAX  ((uint32_t)0x3)                                // EXTIx_CR1_T15最大值
#define EXTIx_CR1_T15_POS  14                                             // EXTIx_CR1_T15起始位
#define EXTIx_CR1_T15_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T15_POS) // EXTIx_CR1_T15位掩码
#define EXTIx_CR1_T15(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR1_T15_POS)   // [15:14] GPIO x[15]/Px[15]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR1_T14_MAX  ((uint32_t)0x3)                                // EXTIx_CR1_T14最大值
#define EXTIx_CR1_T14_POS  12                                             // EXTIx_CR1_T14起始位
#define EXTIx_CR1_T14_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T14_POS) // EXTIx_CR1_T14位掩码
#define EXTIx_CR1_T14(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR1_T14_POS)   // [13:12] GPIO x[14]/Px[14]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR1_T13_MAX  ((uint32_t)0x3)                                // EXTIx_CR1_T13最大值
#define EXTIx_CR1_T13_POS  10                                             // EXTIx_CR1_T13起始位
#define EXTIx_CR1_T13_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T13_POS) // EXTIx_CR1_T13位掩码
#define EXTIx_CR1_T13(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR1_T13_POS)   // [11:10] GPIO x[13]/Px[13]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR1_T12_MAX  ((uint32_t)0x3)                                // EXTIx_CR1_T12最大值
#define EXTIx_CR1_T12_POS  8                                              // EXTIx_CR1_T12起始位
#define EXTIx_CR1_T12_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T12_POS) // EXTIx_CR1_T12位掩码
#define EXTIx_CR1_T12(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR1_T12_POS)   // [9:8] GPIO x[12]/Px[12]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR1_T11_MAX  ((uint32_t)0x3)                                // EXTIx_CR1_T11最大值
#define EXTIx_CR1_T11_POS  6                                              // EXTIx_CR1_T11起始位
#define EXTIx_CR1_T11_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T11_POS) // EXTIx_CR1_T11位掩码
#define EXTIx_CR1_T11(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR1_T11_POS)   // [7:6] GPIO x[11]/Px[11]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR1_T10_MAX  ((uint32_t)0x3)                                // EXTIx_CR1_T10最大值
#define EXTIx_CR1_T10_POS  4                                              // EXTIx_CR1_T10起始位
#define EXTIx_CR1_T10_MASK (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T10_POS) // EXTIx_CR1_T10位掩码
#define EXTIx_CR1_T10(x)   (uint32_t)(((x) & 0x3) << EXTIx_CR1_T10_POS)   // [5:4] GPIO x[10]/Px[10]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR1_T9_MAX   ((uint32_t)0x3)                                // EXTIx_CR1_T9最大值
#define EXTIx_CR1_T9_POS   2                                              // EXTIx_CR1_T9起始位
#define EXTIx_CR1_T9_MASK  (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T9_POS)  // EXTIx_CR1_T9位掩码
#define EXTIx_CR1_T9(x)    (uint32_t)(((x) & 0x3) << EXTIx_CR1_T9_POS)    // [3:2] GPIO x[9]/Px[9]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发
#define EXTIx_CR1_T8_MAX   ((uint32_t)0x3)                                // EXTIx_CR1_T8最大值
#define EXTIx_CR1_T8_POS   0                                              // EXTIx_CR1_T8起始位
#define EXTIx_CR1_T8_MASK  (uint32_t)((uint32_t)0x3 << EXTIx_CR1_T8_POS)  // EXTIx_CR1_T8位掩码
#define EXTIx_CR1_T8(x)    (uint32_t)(((x) & 0x3) << EXTIx_CR1_T8_POS)    // [1:0] GPIO x[8]/Px[8]外部中断/DMA触发类型选择 00：不触发 01：下降沿触发 10：上升沿触发 11：上升沿、下降沿均触发

/* EXTIx_IF(x = 0,1,2,3,4,5) */
#define EXTIx_IF_IF15_BIT BIT15 // [15] GPIO x[15]/ Px[15]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF14_BIT BIT14 // [14] GPIO x[14]/ Px[14]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF13_BIT BIT13 // [13] GPIO x[13]/ Px[13]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF12_BIT BIT12 // [12] GPIO x[12]/ Px[12]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF11_BIT BIT11 // [11] GPIO x[11]/ Px[11]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF10_BIT BIT10 // [10] GPIO x[10]/ Px[10]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF9_BIT  BIT9  // [9] GPIO x[9]/ Px[9]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF8_BIT  BIT8  // [8] GPIO x[8]/ Px[8]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF7_BIT  BIT7  // [7] GPIO x[7]/ Px[7]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF6_BIT  BIT6  // [6] GPIO x[6]/ Px[6]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF5_BIT  BIT5  // [5] GPIO x[5]/ Px[5]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF4_BIT  BIT4  // [4] GPIO x[4]/ Px[4]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF3_BIT  BIT3  // [3] GPIO x[3]/ Px[3]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF2_BIT  BIT2  // [2] GPIO x[2]/ Px[2]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF1_BIT  BIT1  // [1] GPIO x[1]/ Px[1]外部中断标志。中断标志高有效，写1清零
#define EXTIx_IF_IF0_BIT  BIT0  // [0] GPIO x[0]/ Px[0]外部中断标志。中断标志高有效，写1清零

/* CLKO_SEL */
#define CLKO_SEL_HSE_OE_BIT BIT4 // [4] 晶振时钟输出使能。1：使能；0：禁用。
#define CLKO_SEL_ADC_OE_BIT BIT3 // [3] ADC时钟输出使能。1：使能；0：禁用。
#define CLKO_SEL_PLL_OE_BIT BIT2 // [2] PLL时钟输出使能。1：使能；0：禁用。
#define CLKO_SEL_HSI_OE_BIT BIT1 // [1] HRC时钟输出使能。1：使能；0：禁用。
#define CLKO_SEL_LSI_OE_BIT BIT0 // [0] LRC时钟输出使能。1：使能；0：禁用。

/* LCKR_PRT */
#define LCKR_PRT_PSW_15_1__MAX   ((uint32_t)0x7FFF)                                     // LCKR_PRT_PSW_15_1_最大值
#define LCKR_PRT_PSW_15_1__POS   1                                                      // LCKR_PRT_PSW_15_1_起始位
#define LCKR_PRT_PSW_15_1__MASK  (uint32_t)((uint32_t)0x7FFF << LCKR_PRT_PSW_15_1__POS) // LCKR_PRT_PSW_15_1_位掩码
#define LCKR_PRT_PSW_15_1_(x)    (uint32_t)(((x) & 0x7FFF) << LCKR_PRT_PSW_15_1__POS)   // [15:1] GPIO保护密码高15位
#define LCKR_PRT_PSW_0__LOCK_BIT BIT0                                                   // [0] GPIO保护密码最低位，向LCKR_PRT[15:0]写入0x5AC4可解除GPIO配置保护，写入其他数值启用GPIO配置保护，读取LCKR_PRT[0]可得到当前保护状态，LCKR_PRT[15:1]读回恒为0。当启用配置保护后，GPIOx_PIE/GPIOx_POE/GPIOx_PDO/GPIOx_PUE/GPIOx_PDE/GPIOx_PODE/GPIOx_F3210/GPIOx_F7654/GPIOx_FBA98/GPIOx_FFEDC/GPIOx_BSRR/GPIOx_BRR均无法写入。

/* EXTI_REN */
#define EXTI_REN_EXTI_REN_MAX  ((uint32_t)0x3F)                                    // EXTI_REN_EXTI_REN最大值
#define EXTI_REN_EXTI_REN_POS  0                                                   // EXTI_REN_EXTI_REN起始位
#define EXTI_REN_EXTI_REN_MASK (uint32_t)((uint32_t)0x3F << EXTI_REN_EXTI_REN_POS) // EXTI_REN_EXTI_REN位掩码
#define EXTI_REN_EXTI_REN(x)   (uint32_t)(((x) & 0x3F) << EXTI_REN_EXTI_REN_POS)   // [5:0] GPIO5~GPIO0 DMA 请求使能，需要配合EXTIx_CR0/1使用

/* CRC_DR CRC信息码寄存器 */
#define CRC_DR_DR_MAX  ((uint32_t)0xFFFFFFFF)                            // CRC_DR_DR最大值
#define CRC_DR_DR_POS  0                                                 // CRC_DR_DR起始位
#define CRC_DR_DR_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CRC_DR_DR_POS) // CRC_DR_DR位掩码
#define CRC_DR_DR(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CRC_DR_DR_POS)   // [31:0] 存放待编码的信息码和经CRC校验后的编码

/* CRC_CR CRC控制寄存器 */
#define CRC_CR_REV_OUT_TYPE_BIT BIT12                                               // [12] 是否将CRC校验后的编码反转后输出，即b[31]=b[0], b[30]=b[1],… [b0]=b[31]
#define CRC_CR_REV_IN_TYPE_MAX  ((uint32_t)0x3)                                     // CRC_CR_REV_IN_TYPE最大值
#define CRC_CR_REV_IN_TYPE_POS  8                                                   // CRC_CR_REV_IN_TYPE起始位
#define CRC_CR_REV_IN_TYPE_MASK (uint32_t)((uint32_t)0x3 << CRC_CR_REV_IN_TYPE_POS) // CRC_CR_REV_IN_TYPE位掩码
#define CRC_CR_REV_IN_TYPE(x)   (uint32_t)(((x) & 0x3) << CRC_CR_REV_IN_TYPE_POS)   // [9:8] 待编码数据反转类型 00:不反转 01:按字节反转，即b[31]=b[24], b[30]=b[25], …, b[24]=b[31], …, b[7]=b[0], b[6]=b[1], …, b[0]=b[7]10:按半字（16bit）反转，即b[31]=b[16], b[30]=b[17], …, b[16]=b[31], …, b[15]=b[0], b[14]=b[1], …, b[0]=b[15]11:按字反转，即b[31]=b[0], b[30]=b[1],… [b0]=b[31]
#define CRC_CR_POLY_SIZE_MAX    ((uint32_t)0x3)                                     // CRC_CR_POLY_SIZE最大值
#define CRC_CR_POLY_SIZE_POS    4                                                   // CRC_CR_POLY_SIZE起始位
#define CRC_CR_POLY_SIZE_MASK   (uint32_t)((uint32_t)0x3 << CRC_CR_POLY_SIZE_POS)   // CRC_CR_POLY_SIZE位掩码
#define CRC_CR_POLY_SIZE(x)     (uint32_t)(((x) & 0x3) << CRC_CR_POLY_SIZE_POS)     // [5:4] 输出编码（多项式）位宽 00: 32bits 01: 16bits 10: 8bits 11: 7bits
#define CRC_CR_RESET_BIT        BIT0                                                // [0] 与输入信息码进行CRC计算的数据来源 0:来自于上一次的计算结果 1:来自于CRC_INIT 写入1实现CRC数据重置并自动清零，读回恒为0.

/* CRC_INIT CRC初始码寄存器 */
#define CRC_INIT_INIT_MAX  ((uint32_t)0xFFFFFFFF)                                // CRC_INIT_INIT最大值
#define CRC_INIT_INIT_POS  0                                                     // CRC_INIT_INIT起始位
#define CRC_INIT_INIT_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CRC_INIT_INIT_POS) // CRC_INIT_INIT位掩码
#define CRC_INIT_INIT(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CRC_INIT_INIT_POS)   // [31:0] 存放初始码

/* CRC_POL CRC生成码寄存器 */
#define CRC_POL_POL_MAX  ((uint32_t)0xFFFFFFFF)                              // CRC_POL_POL最大值
#define CRC_POL_POL_POS  0                                                   // CRC_POL_POL起始位
#define CRC_POL_POL_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CRC_POL_POL_POS) // CRC_POL_POL位掩码
#define CRC_POL_POL(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CRC_POL_POL_POS)   // [31:0] 存放生成多项式对应的生成码

/* DSP_SC DSP状态控制寄存器 */
#define DSP_SC_MODE_BIT BIT2 // [2] CORDIC mode, 0: arctan, 1: sin/cos

/* DSP_THETA */
#define DSP_THETA_THETA_MAX  ((uint32_t)0xFFFF)                                  // DSP_THETA_THETA最大值
#define DSP_THETA_THETA_POS  0                                                   // DSP_THETA_THETA起始位
#define DSP_THETA_THETA_MASK (uint32_t)((uint32_t)0xFFFF << DSP_THETA_THETA_POS) // DSP_THETA_THETA位掩码
#define DSP_THETA_THETA(x)   (uint32_t)(((x) & 0xFFFF) << DSP_THETA_THETA_POS)   // [15:0] DSP sin/cos输入角度寄存器

/* DSP_SIN */
#define DSP_SIN_SIN_MAX  ((uint32_t)0xFFFF)                              // DSP_SIN_SIN最大值
#define DSP_SIN_SIN_POS  0                                               // DSP_SIN_SIN起始位
#define DSP_SIN_SIN_MASK (uint32_t)((uint32_t)0xFFFF << DSP_SIN_SIN_POS) // DSP_SIN_SIN位掩码
#define DSP_SIN_SIN(x)   (uint32_t)(((x) & 0xFFFF) << DSP_SIN_SIN_POS)   // [15:0] DSP sin/cos计算结果sin寄存器

/* DSP_COS */
#define DSP_COS_COS_MAX  ((uint32_t)0xFFFF)                              // DSP_COS_COS最大值
#define DSP_COS_COS_POS  0                                               // DSP_COS_COS起始位
#define DSP_COS_COS_MASK (uint32_t)((uint32_t)0xFFFF << DSP_COS_COS_POS) // DSP_COS_COS位掩码
#define DSP_COS_COS(x)   (uint32_t)(((x) & 0xFFFF) << DSP_COS_COS_POS)   // [15:0] DSP sin/cos计算结果cos寄存器

/* DSP_X */
#define DSP_X_X_MAX  ((uint32_t)0xFFFF)                          // DSP_X_X最大值
#define DSP_X_X_POS  0                                           // DSP_X_X起始位
#define DSP_X_X_MASK (uint32_t)((uint32_t)0xFFFF << DSP_X_X_POS) // DSP_X_X位掩码
#define DSP_X_X(x)   (uint32_t)(((x) & 0xFFFF) << DSP_X_X_POS)   // [15:0] DSP arctan/module计算输入坐标Y寄存器

/* DSP_Y */
#define DSP_Y_Y_MAX  ((uint32_t)0xFFFF)                          // DSP_Y_Y最大值
#define DSP_Y_Y_POS  0                                           // DSP_Y_Y起始位
#define DSP_Y_Y_MASK (uint32_t)((uint32_t)0xFFFF << DSP_Y_Y_POS) // DSP_Y_Y位掩码
#define DSP_Y_Y(x)   (uint32_t)(((x) & 0xFFFF) << DSP_Y_Y_POS)   // [15:0] DSP arctan/module计算输入坐标Y寄存器

/* DSP_MOD */
#define DSP_MOD_MOD_MAX  ((uint32_t)0xFFFF)                              // DSP_MOD_MOD最大值
#define DSP_MOD_MOD_POS  0                                               // DSP_MOD_MOD起始位
#define DSP_MOD_MOD_MASK (uint32_t)((uint32_t)0xFFFF << DSP_MOD_MOD_POS) // DSP_MOD_MOD位掩码
#define DSP_MOD_MOD(x)   (uint32_t)(((x) & 0xFFFF) << DSP_MOD_MOD_POS)   // [15:0] DSP arctan计算结果 sqrt(X2+Y2) 寄存器

/* **DSP_ARCTAN** */
#define DSP_ARCTAN_ARCTAN_MAX  ((uint32_t)0xFFFF)                                    // DSP_ARCTAN_ARCTAN最大值
#define DSP_ARCTAN_ARCTAN_POS  0                                                     // DSP_ARCTAN_ARCTAN起始位
#define DSP_ARCTAN_ARCTAN_MASK (uint32_t)((uint32_t)0xFFFF << DSP_ARCTAN_ARCTAN_POS) // DSP_ARCTAN_ARCTAN位掩码
#define DSP_ARCTAN_ARCTAN(x)   (uint32_t)(((x) & 0xFFFF) << DSP_ARCTAN_ARCTAN_POS)   // [15:0] DSP arctan计算结果arctan(Y/X) 角度寄存器

/* FMAC_X1BUFCFG FMAC X1 buffer配置寄存器 */
#define FMAC_X1BUFCFG_FULL_WM_MAX      ((uint32_t)0x3)                                             // FMAC_X1BUFCFG_FULL_WM最大值
#define FMAC_X1BUFCFG_FULL_WM_POS      24                                                          // FMAC_X1BUFCFG_FULL_WM起始位
#define FMAC_X1BUFCFG_FULL_WM_MASK     (uint32_t)((uint32_t)0x3 << FMAC_X1BUFCFG_FULL_WM_POS)      // FMAC_X1BUFCFG_FULL_WM位掩码
#define FMAC_X1BUFCFG_FULL_WM(x)       (uint32_t)(((x) & 0x3) << FMAC_X1BUFCFG_FULL_WM_POS)        // [25:24] X1 buffer满水线阈值，当X1 buffer中的空闲位置少于2FULL_WM时，X1 buffer满标志置位。 0：水线阈值为1 1：水线阈值为2 2：水线阈值为4 3：水线阈值为8 设置水线阈值大于1可以在一次中断处理中传输多个数据到X1 buffer中，当使用DMA写X1 buffer时水线阈值应该设置为1。
#define FMAC_X1BUFCFG_X1_BUF_SIZE_MAX  ((uint32_t)0xFF)                                            // FMAC_X1BUFCFG_X1_BUF_SIZE最大值
#define FMAC_X1BUFCFG_X1_BUF_SIZE_POS  8                                                           // FMAC_X1BUFCFG_X1_BUF_SIZE起始位
#define FMAC_X1BUFCFG_X1_BUF_SIZE_MASK (uint32_t)((uint32_t)0xFF << FMAC_X1BUFCFG_X1_BUF_SIZE_POS) // FMAC_X1BUFCFG_X1_BUF_SIZE位掩码
#define FMAC_X1BUFCFG_X1_BUF_SIZE(x)   (uint32_t)(((x) & 0xFF) << FMAC_X1BUFCFG_X1_BUF_SIZE_POS)   // [15:8] X1 buffer 大小，X1 buffer中包含的16bit有符号数个数，buffer尺寸最小值为滤波器前馈阶数（+水线阈值-1）
#define FMAC_X1BUFCFG_X1_BASE_MAX      ((uint32_t)0xFF)                                            // FMAC_X1BUFCFG_X1_BASE最大值
#define FMAC_X1BUFCFG_X1_BASE_POS      0                                                           // FMAC_X1BUFCFG_X1_BASE起始位
#define FMAC_X1BUFCFG_X1_BASE_MASK     (uint32_t)((uint32_t)0xFF << FMAC_X1BUFCFG_X1_BASE_POS)     // FMAC_X1BUFCFG_X1_BASE位掩码
#define FMAC_X1BUFCFG_X1_BASE(x)       (uint32_t)(((x) & 0xFF) << FMAC_X1BUFCFG_X1_BASE_POS)       // [7:0] X1 buffer 基地址

/* FMAC_X2BUFCFG FMAC X2 buffer配置寄存器 */
#define FMAC_X2BUFCFG_X2_BUF_SIZE_MAX  ((uint32_t)0xFF)                                            // FMAC_X2BUFCFG_X2_BUF_SIZE最大值
#define FMAC_X2BUFCFG_X2_BUF_SIZE_POS  8                                                           // FMAC_X2BUFCFG_X2_BUF_SIZE起始位
#define FMAC_X2BUFCFG_X2_BUF_SIZE_MASK (uint32_t)((uint32_t)0xFF << FMAC_X2BUFCFG_X2_BUF_SIZE_POS) // FMAC_X2BUFCFG_X2_BUF_SIZE位掩码
#define FMAC_X2BUFCFG_X2_BUF_SIZE(x)   (uint32_t)(((x) & 0xFF) << FMAC_X2BUFCFG_X2_BUF_SIZE_POS)   // [15:8] X2 buffer 大小，X2 buffer中包含的16bit有符号数个数，这个位域在操作进行中（START=1）时无法修改
#define FMAC_X2BUFCFG_X2_BASE_MAX      ((uint32_t)0xFF)                                            // FMAC_X2BUFCFG_X2_BASE最大值
#define FMAC_X2BUFCFG_X2_BASE_POS      0                                                           // FMAC_X2BUFCFG_X2_BASE起始位
#define FMAC_X2BUFCFG_X2_BASE_MASK     (uint32_t)((uint32_t)0xFF << FMAC_X2BUFCFG_X2_BASE_POS)     // FMAC_X2BUFCFG_X2_BASE位掩码
#define FMAC_X2BUFCFG_X2_BASE(x)       (uint32_t)(((x) & 0xFF) << FMAC_X2BUFCFG_X2_BASE_POS)       // [7:0] X2 buffer 基地址，这个位域在操作进行中（START=1）时无法修改

/* FMAC_YBUFCFG FMAC Y buffer配置寄存器 */
#define FMAC_YBUFCFG_EMPTY_WM_MAX    ((uint32_t)0x3)                                           // FMAC_YBUFCFG_EMPTY_WM最大值
#define FMAC_YBUFCFG_EMPTY_WM_POS    24                                                        // FMAC_YBUFCFG_EMPTY_WM起始位
#define FMAC_YBUFCFG_EMPTY_WM_MASK   (uint32_t)((uint32_t)0x3 << FMAC_YBUFCFG_EMPTY_WM_POS)    // FMAC_YBUFCFG_EMPTY_WM位掩码
#define FMAC_YBUFCFG_EMPTY_WM(x)     (uint32_t)(((x) & 0x3) << FMAC_YBUFCFG_EMPTY_WM_POS)      // [25:24] Y buffer空水线阈值，当Y buffer中的有效数据数量少于2EMPTY_WM时，Y buffer空标志置位。 0：水线阈值为1 1：水线阈值为2 2：水线阈值为4 3：水线阈值为8 设置水线阈值大于1可以在一次中断处理中从Y buffer读取多个数据中，当使用DMA读取Y buffer时水线阈值应该设置为1。
#define FMAC_YBUFCFG_Y_BUF_SIZE_MAX  ((uint32_t)0xFF)                                          // FMAC_YBUFCFG_Y_BUF_SIZE最大值
#define FMAC_YBUFCFG_Y_BUF_SIZE_POS  8                                                         // FMAC_YBUFCFG_Y_BUF_SIZE起始位
#define FMAC_YBUFCFG_Y_BUF_SIZE_MASK (uint32_t)((uint32_t)0xFF << FMAC_YBUFCFG_Y_BUF_SIZE_POS) // FMAC_YBUFCFG_Y_BUF_SIZE位掩码
#define FMAC_YBUFCFG_Y_BUF_SIZE(x)   (uint32_t)(((x) & 0xFF) << FMAC_YBUFCFG_Y_BUF_SIZE_POS)   // [15:8] Y buffer 大小，Y buffer中包含的16bit有符号数个数。对于FIR滤波器，buffer尺寸最小值为1（+水线阈值），对于IIR滤波器，buffer尺寸最小值为滤波器反馈阶数（+水线阈值）
#define FMAC_YBUFCFG_Y_BASE_MAX      ((uint32_t)0xFF)                                          // FMAC_YBUFCFG_Y_BASE最大值
#define FMAC_YBUFCFG_Y_BASE_POS      0                                                         // FMAC_YBUFCFG_Y_BASE起始位
#define FMAC_YBUFCFG_Y_BASE_MASK     (uint32_t)((uint32_t)0xFF << FMAC_YBUFCFG_Y_BASE_POS)     // FMAC_YBUFCFG_Y_BASE位掩码
#define FMAC_YBUFCFG_Y_BASE(x)       (uint32_t)(((x) & 0xFF) << FMAC_YBUFCFG_Y_BASE_POS)       // [7:0] Y buffer 基地址

/* FMAC_PARAM FMAC参数寄存器 */
#define FMAC_PARAM_START_BIT BIT31                                            // [31] 0：停止FMAC执行 1：开始FMAC执行（FMAC执行过程中） 写入1触发FUNC指定操作开始执行，写入0可以停止执行中的操作，初始化操作完成后此位由硬件自动清零。
#define FMAC_PARAM_FUNC_MAX  ((uint32_t)0xF)                                  // FMAC_PARAM_FUNC最大值
#define FMAC_PARAM_FUNC_POS  24                                               // FMAC_PARAM_FUNC起始位
#define FMAC_PARAM_FUNC_MASK (uint32_t)((uint32_t)0xF << FMAC_PARAM_FUNC_POS) // FMAC_PARAM_FUNC位掩码
#define FMAC_PARAM_FUNC(x)   (uint32_t)(((x) & 0xF) << FMAC_PARAM_FUNC_POS)   // [27:24] 0: Reserved 1: Load X1 buffer 2: Load X2 buffer 3: Load Y buffer 4 to 7: Reserved 8: Convolution (FIR filter) 9: IIR filter (direct form 1) 此位域在START=1时无法修改
#define FMAC_PARAM_R_MAX     ((uint32_t)0xFF)                                 // FMAC_PARAM_R最大值
#define FMAC_PARAM_R_POS     16                                               // FMAC_PARAM_R起始位
#define FMAC_PARAM_R_MASK    (uint32_t)((uint32_t)0xFF << FMAC_PARAM_R_POS)   // FMAC_PARAM_R位掩码
#define FMAC_PARAM_R(x)      (uint32_t)(((x) & 0xFF) << FMAC_PARAM_R_POS)     // [23:16] 输入参数R，Y输出前移位幅度，即Y输出前乘以2R倍 此位域在START=1时无法修改
#define FMAC_PARAM_Q_MAX     ((uint32_t)0xFF)                                 // FMAC_PARAM_Q最大值
#define FMAC_PARAM_Q_POS     8                                                // FMAC_PARAM_Q起始位
#define FMAC_PARAM_Q_MASK    (uint32_t)((uint32_t)0xFF << FMAC_PARAM_Q_POS)   // FMAC_PARAM_Q位掩码
#define FMAC_PARAM_Q(x)      (uint32_t)(((x) & 0xFF) << FMAC_PARAM_Q_POS)     // [15:8] 输入参数Q，IIR中反馈系数个数 此位域在START=1时无法修改
#define FMAC_PARAM_P_MAX     ((uint32_t)0xFF)                                 // FMAC_PARAM_P最大值
#define FMAC_PARAM_P_POS     0                                                // FMAC_PARAM_P起始位
#define FMAC_PARAM_P_MASK    (uint32_t)((uint32_t)0xFF << FMAC_PARAM_P_POS)   // FMAC_PARAM_P位掩码
#define FMAC_PARAM_P(x)      (uint32_t)(((x) & 0xFF) << FMAC_PARAM_P_POS)     // [7:0] 输入参数P，FIR及IIR中前馈系数个数 此位域在START=1时无法修改

/* FMAC_CR FMAC控制寄存器 */
#define FMAC_CR_RESET_BIT   BIT16 // [16] 复位FMAC模块，向此位写1可以将FMAC内部的读写指针，内部逻辑状态机，FMAC_SR寄存器和FMAC_PARAM寄存器（包括START）进行复位，其他寄存器不受影响。此位写入自动清零。
#define FMAC_CR_CLIPEN_BIT  BIT15 // [15] 累加器输出饱和使能 1：累加器增益控制后的输出被钳位在Q1.15范围内 0：累加器增益控制后的输出超出Q1.15范围时丢弃高位
#define FMAC_CR_DMAWEN_BIT  BIT9  // [9] DMA写X1 buffer请求使能 0：禁用，无DMA写请求产生 1：使能，当X1不满时有DMA写请求产生 此位只能在START=0时进行改写
#define FMAC_CR_DMAREN_BIT  BIT8  // [8] DMA读请求使能 0：禁用，无DMA写请求产生 1：使能，当Y不空时有DMA读请求产生 此位只能在START=0时进行改写
#define FMAC_CR_SATIEN_BIT  BIT4  // [4] 累加器饱和错误中断使能 0：禁用 1：使能，当FMAC_SR.SAT置位时产生中断请求
#define FMAC_CR_UNFLIEN_BIT BIT3  // [3] Y buffer下溢出中断使能 0：禁用 1：使能，当FMAC_SR.UNFL置位时产生中断请求
#define FMAC_CR_OVFLIEN_BIT BIT2  // [2] X1 buffer上溢出中断使能 0：禁用 1：使能，当FMAC_SR.OVFL置位时产生中断请求
#define FMAC_CR_WIEN_BIT    BIT1  // [1] X1 buffer写请求中断使能 0：禁用 1：使能，当X1 buffer不满时，向CPU发出写请求中断
#define FMAC_CR_RIEN_BIT    BIT0  // [0] Y buffer读请求使能 0：禁用 1：使能，当Y buffer不空时，向CPU发出读请求中断

/* FMAC_SR FMAC状态寄存器 */
#define FMAC_SR_SAT_BIT     BIT10 // [10] 饱和错误标志 当累加器输出结果超出Q1.15表示范围时，此位置位 0：未发生饱和事件 1：监测到饱和事件发生。如果FMAC_CR.SATIEN置位，则产生中断请求
#define FMAC_SR_UNFL_BIT    BIT9  // [9] Y buffer下溢出错误标志 当Y buffer中无有效数据且软件或DMA读取FMAC_RDATA时产生下溢出事件 0：未发生下溢出事件 1：监测到下溢出事件发生。如果FMAC_CR.UNFLIEN置位，则产生中断请求
#define FMAC_SR_OVFL_BIT    BIT8  // [8] X1 buffer上溢出错误标志 当X1 buffer中无空闲空间且软件或DMA通过FMAC_WDATA向X1 buffer写入数据时时产生上溢出事件 0：未发生上溢出事件 1：监测到上溢出事件发生。如果FMAC_CR.OVFLIEN置位，则产生中断请求
#define FMAC_SR_X1_FULL_BIT BIT1  // [1] X1 buffer满标志 当X1 buffer中的空闲空间大小小于水线阈值时，X1 buffer被标志位满。空闲空间大小等于写指针与最近一次读指针之差。 0：X1 buffer不满。如果FMAC_CR.WIEN置位则产生中断请求向X1 buffer写入数据。如果FMAC_CR.DMAWEN置位则请求DMA向X1 buffer写入数据，直到X1_FULL置位。 1：X1 buffer满 此位由硬件自动置位清零，也可以通过向FMAC_CR.RESET写1清零
#define FMAC_SR_Y_EMPTY_BIT BIT0  // [0] Y buffer空标志 当Y buffer中的有效数据数量小于水线阈值时，Y buffer被标志为空。有效数据数量等于读指针与累加器写入数据目的地址之差。 0：Y buffer不空。如果FMAC_CR.RIEN置位则产生中断请求从Y buffer读取数据。如果FMAC_CR.DMAREN置位，则请求DMA从Y buffer读取数据直到Y_EMPTY置位。 1：Y buffer空 此位由硬件自动置位清零，也可以通过向FMAC_CR.RESET写1清零

/* FMAC_WDATA FMAC写入数据寄存器 */
#define FMAC_WDATA_WDATA_MAX  ((uint32_t)0xFFFF)                                   // FMAC_WDATA_WDATA最大值
#define FMAC_WDATA_WDATA_POS  0                                                    // FMAC_WDATA_WDATA起始位
#define FMAC_WDATA_WDATA_MASK (uint32_t)((uint32_t)0xFFFF << FMAC_WDATA_WDATA_POS) // FMAC_WDATA_WDATA位掩码
#define FMAC_WDATA_WDATA(x)   (uint32_t)(((x) & 0xFFFF) << FMAC_WDATA_WDATA_POS)   // [15:0] 写入数据，向此寄存器写入数据，数据被写入写指针指向的本地存储地址，写后写指针自动加1

/* FMAC_RDATA FMAC读取数据寄存器 */
#define FMAC_RDATA_RDATA_MAX  ((uint32_t)0xFFFF)                                   // FMAC_RDATA_RDATA最大值
#define FMAC_RDATA_RDATA_POS  0                                                    // FMAC_RDATA_RDATA起始位
#define FMAC_RDATA_RDATA_MASK (uint32_t)((uint32_t)0xFFFF << FMAC_RDATA_RDATA_POS) // FMAC_RDATA_RDATA位掩码
#define FMAC_RDATA_RDATA(x)   (uint32_t)(((x) & 0xFFFF) << FMAC_RDATA_RDATA_POS)   // [15:0] 读出数据，从寄存器读取数据，数据被从读指针指向的本地存储地址读出，读后读指针自动加1

/* ADCx_DAT0(x = 0,1,2) */
#define ADCx_DAT0_DAT0_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT0_DAT0最大值
#define ADCx_DAT0_DAT0_POS  0                                                  // ADCx_DAT0_DAT0起始位
#define ADCx_DAT0_DAT0_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT0_DAT0_POS) // ADCx_DAT0_DAT0位掩码
#define ADCx_DAT0_DAT0(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT0_DAT0_POS)   // [15:0] ADCx第0次采样数据

/* ADCx_DAT1(x = 0,1,2) */
#define ADCx_DAT1_DAT1_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT1_DAT1最大值
#define ADCx_DAT1_DAT1_POS  0                                                  // ADCx_DAT1_DAT1起始位
#define ADCx_DAT1_DAT1_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT1_DAT1_POS) // ADCx_DAT1_DAT1位掩码
#define ADCx_DAT1_DAT1(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT1_DAT1_POS)   // [15:0] ADCx第1次采样数据

/* ADCx_DAT2(x = 0,1,2) */
#define ADCx_DAT2_DAT2_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT2_DAT2最大值
#define ADCx_DAT2_DAT2_POS  0                                                  // ADCx_DAT2_DAT2起始位
#define ADCx_DAT2_DAT2_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT2_DAT2_POS) // ADCx_DAT2_DAT2位掩码
#define ADCx_DAT2_DAT2(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT2_DAT2_POS)   // [15:0] ADCx第2次采样数据

/* ADCx_DAT3(x = 0,1,2) */
#define ADCx_DAT3_DAT3_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT3_DAT3最大值
#define ADCx_DAT3_DAT3_POS  0                                                  // ADCx_DAT3_DAT3起始位
#define ADCx_DAT3_DAT3_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT3_DAT3_POS) // ADCx_DAT3_DAT3位掩码
#define ADCx_DAT3_DAT3(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT3_DAT3_POS)   // [15:0] ADCx第3次采样数据

/* ADCx_DAT4(x = 0,1,2) */
#define ADCx_DAT4_DAT4_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT4_DAT4最大值
#define ADCx_DAT4_DAT4_POS  0                                                  // ADCx_DAT4_DAT4起始位
#define ADCx_DAT4_DAT4_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT4_DAT4_POS) // ADCx_DAT4_DAT4位掩码
#define ADCx_DAT4_DAT4(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT4_DAT4_POS)   // [15:0] ADCx第4次采样数据

/* ADCx_DAT5(x = 0,1,2) */
#define ADCx_DAT5_DAT5_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT5_DAT5最大值
#define ADCx_DAT5_DAT5_POS  0                                                  // ADCx_DAT5_DAT5起始位
#define ADCx_DAT5_DAT5_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT5_DAT5_POS) // ADCx_DAT5_DAT5位掩码
#define ADCx_DAT5_DAT5(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT5_DAT5_POS)   // [15:0] ADCx第5次采样数据

/* ADCx_DAT6(x = 0,1,2) */
#define ADCx_DAT6_DAT6_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT6_DAT6最大值
#define ADCx_DAT6_DAT6_POS  0                                                  // ADCx_DAT6_DAT6起始位
#define ADCx_DAT6_DAT6_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT6_DAT6_POS) // ADCx_DAT6_DAT6位掩码
#define ADCx_DAT6_DAT6(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT6_DAT6_POS)   // [15:0] ADCx第6次采样数据

/* ADCx_DAT7(x = 0,1,2) */
#define ADCx_DAT7_DAT7_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT7_DAT7最大值
#define ADCx_DAT7_DAT7_POS  0                                                  // ADCx_DAT7_DAT7起始位
#define ADCx_DAT7_DAT7_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT7_DAT7_POS) // ADCx_DAT7_DAT7位掩码
#define ADCx_DAT7_DAT7(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT7_DAT7_POS)   // [15:0] ADCx第7次采样数据

/* ADCx_DAT8(x = 0,1,2) */
#define ADCx_DAT8_DAT8_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT8_DAT8最大值
#define ADCx_DAT8_DAT8_POS  0                                                  // ADCx_DAT8_DAT8起始位
#define ADCx_DAT8_DAT8_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT8_DAT8_POS) // ADCx_DAT8_DAT8位掩码
#define ADCx_DAT8_DAT8(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT8_DAT8_POS)   // [15:0] ADCx第8次采样数据

/* ADCx_DAT9(x = 0,1,2) */
#define ADCx_DAT9_DAT9_MAX  ((uint32_t)0xFFFF)                                 // ADCx_DAT9_DAT9最大值
#define ADCx_DAT9_DAT9_POS  0                                                  // ADCx_DAT9_DAT9起始位
#define ADCx_DAT9_DAT9_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT9_DAT9_POS) // ADCx_DAT9_DAT9位掩码
#define ADCx_DAT9_DAT9(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT9_DAT9_POS)   // [15:0] ADCx第9次采样数据

/* ADCx_DAT10(x = 0,1,2) */
#define ADCx_DAT10_DAT10_MAX  ((uint32_t)0xFFFF)                                   // ADCx_DAT10_DAT10最大值
#define ADCx_DAT10_DAT10_POS  0                                                    // ADCx_DAT10_DAT10起始位
#define ADCx_DAT10_DAT10_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT10_DAT10_POS) // ADCx_DAT10_DAT10位掩码
#define ADCx_DAT10_DAT10(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT10_DAT10_POS)   // [15:0] ADCx第10次采样数据

/* ADCx_DAT11(x = 0,1,2) */
#define ADCx_DAT11_DAT11_MAX  ((uint32_t)0xFFFF)                                   // ADCx_DAT11_DAT11最大值
#define ADCx_DAT11_DAT11_POS  0                                                    // ADCx_DAT11_DAT11起始位
#define ADCx_DAT11_DAT11_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT11_DAT11_POS) // ADCx_DAT11_DAT11位掩码
#define ADCx_DAT11_DAT11(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT11_DAT11_POS)   // [15:0] ADCx第11次采样数据

/* ADCx_DAT12(x = 0,1,2) */
#define ADCx_DAT12_DAT12_MAX  ((uint32_t)0xFFFF)                                   // ADCx_DAT12_DAT12最大值
#define ADCx_DAT12_DAT12_POS  0                                                    // ADCx_DAT12_DAT12起始位
#define ADCx_DAT12_DAT12_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT12_DAT12_POS) // ADCx_DAT12_DAT12位掩码
#define ADCx_DAT12_DAT12(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT12_DAT12_POS)   // [15:0] ADCx第12次采样数据

/* ADCx_DAT13(x = 0,1,2) */
#define ADCx_DAT13_DAT13_MAX  ((uint32_t)0xFFFF)                                   // ADCx_DAT13_DAT13最大值
#define ADCx_DAT13_DAT13_POS  0                                                    // ADCx_DAT13_DAT13起始位
#define ADCx_DAT13_DAT13_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT13_DAT13_POS) // ADCx_DAT13_DAT13位掩码
#define ADCx_DAT13_DAT13(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT13_DAT13_POS)   // [15:0] ADCx第13次采样数据

/* ADCx_DAT14(x = 0,1,2) */
#define ADCx_DAT14_DAT14_MAX  ((uint32_t)0xFFFF)                                   // ADCx_DAT14_DAT14最大值
#define ADCx_DAT14_DAT14_POS  0                                                    // ADCx_DAT14_DAT14起始位
#define ADCx_DAT14_DAT14_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT14_DAT14_POS) // ADCx_DAT14_DAT14位掩码
#define ADCx_DAT14_DAT14(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT14_DAT14_POS)   // [15:0] ADCx第14次采样数据

/* ADCx_DAT15(x = 0,1,2) */
#define ADCx_DAT15_DAT15_MAX  ((uint32_t)0xFFFF)                                   // ADCx_DAT15_DAT15最大值
#define ADCx_DAT15_DAT15_POS  0                                                    // ADCx_DAT15_DAT15起始位
#define ADCx_DAT15_DAT15_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DAT15_DAT15_POS) // ADCx_DAT15_DAT15位掩码
#define ADCx_DAT15_DAT15(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DAT15_DAT15_POS)   // [15:0] ADCx第15次采样数据

/* ADCx_PCHN0(x = 0,1,2) */
#define ADCx_PCHN0_PDS3_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN0_PDS3最大值
#define ADCx_PCHN0_PDS3_POS  12                                               // ADCx_PCHN0_PDS3起始位
#define ADCx_PCHN0_PDS3_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN0_PDS3_POS) // ADCx_PCHN0_PDS3位掩码
#define ADCx_PCHN0_PDS3(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN0_PDS3_POS)   // [15:12] ADCx第3次采样正端输入信号选择
#define ADCx_PCHN0_PDS2_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN0_PDS2最大值
#define ADCx_PCHN0_PDS2_POS  8                                                // ADCx_PCHN0_PDS2起始位
#define ADCx_PCHN0_PDS2_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN0_PDS2_POS) // ADCx_PCHN0_PDS2位掩码
#define ADCx_PCHN0_PDS2(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN0_PDS2_POS)   // [11:8] ADCx第2次采样正端输入信号选择
#define ADCx_PCHN0_PDS1_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN0_PDS1最大值
#define ADCx_PCHN0_PDS1_POS  4                                                // ADCx_PCHN0_PDS1起始位
#define ADCx_PCHN0_PDS1_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN0_PDS1_POS) // ADCx_PCHN0_PDS1位掩码
#define ADCx_PCHN0_PDS1(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN0_PDS1_POS)   // [7:4] ADCx第1次采样正端输入信号选择
#define ADCx_PCHN0_PDS0_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN0_PDS0最大值
#define ADCx_PCHN0_PDS0_POS  0                                                // ADCx_PCHN0_PDS0起始位
#define ADCx_PCHN0_PDS0_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN0_PDS0_POS) // ADCx_PCHN0_PDS0位掩码
#define ADCx_PCHN0_PDS0(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN0_PDS0_POS)   // [3:0] ADCx第0次采样正端输入信号选择

/* ADCx_PCHN1(x = 0,1,2) */
#define ADCx_PCHN1_PDS7_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN1_PDS7最大值
#define ADCx_PCHN1_PDS7_POS  12                                               // ADCx_PCHN1_PDS7起始位
#define ADCx_PCHN1_PDS7_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN1_PDS7_POS) // ADCx_PCHN1_PDS7位掩码
#define ADCx_PCHN1_PDS7(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN1_PDS7_POS)   // [15:12] ADCx第7次采样正端输入信号选择
#define ADCx_PCHN1_PDS6_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN1_PDS6最大值
#define ADCx_PCHN1_PDS6_POS  8                                                // ADCx_PCHN1_PDS6起始位
#define ADCx_PCHN1_PDS6_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN1_PDS6_POS) // ADCx_PCHN1_PDS6位掩码
#define ADCx_PCHN1_PDS6(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN1_PDS6_POS)   // [11:8] ADCx第6次采样正端输入信号选择
#define ADCx_PCHN1_PDS5_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN1_PDS5最大值
#define ADCx_PCHN1_PDS5_POS  4                                                // ADCx_PCHN1_PDS5起始位
#define ADCx_PCHN1_PDS5_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN1_PDS5_POS) // ADCx_PCHN1_PDS5位掩码
#define ADCx_PCHN1_PDS5(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN1_PDS5_POS)   // [7:4] ADCx第5次采样正端输入信号选择
#define ADCx_PCHN1_PDS4_MAX  ((uint32_t)0xF)                                  // ADCx_PCHN1_PDS4最大值
#define ADCx_PCHN1_PDS4_POS  0                                                // ADCx_PCHN1_PDS4起始位
#define ADCx_PCHN1_PDS4_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN1_PDS4_POS) // ADCx_PCHN1_PDS4位掩码
#define ADCx_PCHN1_PDS4(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN1_PDS4_POS)   // [3:0] ADCx第4次采样正端输入信号选择

/* ADCx_PCHN2(x = 0,1,2) */
#define ADCx_PCHN2_PDS11_MAX  ((uint32_t)0xF)                                   // ADCx_PCHN2_PDS11最大值
#define ADCx_PCHN2_PDS11_POS  12                                                // ADCx_PCHN2_PDS11起始位
#define ADCx_PCHN2_PDS11_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN2_PDS11_POS) // ADCx_PCHN2_PDS11位掩码
#define ADCx_PCHN2_PDS11(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN2_PDS11_POS)   // [15:12] ADCx第11次采样正端输入信号选择
#define ADCx_PCHN2_PDS10_MAX  ((uint32_t)0xF)                                   // ADCx_PCHN2_PDS10最大值
#define ADCx_PCHN2_PDS10_POS  8                                                 // ADCx_PCHN2_PDS10起始位
#define ADCx_PCHN2_PDS10_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN2_PDS10_POS) // ADCx_PCHN2_PDS10位掩码
#define ADCx_PCHN2_PDS10(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN2_PDS10_POS)   // [11:8] ADCx第10次采样正端输入信号选择
#define ADCx_PCHN2_PDS9_MAX   ((uint32_t)0xF)                                   // ADCx_PCHN2_PDS9最大值
#define ADCx_PCHN2_PDS9_POS   4                                                 // ADCx_PCHN2_PDS9起始位
#define ADCx_PCHN2_PDS9_MASK  (uint32_t)((uint32_t)0xF << ADCx_PCHN2_PDS9_POS)  // ADCx_PCHN2_PDS9位掩码
#define ADCx_PCHN2_PDS9(x)    (uint32_t)(((x) & 0xF) << ADCx_PCHN2_PDS9_POS)    // [7:4] ADCx第9次采样正端输入信号选择
#define ADCx_PCHN2_PDS8_MAX   ((uint32_t)0xF)                                   // ADCx_PCHN2_PDS8最大值
#define ADCx_PCHN2_PDS8_POS   0                                                 // ADCx_PCHN2_PDS8起始位
#define ADCx_PCHN2_PDS8_MASK  (uint32_t)((uint32_t)0xF << ADCx_PCHN2_PDS8_POS)  // ADCx_PCHN2_PDS8位掩码
#define ADCx_PCHN2_PDS8(x)    (uint32_t)(((x) & 0xF) << ADCx_PCHN2_PDS8_POS)    // [3:0] ADCx第8次采样正端输入信号选择

/* ADCx_PCHN3(x = 0,1,2) */
#define ADCx_PCHN3_PDS15_MAX  ((uint32_t)0xF)                                   // ADCx_PCHN3_PDS15最大值
#define ADCx_PCHN3_PDS15_POS  12                                                // ADCx_PCHN3_PDS15起始位
#define ADCx_PCHN3_PDS15_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN3_PDS15_POS) // ADCx_PCHN3_PDS15位掩码
#define ADCx_PCHN3_PDS15(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN3_PDS15_POS)   // [15:12] ADCx第15次采样正端输入信号选择
#define ADCx_PCHN3_PDS14_MAX  ((uint32_t)0xF)                                   // ADCx_PCHN3_PDS14最大值
#define ADCx_PCHN3_PDS14_POS  8                                                 // ADCx_PCHN3_PDS14起始位
#define ADCx_PCHN3_PDS14_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN3_PDS14_POS) // ADCx_PCHN3_PDS14位掩码
#define ADCx_PCHN3_PDS14(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN3_PDS14_POS)   // [11:8] ADCx第14次采样正端输入信号选择
#define ADCx_PCHN3_PDS13_MAX  ((uint32_t)0xF)                                   // ADCx_PCHN3_PDS13最大值
#define ADCx_PCHN3_PDS13_POS  4                                                 // ADCx_PCHN3_PDS13起始位
#define ADCx_PCHN3_PDS13_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN3_PDS13_POS) // ADCx_PCHN3_PDS13位掩码
#define ADCx_PCHN3_PDS13(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN3_PDS13_POS)   // [7:4] ADCx第13次采样正端输入信号选择
#define ADCx_PCHN3_PDS12_MAX  ((uint32_t)0xF)                                   // ADCx_PCHN3_PDS12最大值
#define ADCx_PCHN3_PDS12_POS  0                                                 // ADCx_PCHN3_PDS12起始位
#define ADCx_PCHN3_PDS12_MASK (uint32_t)((uint32_t)0xF << ADCx_PCHN3_PDS12_POS) // ADCx_PCHN3_PDS12位掩码
#define ADCx_PCHN3_PDS12(x)   (uint32_t)(((x) & 0xF) << ADCx_PCHN3_PDS12_POS)   // [3:0] ADCx第12次采样正端输入信号选择

/* ADCx_NCHN0(x = 0,1,2) */
#define ADCx_NCHN0_NDS3_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN0_NDS3最大值
#define ADCx_NCHN0_NDS3_POS  12                                               // ADCx_NCHN0_NDS3起始位
#define ADCx_NCHN0_NDS3_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN0_NDS3_POS) // ADCx_NCHN0_NDS3位掩码
#define ADCx_NCHN0_NDS3(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN0_NDS3_POS)   // [15:12] ADCx第3次采样负端输入信号选择
#define ADCx_NCHN0_NDS2_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN0_NDS2最大值
#define ADCx_NCHN0_NDS2_POS  8                                                // ADCx_NCHN0_NDS2起始位
#define ADCx_NCHN0_NDS2_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN0_NDS2_POS) // ADCx_NCHN0_NDS2位掩码
#define ADCx_NCHN0_NDS2(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN0_NDS2_POS)   // [11:8] ADCx第2次采样负端输入信号选择
#define ADCx_NCHN0_NDS1_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN0_NDS1最大值
#define ADCx_NCHN0_NDS1_POS  4                                                // ADCx_NCHN0_NDS1起始位
#define ADCx_NCHN0_NDS1_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN0_NDS1_POS) // ADCx_NCHN0_NDS1位掩码
#define ADCx_NCHN0_NDS1(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN0_NDS1_POS)   // [7:4] ADCx第1次采样负端输入信号选择
#define ADCx_NCHN0_NDS0_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN0_NDS0最大值
#define ADCx_NCHN0_NDS0_POS  0                                                // ADCx_NCHN0_NDS0起始位
#define ADCx_NCHN0_NDS0_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN0_NDS0_POS) // ADCx_NCHN0_NDS0位掩码
#define ADCx_NCHN0_NDS0(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN0_NDS0_POS)   // [3:0] ADCx第0次采样负端输入信号选择

/* ADCx_NCHN1(x = 0,1,2) */
#define ADCx_NCHN1_NDS7_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN1_NDS7最大值
#define ADCx_NCHN1_NDS7_POS  12                                               // ADCx_NCHN1_NDS7起始位
#define ADCx_NCHN1_NDS7_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN1_NDS7_POS) // ADCx_NCHN1_NDS7位掩码
#define ADCx_NCHN1_NDS7(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN1_NDS7_POS)   // [15:12] ADCx第7次采样负端信号选择
#define ADCx_NCHN1_NDS6_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN1_NDS6最大值
#define ADCx_NCHN1_NDS6_POS  8                                                // ADCx_NCHN1_NDS6起始位
#define ADCx_NCHN1_NDS6_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN1_NDS6_POS) // ADCx_NCHN1_NDS6位掩码
#define ADCx_NCHN1_NDS6(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN1_NDS6_POS)   // [11:8] ADCx第6次采样负端信号选择
#define ADCx_NCHN1_NDS5_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN1_NDS5最大值
#define ADCx_NCHN1_NDS5_POS  4                                                // ADCx_NCHN1_NDS5起始位
#define ADCx_NCHN1_NDS5_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN1_NDS5_POS) // ADCx_NCHN1_NDS5位掩码
#define ADCx_NCHN1_NDS5(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN1_NDS5_POS)   // [7:4] ADCx第5次采样负端信号选择
#define ADCx_NCHN1_NDS4_MAX  ((uint32_t)0xF)                                  // ADCx_NCHN1_NDS4最大值
#define ADCx_NCHN1_NDS4_POS  0                                                // ADCx_NCHN1_NDS4起始位
#define ADCx_NCHN1_NDS4_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN1_NDS4_POS) // ADCx_NCHN1_NDS4位掩码
#define ADCx_NCHN1_NDS4(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN1_NDS4_POS)   // [3:0] ADCx第4次采样负端信号选择

/* ADCx_NCHN2(x = 0,1,2) */
#define ADCx_NCHN2_NDS11_MAX  ((uint32_t)0xF)                                   // ADCx_NCHN2_NDS11最大值
#define ADCx_NCHN2_NDS11_POS  12                                                // ADCx_NCHN2_NDS11起始位
#define ADCx_NCHN2_NDS11_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN2_NDS11_POS) // ADCx_NCHN2_NDS11位掩码
#define ADCx_NCHN2_NDS11(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN2_NDS11_POS)   // [15:12] ADCx第11次采样负端信号选择
#define ADCx_NCHN2_NDS10_MAX  ((uint32_t)0xF)                                   // ADCx_NCHN2_NDS10最大值
#define ADCx_NCHN2_NDS10_POS  8                                                 // ADCx_NCHN2_NDS10起始位
#define ADCx_NCHN2_NDS10_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN2_NDS10_POS) // ADCx_NCHN2_NDS10位掩码
#define ADCx_NCHN2_NDS10(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN2_NDS10_POS)   // [11:8] ADCx第10次采样负端信号选择
#define ADCx_NCHN2_NDS9_MAX   ((uint32_t)0xF)                                   // ADCx_NCHN2_NDS9最大值
#define ADCx_NCHN2_NDS9_POS   4                                                 // ADCx_NCHN2_NDS9起始位
#define ADCx_NCHN2_NDS9_MASK  (uint32_t)((uint32_t)0xF << ADCx_NCHN2_NDS9_POS)  // ADCx_NCHN2_NDS9位掩码
#define ADCx_NCHN2_NDS9(x)    (uint32_t)(((x) & 0xF) << ADCx_NCHN2_NDS9_POS)    // [7:4] ADCx第9次采样负端信号选择
#define ADCx_NCHN2_NDS8_MAX   ((uint32_t)0xF)                                   // ADCx_NCHN2_NDS8最大值
#define ADCx_NCHN2_NDS8_POS   0                                                 // ADCx_NCHN2_NDS8起始位
#define ADCx_NCHN2_NDS8_MASK  (uint32_t)((uint32_t)0xF << ADCx_NCHN2_NDS8_POS)  // ADCx_NCHN2_NDS8位掩码
#define ADCx_NCHN2_NDS8(x)    (uint32_t)(((x) & 0xF) << ADCx_NCHN2_NDS8_POS)    // [3:0] ADCx第8次采样负端信号选择

/* ADCx_NCHN3(x = 0,1,2) */
#define ADCx_NCHN3_NDS15_MAX  ((uint32_t)0xF)                                   // ADCx_NCHN3_NDS15最大值
#define ADCx_NCHN3_NDS15_POS  12                                                // ADCx_NCHN3_NDS15起始位
#define ADCx_NCHN3_NDS15_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN3_NDS15_POS) // ADCx_NCHN3_NDS15位掩码
#define ADCx_NCHN3_NDS15(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN3_NDS15_POS)   // [15:12] ADCx第15次采样负端信号选择
#define ADCx_NCHN3_NDS14_MAX  ((uint32_t)0xF)                                   // ADCx_NCHN3_NDS14最大值
#define ADCx_NCHN3_NDS14_POS  8                                                 // ADCx_NCHN3_NDS14起始位
#define ADCx_NCHN3_NDS14_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN3_NDS14_POS) // ADCx_NCHN3_NDS14位掩码
#define ADCx_NCHN3_NDS14(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN3_NDS14_POS)   // [11:8] ADCx第14次采样负端信号选择
#define ADCx_NCHN3_NDS13_MAX  ((uint32_t)0xF)                                   // ADCx_NCHN3_NDS13最大值
#define ADCx_NCHN3_NDS13_POS  4                                                 // ADCx_NCHN3_NDS13起始位
#define ADCx_NCHN3_NDS13_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN3_NDS13_POS) // ADCx_NCHN3_NDS13位掩码
#define ADCx_NCHN3_NDS13(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN3_NDS13_POS)   // [7:4] ADCx第13次采样负端信号选择
#define ADCx_NCHN3_NDS12_MAX  ((uint32_t)0xF)                                   // ADCx_NCHN3_NDS12最大值
#define ADCx_NCHN3_NDS12_POS  0                                                 // ADCx_NCHN3_NDS12起始位
#define ADCx_NCHN3_NDS12_MASK (uint32_t)((uint32_t)0xF << ADCx_NCHN3_NDS12_POS) // ADCx_NCHN3_NDS12位掩码
#define ADCx_NCHN3_NDS12(x)   (uint32_t)(((x) & 0xF) << ADCx_NCHN3_NDS12_POS)   // [3:0] ADCx第12次采样负端信号选择

/* ADCx_CHNT(x = 0,1,2) */
#define ADCx_CHNT_S2_MAX  ((uint32_t)0xF)                               // ADCx_CHNT_S2最大值
#define ADCx_CHNT_S2_POS  4                                             // ADCx_CHNT_S2起始位
#define ADCx_CHNT_S2_MASK (uint32_t)((uint32_t)0xF << ADCx_CHNT_S2_POS) // ADCx_CHNT_S2位掩码
#define ADCx_CHNT_S2(x)   (uint32_t)(((x) & 0xF) << ADCx_CHNT_S2_POS)   // [7:4] 第二段采样通道数
#define ADCx_CHNT_S1_MAX  ((uint32_t)0xF)                               // ADCx_CHNT_S1最大值
#define ADCx_CHNT_S1_POS  0                                             // ADCx_CHNT_S1起始位
#define ADCx_CHNT_S1_MASK (uint32_t)((uint32_t)0xF << ADCx_CHNT_S1_POS) // ADCx_CHNT_S1位掩码
#define ADCx_CHNT_S1(x)   (uint32_t)(((x) & 0xF) << ADCx_CHNT_S1_POS)   // [3:0] 第一段采样通道数

/* ADCx_GAIN(x = 0,1,2) */
#define ADCx_GAIN_G15_BIT BIT15 // [15] DAT15增益选择
#define ADCx_GAIN_G14_BIT BIT14 // [14] DAT14增益选择
#define ADCx_GAIN_G13_BIT BIT13 // [13] DAT13增益选择
#define ADCx_GAIN_G12_BIT BIT12 // [12] DAT12增益选择
#define ADCx_GAIN_G11_BIT BIT11 // [11] DAT11增益选择
#define ADCx_GAIN_G10_BIT BIT10 // [10] DAT10增益选择
#define ADCx_GAIN_G9_BIT  BIT9  // [9] DAT9增益选择
#define ADCx_GAIN_G8_BIT  BIT8  // [8] DAT8增益选择
#define ADCx_GAIN_G7_BIT  BIT7  // [7] DAT7增益选择
#define ADCx_GAIN_G6_BIT  BIT6  // [6] DAT6增益选择
#define ADCx_GAIN_G5_BIT  BIT5  // [5] DAT5增益选择
#define ADCx_GAIN_G4_BIT  BIT4  // [4] DAT4增益选择
#define ADCx_GAIN_G3_BIT  BIT3  // [3] DAT3增益选择
#define ADCx_GAIN_G2_BIT  BIT2  // [2] DAT2增益选择
#define ADCx_GAIN_G1_BIT  BIT1  // [1] DAT1增益选择
#define ADCx_GAIN_G0_BIT  BIT0  // [0] DAT0增益选择

/* ADCx_CFG(x = 0,1,2) */
#define ADCx_CFG_NSMP_BIT       BIT12                                          // [12] 0:单段采样，1:两段采样
#define ADCx_CFG_FSM_RS_BIT     BIT11                                          // [11] 状态机复位控制信号。软件写入1产生复位，将ADC内部状态机回到初始状态，完成后自动回到0。该复位控制，不影响ADC其它寄存器的配置值。 读取该位返回ADC当前状态，1表示ADC目前正在采样转换工作中，0表示空闲。
#define ADCx_CFG_DATA_ALIGN_BIT BIT10                                          // [10] ADC_DAT对齐方式 0：左对齐，右端补2’h0， 1：右对齐，左端补2bit符号位
#define ADCx_CFG_CSMP_BIT       BIT8                                           // [8] 连续采样模式 0：不开启 1：开启连续采样模式，触发到来后，ADC即开始采样转换，完成所有信号的转换后，无需等待触发立即从第0个信号开始新一轮的采样转换
#define ADCx_CFG_TCNT_MAX       ((uint32_t)0xF)                                // ADCx_CFG_TCNT最大值
#define ADCx_CFG_TCNT_POS       4                                              // ADCx_CFG_TCNT起始位
#define ADCx_CFG_TCNT_MASK      (uint32_t)((uint32_t)0xF << ADCx_CFG_TCNT_POS) // ADCx_CFG_TCNT位掩码
#define ADCx_CFG_TCNT(x)        (uint32_t)(((x) & 0xF) << ADCx_CFG_TCNT_POS)   // [7:4] TCNT只在单段采样下有效，两段采样时配置实际上不会生效。 触发一次采样所需的事件数。 0：表示需要发生1次事件才能触发一次采样 1：表示需要发生2次事件才能触发一次采样 …… 15：表示需要发生16次事件才能触发一次采样
#define ADCx_CFG_TROVS_BIT      BIT3                                           // [3] 过采样触发模式 0：一次触发即连续过采样多次至OVSR，并将数据平均后存入，可以配置采样多个通道，每个通道都采样OVSR次后才进行下一个通道的采样。 1：一次触发只进行一次采样转换，需要OVSR次触发才完成足够数据的采集并进行平均，而后存入数据寄存器。受到累加器个数限制，在此种配置下，ADCx_CHNT只能配置采样一个通道。
#define ADCx_CFG_OVSR_MAX       ((uint32_t)0x7)                                // ADCx_CFG_OVSR最大值
#define ADCx_CFG_OVSR_POS       0                                              // ADCx_CFG_OVSR起始位
#define ADCx_CFG_OVSR_MASK      (uint32_t)((uint32_t)0x7 << ADCx_CFG_OVSR_POS) // ADCx_CFG_OVSR位掩码
#define ADCx_CFG_OVSR(x)        (uint32_t)(((x) & 0x7) << ADCx_CFG_OVSR_POS)   // [2:0] 过采样率 0：1，默认1次采样即存入数据 1：2次采后存入数据 2：4次采样后存入数据 3：8次采样后存入数据 4：16次采样后存入数据 5：32次采样后存入数据 6：64次采样后存入数据 7：128次采样后存入数据

/* ADCx_TRIG(x = 0,1,2) */
#define ADCx_TRIG_UTIMER4_CMP1_EN_BIT BIT25 // [25] UTIMER4比较事件1触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER4_CMP0_EN_BIT BIT24 // [24] UTIMER4比较事件0触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER3_CMP1_EN_BIT BIT23 // [23] UTIMER3比较事件1触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER3_CMP0_EN_BIT BIT22 // [22] UTIMER3比较事件0触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER2_CMP1_EN_BIT BIT21 // [21] UTIMER2比较事件1触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER2_CMP0_EN_BIT BIT20 // [20] UTIMER2比较事件0触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER1_CMP1_EN_BIT BIT19 // [19] UTIMER1比较事件1触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER1_CMP0_EN_BIT BIT18 // [18] UTIMER1比较事件0触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER0_CMP1_EN_BIT BIT17 // [17] UTIMER0比较事件1触发ADC采样使能，高有效
#define ADCx_TRIG_UTIMER0_CMP0_EN_BIT BIT16 // [16] UTIMER0比较事件0触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM1_T3_EN_BIT    BIT7  // [7] MCPWM1 T3事件触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM1_T2_EN_BIT    BIT6  // [6] MCPWM1 T2事件触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM1_T1_EN_BIT    BIT5  // [5] MCPWM1 T1事件触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM1_T0_EN_BIT    BIT4  // [4] MCPWM1 T0事件触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM0_T3_EN_BIT    BIT3  // [3] MCPWM0 T3事件触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM0_T2_EN_BIT    BIT2  // [2] MCPWM0 T2事件触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM0_T1_EN_BIT    BIT1  // [1] MCPWM0 T1事件触发ADC采样使能，高有效
#define ADCx_TRIG_MCPWM0_T0_EN_BIT    BIT0  // [0] MCPWM0 T0事件触发ADC采样使能，高有效

/* ADCx_SWT(x = 0,1,2) */
#define ADCx_SWT_SWT_MAX  ((uint32_t)0xFFFF)                               // ADCx_SWT_SWT最大值
#define ADCx_SWT_SWT_POS  0                                                // ADCx_SWT_SWT起始位
#define ADCx_SWT_SWT_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_SWT_SWT_POS) // ADCx_SWT_SWT位掩码
#define ADCx_SWT_SWT(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_SWT_SWT_POS)   // [15:0] 写入数据为0x5AA5时，产生一次软件触发

/* ADCx_DC0(x = 0,1,2) */
#define ADCx_DC0_DC_OFFSET_MAX  ((uint32_t)0xFFFF)                                     // ADCx_DC0_DC_OFFSET最大值
#define ADCx_DC0_DC_OFFSET_POS  0                                                      // ADCx_DC0_DC_OFFSET起始位
#define ADCx_DC0_DC_OFFSET_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DC0_DC_OFFSET_POS) // ADCx_DC0_DC_OFFSET位掩码
#define ADCx_DC0_DC_OFFSET(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DC0_DC_OFFSET_POS)   // [15:0] ADC采样电路DC offset

/* ADCx_AMC0(x = 0,1,2) */
#define ADCx_AMC0_AM_CALI_MAX  ((uint32_t)0x3FF)                                    // ADCx_AMC0_AM_CALI最大值
#define ADCx_AMC0_AM_CALI_POS  0                                                    // ADCx_AMC0_AM_CALI起始位
#define ADCx_AMC0_AM_CALI_MASK (uint32_t)((uint32_t)0x3FF << ADCx_AMC0_AM_CALI_POS) // ADCx_AMC0_AM_CALI位掩码
#define ADCx_AMC0_AM_CALI(x)   (uint32_t)(((x) & 0x3FF) << ADCx_AMC0_AM_CALI_POS)   // [9:0] ADC 采样电路增益校正系数

/* ADCx_DC1(x = 0,1,2) */
#define ADCx_DC1_DC_OFFSET_MAX  ((uint32_t)0xFFFF)                                     // ADCx_DC1_DC_OFFSET最大值
#define ADCx_DC1_DC_OFFSET_POS  0                                                      // ADCx_DC1_DC_OFFSET起始位
#define ADCx_DC1_DC_OFFSET_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_DC1_DC_OFFSET_POS) // ADCx_DC1_DC_OFFSET位掩码
#define ADCx_DC1_DC_OFFSET(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_DC1_DC_OFFSET_POS)   // [15:0] ADC采样电路DC offset

/* ADCx_AMC1(x = 0,1,2) */
#define ADCx_AMC1_AM_CALI_MAX  ((uint32_t)0x3FF)                                    // ADCx_AMC1_AM_CALI最大值
#define ADCx_AMC1_AM_CALI_POS  0                                                    // ADCx_AMC1_AM_CALI起始位
#define ADCx_AMC1_AM_CALI_MASK (uint32_t)((uint32_t)0x3FF << ADCx_AMC1_AM_CALI_POS) // ADCx_AMC1_AM_CALI位掩码
#define ADCx_AMC1_AM_CALI(x)   (uint32_t)(((x) & 0x3FF) << ADCx_AMC1_AM_CALI_POS)   // [9:0] ADC 采样电路增益校正系数

/* ADCx_IE(x = 0,1,2) */
#define ADCx_IE_HERR_RE_BIT BIT14 // [14] 硬件触发发生在非空闲状态DMA请求使能
#define ADCx_IE_SERR_RE_BIT BIT13 // [13] 软件触发发生在非空闲状态DMA请求使能
#define ADCx_IE_AWD1_RE_BIT BIT11 // [11] 阈值监测1超限DMA请求使能
#define ADCx_IE_AWD0_RE_BIT BIT10 // [10] 阈值监测0超限DMA请求使能
#define ADCx_IE_SF2_RE_BIT  BIT9  // [9] 第二段采样完成DMA请求使能
#define ADCx_IE_SF1_RE_BIT  BIT8  // [8] 第一段采样完成DMA请求使能
#define ADCx_IE_HERR_IE_BIT BIT6  // [6] 硬件触发发生在非空闲状态中断使能
#define ADCx_IE_SERR_IE_BIT BIT5  // [5] 软件触发发生在非空闲状态中断使能
#define ADCx_IE_AWD1_IE_BIT BIT3  // [3] 阈值监测1超限中断使能
#define ADCx_IE_AWD0_IE_BIT BIT2  // [2] 阈值监测0超限中断使能
#define ADCx_IE_SF2_IE_BIT  BIT1  // [1] 第二段采样完成中断使能
#define ADCx_IE_SF1_IE_BIT  BIT0  // [0] 第一段采样完成中断使能

/* ADCx_IF(x = 0,1,2) */
#define ADCx_IF_HERR_IF_BIT BIT6 // [6] 硬件触发发生在非空闲状态中断标志
#define ADCx_IF_SERR_IF_BIT BIT5 // [5] 软件触发发生在非空闲状态中断标志
#define ADCx_IF_AWD1_IF_BIT BIT3 // [3] 阈值监测1超限中断标志
#define ADCx_IF_AWD0_IF_BIT BIT2 // [2] 阈值监测0超限中断标志
#define ADCx_IF_SF2_IF_BIT  BIT1 // [1] 第二段采样完成中断标志
#define ADCx_IF_SF1_IF_BIT  BIT0 // [0] 第一段采样完成中断标志

/* ADCx_TH0 (x = 0,1,2) */
#define ADCx_TH0_HTH_MAX  ((uint32_t)0x3FFF)                               // ADCx_TH0_HTH最大值
#define ADCx_TH0_HTH_POS  16                                               // ADCx_TH0_HTH起始位
#define ADCx_TH0_HTH_MASK (uint32_t)((uint32_t)0x3FFF << ADCx_TH0_HTH_POS) // ADCx_TH0_HTH位掩码
#define ADCx_TH0_HTH(x)   (uint32_t)(((x) & 0x3FFF) << ADCx_TH0_HTH_POS)   // [29:16] ADC模拟看门狗0上阈值
#define ADCx_TH0_LTH_MAX  ((uint32_t)0x3FFF)                               // ADCx_TH0_LTH最大值
#define ADCx_TH0_LTH_POS  0                                                // ADCx_TH0_LTH起始位
#define ADCx_TH0_LTH_MASK (uint32_t)((uint32_t)0x3FFF << ADCx_TH0_LTH_POS) // ADCx_TH0_LTH位掩码
#define ADCx_TH0_LTH(x)   (uint32_t)(((x) & 0x3FFF) << ADCx_TH0_LTH_POS)   // [13:0] ADC模拟看门狗0下阈值

/* ADCx_GEN0 (x = 0,1,2) */
#define ADCx_GEN0_GEN_MAX  ((uint32_t)0xFFFF)                                // ADCx_GEN0_GEN最大值
#define ADCx_GEN0_GEN_POS  0                                                 // ADCx_GEN0_GEN起始位
#define ADCx_GEN0_GEN_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_GEN0_GEN_POS) // ADCx_GEN0_GEN位掩码
#define ADCx_GEN0_GEN(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_GEN0_GEN_POS)   // [15:0] ADC模拟看门狗0对应使能位 BIT0: DAT0看门狗监测使能 BIT1: DAT1看门狗监测使能 …… BIT15：DAT15看门狗监测使能

/* ADCx_TH1(x = 0,1,2) */
#define ADCx_TH1_HTH_MAX  ((uint32_t)0x3FFF)                               // ADCx_TH1_HTH最大值
#define ADCx_TH1_HTH_POS  16                                               // ADCx_TH1_HTH起始位
#define ADCx_TH1_HTH_MASK (uint32_t)((uint32_t)0x3FFF << ADCx_TH1_HTH_POS) // ADCx_TH1_HTH位掩码
#define ADCx_TH1_HTH(x)   (uint32_t)(((x) & 0x3FFF) << ADCx_TH1_HTH_POS)   // [29:16] ADC模拟看门狗1上阈值
#define ADCx_TH1_LTH_MAX  ((uint32_t)0x3FFF)                               // ADCx_TH1_LTH最大值
#define ADCx_TH1_LTH_POS  0                                                // ADCx_TH1_LTH起始位
#define ADCx_TH1_LTH_MASK (uint32_t)((uint32_t)0x3FFF << ADCx_TH1_LTH_POS) // ADCx_TH1_LTH位掩码
#define ADCx_TH1_LTH(x)   (uint32_t)(((x) & 0x3FFF) << ADCx_TH1_LTH_POS)   // [13:0] ADC模拟看门狗1下阈值

/* ADCx_GEN1 (x = 0,1,2) */
#define ADCx_GEN1_GEN_MAX  ((uint32_t)0xFFFF)                                // ADCx_GEN1_GEN最大值
#define ADCx_GEN1_GEN_POS  0                                                 // ADCx_GEN1_GEN起始位
#define ADCx_GEN1_GEN_MASK (uint32_t)((uint32_t)0xFFFF << ADCx_GEN1_GEN_POS) // ADCx_GEN1_GEN位掩码
#define ADCx_GEN1_GEN(x)   (uint32_t)(((x) & 0xFFFF) << ADCx_GEN1_GEN_POS)   // [15:0] ADC模拟看门狗1对应使能位 BIT0: DAT0看门狗监测使能 BIT1: DAT1看门狗监测使能 …… BIT15：DAT15看门狗监测使能

/* UTIMER0_CFG Timer0配置寄存器 */
#define UTIMER0_CFG_EN_BIT            BIT31                                                // [31] Timer模块整体使能，高有效
#define UTIMER0_CFG_CAP1_CLR_EN_BIT   BIT27                                                // [27] 当发生CAP1捕获事件时，清零Timer计数器，高有效
#define UTIMER0_CFG_CAP0_CLR_EN_BIT   BIT26                                                // [26] 当发生CAP0捕获事件时，清零Timer计数器，高有效
#define UTIMER0_CFG_ONE_TRIG_BIT      BIT25                                                // [25] 在比较模式下，且EN为0时，写1触发Timer发送一个周期的特定占空比的脉冲，此位在脉冲发送期间内读为1，一个Timer周期后，自动清零。
#define UTIMER0_CFG_ETON_BIT          BIT24                                                // [24] Timer计数器计数使能配置。默认为0。 0: 自动运行 1: 等待外部事件触发计数，计数一个周期后停止 外部事件通过UTIMER0_EVT寄存器进行配置。
#define UTIMER0_CFG_CLK_DIV_MAX       ((uint32_t)0x7)                                      // UTIMER0_CFG_CLK_DIV最大值
#define UTIMER0_CFG_CLK_DIV_POS       20                                                   // UTIMER0_CFG_CLK_DIV起始位
#define UTIMER0_CFG_CLK_DIV_MASK      (uint32_t)((uint32_t)0x7 << UTIMER0_CFG_CLK_DIV_POS) // UTIMER0_CFG_CLK_DIV位掩码
#define UTIMER0_CFG_CLK_DIV(x)        (uint32_t)(((x) & 0x7) << UTIMER0_CFG_CLK_DIV_POS)   // [22:20] Timer计数器频率配置，计数器计数频率是系统主时钟频率的2CLK_DIV分频。默认值为0，不分频。 3’h0: 1分频 3’h1: 2分频 3’h2: 4分频 3’h3: 8分频 3’h4: 16分频 3’h5: 32分频 3’h6: 64分频 3’h7: 128分频
#define UTIMER0_CFG_CLK_SRC_MAX       ((uint32_t)0xF)                                      // UTIMER0_CFG_CLK_SRC最大值
#define UTIMER0_CFG_CLK_SRC_POS       16                                                   // UTIMER0_CFG_CLK_SRC起始位
#define UTIMER0_CFG_CLK_SRC_MASK      (uint32_t)((uint32_t)0xF << UTIMER0_CFG_CLK_SRC_POS) // UTIMER0_CFG_CLK_SRC位掩码
#define UTIMER0_CFG_CLK_SRC(x)        (uint32_t)(((x) & 0xF) << UTIMER0_CFG_CLK_SRC_POS)   // [19:16] Timer 时钟源 4’h0: 芯片系统时钟 4’h1: 芯片系统时钟 4’h2: Timer0通道0外部时钟信号 4’h3: Timer0通道1外部时钟信号 4’h4: Timer1通道0外部时钟信号 4’h5: Timer1通道1外部时钟信号 4’h6: Timer2通道0外部时钟信号 4’h7: Timer2通道1外部时钟信号 4’h8: Timer3通道0外部时钟信号 4’h9: Timer3通道1外部时钟信号 4’hA: Timer4通道0外部时钟信号 4’hB: Timer4通道1外部时钟信号
#define UTIMER0_CFG_SRC1_MAX          ((uint32_t)0xF)                                      // UTIMER0_CFG_SRC1最大值
#define UTIMER0_CFG_SRC1_POS          12                                                   // UTIMER0_CFG_SRC1起始位
#define UTIMER0_CFG_SRC1_MASK         (uint32_t)((uint32_t)0xF << UTIMER0_CFG_SRC1_POS)    // UTIMER0_CFG_SRC1位掩码
#define UTIMER0_CFG_SRC1(x)           (uint32_t)(((x) & 0xF) << UTIMER0_CFG_SRC1_POS)      // [15:12] Timer捕获模式通道1信号来源。默认为3’h1。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER0_CFG_CH1_POL_BIT       BIT11                                                // [11] Timer通道1在比较模式下的输出极性控制，当计数器计数值回零时的输出值。
#define UTIMER0_CFG_CH1_MODE_BIT      BIT10                                                // [10] Timer通道1的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道1计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道1输入信号发生捕获事件时，将计数器计数值存入Timer通道1比较捕获寄存器。
#define UTIMER0_CFG_CH1_FE_CAP_EN_BIT BIT9                                                 // [9] Timer通道1下降沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER0_CFG_CH1_RE_CAP_EN_BIT BIT8                                                 // [8] Timer通道1上升沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。
#define UTIMER0_CFG_SRC0_MAX          ((uint32_t)0xF)                                      // UTIMER0_CFG_SRC0最大值
#define UTIMER0_CFG_SRC0_POS          4                                                    // UTIMER0_CFG_SRC0起始位
#define UTIMER0_CFG_SRC0_MASK         (uint32_t)((uint32_t)0xF << UTIMER0_CFG_SRC0_POS)    // UTIMER0_CFG_SRC0位掩码
#define UTIMER0_CFG_SRC0(x)           (uint32_t)(((x) & 0xF) << UTIMER0_CFG_SRC0_POS)      // [7:4] Timer捕获模式通道0信号来源。默认为3’h0。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER0_CFG_CH0_POL_BIT       BIT3                                                 // [3] Timer通道0在比较模式下的输出极性控制：当计数器计数值回零时的输出值。
#define UTIMER0_CFG_CH0_MODE_BIT      BIT2                                                 // [2] Timer通道0的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道0计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道0输入信号发生捕获事件时，将计数器计数值存入Timer通道0比较捕获寄存器。
#define UTIMER0_CFG_CH0_FE_CAP_EN_BIT BIT1                                                 // [1] Timer通道0下降沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER0_CFG_CH0_RE_CAP_EN_BIT BIT0                                                 // [0] Timer通道0上升沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。

/* UTIMER0_TH Timer0门限寄存器 */
#define UTIMER0_TH_TH_MAX  ((uint32_t)0xFFFF)                                // UTIMER0_TH_TH最大值
#define UTIMER0_TH_TH_POS  0                                                 // UTIMER0_TH_TH起始位
#define UTIMER0_TH_TH_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER0_TH_TH_POS) // UTIMER0_TH_TH位掩码
#define UTIMER0_TH_TH(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER0_TH_TH_POS)   // [15:0] Timer 计数器计数门限。计数器从0计数到TH值后再次回0开始计数

/* UTIMER0_CNT Timer0计数寄存器 */
#define UTIMER0_CNT_CNT_MAX  ((uint32_t)0xFFFF)                                  // UTIMER0_CNT_CNT最大值
#define UTIMER0_CNT_CNT_POS  0                                                   // UTIMER0_CNT_CNT起始位
#define UTIMER0_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER0_CNT_CNT_POS) // UTIMER0_CNT_CNT位掩码
#define UTIMER0_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER0_CNT_CNT_POS)   // [15:0] Timer 0计数器当前计数值。写操作可以写入新的计数值。

/* UTIMER0_CMP0 Timer0通道0比较捕获寄存器 */
#define UTIMER0_CMP0_CMP0_MAX  ((uint32_t)0xFFFF)                                    // UTIMER0_CMP0_CMP0最大值
#define UTIMER0_CMP0_CMP0_POS  0                                                     // UTIMER0_CMP0_CMP0起始位
#define UTIMER0_CMP0_CMP0_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER0_CMP0_CMP0_POS) // UTIMER0_CMP0_CMP0位掩码
#define UTIMER0_CMP0_CMP0(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER0_CMP0_CMP0_POS)   // [15:0] Timer 通道0工作在比较模式时，当计数器计数值等于CMP0时，发生比较事件。 Timer 通道0工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP0寄存器。

/* UTIMER0_CMP1 Timer0通道1比较捕获寄存器 */
#define UTIMER0_CMP1_CMP1_MAX  ((uint32_t)0xFFFF)                                    // UTIMER0_CMP1_CMP1最大值
#define UTIMER0_CMP1_CMP1_POS  0                                                     // UTIMER0_CMP1_CMP1起始位
#define UTIMER0_CMP1_CMP1_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER0_CMP1_CMP1_POS) // UTIMER0_CMP1_CMP1位掩码
#define UTIMER0_CMP1_CMP1(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER0_CMP1_CMP1_POS)   // [15:0] Timer 通道1工作在比较模式时，当计数器计数值等于CMP1时，发生比较事件。 Timer 通道1工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP1寄存器。

/* UTIMER0_EVT Timer0外部事件选择寄存器 */
#define UTIMER0_EVT_EVT_SRC_MAX  ((uint32_t)0x1F)                                      // UTIMER0_EVT_EVT_SRC最大值
#define UTIMER0_EVT_EVT_SRC_POS  0                                                     // UTIMER0_EVT_EVT_SRC起始位
#define UTIMER0_EVT_EVT_SRC_MASK (uint32_t)((uint32_t)0x1F << UTIMER0_EVT_EVT_SRC_POS) // UTIMER0_EVT_EVT_SRC位掩码
#define UTIMER0_EVT_EVT_SRC(x)   (uint32_t)(((x) & 0x1F) << UTIMER0_EVT_EVT_SRC_POS)   // [4:0] Timer外部事件选择寄存器，本寄存器需要配合UTIMER0_CFG.ETON使用。ETON为高时，根据本寄存器选择触发Timer计数的事件。 需要注意的是，Timer自身的比较事件无法触发Timer进行计数。 0：TIMER0 通道0比较事件 1：TIMER0 通道1比较事件 2：TIMER1 通道0比较事件 3：TIMER1 通道1比较事件 4：TIMER2 通道0比较事件 5：TIMER2 通道1比较事件 6：TIMER3 通道0比较事件 7：TIMER3 通道1比较事件 8：TIMER4 通道0比较事件 9：TIMER4 通道1比较事件 10：MCPWM0 TADC[0]比较事件 11：MCPWM0 TADC[1]比较事件 12：MCPWM0 TADC[2]比较事件 13：MCPWM0 TADC[3]比较事件 14：MCPWM1 TADC[0]比较事件 15：MCPWM1 TADC[1]比较事件 16：MCPWM1 TADC[2]比较事件 17：MCPWM1 TADC[3]比较事件

/* UTIMER0_FLT Timer0滤波控制寄存器 */
#define UTIMER0_FLT_FLT_MAX  ((uint32_t)0xFF)                                  // UTIMER0_FLT_FLT最大值
#define UTIMER0_FLT_FLT_POS  0                                                 // UTIMER0_FLT_FLT起始位
#define UTIMER0_FLT_FLT_MASK (uint32_t)((uint32_t)0xFF << UTIMER0_FLT_FLT_POS) // UTIMER0_FLT_FLT位掩码
#define UTIMER0_FLT_FLT(x)   (uint32_t)(((x) & 0xFF) << UTIMER0_FLT_FLT_POS)   // [7:0] 通道0/1信号滤波宽度选择。取值范围0~255。 FLT为0时，不对通道进行滤波。 FLT不为0时，对通道信号进行滤波：滤波宽度为FLT×8。当通道信号电平稳定超过FLT×8个系统时钟周期宽度时，滤波器输出更新；否则，滤波器保持当前的输出不变。

/* UTIMER0_IE Timer0中断使能寄存器 */
#define UTIMER0_IE_ZC_RE_BIT  BIT10 // [10] Timer计数器过0事件DMA请求使能，高电平有效。
#define UTIMER0_IE_CH1_RE_BIT BIT9  // [9] Timer通道1比较/捕获DMA请求使能，高电平有效。
#define UTIMER0_IE_CH0_RE_BIT BIT8  // [8] Timer通道0比较/捕获DMA请求使能，高电平有效。
#define UTIMER0_IE_ZC_IE_BIT  BIT2  // [2] Timer计数器过0中断使能，高电平有效。
#define UTIMER0_IE_CH1_IE_BIT BIT1  // [1] Timer通道1比较/捕获中断使能，高电平有效。
#define UTIMER0_IE_CH0_IE_BIT BIT0  // [0] Timer通道0比较/捕获中断使能，高电平有效。

/* UTIMER0_IF Timer0中断标志寄存器 */
#define UTIMER0_IF_ZC_IF_BIT  BIT2 // [2] Timer计数器过0中断标志。高电平有效，写1清0
#define UTIMER0_IF_CH1_IF_BIT BIT1 // [1] Timer通道1比较/捕获中断标志。高电平有效，写1清0
#define UTIMER0_IF_CH0_IF_BIT BIT0 // [0] Timer通道0比较/捕获中断标志。高电平有效，写1清0

/* UTIMER1_CFG Timer1配置寄存器 */
#define UTIMER1_CFG_EN_BIT            BIT31                                                // [31] Timer模块整体使能，高有效
#define UTIMER1_CFG_CAP1_CLR_EN_BIT   BIT27                                                // [27] 当发生CAP1捕获事件时，清零Timer计数器，高有效
#define UTIMER1_CFG_CAP0_CLR_EN_BIT   BIT26                                                // [26] 当发生CAP0捕获事件时，清零Timer计数器，高有效
#define UTIMER1_CFG_ONE_TRIG_BIT      BIT25                                                // [25] 在比较模式下，且EN为0时，写1触发Timer发送一个周期的特定占空比的脉冲，此位在脉冲发送期间内读为1，一个Timer周期后，自动清零。
#define UTIMER1_CFG_ETON_BIT          BIT24                                                // [24] Timer计数器计数使能配置。默认为0。 0: 自动运行 1: 等待外部事件触发计数，计数一个周期后停止 外部事件通过UTIMER1_EVT寄存器进行配置。
#define UTIMER1_CFG_CLK_DIV_MAX       ((uint32_t)0x7)                                      // UTIMER1_CFG_CLK_DIV最大值
#define UTIMER1_CFG_CLK_DIV_POS       20                                                   // UTIMER1_CFG_CLK_DIV起始位
#define UTIMER1_CFG_CLK_DIV_MASK      (uint32_t)((uint32_t)0x7 << UTIMER1_CFG_CLK_DIV_POS) // UTIMER1_CFG_CLK_DIV位掩码
#define UTIMER1_CFG_CLK_DIV(x)        (uint32_t)(((x) & 0x7) << UTIMER1_CFG_CLK_DIV_POS)   // [22:20] Timer计数器频率配置，计数器计数频率是系统主时钟频率的2CLK_DIV分频。默认值为0，不分频。 3’h0: 1分频 3’h1: 2分频 3’h2: 4分频 3’h3: 8分频 3’h4: 16分频 3’h5: 32分频 3’h6: 64分频 3’h7: 128分频
#define UTIMER1_CFG_CLK_SRC_MAX       ((uint32_t)0xF)                                      // UTIMER1_CFG_CLK_SRC最大值
#define UTIMER1_CFG_CLK_SRC_POS       16                                                   // UTIMER1_CFG_CLK_SRC起始位
#define UTIMER1_CFG_CLK_SRC_MASK      (uint32_t)((uint32_t)0xF << UTIMER1_CFG_CLK_SRC_POS) // UTIMER1_CFG_CLK_SRC位掩码
#define UTIMER1_CFG_CLK_SRC(x)        (uint32_t)(((x) & 0xF) << UTIMER1_CFG_CLK_SRC_POS)   // [19:16] Timer 时钟源 4’h0: 芯片系统时钟 4’h1: 芯片系统时钟 4’h2: Timer0通道0外部时钟信号 4’h3: Timer0通道1外部时钟信号 4’h4: Timer1通道0外部时钟信号 4’h5: Timer1通道1外部时钟信号 4’h6: Timer2通道0外部时钟信号 4’h7: Timer2通道1外部时钟信号 4’h8: Timer3通道0外部时钟信号 4’h9: Timer3通道1外部时钟信号 4’hA: Timer4通道0外部时钟信号 4’hB: Timer4通道1外部时钟信号
#define UTIMER1_CFG_SRC1_MAX          ((uint32_t)0xF)                                      // UTIMER1_CFG_SRC1最大值
#define UTIMER1_CFG_SRC1_POS          12                                                   // UTIMER1_CFG_SRC1起始位
#define UTIMER1_CFG_SRC1_MASK         (uint32_t)((uint32_t)0xF << UTIMER1_CFG_SRC1_POS)    // UTIMER1_CFG_SRC1位掩码
#define UTIMER1_CFG_SRC1(x)           (uint32_t)(((x) & 0xF) << UTIMER1_CFG_SRC1_POS)      // [15:12] Timer捕获模式通道1信号来源。默认为3’h1。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER1_CFG_CH1_POL_BIT       BIT11                                                // [11] Timer通道1在比较模式下的输出极性控制，当计数器计数值回零时的输出值。
#define UTIMER1_CFG_CH1_MODE_BIT      BIT10                                                // [10] Timer通道1的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道1计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道1输入信号发生捕获事件时，将计数器计数值存入Timer通道1比较捕获寄存器。
#define UTIMER1_CFG_CH1_FE_CAP_EN_BIT BIT9                                                 // [9] Timer通道1下降沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER1_CFG_CH1_RE_CAP_EN_BIT BIT8                                                 // [8] Timer通道1上升沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。
#define UTIMER1_CFG_SRC0_MAX          ((uint32_t)0xF)                                      // UTIMER1_CFG_SRC0最大值
#define UTIMER1_CFG_SRC0_POS          4                                                    // UTIMER1_CFG_SRC0起始位
#define UTIMER1_CFG_SRC0_MASK         (uint32_t)((uint32_t)0xF << UTIMER1_CFG_SRC0_POS)    // UTIMER1_CFG_SRC0位掩码
#define UTIMER1_CFG_SRC0(x)           (uint32_t)(((x) & 0xF) << UTIMER1_CFG_SRC0_POS)      // [7:4] Timer捕获模式通道0信号来源。默认为3’h0。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER1_CFG_CH0_POL_BIT       BIT3                                                 // [3] Timer通道0在比较模式下的输出极性控制：当计数器计数值回零时的输出值。
#define UTIMER1_CFG_CH0_MODE_BIT      BIT2                                                 // [2] Timer通道0的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道0计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道0输入信号发生捕获事件时，将计数器计数值存入Timer通道0比较捕获寄存器。
#define UTIMER1_CFG_CH0_FE_CAP_EN_BIT BIT1                                                 // [1] Timer通道0下降沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER1_CFG_CH0_RE_CAP_EN_BIT BIT0                                                 // [0] Timer通道0上升沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。

/* UTIMER1_TH Timer1门限寄存器 */
#define UTIMER1_TH_TH_MAX  ((uint32_t)0xFFFF)                                // UTIMER1_TH_TH最大值
#define UTIMER1_TH_TH_POS  0                                                 // UTIMER1_TH_TH起始位
#define UTIMER1_TH_TH_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER1_TH_TH_POS) // UTIMER1_TH_TH位掩码
#define UTIMER1_TH_TH(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER1_TH_TH_POS)   // [15:0] Timer 计数器计数门限。计数器从0计数到TH值后再次回0开始计数

/* UTIMER1_CNT Timer1计数寄存器 */
#define UTIMER1_CNT_CNT_MAX  ((uint32_t)0xFFFF)                                  // UTIMER1_CNT_CNT最大值
#define UTIMER1_CNT_CNT_POS  0                                                   // UTIMER1_CNT_CNT起始位
#define UTIMER1_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER1_CNT_CNT_POS) // UTIMER1_CNT_CNT位掩码
#define UTIMER1_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER1_CNT_CNT_POS)   // [15:0] Timer 0计数器当前计数值。写操作可以写入新的计数值。

/* UTIMER1_CMP0 Timer1通道0比较捕获寄存器 */
#define UTIMER1_CMP0_CMP0_MAX  ((uint32_t)0xFFFF)                                    // UTIMER1_CMP0_CMP0最大值
#define UTIMER1_CMP0_CMP0_POS  0                                                     // UTIMER1_CMP0_CMP0起始位
#define UTIMER1_CMP0_CMP0_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER1_CMP0_CMP0_POS) // UTIMER1_CMP0_CMP0位掩码
#define UTIMER1_CMP0_CMP0(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER1_CMP0_CMP0_POS)   // [15:0] Timer 通道0工作在比较模式时，当计数器计数值等于CMP0时，发生比较事件。 Timer 通道0工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP0寄存器。

/* UTIMER1_CMP1 Timer1通道1比较捕获寄存器 */
#define UTIMER1_CMP1_CMP1_MAX  ((uint32_t)0xFFFF)                                    // UTIMER1_CMP1_CMP1最大值
#define UTIMER1_CMP1_CMP1_POS  0                                                     // UTIMER1_CMP1_CMP1起始位
#define UTIMER1_CMP1_CMP1_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER1_CMP1_CMP1_POS) // UTIMER1_CMP1_CMP1位掩码
#define UTIMER1_CMP1_CMP1(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER1_CMP1_CMP1_POS)   // [15:0] Timer 通道1工作在比较模式时，当计数器计数值等于CMP1时，发生比较事件。 Timer 通道1工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP1寄存器。

/* UTIMER1_EVT Timer1外部事件选择寄存器 */
#define UTIMER1_EVT_EVT_SRC_MAX  ((uint32_t)0xF)                                      // UTIMER1_EVT_EVT_SRC最大值
#define UTIMER1_EVT_EVT_SRC_POS  0                                                    // UTIMER1_EVT_EVT_SRC起始位
#define UTIMER1_EVT_EVT_SRC_MASK (uint32_t)((uint32_t)0xF << UTIMER1_EVT_EVT_SRC_POS) // UTIMER1_EVT_EVT_SRC位掩码
#define UTIMER1_EVT_EVT_SRC(x)   (uint32_t)(((x) & 0xF) << UTIMER1_EVT_EVT_SRC_POS)   // [3:0] Timer1外部事件选择寄存器，本寄存器需要配合UTIMER1_CFG.ETON使用。ETON为高时，根据本寄存器选择触发Timer计数的事件。 需要注意的是，Timer自身的比较事件无法触发Timer进行计数。 0：TIMER0 通道0比较事件 1：TIMER0 通道1比较事件 2：TIMER1 通道0比较事件 3：TIMER1 通道1比较事件 4：TIMER2 通道0比较事件 5：TIMER2 通道1比较事件 6：TIMER3 通道0比较事件 7：TIMER3 通道1比较事件 8：TIMER4 通道0比较事件 9：TIMER4 通道1比较事件 10：MCPWM0 TADC[0]比较事件 11：MCPWM0 TADC[1]比较事件 12：MCPWM0 TADC[2]比较事件 13：MCPWM0 TADC[3]比较事件 14：MCPWM1 TADC[0]比较事件 15：MCPWM1 TADC[1]比较事件 16：MCPWM1 TADC[2]比较事件 17：MCPWM1 TADC[3]比较事件

/* UTIMER1_FLT Timer1滤波控制寄存器 */
#define UTIMER1_FLT_FLT_MAX  ((uint32_t)0xFF)                                  // UTIMER1_FLT_FLT最大值
#define UTIMER1_FLT_FLT_POS  0                                                 // UTIMER1_FLT_FLT起始位
#define UTIMER1_FLT_FLT_MASK (uint32_t)((uint32_t)0xFF << UTIMER1_FLT_FLT_POS) // UTIMER1_FLT_FLT位掩码
#define UTIMER1_FLT_FLT(x)   (uint32_t)(((x) & 0xFF) << UTIMER1_FLT_FLT_POS)   // [7:0] 通道0/1信号滤波宽度选择。取值范围0~255。 FLT为0时，不对通道进行滤波。 FLT不为0时，对通道信号进行滤波：滤波宽度为FLT×8。当通道信号电平稳定超过FLT×8个系统时钟周期宽度时，滤波器输出更新；否则，滤波器保持当前的输出不变。

/* UTIMER1_IE Timer1中断使能寄存器 */
#define UTIMER1_IE_ZC_RE_BIT  BIT10 // [10] Timer计数器过0事件DMA请求使能，高电平有效。
#define UTIMER1_IE_CH1_RE_BIT BIT9  // [9] Timer通道1比较/捕获DMA请求使能，高电平有效。
#define UTIMER1_IE_CH0_RE_BIT BIT8  // [8] Timer通道0比较/捕获DMA请求使能，高电平有效。
#define UTIMER1_IE_ZC_IE_BIT  BIT2  // [2] Timer计数器过0中断使能，高电平有效。
#define UTIMER1_IE_CH1_IE_BIT BIT1  // [1] Timer通道1比较/捕获中断使能，高电平有效。
#define UTIMER1_IE_CH0_IE_BIT BIT0  // [0] Timer通道0比较/捕获中断使能，高电平有效。

/* UTIMER1_IF Timer1中断标志寄存器 */
#define UTIMER1_IF_ZC_IF_BIT  BIT2 // [2] Timer计数器过0中断标志。高电平有效，写1清0
#define UTIMER1_IF_CH1_IF_BIT BIT1 // [1] Timer通道1比较/捕获中断标志。高电平有效，写1清0
#define UTIMER1_IF_CH0_IF_BIT BIT0 // [0] Timer通道0比较/捕获中断标志。高电平有效，写1清0

/* UTIMER2_CFG Timer2配置寄存器 */
#define UTIMER2_CFG_EN_BIT            BIT31                                                // [31] Timer模块整体使能，高有效
#define UTIMER2_CFG_CAP1_CLR_EN_BIT   BIT27                                                // [27] 当发生CAP1捕获事件时，清零Timer计数器，高有效
#define UTIMER2_CFG_CAP0_CLR_EN_BIT   BIT26                                                // [26] 当发生CAP0捕获事件时，清零Timer计数器，高有效
#define UTIMER2_CFG_ONE_TRIG_BIT      BIT25                                                // [25] 在比较模式下，且EN为0时，写1触发Timer发送一个周期的特定占空比的脉冲，此位在脉冲发送期间内读为1，一个Timer周期后，自动清零。
#define UTIMER2_CFG_ETON_BIT          BIT24                                                // [24] Timer计数器计数使能配置。默认为0。 0: 自动运行 1: 等待外部事件触发计数，计数一个周期后停止 外部事件通过UTIMER2_EVT寄存器进行配置。
#define UTIMER2_CFG_CLK_DIV_MAX       ((uint32_t)0x7)                                      // UTIMER2_CFG_CLK_DIV最大值
#define UTIMER2_CFG_CLK_DIV_POS       20                                                   // UTIMER2_CFG_CLK_DIV起始位
#define UTIMER2_CFG_CLK_DIV_MASK      (uint32_t)((uint32_t)0x7 << UTIMER2_CFG_CLK_DIV_POS) // UTIMER2_CFG_CLK_DIV位掩码
#define UTIMER2_CFG_CLK_DIV(x)        (uint32_t)(((x) & 0x7) << UTIMER2_CFG_CLK_DIV_POS)   // [22:20] Timer计数器频率配置，计数器计数频率是系统主时钟频率的2CLK_DIV分频。默认值为0，不分频。 3’h0: 1分频 3’h1: 2分频 3’h2: 4分频 3’h3: 8分频 3’h4: 16分频 3’h5: 32分频 3’h6: 64分频 3’h7: 128分频
#define UTIMER2_CFG_CLK_SRC_MAX       ((uint32_t)0xF)                                      // UTIMER2_CFG_CLK_SRC最大值
#define UTIMER2_CFG_CLK_SRC_POS       16                                                   // UTIMER2_CFG_CLK_SRC起始位
#define UTIMER2_CFG_CLK_SRC_MASK      (uint32_t)((uint32_t)0xF << UTIMER2_CFG_CLK_SRC_POS) // UTIMER2_CFG_CLK_SRC位掩码
#define UTIMER2_CFG_CLK_SRC(x)        (uint32_t)(((x) & 0xF) << UTIMER2_CFG_CLK_SRC_POS)   // [19:16] Timer 时钟源 4’h0: 芯片系统时钟 4’h1: 芯片系统时钟 4’h2: Timer0通道0外部时钟信号 4’h3: Timer0通道1外部时钟信号 4’h4: Timer1通道0外部时钟信号 4’h5: Timer1通道1外部时钟信号 4’h6: Timer2通道0外部时钟信号 4’h7: Timer2通道1外部时钟信号 4’h8: Timer3通道0外部时钟信号 4’h9: Timer3通道1外部时钟信号 4’hA: Timer4通道0外部时钟信号 4’hB: Timer4通道1外部时钟信号
#define UTIMER2_CFG_SRC1_MAX          ((uint32_t)0xF)                                      // UTIMER2_CFG_SRC1最大值
#define UTIMER2_CFG_SRC1_POS          12                                                   // UTIMER2_CFG_SRC1起始位
#define UTIMER2_CFG_SRC1_MASK         (uint32_t)((uint32_t)0xF << UTIMER2_CFG_SRC1_POS)    // UTIMER2_CFG_SRC1位掩码
#define UTIMER2_CFG_SRC1(x)           (uint32_t)(((x) & 0xF) << UTIMER2_CFG_SRC1_POS)      // [15:12] Timer捕获模式通道1信号来源。默认为3’h1。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER2_CFG_CH1_POL_BIT       BIT11                                                // [11] Timer通道1在比较模式下的输出极性控制，当计数器计数值回零时的输出值。
#define UTIMER2_CFG_CH1_MODE_BIT      BIT10                                                // [10] Timer通道1的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道1计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道1输入信号发生捕获事件时，将计数器计数值存入Timer通道1比较捕获寄存器
#define UTIMER2_CFG_CH1_FE_CAP_EN_BIT BIT9                                                 // [9] Timer通道1下降沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER2_CFG_CH1_RE_CAP_EN_BIT BIT8                                                 // [8] Timer通道1上升沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。
#define UTIMER2_CFG_SRC0_MAX          ((uint32_t)0xF)                                      // UTIMER2_CFG_SRC0最大值
#define UTIMER2_CFG_SRC0_POS          4                                                    // UTIMER2_CFG_SRC0起始位
#define UTIMER2_CFG_SRC0_MASK         (uint32_t)((uint32_t)0xF << UTIMER2_CFG_SRC0_POS)    // UTIMER2_CFG_SRC0位掩码
#define UTIMER2_CFG_SRC0(x)           (uint32_t)(((x) & 0xF) << UTIMER2_CFG_SRC0_POS)      // [7:4] Timer捕获模式通道0信号来源。默认为3’h0。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER2_CFG_CH0_POL_BIT       BIT3                                                 // [3] Timer通道0在比较模式下的输出极性控制：当计数器计数值回零时的输出值。
#define UTIMER2_CFG_CH0_MODE_BIT      BIT2                                                 // [2] Timer通道0的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道0计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道0输入信号发生捕获事件时，将计数器计数值存入Timer通道0比较捕获寄存器。
#define UTIMER2_CFG_CH0_FE_CAP_EN_BIT BIT1                                                 // [1] Timer通道0下降沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER2_CFG_CH0_RE_CAP_EN_BIT BIT0                                                 // [0] Timer通道0上升沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。

/* UTIMER2_TH Timer2门限寄存器 */
#define UTIMER2_TH_TH_MAX  ((uint32_t)0xFFFFFFFF)                                // UTIMER2_TH_TH最大值
#define UTIMER2_TH_TH_POS  0                                                     // UTIMER2_TH_TH起始位
#define UTIMER2_TH_TH_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER2_TH_TH_POS) // UTIMER2_TH_TH位掩码
#define UTIMER2_TH_TH(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER2_TH_TH_POS)   // [31:0] Timer计数器计数门限。计数器从0计数到TH值后再次回0开始计数

/* UTIMER2_CNT Timer2计数寄存器 */
#define UTIMER2_CNT_CNT_MAX  ((uint32_t)0xFFFFFFFF)                                  // UTIMER2_CNT_CNT最大值
#define UTIMER2_CNT_CNT_POS  0                                                       // UTIMER2_CNT_CNT起始位
#define UTIMER2_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER2_CNT_CNT_POS) // UTIMER2_CNT_CNT位掩码
#define UTIMER2_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER2_CNT_CNT_POS)   // [31:0] Timer2计数器当前计数值。写操作可以写入新的计数值。

/* UTIMER2_CMP0 Timer2通道0比较捕获寄存器 */
#define UTIMER2_CMP0_CMP0_MAX  ((uint32_t)0xFFFFFFFF)                                    // UTIMER2_CMP0_CMP0最大值
#define UTIMER2_CMP0_CMP0_POS  0                                                         // UTIMER2_CMP0_CMP0起始位
#define UTIMER2_CMP0_CMP0_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER2_CMP0_CMP0_POS) // UTIMER2_CMP0_CMP0位掩码
#define UTIMER2_CMP0_CMP0(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER2_CMP0_CMP0_POS)   // [31:0] Time通道0工作在比较模式时，当计数器计数值等于CMP0时，发生比较事件。 Timer通道0工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP0寄存器。

/* UTIMER2_CMP1 Timer2通道1比较捕获寄存器 */
#define UTIMER2_CMP1_CMP1_MAX  ((uint32_t)0xFFFFFFFF)                                    // UTIMER2_CMP1_CMP1最大值
#define UTIMER2_CMP1_CMP1_POS  0                                                         // UTIMER2_CMP1_CMP1起始位
#define UTIMER2_CMP1_CMP1_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER2_CMP1_CMP1_POS) // UTIMER2_CMP1_CMP1位掩码
#define UTIMER2_CMP1_CMP1(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER2_CMP1_CMP1_POS)   // [31:0] Timer通道1工作在比较模式时，当计数器计数值等于CMP1时，发生比较事件。 Timer通道1工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP1寄存器。

/* UTIMER2_EVT Timer2外部事件选择寄存器 */
#define UTIMER2_EVT_EVT_SRC_MAX  ((uint32_t)0x7)                                      // UTIMER2_EVT_EVT_SRC最大值
#define UTIMER2_EVT_EVT_SRC_POS  0                                                    // UTIMER2_EVT_EVT_SRC起始位
#define UTIMER2_EVT_EVT_SRC_MASK (uint32_t)((uint32_t)0x7 << UTIMER2_EVT_EVT_SRC_POS) // UTIMER2_EVT_EVT_SRC位掩码
#define UTIMER2_EVT_EVT_SRC(x)   (uint32_t)(((x) & 0x7) << UTIMER2_EVT_EVT_SRC_POS)   // [2:0] Timer外部事件选择寄存器，本寄存器需要配合UTIMER2_CFG.ETON使用。ETON为高时，根据本寄存器选择触发Timer计数的事件。 需要注意的是，Timer自身的比较事件无法触发Timer进行计数。 0：TIMER0 通道0比较事件 1：TIMER0 通道1比较事件 2：TIMER1 通道0比较事件 3：TIMER1 通道1比较事件 4：TIMER2 通道0比较事件 5：TIMER2 通道1比较事件 6：TIMER3 通道0比较事件 7：TIMER3 通道1比较事件 8：TIMER4 通道0比较事件 9：TIMER4 通道1比较事件 10：MCPWM0 TADC[0]比较事件 11：MCPWM0 TADC[1]比较事件 12：MCPWM0 TADC[2]比较事件 13：MCPWM0 TADC[3]比较事件 14：MCPWM1 TADC[0]比较事件 15：MCPWM1 TADC[1]比较事件 16：MCPWM1 TADC[2]比较事件 17：MCPWM1 TADC[3]比较事件

/* UTIMER2_FLT Timer2滤波控制寄存器 */
#define UTIMER2_FLT_FLT_MAX  ((uint32_t)0xFF)                                  // UTIMER2_FLT_FLT最大值
#define UTIMER2_FLT_FLT_POS  0                                                 // UTIMER2_FLT_FLT起始位
#define UTIMER2_FLT_FLT_MASK (uint32_t)((uint32_t)0xFF << UTIMER2_FLT_FLT_POS) // UTIMER2_FLT_FLT位掩码
#define UTIMER2_FLT_FLT(x)   (uint32_t)(((x) & 0xFF) << UTIMER2_FLT_FLT_POS)   // [7:0] 通道0/1信号滤波宽度选择。取值范围0~255。 FLT为0时，不对通道进行滤波。 FLT不为0时，对通道信号进行滤波：滤波宽度为FLT×8。当通道信号电平稳定超过FLT×8个系统时钟周期宽度时，滤波器输出更新；否则，滤波器保持当前的输出不变。

/* UTIMER2_IE Timer2中断使能寄存器 */
#define UTIMER2_IE_ZC_RE_BIT  BIT10 // [10] Timer计数器过0事件DMA请求使能，高电平有效。
#define UTIMER2_IE_CH1_RE_BIT BIT9  // [9] Timer通道1比较/捕获DMA请求使能，高电平有效。
#define UTIMER2_IE_CH0_RE_BIT BIT8  // [8] Timer通道0比较/捕获DMA请求使能，高电平有效。
#define UTIMER2_IE_ZC_IE_BIT  BIT2  // [2] Timer计数器过0中断使能，高电平有效。
#define UTIMER2_IE_CH1_IE_BIT BIT1  // [1] Timer通道1比较/捕获中断使能，高电平有效。
#define UTIMER2_IE_CH0_IE_BIT BIT0  // [0] Timer通道0比较/捕获中断使能，高电平有效。

/* UTIMER2_IF Timer2中断标志寄存器 */
#define UTIMER2_IF_ZC_IF_BIT  BIT2 // [2] Timer计数器过0中断标志。高电平有效，写1清0
#define UTIMER2_IF_CH1_IF_BIT BIT1 // [1] Timer通道1比较/捕获中断标志。高电平有效，写1清0
#define UTIMER2_IF_CH0_IF_BIT BIT0 // [0] Timer通道0比较/捕获中断标志。高电平有效，写1清0

/* UTIMER3_CFG Timer3配置寄存器 */
#define UTIMER3_CFG_EN_BIT            BIT31                                                // [31] Timer模块整体使能，高有效
#define UTIMER3_CFG_CAP1_CLR_EN_BIT   BIT27                                                // [27] 当发生CAP1捕获事件时，清零Timer计数器，高有效
#define UTIMER3_CFG_CAP0_CLR_EN_BIT   BIT26                                                // [26] 当发生CAP0捕获事件时，清零Timer计数器，高有效
#define UTIMER3_CFG_ONE_TRIG_BIT      BIT25                                                // [25] 在比较模式下，且EN为0时，写1触发Timer发送一个周期的特定占空比的脉冲，此位在脉冲发送期间内读为1，一个Timer周期后，自动清零。
#define UTIMER3_CFG_ETON_BIT          BIT24                                                // [24] Timer计数器计数使能配置。默认为0。 0: 自动运行 1: 等待外部事件触发计数，计数一个周期后停止 外部事件通过UTIMER3_EVT寄存器进行配置。
#define UTIMER3_CFG_CLK_DIV_MAX       ((uint32_t)0x7)                                      // UTIMER3_CFG_CLK_DIV最大值
#define UTIMER3_CFG_CLK_DIV_POS       20                                                   // UTIMER3_CFG_CLK_DIV起始位
#define UTIMER3_CFG_CLK_DIV_MASK      (uint32_t)((uint32_t)0x7 << UTIMER3_CFG_CLK_DIV_POS) // UTIMER3_CFG_CLK_DIV位掩码
#define UTIMER3_CFG_CLK_DIV(x)        (uint32_t)(((x) & 0x7) << UTIMER3_CFG_CLK_DIV_POS)   // [22:20] Timer计数器频率配置，计数器计数频率是系统主时钟频率的2CLK_DIV分频。默认值为0，不分频。 3’h0: 1分频 3’h1: 2分频 3’h2: 4分频 3’h3: 8分频 3’h4: 16分频 3’h5: 32分频 3’h6: 64分频 3’h7: 128分频
#define UTIMER3_CFG_CLK_SRC_MAX       ((uint32_t)0xF)                                      // UTIMER3_CFG_CLK_SRC最大值
#define UTIMER3_CFG_CLK_SRC_POS       16                                                   // UTIMER3_CFG_CLK_SRC起始位
#define UTIMER3_CFG_CLK_SRC_MASK      (uint32_t)((uint32_t)0xF << UTIMER3_CFG_CLK_SRC_POS) // UTIMER3_CFG_CLK_SRC位掩码
#define UTIMER3_CFG_CLK_SRC(x)        (uint32_t)(((x) & 0xF) << UTIMER3_CFG_CLK_SRC_POS)   // [19:16] Timer 时钟源 4’h0: 芯片系统时钟 4’h1: 芯片系统时钟 4’h2: Timer0通道0外部时钟信号 4’h3: Timer0通道1外部时钟信号 4’h4: Timer1通道0外部时钟信号 4’h5: Timer1通道1外部时钟信号 4’h6: Timer2通道0外部时钟信号 4’h7: Timer2通道1外部时钟信号 4’h8: Timer3通道0外部时钟信号 4’h9: Timer3通道1外部时钟信号 4’hA: Timer4通道0外部时钟信号 4’hB: Timer4通道1外部时钟信号
#define UTIMER3_CFG_SRC1_MAX          ((uint32_t)0xF)                                      // UTIMER3_CFG_SRC1最大值
#define UTIMER3_CFG_SRC1_POS          12                                                   // UTIMER3_CFG_SRC1起始位
#define UTIMER3_CFG_SRC1_MASK         (uint32_t)((uint32_t)0xF << UTIMER3_CFG_SRC1_POS)    // UTIMER3_CFG_SRC1位掩码
#define UTIMER3_CFG_SRC1(x)           (uint32_t)(((x) & 0xF) << UTIMER3_CFG_SRC1_POS)      // [15:12] Timer捕获模式通道1信号来源。默认为3’h1。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER3_CFG_CH1_POL_BIT       BIT11                                                // [11] Timer通道1在比较模式下的输出极性控制，当计数器计数值回零时的输出值。
#define UTIMER3_CFG_CH1_MODE_BIT      BIT10                                                // [10] Timer通道1的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道1计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道1输入信号发生捕获事件时，将计数器计数值存入Timer通道1比较捕获寄存器
#define UTIMER3_CFG_CH1_FE_CAP_EN_BIT BIT9                                                 // [9] Timer通道1下降沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER3_CFG_CH1_RE_CAP_EN_BIT BIT8                                                 // [8] Timer通道1上升沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。
#define UTIMER3_CFG_SRC0_MAX          ((uint32_t)0xF)                                      // UTIMER3_CFG_SRC0最大值
#define UTIMER3_CFG_SRC0_POS          4                                                    // UTIMER3_CFG_SRC0起始位
#define UTIMER3_CFG_SRC0_MASK         (uint32_t)((uint32_t)0xF << UTIMER3_CFG_SRC0_POS)    // UTIMER3_CFG_SRC0位掩码
#define UTIMER3_CFG_SRC0(x)           (uint32_t)(((x) & 0xF) << UTIMER3_CFG_SRC0_POS)      // [7:4] Timer捕获模式通道0信号来源。默认为3’h0。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER3_CFG_CH0_POL_BIT       BIT3                                                 // [3] Timer通道0在比较模式下的输出极性控制：当计数器计数值回零时的输出值。
#define UTIMER3_CFG_CH0_MODE_BIT      BIT2                                                 // [2] Timer通道0的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道0计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道0输入信号发生捕获事件时，将计数器计数值存入Timer通道0比较捕获寄存器。
#define UTIMER3_CFG_CH0_FE_CAP_EN_BIT BIT1                                                 // [1] Timer通道0下降沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER3_CFG_CH0_RE_CAP_EN_BIT BIT0                                                 // [0] Timer通道0上升沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。

/* UTIMER3_TH Timer3门限寄存器 */
#define UTIMER3_TH_TH_MAX  ((uint32_t)0xFFFFFFFF)                                // UTIMER3_TH_TH最大值
#define UTIMER3_TH_TH_POS  0                                                     // UTIMER3_TH_TH起始位
#define UTIMER3_TH_TH_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER3_TH_TH_POS) // UTIMER3_TH_TH位掩码
#define UTIMER3_TH_TH(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER3_TH_TH_POS)   // [31:0] Timer计数器计数门限。计数器从0计数到TH值后再次回0开始计数

/* UTIMER3_CNT Timer3计数寄存器 */
#define UTIMER3_CNT_CNT_MAX  ((uint32_t)0xFFFFFFFF)                                  // UTIMER3_CNT_CNT最大值
#define UTIMER3_CNT_CNT_POS  0                                                       // UTIMER3_CNT_CNT起始位
#define UTIMER3_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER3_CNT_CNT_POS) // UTIMER3_CNT_CNT位掩码
#define UTIMER3_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER3_CNT_CNT_POS)   // [31:0] Timer计数器当前计数值。写操作可以写入新的计数值。

/* UTIMER3_CMP0 Timer3通道0比较捕获寄存器 */
#define UTIMER3_CMP0_CMP0_MAX  ((uint32_t)0xFFFFFFFF)                                    // UTIMER3_CMP0_CMP0最大值
#define UTIMER3_CMP0_CMP0_POS  0                                                         // UTIMER3_CMP0_CMP0起始位
#define UTIMER3_CMP0_CMP0_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER3_CMP0_CMP0_POS) // UTIMER3_CMP0_CMP0位掩码
#define UTIMER3_CMP0_CMP0(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER3_CMP0_CMP0_POS)   // [31:0] Timer通道0工作在比较模式时，当计数器计数值等于CMP0时，发生比较事件。 Timer通道0工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP0寄存器。

/* UTIMER3_CMP1 Timer3通道1比较捕获寄存器 */
#define UTIMER3_CMP1_CMP1_MAX  ((uint32_t)0xFFFFFFFF)                                    // UTIMER3_CMP1_CMP1最大值
#define UTIMER3_CMP1_CMP1_POS  0                                                         // UTIMER3_CMP1_CMP1起始位
#define UTIMER3_CMP1_CMP1_MASK (uint32_t)((uint32_t)0xFFFFFFFF << UTIMER3_CMP1_CMP1_POS) // UTIMER3_CMP1_CMP1位掩码
#define UTIMER3_CMP1_CMP1(x)   (uint32_t)(((x) & 0xFFFFFFFF) << UTIMER3_CMP1_CMP1_POS)   // [31:0] Timer通道1工作在比较模式时，当计数器计数值等于CMP1时，发生比较事件。 Timer通道1工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP1寄存器。

/* UTIMER3_EVT Timer3外部事件选择寄存器 */
#define UTIMER3_EVT_EVT_SRC_MAX  ((uint32_t)0x7)                                      // UTIMER3_EVT_EVT_SRC最大值
#define UTIMER3_EVT_EVT_SRC_POS  0                                                    // UTIMER3_EVT_EVT_SRC起始位
#define UTIMER3_EVT_EVT_SRC_MASK (uint32_t)((uint32_t)0x7 << UTIMER3_EVT_EVT_SRC_POS) // UTIMER3_EVT_EVT_SRC位掩码
#define UTIMER3_EVT_EVT_SRC(x)   (uint32_t)(((x) & 0x7) << UTIMER3_EVT_EVT_SRC_POS)   // [2:0] Timer外部事件选择寄存器，本寄存器需要配合UTIMER3_CFG.ETON使用。ETON为高时，根据本寄存器选择触发Timer计数的事件。 需要注意的是，Timer自身的比较事件无法触发Timer进行计数。 0：TIMER0 通道0比较事件 1：TIMER0 通道1比较事件 2：TIMER1 通道0比较事件 3：TIMER1 通道1比较事件 4：TIMER2 通道0比较事件 5：TIMER2 通道1比较事件 6：TIMER3 通道0比较事件 7：TIMER3 通道1比较事件 8：TIMER4 通道0比较事件 9：TIMER4 通道1比较事件 10：MCPWM0 TADC[0]比较事件 11：MCPWM0 TADC[1]比较事件 12：MCPWM0 TADC[2]比较事件 13：MCPWM0 TADC[3]比较事件 14：MCPWM1 TADC[0]比较事件 15：MCPWM1 TADC[1]比较事件 16：MCPWM1 TADC[2]比较事件 17：MCPWM1 TADC[3]比较事件

/* UTIMER3_FLT Timer3滤波控制寄存器 */
#define UTIMER3_FLT_FLT_MAX  ((uint32_t)0xFF)                                  // UTIMER3_FLT_FLT最大值
#define UTIMER3_FLT_FLT_POS  0                                                 // UTIMER3_FLT_FLT起始位
#define UTIMER3_FLT_FLT_MASK (uint32_t)((uint32_t)0xFF << UTIMER3_FLT_FLT_POS) // UTIMER3_FLT_FLT位掩码
#define UTIMER3_FLT_FLT(x)   (uint32_t)(((x) & 0xFF) << UTIMER3_FLT_FLT_POS)   // [7:0] 通道0/1信号滤波宽度选择。取值范围0~255。 FLT为0时，不对通道进行滤波。 FLT不为0时，对通道信号进行滤波：滤波宽度为FLT×8。当通道信号电平稳定超过FLT×8个系统时钟周期宽度时，滤波器输出更新；否则，滤波器保持当前的输出不变。

/* UTIMER3_IE Timer3中断使能寄存器 */
#define UTIMER3_IE_ZC_RE_BIT  BIT10 // [10] Timer计数器过0事件DMA请求使能，高电平有效。
#define UTIMER3_IE_CH1_RE_BIT BIT9  // [9] Timer通道1比较/捕获DMA请求使能，高电平有效。
#define UTIMER3_IE_CH0_RE_BIT BIT8  // [8] Timer通道0比较/捕获DMA请求使能，高电平有效。
#define UTIMER3_IE_ZC_IE_BIT  BIT2  // [2] Timer计数器过0中断使能，高电平有效。
#define UTIMER3_IE_CH1_IE_BIT BIT1  // [1] Timer通道1比较/捕获中断使能，高电平有效。
#define UTIMER3_IE_CH0_IE_BIT BIT0  // [0] Timer通道0比较/捕获中断使能，高电平有效。

/* UTIMER3_IF Timer3中断标志寄存器 */
#define UTIMER3_IF_ZC_IF_BIT  BIT2 // [2] Timer计数器过0中断标志。高电平有效，写1清0
#define UTIMER3_IF_CH1_IF_BIT BIT1 // [1] Timer通道1比较/捕获中断标志。高电平有效，写1清0
#define UTIMER3_IF_CH0_IF_BIT BIT0 // [0] Timer通道0比较/捕获中断标志。高电平有效，写1清0

/* UTIMER4_CFG Timer4配置寄存器 */
#define UTIMER4_CFG_EN_BIT            BIT31                                                // [31] Timer模块整体使能，高有效
#define UTIMER4_CFG_CAP1_CLR_EN_BIT   BIT27                                                // [27] 当发生CAP1捕获事件时，清零Timer计数器，高有效
#define UTIMER4_CFG_CAP0_CLR_EN_BIT   BIT26                                                // [26] 当发生CAP0捕获事件时，清零Timer计数器，高有效
#define UTIMER4_CFG_ONE_TRIG_BIT      BIT25                                                // [25] 在比较模式下，且EN为0时，写1触发Timer发送一个周期的特定占空比的脉冲，此位在脉冲发送期间内读为1，一个Timer周期后，自动清零。
#define UTIMER4_CFG_ETON_BIT          BIT24                                                // [24] Timer计数器计数使能配置。默认为0。 0: 自动运行 1: 等待外部事件触发计数，计数一个周期后停止 外部事件通过UTIMER3_EVT寄存器进行配置。
#define UTIMER4_CFG_CLK_DIV_MAX       ((uint32_t)0x7)                                      // UTIMER4_CFG_CLK_DIV最大值
#define UTIMER4_CFG_CLK_DIV_POS       20                                                   // UTIMER4_CFG_CLK_DIV起始位
#define UTIMER4_CFG_CLK_DIV_MASK      (uint32_t)((uint32_t)0x7 << UTIMER4_CFG_CLK_DIV_POS) // UTIMER4_CFG_CLK_DIV位掩码
#define UTIMER4_CFG_CLK_DIV(x)        (uint32_t)(((x) & 0x7) << UTIMER4_CFG_CLK_DIV_POS)   // [22:20] Timer计数器频率配置，计数器计数频率是系统主时钟频率的2CLK_DIV分频。默认值为0，不分频。 3’h0: 1分频 3’h1: 2分频 3’h2: 4分频 3’h3: 8分频 3’h4: 16分频 3’h5: 32分频 3’h6: 64分频 3’h7: 128分频
#define UTIMER4_CFG_CLK_SRC_MAX       ((uint32_t)0xF)                                      // UTIMER4_CFG_CLK_SRC最大值
#define UTIMER4_CFG_CLK_SRC_POS       16                                                   // UTIMER4_CFG_CLK_SRC起始位
#define UTIMER4_CFG_CLK_SRC_MASK      (uint32_t)((uint32_t)0xF << UTIMER4_CFG_CLK_SRC_POS) // UTIMER4_CFG_CLK_SRC位掩码
#define UTIMER4_CFG_CLK_SRC(x)        (uint32_t)(((x) & 0xF) << UTIMER4_CFG_CLK_SRC_POS)   // [19:16] Timer 时钟源 4’h0: 芯片系统时钟 4’h1: 芯片系统时钟 4’h2: Timer0通道0外部时钟信号 4’h3: Timer0通道1外部时钟信号 4’h4: Timer1通道0外部时钟信号 4’h5: Timer1通道1外部时钟信号 4’h6: Timer2通道0外部时钟信号 4’h7: Timer2通道1外部时钟信号 4’h8: Timer3通道0外部时钟信号 4’h9: Timer3通道1外部时钟信号 4’hA: Timer4通道0外部时钟信号 4’hB: Timer4通道1外部时钟信号
#define UTIMER4_CFG_SRC1_MAX          ((uint32_t)0xF)                                      // UTIMER4_CFG_SRC1最大值
#define UTIMER4_CFG_SRC1_POS          12                                                   // UTIMER4_CFG_SRC1起始位
#define UTIMER4_CFG_SRC1_MASK         (uint32_t)((uint32_t)0xF << UTIMER4_CFG_SRC1_POS)    // UTIMER4_CFG_SRC1位掩码
#define UTIMER4_CFG_SRC1(x)           (uint32_t)(((x) & 0xF) << UTIMER4_CFG_SRC1_POS)      // [15:12] Timer捕获模式通道1信号来源。默认为3’h1。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER4_CFG_CH1_POL_BIT       BIT11                                                // [11] Timer通道1在比较模式下的输出极性控制，当计数器计数值回零时的输出值。
#define UTIMER4_CFG_CH1_MODE_BIT      BIT10                                                // [10] Timer通道1的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道1计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道1输入信号发生捕获事件时，将计数器计数值存入Timer通道1比较捕获寄存器
#define UTIMER4_CFG_CH1_FE_CAP_EN_BIT BIT9                                                 // [9] Timer通道1下降沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER4_CFG_CH1_RE_CAP_EN_BIT BIT8                                                 // [8] Timer通道1上升沿捕获事件使能。1：使能；0：关闭。 Timer通道1输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。
#define UTIMER4_CFG_SRC0_MAX          ((uint32_t)0xF)                                      // UTIMER4_CFG_SRC0最大值
#define UTIMER4_CFG_SRC0_POS          4                                                    // UTIMER4_CFG_SRC0起始位
#define UTIMER4_CFG_SRC0_MASK         (uint32_t)((uint32_t)0xF << UTIMER4_CFG_SRC0_POS)    // UTIMER4_CFG_SRC0位掩码
#define UTIMER4_CFG_SRC0(x)           (uint32_t)(((x) & 0xF) << UTIMER4_CFG_SRC0_POS)      // [7:4] Timer捕获模式通道0信号来源。默认为3’h0。 4’h0: Timer通道0，来自芯片GPIO（参见Datasheet及应用配置） 4’h1: Timer通道1，来自芯片GPIO（参见Datasheet及应用配置） 4’h2: 比较器0的输出 4’h3: 比较器1的输出 4’h4: 比较器2的输出 4’h5: 比较器3的输出 4’h6: 比较器4的输出 4’h7: 比较器5的输出 4’h8: Timer通道0和1的异或
#define UTIMER4_CFG_CH0_POL_BIT       BIT3                                                 // [3] Timer通道0在比较模式下的输出极性控制：当计数器计数值回零时的输出值。
#define UTIMER4_CFG_CH0_MODE_BIT      BIT2                                                 // [2] Timer通道0的工作模式选择，默认值为0。 0: 比较模式。输出方波，在Timer通道0计数器计数值等于0或等于Timer比较捕获寄存器值时，IO发生翻转。 1: 捕获模式。当Timer通道0输入信号发生捕获事件时，将计数器计数值存入Timer通道0比较捕获寄存器。
#define UTIMER4_CFG_CH0_FE_CAP_EN_BIT BIT1                                                 // [1] Timer通道0下降沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生1?0跳变被视为捕获事件。下降沿事件使能可以与上升沿事件使能并存。
#define UTIMER4_CFG_CH0_RE_CAP_EN_BIT BIT0                                                 // [0] Timer通道0上升沿捕获事件使能。1：使能；0：关闭。 Timer通道0输入信号发生0?1跳变被视为捕获事件。上升沿事件使能可以与下降沿事件使能并存。

/* UTIMER4_TH Timer4门限寄存器 */
#define UTIMER4_TH_TH_MAX  ((uint32_t)0xFFFF)                                // UTIMER4_TH_TH最大值
#define UTIMER4_TH_TH_POS  0                                                 // UTIMER4_TH_TH起始位
#define UTIMER4_TH_TH_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER4_TH_TH_POS) // UTIMER4_TH_TH位掩码
#define UTIMER4_TH_TH(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER4_TH_TH_POS)   // [15:0] Timer 计数器计数门限。计数器从0计数到TH值后再次回0开始计数

/* UTIMER4_CNT Timer4计数寄存器 */
#define UTIMER4_CNT_CNT_MAX  ((uint32_t)0xFFFF)                                  // UTIMER4_CNT_CNT最大值
#define UTIMER4_CNT_CNT_POS  0                                                   // UTIMER4_CNT_CNT起始位
#define UTIMER4_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER4_CNT_CNT_POS) // UTIMER4_CNT_CNT位掩码
#define UTIMER4_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER4_CNT_CNT_POS)   // [15:0] Timer 0计数器当前计数值。写操作可以写入新的计数值。

/* UTIMER4_CMP0 Timer4通道0比较捕获寄存器 */
#define UTIMER4_CMP0_CMP0_MAX  ((uint32_t)0xFFFF)                                    // UTIMER4_CMP0_CMP0最大值
#define UTIMER4_CMP0_CMP0_POS  0                                                     // UTIMER4_CMP0_CMP0起始位
#define UTIMER4_CMP0_CMP0_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER4_CMP0_CMP0_POS) // UTIMER4_CMP0_CMP0位掩码
#define UTIMER4_CMP0_CMP0(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER4_CMP0_CMP0_POS)   // [15:0] Timer 通道0工作在比较模式时，当计数器计数值等于CMP0时，发生比较事件。 Timer 通道0工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP0寄存器。

/* UTIMER4_CMP1 Timer4通道1比较捕获寄存器 */
#define UTIMER4_CMP1_CMP1_MAX  ((uint32_t)0xFFFF)                                    // UTIMER4_CMP1_CMP1最大值
#define UTIMER4_CMP1_CMP1_POS  0                                                     // UTIMER4_CMP1_CMP1起始位
#define UTIMER4_CMP1_CMP1_MASK (uint32_t)((uint32_t)0xFFFF << UTIMER4_CMP1_CMP1_POS) // UTIMER4_CMP1_CMP1位掩码
#define UTIMER4_CMP1_CMP1(x)   (uint32_t)(((x) & 0xFFFF) << UTIMER4_CMP1_CMP1_POS)   // [15:0] Timer 通道1工作在比较模式时，当计数器计数值等于CMP1时，发生比较事件。 Timer 通道1工作在捕获模式时，发生捕获事件时的计数器计数值存入CMP1寄存器。

/* UTIMER4_EVT Timer4外部事件选择寄存器 */
#define UTIMER4_EVT_EVT_SRC_MAX  ((uint32_t)0x7)                                      // UTIMER4_EVT_EVT_SRC最大值
#define UTIMER4_EVT_EVT_SRC_POS  0                                                    // UTIMER4_EVT_EVT_SRC起始位
#define UTIMER4_EVT_EVT_SRC_MASK (uint32_t)((uint32_t)0x7 << UTIMER4_EVT_EVT_SRC_POS) // UTIMER4_EVT_EVT_SRC位掩码
#define UTIMER4_EVT_EVT_SRC(x)   (uint32_t)(((x) & 0x7) << UTIMER4_EVT_EVT_SRC_POS)   // [2:0] Timer外部事件选择寄存器，本寄存器需要配合UTIMER4_CFG.ETON使用。ETON为高时，根据本寄存器选择触发Timer计数的事件。 需要注意的是，Timer自身的比较事件无法触发Timer进行计数。 0：TIMER0 通道0比较事件 1：TIMER0 通道1比较事件 2：TIMER1 通道0比较事件 3：TIMER1 通道1比较事件 4：TIMER2 通道0比较事件 5：TIMER2 通道1比较事件 6：TIMER3 通道0比较事件 7：TIMER3 通道1比较事件 8：TIMER4 通道0比较事件 9：TIMER4 通道1比较事件 10：MCPWM0 TADC[0]比较事件 11：MCPWM0 TADC[1]比较事件 12：MCPWM0 TADC[2]比较事件 13：MCPWM0 TADC[3]比较事件 14：MCPWM1 TADC[0]比较事件 15：MCPWM1 TADC[1]比较事件 16：MCPWM1 TADC[2]比较事件 17：MCPWM1 TADC[3]比较事件

/* UTIMER4_FLT Timer4滤波控制寄存器 */
#define UTIMER4_FLT_FLT_MAX  ((uint32_t)0xFF)                                  // UTIMER4_FLT_FLT最大值
#define UTIMER4_FLT_FLT_POS  0                                                 // UTIMER4_FLT_FLT起始位
#define UTIMER4_FLT_FLT_MASK (uint32_t)((uint32_t)0xFF << UTIMER4_FLT_FLT_POS) // UTIMER4_FLT_FLT位掩码
#define UTIMER4_FLT_FLT(x)   (uint32_t)(((x) & 0xFF) << UTIMER4_FLT_FLT_POS)   // [7:0] 通道0/1信号滤波宽度选择。取值范围0~255。 FLT为0时，不对通道进行滤波。 FLT不为0时，对通道信号进行滤波：滤波宽度为FLT×8。当通道信号电平稳定超过FLT×8个系统时钟周期宽度时，滤波器输出更新；否则，滤波器保持当前的输出不变。

/* UTIMER4_IE Timer4中断使能寄存器 */
#define UTIMER4_IE_ZC_RE_BIT  BIT10 // [10] Timer计数器过0事件DMA请求使能，高电平有效。
#define UTIMER4_IE_CH1_RE_BIT BIT9  // [9] Timer通道1比较/捕获DMA请求使能，高电平有效。
#define UTIMER4_IE_CH0_RE_BIT BIT8  // [8] Timer通道0比较/捕获DMA请求使能，高电平有效。
#define UTIMER4_IE_ZC_IE_BIT  BIT2  // [2] Timer计数器过0中断使能，高电平有效。
#define UTIMER4_IE_CH1_IE_BIT BIT1  // [1] Timer通道1比较/捕获中断使能，高电平有效。
#define UTIMER4_IE_CH0_IE_BIT BIT0  // [0] Timer通道0比较/捕获中断使能，高电平有效。

/* UTIMER4_IF Timer4中断标志寄存器 */
#define UTIMER4_IF_ZC_IF_BIT  BIT2 // [2] Timer计数器过0中断标志。高电平有效，写1清0
#define UTIMER4_IF_CH1_IF_BIT BIT1 // [1] Timer通道1比较/捕获中断标志。高电平有效，写1清0
#define UTIMER4_IF_CH0_IF_BIT BIT0 // [0] Timer通道0比较/捕获中断标志。高电平有效，写1清0

/* QEP0_CFG QEP0配置寄存器 */
#define QEP0_CFG_EN_BIT        BIT15                                          // [15] QEP模块整体使能
#define QEP0_CFG_FE_CNT_EN_BIT BIT10                                          // [10] CCW+SIGN/CCW+CW两种模式下，是否在下降沿进行计数（上升沿总是计数）
#define QEP0_CFG_MODE_MAX      ((uint32_t)0x3)                                // QEP0_CFG_MODE最大值
#define QEP0_CFG_MODE_POS      8                                              // QEP0_CFG_MODE起始位
#define QEP0_CFG_MODE_MASK     (uint32_t)((uint32_t)0x3 << QEP0_CFG_MODE_POS) // QEP0_CFG_MODE位掩码
#define QEP0_CFG_MODE(x)       (uint32_t)(((x) & 0x3) << QEP0_CFG_MODE_POS)   // [9:8] 编码器模式选择 00：counting on T1， 01：counting on T1 & T2 以上两种模式都为正交编码信号计数模式 10：CCW+SIGN，符号加脉冲信号计数模式 11：CCW+CW，CCW+CW双脉冲信号计数模式
#define QEP0_CFG_ZNC_BIT       BIT3                                           // [3] Z信号清零极性选择：低电平/下降沿清零使能
#define QEP0_CFG_ZPC_BIT       BIT2                                           // [2] Z信号清零极性选择：高电平/上降沿清零使能
#define QEP0_CFG_ZLC_BIT       BIT1                                           // [1] Z信号电平清零QEP计数器使能
#define QEP0_CFG_ZEC_BIT       BIT0                                           // [0] Z信号边沿清零QEP计数器使能

/* QEP0_TH QEP0计数门限寄存器 */
#define QEP0_TH_TH_MAX  ((uint32_t)0xFFFF)                             // QEP0_TH_TH最大值
#define QEP0_TH_TH_POS  0                                              // QEP0_TH_TH起始位
#define QEP0_TH_TH_MASK (uint32_t)((uint32_t)0xFFFF << QEP0_TH_TH_POS) // QEP0_TH_TH位掩码
#define QEP0_TH_TH(x)   (uint32_t)(((x) & 0xFFFF) << QEP0_TH_TH_POS)   // [15:0] 计数门限TH。编码器向上计数（增）到TH值后，再次向上计数会导致计数器回到0。编码器向下计数（减）到0值后，再次向下计数会导致计数器回到TH。

/* QEP0_CNT QEP0计数值寄存器 */
#define QEP0_CNT_CNT_MAX  ((uint32_t)0xFFFF)                               // QEP0_CNT_CNT最大值
#define QEP0_CNT_CNT_POS  0                                                // QEP0_CNT_CNT起始位
#define QEP0_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFF << QEP0_CNT_CNT_POS) // QEP0_CNT_CNT位掩码
#define QEP0_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFF) << QEP0_CNT_CNT_POS)   // [15:0] QEP0计数值。

/* QEP0_IE QEP0中断使能寄存器 */
#define QEP0_IE_OF_IE_BIT BIT1 // [1] 上溢出中断使能，高电平有效。
#define QEP0_IE_UF_IE_BIT BIT0 // [0] 下溢出中断使能，高电平有效。

/* QEP0_IF QEP0中断标志寄存器 */
#define QEP0_IF_OF_IF_BIT BIT1 // [1] 上溢出中断标志。高电平有效，写1清0。当计数器计数达到计数门限时，上计数事件触发上溢出中断。
#define QEP0_IF_UF_IF_BIT BIT0 // [0] 下溢出中断标志。高电平有效，写1清0。当计数器计数达到0时，下计数事件触发下溢出中断。

/* QEP1_CFG QEP1配置寄存器 */
#define QEP1_CFG_EN_BIT        BIT15                                          // [15] QEP模块整体使能
#define QEP1_CFG_FE_CNT_EN_BIT BIT10                                          // [10] CCW+SIGN/CCW+CW两种模式下，是否在下降沿进行计数（上升沿总是计数）
#define QEP1_CFG_MODE_MAX      ((uint32_t)0x3)                                // QEP1_CFG_MODE最大值
#define QEP1_CFG_MODE_POS      8                                              // QEP1_CFG_MODE起始位
#define QEP1_CFG_MODE_MASK     (uint32_t)((uint32_t)0x3 << QEP1_CFG_MODE_POS) // QEP1_CFG_MODE位掩码
#define QEP1_CFG_MODE(x)       (uint32_t)(((x) & 0x3) << QEP1_CFG_MODE_POS)   // [9:8] 编码器模式选择 00：counting on T1， 01：counting on T1 & T2 以上两种模式都为正交编码信号计数模式 10：CCW+SIGN，符号加脉冲信号计数模式 11：CCW+CW，CCW+CW双脉冲信号计数模式
#define QEP1_CFG_ZNC_BIT       BIT3                                           // [3] Z信号清零极性选择：低电平/下降沿清零使能
#define QEP1_CFG_ZPC_BIT       BIT2                                           // [2] Z信号清零极性选择：高电平/上降沿清零使能
#define QEP1_CFG_ZLC_BIT       BIT1                                           // [1] Z信号电平清零QEP计数器使能
#define QEP1_CFG_ZEC_BIT       BIT0                                           // [0] Z信号边沿清零QEP计数器使能

/* QEP1_TH QEP1计数门限寄存器 */
#define QEP1_TH_TH_MAX  ((uint32_t)0xFFFF)                             // QEP1_TH_TH最大值
#define QEP1_TH_TH_POS  0                                              // QEP1_TH_TH起始位
#define QEP1_TH_TH_MASK (uint32_t)((uint32_t)0xFFFF << QEP1_TH_TH_POS) // QEP1_TH_TH位掩码
#define QEP1_TH_TH(x)   (uint32_t)(((x) & 0xFFFF) << QEP1_TH_TH_POS)   // [15:0] QEP计数门限TH。编码器向上计数（增）到TH值后，再次向上计数会导致计数器回到0。编码器向下计数（减）到0值后，再次向下计数会导致计数器回到TH。

/* QEP1_CNT QEP1计数值寄存器 */
#define QEP1_CNT_CNT_MAX  ((uint32_t)0xFFFF)                               // QEP1_CNT_CNT最大值
#define QEP1_CNT_CNT_POS  0                                                // QEP1_CNT_CNT起始位
#define QEP1_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFF << QEP1_CNT_CNT_POS) // QEP1_CNT_CNT位掩码
#define QEP1_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFF) << QEP1_CNT_CNT_POS)   // [15:0] QEP计数值。

/* QEP1_IE QEP1中断使能寄存器 */
#define QEP1_IE_OF_IE_BIT BIT1 // [1] 上溢出中断使能，高电平有效。
#define QEP1_IE_UF_IE_BIT BIT0 // [0] 下溢出中断使能，高电平有效。

/* QEP1_IF QEP1中断标志寄存器 */
#define QEP1_IF_OF_IF_BIT BIT1 // [1] 上溢出中断标志。高电平有效，写1清0。当计数器计数达到计数门限时，上计数事件触发上溢出中断。
#define QEP1_IF_UF_IF_BIT BIT0 // [0] 下溢出中断标志。高电平有效，写1清0。当计数器计数达到0时，下计数事件触发下溢出中断。

/* QEP2_CFG QEP2配置寄存器 */
#define QEP2_CFG_FE_CNT_EN_BIT BIT10                                          // [10] CCW+SIGN/CCW+CW两种模式下，是否在下降沿进行计数（上升沿总是计数）
#define QEP2_CFG_MODE_MAX      ((uint32_t)0x3)                                // QEP2_CFG_MODE最大值
#define QEP2_CFG_MODE_POS      8                                              // QEP2_CFG_MODE起始位
#define QEP2_CFG_MODE_MASK     (uint32_t)((uint32_t)0x3 << QEP2_CFG_MODE_POS) // QEP2_CFG_MODE位掩码
#define QEP2_CFG_MODE(x)       (uint32_t)(((x) & 0x3) << QEP2_CFG_MODE_POS)   // [9:8] 编码器模式选择 00：counting on T1， 01：counting on T1 & T2 以上两种模式都为正交编码信号计数模式 10：CCW+SIGN，符号加脉冲信号计数模式 11：CCW+CW，CCW+CW双脉冲信号计数模式
#define QEP2_CFG_ZNC_BIT       BIT3                                           // [3] Z信号清零极性选择：低电平/下降沿清零使能
#define QEP2_CFG_ZPC_BIT       BIT2                                           // [2] Z信号清零极性选择：高电平/上降沿清零使能
#define QEP2_CFG_ZLC_BIT       BIT1                                           // [1] Z信号电平清零QEP计数器使能
#define QEP2_CFG_ZEC_BIT       BIT0                                           // [0] Z信号边沿清零QEP计数器使能

/* QEP2_TH QEP2计数门限寄存器 */
#define QEP2_TH_TH_MAX  ((uint32_t)0xFFFF)                             // QEP2_TH_TH最大值
#define QEP2_TH_TH_POS  0                                              // QEP2_TH_TH起始位
#define QEP2_TH_TH_MASK (uint32_t)((uint32_t)0xFFFF << QEP2_TH_TH_POS) // QEP2_TH_TH位掩码
#define QEP2_TH_TH(x)   (uint32_t)(((x) & 0xFFFF) << QEP2_TH_TH_POS)   // [15:0] QEP计数门限TH。编码器向上计数（增）到TH值后，再次向上计数会导致计数器回到0。编码器向下计数（减）到0值后，再次向下计数会导致计数器回到TH。

/* QEP2_CNT QEP2计数值寄存器 */
#define QEP2_CNT_CNT_MAX  ((uint32_t)0xFFFF)                               // QEP2_CNT_CNT最大值
#define QEP2_CNT_CNT_POS  0                                                // QEP2_CNT_CNT起始位
#define QEP2_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFF << QEP2_CNT_CNT_POS) // QEP2_CNT_CNT位掩码
#define QEP2_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFF) << QEP2_CNT_CNT_POS)   // [15:0] QEP计数值。

/* QEP2_IE QEP2中断使能寄存器 */
#define QEP2_IE_OF_IE_BIT BIT1 // [1] 上溢出中断使能，高电平有效。
#define QEP2_IE_UF_IE_BIT BIT0 // [0] 下溢出中断使能，高电平有效。

/* QEP2_IF QEP2中断标志寄存器 */
#define QEP2_IF_OF_IF_BIT BIT1 // [1] 上溢出中断标志。高电平有效，写1清0。当计数器计数达到计数门限时，上计数事件触发上溢出中断。
#define QEP2_IF_UF_IF_BIT BIT0 // [0] 下溢出中断标志。高电平有效，写1清0。当计数器计数达到0时，下计数事件触发下溢出中断。

/* QEP3_CFG QEP3配置寄存器 */
#define QEP3_CFG_FE_CNT_EN_BIT BIT10                                          // [10] CCW+SIGN/CCW+CW两种模式下，是否在下降沿进行计数（上升沿总是计数）
#define QEP3_CFG_MODE_MAX      ((uint32_t)0x3)                                // QEP3_CFG_MODE最大值
#define QEP3_CFG_MODE_POS      8                                              // QEP3_CFG_MODE起始位
#define QEP3_CFG_MODE_MASK     (uint32_t)((uint32_t)0x3 << QEP3_CFG_MODE_POS) // QEP3_CFG_MODE位掩码
#define QEP3_CFG_MODE(x)       (uint32_t)(((x) & 0x3) << QEP3_CFG_MODE_POS)   // [9:8] 编码器模式选择 00：counting on T1， 01：counting on T1 & T2 以上两种模式都为正交编码信号计数模式 10：CCW+SIGN，符号加脉冲信号计数模式 11：CCW+CW，CCW+CW双脉冲信号计数模式
#define QEP3_CFG_ZNC_BIT       BIT3                                           // [3] Z信号清零极性选择：低电平/下降沿清零使能
#define QEP3_CFG_ZPC_BIT       BIT2                                           // [2] Z信号清零极性选择：高电平/上降沿清零使能
#define QEP3_CFG_ZLC_BIT       BIT1                                           // [1] Z信号电平清零QEP计数器使能
#define QEP3_CFG_ZEC_BIT       BIT0                                           // [0] Z信号边沿清零QEP计数器使能

/* QEP3_TH QEP3计数门限寄存器 */
#define QEP3_TH_TH_MAX  ((uint32_t)0xFFFF)                             // QEP3_TH_TH最大值
#define QEP3_TH_TH_POS  0                                              // QEP3_TH_TH起始位
#define QEP3_TH_TH_MASK (uint32_t)((uint32_t)0xFFFF << QEP3_TH_TH_POS) // QEP3_TH_TH位掩码
#define QEP3_TH_TH(x)   (uint32_t)(((x) & 0xFFFF) << QEP3_TH_TH_POS)   // [15:0] QEP计数门限TH。编码器向上计数（增）到TH值后，再次向上计数会导致计数器回到0。编码器向下计数（减）到0值后，再次向下计数会导致计数器回到TH。

/* QEP3_CNT QEP3计数值寄存器 */
#define QEP3_CNT_CNT_MAX  ((uint32_t)0xFFFF)                               // QEP3_CNT_CNT最大值
#define QEP3_CNT_CNT_POS  0                                                // QEP3_CNT_CNT起始位
#define QEP3_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFF << QEP3_CNT_CNT_POS) // QEP3_CNT_CNT位掩码
#define QEP3_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFF) << QEP3_CNT_CNT_POS)   // [15:0] QEP计数值。

/* QEP3_IE QEP3中断使能寄存器 */
#define QEP3_IE_OF_IE_BIT BIT1 // [1] 上溢出中断使能，高电平有效。
#define QEP3_IE_UF_IE_BIT BIT0 // [0] 下溢出中断使能，高电平有效。

/* QEP3_IF QEP3中断标志寄存器 */
#define QEP3_IF_OF_IF_BIT BIT1 // [1] 上溢出中断标志。高电平有效，写1清0。当计数器计数达到计数门限时，上计数事件触发上溢出中断。
#define QEP3_IF_UF_IF_BIT BIT0 // [0] 下溢出中断标志。高电平有效，写1清0。当计数器计数达到0时，下计数事件触发下溢出中断。

/* HALLx_CFG 模块配置寄存器(x = 0,1) */
#define HALLx_CFG_SW_IE_BIT    BIT30                                                 // [30] 软件触发HALL信号变化中断使能，高电平有效。有效此位后，INFO[18]写1，将手动产生HALL信号变化中断。
#define HALLx_CFG_OV_IE_BIT    BIT29                                                 // [29] HALL计数器溢出中断使能开关。默认关闭。 0: 关闭 1: 使能
#define HALLx_CFG_CHG_IE_BIT   BIT28                                                 // [28] HALL信号变化中断使能开关。默认关闭。 0: 关闭 1: 使能
#define HALLx_CFG_SW_RE_BIT    BIT27                                                 // [27] 软件触发HALL信号变化DMA请求使能，高电平有效。有效此位后，INFO[18]写1，将手动产生HALL信号变化DMA请求。
#define HALLx_CFG_OV_RE_BIT    BIT26                                                 // [26] HALL计数器溢出DMA请求使能开关。默认关闭。 0: 关闭 1: 使能
#define HALLx_CFG_CHG_RE_BIT   BIT25                                                 // [25] HALL信号变化DMA请求使能开关。默认关闭。 0: 关闭 1: 使能
#define HALLx_CFG_HALL_EN_BIT  BIT24                                                 // [24] HALL模块使能开关。默认关闭。 0: 关闭 1: 使能
#define HALLx_CFG_FIL_75_BIT   BIT20                                                 // [20] 7/5滤波开关（连续采样7次，5次值一致）。默认关闭。 0: 关闭 1: 使能
#define HALLx_CFG_CLK_DIV_MAX  ((uint32_t)0x3)                                       // HALLx_CFG_CLK_DIV最大值
#define HALLx_CFG_CLK_DIV_POS  16                                                    // HALLx_CFG_CLK_DIV起始位
#define HALLx_CFG_CLK_DIV_MASK (uint32_t)((uint32_t)0x3 << HALLx_CFG_CLK_DIV_POS)    // HALLx_CFG_CLK_DIV位掩码
#define HALLx_CFG_CLK_DIV(x)   (uint32_t)(((x) & 0x3) << HALLx_CFG_CLK_DIV_POS)      // [17:16] HALL时钟分频系数。默认不分频。 00：不分频 01：2分频 10：4分频 11：8分频
#define HALLx_CFG_FIL_LEN_MAX  ((uint32_t)0x7FFF)                                    // HALLx_CFG_FIL_LEN最大值
#define HALLx_CFG_FIL_LEN_POS  0                                                     // HALLx_CFG_FIL_LEN起始位
#define HALLx_CFG_FIL_LEN_MASK (uint32_t)((uint32_t)0x7FFF << HALLx_CFG_FIL_LEN_POS) // HALLx_CFG_FIL_LEN位掩码
#define HALLx_CFG_FIL_LEN(x)   (uint32_t)(((x) & 0x7FFF) << HALLx_CFG_FIL_LEN_POS)   // [14:0] 滤波宽度，低于对应脉冲宽度的信号将被硬件自动过滤掉。滤波宽度的计算公式为[14:0]+ 1。

/* HALLx_INFO 模块信息寄存器 (x = 0,1) */
#define HALLx_INFO_SW_IF_BIT     BIT18                                                // [18] 软件触发HALL信号变化中断。写1触发，自动清零。
#define HALLx_INFO_OV_IF_BIT     BIT17                                                // [17] HALL计数器溢出事件标志，写1清空
#define HALLx_INFO_CHG_IF_BIT    BIT16                                                // [16] HALL信号变化事件标志，写1清空
#define HALLx_INFO_RAW_DATA_MAX  ((uint32_t)0x7)                                      // HALLx_INFO_RAW_DATA最大值
#define HALLx_INFO_RAW_DATA_POS  8                                                    // HALLx_INFO_RAW_DATA起始位
#define HALLx_INFO_RAW_DATA_MASK (uint32_t)((uint32_t)0x7 << HALLx_INFO_RAW_DATA_POS) // HALLx_INFO_RAW_DATA位掩码
#define HALLx_INFO_RAW_DATA(x)   (uint32_t)(((x) & 0x7) << HALLx_INFO_RAW_DATA_POS)   // [10:8] HALL值，未滤波结果
#define HALLx_INFO_FLT_DATA_MAX  ((uint32_t)0x7)                                      // HALLx_INFO_FLT_DATA最大值
#define HALLx_INFO_FLT_DATA_POS  0                                                    // HALLx_INFO_FLT_DATA起始位
#define HALLx_INFO_FLT_DATA_MASK (uint32_t)((uint32_t)0x7 << HALLx_INFO_FLT_DATA_POS) // HALLx_INFO_FLT_DATA位掩码
#define HALLx_INFO_FLT_DATA(x)   (uint32_t)(((x) & 0x7) << HALLx_INFO_FLT_DATA_POS)   // [2:0] HALL值，滤波结果

/* HALLx_WIDTH 宽度计数值寄存器(x = 0,1) */
#define HALLx_WIDTH_CAP_CNT_MAX  ((uint32_t)0xFFFFFF)                                      // HALLx_WIDTH_CAP_CNT最大值
#define HALLx_WIDTH_CAP_CNT_POS  0                                                         // HALLx_WIDTH_CAP_CNT起始位
#define HALLx_WIDTH_CAP_CNT_MASK (uint32_t)((uint32_t)0xFFFFFF << HALLx_WIDTH_CAP_CNT_POS) // HALLx_WIDTH_CAP_CNT位掩码
#define HALLx_WIDTH_CAP_CNT(x)   (uint32_t)(((x) & 0xFFFFFF) << HALLx_WIDTH_CAP_CNT_POS)   // [23:0] HALL 宽度计数器值

/* HALLx_TH 模块计数器门限值寄存器(x = 0,1) */
#define HALLx_TH_TH_MAX  ((uint32_t)0xFFFFFF)                              // HALLx_TH_TH最大值
#define HALLx_TH_TH_POS  0                                                 // HALLx_TH_TH起始位
#define HALLx_TH_TH_MASK (uint32_t)((uint32_t)0xFFFFFF << HALLx_TH_TH_POS) // HALLx_TH_TH位掩码
#define HALLx_TH_TH(x)   (uint32_t)(((x) & 0xFFFFFF) << HALLx_TH_TH_POS)   // [23:0] HALL计数器门限值

/* HALLx_CNT 计数寄存器(x = 0,1) */
#define HALLx_CNT_CNT_MAX  ((uint32_t)0xFFFFFF)                                // HALLx_CNT_CNT最大值
#define HALLx_CNT_CNT_POS  0                                                   // HALLx_CNT_CNT起始位
#define HALLx_CNT_CNT_MASK (uint32_t)((uint32_t)0xFFFFFF << HALLx_CNT_CNT_POS) // HALLx_CNT_CNT位掩码
#define HALLx_CNT_CNT(x)   (uint32_t)(((x) & 0xFFFFFF) << HALLx_CNT_CNT_POS)   // [23:0] HALL计数值，写入任意值可清零

/* MCPWMx_TH00(x = 0,1) */
#define MCPWMx_TH00_TH00_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH00_TH00最大值
#define MCPWMx_TH00_TH00_POS  0                                                    // MCPWMx_TH00_TH00起始位
#define MCPWMx_TH00_TH00_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH00_TH00_POS) // MCPWMx_TH00_TH00位掩码
#define MCPWMx_TH00_TH00(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH00_TH00_POS)   // [15:0] MCPWM CH0_P比较门限值，16位有符号数；当时基0使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH01(x = 0,1) */
#define MCPWMx_TH01_TH01_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH01_TH01最大值
#define MCPWMx_TH01_TH01_POS  0                                                    // MCPWMx_TH01_TH01起始位
#define MCPWMx_TH01_TH01_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH01_TH01_POS) // MCPWMx_TH01_TH01位掩码
#define MCPWMx_TH01_TH01(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH01_TH01_POS)   // [15:0] MCPWM CH0_N比较门限值，16位有符号数；当时基0使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH10(x = 0,1) */
#define MCPWMx_TH10_TH10_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH10_TH10最大值
#define MCPWMx_TH10_TH10_POS  0                                                    // MCPWMx_TH10_TH10起始位
#define MCPWMx_TH10_TH10_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH10_TH10_POS) // MCPWMx_TH10_TH10位掩码
#define MCPWMx_TH10_TH10(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH10_TH10_POS)   // 15:0] MCPWM CH1_P比较门限值，16位有符号数；当时基0使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH11(x = 0,1) */
#define MCPWMx_TH11_TH11_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH11_TH11最大值
#define MCPWMx_TH11_TH11_POS  0                                                    // MCPWMx_TH11_TH11起始位
#define MCPWMx_TH11_TH11_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH11_TH11_POS) // MCPWMx_TH11_TH11位掩码
#define MCPWMx_TH11_TH11(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH11_TH11_POS)   // [15:0] MCPWM CH1_N比较门限值，16位有符号数；当时基0使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH20(x = 0,1) */
#define MCPWMx_TH20_TH20_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH20_TH20最大值
#define MCPWMx_TH20_TH20_POS  0                                                    // MCPWMx_TH20_TH20起始位
#define MCPWMx_TH20_TH20_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH20_TH20_POS) // MCPWMx_TH20_TH20位掩码
#define MCPWMx_TH20_TH20(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH20_TH20_POS)   // [15:0] MCPWM CH2_P比较门限值，16位有符号数；当时基0使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH21(x = 0,1) */
#define MCPWMx_TH21_TH21_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH21_TH21最大值
#define MCPWMx_TH21_TH21_POS  0                                                    // MCPWMx_TH21_TH21起始位
#define MCPWMx_TH21_TH21_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH21_TH21_POS) // MCPWMx_TH21_TH21位掩码
#define MCPWMx_TH21_TH21(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH21_TH21_POS)   // [15:0] MCPWM CH2_N比较门限值，16位有符号数；当时基0使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH30(x = 0,1) */
#define MCPWMx_TH30_TH30_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH30_TH30最大值
#define MCPWMx_TH30_TH30_POS  0                                                    // MCPWMx_TH30_TH30起始位
#define MCPWMx_TH30_TH30_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH30_TH30_POS) // MCPWMx_TH30_TH30位掩码
#define MCPWMx_TH30_TH30(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH30_TH30_POS)   // [15:0] MCPWM CH3_P比较门限值，16位有符号数；当时基1使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH31(x = 0,1) */
#define MCPWMx_TH31_TH31_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TH31_TH31最大值
#define MCPWMx_TH31_TH31_POS  0                                                    // MCPWMx_TH31_TH31起始位
#define MCPWMx_TH31_TH31_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TH31_TH31_POS) // MCPWMx_TH31_TH31位掩码
#define MCPWMx_TH31_TH31(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TH31_TH31_POS)   // [15:0] MCPWM CH3_N比较门限值，16位有符号数；当时基1使能时，发生更新事件时，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TMR0(x = 0,1) */
#define MCPWMx_TMR0_TMR0_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TMR0_TMR0最大值
#define MCPWMx_TMR0_TMR0_POS  0                                                    // MCPWMx_TMR0_TMR0起始位
#define MCPWMx_TMR0_TMR0_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TMR0_TMR0_POS) // MCPWMx_TMR0_TMR0位掩码
#define MCPWMx_TMR0_TMR0(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TMR0_TMR0_POS)   // [15:0] ADC采样定时器比较门限0寄存器，16位有符号数；当MCPWM_CNT0=TMR0时产生TADC[0]事件触发ADC进行采样。MCPWM发生更新事件后，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TMR1(x = 0,1) */
#define MCPWMx_TMR1_TMR1_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TMR1_TMR1最大值
#define MCPWMx_TMR1_TMR1_POS  0                                                    // MCPWMx_TMR1_TMR1起始位
#define MCPWMx_TMR1_TMR1_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TMR1_TMR1_POS) // MCPWMx_TMR1_TMR1位掩码
#define MCPWMx_TMR1_TMR1(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TMR1_TMR1_POS)   // [15:0] ADC采样定时器比较门限1寄存器，16位有符号数；当MCPWM_CNT0=TMR1时产生TADC[1]事件触发ADC进行采样。MCPWM发生更新事件后，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TMR2(x = 0,1) */
#define MCPWMx_TMR2_TMR2_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TMR2_TMR2最大值
#define MCPWMx_TMR2_TMR2_POS  0                                                    // MCPWMx_TMR2_TMR2起始位
#define MCPWMx_TMR2_TMR2_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TMR2_TMR2_POS) // MCPWMx_TMR2_TMR2位掩码
#define MCPWMx_TMR2_TMR2(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TMR2_TMR2_POS)   // [15:0] ADC采样定时器比较门限2寄存器，16位有符号数；当MCPWM_CNT1=TMR2时产生TADC[2]事件触发ADC进行采样。发生更新事件后，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TMR3(x = 0,1) */
#define MCPWMx_TMR3_TMR3_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_TMR3_TMR3最大值
#define MCPWMx_TMR3_TMR3_POS  0                                                    // MCPWMx_TMR3_TMR3起始位
#define MCPWMx_TMR3_TMR3_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_TMR3_TMR3_POS) // MCPWMx_TMR3_TMR3位掩码
#define MCPWMx_TMR3_TMR3(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_TMR3_TMR3_POS)   // [15:0] ADC采样定时器比较门限3寄存器，16位有符号数；当MCPWM_CNT1=TMR3时产生TADC[3]事件触发ADC进行采样。发生更新事件后，本寄存器加载到MCPWM实际运行系统中。。

/* MCPWMx_TH0(x = 0,1) */
#define MCPWMx_TH0_TH_MAX  ((uint32_t)0x7FFF)                                // MCPWMx_TH0_TH最大值
#define MCPWMx_TH0_TH_POS  0                                                 // MCPWMx_TH0_TH起始位
#define MCPWMx_TH0_TH_MASK (uint32_t)((uint32_t)0x7FFF << MCPWMx_TH0_TH_POS) // MCPWMx_TH0_TH位掩码
#define MCPWMx_TH0_TH(x)   (uint32_t)(((x) & 0x7FFF) << MCPWMx_TH0_TH_POS)   // [14:0] MCPWM时基0计数器门限值，15位无符号数，MCPWM实际运行系统中的时基0计数器从-TH计数到TH；发生更新事件后，本寄存器加载到MCPWM实际运行系统中。

/* MCPWMx_TH1(x = 0,1) */
#define MCPWMx_TH1_TH_MAX  ((uint32_t)0x7FFF)                                // MCPWMx_TH1_TH最大值
#define MCPWMx_TH1_TH_POS  0                                                 // MCPWMx_TH1_TH起始位
#define MCPWMx_TH1_TH_MASK (uint32_t)((uint32_t)0x7FFF << MCPWMx_TH1_TH_POS) // MCPWMx_TH1_TH位掩码
#define MCPWMx_TH1_TH(x)   (uint32_t)(((x) & 0x7FFF) << MCPWMx_TH1_TH_POS)   // [14:0] MCPWM时基1计数器门限值，15位无符号数，MCPWM实际运行系统中的时基1计数器从-TH计数到TH；发生更新事件后，本寄存器加载到MCPWM实际运行系统中。。

/* MCPWMx_CNT0(x = 0,1) */
#define MCPWMx_CNT0_CNT_MAX  ((uint32_t)0xFFFF)                                  // MCPWMx_CNT0_CNT最大值
#define MCPWMx_CNT0_CNT_POS  0                                                   // MCPWMx_CNT0_CNT起始位
#define MCPWMx_CNT0_CNT_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_CNT0_CNT_POS) // MCPWMx_CNT0_CNT位掩码
#define MCPWMx_CNT0_CNT(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_CNT0_CNT_POS)   // [15:0] 向此寄存器写入，更改时基0计数器的设定值，发生更新事件后，本寄存器加载到MCPWM实际运行系统的时基0 CNT中。 读出的数据为MCPWM实际运行系统中时基0计数器的值。实际读出的计数范围为-TH ~ +TH

/* MCPWMx_CNT1(x = 0,1) */
#define MCPWMx_CNT1_CNT_MAX  ((uint32_t)0xFFFF)                                  // MCPWMx_CNT1_CNT最大值
#define MCPWMx_CNT1_CNT_POS  0                                                   // MCPWMx_CNT1_CNT起始位
#define MCPWMx_CNT1_CNT_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_CNT1_CNT_POS) // MCPWMx_CNT1_CNT位掩码
#define MCPWMx_CNT1_CNT(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_CNT1_CNT_POS)   // [15:0] 向此寄存器写入，更改时基1计数器的设定值，发生更新事件后，本寄存器加载到MCPWM实际运行系统的时基1 CNT中。 读出的数据为MCPWM实际运行系统中时基1计数器的值。实际读出的计数范围为-TH ~ +TH

/* MCPWMx_UPDATE(x = 0,1) */
#define MCPWMx_UPDATE_CNT1_UPDATE_BIT BIT15 // [15] 手动将加载MCPWM_CNT1寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_CNT0_UPDATE_BIT BIT14 // [14] 手动将加载MCPWM_CNT0寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH1_UPDATE_BIT  BIT13 // [13] 手动将加载MCPWM_TH1寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH0_UPDATE_BIT  BIT12 // [12] 手动将加载MCPWM_TH0寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TMR3_UPDATE_BIT BIT11 // [11] 手动将加载MCPWM_TMR3寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TMR2_UPDATE_BIT BIT10 // [10] 手动将加载MCPWM_TMR2寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TMR1_UPDATE_BIT BIT9  // [9] 手动将加载MCPWM_TMR1寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TMR0_UPDATE_BIT BIT8  // [8] 手动将加载MCPWM_TMR0寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH31_UPDATE_BIT BIT7  // [7] 手动将加载MCPWM_TH31寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH30_UPDATE_BIT BIT6  // [6] 手动将加载MCPWM_TH30寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH21_UPDATE_BIT BIT5  // [5] 手动将加载MCPWM_TH21寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH20_UPDATE_BIT BIT4  // [4] 手动将加载MCPWM_TH20寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH11_UPDATE_BIT BIT3  // [3] 手动将加载MCPWM_TH11寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH10_UPDATE_BIT BIT2  // [2] 手动将加载MCPWM_TH10寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH01_UPDATE_BIT BIT1  // [1] 手动将加载MCPWM_TH01寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。
#define MCPWMx_UPDATE_TH00_UPDATE_BIT BIT0  // [0] 手动将加载MCPWM_TH00寄存器的内容到MCPWM运行系统中。 1：加载；0：不加载。

/* MCPWMx_FCNT(x = 0,1) */
#define MCPWMx_FCNT_FCNT_MAX  ((uint32_t)0xFFFF)                                   // MCPWMx_FCNT_FCNT最大值
#define MCPWMx_FCNT_FCNT_POS  0                                                    // MCPWMx_FCNT_FCNT起始位
#define MCPWMx_FCNT_FCNT_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_FCNT_FCNT_POS) // MCPWMx_FCNT_FCNT位掩码
#define MCPWMx_FCNT_FCNT(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_FCNT_FCNT_POS)   // [15:0] 若MCPWM_FAIL012[15]=1，当发生fail0/1事件时，记录MCPWM_CNT0值，存入MCPWM_FCNT；若MCPWM_FAIL3[15]=1，当发生fail2/3事件时，记录MCPWM_CNT0值，存入MCPWM_FCNT

/* MCPWMx_EVT0(x = 0,1) */
#define MCPWMx_EVT0_TIMER3_CMP1_BIT BIT15 // [15] TIMER3 CMP1事件触发时基0开始计数
#define MCPWMx_EVT0_TIMER3_CMP0_BIT BIT14 // [14] TIMER3 CMP0事件触发时基0开始计数
#define MCPWMx_EVT0_TIMER2_CMP1_BIT BIT13 // [13] TIMER2 CMP1事件触发时基0开始计数
#define MCPWMx_EVT0_TIMER2_CMP0_BIT BIT12 // [12] TIMER2 CMP0事件触发时基0开始计数
#define MCPWMx_EVT0_TIMER1_CMP1_BIT BIT11 // [11] TIMER1 CMP1事件触发时基0开始计数
#define MCPWMx_EVT0_TIMER1_CMP0_BIT BIT10 // [10] TIMER1 CMP0事件触发时基0开始计数
#define MCPWMx_EVT0_TIMER0_CMP1_BIT BIT9  // [9] TIMER0 CMP1事件触发时基0开始计数
#define MCPWMx_EVT0_TIMER0_CMP0_BIT BIT8  // [8] TIMER0 CMP0事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM1_TMR3_BIT BIT7  // [7] MCPWM1 TMR3事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM1_TMR2_BIT BIT6  // [6] MCPWM1 TMR2事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM1_TMR1_BIT BIT5  // [5] MCPWM1 TMR1事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM1_TMR0_BIT BIT4  // [4] MCPWM1 TMR0事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM0_TMR3_BIT BIT3  // [3] MCPWM0 TMR3事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM0_TMR2_BIT BIT2  // [2] MCPWM0 TMR2事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM0_TMR1_BIT BIT1  // [1] MCPWM0 TMR1事件触发时基0开始计数
#define MCPWMx_EVT0_MCPWM0_TMR0_BIT BIT0  // [0] MCPWM0 TMR0事件触发时基0开始计数

/* MCPWMx_EVT1(x = 0,1) */
#define MCPWMx_EVT1_TIMER3_CMP1_BIT BIT15 // [15] TIMER3 CMP1事件触发时基1开始计数
#define MCPWMx_EVT1_TIMER3_CMP0_BIT BIT14 // [14] TIMER3 CMP0事件触发时基1开始计数
#define MCPWMx_EVT1_TIMER2_CMP1_BIT BIT13 // [13] TIMER2 CMP1事件触发时基1开始计数
#define MCPWMx_EVT1_TIMER2_CMP0_BIT BIT12 // [12] TIMER2 CMP0事件触发时基1开始计数
#define MCPWMx_EVT1_TIMER1_CMP1_BIT BIT11 // [11] TIMER1 CMP1事件触发时基1开始计数
#define MCPWMx_EVT1_TIMER1_CMP0_BIT BIT10 // [10] TIMER1 CMP0事件触发时基1开始计数
#define MCPWMx_EVT1_TIMER0_CMP1_BIT BIT9  // [9] TIMER0 CMP1事件触发时基1开始计数
#define MCPWMx_EVT1_TIMER0_CMP0_BIT BIT8  // [8] TIMER0 CMP0事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM1_TMR3_BIT BIT7  // [7] MCPWM1 TMR3事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM1_TMR2_BIT BIT6  // [6] MCPWM1 TMR2事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM1_TMR1_BIT BIT5  // [5] MCPWM1 TMR1事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM1_TMR0_BIT BIT4  // [4] MCPWM1 TMR0事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM0_TMR3_BIT BIT3  // [3] MCPWM0 TMR3事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM0_TMR2_BIT BIT2  // [2] MCPWM0 TMR2事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM0_TMR1_BIT BIT1  // [1] MCPWM0 TMR1事件触发时基1开始计数
#define MCPWMx_EVT1_MCPWM0_TMR0_BIT BIT0  // [0] MCPWM0 TMR0事件触发时基1开始计数

/* MCPWMx_DTH00(x = 0,1) */
#define MCPWMx_DTH00_DTH00_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH00_DTH00最大值
#define MCPWMx_DTH00_DTH00_POS  0                                                     // MCPWMx_DTH00_DTH00起始位
#define MCPWMx_DTH00_DTH00_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH00_DTH00_POS) // MCPWMx_DTH00_DTH00位掩码
#define MCPWMx_DTH00_DTH00(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH00_DTH00_POS)   // [9:0] MCPWM CH0 P通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_DTH01(x = 0,1) */
#define MCPWMx_DTH01_DTH01_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH01_DTH01最大值
#define MCPWMx_DTH01_DTH01_POS  0                                                     // MCPWMx_DTH01_DTH01起始位
#define MCPWMx_DTH01_DTH01_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH01_DTH01_POS) // MCPWMx_DTH01_DTH01位掩码
#define MCPWMx_DTH01_DTH01(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH01_DTH01_POS)   // [9:0] MCPWM CH0 N通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_DTH10(x = 0,1) */
#define MCPWMx_DTH10_DTH10_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH10_DTH10最大值
#define MCPWMx_DTH10_DTH10_POS  0                                                     // MCPWMx_DTH10_DTH10起始位
#define MCPWMx_DTH10_DTH10_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH10_DTH10_POS) // MCPWMx_DTH10_DTH10位掩码
#define MCPWMx_DTH10_DTH10(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH10_DTH10_POS)   // [9:0] MCPWM CH1 P通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_DTH11(x = 0,1) */
#define MCPWMx_DTH11_DTH11_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH11_DTH11最大值
#define MCPWMx_DTH11_DTH11_POS  0                                                     // MCPWMx_DTH11_DTH11起始位
#define MCPWMx_DTH11_DTH11_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH11_DTH11_POS) // MCPWMx_DTH11_DTH11位掩码
#define MCPWMx_DTH11_DTH11(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH11_DTH11_POS)   // [9:0] MCPWM CH1 N通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_DTH20(x = 0,1) */
#define MCPWMx_DTH20_DTH20_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH20_DTH20最大值
#define MCPWMx_DTH20_DTH20_POS  0                                                     // MCPWMx_DTH20_DTH20起始位
#define MCPWMx_DTH20_DTH20_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH20_DTH20_POS) // MCPWMx_DTH20_DTH20位掩码
#define MCPWMx_DTH20_DTH20(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH20_DTH20_POS)   // [9:0] MCPWM CH2 P通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_DTH21(x = 0,1) */
#define MCPWMx_DTH21_DTH21_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH21_DTH21最大值
#define MCPWMx_DTH21_DTH21_POS  0                                                     // MCPWMx_DTH21_DTH21起始位
#define MCPWMx_DTH21_DTH21_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH21_DTH21_POS) // MCPWMx_DTH21_DTH21位掩码
#define MCPWMx_DTH21_DTH21(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH21_DTH21_POS)   // [9:0] MCPWM CH2 N通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_DTH30(x = 0,1) */
#define MCPWMx_DTH30_DTH30_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH30_DTH30最大值
#define MCPWMx_DTH30_DTH30_POS  0                                                     // MCPWMx_DTH30_DTH30起始位
#define MCPWMx_DTH30_DTH30_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH30_DTH30_POS) // MCPWMx_DTH30_DTH30位掩码
#define MCPWMx_DTH30_DTH30(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH30_DTH30_POS)   // [9:0] MCPWM CH3 P通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_DTH31(x = 0,1) */
#define MCPWMx_DTH31_DTH31_MAX  ((uint32_t)0x3FF)                                     // MCPWMx_DTH31_DTH31最大值
#define MCPWMx_DTH31_DTH31_POS  0                                                     // MCPWMx_DTH31_DTH31起始位
#define MCPWMx_DTH31_DTH31_MASK (uint32_t)((uint32_t)0x3FF << MCPWMx_DTH31_DTH31_POS) // MCPWMx_DTH31_DTH31位掩码
#define MCPWMx_DTH31_DTH31(x)   (uint32_t)(((x) & 0x3FF) << MCPWMx_DTH31_DTH31_POS)   // [9:0] MCPWM CH3 N通道死区宽度控制寄存器，10bit无符号数

/* MCPWMx_FLT(x = 0,1) */
#define MCPWMx_FLT_CMP_FLT_CLKDIV_MAX  ((uint32_t)0xFF)                                            // MCPWMx_FLT_CMP_FLT_CLKDIV最大值
#define MCPWMx_FLT_CMP_FLT_CLKDIV_POS  8                                                           // MCPWMx_FLT_CMP_FLT_CLKDIV起始位
#define MCPWMx_FLT_CMP_FLT_CLKDIV_MASK (uint32_t)((uint32_t)0xFF << MCPWMx_FLT_CMP_FLT_CLKDIV_POS) // MCPWMx_FLT_CMP_FLT_CLKDIV位掩码
#define MCPWMx_FLT_CMP_FLT_CLKDIV(x)   (uint32_t)(((x) & 0xFF) << MCPWMx_FLT_CMP_FLT_CLKDIV_POS)   // [15:8] 比较器输出的滤波时钟分频寄存器，基于系统时钟分频，影响MCPWM_FAIL[3:0]。计算公式如下： 系统时钟 / (CMP_FLT_CLKDIV + 1)。分频范围是1-256。
#define MCPWMx_FLT_IO_FLT_CLKDIV_MAX   ((uint32_t)0xFF)                                            // MCPWMx_FLT_IO_FLT_CLKDIV最大值
#define MCPWMx_FLT_IO_FLT_CLKDIV_POS   0                                                           // MCPWMx_FLT_IO_FLT_CLKDIV起始位
#define MCPWMx_FLT_IO_FLT_CLKDIV_MASK  (uint32_t)((uint32_t)0xFF << MCPWMx_FLT_IO_FLT_CLKDIV_POS)  // MCPWMx_FLT_IO_FLT_CLKDIV位掩码
#define MCPWMx_FLT_IO_FLT_CLKDIV(x)    (uint32_t)(((x) & 0xFF) << MCPWMx_FLT_IO_FLT_CLKDIV_POS)    // [7:0] GPIO输入的滤波时钟分频寄存器，基于系统时钟分频，影响MCPWM_FAIL[3:0]。计算公式如下： 系统时钟 / (IO_FLT_CLKDIV + 1)。分频范围是1-256。

/* MCPWMx_SDCFG(x = 0,1) */
#define MCPWMx_SDCFG_TR1_AEC_BIT      BIT14                                                     // [14] 更新事件是否自动清除MCPWM_EIF[7:6]并置位MCPWM_FAIL3.MOE，恢复MCPWM通道3信号输出。 1：使能自动故障清除功能；0：关闭自动故障清除功能。
#define MCPWMx_SDCFG_TR1_T1_UEN_BIT   BIT13                                                     // [13] 时基1 t1（过零）事件更新使能。1：使能；0，关闭。
#define MCPWMx_SDCFG_TR1_T0_UEN_BIT   BIT12                                                     // [12] 时基1 t0（起点）事件更新使能。1：使能；0，关闭。
#define MCPWMx_SDCFG_TR1_UP_INTV_MAX  ((uint32_t)0xF)                                           // MCPWMx_SDCFG_TR1_UP_INTV最大值
#define MCPWMx_SDCFG_TR1_UP_INTV_POS  8                                                         // MCPWMx_SDCFG_TR1_UP_INTV起始位
#define MCPWMx_SDCFG_TR1_UP_INTV_MASK (uint32_t)((uint32_t)0xF << MCPWMx_SDCFG_TR1_UP_INTV_POS) // MCPWMx_SDCFG_TR1_UP_INTV位掩码
#define MCPWMx_SDCFG_TR1_UP_INTV(x)   (uint32_t)(((x) & 0xF) << MCPWMx_SDCFG_TR1_UP_INTV_POS)   // [11:8] 时基1更新间隔。一旦t0和t1事件发生次数同TR1_UP_INTV+1相等，MCPWM系统自动触发MCPWM_TH1，TH30，TH31和MCPWM_TMR寄存器加载到MCPWM运行系统的操作。若TR1_T1_UEN和TR1_T0_UEN均关闭，将不会触发此类型加载，只能手动触发加载。
#define MCPWMx_SDCFG_TR0_AEC_BIT      BIT6                                                      // [6] 更新事件是否自动清除MCPWM_EIF[5:4]并置位MCPWM_FAIL012.MOE，恢复MCPWM通道0/1/2信号输出。 1：使能自动故障清除功能；0：关闭自动故障清除功能。
#define MCPWMx_SDCFG_TR0_T1_UEN_BIT   BIT5                                                      // [5] 时基0 t1（过零）事件更新使能。1：使能；0，关闭。
#define MCPWMx_SDCFG_TR0_T0_UEN_BIT   BIT4                                                      // [4] 时基0 t0（起点）事件更新使能。1：使能；0，关闭。
#define MCPWMx_SDCFG_TR0_UP_INTV_MAX  ((uint32_t)0xF)                                           // MCPWMx_SDCFG_TR0_UP_INTV最大值
#define MCPWMx_SDCFG_TR0_UP_INTV_POS  0                                                         // MCPWMx_SDCFG_TR0_UP_INTV起始位
#define MCPWMx_SDCFG_TR0_UP_INTV_MASK (uint32_t)((uint32_t)0xF << MCPWMx_SDCFG_TR0_UP_INTV_POS) // MCPWMx_SDCFG_TR0_UP_INTV位掩码
#define MCPWMx_SDCFG_TR0_UP_INTV(x)   (uint32_t)(((x) & 0xF) << MCPWMx_SDCFG_TR0_UP_INTV_POS)   // [3:0] 时基0更新间隔。一旦t0和t1事件发生次数同TR0_UP_INTV+1相等，MCPWM系统自动触发MCPWM_TH0，MCPWM_TH00~TH21和MCPWM_TMR寄存器加载到MCPWM运行系统的操作。若TR0_T1_UEN和TR0_T0_UEN均关闭，将不会触发此类型加载，只能手动触发加载。

/* MCPWMx_AUEN(x = 0,1) */
#define MCPWMx_AUEN_CNT1_AUPDATE_BIT BIT15 // [15] MCPWM_CNT1自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_CNT0_AUPDATE_BIT BIT14 // [14] MCPWM_CNT0自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH1_AUPDATE_BIT  BIT13 // [13] MCPWM_TH1自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH0_AUPDATE_BIT  BIT12 // [12] MCPWM_TH0自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TMR3_AUPDATE_BIT BIT11 // [11] MCPWM_TMR3自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TMR2_AUPDATE_BIT BIT10 // [10] MCPWM_TMR2自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TMR1_AUPDATE_BIT BIT9  // [9] MCPWM_TMR1自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TMR0_AUPDATE_BIT BIT8  // [8] MCPWM_TMR0自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH31_AUPDATE_BIT BIT7  // [7] MCPWM_TH31自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH30_AUPDATE_BIT BIT6  // [6] MCPWM_TH30自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH21_AUPDATE_BIT BIT5  // [5] MCPWM_TH21自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH20_AUPDATE_BIT BIT4  // [4] MCPWM_TH20自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH11_AUPDATE_BIT BIT3  // [3] MCPWM_TH11自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH10_AUPDATE_BIT BIT2  // [2] MCPWM_TH10自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH01_AUPDATE_BIT BIT1  // [1] MCPWM_TH01自动加载使能。1：加载；0：不加载。
#define MCPWMx_AUEN_TH00_AUPDATE_BIT BIT0  // [0] MCPWM_TH00自动加载使能。1：加载；0：不加载。

/* MCPWMx_TCLK(x = 0,1) */
#define MCPWMx_TCLK_EVT_CNT1_EN_BIT  BIT9                                                 // [9] 时基1外部触发使能
#define MCPWMx_TCLK_EVT_CNT0_EN_BIT  BIT8                                                 // [8] 时基0外部触发使能
#define MCPWMx_TCLK_BASE_CNT1_EN_BIT BIT7                                                 // [7] MCPWM时基1计数器使能开关。1：使能；0：关闭。
#define MCPWMx_TCLK_BASE_CNT0_EN_BIT BIT6                                                 // [6] MCPWM时基0计数器使能开关。1：使能；0：关闭。
#define MCPWMx_TCLK_TMR3_TB_BIT      BIT5                                                 // [5] TMR3时基选择，0:时基0，1:时基1
#define MCPWMx_TCLK_TMR2_TB_BIT      BIT4                                                 // [4] TMR2时基选择，0:时基0，1:时基1
#define MCPWMx_TCLK_CLK_EN_BIT       BIT2                                                 // [2] MCPWM工作时钟使能。1：使能；0：关闭。
#define MCPWMx_TCLK_CLK_DIV_MAX      ((uint32_t)0x3)                                      // MCPWMx_TCLK_CLK_DIV最大值
#define MCPWMx_TCLK_CLK_DIV_POS      0                                                    // MCPWMx_TCLK_CLK_DIV起始位
#define MCPWMx_TCLK_CLK_DIV_MASK     (uint32_t)((uint32_t)0x3 << MCPWMx_TCLK_CLK_DIV_POS) // MCPWMx_TCLK_CLK_DIV位掩码
#define MCPWMx_TCLK_CLK_DIV(x)       (uint32_t)(((x) & 0x3) << MCPWMx_TCLK_CLK_DIV_POS)   // [1:0] MCPWM工作时钟分频寄存器。 0：系统时钟 1：系统时钟/2 2：系统时钟/4 3：系统时钟/8

/* MCPWMx_IE0(x = 0,1) */
#define MCPWMx_IE0_UP_IE_BIT   BIT14 // [14] MCPWM_TH/MCPWM_TH00~MCPWM_TH31/MCPWM_TMR0~MCPWM_TMR3等寄存器更新事件中断源使能。 1，使能；0，关闭。
#define MCPWMx_IE0_TMR3_IE_BIT BIT13 // [13] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR3中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TMR2_IE_BIT BIT12 // [12] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR2中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TMR1_IE_BIT BIT11 // [11] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR1中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TMR0_IE_BIT BIT10 // [10] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR0中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH31_IE_BIT BIT9  // [9] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH31中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH30_IE_BIT BIT8  // [8] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH30中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH21_IE_BIT BIT7  // [7] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH21中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH20_IE_BIT BIT6  // [6] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH20中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH11_IE_BIT BIT5  // [5] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH11中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH10_IE_BIT BIT4  // [4] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH10中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH01_IE_BIT BIT3  // [3] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH01中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_TH00_IE_BIT BIT2  // [2] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH00中断源使能。1，使能；0，关闭。
#define MCPWMx_IE0_T1_IE_BIT   BIT1  // [1] t1事件，计数器的计数值到达0中断源使能。 1，使能；0，关闭。
#define MCPWMx_IE0_T0_IE_BIT   BIT0  // [0] t0事件，计数器的计数值回到MCPWM_TH中断源使能。 1，使能；0，关闭。

/* MCPWMx_IF0(x = 0,1) */
#define MCPWMx_IF0_UP_IF_BIT   BIT14 // [14] 时基0更新事件 MCPWM_TH0/MCPWM_TH00~MCPWM_TH21/MCPWM_TMR等寄存器更新到MCPWM实际运行系统的中断源事件。 1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TMR3_IF_BIT BIT13 // [13] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR3中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TMR2_IF_BIT BIT12 // [12] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR2中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TMR1_IF_BIT BIT11 // [11] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR1中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TMR0_IF_BIT BIT10 // [10] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR0中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH31_IF_BIT BIT9  // [9] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH31中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH30_IF_BIT BIT8  // [8] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH30中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH21_IF_BIT BIT7  // [7] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH21中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH20_IF_BIT BIT6  // [6] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH20中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH11_IF_BIT BIT5  // [5] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH11中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH10_IF_BIT BIT4  // [4] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH10中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH01_IF_BIT BIT3  // [3] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH01中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_TH00_IF_BIT BIT2  // [2] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH00中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_T1_IF_BIT   BIT1  // [1] t1事件，MCPWM_CNT0回0中断源事件。 1，发生；0，没发生。写1清零。
#define MCPWMx_IF0_T0_IF_BIT   BIT0  // [0] t0事件，MCPWM_CNT0回到MCPWM_TH中断源事件。 1，发生；0，没发生。写1清零。

/* MCPWMx_IE1(x = 0,1) */
#define MCPWMx_IE1_UP_IE_BIT   BIT14 // [14] MCPWM_TH/MCPWM_TH00~MCPWM_TH31/MCPWM_TMR0~MCPWM_TMR3等寄存器更新到MCPWM实际运行系统的中断源使能。 1，使能；0，关闭。
#define MCPWMx_IE1_TMR3_IE_BIT BIT13 // [13] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR3中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TMR2_IE_BIT BIT12 // [12] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR2中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TMR1_IE_BIT BIT11 // [11] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR1中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TMR0_IE_BIT BIT10 // [10] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR0中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH31_IE_BIT BIT9  // [9] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH31中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH30_IE_BIT BIT8  // [8] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH30中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH21_IE_BIT BIT7  // [7] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH21中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH20_IE_BIT BIT6  // [6] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH20中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH11_IE_BIT BIT5  // [5] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH11中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH10_IE_BIT BIT4  // [4] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH10中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH01_IE_BIT BIT3  // [3] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH01中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_TH00_IE_BIT BIT2  // [2] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH00中断源使能。1，使能；0，关闭。
#define MCPWMx_IE1_T1_IE_BIT   BIT1  // [1] t1事件，计数器的计数值到达0中断源使能。 1，使能；0，关闭。
#define MCPWMx_IE1_T0_IE_BIT   BIT0  // [0] t0事件，计数器的计数值回到MCPWM_TH中断源使能。 1，使能；0，关闭。

/* MCPWMx_IF1(x = 0,1) */
#define MCPWMx_IF1_UP_IF_BIT   BIT14 // [14] 时基1更新事件 MCPWM_TH1/MCPWM_TH30~MCPWM_TH31/MCPWM_TMR等寄存器更新到MCPWM实际运行系统的中断源事件。 1，发生；0，没发生。写1清零。
#define MCPWMx_IF1_TMR3_IF_BIT BIT13 // [13] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR3中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF1_TMR2_IF_BIT BIT12 // [12] MCPWM实际运行系统中计数器的计数值等于MCPWM_TMR2中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF1_TH31_IF_BIT BIT9  // [9] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH31中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF1_TH30_IF_BIT BIT8  // [8] MCPWM实际运行系统中计数器的计数值等于MCPWM_TH30中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_IF1_T1_IF_BIT   BIT1  // [1] T1事件，MCPWM_CNT1的计数值过0中断源事件。 1，发生；0，没发生。写1清零。
#define MCPWMx_IF1_T0_IF_BIT   BIT0  // [0] T0事件，MCPWM_CNT1的计数值回到MCPWM_TH中断源事件。 1，发生；0，没发生。写1清零。

/* MCPWMx_EIE(x = 0,1) */
#define MCPWMx_EIE_FAIL3_IE_BIT BIT7 // [7] FAIL3中断源使能。1，使能；0，关闭。
#define MCPWMx_EIE_FAIL2_IE_BIT BIT6 // [6] FAIL2中断源使能。1，使能；0，关闭。
#define MCPWMx_EIE_FAIL1_IE_BIT BIT5 // [5] FAIL1中断源使能。1，使能；0，关闭。
#define MCPWMx_EIE_FAIL0_IE_BIT BIT4 // [4] FAIL0中断源使能。1，使能；0，关闭。

/* MCPWMx_RE(x = 0,1) */
#define MCPWMx_RE_TR1_T1_RE_BIT BIT7 // [7] 时基1 T1事件DMA请求使能。1：使能；0：关闭。
#define MCPWMx_RE_TR1_T0_RE_BIT BIT6 // [6] 时基1 T0事件DMA请求使能。1：使能；0：关闭。
#define MCPWMx_RE_TR0_T1_RE_BIT BIT5 // [5] 时基0 T1事件DMA请求使能。1：使能；0：关闭。
#define MCPWMx_RE_TR0_T0_RE_BIT BIT4 // [4] 时基0 T0事件DMA请求使能。1：使能；0：关闭。
#define MCPWMx_RE_TMR3_RE_BIT   BIT3 // [3] MCPWM计数器命中TMR3，DMA请求使能。1：使能；0：关闭。
#define MCPWMx_RE_TMR2_RE_BIT   BIT2 // [2] MCPWM计数器命中TMR2，DMA请求使能。1：使能；0：关闭。
#define MCPWMx_RE_TMR1_RE_BIT   BIT1 // [1] MCPWM计数器命中TMR1，DMA请求使能。1：使能；0：关闭。
#define MCPWMx_RE_TMR0_RE_BIT   BIT0 // [0] MCPWM计数器命中TMR0，DMA请求使能。1：使能；0：关闭。

/* MCPWMx_EIF(x = 0,1) */
#define MCPWMx_EIF_FAIL3_IF_BIT BIT7 // [7] FAIL3中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_EIF_FAIL2_IF_BIT BIT6 // [6] FAIL2中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_EIF_FAIL1_IF_BIT BIT5 // [5] FAIL1中断源事件。1，发生；0，没发生。写1清零。
#define MCPWMx_EIF_FAIL0_IF_BIT BIT4 // [4] FAIL0中断源事件。1，发生；0，没发生。写1清零。

/* MCPWMx_PP(x = 0,1) */
#define MCPWMx_PP_IO3_PPE_BIT BIT3 // [3] IO3推挽模式使能信号。写1，使能；写0，关闭。
#define MCPWMx_PP_IO2_PPE_BIT BIT2 // [2] IO2推挽模式使能信号。写1，使能；写0，关闭。
#define MCPWMx_PP_IO1_PPE_BIT BIT1 // [1] IO1推挽模式使能信号。写1，使能；写0，关闭。
#define MCPWMx_PP_IO0_PPE_BIT BIT0 // [0] IO0推挽模式使能信号。写1，使能；写0，关闭。

/* MCPWMx_IO01(x = 0,1) */
#define MCPWMx_IO01_CH1_WM_BIT     BIT15 // [15] CH1工作模式选择。1：边沿模式；0：互补模式。
#define MCPWMx_IO01_CH1_PN_SW_BIT  BIT14 // [14] CH1的P和N通道输出互换选择。即P通道信号最后从N通道输出，N通道的信号最后从P通道输出。1：不互换；0：互换。
#define MCPWMx_IO01_CH1_SCTRLP_BIT BIT13 // [13] 当CH1_PS=1时，输出到CH1 P通道的值。
#define MCPWMx_IO01_CH1_SCTRLN_BIT BIT12 // [12] 当CH1_NS=1时，输出到CH1 N通道的值。
#define MCPWMx_IO01_CH1_PS_BIT     BIT11 // [11] CH1 P来源。1：来自CH1_SCTRLP；0：MCPWM内部计数器产生。
#define MCPWMx_IO01_CH1_NS_BIT     BIT10 // [10] CH1 N来源。1：来自CH1_SCTRLN；0：MCPWM内部计数器产生。
#define MCPWMx_IO01_CH1_PP_BIT     BIT9  // [9] CH1 P极性选择。1：CH1 P信号取反输出；0：CH1 P信号正常输出。
#define MCPWMx_IO01_CH1_NP_BIT     BIT8  // [8] CH1 N极性选择。1：CH1 N信号取反输出；0：CH1 N信号正常输出。
#define MCPWMx_IO01_CH0_WM_BIT     BIT7  // [7] CH0工作模式选择。1：边沿模式；0：互补模式。
#define MCPWMx_IO01_CH0_PN_SW_BIT  BIT6  // [6] CH0的P和N通道输出互换选择。即P通道信号最后从N通道输出，N通道的信号最后从P通道输出。1：不互换；0：互换。
#define MCPWMx_IO01_CH0_SCTRLP_BIT BIT5  // [5] 当CH0_PS =1时，输出到CH0 P通道的值。
#define MCPWMx_IO01_CH0_SCTRLN_BIT BIT4  // [4] 当CH0_NS =1时，输出到CH0 N通道的值。
#define MCPWMx_IO01_CH0_PS_BIT     BIT3  // [3] CH0 P来源。1：来自CH0_SCTRLP；0：MCPWM实际运行系统中计数器产生。
#define MCPWMx_IO01_CH0_NS_BIT     BIT2  // [2] CH0 N来源。1：来自CH0_SCTRLN；0：MCPWM实际运行系统中计数器产生。
#define MCPWMx_IO01_CH0_PP_BIT     BIT1  // [1] CH0 P极性选择。1：CH0 P信号取反输出；0：CH0 P信号正常输出。
#define MCPWMx_IO01_CH0_NP_BIT     BIT0  // [0] CH0 N极性选择。1：CH0 N信号取反输出；0：CH0 N信号正常输出。极性选择跟随通道交换，例如CH0 N选择取反输出，同时选择了通道交换，则交换后的CH0 N仍是取反输出。

/* MCPWMx_IO23(x = 0,1) */
#define MCPWMx_IO23_CH3_WM_BIT     BIT15 // [15] CH3工作模式选择。1：Edge模式；0：互补模式。
#define MCPWMx_IO23_CH3_PN_SW_BIT  BIT14 // [14] CH3的P和N通道输出互换选择。即P通道信号最后从N通道输出，N通道的信号最后从P通道输出。1：不互换；0：互换。
#define MCPWMx_IO23_CH3_SCTRLP_BIT BIT13 // [13] 当CH3_PS =1时，输出到CH3 P通道的值。
#define MCPWMx_IO23_CH3_SCTRLN_BIT BIT12 // [12] 当CH3_NS =1时，输出到CH3 N通道的值。
#define MCPWMx_IO23_CH3_PS_BIT     BIT11 // [11] CH3 P来源。1：来自CH3_SCTRLP；0：MCPWM实际运行系统中计数器产生。
#define MCPWMx_IO23_CH3_NS_BIT     BIT10 // [10] CH3 N来源。1：来自CH3_SCTRLN；0：MCPWM实际运行系统中计数器产生。
#define MCPWMx_IO23_CH3_PP_BIT     BIT9  // [9] CH3 P极性选择。1：CH3 P信号取反输出；0：CH3 P信号正常输出。
#define MCPWMx_IO23_CH3_NP_BIT     BIT8  // [8] CH3 N极性选择。1：CH3 N信号取反输出；0：CH3 N信号正常输出。
#define MCPWMx_IO23_CH2_WM_BIT     BIT7  // [7] CH2工作模式选择。1：Edge模式；0：互补模式。
#define MCPWMx_IO23_CH2_PN_SW_BIT  BIT6  // [6] CH2的P和N通道输出互换选择。即P通道信号最后从N通道输出，N通道的信号最后从P通道输出。1：不互换；0：互换。
#define MCPWMx_IO23_CH2_SCTRLP_BIT BIT5  // [5] 当CH2_PS =1时，输出到CH2 P通道的值。
#define MCPWMx_IO23_CH2_SCTRLN_BIT BIT4  // [4] 当CH2_NS =1时，输出到CH2 N通道的值。
#define MCPWMx_IO23_CH2_PS_BIT     BIT3  // [3] CH2 P来源。1：来自CH2_SCTRLP；0：MCPWM实际运行系统中计数器产生。
#define MCPWMx_IO23_CH2_NS_BIT     BIT2  // [2] CH2 N来源。1：来自CH2_SCTRLN；0：MCPWM实际运行系统中计数器产生。
#define MCPWMx_IO23_CH20_PP_BIT    BIT1  // [1] CH2 P极性选择。1：CH2 P信号取反输出；0：CH2 P信号正常输出。
#define MCPWMx_IO23_CH2_NP_BIT     BIT0  // [0] CH2 N极性选择。1：CH2 N信号取反输出；0：CH2 N信号正常输出。 极性选择跟随通道交换，例如CH0 N选择取反输出，同时选择了通道交换，则交换后的CH0 N仍是取反输出。

/* MCPWMx_FAIL012(x = 0,1) */
#define MCPWMx_FAIL012_FAIL_0CAP_BIT    BIT15 // [15] 当发生fail0/1事件时，记录MCPWM_CNT0值，存入MCPWM_FCNT
#define MCPWMx_FAIL012_CH2N_DEFAULT_BIT BIT13 // [13] CH2 N通道默认值
#define MCPWMx_FAIL012_CH2P_DEFAULT_BIT BIT12 // [12] CH2 P通道默认值
#define MCPWMx_FAIL012_CH1N_DEFAULT_BIT BIT11 // [11] CH1 N通道默认值
#define MCPWMx_FAIL012_CH1P_DEFAULT_BIT BIT10 // [10] CH1 P通道默认值
#define MCPWMx_FAIL012_CH0N_DEFAULT_BIT BIT9  // [9] CH0 N通道默认值
#define MCPWMx_FAIL012_CH0P_DEFAULT_BIT BIT8  // [8] CH0 P通道默认值。当发生FAIL事件或MOE为0时，相应通道输出默认电平。默认电平输出不受MCPWM_IO01和MCPWM_IO23的 BIT0、BIT1、BIT8、BIT9、BIT6、BIT14通道交换和极性控制的影响，直接控制通道输出。
#define MCPWMx_FAIL012_HALT_PRT_BIT     BIT7  // [7] MCU进入HALT状态，MCPWM输出值选择。 1：正常输出；0：强制MCPWM输出保护值。
#define MCPWMx_FAIL012_MOE_BIT          BIT6  // [6] MOE控制MCPWM CH0/CH1/CH2 P和N输出值。 1：输出MCPWM产生的正常信号 0：输出CHxN_DEFAULT和CHxP_DEFAULT默认值，此默认值不受极性/通道选择等控制。 MCPWM_EIF.FAIL1_IF和MCPWM_EIF.FAIL0_IF任意一位变1将触发MOE变成0，输出默认值。
#define MCPWMx_FAIL012_FAIL1_EN_BIT     BIT5  // [5] FAIL1输入使能。1：使能；0：关闭。
#define MCPWMx_FAIL012_FAIL0_EN_BIT     BIT4  // [4] FAIL0输入使能。1：使能；0：关闭。
#define MCPWMx_FAIL012_FAIL1_POL_BIT    BIT3  // [3] FAIL1极性选择。1：信号极性取反输入，信号输入低为有效电平；0：信号极性正常输入，信号输入高为有效电平。
#define MCPWMx_FAIL012_FAIL0_POL_BIT    BIT2  // [2] FAIL0极性选择。1：信号极性取反输入，信号输入低为有效电平；0：信号极性正常输入，信号输入高为有效电平。
#define MCPWMx_FAIL012_FAIL1_SEL_BIT    BIT1  // [1] FAIL1来源选择。1：比较器；0：来自GPIO。
#define MCPWMx_FAIL012_FAIL0_SEL_BIT    BIT0  // [0] FAIL0来源选择。1：比较器；0：来自GPIO。

/* MCPWMx_FAIL3(x = 0,1) */
#define MCPWMx_FAIL3_FAIL_1CAP_BIT    BIT15 // [15] 当发生fail2/3事件时，记录MCPWM_CNT1值，存入MCPWM_FCNT
#define MCPWMx_FAIL3_CH3N_DEFAULT_BIT BIT9  // [9] CH3 N通道默认值
#define MCPWMx_FAIL3_CH3P_DEFAULT_BIT BIT8  // [8] CH3 P通道默认值。当发生FAIL事件或MOE为0时，相应通道输出默认电平。默认电平输出不受MCPWM_IO23的 BIT0、BIT1、BIT8、BIT9、BIT6、BIT14通道交换和极性控制的影响，直接控制通道输出。
#define MCPWMx_FAIL3_HALT_PRT_BIT     BIT7  // [7] MCU进入HALT状态，MCPWM输出值选择。 1：正常输出；0：强制MCPWM输出保护值。
#define MCPWMx_FAIL3_MOE_BIT          BIT6  // [6] MOE控制MCPWM CH3 P和N输出值。 1：输出MCPWM产生的正常信号 0：输出CH3N_DEFAULT和CH3P_DEFAULT默认值，此默认值不受极性/通道选择等控制。 MCPWM_EIF.FAIL2_IF和MCPWM_EIF.FAIL3_IF任意一位变1将触发MOE变成0，输出默认值。
#define MCPWMx_FAIL3_FAIL3_EN_BIT     BIT5  // [5] FAIL3输入使能。1：使能；0：关闭。
#define MCPWMx_FAIL3_FAIL2_EN_BIT     BIT4  // [4] FAIL2输入使能。1：使能；0：关闭。
#define MCPWMx_FAIL3_FAIL3_POL_BIT    BIT3  // [3] FAIL3极性选择。1：信号极性取反输入，信号输入低为有效电平；0：信号极性正常输入，信号输入高为有效电平。
#define MCPWMx_FAIL3_FAIL2_POL_BIT    BIT2  // [2] FAIL2极性选择。1：信号极性取反输入，信号输入低为有效电平；0：信号极性正常输入，信号输入高为有效电平。
#define MCPWMx_FAIL3_FAIL3_SEL_BIT    BIT1  // [1] FAIL3来源选择。1：比较器；0：来自GPIO
#define MCPWMx_FAIL3_FAIL2_SEL_BIT    BIT0  // [0] FAIL2来源选择。1：比较器；0：来自GPIO

/* MCPWMx_PRT(x = 0,1) */
#define MCPWMx_PRT_PRT_MAX  ((uint32_t)0xFFFF)                                 // MCPWMx_PRT_PRT最大值
#define MCPWMx_PRT_PRT_POS  0                                                  // MCPWMx_PRT_PRT起始位
#define MCPWMx_PRT_PRT_MASK (uint32_t)((uint32_t)0xFFFF << MCPWMx_PRT_PRT_POS) // MCPWMx_PRT_PRT位掩码
#define MCPWMx_PRT_PRT(x)   (uint32_t)(((x) & 0xFFFF) << MCPWMx_PRT_PRT_POS)   // [15:0] 写入0xDEAD，解除MCPWM寄存器写保护；写入其它值，MCPWM寄存器进入写保护。此寄存器读出恒为0。

/* MCPWMx_CHMSK(x = 0,1) */
#define MCPWMx_CHMSK_CH2P_FAIL_EN_BIT BIT5 // [5] CH2_P FAIL事件通道屏蔽使能，高有效，默认开启
#define MCPWMx_CHMSK_CH2N_FAIL_EN_BIT BIT4 // [4] CH2_N FAIL事件通道屏蔽使能，高有效，默认开启
#define MCPWMx_CHMSK_CH1P_FAIL_EN_BIT BIT3 // [3] CH1_P FAIL事件通道屏蔽使能，高有效，默认开启
#define MCPWMx_CHMSK_CH1N_FAIL_EN_BIT BIT2 // [2] CH1_N FAIL事件通道屏蔽使能，高有效，默认开启
#define MCPWMx_CHMSK_CH0P_FAIL_EN_BIT BIT1 // [1] CH0_P FAIL事件通道屏蔽使能，高有效，默认开启
#define MCPWMx_CHMSK_CH0N_FAIL_EN_BIT BIT0 // [0] CH0_N FAIL事件通道屏蔽使能，1：发生FAIL事件时，CH0_N通道电平输出为默认值，0：发生FAIL事件时，CH0_N通道电平不受影响，仍由MCPWM内部硬件控制。默认开启FAIL关闭机制

/* UARTx_CTRL UARTx控制寄存器 (x = 0,1,2) */
#define UARTx_CTRL_DUPLEX_BIT    BIT7 // [7] 双工，默认值为0。 0:全双工；1:半双工
#define UARTx_CTRL_LIN_EN_BIT    BIT6 // [6] LIN模式使能，默认值为0。 0:关闭；1:开启
#define UARTx_CTRL_MD_EN_BIT     BIT5 // [5] 使能Multi-drop，默认值为0。 0:关闭；1:开启
#define UARTx_CTRL_CK_EN_BIT     BIT4 // [4] 数据校验开关，默认值为0。 0:关闭；1:开启
#define UARTx_CTRL_CK_TYPE_BIT   BIT3 // [3] 奇偶校验配置，默认值为0。 0:偶校验（EVEN）；1: 奇校验（ODD）
#define UARTx_CTRL_BIT_ORDER_BIT BIT2 // [2] 数据发送顺序配置，默认值为0。 0:LSB；1:MSB
#define UARTx_CTRL_STOP_LEN_BIT  BIT1 // [1] 停止位长度配置，默认值为0。 0:1-Bit；1:2-Bit
#define UARTx_CTRL_BYTE_LEN_BIT  BIT0 // [0] 数据长度配置，默认值为0。 0:8-Bit；1:9-Bit

/* UARTx_DIVH UARTx波特率设置高字节寄存器 (x = 0,1,2) */
#define UARTx_DIVH_DIVH_MAX  ((uint32_t)0xFF)                                  // UARTx_DIVH_DIVH最大值
#define UARTx_DIVH_DIVH_POS  0                                                 // UARTx_DIVH_DIVH起始位
#define UARTx_DIVH_DIVH_MASK (uint32_t)((uint32_t)0xFF << UARTx_DIVH_DIVH_POS) // UARTx_DIVH_DIVH位掩码
#define UARTx_DIVH_DIVH(x)   (uint32_t)(((x) & 0xFF) << UARTx_DIVH_DIVH_POS)   // [7:0] 波特率设置高字节 BAUDRATE =主时钟/(1+256\* UART_DIVH+UART_DIVL)

/* UARTx_DIVL UARTx波特率设置低字节寄存器 (x = 0,1,2) */
#define UARTx_DIVL_DIVL_MAX  ((uint32_t)0xFF)                                  // UARTx_DIVL_DIVL最大值
#define UARTx_DIVL_DIVL_POS  0                                                 // UARTx_DIVL_DIVL起始位
#define UARTx_DIVL_DIVL_MASK (uint32_t)((uint32_t)0xFF << UARTx_DIVL_DIVL_POS) // UARTx_DIVL_DIVL位掩码
#define UARTx_DIVL_DIVL(x)   (uint32_t)(((x) & 0xFF) << UARTx_DIVL_DIVL_POS)   // [7:0] 波特率设置低字节 BAUDRATE =主时钟/(1+256\* UART_DIVH+UART_DIVL)

/* UARTx_BUFF UARTx收发缓冲寄存器 (x = 0,1,2) */
#define UARTx_BUFF_BUFF_MAX  ((uint32_t)0x1FF)                                  // UARTx_BUFF_BUFF最大值
#define UARTx_BUFF_BUFF_POS  0                                                  // UARTx_BUFF_BUFF起始位
#define UARTx_BUFF_BUFF_MASK (uint32_t)((uint32_t)0x1FF << UARTx_BUFF_BUFF_POS) // UARTx_BUFF_BUFF位掩码
#define UARTx_BUFF_BUFF(x)   (uint32_t)(((x) & 0x1FF) << UARTx_BUFF_BUFF_POS)   // [8:0] 写:发送数据缓存；读:接收数据寄存器

/* UARTx_ADR UARTx地址匹配寄存器 (x = 0,1,2) */
#define UARTx_ADR_ADR_MAX  ((uint32_t)0xFF)                                // UARTx_ADR_ADR最大值
#define UARTx_ADR_ADR_POS  0                                               // UARTx_ADR_ADR起始位
#define UARTx_ADR_ADR_MASK (uint32_t)((uint32_t)0xFF << UARTx_ADR_ADR_POS) // UARTx_ADR_ADR位掩码
#define UARTx_ADR_ADR(x)   (uint32_t)(((x) & 0xFF) << UARTx_ADR_ADR_POS)   // [7:0] 多机通讯时的从机地址

/* UARTx_STT UARTx状态寄存器 (x = 0,1,2) */
#define UARTx_STT_RX_BUSY_BIT      BIT3 // [3] 1:UART已检测到起始符并正处于接收状态 0:UART接收端空闲 此状态位只读，置位与清零均由硬件完成
#define UARTx_STT_ADR_MATCH_BIT    BIT2 // [2] Multi-drop模式下，地址匹配标志位。 1:匹配；0:未匹配。
#define UARTx_STT_TX_DONE_BIT      BIT1 // [1] 发送完成标志位。 1:完成；0:未完成。
#define UARTx_STT_TX_BUF_EMPTY_BIT BIT0 // [0] 发送缓存状态位。 1:空；0:非空。

/* UARTx_RE UARTx DMA请求使能寄存器 (x = 0,1,2) */
#define UARTx_RE_TX_BUF_EMPTY_RE_BIT BIT2 // [2] 发送缓冲区空DMA请求开关，默认值为0。 0:关闭；1:开启。
#define UARTx_RE_RX_DONE_RE_BIT      BIT1 // [1] 接收完成DMA请求开关，默认值为0。 0:关闭；1:开启。
#define UARTx_RE_TX_DONE_RE_BIT      BIT0 // [0] 发送完成DMA请求开关，默认值为0。 0:关闭；1:开启。

/* UARTx_IE UARTx中断使能寄存器 (x = 0,1,2) */
#define UARTx_IE_IDLE_IE_BIT         BIT8 // [8] 空闲帧中断使能 0:关闭；1:开启
#define UARTx_IE_LBD_IE_BIT          BIT7 // [7] LIN break character检测中断使能 0:关闭；1:开启
#define UARTx_IE_RX_OV_IE_BIT        BIT6 // [6] 接收缓冲区溢出中断使能 0:关闭；1:开启
#define UARTx_IE_TX_OV_IE_BIT        BIT5 // [5] 发送缓冲区溢出中断使能 0:关闭；1:开启
#define UARTx_IE_CK_ERR_IE_BIT       BIT4 // [4] 校验错误中断开关，默认值为0。 0:关闭；1:开启
#define UARTx_IE_STOP_ERR_IE_BIT     BIT3 // [3] 停止位错误中断开关，默认值为0。 0:关闭；1:开启
#define UARTx_IE_TX_BUF_EMPTY_IE_BIT BIT2 // [2] 发送缓冲区空中断开关，默认值为0。 0:关闭；1:开启
#define UARTx_IE_RX_DONE_IE_BIT      BIT1 // [1] 接收完成中断开关，默认值为0。 0:关闭；1:开启
#define UARTx_IE_TX_DONE_IE_BIT      BIT0 // [0] 发送完成中断开关，默认值为0。 0:关闭；1:开启

/* UARTx_IF UARTx中断标志寄存器 (x = 0,1,2) */
#define UARTx_IF_IDLE_IF_BIT         BIT8 // [8] 空闲帧中断标志，高有效，写1清零 当UART检测到空闲帧后，硬件置位这一标志，如果UARTx_IE.IDLE_IE=1，则产生中断请求；写1清零后，只有待RX_DONE_IF标志再次置位后，IDLE_IF标志才会置位。在多从机（Multi-drop）场景中，只有从机地址命中时，即UARTx_STT.ADR_MATCH=1时，表示主机此时欲与本从机通讯，IDLE_IF才会置位，否则即使UARTx_RX信号为常高，IDLE_IF也不会置位。
#define UARTx_IF_LBD_IF_BIT          BIT7 // [7] LIN break character检测中断标志，高有效，写1清零
#define UARTx_IF_RX_OV_IF_BIT        BIT6 // [6] 接收缓冲区溢出中断标志，高有效，写1清零
#define UARTx_IF_TX_OV_IF_BIT        BIT5 // [5] 发送缓冲区溢出中断标志，高有效，写1清零
#define UARTx_IF_CK_ERR_IF_BIT       BIT4 // [4] 校验错误中断标志，高有效，写1清零
#define UARTx_IF_STOP_ERR_IF_BIT     BIT3 // [3] 停止位错误中断标志，高有效，写1清零
#define UARTx_IF_TX_BUF_EMPTY_IF_BIT BIT2 // [2] 发送缓冲区空中断标志，高有效，写1清零
#define UARTx_IF_RX_DONE_IF_BIT      BIT1 // [1] 接收完成中断标志，高有效，写1清零
#define UARTx_IF_TX_DONE_IF_BIT      BIT0 // [0] 发送完成中断标志，高有效，写1清零

/* UARTx_IOC UARTx IO控制寄存器 (x = 0,1,2) */
#define UARTx_IOC_SBK_BIT     BIT7 // [7] LIN模式下，写1发送一次break character，即连续13个0，完成后自动清零，未完成时读回为1，向此位写1之前需要先配置UARTx_CTRL.LIN_EN=1，否则无法进行break character的发送
#define UARTx_IOC_LBDL_BIT    BIT6 // [6] LIN break character检测长度，10/11个0 0:10bits，1:11bits
#define UARTx_IOC_AUTO_BIT    BIT4 // [4] 波特率自适应IO端口使能开关。 0:关闭；1:开启
#define UARTx_IOC_TXD_INV_BIT BIT1 // [1] TXD输出极性使能开关，默认值为0。 0:正常输出；1:取反输出。 正常输出极性，即软件发送1，硬件发送1；取反输出极性，即应用发送1，硬件发送0。
#define UARTx_IOC_RXD_INV_BIT BIT0 // [0] RXD输入极性使能开关，默认值为0。 0:正常输入；1:取反输入。 正常输入极性，即硬件接收到1，软件接收的是1；取反输入极性，即硬件接收1，软件接收的是0。

/* I2Cx_ADDR 地址寄存器(x = 0,1) */
#define I2Cx_ADDR_ADDR_CMP_BIT BIT7                                             // [7] I2C硬件地址比较使能开关，默认值为0。 0：关闭 1：开启
#define I2Cx_ADDR_ADDR_MAX     ((uint32_t)0x7F)                                 // I2Cx_ADDR_ADDR最大值
#define I2Cx_ADDR_ADDR_POS     0                                                // I2Cx_ADDR_ADDR起始位
#define I2Cx_ADDR_ADDR_MASK    (uint32_t)((uint32_t)0x7F << I2Cx_ADDR_ADDR_POS) // I2Cx_ADDR_ADDR位掩码
#define I2Cx_ADDR_ADDR(x)      (uint32_t)(((x) & 0x7F) << I2Cx_ADDR_ADDR_POS)   // [6:0] 仅用于从模式下，I2C设备硬件地址。主模式下，从设备地址写入I2C_DATA寄存器。

/* I2Cx_CFG 系统控制寄存器(x = 0,1) */
#define I2Cx_CFG_IE_BIT         BIT7 // [7] I2C中断使能信号。默认值为0。 1：使能I2C中断 0：关闭I2C中断
#define I2Cx_CFG_TC_IE_BIT      BIT6 // [6] I2C数据传输完成中断使能信号。默认值为0。 1：使能此中断源 0：屏蔽此中断源
#define I2Cx_CFG_BUS_ERR_IE_BIT BIT5 // [5] I2C总线错误事件中断使能信号。默认值为0。 1：使能此中断源 0：屏蔽此中断源
#define I2Cx_CFG_STOP_IE_BIT    BIT4 // [4] I2CSTOP事件中断使能信号。默认值为0。 1：使能此中断源 0：屏蔽此中断源
#define I2Cx_CFG_MST_MODE_BIT   BIT1 // [1] I2C主模式使能信号。默认值为0。 1：使能主模式 0：关闭主模式
#define I2Cx_CFG_SLV_MODE_BIT   BIT0 // [0] I2C从模式使能信号。默认值为0。 1：使能从模式 0：关闭从模式

/* I2Cx_SCR 状态控制寄存器(x = 0,1) */
#define I2Cx_SCR_STT_ERR_BIT    BIT7 // [7] 总线错误状态标志位，用于主模式发送/主模式接收，写0清除。 0：无START/STOP总线错误 1：有START/STOP总线错误
#define I2Cx_SCR_LOST_ARB_BIT   BIT6 // [6] 总线仲裁丢失状态标志位，用于主模式发送/主模式接收，发生总线仲裁丢失事件将此位置1，无中断事件产生，在字节完成中断中需查此位。 总线上任何START事件将导致硬件清除此位。 0：无总线仲裁丢失错误发生 1：有总线仲裁丢失错误发生
#define I2Cx_SCR_STOP_EVT_BIT   BIT5 // [5] STOP事件状态标志位，用于主模式发送/从模式发送/主模式接收/从模式接收。写0清除。 0：无STOP事件 1：有STOP事件
#define I2Cx_SCR_BYTE_CMPLT_BIT BIT4 // [4] ACK控制位，用于主模式接收/从模式接收。发送方发送完毕当前字节，接收方对此的响应。若是发送方，此位保留0值。接收方，根据实际情况配置。 0：字节发送完成，返回NACK回应，表示接收方不能接收更多数据 1：字节发送完成，返回ACK回应，表示接收方可以继续接收数据
#define I2Cx_SCR_ADDR_DATA_BIT  BIT3 // [3] 地址数据标志位，用于主模式发送/从模式发送/主模式接收/从模式接收。START后，第一个字节为地址数据，此位是一个提示位。写0清除。 0：当前传输的数据非地址数据。 1：当前传输的数据是地址数据。
#define I2Cx_SCR_DATA_DIR_BIT   BIT2 // [2] 发送或接收控制位，主模式发送/从模式发送，此位置1，触发发送，硬件自动清零；主模式接收/从模式接收，此位置0，等待接收。 0：接收 1：触发发送
#define I2Cx_SCR_RX_ACK_BIT     BIT1 // [1] 接收响应标志位，用于主模式发送/从模式发送，告知发送方，接收方的反馈。发送方收到反馈后，对该位执行清零操作。 0：本I2C接口发送数据，接收到ACK响应。 1：本I2C接口发送数据，接收到NACK响应。
#define I2Cx_SCR_Done_BIT       BIT0 // [0] 传输完成状态标志位，用于主模式发送/从模式发送/主模式接收/从模式接收。写0清除。 0：传输未完成 1：传输已完成

/* I2C_DATA 数据寄存器(x = 0,1) */
#define I2C_DATA_DATA_MAX  ((uint32_t)0xFF)                                // I2C_DATA_DATA最大值
#define I2C_DATA_DATA_POS  0                                               // I2C_DATA_DATA起始位
#define I2C_DATA_DATA_MASK (uint32_t)((uint32_t)0xFF << I2C_DATA_DATA_POS) // I2C_DATA_DATA位掩码
#define I2C_DATA_DATA(x)   (uint32_t)(((x) & 0xFF) << I2C_DATA_DATA_POS)   // [7:0] 数据寄存器，用于主模式发送/从模式发送/主模式接收/从模式接收。发送方，写入发送数据；接收方，读取接收数据。注意，地址数据也是数据，主模式只能将要发送地址数据写入此寄存器。

/* I2Cx_MSCR 主模式寄存器(x = 0,1) */
#define I2Cx_MSCR_BUSY_BIT      BIT3 // [3] I2C总线，闲忙状态。 0：检测到STOP事件，空闲。 1：检测到START事件，忙碌。
#define I2Cx_MSCR_MST_CHECK_BIT BIT2 // [2] 主模式争抢总线标志位。争抢到总线，置1；STOP事件或者发生总线冲突本模块释放总线，置0。
#define I2Cx_MSCR_RESTART_BIT   BIT1 // [1] 再次触发START事件，写1有效。发送START完毕，硬件清0。I2C_CFG[1]置1，才能实现写1操作。
#define I2Cx_MSCR_START_BIT     BIT0 // [0] 触发START事件并发送地址数据至总线，写1有效。I2C_CFG[1]置1，才能实现写1操作。

/* I2Cx_BCR I2C传输控制寄存器(x = 0,1) */
#define I2Cx_BCR_NACK_IE_BIT     BIT7 // [7] I2C传输，NACK事件中断使能信号。 0：屏蔽此中断源 1：使能此中断源
#define I2Cx_BCR_ADDR_CMP_IE_BIT BIT6 // [6] I2C传输，硬件地址匹配中断使能信号。 0：屏蔽此中断源 1：使能此中断源
#define I2Cx_BCR_BUSRT_EN_BIT    BIT5 // [5] I2C 多数据传输使能，需要采用 DMA 方式。 1：使能 0：关闭

/* SPIx_CFG SPI控制寄存器 */
#define SPIx_CFG_DUPLEX_MAX  ((uint32_t)0x3)                                  // SPIx_CFG_DUPLEX最大值
#define SPIx_CFG_DUPLEX_POS  6                                                // SPIx_CFG_DUPLEX起始位
#define SPIx_CFG_DUPLEX_MASK (uint32_t)((uint32_t)0x3 << SPIx_CFG_DUPLEX_POS) // SPIx_CFG_DUPLEX位掩码
#define SPIx_CFG_DUPLEX(x)   (uint32_t)(((x) & 0x3) << SPIx_CFG_DUPLEX_POS)   // [7:6] 半双工模式设置 0X：关闭半双工模式 10：开启半双工模式，仅发送 11：开启半双工模式，仅接收
#define SPIx_CFG_CS_BIT      BIT5                                             // [5] SPI从设备下，片选信号来源。默认值为1。 0：Slave模式下，片选信号恒为有效值--0 1：Slave模式下，片选信号来自Master设备
#define SPIx_CFG_MS_BIT      BIT4                                             // [4] SPI主从模式选择。默认值为0。 0：Slave模式 1：Master模式
#define SPIx_CFG_CPHA_BIT    BIT3                                             // [3] SPI相位选择。默认值为0。 0：Phase为0 1：Phase为1
#define SPIx_CFG_CPOL_BIT    BIT2                                             // [2] SPI极性选择。默认值为0。 0：Polarity为0 1：Polarity为1
#define SPIx_CFG_ENDIAN_BIT  BIT1                                             // [1] SPI模块传输顺序。默认值为0。 0：MSB，高位先传输 1：LSB，低位先传输
#define SPIx_CFG_EN_BIT      BIT0                                             // [0] SPI模块使能信号。默认值为0。 0：关闭SPI模块 1：开启SPI模块

/* SPI_IE SPI中断寄存器 */
#define SPI_IE_IE_BIT         BIT7 // [7] SPI中断使能开关。默认值为0。 0：关闭SPI中断 1：使能SPI中断
#define SPI_IE_CMPLT_IE_BIT   BIT6 // [6] SPI传输，完成事件中断使能信号。 0：屏蔽此中断源 1：使能此中断源
#define SPI_IE_AB_IE_BIT      BIT5 // [5] SPI传输，异常事件中断使能信号。 0：屏蔽此中断源 1：使能此中断源
#define SPI_IE_OV_IE_BIT      BIT4 // [4] SPI传输，溢出事件中断使能信号。默认值为0。 0：屏蔽此中断源 1：使能此中断源
#define SPI_IE_TRANS_TRIG_BIT BIT3 // [3] 传输触发选择。 1：外部触发 0：内部自动执行。仅主模式有效
#define SPI_IE_CMPLT_IF_BIT   BIT2 // [2] SPI传输，完成事件。高电平有效，写1清除。
#define SPI_IE_AB_IF_BIT      BIT1 // [1] SPI传输，异常事件。Slave模式下，传输未完成，发生片选信号无效事件。高电平有效，写1清除。
#define SPI_IE_OV_IF_BIT      BIT0 // [0] SPI传输，溢出事件。前次接收的旧数据没有被取走，本次接收的新数据已经到达。 高电平有效，写1清除。

/* SPI_BAUD SPI波特率寄存器 */
#define SPI_BAUD_TRANS_MODE_BIT BIT15                                            // [15] SPI 数据搬移方式。默认为 0，DMA 方式。 0：SPI 接口支持 DMA 搬移数据到 SPI 接口，完成发送和接收。 1：SPI 接口支持 MCU 搬移数据到 SPI 接口，完成发送和接收。
#define SPI_BAUD_BAUD_MAX       ((uint32_t)0xFFF)                                // SPI_BAUD_BAUD最大值
#define SPI_BAUD_BAUD_POS       0                                                // SPI_BAUD_BAUD起始位
#define SPI_BAUD_BAUD_MASK      (uint32_t)((uint32_t)0xFFF << SPI_BAUD_BAUD_POS) // SPI_BAUD_BAUD位掩码
#define SPI_BAUD_BAUD(x)        (uint32_t)(((x) & 0xFFF) << SPI_BAUD_BAUD_POS)   // [11:0] SPI传输波特率配置，SPI实际传输速度计算公式为： SPI传输速度 = 系统时钟 / (2\*(BAUD + 1)) 切记，BAUD的配置值不能小于3。

/* SPI_TXDATA SPI数据发送寄存器 */
#define SPI_TXDATA_TX_DATA_MAX  ((uint32_t)0xFFFF)                                     // SPI_TXDATA_TX_DATA最大值
#define SPI_TXDATA_TX_DATA_POS  0                                                      // SPI_TXDATA_TX_DATA起始位
#define SPI_TXDATA_TX_DATA_MASK (uint32_t)((uint32_t)0xFFFF << SPI_TXDATA_TX_DATA_POS) // SPI_TXDATA_TX_DATA位掩码
#define SPI_TXDATA_TX_DATA(x)   (uint32_t)(((x) & 0xFFFF) << SPI_TXDATA_TX_DATA_POS)   // [15:0] SPI数据发送寄存器

/* SPI_RXDATA SPI数据接收寄存器 */
#define SPI_RXDATA_RX_DATA_MAX  ((uint32_t)0xFFFF)                                     // SPI_RXDATA_RX_DATA最大值
#define SPI_RXDATA_RX_DATA_POS  0                                                      // SPI_RXDATA_RX_DATA起始位
#define SPI_RXDATA_RX_DATA_MASK (uint32_t)((uint32_t)0xFFFF << SPI_RXDATA_RX_DATA_POS) // SPI_RXDATA_RX_DATA位掩码
#define SPI_RXDATA_RX_DATA(x)   (uint32_t)(((x) & 0xFFFF) << SPI_RXDATA_RX_DATA_POS)   // [15:0] SPI数据接收寄存器

/* SPI_SIZE SPI数据字节长度寄存器 */
#define SPI_SIZE_BITSIZE_MAX  ((uint32_t)0x1F)                                   // SPI_SIZE_BITSIZE最大值
#define SPI_SIZE_BITSIZE_POS  0                                                  // SPI_SIZE_BITSIZE起始位
#define SPI_SIZE_BITSIZE_MASK (uint32_t)((uint32_t)0x1F << SPI_SIZE_BITSIZE_POS) // SPI_SIZE_BITSIZE位掩码
#define SPI_SIZE_BITSIZE(x)   (uint32_t)(((x) & 0x1F) << SPI_SIZE_BITSIZE_POS)   // [4:0] 字节长度寄存器。 0x00：非法值 0x07：非法值 0x08：8-Bit 0x09：9-Bit … 0x0E：14-Bit 0x0F：15-Bit 0x10：16-Bit

/* CMP_IE中断使能寄存器 */
#define CMP_IE_CMP5_RE_BIT BIT13 // [13] 比较器5 DMA请求使能，高有效
#define CMP_IE_CMP4_RE_BIT BIT12 // [12] 比较器4 DMA请求使能，高有效
#define CMP_IE_CMP3_RE_BIT BIT11 // [11] 比较器3 DMA请求使能，高有效
#define CMP_IE_CMP2_RE_BIT BIT10 // [10] 比较器2 DMA请求使能，高有效
#define CMP_IE_CMP1_RE_BIT BIT9  // [9] 比较器1 DMA请求使能，高有效
#define CMP_IE_CMP0_RE_BIT BIT8  // [8] 比较器0 DMA请求使能，高有效
#define CMP_IE_CMP5_IE_BIT BIT5  // [5] 比较器5中断使能，高有效
#define CMP_IE_CMP4_IE_BIT BIT4  // [4] 比较器4中断使能，高有效
#define CMP_IE_CMP3_IE_BIT BIT3  // [3] 比较器3中断使能，高有效
#define CMP_IE_CMP2_IE_BIT BIT2  // [2] 比较器2中断使能，高有效
#define CMP_IE_CMP1_IE_BIT BIT1  // [1] 比较器1中断使能，高有效
#define CMP_IE_CMP0_IE_BIT BIT0  // [0] 比较器0中断使能，高有效

/* CMP_IF中断标志寄存器 */
#define CMP_IF_CMP5_IF_BIT BIT5 // [5] 比较器5中断标志，高有效，写1清零
#define CMP_IF_CMP4_IF_BIT BIT4 // [4] 比较器4中断标志，高有效，写1清零
#define CMP_IF_CMP3_IF_BIT BIT3 // [3] 比较器3中断标志，高有效，写1清零
#define CMP_IF_CMP2_IF_BIT BIT2 // [2] 比较器2中断标志，高有效，写1清零
#define CMP_IF_CMP1_IF_BIT BIT1 // [1] 比较器1中断标志，高有效，写1清零
#define CMP_IF_CMP0_IF_BIT BIT0 // [0] 比较器0中断标志，高有效，写1清零

/* CMP_TCLK分频时钟控制寄存器 */
#define CMP_TCLK_FIL_CLK54_DIV16_MAX  ((uint32_t)0xF)                                           // CMP_TCLK_FIL_CLK54_DIV16最大值
#define CMP_TCLK_FIL_CLK54_DIV16_POS  20                                                        // CMP_TCLK_FIL_CLK54_DIV16起始位
#define CMP_TCLK_FIL_CLK54_DIV16_MASK (uint32_t)((uint32_t)0xF << CMP_TCLK_FIL_CLK54_DIV16_POS) // CMP_TCLK_FIL_CLK54_DIV16位掩码
#define CMP_TCLK_FIL_CLK54_DIV16(x)   (uint32_t)(((x) & 0xF) << CMP_TCLK_FIL_CLK54_DIV16_POS)   // [23:20] 比较器5/4滤波时钟分频，基于MCLK进行1~16分频，影响进入比较器中断的时间
#define CMP_TCLK_CLK54_EN_BIT         BIT19                                                     // [19] 比较器5/4时钟使能，高有效
#define CMP_TCLK_FIL_CLK54_DIV2_MAX   ((uint32_t)0x7)                                           // CMP_TCLK_FIL_CLK54_DIV2最大值
#define CMP_TCLK_FIL_CLK54_DIV2_POS   16                                                        // CMP_TCLK_FIL_CLK54_DIV2起始位
#define CMP_TCLK_FIL_CLK54_DIV2_MASK  (uint32_t)((uint32_t)0x7 << CMP_TCLK_FIL_CLK54_DIV2_POS)  // CMP_TCLK_FIL_CLK54_DIV2位掩码
#define CMP_TCLK_FIL_CLK54_DIV2(x)    (uint32_t)(((x) & 0x7) << CMP_TCLK_FIL_CLK54_DIV2_POS)    // [18:16] 比较器5/4滤波时钟分频，3’h0:1分频, 3’h1:2分频, 3’h2:4分频, 3’h3:8分频, 3’h4:16分频, 3’h5:32分频, 3’h6:64分频, 3’h7:128分频
#define CMP_TCLK_FIL_CLK32_DIV16_MAX  ((uint32_t)0xF)                                           // CMP_TCLK_FIL_CLK32_DIV16最大值
#define CMP_TCLK_FIL_CLK32_DIV16_POS  12                                                        // CMP_TCLK_FIL_CLK32_DIV16起始位
#define CMP_TCLK_FIL_CLK32_DIV16_MASK (uint32_t)((uint32_t)0xF << CMP_TCLK_FIL_CLK32_DIV16_POS) // CMP_TCLK_FIL_CLK32_DIV16位掩码
#define CMP_TCLK_FIL_CLK32_DIV16(x)   (uint32_t)(((x) & 0xF) << CMP_TCLK_FIL_CLK32_DIV16_POS)   // [15:12] 比较器3/2滤波时钟分频，基于MCLK进行1~16分频，影响进入比较器中断的时间
#define CMP_TCLK_CLK32_EN_BIT         BIT11                                                     // [11] 比较器3/2时钟使能，高有效
#define CMP_TCLK_FIL_CLK32_DIV2_MAX   ((uint32_t)0x7)                                           // CMP_TCLK_FIL_CLK32_DIV2最大值
#define CMP_TCLK_FIL_CLK32_DIV2_POS   8                                                         // CMP_TCLK_FIL_CLK32_DIV2起始位
#define CMP_TCLK_FIL_CLK32_DIV2_MASK  (uint32_t)((uint32_t)0x7 << CMP_TCLK_FIL_CLK32_DIV2_POS)  // CMP_TCLK_FIL_CLK32_DIV2位掩码
#define CMP_TCLK_FIL_CLK32_DIV2(x)    (uint32_t)(((x) & 0x7) << CMP_TCLK_FIL_CLK32_DIV2_POS)    // [10:8] 比较器3/2滤波时钟分频，3’h0:1分频, 3’h1:2分频, 3’h2:4分频, 3’h3:8分频, 3’h4:16分频, 3’h5:32分频, 3’h6:64分频, 3’h7:128分频
#define CMP_TCLK_FIL_CLK10_DIV16_MAX  ((uint32_t)0xF)                                           // CMP_TCLK_FIL_CLK10_DIV16最大值
#define CMP_TCLK_FIL_CLK10_DIV16_POS  4                                                         // CMP_TCLK_FIL_CLK10_DIV16起始位
#define CMP_TCLK_FIL_CLK10_DIV16_MASK (uint32_t)((uint32_t)0xF << CMP_TCLK_FIL_CLK10_DIV16_POS) // CMP_TCLK_FIL_CLK10_DIV16位掩码
#define CMP_TCLK_FIL_CLK10_DIV16(x)   (uint32_t)(((x) & 0xF) << CMP_TCLK_FIL_CLK10_DIV16_POS)   // [7:4] 比较器1/0滤波时钟分频，基于MCLK进行1~16分频，影响进入比较器中断的时间
#define CMP_TCLK_CLK10_EN_BIT         BIT3                                                      // [3] 比较器1/0滤波时钟使能，高有效
#define CMP_TCLK_FIL_CLK10_DIV2_MAX   ((uint32_t)0x7)                                           // CMP_TCLK_FIL_CLK10_DIV2最大值
#define CMP_TCLK_FIL_CLK10_DIV2_POS   0                                                         // CMP_TCLK_FIL_CLK10_DIV2起始位
#define CMP_TCLK_FIL_CLK10_DIV2_MASK  (uint32_t)((uint32_t)0x7 << CMP_TCLK_FIL_CLK10_DIV2_POS)  // CMP_TCLK_FIL_CLK10_DIV2位掩码
#define CMP_TCLK_FIL_CLK10_DIV2(x)    (uint32_t)(((x) & 0x7) << CMP_TCLK_FIL_CLK10_DIV2_POS)    // [2:0] 比较器1/0滤波时钟分频，3’h0:1分频, 3’h1:2分频, 3’h2:4分频, 3’h3:8分频, 3’h4:16分频, 3’h5:32分频, 3’h6:64分频, 3’h7:128分频

/* CMP_CFG控制寄存器 */
#define CMP_CFG_CMP5_W_PWM_POL_BIT BIT23 // [23] 比较器5开窗PWM信号极性选择，在CMP_BLCWIN1使能情况下使用
#define CMP_CFG_CMP5_IRQ_TRIG_BIT  BIT22 // [22] 比较器5中断触发类型，0:电平触发，1:上升沿触发
#define CMP_CFG_CMP5_IN_EN_BIT     BIT21 // [21] 比较器5信号输入使能
#define CMP_CFG_CMP5_POL_BIT       BIT20 // [20] 比较器5极性选择，0:高电平有效；1:低电平有效
#define CMP_CFG_CMP4_W_PWM_POL_BIT BIT19 // [19] 比较器4开窗PWM信号极性选择，在CMP_BLCWIN1使能情况下使用
#define CMP_CFG_CMP4_IRQ_TRIG_BIT  BIT18 // [18] 比较器4中断触发类型，0:电平触发，1:上升沿触发
#define CMP_CFG_CMP4_IN_EN_BIT     BIT17 // [17] 比较器4信号输入使能
#define CMP_CFG_CMP4_POL_BIT       BIT16 // [16] 比较器4极性选择，0:高电平有效；1:低电平有效
#define CMP_CFG_CMP3_W_PWM_POL_BIT BIT15 // [15] 比较器3开窗PWM信号极性选择，在CMP_BLCWIN0使能情况下使用
#define CMP_CFG_CMP3_IRQ_TRIG_BIT  BIT14 // [14] 比较器3中断触发类型，0:电平触发，1:上升沿触发
#define CMP_CFG_CMP3_IN_EN_BIT     BIT13 // [13] 比较器3信号输入使能
#define CMP_CFG_CMP3_POL_BIT       BIT12 // [12] 比较器3极性选择，0:高电平有效；1:低电平有效
#define CMP_CFG_CMP2_W_PWM_POL_BIT BIT11 // [11] 比较器2开窗PWM信号极性选择，在CMP_BLCWIN0使能情况下使用
#define CMP_CFG_CMP2_IRQ_TRIG_BIT  BIT10 // [10] 比较器2中断触发类型，0:电平触发，1:上升沿触发
#define CMP_CFG_CMP2_IN_EN_BIT     BIT9  // [9] 比较器2信号输入使能
#define CMP_CFG_CMP2_POL_BIT       BIT8  // [8] 比较器2极性选择，0:高电平有效；1:低电平有效
#define CMP_CFG_CMP1_W_PWM_POL_BIT BIT7  // [7] 比较器1开窗PWM信号极性选择，在CMP_BLCWIN0使能情况下使用
#define CMP_CFG_CMP1_IRQ_TRIG_BIT  BIT6  // [6] 比较器1中断触发类型，0:电平触发，1:上升沿触发
#define CMP_CFG_CMP1_IN_EN_BIT     BIT5  // [5] 比较器1信号输入使能
#define CMP_CFG_CMP1_POL_BIT       BIT4  // [4] 比较器1极性选择，0:高电平有效；1:低电平有效
#define CMP_CFG_CMP0_W_PWM_POL_BIT BIT3  // [3] 比较器0开窗PWM信号极性选择，在CMP_BLCWIN0使能情况下使用
#define CMP_CFG_CMP0_IRQ_TRIG_BIT  BIT2  // [2] 比较器0中断触发类型，0:电平触发，1:上升沿触发
#define CMP_CFG_CMP0_IN_EN_BIT     BIT1  // [1] 比较器0信号输入使能
#define CMP_CFG_CMP0_POL_BIT       BIT0  // [0] 比较器0极性选择，0:高电平有效；1:低电平有效

/* CMP_BLCWIN0开窗控制寄存器0 */
#define CMP_BLCWIN0_CMP3_CHN3P_WIN_EN_BIT BIT15 // [15] 使用MCPWM1模块CHN3_P通道输出的P管开关控制信号作为比较器3开窗使能
#define CMP_BLCWIN0_CMP3_CHN2P_WIN_EN_BIT BIT14 // [14] 使用MCPWM1模块CHN2_P通道输出的P管开关控制信号作为比较器3开窗使能
#define CMP_BLCWIN0_CMP3_CHN1P_WIN_EN_BIT BIT13 // [13] 使用MCPWM1模块CHN1_P通道输出的P管开关控制信号作为比较器3开窗使能
#define CMP_BLCWIN0_CMP3_CHN0P_WIN_EN_BIT BIT12 // [12] 使用MCPWM1模块CHN0_P通道输出的P管开关控制信号作为比较器3开窗使能
#define CMP_BLCWIN0_CMP2_CHN3P_WIN_EN_BIT BIT11 // [11] 使用MCPWM1模块CHN3_P通道输出的P管开关控制信号作为比较器2开窗使能
#define CMP_BLCWIN0_CMP2_CHN2P_WIN_EN_BIT BIT10 // [10] 使用MCPWM1模块CHN2_P通道输出的P管开关控制信号作为比较器2开窗使能
#define CMP_BLCWIN0_CMP2_CHN1P_WIN_EN_BIT BIT9  // [9] 使用MCPWM1模块CHN1_P通道输出的P管开关控制信号作为比较器2开窗使能
#define CMP_BLCWIN0_CMP2_CHN0P_WIN_EN_BIT BIT8  // [8] 使用MCPWM1模块CHN0_P通道输出的P管开关控制信号作为比较器2开窗使能
#define CMP_BLCWIN0_CMP1_CHN3P_WIN_EN_BIT BIT7  // [7] 使用MCPWM0模块CHN3_P通道输出的P管开关控制信号作为比较器1开窗使能
#define CMP_BLCWIN0_CMP1_CHN2P_WIN_EN_BIT BIT6  // [6] 使用MCPWM0模块CHN2_P通道输出的P管开关控制信号作为比较器1开窗使能
#define CMP_BLCWIN0_CMP1_CHN1P_WIN_EN_BIT BIT5  // [5] 使用MCPWM0模块CHN1_P通道输出的P管开关控制信号作为比较器1开窗使能
#define CMP_BLCWIN0_CMP1_CHN0P_WIN_EN_BIT BIT4  // [4] 使用MCPWM0模块CHN0_P通道输出的P管开关控制信号作为比较器1开窗使能
#define CMP_BLCWIN0_CMP0_CHN3P_WIN_EN_BIT BIT3  // [3] 使用MCPWM0模块CHN3_P通道输出的P管开关控制信号作为比较器0开窗使能
#define CMP_BLCWIN0_CMP0_CHN2P_WIN_EN_BIT BIT2  // [2] 使用MCPWM0模块CHN2_P通道输出的P管开关控制信号作为比较器0开窗使能
#define CMP_BLCWIN0_CMP0_CHN1P_WIN_EN_BIT BIT1  // [1] 使用MCPWM0模块CHN1_P通道输出的P管开关控制信号作为比较器0开窗使能
#define CMP_BLCWIN0_CMP0_CHN0P_WIN_EN_BIT BIT0  // [0] 使用MCPWM0模块CHN0_P通道输出的P管开关控制信号作为比较器0开窗使能

/* CMP_BLCWIN1开窗控制寄存器1 */
#define CMP_BLCWIN1_CMP5_1CHN3P_WIN_EN_BIT BIT15 // [15] 使用MCPWM1模块CHN3_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP5_1CHN2P_WIN_EN_BIT BIT14 // [14] 使用MCPWM1模块CHN2_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP5_1CHN1P_WIN_EN_BIT BIT13 // [13] 使用MCPWM1模块CHN1_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP5_1CHN0P_WIN_EN_BIT BIT12 // [12] 使用MCPWM1模块CHN0_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP5_0CHN3P_WIN_EN_BIT BIT11 // [11] 使用MCPWM0模块CHN3_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP5_0CHN2P_WIN_EN_BIT BIT10 // [10] 使用MCPWM0模块CHN2_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP5_0CHN1P_WIN_EN_BIT BIT9  // [9] 使用MCPWM0模块CHN1_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP5_0CHN0P_WIN_EN_BIT BIT8  // [8] 使用MCPWM0模块CHN0_P通道输出的P管开关控制信号作为比较器5开窗使能
#define CMP_BLCWIN1_CMP4_1CHN3P_WIN_EN_BIT BIT7  // [7] 使用MCPWM1模块CHN3_P通道输出的P管开关控制信号1作为比较器4开窗使能
#define CMP_BLCWIN1_CMP4_1CHN2P_WIN_EN_BIT BIT6  // [6] 使用MCPWM1模块CHN2_P通道输出的P管开关控制信号作为比较器4开窗使能
#define CMP_BLCWIN1_CMP4_1CHN1P_WIN_EN_BIT BIT5  // [5] 使用MCPWM1模块CHN1_P通道输出的P管开关控制信号作为比较器4开窗使能
#define CMP_BLCWIN1_CMP4_1CHN0P_WIN_EN_BIT BIT4  // [4] 使用MCPWM1模块CHN0_P通道输出的P管开关控制信号作为比较器4开窗使能
#define CMP_BLCWIN1_CMP4_0CHN3P_WIN_EN_BIT BIT3  // [3] 使用MCPWM0模块CHN3_P通道输出的P管开关控制信号作为比较器4开窗使能
#define CMP_BLCWIN1_CMP4_0CHN2P_WIN_EN_BIT BIT2  // [2] 使用MCPWM0模块CHN2_P通道输出的P管开关控制信号作为比较器4开窗使能
#define CMP_BLCWIN1_CMP4_0CHN1P_WIN_EN_BIT BIT1  // [1] 使用MCPWM0模块CHN1_P通道输出的P管开关控制信号作为比较器4开窗使能
#define CMP_BLCWIN1_CMP4_0CHN0P_WIN_EN_BIT BIT0  // [0] 使用MCPWM0模块CHN0_P通道输出的P管开关控制信号作为比较器4开窗使能

/* CMP_DATA输出数据寄存器 */
#define CMP_DATA_CMP5_FLT_DATA_BIT BIT13 // [13] 比较器5经过滤波后的信号
#define CMP_DATA_CMP4_FLT_DATA_BIT BIT12 // [12] 比较器4经过滤波后的信号
#define CMP_DATA_CMP3_FLT_DATA_BIT BIT11 // [11] 比较器3经过滤波后的信号
#define CMP_DATA_CMP2_FLT_DATA_BIT BIT10 // [10] 比较器2经过滤波后的信号
#define CMP_DATA_CMP1_FLT_DATA_BIT BIT9  // [9] 比较器1经过滤波后的信号
#define CMP_DATA_CMP0_FLT_DATA_BIT BIT8  // [8] 比较器0经过滤波后的信号
#define CMP_DATA_CMP5_RAW_DATA_BIT BIT5  // [5] 比较器5原始输出信号，直接来自模拟比较器5
#define CMP_DATA_CMP4_RAW_DATA_BIT BIT4  // [4] 比较器4原始输出信号，直接来自模拟比较器4
#define CMP_DATA_CMP3_RAW_DATA_BIT BIT3  // [3] 比较器3原始输出信号，直接来自模拟比较器3
#define CMP_DATA_CMP2_RAW_DATA_BIT BIT2  // [2] 比较器2原始输出信号，直接来自模拟比较器2
#define CMP_DATA_CMP1_RAW_DATA_BIT BIT1  // [1] 比较器1原始输出信号，直接来自模拟比较器1
#define CMP_DATA_CMP0_RAW_DATA_BIT BIT0  // [0] 比较器0原始输出信号，直接来自模拟比较器0

/* CAN寄存器位分配表 */

/* CAN_RBUF0~CAN_RBU19寄存器 */
#define CAN_RBUF0_RDATA_MAX  ((uint32_t)0xFFFFFFFF)                                  // CAN_RBUF0_RDATA最大值
#define CAN_RBUF0_RDATA_POS  0                                                       // CAN_RBUF0_RDATA起始位
#define CAN_RBUF0_RDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CAN_RBUF0_RDATA_POS) // CAN_RBUF0_RDATA位掩码
#define CAN_RBUF0_RDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CAN_RBUF0_RDATA_POS)   // [31:0] 接收缓冲区寄存器，从Rx Buffer Slot中读出CAN帧的数据

/* CAN_TBUF0~CAN_TBUF17寄存器器 */
#define CAN_TBUF0_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                  // CAN_TBUF0_WDATA最大值
#define CAN_TBUF0_WDATA_POS  0                                                       // CAN_TBUF0_WDATA起始位
#define CAN_TBUF0_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CAN_TBUF0_WDATA_POS) // CAN_TBUF0_WDATA位掩码
#define CAN_TBUF0_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CAN_TBUF0_WDATA_POS)   // [31:0] 发送数据寄存器，写入数据到Tx Buffer Slot中（PTB或者STB）

/* CAN_TTS0 发送时间戳寄存器0 */
#define CAN_TTS0_TTS_MAX  ((uint32_t)0xFFFFFFFF)                               // CAN_TTS0_TTS最大值
#define CAN_TTS0_TTS_POS  0                                                    // CAN_TTS0_TTS起始位
#define CAN_TTS0_TTS_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CAN_TTS0_TTS_POS) // CAN_TTS0_TTS位掩码
#define CAN_TTS0_TTS(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CAN_TTS0_TTS_POS)   // [31:0] 64位传输时间戳低32位 TTS 保存最后传输帧的时间戳。 如果TTSEN=1，每个新帧都会覆盖TTS。TTS旨在供时间主机用于获取SYNC消息的时间戳

/* CAN_TTS1 发送时间戳寄存器1 */
#define CAN_TTS1_TTS_MAX  ((uint32_t)0xFFFFFFFF)                               // CAN_TTS1_TTS最大值
#define CAN_TTS1_TTS_POS  0                                                    // CAN_TTS1_TTS起始位
#define CAN_TTS1_TTS_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CAN_TTS1_TTS_POS) // CAN_TTS1_TTS位掩码
#define CAN_TTS1_TTS(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CAN_TTS1_TTS_POS)   // [31:0] 64位传输时间戳高32位 TTS 保存最后传输帧的时间戳。 如果TTSEN=1，每个新帧都会覆盖TTS。TTS旨在供时间主机用于获取SYNC消息的时间戳

/* CAN_CFG_STAT 配置和状态寄存器 */
#define CAN_CFG_STAT_RESET_BIT   BIT7 // [7] 1：CAN模块复位模式 0：CAN模块正常工作模式 复位模式下，CAN模块部分电路处于复位状态，部分寄存器只能在复位模式下配置；正常工作模式下，可以收发CAN帧。 注意，从复位模式切换到正常工作模式，需要等待11个CAN Bit Time的时间（例如波特率为500K，一个Bit Time就是2us，需要等待22us才能发送或者接收CAN帧）
#define CAN_CFG_STAT_LBME_BIT    BIT6 // [6] 外部回环模式使能位 1：使能 0：关闭 注意：正常通信中，禁止使能该位，使能外部回环时，注意打开CAN_RCTRL.SACK（自应答使能位）。应在CAN初始化和ID滤波设置之后再使能。
#define CAN_CFG_STAT_LBMI_BIT    BIT5 // [5] 内部回环模式使能位 1：使能 0：关闭 注意：正常通信中，禁止使能该位。应在CAN初始化和ID滤波设置之后再使能。
#define CAN_CFG_STAT_TPSS_BIT    BIT4 // [4] PTB单次传输模式使能位 1：使能 0：关闭 注意：应在CAN初始化和ID滤波设置之后再使能。
#define CAN_CFG_STAT_TSSS_BIT    BIT3 // [3] STB单次传输模式使能位 1：使能 0：关闭 注意：应在CAN初始化和ID滤波设置之后再使能。
#define CAN_CFG_STAT_RACTIVE_BIT BIT2 // [2] 接收状态标志位 0：本CAN设备，接收空闲，总线空闲 1：本CAN设备，正在接收CAN帧
#define CAN_CFG_STAT_TACTIVE_BIT BIT1 // [1] 发送状态标志位 0：本CAN设备，发送空闲 1：本CAN设备，正在发送CAN帧 注意：发送错误帧时，该位会拉高
#define CAN_CFG_STAT_BUSOFF_BIT  BIT0 // [0] 本CAN设备总线关闭状态位（Bus Off） 0：本CAN设备，不在总线关闭状态位 1：本CAN设备，处于总线关闭状态位 注意：BUSOFF写1可以清零TECNT和RECNT寄存器，但仅限于项目调试。正常使用时需要禁止对CANx_CFG_STAT.BUSOFF写1。软件操作 CANx_CFG_STAT 寄存器时需要避免使用或等于（\ =）以及与等于符号（&=），因为使用这两个符号操作 CANx_CFG_STAT 寄存器时可能会将 CANx_CFG_STAT.BUSOFF 字段误写 1，从而导致将 BUSOFF 误清零，导致BUSOFF提前恢复。

/* CAN_TCMD发送命令寄存器 */
#define CAN_TCMD_TBSEL_BIT BIT7 // [7] Tx Buffer选择位，通过CAN_TBUF写入到对应Buffer中 1：STB 0：PTB 注意在写入CAN_TBUF过程中，TBSEL的值不能改变；同时，在写入STB的时候，完成一帧的写入，需要更新TSNEXT。
#define CAN_TCMD_LOM_BIT   BIT6 // [6] 监听模式使能位 1：使能 0：关闭 如果设置了TPE、TSONE或TSALL，则无法设置LOM。如果LOM启用且LBME禁用，则无法启动传输。 LOM=1和LBME=0禁止所有传输。 LOM=1和LBME=1禁止应答相应接收到的帧和错误帧，但可以发送本设备的帧 注意：正常通信中，禁止使能该位
#define CAN_TCMD_TPE_BIT   BIT4 // [4] PTB发送使能位 1：触发PTB发送 0：不触发PTB发送 配置TPE，在下一个可以发送的窗口，优先STB发送PTB的数据（除非当前已经在发送STB，否则先发PTB）。 该位写1后将保持为1直到PTB发送完成或者通过TPA取消发送。软件不能通过写0清除该位。TPE可以被清除的另外几种情况： 1. CAN_CFG_STAT.RESET=1 2. CAN_TCMD.LOM=1同时CAN_CFG_STAT.LBME=0
#define CAN_TCMD_TPA_BIT   BIT3 // [3] PTB发送取消位 1：取消已经通过TPE置1请求但还未开始的PTB发送 0：不取消 软件置位，硬件自动清零。设置TPA会自动清零TPE，一般TPA和TPE不同时置位。CAN_CFG_STAT.RESET=1可清零TPA。
#define CAN_TCMD_TSONE_BIT BIT2 // [2] 发送一帧STB数据控制位（Transmit Secondary ONE Frame） 1：发送一帧STB数据 0：不发送 TSONE配置为1，触发发送，成功发送或者TSA终止发送可实现硬件清零，否则一直保持1。CAN_CFG_STAT.RESET=1，也可清零。
#define CAN_TCMD_TSALL_BIT BIT1 // [1] 发送多帧STB数据控制位（Transmit Secondary All Frames） 1：发送多帧STB数据 0：不发送 TSALL配置为1，触发发送，成功发送或者TSA终止发送可实现硬件清零，否则一直保持1。CAN_CFG_STAT.RESET=1，也可清零。
#define CAN_TCMD_TSA_BIT   BIT0 // [0] STB发送取消位 1：取消已经通过TSONE或者TSALL置1请求但还未开始的STB发送，软件写1，硬件清零。写1可以清零TSONE或者TSALL位 0：不取消 一般TSA和TSONE/TSALL，不同时置位。CAN_CFG_STAT.RESET=1可清零TSA

/* CAN_TCTRL发送控制寄存器 */
#define CAN_TCTRL_FD_ISO_BIT  BIT7                                              // [7] CAN FD ISO 模式 0 - 博世 CAN FD（非 ISO）模式 1 - ISO CAN FD 模式 (ISO 11898-1:2015) ISO CAN FD模式具有不同的CRC初始化值和额外的填充位计数。两种模式不兼容，不能在一个CAN网络中混合使用。 该位对CAN 2.0B没有影响。该位仅在 RESET=1时可写。
#define CAN_TCTRL_TSNEXT_BIT  BIT6                                              // [6] 更新STB Slot位置 1：更新 0：不更新 当前的STB Slot填满数据后，软件置位TSNEXT，硬件自动指向下一个STB Slot，此时，TSONE/TSALL置位，即可发送被填满的STB Slot。可以同时设置TSNEXT和TSONE或TSALL。如果TBSEL=0，则设置TSNEXT没有意义，TSNEXT的配置将被忽略并自动清除。如果STB的所有Slot都已填满，则TSNEXT将保持置位状态，直到Slot有空闲，才会被硬件清零。
#define CAN_TCTRL_TSMODE_BIT  BIT5                                              // [5] 发送缓冲器STB工作模式 0 - FIFO模式 1 - 优先级模式 在FIFO模式下，帧按照写入STB的顺序传输。 在优先级模式下，STB 中优先级最高的帧会先发送。 帧的ID用于优先级判定。较小的ID意味着帧的优先级更高。PTB中的帧始终具有最高优先级，与ID无关。 只有当 STB为空时，才可以切换TSMODE。
#define CAN_TCTRL_TTTBM_BIT   BIT4                                              // [4] TTCAN 发送缓冲模式 如果TTEN=0，则忽略TTTBM，如果TTEN=1，根据TTTBM不同值： 0 - 单独的PTB和STB，由TSMODE定义缓冲区行为 1 - 完整的TTCAN支持：消息槽可由TBPTR 和TTPTR选择 对于事件驱动的 CAN 通信 (TTEN=0)，系统提供PTB和STB，STB 的行为由TSMODE定义，忽略TTTBM设定。 对于支持时间触发传输在内的所有功能的TTCAN 通信 (TTEN=1)，需要选择TTTBM=1。 此时使用TTPTR和TBPTR可寻址所有TB消息槽。 对于仅支持接收时间戳的时间触发CAN通信 (TTEN=1)，可以选择 TTTBM=0。发送缓冲器在事件驱动模式下工作，并且可以通过 TSMODE 选择缓冲区行为。 只有当TBUF为空时，才可以切换TTTBM。
#define CAN_TCTRL_TSSTAT_MAX  ((uint32_t)0x3)                                   // CAN_TCTRL_TSSTAT最大值
#define CAN_TCTRL_TSSTAT_POS  0                                                 // CAN_TCTRL_TSSTAT起始位
#define CAN_TCTRL_TSSTAT_MASK (uint32_t)((uint32_t)0x3 << CAN_TCTRL_TSSTAT_POS) // CAN_TCTRL_TSSTAT位掩码
#define CAN_TCTRL_TSSTAT(x)   (uint32_t)(((x) & 0x3) << CAN_TCTRL_TSSTAT_POS)   // [1:0] STB状态位 3：STB满 2：STB大于半满 1：STB小于等于半满 0：STB空

/* CAN_RCTRL接收控制寄存器 */
#define CAN_RCTRL_SACK_BIT   BIT7                                             // [7] 自应答 1：LBME=1时，使能自应答功能 0：无自应答
#define CAN_RCTRL_ROM_BIT    BIT6                                             // [6] Rx Buffer满，溢出控制位 1：新接收到的数据不被存储 0：最早接收到的数据被覆盖
#define CAN_RCTRL_ROV_BIT    BIT5                                             // [5] Rx Buffer溢出标志位 1：溢出，最少有一帧数据丢失。通过写RREL为1清零 0：无溢出
#define CAN_RCTRL_RREL_BIT   BIT4                                             // [4] 释放Rx Buffer Slot 1：软件已经取走当前Rx Buffer Slot数据，可释放当前Rx Buffer Slot，硬件指向下一个Rx Buffer Slot 0：无释放操作
#define CAN_RCTRL_RBALL_BIT  BIT3                                             // [3] 接收Rx Buffer存储通过ID滤波的帧 1：存储所有的CAN帧，包括错误的帧 0：正常模式，仅存储正确的CAN帧
#define CAN_RCTRL_RSTAT_MAX  ((uint32_t)0x3)                                  // CAN_RCTRL_RSTAT最大值
#define CAN_RCTRL_RSTAT_POS  0                                                // CAN_RCTRL_RSTAT起始位
#define CAN_RCTRL_RSTAT_MASK (uint32_t)((uint32_t)0x3 << CAN_RCTRL_RSTAT_POS) // CAN_RCTRL_RSTAT位掩码
#define CAN_RCTRL_RSTAT(x)   (uint32_t)(((x) & 0x3) << CAN_RCTRL_RSTAT_POS)   // [1:0] Rx Buffer状态位 3：满（溢出状态下，保持此值） 2：Rx Buffer已经接收的帧的数量大于等于AFWL的值，但未满 1：Rx Buffer已经接收的帧的数量小于AFWL的值 0：Rx Buffer已经接收的帧的数量为0，空

/* CAN_RTIE发送接收中断控制寄存器 */
#define CAN_RTIE_RIE_BIT   BIT7 // [7] 接收中断使能（Receive Interrupt Enable） 1：使能 0：禁止
#define CAN_RTIE_ROIE_BIT  BIT6 // [6] 接收溢出中断使能（Receive Overrun Interrupt Enable） 1：使能 0：禁止
#define CAN_RTIE_RFIE_BIT  BIT5 // [5] Rx Buffer满中断使能（Rx Buffer Full Interrupt Enable） 1：使能 0：禁止
#define CAN_RTIE_RAFIE_BIT BIT4 // [4] Rx Buffer将满中断使能（Rx Buffer Almost Full Interrupt Enable） 1：使能 0：禁止
#define CAN_RTIE_TPIE_BIT  BIT3 // [3] PTB发送中断使能（Transmission Primary Interrupt Enable） 1：使能 0：禁止
#define CAN_RTIE_TSIE_BIT  BIT2 // [2] STB发送中断使能（Transmission Secondary Interrupt Enable） 1：使能 0：禁止
#define CAN_RTIE_EIE_BIT   BIT1 // [1] 错误中断使能（Error Interrupt Enable） 1：使能 0：禁止
#define CAN_RTIE_TSFF_BIT  BIT0 // [0] Tx Buffer标志位 1：STB Slot被全部填满 0：STB Slot没有被全部填满

/* CAN_RTIF 发送接收中断标志寄存器 */
#define CAN_RTIF_RIF_BIT   BIT7 // [7] 接收中断标志位（Receive Interrupt Flag） 1：接收到有效帧（数据帧或者远程帧），写1清零 0：没有接收到有效帧
#define CAN_RTIF_ROIF_BIT  BIT6 // [6] 接收溢出中断标志位（Receive Overrun Interrupt Flag） 1：Rx Buffer至少有一帧未读走的数据被覆盖 0：Rx Buffer无覆盖 溢出时ROIF和RFIF同时置1，写1清零
#define CAN_RTIF_RFIF_BIT  BIT5 // [5] Rx Buffer满中断标志位（Rx Buffer Full Interrupt Flag） 1：Rx Buffer满，写1清零 0：Rx Buffer未满
#define CAN_RTIF_RAFIF_BIT BIT4 // [4] Rx Buffer将满中断标志位（Rx Buffer Almost Full Interrupt Flag） 1：被填充的Rx Buffer Slot数目大于等于AFWL设定值 0：被填充的Rx Buffer Slot数目小于AFWL设定值
#define CAN_RTIF_TPIF_BIT  BIT3 // [3] PTB发送中断标志（Transmission Primary Interrupt Flag） 1：触发PTB发送，发送成功完成。写1清零 0：无PTB发送请求，无完成标志
#define CAN_RTIF_TSIF_BIT  BIT2 // [2] STB发送中断标志（Transmission Secondary Interrupt Flag） 1：触发STB发送，发送成功完成。写1清零 0：无STB发送请求，无完成标志
#define CAN_RTIF_EIF_BIT   BIT1 // [1] 错误中断标志（Error Interrupt Flag） 1：错误计数器的值发生变化，大于或者小于错误警告寄存器的设定值。写1清零 0：无 错误计数器的值从小于错误警告寄存器的设定值变为大于设定值，或者从大于设定值变为小于设定值，均会触发中断标志。另外，进入Bus Off或从Bus Off退出，也会触发。
#define CAN_RTIF_AIF_BIT   BIT0 // [0] 取消发送中断标志（Abort Interrupt Flag） 1：通过TPA和TSA请求的发送消息被成功取消。写1清零 0：未取消发送数据 AIF没有对应的使能寄存器

/* CAN_ERRINT错误中断使能和标志寄存器 */
#define CAN_ERRINT_EWARN_BIT BIT7 // [7] 错误计数值超过门限中断标志位 1：RECNT或者TECNT大于等于EWL设定值，写1清零 0：RECNT或者TECNT小于EWL设定值
#define CAN_ERRINT_EPASS_BIT BIT6 // [6] CAN设备处于被动错误状态 1：CAN设备处于被动错误状态 0：CAN设备处于主动错误状态
#define CAN_ERRINT_EPIE_BIT  BIT5 // [5] 被动错误中断使能（Error Passive Interrupt Enable） 1：使能 0：禁止
#define CAN_ERRINT_EPIF_BIT  BIT4 // [4] 被动错误中断标志（Error Passive Interrupt Flag） 1：发生主动错误到被动错误（或者相反）的改变，写1清零 0：未发生
#define CAN_ERRINT_ALIE_BIT  BIT3 // [3] 仲裁失败中断使能（Arbitration Lost Interrupt Enable） 1：使能 0：禁止
#define CAN_ERRINT_ALIF_BIT  BIT2 // [2] 仲裁失败中断标志位（Arbitration Lost Interrupt Flag） 1：仲裁失败，写1清零 0：仲裁成功
#define CAN_ERRINT_BEIE_BIT  BIT1 // [1] 总线错误中断使能（Bus Error Interrupt Enable） 1：使能 0：禁止
#define CAN_ERRINT_BEIF_BIT  BIT0 // [0] 总线错误中断标志（Bus Error Interrupt Flag） 1：总线错误，写1清零 0：无总线错误

/* CAN_LIMIT错误&警告门限值寄存器 */
#define CAN_LIMIT_AFWL_MAX  ((uint32_t)0xF)                                 // CAN_LIMIT_AFWL最大值
#define CAN_LIMIT_AFWL_POS  4                                               // CAN_LIMIT_AFWL起始位
#define CAN_LIMIT_AFWL_MASK (uint32_t)((uint32_t)0xF << CAN_LIMIT_AFWL_POS) // CAN_LIMIT_AFWL位掩码
#define CAN_LIMIT_AFWL(x)   (uint32_t)(((x) & 0xF) << CAN_LIMIT_AFWL_POS)   // [7:4] Rx Buffer快满警告配置值 AFWL同Rx Buffer实际接收到的消息数量进行比对，实际数量超过AFWL，触发RAFIF。 AFWL=0，无意义，硬件强制配置为1；AFWL超过Rx Buffer实际容量，无意义，硬件强制配置为Rx Buffer实际容量
#define CAN_LIMIT_EWL_MAX   ((uint32_t)0xF)                                 // CAN_LIMIT_EWL最大值
#define CAN_LIMIT_EWL_POS   0                                               // CAN_LIMIT_EWL起始位
#define CAN_LIMIT_EWL_MASK  (uint32_t)((uint32_t)0xF << CAN_LIMIT_EWL_POS)  // CAN_LIMIT_EWL位掩码
#define CAN_LIMIT_EWL(x)    (uint32_t)(((x) & 0xF) << CAN_LIMIT_EWL_POS)    // [3:0] 可编程错误警告限值=(EWL+1)×8。可能的极限值：8，16，…128。EWL的值控制EIF。

/* CAN_SBAUD慢速波特率配置寄存器 */
#define CAN_SBAUD_S_PRESC_MAX  ((uint32_t)0xFF)                                    // CAN_SBAUD_S_PRESC最大值
#define CAN_SBAUD_S_PRESC_POS  24                                                  // CAN_SBAUD_S_PRESC起始位
#define CAN_SBAUD_S_PRESC_MASK (uint32_t)((uint32_t)0xFF << CAN_SBAUD_S_PRESC_POS) // CAN_SBAUD_S_PRESC位掩码
#define CAN_SBAUD_S_PRESC(x)   (uint32_t)(((x) & 0xFF) << CAN_SBAUD_S_PRESC_POS)   // [31:24] 慢速时间量子（Time Quanta）TQ预分频设定值（S_Prescaler），主要配置TQ的大小。 慢速TQ = system clock period \*(S_PRESC+1)
#define CAN_SBAUD_S_SJW_MAX    ((uint32_t)0x7F)                                    // CAN_SBAUD_S_SJW最大值
#define CAN_SBAUD_S_SJW_POS    16                                                  // CAN_SBAUD_S_SJW起始位
#define CAN_SBAUD_S_SJW_MASK   (uint32_t)((uint32_t)0x7F << CAN_SBAUD_S_SJW_POS)   // CAN_SBAUD_S_SJW位掩码
#define CAN_SBAUD_S_SJW(x)     (uint32_t)(((x) & 0x7F) << CAN_SBAUD_S_SJW_POS)     // [22:16] 再同步补偿宽度时间设定（Bit Timing Segment 2） 再同步补偿宽度时间=(S_SJW+1)\*TQ
#define CAN_SBAUD_S_SEG_2_MAX  ((uint32_t)0x7F)                                    // CAN_SBAUD_S_SEG_2最大值
#define CAN_SBAUD_S_SEG_2_POS  8                                                   // CAN_SBAUD_S_SEG_2起始位
#define CAN_SBAUD_S_SEG_2_MASK (uint32_t)((uint32_t)0x7F << CAN_SBAUD_S_SEG_2_POS) // CAN_SBAUD_S_SEG_2位掩码
#define CAN_SBAUD_S_SEG_2(x)   (uint32_t)(((x) & 0x7F) << CAN_SBAUD_S_SEG_2_POS)   // [14:8] 慢速bit时间段2时间单元设定（Bit Timing Segment 2） 慢速bit时间段2时间=(S_SEG_2+1)\*TQ
#define CAN_SBAUD_S_SEG_1_MAX  ((uint32_t)0xFF)                                    // CAN_SBAUD_S_SEG_1最大值
#define CAN_SBAUD_S_SEG_1_POS  0                                                   // CAN_SBAUD_S_SEG_1起始位
#define CAN_SBAUD_S_SEG_1_MASK (uint32_t)((uint32_t)0xFF << CAN_SBAUD_S_SEG_1_POS) // CAN_SBAUD_S_SEG_1位掩码
#define CAN_SBAUD_S_SEG_1(x)   (uint32_t)(((x) & 0xFF) << CAN_SBAUD_S_SEG_1_POS)   // [7:0] 慢速bit时间段1时间单元设定（Bit Timing Segment 1） 慢速bit时间段1时间=(S_SEG_1+2)\*TQ

/* CAN_FBAUD快速波特率配置寄存器 */
#define CAN_FBAUD_F_PRESC_MAX  ((uint32_t)0xFF)                                    // CAN_FBAUD_F_PRESC最大值
#define CAN_FBAUD_F_PRESC_POS  24                                                  // CAN_FBAUD_F_PRESC起始位
#define CAN_FBAUD_F_PRESC_MASK (uint32_t)((uint32_t)0xFF << CAN_FBAUD_F_PRESC_POS) // CAN_FBAUD_F_PRESC位掩码
#define CAN_FBAUD_F_PRESC(x)   (uint32_t)(((x) & 0xFF) << CAN_FBAUD_F_PRESC_POS)   // [31:24] 快速时间量子TQ预分频率设定值（F_Prescaler），主要配置TQ的大小。 快速TQ = system clock period \*(F_PRESC+1)
#define CAN_FBAUD_F_SJW_MAX    ((uint32_t)0x7F)                                    // CAN_FBAUD_F_SJW最大值
#define CAN_FBAUD_F_SJW_POS    16                                                  // CAN_FBAUD_F_SJW起始位
#define CAN_FBAUD_F_SJW_MASK   (uint32_t)((uint32_t)0x7F << CAN_FBAUD_F_SJW_POS)   // CAN_FBAUD_F_SJW位掩码
#define CAN_FBAUD_F_SJW(x)     (uint32_t)(((x) & 0x7F) << CAN_FBAUD_F_SJW_POS)     // [22:16] 再同步补偿宽度时间设定（Bit Timing Segment 2） 再同步补偿宽度时间=(F_SJW+1)\*TQ
#define CAN_FBAUD_F_SEG_2_MAX  ((uint32_t)0xF)                                     // CAN_FBAUD_F_SEG_2最大值
#define CAN_FBAUD_F_SEG_2_POS  0                                                   // CAN_FBAUD_F_SEG_2起始位
#define CAN_FBAUD_F_SEG_2_MASK (uint32_t)((uint32_t)0xF << CAN_FBAUD_F_SEG_2_POS)  // CAN_FBAUD_F_SEG_2位掩码
#define CAN_FBAUD_F_SEG_2(x)   (uint32_t)(((x) & 0xF) << CAN_FBAUD_F_SEG_2_POS)    // [3:0] 快速bit时间段2时间单元设定（Bit Timing Segment 2） 快速bit时间段2时间=(F_SEG_2+1)\*TQ
#define CAN_FBAUD_F_SEG_1_MAX  ((uint32_t)0x1F)                                    // CAN_FBAUD_F_SEG_1最大值
#define CAN_FBAUD_F_SEG_1_POS  0                                                   // CAN_FBAUD_F_SEG_1起始位
#define CAN_FBAUD_F_SEG_1_MASK (uint32_t)((uint32_t)0x1F << CAN_FBAUD_F_SEG_1_POS) // CAN_FBAUD_F_SEG_1位掩码
#define CAN_FBAUD_F_SEG_1(x)   (uint32_t)(((x) & 0x1F) << CAN_FBAUD_F_SEG_1_POS)   // [4:0] 快速bit时间段1时间单元设定（Bit Timing Segment 1） 快速bit时间段1时间=(F_SEG_1+2)\*TQ

/* CAN_EALCAP错误信息和丢失仲裁信息记录寄存器 */
#define CAN_EALCAP_KOER_MAX  ((uint32_t)0x7)                                  // CAN_EALCAP_KOER最大值
#define CAN_EALCAP_KOER_POS  5                                                // CAN_EALCAP_KOER起始位
#define CAN_EALCAP_KOER_MASK (uint32_t)((uint32_t)0x7 << CAN_EALCAP_KOER_POS) // CAN_EALCAP_KOER位掩码
#define CAN_EALCAP_KOER(x)   (uint32_t)(((x) & 0x7) << CAN_EALCAP_KOER_POS)   // [7:5] 错误类别（Kind Of Error） 0：无错误 1：位错误 2：形式错误 3：填充错误 4：应答错误 5：CRC错误 6：其他错误 7：保留 有错误时KOER位更新，正常发送接收时KOER位保持不变。
#define CAN_EALCAP_ALC_MAX   ((uint32_t)0x1F)                                 // CAN_EALCAP_ALC最大值
#define CAN_EALCAP_ALC_POS   0                                                // CAN_EALCAP_ALC起始位
#define CAN_EALCAP_ALC_MASK  (uint32_t)((uint32_t)0x1F << CAN_EALCAP_ALC_POS) // CAN_EALCAP_ALC位掩码
#define CAN_EALCAP_ALC(x)    (uint32_t)(((x) & 0x1F) << CAN_EALCAP_ALC_POS)   // [4:0] 仲裁失败位置捕捉（Arbitration Lost Capture） 仲裁失败时ALC记录一帧数据仲裁失败时的bit位置

/* CAN_TDC发送延迟补偿寄存器 */
#define CAN_TDC_TDCEN_BIT   BIT7                                             // [7] 发送延迟补偿使能 如果TDCEN=1，BRS处于活动状态，则TDC将在CAN FD帧的数据阶段被激活。有关TDC的更多详细信息，请参见21.7.6。
#define CAN_TDC_SSPOFF_MAX  ((uint32_t)0x7F)                                 // CAN_TDC_SSPOFF最大值
#define CAN_TDC_SSPOFF_POS  0                                                // CAN_TDC_SSPOFF起始位
#define CAN_TDC_SSPOFF_MASK (uint32_t)((uint32_t)0x7F << CAN_TDC_SSPOFF_POS) // CAN_TDC_SSPOFF位掩码
#define CAN_TDC_SSPOFF(x)   (uint32_t)(((x) & 0x7F) << CAN_TDC_SSPOFF_POS)   // [6:0] 次采样点偏移 发送延迟加上SSPOFF定义了TDC的辅助采样时间点。SSPOFF的计数单位为TQ。

/* CAN_RECNT接收错误计数器寄存器 */
#define CAN_RECNT_RECNT_MAX  ((uint32_t)0xFF)                                  // CAN_RECNT_RECNT最大值
#define CAN_RECNT_RECNT_POS  0                                                 // CAN_RECNT_RECNT起始位
#define CAN_RECNT_RECNT_MASK (uint32_t)((uint32_t)0xFF << CAN_RECNT_RECNT_POS) // CAN_RECNT_RECNT位掩码
#define CAN_RECNT_RECNT(x)   (uint32_t)(((x) & 0xFF) << CAN_RECNT_RECNT_POS)   // [7:0] 接收错误计数器（Receive Error Count） 接收错误计数器根据CAN协议规定的错误计数增加或者减少。该计数器不存在上溢，255为最大值

/* CAN_TECNT发送错误计数器寄存器 */
#define CAN_TECNT_TECNT_MAX  ((uint32_t)0xFF)                                  // CAN_TECNT_TECNT最大值
#define CAN_TECNT_TECNT_POS  0                                                 // CAN_TECNT_TECNT起始位
#define CAN_TECNT_TECNT_MASK (uint32_t)((uint32_t)0xFF << CAN_TECNT_TECNT_POS) // CAN_TECNT_TECNT位掩码
#define CAN_TECNT_TECNT(x)   (uint32_t)(((x) & 0xFF) << CAN_TECNT_TECNT_POS)   // [7:0] 发送错误计数器（Transmit Error Count） 发送错误计数器根据CAN协议规定的错误计数增加或者减少。该计数器不存在上溢，255为最大值

/* CAN_ACFCTRL ID过滤器控制寄存器 */
#define CAN_ACFCTRL_SELMASK_BIT BIT5                                                // [5] 选择ID过滤器的屏蔽寄存器（Select Acceptance MASK） 1：ACF指向ID过滤器掩码AMR寄存器（MASK） 0：ACF指向ID过滤器ACR寄存器 通过ACFADR选择具体的筛选寄存器组
#define CAN_ACFCTRL_ACFADR_MAX  ((uint32_t)0xF)                                     // CAN_ACFCTRL_ACFADR最大值
#define CAN_ACFCTRL_ACFADR_POS  0                                                   // CAN_ACFCTRL_ACFADR起始位
#define CAN_ACFCTRL_ACFADR_MASK (uint32_t)((uint32_t)0xF << CAN_ACFCTRL_ACFADR_POS) // CAN_ACFCTRL_ACFADR位掩码
#define CAN_ACFCTRL_ACFADR(x)   (uint32_t)(((x) & 0xF) << CAN_ACFCTRL_ACFADR_POS)   // [3:0] ID过滤器地址（Acceptance Filter Address） ACFADR指向具体的ID过滤器，通过SELMASK去区分ACR和AMR。 0：指向ACF_0 1：指向ACF_1 2：指向ACF_2 3：指向ACF_3 4：指向ACF_4 5：指向ACF_5 6：指向ACF_6 7：指向ACF_7 8：指向ACF_8 9：指向ACF_9 10：指向ACF_10 11：指向ACF_11 12：指向ACF_12 13：指向ACF_13 14：指向ACF_14 15：指向ACF_15

/* CAN_TIMECFG CiA603时间戳配置寄存器 */
#define CAN_TIMECFG_TIMEPOS_BIT BIT1 // [1] 时间戳位置 0 - SOF 1 - EOF TIMEPOS只能在TIMEEN=0时更改，但可以在设置TIMEEN=1的同时修改TIMPOS。
#define CAN_TIMECFG_TIMEEN_BIT  BIT0 // [0] 时间戳使能 0 - 禁用 1 - 启用

/* CAN_ACFEN ID过滤器使能寄存器 */
#define CAN_ACFEN_AE_15_BIT BIT15 // [15] ACF_15使能（Acceptance Filter 15 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_14_BIT BIT14 // [14] ACF_14使能（Acceptance Filter 14 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_13_BIT BIT13 // [13] ACF_13使能（Acceptance Filter 13 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_12_BIT BIT12 // [12] ACF_12使能（Acceptance Filter 12 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_11_BIT BIT11 // [11] ACF_11使能（Acceptance Filter 11 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_10_BIT BIT10 // [10] ACF_10使能（Acceptance Filter 10 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_9_BIT  BIT9  // [9] ACF_9使能（Acceptance Filter 9 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_8_BIT  BIT8  // [8] ACF_8使能（Acceptance Filter 8 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_7_BIT  BIT7  // [7] ACF_7使能（Acceptance Filter 7 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_6_BIT  BIT6  // [6] ACF_6使能（Acceptance Filter 6 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_5_BIT  BIT5  // [5] ACF_5使能（Acceptance Filter 5 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_4_BIT  BIT4  // [4] ACF_4使能（Acceptance Filter 4 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_3_BIT  BIT3  // [3] ACF_3使能（Acceptance Filter 3 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_2_BIT  BIT2  // [2] ACF_2使能（Acceptance Filter 2 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_1_BIT  BIT1  // [1] ACF_1使能（Acceptance Filter 1 Enable） 1：使能 0：禁止
#define CAN_ACFEN_AE_0_BIT  BIT0  // [0] ACF_0使能（Acceptance Filter 0 Enable） 1：使能 0：禁止 Filter 0 默认开启

/* CAN_ACF ID过滤器寄存器 */
#define CAN_ACF_IDCMP_BIT        BIT30                                                       // [30] SELMASK=1时有效，ID AMR（MASK）选择作用范围 1：ID过滤器只接收标准帧或者扩展帧，由IDMASK进一步指定 0：ID过滤器接收标准帧和扩展帧两种格式
#define CAN_ACF_IDMASK_BIT       BIT29                                                       // [29] IDCMP位为1时，MASK选择哪种帧格式 1：ID过滤器仅接收扩展帧格式 0：ID过滤器仅接收标准帧格式
#define CAN_ACF_IDCODE_MASK_MAX  ((uint32_t)0x1FFFFFFF)                                      // CAN_ACF_IDCODE_MASK最大值
#define CAN_ACF_IDCODE_MASK_POS  0                                                           // CAN_ACF_IDCODE_MASK起始位
#define CAN_ACF_IDCODE_MASK_MASK (uint32_t)((uint32_t)0x1FFFFFFF << CAN_ACF_IDCODE_MASK_POS) // CAN_ACF_IDCODE_MASK位掩码
#define CAN_ACF_IDCODE_MASK(x)   (uint32_t)(((x) & 0x1FFFFFFF) << CAN_ACF_IDCODE_MASK_POS)   // [28:0] CAN_ACFCTRL.ACFADR选择具体的ID过滤器组 SELMASK=0，表示ID过滤器选择的是ID ACR SELMASK=1，表示ID过滤器选择的是ID AMR 标准帧格式时ID ACR/AMR的范围是Bit10-Bit0，扩展帧格式时的范围是Bit28-Bit0

/* CAN_TBSLOT TTCAN 发送缓冲区指针寄存器 */
#define CAN_TBSLOT_TBE_BIT    BIT7                                               // [7] 将PTB/STB消息槽设置为“空” 1 - 将TBPTR选择的消息标记为“空的” 0 - 无动作 一旦消息槽被标记为空且TSFF=0，TBE就会自动重置为0。如果消息正在被发送，则只要发送完成或在传输错误或仲裁丢失之后传输不再进行，TBE就会保持置位状态。 如果TBF和TBE同时被设置为1，则TBE优先。
#define CAN_TBSLOT_TBF_BIT    BIT6                                               // [6] 将TB消息槽设置为“已填充” 1 - TBPTR选择的消息应标记为 “填充” 0 - 无动作 一旦消息槽被标记为已满且TSFF=1，TBF就会自动重置为0。如果TBF 和TBE同时被设置为1，则TBE优先。
#define CAN_TBSLOT_TBPTR_MAX  ((uint32_t)0x3F)                                   // CAN_TBSLOT_TBPTR最大值
#define CAN_TBSLOT_TBPTR_POS  0                                                  // CAN_TBSLOT_TBPTR起始位
#define CAN_TBSLOT_TBPTR_MASK (uint32_t)((uint32_t)0x3F << CAN_TBSLOT_TBPTR_POS) // CAN_TBSLOT_TBPTR位掩码
#define CAN_TBSLOT_TBPTR(x)   (uint32_t)(((x) & 0x3F) << CAN_TBSLOT_TBPTR_POS)   // [5:0] 指向TB消息的指针。 0x00 - 指向PTB 其他 - 指向STB中的消息槽 TBPTR 指向的消息槽可以使用TBUF寄存器读取/写入。只有在 TSFF=0 时才能进行写访问。将TBF设置为1将所选消息槽标记为已填充，将TBE设置为1将所选消息槽标记为空。 TBSEL和TSNEXT在TTCAN模式下无意义。 TBPTR 仅限于PTB和STB消息槽。如果TBPTR太大并指向一个不可用的消息槽，则TBF和TBE将自动重置并且不执行任何操作。

/* CAN_TTCFG TTCAN 配置寄存器 */
#define CAN_TTCFG_WTIE_BIT     BIT7                                               // [7] 超时监测触发中断使能
#define CAN_TTCFG_WTIF_BIT     BIT6                                               // [6] 超时监测触发中断标志 如果循环计数达到由TT_WTRIG 定义的门限值并且WTIE=1，则WTIF置位
#define CAN_TTCFG_TEIF_BIT     BIT5                                               // [5] 触发错误中断标志 TEIF始终使能
#define CAN_TTCFG_TTIE_BIT     BIT4                                               // [4] 时间触发中断使能 如果设置TTIE=1，则如果循环计数等于触发时间TT_TRIG，则TTIF置位。
#define CAN_TTCFG_TTIF_BIT     BIT3                                               // [3] 时间触发中断标志 如果设置TTIE=1并且循环计数等于触发时间TT_TRIG，则TTIF置位。向TTIF写入1清零。写0无影响。 TTIF将只设置一次。如果TT_TRIG没有更新，则在下一个基本周期中不会再次设置TTIF。
#define CAN_TTCFG_T_PRESC_MAX  ((uint32_t)0x3)                                    // CAN_TTCFG_T_PRESC最大值
#define CAN_TTCFG_T_PRESC_POS  1                                                  // CAN_TTCFG_T_PRESC起始位
#define CAN_TTCFG_T_PRESC_MASK (uint32_t)((uint32_t)0x3 << CAN_TTCFG_T_PRESC_POS) // CAN_TTCFG_T_PRESC位掩码
#define CAN_TTCFG_T_PRESC(x)   (uint32_t)(((x) & 0x3) << CAN_TTCFG_T_PRESC_POS)   // [2:1] TTCAN 定时器预分频设置 00 - 1 01 - 2 10 - 4 11 - 8 TTCAN时基是由S_PRES、S_SEG_1和S_SEG_2定义的CAN bit时间。使用T_PRESC定义了额外的预分频因子1、2、4 或 8。 T_PRESC只能在TTEN=0时修改，但可以在修改T_PRESC的同时设置 TTEN=1。
#define CAN_TTCFG_TTEN_BIT     BIT0                                               // [0] TTCAN启用 1 - TTCAN启用，循环计数定时器开启计数 0 - 禁用

/* CAN_REF_MSG TTCAN参考帧寄存器 */
#define CAN_REF_MSG_REF_IDE_BIT BIT31                                                      // [31] 参考帧IDE位
#define CAN_REF_MSG_REF_ID_MAX  ((uint32_t)0x1FFFFFFF)                                     // CAN_REF_MSG_REF_ID最大值
#define CAN_REF_MSG_REF_ID_POS  0                                                          // CAN_REF_MSG_REF_ID起始位
#define CAN_REF_MSG_REF_ID_MASK (uint32_t)((uint32_t)0x1FFFFFFF << CAN_REF_MSG_REF_ID_POS) // CAN_REF_MSG_REF_ID位掩码
#define CAN_REF_MSG_REF_ID(x)   (uint32_t)(((x) & 0x1FFFFFFF) << CAN_REF_MSG_REF_ID_POS)   // [28:0] 参考帧标识符。如果REF_IDE是 1 - REF_ID(28:0) 有效（扩展 ID） 0 - REF_ID(10:0) 有效（标准 ID） REF_ID在TTCAN模式下用于检测参考帧。这适用于时间从站（接收）以及时间主站（传输）。如果检测到参考帧并且没有错误，则该帧的 Sync_Mark将成为Ref_Mark。 REF_ID(2:0)强制为0。 CAN控制器仅通过ID识别参考帧。有效载荷未经测试。附加说明：时间主机发送参考帧的方式和正常帧相同。 REF_ID用于检测参考帧的成功传输。

/* CAN_TRG_CFG TTCAN触发配置寄存器 */
#define CAN_TRG_CFG_TEW_MAX     ((uint32_t)0xF)                                      // CAN_TRG_CFG_TEW最大值
#define CAN_TRG_CFG_TEW_POS     12                                                   // CAN_TRG_CFG_TEW起始位
#define CAN_TRG_CFG_TEW_MASK    (uint32_t)((uint32_t)0xF << CAN_TRG_CFG_TEW_POS)     // CAN_TRG_CFG_TEW位掩码
#define CAN_TRG_CFG_TEW(x)      (uint32_t)(((x) & 0xF) << CAN_TRG_CFG_TEW_POS)       // [15:12] 发送使能窗口 对于单次发射触发，允许帧开始的循环时间最多有16个cycle。 TWE+1 定义了cycle数。见章节TTCAN Timin。TEW=0 将传输启用窗口缩短到1个cycle。
#define CAN_TRG_CFG_TTYPE_MAX   ((uint32_t)0x7)                                      // CAN_TRG_CFG_TTYPE最大值
#define CAN_TRG_CFG_TTYPE_POS   8                                                    // CAN_TRG_CFG_TTYPE起始位
#define CAN_TRG_CFG_TTYPE_MASK  (uint32_t)((uint32_t)0x7 << CAN_TRG_CFG_TTYPE_POS)   // CAN_TRG_CFG_TTYPE位掩码
#define CAN_TRG_CFG_TTYPE(x)    (uint32_t)(((x) & 0x7) << CAN_TRG_CFG_TTYPE_POS)     // [10:8] 触发类型 000 - 立即触发发送 001 - 定时触发 010 - 单次发射触发，针对独家时间窗口 011 - 传输开始触发，针对合并仲裁时间窗口 100 - 传输停止触发，针对合并仲裁时间窗口 其他- 无动作 触发时间由TT_TRIG定义。TTPTR选择TB中的消息。
#define CAN_TRG_CFG_TT_PTR_MAX  ((uint32_t)0x3F)                                     // CAN_TRG_CFG_TT_PTR最大值
#define CAN_TRG_CFG_TT_PTR_POS  0                                                    // CAN_TRG_CFG_TT_PTR起始位
#define CAN_TRG_CFG_TT_PTR_MASK (uint32_t)((uint32_t)0x3F << CAN_TRG_CFG_TT_PTR_POS) // CAN_TRG_CFG_TT_PTR位掩码
#define CAN_TRG_CFG_TT_PTR(x)   (uint32_t)(((x) & 0x3F) << CAN_TRG_CFG_TT_PTR_POS)   // [5:0] TB发送消息指针 如果TTPTR 太大并指向不可用的消息槽，则TEIF置位，并且在对 TT_TRIG进行写访问后无法产生新的触发。 如果TTPTR指向一个空槽，那么TEIF将在触发发送时被设置。

/* CAN_TT_TRIG TTCAN触发时刻寄存器 */
#define CAN_TT_TRIG_TT_TRIG_MAX  ((uint32_t)0xFFFF)                                      // CAN_TT_TRIG_TT_TRIG最大值
#define CAN_TT_TRIG_TT_TRIG_POS  0                                                       // CAN_TT_TRIG_TT_TRIG起始位
#define CAN_TT_TRIG_TT_TRIG_MASK (uint32_t)((uint32_t)0xFFFF << CAN_TT_TRIG_TT_TRIG_POS) // CAN_TT_TRIG_TT_TRIG位掩码
#define CAN_TT_TRIG_TT_TRIG(x)   (uint32_t)(((x) & 0xFFFF) << CAN_TT_TRIG_TT_TRIG_POS)   // [15:0] 触发时间 TT_TRIG定义了触发时间。对于发送触发，相应帧的SOF的最早传输点将是 TT_TRIG+1。

/* CAN_TT_WTRIG TTCAN超时寄存器 */
#define CAN_TT_WTRIG_TT_WTRIG_MAX  ((uint32_t)0xFFFF)                                        // CAN_TT_WTRIG_TT_WTRIG最大值
#define CAN_TT_WTRIG_TT_WTRIG_POS  0                                                         // CAN_TT_WTRIG_TT_WTRIG起始位
#define CAN_TT_WTRIG_TT_WTRIG_MASK (uint32_t)((uint32_t)0xFFFF << CAN_TT_WTRIG_TT_WTRIG_POS) // CAN_TT_WTRIG_TT_WTRIG位掩码
#define CAN_TT_WTRIG_TT_WTRIG(x)   (uint32_t)(((x) & 0xFFFF) << CAN_TT_WTRIG_TT_WTRIG_POS)   // [15:0] 超时触发时间 TT_WTRIG定义了超时触发周期。初始值是最大周期时间0xFFFF。

/* CAN_CIAWDAT0 CiA603时间戳低32位写入值寄存器 */
#define CAN_CIAWDAT0_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                     // CAN_CIAWDAT0_WDATA最大值
#define CAN_CIAWDAT0_WDATA_POS  0                                                          // CAN_CIAWDAT0_WDATA起始位
#define CAN_CIAWDAT0_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CAN_CIAWDAT0_WDATA_POS) // CAN_CIAWDAT0_WDATA位掩码
#define CAN_CIAWDAT0_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CAN_CIAWDAT0_WDATA_POS)   // [31:0] CiA603时间戳低32位写入值

/* CAN_CIAWDAT1 CiA603时间戳高32位写入值寄存器 */
#define CAN_CIAWDAT1_WDATA_MAX  ((uint32_t)0xFFFFFFFF)                                     // CAN_CIAWDAT1_WDATA最大值
#define CAN_CIAWDAT1_WDATA_POS  0                                                          // CAN_CIAWDAT1_WDATA起始位
#define CAN_CIAWDAT1_WDATA_MASK (uint32_t)((uint32_t)0xFFFFFFFF << CAN_CIAWDAT1_WDATA_POS) // CAN_CIAWDAT1_WDATA位掩码
#define CAN_CIAWDAT1_WDATA(x)   (uint32_t)(((x) & 0xFFFFFFFF) << CAN_CIAWDAT1_WDATA_POS)   // [31:0] CiA603时间戳高32位写入值

/* WWDG_CR窗口看门狗控制寄存器 */
#define WWDG_CR_WDG_EN_BIT BIT7                                        // [7] 窗口看门狗使能，1：使能；0：禁用。上电默认禁用。软件写1可使能看门狗，软件写0且同时向[15:8]写入0x3C时，可禁用看门狗。 禁用后看门狗不再产生复位，但仍可计数并产生超前中断
#define WWDG_CR_T_MAX      ((uint32_t)0x7F)                            // WWDG_CR_T最大值
#define WWDG_CR_T_POS      0                                           // WWDG_CR_T起始位
#define WWDG_CR_T_MASK     (uint32_t)((uint32_t)0x7F << WWDG_CR_T_POS) // WWDG_CR_T位掩码
#define WWDG_CR_T(x)       (uint32_t)(((x) & 0x7F) << WWDG_CR_T_POS)   // [6:0] 窗口看门狗计数器，使用看门狗内部的分频时钟进行递减计数，当计数值小于0x40(T[6]为0)时产生复位。为避免写入T[6]为0立即产生复位， T[6]在写入时强制置1，软件只能写入T[5:0]。

/* WWDG_CFG窗口看门狗配置寄存器 */
#define WWDG_CFG_WDGTB_MAX  ((uint32_t)0x3)                                 // WWDG_CFG_WDGTB最大值
#define WWDG_CFG_WDGTB_POS  8                                               // WWDG_CFG_WDGTB起始位
#define WWDG_CFG_WDGTB_MASK (uint32_t)((uint32_t)0x3 << WWDG_CFG_WDGTB_POS) // WWDG_CFG_WDGTB位掩码
#define WWDG_CFG_WDGTB(x)   (uint32_t)(((x) & 0x3) << WWDG_CFG_WDGTB_POS)   // [9:8] 窗口看门狗时钟预分频系数 2’h0: 系统主时钟/32768/1 2’h1: 系统主时钟/32768/2 2’h2: 系统主时钟/32768/4 2’h3: 系统主时钟/32768/8
#define WWDG_CFG_EWI_BIT    BIT7                                            // [7] 超前中断使能，1：使能；0：禁用。上电默认禁用。软件写1可使能中断，软件写0无效，此位一旦置1只能通过硬件外部复位或上电复位清零。看门狗计数至0x40时产生超前中断。
#define WWDG_CFG_W_MAX      ((uint32_t)0x7F)                                // WWDG_CFG_W最大值
#define WWDG_CFG_W_POS      0                                               // WWDG_CFG_W起始位
#define WWDG_CFG_W_MASK     (uint32_t)((uint32_t)0x7F << WWDG_CFG_W_POS)    // WWDG_CFG_W位掩码
#define WWDG_CFG_W(x)       (uint32_t)(((x) & 0x7F) << WWDG_CFG_W_POS)      // [6:0] 窗口看门狗喂狗窗口，当T\>W时喂狗也会产生复位，即合法的复位窗口为W\>=T\>0x40

/* WWDG_IF窗口看门狗中断标志寄存器 */
#define WWDG_IF_EWIF_BIT BIT0 // [0] 窗口看门狗超前中断标志，当计数器计数至0x40时EWIF置位为1，写1清零，写0无效果。即使看门狗不使能，EWIF位仍可以置位，因为看门狗计数器T[6:0]在看门狗禁用时仍在计数。EWIF和EWI均为1时，看门狗才会向CPU提起中断请求。

/* IWDG_PSW 独立看门狗密码寄存器 */
#define IWDG_PSW_PSW_MAX  ((uint32_t)0xFFFF)                               // IWDG_PSW_PSW最大值
#define IWDG_PSW_PSW_POS  0                                                // IWDG_PSW_PSW起始位
#define IWDG_PSW_PSW_MASK (uint32_t)((uint32_t)0xFFFF << IWDG_PSW_PSW_POS) // IWDG_PSW_PSW位掩码
#define IWDG_PSW_PSW(x)   (uint32_t)(((x) & 0xFFFF) << IWDG_PSW_PSW_POS)   // [15:0] 写入0xA6B4，才能对IWDG_CLR/ IWDG_RTH等进行写操作，对IWDG_CLR或IWDG_RTH的写操作会将密码清空，因此每次对看门狗进行写操作前都需要写入密码

/* IWDG_CFG 独立看门狗配置寄存器 */
#define IWDG_CFG_DWK_EN_BIT BIT4 // [4] 深度休眠定时唤醒使能，0：禁用，1：使能
#define IWDG_CFG_WDG_EN_BIT BIT0 // [0] 独立看门狗使能，0：禁用，1：使能。默认使能，写1置位，写0同时向[15:8]写入0x3C可清零。当看门狗被禁用时，不再产生复位信号，但仍可计数并产生定时唤醒信号

/* IWDG_WTH 独立看门狗定时唤醒门限寄存器 */
#define IWDG_WTH_WTH_MAX  ((uint32_t)0x1FF)                               // IWDG_WTH_WTH最大值
#define IWDG_WTH_WTH_POS  12                                              // IWDG_WTH_WTH起始位
#define IWDG_WTH_WTH_MASK (uint32_t)((uint32_t)0x1FF << IWDG_WTH_WTH_POS) // IWDG_WTH_WTH位掩码
#define IWDG_WTH_WTH(x)   (uint32_t)(((x) & 0x1FF) << IWDG_WTH_WTH_POS)   // [20:12] 看门狗定时唤醒门限值，看门狗使用32kHz LRC时钟从IWDG_RTH开始计数，递减计数至IWDG_WTH产生唤醒信号。

/* IWDG_RTH 独立看门狗超时复位门限寄存器 */
#define IWDG_RTH_RTH_MAX  ((uint32_t)0x1FF)                               // IWDG_RTH_RTH最大值
#define IWDG_RTH_RTH_POS  12                                              // IWDG_RTH_RTH起始位
#define IWDG_RTH_RTH_MASK (uint32_t)((uint32_t)0x1FF << IWDG_RTH_RTH_POS) // IWDG_RTH_RTH位掩码
#define IWDG_RTH_RTH(x)   (uint32_t)(((x) & 0x1FF) << IWDG_RTH_RTH_POS)   // [20:12] 看门狗超时复位门限值，也是重新装载值。看门狗使用32kHz LRC时钟从IWDG_RTH开始计数，计数至0x7产生复位。向该寄存器写入0x0，会被硬件强制改写为0x1000。先向IWDG_PSW写入正确密码才能改写IWDG_RTH寄存器。改写IWDG_RTH同样具有重置看门狗计数器的作用，看门狗会从新的IWDG_RTH开始计数。

/* IWDG_CNT 独立看门狗当前计数值寄存器 */
#define IWDG_CNT_CNT_MAX  ((uint32_t)0x1FFFFF)                               // IWDG_CNT_CNT最大值
#define IWDG_CNT_CNT_POS  0                                                  // IWDG_CNT_CNT起始位
#define IWDG_CNT_CNT_MASK (uint32_t)((uint32_t)0x1FFFFF << IWDG_CNT_CNT_POS) // IWDG_CNT_CNT位掩码
#define IWDG_CNT_CNT(x)   (uint32_t)(((x) & 0x1FFFFF) << IWDG_CNT_CNT_POS)   // [20:0] 看门狗当前计数值，此数值≤IWDG_RTH

/* AON_PWR_CFG 功耗管理配置寄存器 */
#define AON_PWR_CFG_IOWK_FLT_BIT BIT1 // [1] IO唤醒信号滤波使能，默认使能
#define AON_PWR_CFG_PG_BIT       BIT0 // [0] 停机模式配置位

/* AON_EVT_RCD 事件记录寄存器 */
#define AON_EVT_RCD_STANDBY_BIT      BIT14 // [14] 停机(掉电)模式记录，高表示发生过
#define AON_EVT_RCD_DEEPSLEEP_BIT    BIT13 // [13] 深度休眠记录，高表示发生过
#define AON_EVT_RCD_SLEEP_BIT        BIT12 // [12] 休眠记录，高表示发生过
#define AON_EVT_RCD_IWDG_WK_BIT      BIT9  // [9] IWDG定时唤醒记录，高表示休眠被IWDG定时唤醒，包括Deep Sleep以及Standby模式的唤醒
#define AON_EVT_RCD_IO_WK_BIT        BIT8  // [8] IO唤醒记录，高表示休眠被IO唤醒，包括Deep Sleep以及Standby模式的唤醒
#define AON_EVT_RCD_CPOR_RST_BIT     BIT5  // [5] 芯片停机记录，高表示芯片进入过停机模式
#define AON_EVT_RCD_WWDG_RST_BIT     BIT4  // [4] 窗口看门狗复位发生记录，高表示发生过
#define AON_EVT_RCD_IWDG_RST_BIT     BIT3  // [3] 独立看门狗复位发生记录，高表示发生过
#define AON_EVT_RCD_KEY_RST_RCD_BIT  BIT2  // [2] 按键复位发生记录，高表示发生过
#define AON_EVT_RCD_HPOR_RST_RCD_BIT BIT1  // [1] HPOR复位发生记录，高表示发生过
#define AON_EVT_RCD_LPOR_RST_RCD_BIT BIT0  // [0] LPOR复位发生记录，高表示发生过

/* AON_IO_WAKE_POL IO唤醒极性寄存器 */
#define AON_IO_WAKE_POL_WK_POL_BIT BIT0 // [0] IO外部唤醒触发电平选择。 1：高电平，唤醒IO开启下拉 0：低电平，唤醒IO开启上拉

/* AON_IO_WAKE_EN IO唤醒使能寄存器 */
#define AON_IO_WAKE_EN_P3_2_EN_BIT  BIT7 // [7] P3[2]外部唤醒触发使能
#define AON_IO_WAKE_EN_P2_14_EN_BIT BIT6 // [6] P2[14]外部唤醒触发使能
#define AON_IO_WAKE_EN_P1_11_EN_BIT BIT5 // [5] P1[11]外部唤醒触发使能
#define AON_IO_WAKE_EN_P0_13_EN_BIT BIT4 // [4] P0[13]外部唤醒触发使能
#define AON_IO_WAKE_EN_P0_5_EN_BIT  BIT3 // [3] P0[5]外部唤醒触发使能
#define AON_IO_WAKE_EN_P0_4_EN_BIT  BIT2 // [2] P0[4]外部唤醒触发使能
#define AON_IO_WAKE_EN_P0_3_EN_BIT  BIT1 // [1] P0[3]外部唤醒触发使能
#define AON_IO_WAKE_EN_P0_2_EN_BIT  BIT0 // [0] P0[2]外部唤醒触发使能
#endif
