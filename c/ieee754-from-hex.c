#include <stdio.h>
#include <inttypes.h>

void f(uint32_t n) {
  float *ptr = (float*)&n;
  printf("0x%08" PRIx32 " = %g\n", n, *ptr);
}

int main() {
  f(0x45287000);
  f(0x45458000);
}
