#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "packet.h"
#include "filter_rules.h"

bool apply_filter_rules(const struct filter_rule *rules, uint32_t rule_count, const struct packet *packet) {
    for (uint32_t i = 0; i < rule_count; i++) {
        if (rules[i].src_ip == packet->src_ip && rules[i].dst_ip == packet->dst_ip &&
            rules[i].src_port == packet->src_port && rules[i].dst_port == packet->dst_port) {
            return rules[i].accept;
        }
    }
    return false;
}