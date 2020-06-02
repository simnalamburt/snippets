#include <stdio.h>
#include <inttypes.h>

void f(uint64_t n) {
  float out = (float)n;
  uint32_t *ptr = (uint32_t*)&out;
  printf("0x%08" PRIx32 " = %" PRIu64 ".0\n", *ptr, n);
}

int main() {
  for (uint64_t i = 0; i < 272; ++i) { f(i); }
  putchar('\n');
  int arr[] = {
    31960, 99416, 166872, 234328,
    301784, 369240, 436696, 504152,
    571608, 639064, 706520, 773976,
    841432, 908888, 976344, 1043800,
  };
  for (uint64_t i = 0; i < 16; ++i) { f(arr[i]); }
}
