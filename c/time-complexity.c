#include <stdio.h>
#include <stdint.h>

enum { SIZE = 1000000 };
uint64_t CACHE[SIZE];

uint64_t test(int n) {
  // cache
  if (CACHE[n]) { return CACHE[n]; }

  if (n <= 50) { return 1; }
  return test(n/3+5) + test(2*n/3+7);
}

int main() {
  printf("x,f(x)\n");
  for (int i = 0; i < SIZE; ++i) {
    printf("%d,%llu\n", i, test(i));
  }
  // 그래프 그려보면 선형임
}
