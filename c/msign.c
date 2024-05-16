#include <stdio.h>
#include <stdint.h>

float msign2(float f) {
  if (f >= 0.0f) {
    return 1.0f;
  } else {
    return -1.0f;
  }
}

float msign(float f) {
  uint32_t i = *(uint32_t*)(&f);
  uint32_t ret = (i & 0x80000000u) | 0x3f800000;
  return *(float*)(&ret);
}

int main() {
  float sum;

  sum = 0.0f;
  for (long i = 0; i < 10000000000; ++i) {
    sum += msign((float)i);
  }
  printf("sum = %f\n", sum);

  sum = 0.0f;
  for (long i = 0; i < 10000000000; ++i) {
    sum += msign2((float)i);
  }
  printf("sum = %f\n", sum);
}
