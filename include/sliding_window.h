#ifndef _SLIDING_WINDOW_H
#define _SLIDING_WINDOW_H

#include <stdint.h>

// Define the structure of a sliding window
struct sliding_window {
    uint32_t send_seq;
    uint32_t recv_seq;
    uint32_t window_size;
};

// Function to initialize a sliding window
struct sliding_window *sliding_window_init(uint32_t window_size);

// Function to free a sliding window
void sliding_window_free(struct sliding_window *window);

// Function to update the send sequence number
void sliding_window_send(struct sliding_window *window, uint32_t seq);

// Function to update the receive sequence number
void sliding_window_recv(struct sliding_window *window, uint32_t seq);

#endif // _SLIDING_WINDOW_H