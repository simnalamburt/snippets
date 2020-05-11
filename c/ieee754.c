#include <stdio.h>
#include <stdint.h>

int main() {
  for (size_t i = 0; i < 32; ++i) {
    float out = (float)i;
    uint32_t *ptr = (uint32_t*)&out;
    printf("%08x\n", *ptr);
  }
}
