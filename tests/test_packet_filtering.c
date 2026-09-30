#include <stdio.h>
#include <stdbool.h>
#include "packet.h"
#include "filter_rules.h"

int main() {
    struct filter_rule rules[] = {
        {0x01020304, 0x05060708, 1234, 8765, true},
        {0x01020304, 0x05060708, 8765, 1234, false}
    };
    const struct packet *packet = packet_alloc(0x01020304, 0x05060708, 1234, 8765, 1024);
    if (!packet) {
        return 1;
    }
    bool result = apply_filter_rules(rules, 2, packet);
    if (result) {
        printf("Packet accepted\n");
    } else {
        printf("Packet rejected\n");
    }
    packet_free(packet);
    return 0;
}