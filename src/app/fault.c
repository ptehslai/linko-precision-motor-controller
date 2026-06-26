#include "fault.h"

static fault_code_t s_fault = FAULT_NONE;

void fault_init(void)
{
    s_fault = FAULT_NONE;
}

void fault_set(fault_code_t code)
{
    s_fault = code;
}

void fault_clear(void)
{
    s_fault = FAULT_NONE;
}

void fault_clear_all(void)
{
    s_fault = FAULT_NONE;
}

bool fault_is_active(void)
{
    return s_fault != FAULT_NONE;
}

fault_code_t fault_get(void)
{
    return s_fault;
}
