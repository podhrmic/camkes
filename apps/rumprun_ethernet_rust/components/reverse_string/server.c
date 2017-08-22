/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

#include <camkes.h>
#include <buffer.h>
#include <string.h>
#include <stdio.h>

int run(void) {

    char *buffer_str = (char*)network_buffer;
    while(true) {
        /* Wait for event */
        ipframe_ev_rx_wait();
        printf("Server: Got string: %s\n", buffer_str);

        int len = strnlen(buffer_str, IP_FRAME_MAX_LEN);
        for (int i = 0; i < len / 2; ++i) {
            int swap_idx = len - i - 1;
            char tmp = buffer_str[i];
            buffer_str[i] = buffer_str[swap_idx];
            buffer_str[swap_idx] = tmp;
        }

        /* Signal to client that we are finished */
        ipframe_ev_tx_emit();
    }

    return 0;
}
