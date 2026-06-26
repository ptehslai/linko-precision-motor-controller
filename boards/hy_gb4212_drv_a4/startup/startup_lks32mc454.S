.syntax unified
.cpu cortex-m4
.fpu fpv4-sp-d16
.thumb

.global g_pfnVectors
.global Reset_Handler
.global Default_Handler

.extern SystemInit
.extern main

.section .text.Reset_Handler,"ax",%progbits
.weak Default_Handler
.type Default_Handler, %function
Default_Handler:
    b Default_Handler

.macro def_irq_handler handler_name
.weak \handler_name
.thumb_set \handler_name, Default_Handler
.endm

def_irq_handler NMI_Handler
def_irq_handler HardFault_Handler
def_irq_handler MemManage_Handler
def_irq_handler BusFault_Handler
def_irq_handler UsageFault_Handler
def_irq_handler SVC_Handler
def_irq_handler DebugMon_Handler
def_irq_handler PendSV_Handler
def_irq_handler SysTick_Handler

def_irq_handler I2C0_IRQHandler
def_irq_handler I2C1_IRQHandler
def_irq_handler HALL0_IRQHandler
def_irq_handler HALL1_IRQHandler
def_irq_handler UART0_IRQHandler
def_irq_handler UART1_IRQHandler
def_irq_handler UART2_IRQHandler
def_irq_handler CMP0_IRQHandler
def_irq_handler CMP1_IRQHandler
def_irq_handler CMP2_IRQHandler
def_irq_handler CMP3_IRQHandler
def_irq_handler CMP4_IRQHandler
def_irq_handler CMP5_IRQHandler
def_irq_handler MCPWM00_IRQHandler
def_irq_handler MCPWM01_IRQHandler
def_irq_handler MCPWM10_IRQHandler
def_irq_handler MCPWM11_IRQHandler
def_irq_handler TIMER0_IRQHandler
def_irq_handler TIMER1_IRQHandler
def_irq_handler TIMER2_IRQHandler
def_irq_handler TIMER3_IRQHandler
def_irq_handler TIMER4_IRQHandler
def_irq_handler QEP0_IRQHandler
def_irq_handler QEP1_IRQHandler
def_irq_handler QEP2_IRQHandler
def_irq_handler QEP3_IRQHandler
def_irq_handler EXTI_IRQHandler
def_irq_handler ADC0_IRQHandler
def_irq_handler ADC1_IRQHandler
def_irq_handler ADC2_IRQHandler
def_irq_handler CAN_IRQHandler
def_irq_handler SPI0_IRQHandler
def_irq_handler SPI1_IRQHandler
def_irq_handler WWDG_IRQHandler
def_irq_handler DMA_IRQHandler
def_irq_handler WAKEUP_IRQHandler
def_irq_handler PWRDN_IRQHandler
def_irq_handler FMAC_IRQHandler
def_irq_handler SW_IRQHandler

.type Reset_Handler, %function
Reset_Handler:
    ldr r0, =_sbss
    ldr r1, =_ebss
    mov r2, #0
1:  cmp r0, r1
    bge 2f
    str r2, [r0], #4
    b 1b
2:  ldr r0, =_sdata
    ldr r1, =_edata
    ldr r2, =_sidata
    mov r3, r0
3:  cmp r0, r1
    bge 4f
    ldr r4, [r2], #4
    str r4, [r0], #4
    b 3b
4:  bl SystemInit
    bl main
    b .

.size Reset_Handler, .-Reset_Handler

.section .isr_vector,"a",%progbits
.type g_pfnVectors, %object
g_pfnVectors:
    .word _estack
    .word Reset_Handler
    .word NMI_Handler
    .word HardFault_Handler
    .word MemManage_Handler
    .word BusFault_Handler
    .word UsageFault_Handler
    .word 0
    .word 0
    .word 0
    .word 0
    .word SVC_Handler
    .word DebugMon_Handler
    .word 0
    .word PendSV_Handler
    .word SysTick_Handler
    .word I2C0_IRQHandler
    .word I2C1_IRQHandler
    .word HALL0_IRQHandler
    .word HALL1_IRQHandler
    .word UART0_IRQHandler
    .word UART1_IRQHandler
    .word UART2_IRQHandler
    .word CMP0_IRQHandler
    .word CMP1_IRQHandler
    .word CMP2_IRQHandler
    .word CMP3_IRQHandler
    .word CMP4_IRQHandler
    .word CMP5_IRQHandler
    .word MCPWM00_IRQHandler
    .word MCPWM01_IRQHandler
    .word MCPWM10_IRQHandler
    .word MCPWM11_IRQHandler
    .word TIMER0_IRQHandler
    .word TIMER1_IRQHandler
    .word TIMER2_IRQHandler
    .word TIMER3_IRQHandler
    .word TIMER4_IRQHandler
    .word QEP0_IRQHandler
    .word QEP1_IRQHandler
    .word QEP2_IRQHandler
    .word QEP3_IRQHandler
    .word EXTI_IRQHandler
    .word ADC0_IRQHandler
    .word ADC1_IRQHandler
    .word ADC2_IRQHandler
    .word CAN_IRQHandler
    .word SPI0_IRQHandler
    .word SPI1_IRQHandler
    .word WWDG_IRQHandler
    .word DMA_IRQHandler
    .word WAKEUP_IRQHandler
    .word PWRDN_IRQHandler
    .word FMAC_IRQHandler
    .word SW_IRQHandler

.size g_pfnVectors, .-g_pfnVectors
