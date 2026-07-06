#include "sys_diag.h"

#include "lks_hal.h"

void sys_fault_halt(const char *reason)
{
    hal_mcpwm_enable(false);
    hal_uart_init(115200U);
    if (reason != NULL) {
        hal_uart_write("FAULT: ");
        hal_uart_write(reason);
        hal_uart_write("\r\n");
    }
    for (;;) {
    }
}
