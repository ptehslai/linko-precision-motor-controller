#include <stdint.h>

#ifdef LKS_SDK_LINK
#include "lks32mc45x_lib.h"
#endif

uint32_t SystemCoreClock = 192000000U;

void SystemInit(void)
{
#ifdef LKS_SDK_LINK
    SYS_WR_PROTECT = 0x7A83U;
    SYS_SFT_RST    = 0xFFFFFFFFU;
    SYS_SFT_RST    = 0U;

    for (volatile int i = 0; i < 8; i++) {
        __NOP();
    }

#if defined(BOARD_HSE_MHZ) && (BOARD_HSE_MHZ == 24)
    SYS_MclkChoice(SYS_MCLK_192M_XTAL24);
#else
    SYS_MclkChoice(SYS_MCLK_192M_XTAL12);
#endif
    SystemCoreClock = SYS_ReadMcuClk();

    IWDG_Disable();
    WWDG_Disable();

    SCB->CPACR = 0xFU << 20;
#else
    SystemCoreClock = 192000000U;
#endif
}
