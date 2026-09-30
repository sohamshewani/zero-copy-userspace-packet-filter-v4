#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "packet.h"
#include "ring_buffer.h"

struct packet *packet_alloc(uint32_t src_ip, uint32_t dst_ip, uint16_t src_port, uint16_t dst_port, uint32_t packet_len) {
    struct packet *packet = malloc(sizeof(struct packet));
    if (!packet) {
        perror("malloc");
        return NULL;
    }
    packet->src_ip = src_ip;
    packet->dst_ip = dst_ip;
    packet->src_port = src_port;
    packet->dst_port = dst_port;
    packet->packet_len = packet_len;
    packet->data = malloc(packet_len);
    if (!packet->data) {
        perror("malloc");
        free(packet);
        return NULL;
    }
    return packet;
}

void packet_free(struct packet *packet) {
    if (packet->data) {
        free(packet->data);
    }
    free(packet);
}

void packet_copy_data(const struct packet *src, struct packet *dest) {
    dest->src_ip = src->src_ip;
    dest->dst_ip = src->dst_ip;
    dest->src_port = src->src_port;
    dest->dst_port = src->dst_port;
    dest->packet_len = src->packet_len;
    memcpy(dest->data, src->data, src->packet_len);
}
