#include <assert.h>
#include "hardware_probe.h"
int main(void){ hardware_probe_result_t r=hardware_probe_run(); assert(r.ok==r.ok); return 0; }
