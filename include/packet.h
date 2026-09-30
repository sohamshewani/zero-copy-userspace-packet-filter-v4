#ifndef _PACKET_H
#define _PACKET_H

#include <stdint.h>

// Define the structure of a packet
struct packet {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t packet_len;
    uint8_t *data;
};

// Function to allocate and initialize a packet
struct packet *packet_alloc(uint32_t src_ip, uint32_t dst_ip, uint16_t src_port, uint16_t dst_port, uint32_t packet_len);

// Function to free a packet
void packet_free(struct packet *packet);

// Function to copy packet data
void packet_copy_data(const struct packet *src, struct packet *dest);

#endif // _PACKET_H