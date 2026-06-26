/**
 * @file
 * @defgroup aon
 * @brief        后背存储器库函数
 * @author       YangZJ
 * @date         2023-01-02
 * @{
 */
#include "lks32mc45x_aon.h"
#include "lks32mc45x.h"

/**
 * @brief    向后背存储器写入数据数据
 * @param len : 需要写入的数据长度，单位字，最大32
 * @param p   : 需要写入数据的地址
 * @par 更新记录  V1.0  2022/05/12  YangZJ  创建
 */
void AON_SaveData(u8 len, u32 *p)
{
    u32 i;
    len = (len > 32) ? 32 : len;
    for (i = 0; i < len; i++)
    {
        AON->BRAM[i] = p[i];
    }
    __NOP();
}
/**
 * @brief    读取后备存储器数据
 * @param len : 需要读取的数据长度，单位字，最大32
 * @param p   : 需要读取数据的地址
 * @par 更新记录  V1.0  2022/05/12  YangZJ  创建
 */
void AON_RadeData(u8 len, u32 *p)
{
    u32 i;
    len = (len > 32) ? 32 : len;
    for (i = 0; i < len; i++)
    {
        p[i] = AON->BRAM[i];
    }
    __NOP();
}
/**
 * @brief    读取掉电记录
 * @param PMU_RCD_x 需要读取的复位记录
 * @par 更新记录  V1.0  2022/05/12  YangZJ  创建
 */
u8 AON_ReadEVTRCD(u16 PMU_RCD_x)
{
    if (AON->EVT_RCD & PMU_RCD_x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/**
 * @brief    读取掉电记录
 * @param PMU_RCD_x 需要读取的复位记录
 * @par 更新记录  V1.0  2022/05/12  YangZJ  创建
 */
void AON_ClearEVTRCD(void)
{
    u32 i        = 0;
    AON->EVT_RCD = 0xca40;
    while (AON->EVT_RCD != 0)
    {
        i++;
        if (i > 0x1ffff)
        {
            return;
        }
    }
}
/**
 * @brief    设置IO唤醒极性以及唤醒IO
 * @param WK_Pin    唤醒IO
 * @param Polarity  唤醒极性 1：高电平唤醒 0：低电平唤醒
 * @par 更新记录  V1.0  2022/05/12  YangZJ  创建
 */
void AON_SetGpioWakePolarity(u16 AON_Wake_Pinx, u16 AON_Polarity_x)
{
    AON->IO_WAKE_EN  = AON_Wake_Pinx;
    AON->IO_WAKE_POL = (AON_Polarity_x != 0);
}
/**
 * @brief   进入停机模式
 * @warning 需要配置唤醒源（io唤醒或定时唤醒），以及定义WAKEUP_IRQHandler函数
 * @note
 * 停机模式可使芯片功耗降至最低。
 * 停机模式在深度休眠模式的基础上，进一步将大部分数字电路断电。
 * 但LSI时钟、功耗管理模块PMU、复位管理模块RMU、独立看门狗模块IWDG仍正常工作，
 * 后备存储器BRAM在进入停机模式后不断电，可以提供128Bytes大小的存储空间用于保持停机模式前的系统关键数据。
 * 此外，IO唤醒使能极性选择，系统复位、休眠、唤醒事件记录寄存器不断电。
 * 停机模式下所有IO处于高阻态，IO唤醒信号从PAD直接送入芯片内部唤醒逻辑。
 */
void AON_StandbyMode(void)
{
    __disable_irq();
    SYS_WR_PROTECT = 0x7a83; // 开启寄存器写使能
    AON_PWR_CFG    = BIT0;   // 使能掉电
    SYS_CLK_CFG    = 0x0;    // 切换到HRC时钟
    SYS_AFE_REG9   = 0;
    SYS_AFE_REGA   = 0x3;
    SYS_WR_PROTECT = 0x0;

    NVIC->ICER[0] = 0xFFFFFFFF;
    NVIC->ICER[1] = 0xFFFFFFFF;

    IWDG_PSW = 0xA6B4;
    IWDG_CLR = 0x798D;
    SCB->SCR |= (1UL << 2);
    NVIC_EnableIRQ(WAKEUP_IRQn);
    __enable_irq();
    __WFI(); // 芯片休眠
             // 如果执行wfi时，唤醒的gpio处于唤醒状态，则芯片在休眠的同时会被唤醒，此时先执行WAKEUP_IRQHandler，随后继续往下执行
    NVIC_SystemReset();
}
/**
 * @brief   进入深度休眠模式
 * @warning 需要配置唤醒源（io唤醒或定时唤醒），以及定义WAKEUP_IRQHandler函数
 * @note
 * 深度休眠模式关闭所有系统高速时钟，包括PLL/HSI/HSE。32kHz RC时钟LSI仍正常工作。
 * 同时LDO会进入低功耗模式，BGP模块被关闭。
 * 相比休眠模式，深度休眠模式可以进一步降低功耗。
 * 深度休眠模式对电路供电没有影响，所有寄存器状态和存储器数据在深度休眠模式中保持正常供电。
 * 如果有外设需要使用高速时钟完成正在进行中的操作，例如flash的擦除写入，则深度休眠会推迟等待操作完成后再进入。
 */
void AON_DeepSleepMode(void)
{
    uint32_t cnt;
    uint32_t afe_reg9;
    uint32_t afe_rega;
    uint32_t clk_cfg;

    __disable_irq();
    SYS_WR_PROTECT = 0x7a83; /*开启寄存器写使能*/
    afe_reg9       = SYS_AFE_REG9;
    afe_rega       = SYS_AFE_REGA;
    clk_cfg        = SYS_CLK_CFG;
    SYS_CLK_CFG    = 0x0; /* 切换到HRC时钟*/
    SYS_AFE_REG9   = 0;
    SYS_AFE_REGA   = 0x3;
    SYS_WR_PROTECT = 0x0;

    NVIC->ICER[0] = 0xFFFFFFFF;
    NVIC->ICER[1] = 0xFFFFFFFF;

    IWDG_PSW = 0xA6B4;
    IWDG_CLR = 0x798D;
    SCB->SCR |= (1UL << 2);
    NVIC_EnableIRQ(WAKEUP_IRQn);
    __enable_irq();
    __WFI(); /*PC指针停止运行，等待中断*/
    NVIC_DisableIRQ(WAKEUP_IRQn);
    __disable_irq();

    SYS_WR_PROTECT = 0x7a83;
    SYS_AFE_REG9   = afe_reg9;
    SYS_AFE_REGA   = afe_rega;
    for (cnt = 0; cnt < 500; cnt++)
    {
        __NOP();
    }
    SYS_CLK_CFG    = clk_cfg;
    SYS_WR_PROTECT = 0x0;
}
/*! @} */
