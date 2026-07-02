#include <assert.h>
#include "startup_protection.h"
int main(void){ startup_protection_init(); assert(startup_protection_run()); return 0; }
