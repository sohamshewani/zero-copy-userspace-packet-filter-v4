#include <stdio.h>
#include <stdlib.h>
#include "packet.h"
#include "ring_buffer.h"
#include "sliding_window.h"

void transmit_packet(struct packet *packet, struct ring_buffer *buffer, struct sliding_window *window) {
    // Simulate transmission
    // For simplicity, just push the packet to the ring buffer
    ring_buffer_push(buffer, packet->data, packet->packet_len);
    // Update the sliding window
    sliding_window_send(window, packet->src_ip << 16 | packet->dst_ip);
}