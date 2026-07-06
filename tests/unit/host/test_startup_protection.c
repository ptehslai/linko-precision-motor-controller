#include <assert.h>
#include "board.h"
#include "startup_protection.h"

int main(void)
{
    board_init();
    startup_protection_init();
    assert(startup_protection_run());
    assert(!startup_protection_can_allowed());
    startup_protection_release_can();
    assert(startup_protection_can_allowed());
    return 0;
}
