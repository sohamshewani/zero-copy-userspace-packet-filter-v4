#include <stdio.h>
#include <stdlib.h>
#include "sliding_window.h"

struct sliding_window *sliding_window_init(uint32_t window_size) {
    struct sliding_window *window = malloc(sizeof(struct sliding_window));
    if (!window) {
        perror("malloc");
        return NULL;
    }
    window->send_seq = 0;
    window->recv_seq = 0;
    window->window_size = window_size;
    return window;
}

void sliding_window_free(struct sliding_window *window) {
    free(window);
}

void sliding_window_send(struct sliding_window *window, uint32_t seq) {
    window->send_seq = seq;
}

void sliding_window_recv(struct sliding_window *window, uint32_t seq) {
    window->recv_seq = seq;
}