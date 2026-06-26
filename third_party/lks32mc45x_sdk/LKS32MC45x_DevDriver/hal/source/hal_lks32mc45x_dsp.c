#include "../include/hal_lksmcu_dsp.h"
#include "../hal_lks32mc45x.h"
#include "lks32mc45x_user_manual.h"
#include "../include/hal_lksmcu_reg.h"
#include "../include/hal_lks32mc45x_reg.h"
void HAL_DSP_Reset(HAL_DSP_x dsp_x)
{
    (void)dsp_x;
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    HAL_REG_SET(SYS_SFT_RST, SYS_SFT_RST_CORDIC_SFT_RST_BIT);
    HAL_REG_RESET(SYS_SFT_RST, SYS_SFT_RST_CORDIC_SFT_RST_BIT);
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}
void HAL_DSP_Enable(HAL_DSP_x dsp_x)
{
    (void)dsp_x;
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    HAL_REG_SET(SYS_CLK_FEN, SYS_CLK_FEN_CORDIC_CLK_EN_BIT);
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}
void HAL_DSP_Disable(HAL_DSP_x dsp_x)
{
    (void)dsp_x;
    // 系统寄存器解锁
    HAL_REG_SYS_UNLOCK();
    HAL_REG_RESET(SYS_CLK_FEN, SYS_CLK_FEN_CORDIC_CLK_EN_BIT);
    // 系统寄存器上锁
    HAL_REG_SYS_LOCK();
}
int16_t HAL_DSP_Sin(HAL_DSP_x dsp_x, int16_t angle)
{
    (void)dsp_x;
    DSP_SC    = 0x6;
    DSP_THETA = angle;
    return DSP_SIN;
}
int16_t HAL_DSP_Cos(HAL_DSP_x dsp_x, int16_t angle)
{
    (void)dsp_x;
    DSP_SC    = 0x6;
    DSP_THETA = angle;
    return DSP_COS;
}
void HAL_DSP_SinCos(HAL_DSP_x dsp_x, int16_t angle, int16_t *sin, int16_t *cos)
{
    (void)dsp_x;
    DSP_SC    = 0x6;
    DSP_THETA = angle;
    *sin      = DSP_SIN;
    *cos      = DSP_COS;
}
#include "math.h"
uint16_t HAL_DSP_Sqrt(HAL_DSP_x dsp_x, uint32_t x)
{
    (void)dsp_x;
    return (uint16_t)sqrtf((float)x);
}
int32_t HAL_DSP_Div(HAL_DSP_x dsp_x, int32_t a, int32_t b)
{
    (void)dsp_x;
    return a / b;
}
