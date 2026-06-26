#include "../include/hal_lksmcu_dac.h"
#include "../include/hal_lksmcu_trim.h"
#include "../hal_lks32mc45x.h"
#include "lks32mc45x_user_manual.h"
#include "../include/hal_lksmcu_reg.h"
#include "../include/hal_lks32mc45x_reg.h"
// 模块复位
void HAL_DAC_Reset(HAL_DAC_x dac_x)
{
    HAL_DAC_Disable(dac_x);
}
// 模块打开
void HAL_DAC_Enable(HAL_DAC_x dac_x)
{
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    switch (dac_x)
    {
        case HAL_DAC_0:
            HAL_REG_SET(SYS_AFE_REGA, BIT2);
            break;
        case HAL_DAC_1:
            HAL_REG_SET(SYS_AFE_REGA, BIT3);
            break;
        default:
            break;
    }
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}
// 模块关闭
void HAL_DAC_Disable(HAL_DAC_x dac_x)
{
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    switch (dac_x)
    {
        case HAL_DAC_0:
            HAL_REG_RESET(SYS_AFE_REGA, BIT2);
            break;
        case HAL_DAC_1:
            HAL_REG_RESET(SYS_AFE_REGA, BIT3);
            break;
        default:
            break;
    }
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}

void HAL_DAC_SetOutVal(HAL_DAC_x dac_x, uint16_t val)
{
    switch (dac_x)
    {
        case HAL_DAC_0:
            HAL_REG_WRITE(SYS_AFE_DAC0, val);
            break;
        case HAL_DAC_1:
            HAL_REG_WRITE(SYS_AFE_DAC1, val);
            break;
        default:
            break;
    }
}
void HAL_DAC_SetOutVoltagemV(HAL_DAC_x dac_x, uint16_t vol_mV)
{
    int32_t val;
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    switch (dac_x)
    {
        case HAL_DAC_0:
            if (vol_mV < 1000)
            {
                val = vol_mV;
                val = (val * 13981) >> 12;
                if (val > 4095)
                {
                    val = 4095;
                }
                if (val < 0)
                {
                    val = 0;
                }

                HAL_REG_WRITE(SYS_AFE_DAC0_AMC, HAL_TRIM_Read(0x00000864));
                HAL_REG_WRITE(SYS_AFE_DAC0_DC, HAL_TRIM_Read(0x0000086C));
                HAL_REG_SET(SYS_AFE_REG4, BIT0);
                HAL_REG_WRITE(SYS_AFE_DAC0, val);
            }
            else
            {
                val = vol_mV;
                val = (val * 22370) >> 14;
                if (val > 4095)
                {
                    val = 4095;
                }
                if (val < 0)
                {
                    val = 0;
                }
                HAL_REG_WRITE(SYS_AFE_DAC0_AMC, HAL_TRIM_Read(0x00000860));
                HAL_REG_WRITE(SYS_AFE_DAC0_DC, HAL_TRIM_Read(0x00000868));
                HAL_REG_RESET(SYS_AFE_REG4, BIT0);
                HAL_REG_WRITE(SYS_AFE_DAC0, val);
            }
            break;
        case HAL_DAC_1:
            if (vol_mV < 1000)
            {
                val = vol_mV;
                val = (val * 13981) >> 12;
                if (val > 4095)
                {
                    val = 4095;
                }
                if (val < 0)
                {
                    val = 0;
                }
                HAL_REG_SET(SYS_AFE_REG4, BIT2);
                HAL_REG_WRITE(SYS_AFE_DAC1, val);
            }
            else
            {
                val = vol_mV;
                val = (val * 22370) >> 14;
                if (val > 4095)
                {
                    val = 4095;
                }
                if (val < 0)
                {
                    val = 0;
                }
                HAL_REG_RESET(SYS_AFE_REG4, BIT2);
                HAL_REG_WRITE(SYS_AFE_DAC1, val);
            }
            break;
        default:
            break;
    }
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}

void HAL_DAC_Out2GpioEnable(HAL_DAC_x dac_x)
{
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    switch (dac_x)
    {
        case HAL_DAC_0:
            HAL_REG_SET(SYS_AFE_REG4, BIT4);
            break;
        case HAL_DAC_1:
            HAL_REG_SET(SYS_AFE_REG4, BIT5);
            break;
        default:
            break;
    }
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}
void HAL_DAC_Out2GpioDisable(HAL_DAC_x dac_x)
{
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    switch (dac_x)
    {
        case HAL_DAC_0:
            HAL_REG_RESET(SYS_AFE_REG4, BIT4);
            break;
        case HAL_DAC_1:
            HAL_REG_RESET(SYS_AFE_REG4, BIT5);
            break;
        default:
            break;
    }
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}

/**
 * @brief 设置DAC输出到GPIO
 * @param dac DAC模块
 * @param px GPIO
 */
void HAL_DAC_SetGpioOut(HAL_DAC_x dac, HAL_GPIO_Px px)
{
    (void)dac;

    HAL_GPIO_SetAf(px, HAL_GPIO_AF_DAC);
    HAL_GPIO_SetMode(px, HAL_GPIO_MODE_AFE);
}
