#include <stdio.h>
#include "packet.h"
#include "ring_buffer.h"
#include "sliding_window.h"

int main() {
    struct packet *packet = packet_alloc(0x01020304, 0x05060708, 1234, 8765, 1024);
    if (!packet) {
        return 1;
    }

    struct ring_buffer *buffer = ring_buffer_init(1024);
    if (!buffer) {
        return 1;
    }

    struct sliding_window *window = sliding_window_init(10);
    if (!window) {
        return 1;
    }

    transmit_packet(packet, buffer, window);

    ring_buffer_free(buffer);
    sliding_window_free(window);
    packet_free(packet);
    return 0;
}