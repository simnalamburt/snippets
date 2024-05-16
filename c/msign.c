#include <stdio.h>
#include <stdint.h>

float msign(float f) {
  uint32_t i = *(uint32_t*)(&f);
  uint32_t ret = (i & 0x80000000u) | 0x3f800000;
  return *(float*)(&ret);
}

int main() {
  printf("%f\n", msign(+0.0f));
  printf("%f\n", msign(-0.0f));
  printf("%f\n", msign(+1.0f));
  printf("%f\n", msign(-1.0f));
  printf("%f\n", msign(+3.14f));
  printf("%f\n", msign(-3.14f));
  printf("%f\n", msign(+3.14f));
  printf("%f\n", msign(-3.14f));
}
