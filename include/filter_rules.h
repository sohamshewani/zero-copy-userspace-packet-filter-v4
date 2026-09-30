#ifndef _FILTER_RULES_H
#define _FILTER_RULES_H

#include <stdint.h>
#include <stdbool.h>

// Define the structure of a filter rule
struct filter_rule {
    uint32_t src_ip;
    uint32_t dst_ip;
    uint16_t src_port;
    uint16_t dst_port;
    bool accept;
};

// Function to apply filter rules to a packet
bool apply_filter_rules(const struct filter_rule *rules, uint32_t rule_count, const struct packet *packet);

#endif // _FILTER_RULES_H