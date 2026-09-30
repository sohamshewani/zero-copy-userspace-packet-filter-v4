#include <stdio.h>
#include "packet.h"

int main() {
    struct packet *packet = packet_alloc(0x01020304, 0x05060708, 1234, 8765, 1024);
    if (!packet) {
        return 1;
    }
    packet_free(packet);
    return 0;
}