
#ifndef __HAL_LKS32MC45X_REG_H__
#define __HAL_LKS32MC45X_REG_H__
#include "lks32mc45x.h"
/**
 * @brief SYS寄存器定义
 */
typedef struct
{
    __IO u32 null0; ///<  0x00 填充地址
    __IO u32 INFO;  ///<  0x04 芯片版本信息寄存器
    __IO u32 DBG0;  ///<  0x08 调试寄存器
    __IO u32 null1; ///<  0x0C 填充地址

    __IO u32 REG0; ///<  0x10 模拟配置寄存器 0
    __IO u32 REG1; ///<  0x14 模拟配置寄存器 1
    __IO u32 REG2; ///<  0x18 模拟配置寄存器 2
    __IO u32 REG3; ///<  0x1C 模拟配置寄存器 3

    __IO u32 REG4;  ///<  0x20 模拟配置寄存器 4
    __IO u32 REG5;  ///<  0x24 模拟配置寄存器 5
    __IO u32 REG6;  ///<  0x28 模拟配置寄存器 6
    __IO u32 null2; ///<  0x2c 填充地址

    __IO u32 null3; ///<  0x30 填充地址
    __IO u32 REG9;  ///<  0x34 模拟配置寄存器 9
    __IO u32 REGA;  ///<  0x38 模拟配置寄存器 A
    __IO u32 REGB;  ///<  0x3C 模拟配置寄存器 B

    __IO u32 REGC; ///<  0x40 模拟配置寄存器 C
    __IO u32 REGD; ///<  0x44 模拟配置寄存器 D
    __IO u32 REGE; ///<  0x48 模拟配置寄存器 E
    __IO u32 REGF; ///<  0x4C 模拟配置寄存器 F

    __IO u32 REG10; ///<  0x50 模拟配置寄存器 10
    __IO u32 null4; ///<  0x54 填充地址
    __IO u32 TMP_A; ///<  0x58 温度传感器系数 A
    __IO u32 TMP_B; ///<  0x5C 温度传感器系数 B

    __IO u32 DAC0;     ///<  0x60 DAC0 数字量寄存器
    __IO u32 DAC0_AMC; ///<  0x64 DAC0 增益校正寄存器
    __IO u32 DAC0_DC;  ///<  0x68 DAC0 直流偏置寄存器
    __IO u32 null5;    ///<  0x6c 填充地址

    __IO u32 DAC1;     ///<  0x70 DAC1 数字量寄存器
    __IO u32 DAC1_AMC; ///<  0x74 DAC1 增益校正寄存器
    __IO u32 DAC1_DC;  ///<  0x78 DAC1 直流偏置寄存器
    __IO u32 null6;    ///<  0x7C 填充地址

    __IO u32 CLK_CFG;   ///< 0x80 时钟控制寄存器
    __IO u32 IO_CFG;    ///< 0x84 IO控制寄存器
    __IO u32 DBG_CFG;   ///< 0x88 Debug控制寄存器
    __IO u32 null7;     ///< 0x8C 地址对齐，无意义
    __IO u32 CLK_DIV0;  ///< 0x90 外设时钟分频寄存器0
    __IO u32 CLK_DIV1;  ///< 0x94 外设时钟分频寄存器1
    __IO u32 CLK_DIV2;  ///< 0x98 外设时钟分频寄存器2
    __IO u32 CLK_FEN;   ///< 0x9C 外设时钟门控寄存器
    __IO u32 null8;     ///< 0xA0 地址对齐，无意义
    __IO u32 SFT_RST;   ///< 0xA4 软复位寄存器
    __IO u32 PROTECT;   ///< 0xA8 写保护寄存器
    __IO u32 CACHE_CFG; ///< 0xAC Cache控制寄存器
    __IO u32 null9;     ///< 0xB0 地址对齐，无意义
    __IO u32 null10;    ///< 0xB4 地址对齐，无意义
    __IO u32 null11;    ///< 0xB8 地址对齐，无意义
    __IO u32 null12;    ///< 0xBC 地址对齐，无意义
    __IO u32 null13;    ///< 0xC0 地址对齐，无意义
    __IO u32 MEM_CFG;   ///< 0xC4 Memory控制寄存器
    __IO u32 null14;    ///< 0xC8 地址对齐，无意义
    __IO u32 null15;    ///< 0xCC 地址对齐，无意义
    __IO u32 FLSE;      ///< 0xD0 On-Chip FLASH擦除控制寄存器
    __IO u32 FLSP;      ///< 0xD4 On-Chip FLASH编程控制寄存器
} HAL_SYS_TypeDef;

/**
 * @brief FLASH寄存器定义
 */
typedef struct
{
    volatile uint32_t CFG;     ///< 0x00 Flash配置寄存器
    volatile uint32_t ADDR;    ///< 0x04 Flash访问地址寄存器
    volatile uint32_t WDATA;   ///< 0x08 Flash写数据寄存器
    volatile uint32_t RDATA;   ///< 0x0C Flash读数据寄存器
    volatile uint32_t ERASE;   ///< 0x10 Flash触发擦除操作寄存器
    volatile uint32_t PROTECT; ///< 0x14 读取更新Flash保护状态
    volatile uint32_t READY;   ///< 0x18 Flash忙/空闲状态
} HAL_FLASH_TypeDef;
/**
 * @brief SPI寄存器定义
 */
typedef struct
{
    volatile uint32_t CFG;    ///< 0x00 配置寄存器
    volatile uint32_t IE;     ///< 0x04 中断寄存器
    volatile uint32_t BAUD;   ///< 0x08 波特率寄存器
    volatile uint32_t TXDATA; ///< 0x0C 发送数据寄存器
    volatile uint32_t RXDATA; ///< 0x10 接收数据寄存器
    volatile uint32_t SIZE;   ///< 0x14 传输数据长度寄存器
} HAL_SPI_TypeDef;

/**
 * @brief I2C寄存器定义
 */
typedef struct
{
    volatile uint32_t ADDR; ///< 0x00 设备地址寄存器
    volatile uint32_t CFG;  ///< 0x04 配置寄存器
    volatile uint32_t SCR;  ///< 0x08 状态控制寄存器
    volatile uint32_t DATA; ///< 0x0C 数据寄存器
    volatile uint32_t MSCR; ///< 0x10 主状态控制寄存器
    volatile uint32_t BCR;  ///< 0x14 突发控制寄存器
} HAL_I2C_TypeDef;

/**
 * @brief CMP寄存器定义
 */
typedef struct
{
    volatile uint32_t IE;     ///< 0x00 中断使能寄存器
    volatile uint32_t IF;     ///< 0x04 中断标志寄存器
    volatile uint32_t TCLK;   ///< 0x08 时钟分频控制寄存器
    volatile uint32_t CFG;    ///< 0x0C 配置寄存器
    volatile uint32_t BLCWIN; ///< 0x10 黑窗口控制寄存器
    volatile uint32_t DATA;   ///< 0x14 数据寄存器
} HAL_CMP_TypeDef;

/**
 * @brief HALL寄存器定义
 */
typedef struct
{
    volatile uint32_t CFG;   ///< 0x00 配置寄存器
    volatile uint32_t INFO;  ///< 0x04 信息寄存器
    volatile uint32_t WIDTH; ///< 0x08 宽度寄存器
    volatile uint32_t TH;    ///< 0x0C 阈值寄存器
    volatile uint32_t CNT;   ///< 0x10 计数寄存器
} HAL_HALL_TypeDef;

/**
 * @brief ADC0寄存器定义
 */
typedef struct
{
    volatile uint32_t DAT[16]; // 采样数据
    volatile uint32_t PCHN0;   // 正端输入信号选择
    volatile uint32_t PCHN1;   // 正端输入信号选择
    volatile uint32_t PCHN2;   // 正端输入信号选择
    volatile uint32_t PCHN3;   // 正端输入信号选择
    volatile uint32_t NCHN0;   // 负端输入信号选择
    volatile uint32_t NCHN1;   // 负端输入信号选择
    volatile uint32_t NCHN2;   // 负端输入信号选择
    volatile uint32_t NCHN3;   // 负端输入信号选择
    volatile uint32_t CHNT;    // 采样次数
    volatile uint32_t null[3]; // 地址对齐
    volatile uint32_t GAIN;    // 增益选择
    volatile uint32_t CFG;     // 模式配置
    volatile uint32_t TRIG;    // 采样触发配置
    volatile uint32_t SWT;     // 软件触发
    volatile uint32_t DC0;     // 增益为0时 DC offset
    volatile uint32_t AMC0;    // 增益为0时增益校正系数
    volatile uint32_t DC1;     // 增益为1时 DC offset
    volatile uint32_t AMC1;    // 增益为1时增益校正系数
    volatile uint32_t IE;      // 中断使能
    volatile uint32_t IF;      // 中断标志
    volatile uint32_t TH0;     // 阈值0
    volatile uint32_t GEN0;    // 阈值0监测使能
    volatile uint32_t TH1;     // 阈值1
    volatile uint32_t GEN1;    // 阈值1监测使能
} HAL_ADC_TypeDef;

/**
 * @brief TIMER寄存器定义
 */
typedef struct
{
    volatile uint32_t CFG;  ///< 0x00 配置寄存器
    volatile uint32_t TH;   ///< 0x04 计数门限寄存器
    volatile uint32_t CNT;  ///< 0x08 计数值寄存器
    volatile uint32_t CMP0; ///< 0x0C 比较/捕获寄存器 0
    volatile uint32_t CMP1; ///< 0x10 比较/捕获寄存器 1
    volatile uint32_t EVT;  ///< 0x14 外部事件选择寄存器
    volatile uint32_t FLT;  ///< 0x18 滤波控制寄存器
    volatile uint32_t IE;   ///< 0x1C 中断使能寄存器
    volatile uint32_t IF;   ///< 0x20 中断标志寄存器
} HAL_TIMER_TypeDef;

/**
 * @brief QEP寄存器定义
 */
typedef struct
{
    volatile uint32_t CFG; ///< 0x00 QEP0配置寄存器
    volatile uint32_t TH;  ///< 0x04 QEP0计数门限寄存器
    volatile uint32_t CNT; ///< 0x08 QEP0计数值寄存器
    volatile uint32_t IE;  ///< 0x0C QEP0中断使能寄存器
    volatile uint32_t IF;  ///< 0x10 QEP0中断标志寄存器
} HAL_QEP_TypeDef;
/**
 * @brief MCPWM寄存器定义
 */
typedef struct
{

    volatile uint32_t TH[8];   ///< 0x00 MCPWM CH0_P比较门限值寄存器
    volatile uint32_t TMR0;    ///< 0x20 ADC采样定时器比较门限0寄存器
    volatile uint32_t TMR1;    ///< 0x24 ADC采样定时器比较门限1寄存器
    volatile uint32_t TMR2;    ///< 0x28 ADC采样定时器比较门限2寄存器
    volatile uint32_t TMR3;    ///< 0x2C ADC采样定时器比较门限3寄存器
    volatile uint32_t TH0;     ///< 0x30 MCPWM时基0门限值寄存器
    volatile uint32_t TH1;     ///< 0x34 MCPWM时基1门限值寄存器
    volatile uint32_t CNT0;    ///< 0x38 MCPWM时基0计数器寄存器
    volatile uint32_t CNT1;    ///< 0x3C MCPWM时基1计数器寄存器
    volatile uint32_t UPDATE;  ///< 0x40 MCPWM加载控制寄存器
    volatile uint32_t FCNT;    ///< 0x44 MCPWM FAIL时刻CNT值
    volatile uint32_t EVT0;    ///< 0x48 MCPWM时基0外部触发
    volatile uint32_t EVT1;    ///< 0x4C MCPWM时基1外部触发
    volatile uint32_t DTH00;   ///< 0x50 MCPWM CH0 N通道死区宽度控制寄存器
    volatile uint32_t DTH01;   ///< 0x54 MCPWM CH0 P通道死区宽度控制寄存器
    volatile uint32_t DTH10;   ///< 0x58 MCPWM CH1 N通道死区宽度控制寄存器
    volatile uint32_t DTH11;   ///< 0x5C MCPWM CH1 P通道死区宽度控制寄存器
    volatile uint32_t DTH20;   ///< 0x60 MCPWM CH2 N通道死区宽度控制寄存器
    volatile uint32_t DTH21;   ///< 0x64 MCPWM CH2 P通道死区宽度控制寄存器
    volatile uint32_t DTH30;   ///< 0x68 MCPWM CH3 N通道死区宽度控制寄存器
    volatile uint32_t DTH31;   ///< 0x6C MCPWM CH3 P通道死区宽度控制寄存器
    volatile uint32_t FLT;     ///< 0x70 MCPWM滤波时钟分频寄存器
    volatile uint32_t SDCFG;   ///< 0x74 MCPWM加载配置寄存器
    volatile uint32_t AUEN;    ///< 0x78 MCPWM自动更新使能寄存器
    volatile uint32_t TCLK;    ///< 0x7C MCPWM时钟分频控制寄存器
    volatile uint32_t IE0;     ///< 0x80 MCPWM时基0中断控制寄存器
    volatile uint32_t IF0;     ///< 0x84 MCPWM时基0中断标志位寄存器
    volatile uint32_t IE1;     ///< 0x88 MCPWM中断控制寄存器
    volatile uint32_t IF1;     ///< 0x8C MCPWM中断标志位寄存器
    volatile uint32_t EIE;     ///< 0x90 MCPWM异常中断控制寄存器
    volatile uint32_t EIF;     ///< 0x94 MCPWM异常中断标志位寄存器
    volatile uint32_t RE;      ///< 0x98 MCPWM DMA请求控制寄存器
    volatile uint32_t PP;      ///< 0x9C MCPWM推挽模式使能寄存器
    volatile uint32_t IO01;    ///< 0xA0 MCPWM CH0 CH1 IO控制寄存器
    volatile uint32_t IO23;    ///< 0xA4 MCPWM CH2 CH3 IO控制寄存器
    volatile uint32_t FAIL012; ///< 0xA8 MCPWM CH0 CH1 CH2短路控制寄存器
    volatile uint32_t FAIL3;   ///< 0xAC MCPWM CH3短路控制寄存器
    volatile uint32_t PRT;     ///< 0xB0 MCPWM保护寄存器
    volatile uint32_t null13;  ///< 0xB4 无意义 地址对齐
    volatile uint32_t CHMSK;   ///< 0xB8 MCPWM通道屏蔽位寄存器
} HAL_MCPWM_TypeDef;

/**
 * @brief GPIO寄存器定义
 */
typedef struct
{
    volatile uint32_t PIE;   ///< 输入使能
    volatile uint32_t POE;   ///< 输出使能
    volatile uint32_t PDI;   ///< 输入数据
    volatile uint32_t PDO;   ///< 输出数据
    volatile uint32_t PUE;   ///< 上拉使能
    volatile uint32_t PDE;   ///< 下拉使能
    volatile uint32_t PODE;  ///< 开漏使能
    volatile uint32_t PFLT;  ///< 滤波使能
    volatile uint32_t F3210; ///< 功能选择 GPIO_Pin_0-3
    volatile uint32_t F7654; ///< 功能选择 GPIO_Pin_4-7
    volatile uint32_t FBA98; ///< 功能选择 GPIO_Pin_8-11
    volatile uint32_t FFEDC; ///< 功能选择 GPIO_Pin_12-15
    volatile uint32_t BSRR;  ///< 位操作寄存器
    volatile uint32_t BRR;   ///< 位清零寄存器
} HAL_GPIO_TypeDef;

/**
 * @brief CRC寄存器定义
 */
typedef struct
{
    volatile uint32_t DR;   ///< 0x00 CRC数据
    volatile uint32_t CR;   ///< 0x04 CRC控制
    volatile uint32_t INIT; ///< 0x08 CRC初始值
    volatile uint32_t POL;  ///< 0x0C CRC系数
} HAL_CRC_TypeDef;

/**
 * @brief UART寄存器定义
 */
typedef struct
{
    volatile uint32_t CTRL; ///< 0x00 UART控制
    volatile uint32_t DIVH; ///< 0x04 UART波特率高字节
    volatile uint32_t DIVL; ///< 0x08 UART波特率低字节
    volatile uint32_t BUFF; ///< 0x0C UART读/写缓冲区
    volatile uint32_t ADR;  ///< 0x10 UART匹配地址(如RS485)
    volatile uint32_t STT;  ///< 0x14 UART状态
    volatile uint32_t IE;   ///< 0x18 UART中断使能
    volatile uint32_t IF;   ///< 0x1C UART中断标志
    volatile uint32_t IOC;  ///< 0x20 UART IO控制
} HAL_UART_TypeDef;

/**
 * @brief DSP寄存器定义
 */
typedef struct
{
    volatile uint32_t SC;           ///< 0x00 DSP被除数
    volatile uint32_t THETA;        ///< 0x04 CORDIC的theta
    volatile uint32_t XY;           ///< 0x08 CORDIC的坐标x,y
    volatile uint32_t RESERVED;     //
    volatile uint32_t SIN;          ///< 0x10 CORDIC的sin
    volatile uint32_t COS;          ///< 0x14 CORDIC的cos
    volatile uint32_t MOD;          ///< 0x18 CORDIC的模
    volatile uint32_t ATAN;         ///< 0x1C CORDIC的arctan
    volatile uint32_t RESERVED1[4]; //
    volatile uint32_t RAD;          ///< 0x30 DSP被开方数
    volatile uint16_t SQRT;         ///< 0x34 DSP平方根
} HAL_DSP_TypeDef;

typedef struct
{
    volatile uint32_t PSW; ///< 0x00 独立看门狗密码寄存器
    volatile uint32_t CFG; ///< 0x04 独立看门狗配置寄存器
    volatile uint32_t CLR; ///< 0x08 独立看门狗清零寄存器
    volatile uint32_t WTH; ///< 0x0C 独立看门狗计数器定时唤醒门限值寄存器
    volatile uint32_t RTH; ///< 0x10 独立看门狗计数器超时复位门限值寄存器
    volatile uint32_t CNT; ///< 0x14 独立看门狗计数器当前计数值寄存器
} HAL_IWDG_TypeDef;
/**
 * @brief DMA寄存器定义
 */
typedef struct
{
    volatile uint32_t CCR;  ///< 0x00 DMA 通道 0 通道配置寄存器
    volatile uint32_t REN;  ///< 0x04 DMA 通道 0 请求使能寄存器
    volatile uint32_t CTMS; ///< 0x08 DMA 通道 0 传输次数寄存器
    volatile uint32_t SADR; ///< 0x0C DMA 通道 0 源地址寄存器
    volatile uint32_t DADR; ///< 0x10 DMA 通道 0 目的地址寄存器
} HAL_DMA_TypeDef;
extern HAL_DMA_TypeDef *const HAL_DMA[];
extern HAL_SYS_TypeDef *const HAL_SYS[];
extern HAL_FLASH_TypeDef *const HAL_FLASH[];
extern HAL_SPI_TypeDef *const HAL_SPI[];
extern HAL_I2C_TypeDef *const HAL_I2C[];
extern HAL_CMP_TypeDef *const HAL_CMP[];
extern HAL_HALL_TypeDef *const HAL_HALL[];
extern HAL_ADC_TypeDef *const HAL_ADC[];
extern HAL_TIMER_TypeDef *const HAL_TIMER[];
extern HAL_QEP_TypeDef *const HAL_QEP[];
extern HAL_MCPWM_TypeDef *const HAL_MCPWM[];
extern HAL_GPIO_TypeDef *const HAL_GPIO[];
extern HAL_CRC_TypeDef *const HAL_CRC[];
extern HAL_UART_TypeDef *const HAL_UART[];
extern HAL_DSP_TypeDef *const HAL_DSP[];
extern HAL_IWDG_TypeDef *const HAL_IWDG[];
#endif
