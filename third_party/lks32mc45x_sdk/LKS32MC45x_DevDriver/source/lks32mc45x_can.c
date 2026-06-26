/**
 * @file
 * @defgroup can
 * @brief        CAN库函数
 * @author       YangZJ
 * @date         2023-01-02
 * @{
 */
#include "lks32mc45x_can.h"
#include "lks32mc45x_sys.h"
#include "string.h"

CANRxMsg g_rxMsg = {
    0,
    0,
    0,
    0,
    0,
    0,

    0,
    {0},
};

static bool GetBaudParam(u32 baud, u8 *presc, u8 *sjw, u8 *seg2, u8 *seg1);
static void CAN_Write_TBUF(u32 id, u8 ide, u8 rtr, u8 fdf, u8 brs, u8 *msg, u8 len);

static void Set_CFG_STAT(u32 bitValue);
static void Reset_CFG_STAT(u32 bitValue);

static void Delay(u32 cnt);

/**
 * @brief    CAN初始化函数,采用2.0B/FD协议
 * 输入参数: CAN_InitTypeDef*: 初始化参数
 * @par 更新记录  V1.0  2024/07/03  YangZJ  创建
 */
void CAN_Init(CAN_InitTypeDef *this)
{
    u8 s_presc, s_sjw, s_seg2, s_seg1;
    u8 f_presc, f_sjw, f_seg2, f_seg1;

    SYS_WR_PROTECT = 0x7a83; // 关闭写保护

    SYS_SFT_RST |= BIT29;  // 复位CAN
    SYS_SFT_RST &= ~BIT29; // 释放CAN复位

    SYS_CLK_FEN |= BIT29; // 使能CAN时钟

    CAN_CFG_STAT |= BIT7; // CAN复位模式
    CAN_ACFEN = 0x00;     // 关闭ID滤波功能

    if (this->SBaud > 0 && GetBaudParam(this->SBaud, &s_presc, &s_sjw, &s_seg2, &s_seg1))
    {
        CAN_SBAUD = (s_presc << 24) | (s_sjw << 16) | (s_seg2 << 8) | s_seg1; // 慢速波特率设置
    }

    if (this->FBaud > 0 && GetBaudParam(this->FBaud, &f_presc, &f_sjw, &f_seg2, &f_seg1))
    {
        CAN_FBAUD = (f_presc << 24) | (f_sjw << 16) | (f_seg2 << 8) | f_seg1; // 快速波特率设置
    }

    CAN_TDC = this->SSPoff & 0x7F;
    if (this->TDCEn)
    {
        CAN_TDC |= BIT7;
    }

    CAN_CFG_STAT &= ~BIT7; // 正常输出模式
    Delay(100);
    CAN_TCMD   = 0x00;
    CAN_RTIE   = this->IE; // 默认开启 错误中断使能+接收中断使能
    CAN_ERRINT = this->ERRINT_IE;

    SYS_WR_PROTECT = 0x0; // 打开写保护
}

/**
 * @brief    CAN配置结构体初始化，并设置默认参数
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
void CAN_StructInit(CAN_InitTypeDef *this)
{
    this->SBaud  = 500;
    this->FBaud  = 0;
    this->TDCEn  = 0;
    this->SSPoff = 0;
    this->IE     = CAN_RTIE_EIE | CAN_RTIE_RIE;
}

/*******************************************************************************
函数名称: void CAN_Initl(u8 BTR3,u8 BTR2,u8 BTR1,u8 BTR0)
功能描述: CAN初始化函数,采用2.0B协议
操作的表:
波特率  : 参考GetBaudParam()函数注释
输入参数: presc  S_PRESC ：TQ 预分频率设定值
          sjw    S_SJW ： 再同步补偿宽度时间设定
          seg2   S_SEG_2：段时间段 2 时间单元设定
          seg1   S_SEG_1: 段时间段 1 时间单元设定
输出参数: 无
返回值:   无
其它说明:
修改日期     版本号     修改人    修改内容
-----------------------------------------------------------------------------
2023/02/13   V1.0     HuangMG     创建
*******************************************************************************/
/**
 * @brief    CAN初始化函数,采用2.0B/FD协议
 * @par 更新记录  V1.0  2023/02/13  HuangMG  创建
 */
void CAN_Initl(u8 presc, u8 sjw, u8 seg2, u8 seg1)
{
    SYS_WR_PROTECT = 0x7a83; // 关闭写保护

    SYS_SFT_RST |= BIT29;  // 复位CAN
    SYS_SFT_RST &= ~BIT29; // 释放CAN复位

    SYS_CLK_FEN |= BIT29; // 使能CAN时钟

    CAN_CFG_STAT |= BIT7; // CAN复位模式

    CAN_ACFEN = 0x00;                                             // 关闭ID滤波功能
    CAN_SBAUD = seg1 | (seg2 << 8) | (sjw << 16) | (presc << 24); // 波特率设置
    CAN_CFG_STAT &= ~BIT7;                                        // 正常输出模式
    Delay(100);
    CAN_TCMD = 0x00;
    CAN_RTIE |= (BIT1 | BIT7); // 默认开启 错误中断使能+接收中断使能

    SYS_WR_PROTECT = 0x0; // 打开写保护
}

CanSendRet CAN_Send(CANTxMsg *tx_msg)
{
    u16 i = 0;

    if (CAN->CFG_STAT & BIT7)
    {
        return CanSend_Reset;
    }

    if (CAN->CFG_STAT & BIT0)
    {
        return CanSend_Busoff;
    }

    if (tx_msg->fdf == 1)
    {
        if (tx_msg->len > 64)
        {
            return CanSend_DataTooLong;
        }
    }
    else
    {
        if (tx_msg->len > 8)
        {
            return CanSend_DataTooLong;
        }
    }

    if (tx_msg->tbsel == TBSel_PTB)
    {
        // PTB发送
        if (CAN->CFG_STAT & BIT1) // 本设备正在发送CAN帧
        {
            return CanSend_NotIdle; // 发送失败
        }

        CAN_TCMD &= ~BIT7; // PTB发送。CAN_TCMD.TBSEL，0-PTB 1-STB
        CAN_Write_TBUF(tx_msg->id, tx_msg->ide, tx_msg->rtr, tx_msg->fdf, tx_msg->brs, tx_msg->buf, tx_msg->len);
        CAN_TCMD |= BIT4; // CAN 发送传输请求,触发PTB发送
        while (CAN_TCMD & BIT4)
        {
            if ((i++) >= 0x0fff)
            {
                return CanSend_Timeout; // 发送失败
            }
        }
        return CanSend_Succ; // 发送完成
    }
    else
    {
        // STB发送
        if ((CAN->TCTRL & 0x03) == 0x03)
        {
            return CanSend_STBFull; // 发送失败，STB满
        }

        CAN->TCMD |= BIT7; // STB发送。CAN_TCMD.TBSEL，0-PTB 1-STB
        CAN_Write_TBUF(tx_msg->id, tx_msg->ide, tx_msg->rtr, tx_msg->fdf, tx_msg->brs, tx_msg->buf, tx_msg->len);
        CAN->TCTRL |= BIT6; // 置位TSNEXT，更新STB slot位置

        return CanSend_Succ; // STB添加成功即返回，还需调用CAN_Send_Trig触发发送
    }
}

/**
 * @brief    CANFD数据发送函数，采用CAN-FD协议，PTB发送
 * 输入参数: id: 发送id ide: 标准/扩展帧 rtr：远程帧/数据帧 fdf:CAN2.0/CANFD brs:切换波特率 *msg: 发送的数据  len:发送字节长度
 * 输出参数: 无
 * 返回值:   0：发送成功 !0：发送失败
 * 其它说明: id:标准ID(11位)/扩展ID(11位+18位)
 *           ide:0,标准帧;1,扩展帧
 *           rtr:0,数据帧;1,遥控帧
 *           fdf:0,CAN2.0;1,CANFD
 *           brs:0,不切换波特率;1,切换波特率
 *           len:要发送的数据长度，CAN2.0最大8字节，CANFD最大64字节
 * @par 更新记录  V1.0  2023/02/13  HuangMG  创建
 */
CanSendRet CAN_Send_Msg(u32 id, u8 ide, u8 rtr, u8 fdf, u8 brs, u8 *msg, u8 len)
{
    CANTxMsg tx_msg;
    tx_msg.id  = id;
    tx_msg.ide = ide;
    tx_msg.rtr = rtr;
    tx_msg.fdf = fdf;
    tx_msg.brs = brs;
    tx_msg.buf = msg;
    tx_msg.len = len;

    tx_msg.tbsel = TBSel_PTB;

    return CAN_Send(&tx_msg);
}

/**
 * @brief    CANFD数据发送函数，采用CAN-FD协议，STB发送。默认STB为FIFO模式。
 * 输入参数: id:发送id ide: 标准/扩展帧 rtr:远程帧/数据帧 fdf:CAN2.0/CANFD brs:切换波特率 *msg:发送的数据  len:发送字节长度
 * 输出参数: 无
 * 返回值:   0：发送成功 !0：发送失败
 * 其它说明: id:标准ID(11位)/扩展ID(11位+18位)
 *           ide:0,标准帧;1,扩展帧
 *           rtr:0,数据帧;1,遥控帧
 *           fdf:0,CAN2.0;1,CANFD
 *           brs:0,不切换波特率;1,切换波特率
 *           option:0,本次不发送;1,发送一帧;2,发送所有帧
 * @par 更新记录  V1.0  2023/02/13  HuangMG  创建
 */
CanSendRet CAN_Send_Trig(STBTransOption stb_trans)
{
    u32 i = 0;

    if (stb_trans == STB_TransAll)
    {
        CAN->TCMD |= BIT1;       // 触发所有STB发送
        while (CAN->TCMD & BIT1) // 最近一次是否传输完成
        {
            if ((i++) >= 0x0fff)
            {
                return CanSend_Timeout; // 发送失败
            }
        }
    }
    else if (stb_trans == STB_TransOne)
    {
        CAN->TCMD |= BIT2;       // 触发一帧STB发送
        while (CAN->TCMD & BIT2) // 最近一次是否传输完成
        {
            if ((i++) >= 0x0fff)
            {
                return CanSend_Timeout; // 发送失败
            }
        }
    }
    else
    {
        return CanSend_Succ; // 不需要发送，返回成功
    }

    return CanSend_Succ; // 发送完成
}

/*
 * 取消发送
 */
void CAN_Send_Cancel(TBSelOption tbsel)
{
    if (tbsel == TBSel_PTB)
    {
        CAN->TCMD |= BIT3;
    }
    else if (tbsel == TBSel_STB)
    {
        CAN->TCMD |= BIT0;
    }
}

/**
 * @brief    CAN接收数据
 * 输入参数: *rx_msg: 接收数据存储对象
 * 返回值:   CanRecvRet
 * @par 更新记录
 */
CanRecvRet CAN_Recv(CANRxMsg *rx_msg)
{
    u8 reg_inf;
    u8 dlc = 0;
    u16 rbufx;
    u8 x;

    if ((CAN_RCTRL & 0x03) > 0) /*Rx Buffer存有一帧或多帧数据，可以通过 RFIFO 寄存器读取*/
    {
        reg_inf = CAN_RBUF_01;

        // read ide,id
        if (reg_inf & BIT7) /*扩展帧*/
        {
            rx_msg->ide = 1;
            rx_msg->id  = CAN_RBUF_00 & 0x1FFFFFFF;
        }
        else /*标准帧*/
        {
            rx_msg->ide = 0;
            rx_msg->id  = CAN_RBUF_00 & 0x7ff;
        }

        // read rtr
        if (reg_inf & BIT6)
        {
            rx_msg->rtr = 1;
        }
        else
        {
            rx_msg->rtr = 0;
        }

        // read fdf,len
        dlc = reg_inf & 0x0f;
        if (reg_inf & BIT5) /*CANFD*/
        {
            rx_msg->fdf = 1;
            if (dlc <= 8)
                rx_msg->len = dlc;
            else if (dlc == 9)
                rx_msg->len = 12;
            else if (dlc == 10)
                rx_msg->len = 16;
            else if (dlc == 11)
                rx_msg->len = 20;
            else if (dlc == 12)
                rx_msg->len = 24;
            else if (dlc == 13)
                rx_msg->len = 32;
            else if (dlc == 14)
                rx_msg->len = 48;
            else if (dlc == 15)
                rx_msg->len = 64;
        }
        else /*CAN2.0*/
        {
            rx_msg->fdf = 0;
            if (dlc <= 8)
                rx_msg->len = dlc;
            else
                rx_msg->len = 8;
        }

        if (rx_msg->rtr)
        {
            rx_msg->len = 0;
        }

        if (CAN_RBUF_00 & BIT31)
        {
            rx_msg->esi = 1;
        }
        else
        {
            rx_msg->esi = 0;
        }

        // read buf
        x     = 0;
        rbufx = 2;
        while (x < rx_msg->len)
        {
            rx_msg->buf[x]     = CAN->RBUF[rbufx];
            rx_msg->buf[x + 1] = CAN->RBUF[rbufx] >> 8;
            rx_msg->buf[x + 2] = CAN->RBUF[rbufx] >> 16;
            rx_msg->buf[x + 3] = CAN->RBUF[rbufx] >> 24;
            x += 4;
            rbufx++;
        }

        CAN_RCTRL |= BIT4; /*释放 Rx Buffer Slot*/
        rx_msg->valid = 1;
        return CanRecv_Succ;
    }

    return CanRecv_NoData;
}

/**
 * @brief    CAN接收数据
 * 输入参数: *id: 接收的id, *ide: 标准/扩展帧, *rtr：数据帧/遥控帧, *fdf：FD帧, *buf: 接收的数据,  len:接收数据长度
 * 返回值:   0：接收成功 !0：接收失败
 * @par 更新记录  V1.0  2023/02/13  HuangMG  创建
 */
CanRecvRet CAN_Recv_Msg(u32 *id, u8 *ide, u8 *rtr, u8 *fdf, u8 *buf, u8 *len)
{
    CANRxMsg rx_msg;
    CanRecvRet ret;
    int i;

    ret  = CAN_Recv(&rx_msg);
    *id  = rx_msg.id;
    *ide = rx_msg.ide;
    *rtr = rx_msg.rtr;
    *fdf = rx_msg.fdf;
    for (i = 0; i < rx_msg.len; i++)
    {
        buf[i] = rx_msg.buf[i];
    }
    *len = rx_msg.len;

    return ret;
}

/*******************************************************************************
 函数名称：    void SoftDelay(void)
 功能描述：    软件延时函数
 输入参数：    无
 输出参数：    无
 返 回 值：    无
 其它说明：
 修改日期      版本号          修改人            修改内容
 -----------------------------------------------------------------------------
 2020/8/5      V1.0           Howlet Li          创建
 *******************************************************************************/
static void Delay(u32 cnt)
{
    volatile u32 t_cnt;

    for (t_cnt = 0; t_cnt < cnt; t_cnt++)
    {
        __NOP();
    }
}

/**
 * @brief    CAN IDx接收滤波函数
 * 输入参数:  x: 滤波通道号。
              id: ID值。
 *            mask：屏蔽位。bit=0表示需要位匹配，bit=1表示不需要匹配。
 *            ide_filter：IDEFilter_St_Ex / IDEFilter_St / IDEFilter_Ex
 * @par 更新记录
 */
void IDx_Filter(u8 x, u32 id, u32 mask, IDEFilterOption ide_filter)
{
    CAN_CFG_STAT |= BIT7; // 复位模式

    CAN_ACFEN |= (1 << x);    // ACFx is Enabled
    CAN_ACFCTRL = (x & 0x0F); // ACFADR [3:0]

    // 1.set MASK
    CAN_ACFCTRL |= BIT5; // CAN_ACFCTRL.SELMASK==1 MASK
    if (ide_filter == IDEFilter_St_Ex)
    {
        CAN_ACF &= ~BIT30;
    }
    else if (ide_filter == IDEFilter_St)
    {
        CAN_ACF |= BIT30;
        CAN_ACF &= ~BIT29; // 只接收标准帧
    }
    else if (ide_filter == IDEFilter_Ex)
    {
        CAN_ACF |= BIT30;
        CAN_ACF |= BIT29; // 只接收扩展帧
    }

    CAN_ACF &= ~0x1FFFFFFF;
    CAN_ACF |= (mask & 0x1FFFFFFF); // set ACFx MASK

    // 2.set ACR
    CAN_ACFCTRL &= ~BIT5; // CAN_ACFCTRL.SELMASK==0 ACR
    CAN_ACF &= ~0x1FFFFFFF;
    CAN_ACF |= (id & 0x1FFFFFFF); // set ACFx ID

    Delay(100);
    CAN_CFG_STAT &= ~BIT7; // 正常输出模式
    Delay(100);
}

/**
 * @brief    CAN接收过滤器使能与禁止
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
void IDx_FilterCmd(u8 x, FuncState state)
{
    if (state == ENABLE)
    {
        CAN->ACFEN |= (1 << x);
    }
    else
    {
        CAN->ACFEN &= ~(1 << x);
    }
}

/*
 TQ = (PRESC + 1) / Fclock
 Tseg1 = TQ * (SEG1 + 2)
 Tseg2 = TQ * (SEG2 + 1)
 CAN_BAUD = 1 / (Tseg1 + Tseg2) = 1 / (TQ * (SEG1 + 2 + SEG2 + 1)) = 1 / (TQ * (SEG1 + SEG2 + 3)) = Fclock / (PRESC + 1)*(SEG1 + SEG2 + 3)
 SEG1 + SEG2 = Fclock / ((PRESC + 1) * CAN_BAUD) - 3
 只要SEG1 + SEG2的总和固定，波特率就正确。
 另外：SEG1 > SEG2，SEG1略大于SEG2
       SEG2 >= SJW

example:
    Fclock = 192000000; PRESC = 23; CAN_BAUD = 500000;
    SEG = 192000000 / ((23+1) * 500000) - 3 = 13
    SEG1 + SEG2 = 12 + 1 = 11 + 2 = ... = 8 + 5

波特率                 PRESC         SJW                SEG2              SEG1
    8000Kbps            2             2                  2                 3
    8000Kbps            1             2                  2                 7

    6153Kbps            1             2                  3                 9

    4000Kbps            5             2                  2                 3
    4000Kbps            3             2                  2                 7

    2000Kbps            11            2                  2                 3

    1000Kbps            23            2                  2                 3
    1000Kbps            15            2                  2                 7

    800Kbps             23            2                  3                 4
    666.6Kbps           23            2                  3                 6

    500Kbps             23            2                  5                 8
    500Kbps             15            2                  4                 17

    400Kbps             23            2                  7                 10
    250Kbps             47            2                  5                 8
    200Kbps             47            2                  7                 10
    160Kbps             47            2                  10                12
    125Kbps             95            2                  5                 8
    100Kbps             95            2                  7                 10
    83.33Kbps           95            2                  8                 13
    80Kbps              95            2                  7                 15
    66.66Kbps           119           2                  8                 13
    50Kbps              119           2                  13                16
    40Kbps              191           2                  10                12
    20Kbps              191           2                  20                27
*/
static bool GetBaudParam(u32 baud, u8 *presc, u8 *sjw, u8 *seg2, u8 *seg1)
{
    bool ret = true;
    switch (baud)
    {
        case 8000:
            // *presc = 2;   *sjw = 2; *seg2 = 2;  *seg1 = 3;
            *presc = 1;
            *sjw   = 2;
            *seg2  = 2;
            *seg1  = 7;
            // *presc = 1;   *sjw = 2; *seg2 = 3;  *seg1 = 6;
            // *presc = 1;   *sjw = 1; *seg2 = 1;  *seg1 = 8;
            // *presc = 0;   *sjw = 1; *seg2 = 1;  *seg1 = 20;
            break;
        case 6153:
            *presc = 1;
            *sjw   = 2;
            *seg2  = 3;
            *seg1  = 9;
            break;
        case 4000:
            //*presc = 5;   *sjw = 2; *seg2 = 2;  *seg1 = 3;
            *presc = 3;
            *sjw   = 2;
            *seg2  = 2;
            *seg1  = 7;
            break;
        case 2000:
            *presc = 11;
            *sjw   = 2;
            *seg2  = 2;
            *seg1  = 3;
            break;
        case 1000:
            // *presc = 23;  *sjw = 2; *seg2 = 2;  *seg1 = 3;
            *presc = 15;
            *sjw   = 2;
            *seg2  = 2;
            *seg1  = 7;
            break;
        case 800:
            // *presc = 23;  *sjw = 2; *seg2 = 2;  *seg1 = 5;
            *presc = 15;
            *sjw   = 2;
            *seg2  = 3;
            *seg1  = 9;
            break;
        case 666:
            *presc = 23;
            *sjw   = 2;
            *seg2  = 3;
            *seg1  = 6;
            break;
        case 500:
            // *presc = 23;  *sjw = 2; *seg2 = 3;  *seg1 = 10;
            *presc = 15;
            *sjw   = 2;
            *seg2  = 4;
            *seg1  = 17;
            break;
        case 400:
            *presc = 23;
            *sjw   = 2;
            *seg2  = 7;
            *seg1  = 10;
            break;
        case 250:
            *presc = 47;
            *sjw   = 2;
            *seg2  = 5;
            *seg1  = 8;
            break;
        case 200:
            *presc = 47;
            *sjw   = 2;
            *seg2  = 7;
            *seg1  = 10;
            break;
        case 160:
            *presc = 47;
            *sjw   = 2;
            *seg2  = 10;
            *seg1  = 12;
            break;
        case 125:
            *presc = 95;
            *sjw   = 2;
            *seg2  = 5;
            *seg1  = 8;
            break;
        case 100:
            *presc = 95;
            *sjw   = 2;
            *seg2  = 7;
            *seg1  = 10;
            break;
        case 83:
            *presc = 95;
            *sjw   = 2;
            *seg2  = 8;
            *seg1  = 13;
            break;
        case 80:
            *presc = 95;
            *sjw   = 2;
            *seg2  = 7;
            *seg1  = 15;
            break;
        case 66:
            *presc = 119;
            *sjw   = 2;
            *seg2  = 8;
            *seg1  = 13;
            break;
        case 50:
            *presc = 119;
            *sjw   = 2;
            *seg2  = 13;
            *seg1  = 16;
            break;
        case 40:
            *presc = 191;
            *sjw   = 2;
            *seg2  = 10;
            *seg1  = 12;
            break;
        case 20:
            *presc = 191;
            *sjw   = 2;
            *seg2  = 20;
            *seg1  = 27;
            break;
        default:
            ret = false;
            break;
    }

    return ret;
}

static void CAN_Write_TBUF(u32 id, u8 ide, u8 rtr, u8 fdf, u8 brs, u8 *msg, u8 len)
{
    u8 frame_inf = 0;
    u8 dlc       = 0;
    u16 tbufx    = 0;
    u32 tbufv    = 0;
    u16 x        = 0;

    if (ide == 0)
    {
        id &= 0x7FF; // 标准帧，11位ID
    }
    else
    {
        id &= 0x1FFFFFFF; // 扩展帧，29位ID
    }
    CAN_TBUF_00 = id;

    if (len <= 8)
        dlc = len;
    else if (len > 8 && len <= 12)
        dlc = 0x09;
    else if (len > 12 && len <= 16)
        dlc = 0x0A;
    else if (len > 16 && len <= 20)
        dlc = 0x0B;
    else if (len > 20 && len <= 24)
        dlc = 0x0C;
    else if (len > 24 && len <= 32)
        dlc = 0x0D;
    else if (len > 32 && len <= 48)
        dlc = 0x0E;
    else if (len > 48 && len <= 64)
        dlc = 0x0F;

    frame_inf |= (ide << 7); // 0标准/1扩展帧
    frame_inf |= (rtr << 6); // 0,数据帧;1,遥控帧
    if (fdf == 1)
        frame_inf |= (1 << 5); // 1,FD帧标记
    else
        frame_inf &= ~(1 << 5);
    if (brs == 1)
        frame_inf |= (1 << 4); // 1,BRS标记
    else
        frame_inf &= ~(1 << 4);
    frame_inf |= (dlc << 0); // dlc,发送数据长度
    CAN_TBUF_01 = frame_inf;

    // set CAN_TBUF_02 ~ CAN_TBUF_17
    x     = 0;
    tbufx = 2; // TBUF赋值从CAN_TBUF_02开始
    while (x < len)
    {
        tbufv = msg[x];
        if ((x + 1) < len) tbufv += (msg[x + 1] << 8);
        if ((x + 2) < len) tbufv += (msg[x + 2] << 16);
        if ((x + 3) < len) tbufv += (msg[x + 3] << 24);
        CAN->TBUF[tbufx] = tbufv;

        x += 4;
        tbufx++;
    }
}

/**
 * @brief    CAN_CFG_STAT按bit置位
 * @par 更新记录
 * CAN_CFG_STAT按bit置位方法，避免向CAN_CFG_STAT.Busoff位写1
 */
void Set_CFG_STAT(u32 bitValue)
{
    u32 tmp_cfg_stat;

    tmp_cfg_stat = CAN->CFG_STAT;
    tmp_cfg_stat &= ~BIT0;
    tmp_cfg_stat |= bitValue;

    CAN->CFG_STAT = tmp_cfg_stat;
}

/**
 * @brief    CAN_CFG_STAT按bit复位
 * @par 更新记录
 * CAN_CFG_STAT按bit复位方法，避免向CAN_CFG_STAT.Busoff位写1
 */
void Reset_CFG_STAT(u32 bitValue)
{
    u32 tmp_cfg_stat;

    tmp_cfg_stat = CAN->CFG_STAT;
    tmp_cfg_stat &= ~BIT0;
    tmp_cfg_stat &= ~bitValue;

    CAN->CFG_STAT = tmp_cfg_stat;
}

/**
 * @brief    内部回环模式使能/禁止
 * @par 更新记录
 * 自发自收，无需自应答，芯片RX和TX引脚可悬空。
 * 应在CAN初始化和ID滤波设置之后再使能。
 */
void CAN_LBMICmd(FuncState state)
{
    if (state == ENABLE)
    {
        Set_CFG_STAT(BIT5); // 开启内回环
    }
    else
    {
        Reset_CFG_STAT(BIT5); // 关闭内回环
    }
}

/**
 * @brief    外部回环模式使能/禁止
 * @par 更新记录
 * 自发自收，自应答，需将芯片RX和TX接入CAN收发器，收发器可以不挂入总线。
 * 应在CAN初始化和ID滤波设置之后再使能。
 */
void CAN_LBMECmd(FuncState state)
{
    if (state == ENABLE)
    {
        Set_CFG_STAT(BIT6); // 开启外回环
        CAN->RCTRL |= BIT7; // 使能自应答
    }
    else
    {
        Reset_CFG_STAT(BIT6); // 关闭外回环
        CAN->RCTRL &= ~BIT7;  // 关闭自应答
    }
}

/**
 * @brief    单次传输模式使能/禁止
 * @par 更新记录
 * PTB/STB单次传输模式使能，使能后错误不重发。
 * 应在CAN初始化和ID滤波设置之后再使能。
 */
void CAN_SS_Enable(TBSelOption tbsel, FuncState state)
{
    if (tbsel == TBSel_PTB)
    {
        if (state == ENABLE)
        {
            Set_CFG_STAT(BIT4);
        }
        else
        {
            Reset_CFG_STAT(BIT4);
        }
    }
    else if (tbsel == TBSel_STB)
    {
        if (state == ENABLE)
        {
            Set_CFG_STAT(BIT3);
        }
        else
        {
            Reset_CFG_STAT(BIT3);
        }
    }
}

/**
 * @brief    打开CAN模块时钟
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
void CAN_Enable(void)
{
    SYS_ModuleClockCmd(SYS_MODULE_CAN, ENABLE);
    Reset_CFG_STAT(BIT7);
    Delay(100);
}
/**
 * @brief    关闭CAN模块时钟
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
void CAN_Disable(void)
{
    SYS_ModuleClockCmd(SYS_MODULE_CAN, DISABLE);
    Set_CFG_STAT(BIT7);
}
/**
 * @brief    CAN模块进入复位模式
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
void CAN_Reset(void)
{
    Set_CFG_STAT(BIT7);
    Delay(100);
    Reset_CFG_STAT(BIT7);
    Delay(100);
}

/*
 * 发送缓冲区模式设置，对应CAN_TCTRL.TSMODE位
 */
void CAN_SetSTBMode(STBTransMode tsMode)
{
    /* 只有STB为空时，才能切换TSMode */
    if ((CAN_TCTRL & 0x03) > 0)
    {
        return;
    }

    if (tsMode == STB_FIFOMode)
    {
        CAN_TCTRL &= ~BIT5;
    }
    else
    {
        CAN_TCTRL |= BIT5;
    }
}

/**
 * @brief    获取can接收错误计数
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
u8 CAN_RxErrorCntGet(void)
{
    return CAN->RECNT & 0xFF;
}

/**
 * @brief    获取can发送错误计数
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
u8 CAN_TxErrorCntGet(void)
{
    return CAN->TECNT & 0xFF;
}

/**
 * @brief    获取can的error passive state
 * @par 更新记录
 */
u8 CAN_ErrorPassiveGet(void)
{
    return (CAN->ERRINT >> 6) & 0x01;
}

/**
 * @brief    获取can的bus off state
 * @par 更新记录
 */
u8 CAN_BusoffGet(void)
{
    return CAN->CFG_STAT & 0x01;
}

/**
 * @brief    获取can的kind of error，错误类别读取
 * @par 更新记录
 */
CANErrorKind CAN_KindOfErrorGet(void)
{
    u8 koer = (CAN->EALCAP >> 5) & 0x07;
    return (CANErrorKind)koer;
}

/**
 * @brief    获取can仲裁失败位置
 * @par 更新记录  V1.0  2022/09/19  YangZJ  创建
 */
u8 CAN_ArbitrationLostCap(void)
{
    return (CAN->EALCAP & 0x1f);
}

/*! @} */
