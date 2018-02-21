// clang++ a.cpp -std=c++1z && time ./a.out

#include <cstdint>
#include <cstdio>

int main() {
  __uint128_t a = 2, b = 3;

  __uint128_t z = 0;

  for (uint32_t i = 0; i < 1'000'000'000; ++i) {
    a += 1;
    b += 1;

    z += a*b;
  }

  printf("%llx\n", (unsigned long long)(z & 0xFFFFFFFFFFFFFFFF));
}
