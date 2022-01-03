#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <inttypes.h>

int main() {
    char command[8];
    uint64_t amount, x = 0, y = 0, aim = 0;

    while(scanf("%s %" SCNu64, command, &amount) == 2) {
        if (strcmp(command, "forward") == 0) {
            x += amount;
            y += amount * aim;
        } else if (strcmp(command, "down") == 0) {
            aim += amount;
        } else if (strcmp(command, "up") == 0)
            aim -= amount;
        else
            assert(0);
    }

    printf("%" PRIu64 "\n", x * y);

    return 0;
}
