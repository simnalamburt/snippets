// Reference:
//   https://twitter.com/cog25_/status/1775728377477165211
//   https://colab.research.google.com/drive/1DML8q3-BXZ89EmuDxmNuMXn5ZkDmGy3i?usp=sharing

#include <stdio.h>

typedef unsigned long long u64;

// Treat binary number as a decimal number.
//
// Example:
//   f(0b1010) => 1010
//   f(0b1111) => 1111
//
// 0 <= n <= 0b10'000'000'000'000'000'000
// 0 <= returned value <= 10'000'000'000'000'000'000
static u64 f(u64 n) {
  u64 ret = 0;
  u64 base = 1;
  while (n) {
    ret += (n & 1) * base;
    base *= 10;
    n >>= 1;
  }
  return ret;
}


int main() {
  const u64 N = 1024;

  for (u64 a = 0; a < N; ++a) {
    for (u64 b = 0; b < N; ++b) {
      putchar((f(a) & f(b)) == f(a & b) ? '#' : ' ');
    }
    putchar('\n');
  }
}
