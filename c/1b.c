// Calculate the XOR of the squares of the first 1 billion non-negative integers
//
// $\bigoplus_{\substack{0 \le i < 10^9}} i^2$
//
//     $ clang -Wall -Wextra -Wpedantic -std=c23 -O3 1b.c
//
//     $ time ./a.out
//     621501058362566656
//     ./a.out  0.16s user 0.00s system 99% cpu 0.165 total
#include <stdio.h>
#include <stdint.h>

typedef uint64_t u64;

int main() {
  u64 accum = 0;
  for (u64 i = 0; i < 1000000000; i++) {
    accum ^= i*i;
  }
  printf("%lld\n", accum);
}
