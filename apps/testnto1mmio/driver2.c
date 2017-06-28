/*
 * Copyright 2016, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */

#include <camkes.h>
#include "driver.h"

void h_handoff(void) {
    uart_put("hello from ");
    uart_put(get_instance_name());
    uart_put_char('\n');
}