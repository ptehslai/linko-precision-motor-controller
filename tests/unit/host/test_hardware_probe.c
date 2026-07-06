#include <assert.h>
#include "board.h"
#include "hardware_probe.h"

int main(void)
{
    board_init();
    hardware_probe_result_t r = hardware_probe_run();
    assert(r.adc_ok);
    assert(r.encoder_ok);
    return 0;
}
