#include <stdint.h>
#include <stdio.h>

// Optimized version
uint32_t popcnt(uint64_t num) {
    uint32_t count = 0;
    while (num) {
        num &= (num - 1); // Clear the rightmost set bit
        count++;
    }
    return count;
}

// Naive version
uint32_t count(uint64_t bits) {
    uint32_t used = 0;
    for (uint32_t i = 0; i < 64; i++) {
        if (bits & (1ull << i)) {
            used += 1;
        }
    }
    return used;
}

int main() {
    for (uint64_t i = 0; i < 1000000000; i++) {
        if (popcnt(i) != count(i)) {
            printf("Error: %llu (%d != %d)\n", i, popcnt(i), count(i));
            return 1;
        }
    }
}
