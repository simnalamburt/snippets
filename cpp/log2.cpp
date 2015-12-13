#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

static inline uint32_t log2(const uint32_t x) {
  uint32_t y;
  asm ("bsr %1, %0" : "=r"(y) : "r" (x));
  return y;
}

static inline uint32_t log2_slow(uint32_t x) {
  uint32_t ret = 0;
  while (x >>= 1) { ++ret; }
  return ret;
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    cout << "Type int: ";
    uint32_t input;
    cin >> input;
    cout << log2(input) << endl;
    return 0;
  }

  auto t1 = high_resolution_clock::now();

  for (uint32_t i = 0; i < 100000000; ++i) {
    volatile auto _ = log2(i);
  }

  auto t2 = high_resolution_clock::now();

  for (uint32_t i = 0; i < 100000000; ++i) {
    volatile auto _ = log2_slow(i);
  }

  auto t3 = high_resolution_clock::now();

  cout << "어셈 : " << duration<double>(t2 - t1).count() * 1000 << "ms\n";
  cout << "계산 : " << duration<double>(t3 - t2).count() * 1000 << "ms\n";

  return 0;
}
