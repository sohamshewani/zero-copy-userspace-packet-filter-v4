#include <stdio.h>
#include <stdlib.h>
#include "ring_buffer.h"

struct ring_buffer *ring_buffer_init(uint32_t size) {
    struct ring_buffer *buffer = malloc(sizeof(struct ring_buffer));
    if (!buffer) {
        perror("malloc");
        return NULL;
    }
    buffer->buffer = malloc(size);
    if (!buffer->buffer) {
        perror("malloc");
        free(buffer);
        return NULL;
    }
    buffer->size = size;
    buffer->head = 0;
    buffer->tail = 0;
    buffer->count = 0;
    return buffer;
}

void ring_buffer_free(struct ring_buffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

void ring_buffer_push(struct ring_buffer *buffer, const uint8_t *data, uint32_t len) {
    if (len > buffer->size - buffer->count) {
        perror("ring buffer overflow");
        return;
    }
    memcpy(&buffer->buffer[buffer->head], data, len);
    buffer->head = (buffer->head + len) % buffer->size;
    buffer->count += len;
}

void ring_buffer_pull(struct ring_buffer *buffer, uint8_t *data, uint32_t len) {
    if (len > buffer->count) {
        perror("ring buffer underflow");
        return;
    }
    memcpy(data, &buffer->buffer[buffer->tail], len);
    buffer->tail = (buffer->tail + len) % buffer->size;
    buffer->count -= len;
}