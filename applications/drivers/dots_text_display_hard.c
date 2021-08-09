#include "dots_text_display_hard.h"
#include "tock.h"

#define DOTS_TEXT_DISPLAY_DRIVER_NUM2 0xa0003


bool display_is_present (void) {
    syscall_return_t ret = command (DOTS_TEXT_DISPLAY_DRIVER_NUM2, 0, 0 , 0);
    return ret.type == TOCK_SYSCALL_SUCCESS;
}

bool display_set_speed (unsigned int ms) {
    syscall_return_t ret = command (DOTS_TEXT_DISPLAY_DRIVER_NUM2, 1, ms, 0);
    return ret.type == TOCK_SYSCALL_SUCCESS;
}

bool display_get_speed (unsigned int *ms) {
    syscall_return_t ret = command (DOTS_TEXT_DISPLAY_DRIVER_NUM2, 2, 0, 0);

    if ( ret.type == TOCK_SYSCALL_SUCCESS_U32) {

        *ms = ret.data[0];
        return true;
    }

    else {
        return false;
    }
}




 