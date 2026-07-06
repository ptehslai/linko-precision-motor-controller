#include "boot_jump.h"

/* NVIC register block for clearing pending interrupts */
#define NVIC_ICPR0 (*(volatile uint32_t *)0xE000E280U)
#define NVIC_ICPR1 (*(volatile uint32_t *)0xE000E284U)

#define SCB_VTOR  (*(volatile uint32_t *)0xE000ED08U)

typedef void (*app_entry_t)(void);

void boot_jump_to_app(uint32_t vector_table_addr)
{
    uint32_t sp = *(volatile uint32_t *)vector_table_addr;
    uint32_t pc = *(volatile uint32_t *)(vector_table_addr + 4U);

    if (sp == 0U || pc == 0U || pc == 0xFFFFFFFFU) {
        return;
    }

    /* Clear all pending NVIC interrupts before switching vector tables */
    NVIC_ICPR0 = 0xFFFFFFFFU;
    NVIC_ICPR1 = 0xFFFFFFFFU;

    __asm volatile("cpsid i");

    SCB_VTOR = vector_table_addr;
    __asm volatile("msr msp, %0" : : "r"(sp) :);
    ((app_entry_t)pc)();
}
