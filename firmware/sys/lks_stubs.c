/* Stubs for missing SDK functions when lks32mc45x_trim.s is not linked */

/* TRIM_Read: reads analog trim values from chip-specific OTP.
   Called by ADC_Init(). Returning 0 lets ADC use default values. */
unsigned int TRIM_Read(unsigned int addr)
{
    (void)addr;
    return 0U;
}
