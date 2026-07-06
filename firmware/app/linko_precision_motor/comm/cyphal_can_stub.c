/* Temporary stub — libcanard v3 (cavl2.h) not available in this build */
#include "cyphal_can.h"
#include "can_lks.h"
#include "config_generated.h"

bool cyphal_can_init(cyphal_can_t *ctx, can_lks_t *can, runtime_config_t *cfg,
                     void *mem, size_t mem_size)
{
    (void)ctx; (void)can; (void)cfg; (void)mem; (void)mem_size;
    return true;
}

void cyphal_can_update(cyphal_can_t *ctx, uint32_t now_ms)
{
    (void)ctx; (void)now_ms;
}
