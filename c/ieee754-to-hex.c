#include <stdio.h>
#include <inttypes.h>

void f(uint64_t n) {
  float out = (float)n;
  uint32_t *ptr = (uint32_t*)&out;
  printf("0x%08" PRIx32 " = %" PRIu64 ".0\n", *ptr, n);
}

int main() {
  for (uint64_t i = 0; i < 272; ++i) { f(i); }
  f(8606080);
}
