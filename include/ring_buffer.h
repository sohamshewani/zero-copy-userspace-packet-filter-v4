#ifndef _RING_BUFFER_H
#define _RING_BUFFER_H

#include <stdint.h>
#include <stdlib.h>

// Define the structure of a ring buffer
struct ring_buffer {
    uint8_t *buffer;
    uint32_t size;
    uint32_t head;
    uint32_t tail;
    uint32_t count;
};

// Function to initialize a ring buffer
struct ring_buffer *ring_buffer_init(uint32_t size);

// Function to free a ring buffer
void ring_buffer_free(struct ring_buffer *buffer);

// Function to add data to the ring buffer
void ring_buffer_push(struct ring_buffer *buffer, const uint8_t *data, uint32_t len);

// Function to get data from the ring buffer
void ring_buffer_pull(struct ring_buffer *buffer, uint8_t *data, uint32_t len);

#endif // _RING_BUFFER_H