//
// 실험 결과
// ========
//
//     $ clang++ -O3 -std=c++14 is-power-of-2.cpp
//     $ ./a.out
//
//     c        : 71.1623ms
//     c (long) : 245.19ms
//     x86      : 335.545ms
//
// ### 이유
// 1.  inline asm은 컴파일러 최적화가 불가능
// 2.  for loop으로 순회하면서 실행하면, 루프언롤링+벡터연산으로 최적화하기
//     때문에 c코드로 짜는쪽이 훨씬 유리함
//
// Reference
// * https://github.com/simnalamburt/snucse.cachelab2/blob/master/cache.c#L37
//

#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

namespace x86 {
  bool is_power_of_2(uint32_t input) {
    return __builtin_popcount(input) == 1;
  }
}

namespace c {
  bool is_power_of_2(uint32_t input) {
    return (input != 0) && !(input & (input - 1));
  }
}

namespace c_long {
  bool is_power_of_2(uint32_t x) {
    return
      x ==        0x1 || x ==        0x2 || x ==        0x4 || x ==        0x8 ||
      x ==       0x10 || x ==       0x20 || x ==       0x40 || x ==       0x80 ||
      x ==      0x100 || x ==      0x200 || x ==      0x400 || x ==      0x800 ||
      x ==     0x1000 || x ==     0x2000 || x ==     0x4000 || x ==     0x8000 ||
      x ==    0x10000 || x ==    0x20000 || x ==    0x40000 || x ==    0x80000 ||
      x ==   0x100000 || x ==   0x200000 || x ==   0x400000 || x ==   0x800000 ||
      x ==  0x1000000 || x ==  0x2000000 || x ==  0x4000000 || x ==  0x8000000 ||
      x == 0x10000000 || x == 0x20000000 || x == 0x40000000 || x == 0x80000000;
  }
}

int main(int argc, char *argv[]) {
  // Interactive mode
  if (argc >= 2) {
    cout << "Type uint32_t: ";
    uint32_t input;
    cin >> input;
    cout << (c::is_power_of_2(input) ? "true" : "false") << endl;
    return 0;
  }

  auto t1 = high_resolution_clock::now();

  for (uint32_t i = 0; i < 100000000; ++i) {
    volatile auto _ = x86::is_power_of_2(i);
  }

  auto t2 = high_resolution_clock::now();
  cout << "x86      : " << duration<double>(t2 - t1).count() * 1000 << "ms\n";

  for (uint32_t i = 0; i < 100000000; ++i) {
    volatile auto _ = c::is_power_of_2(i);
  }

  auto t3 = high_resolution_clock::now();
  cout << "c        : " << duration<double>(t3 - t2).count() * 1000 << "ms\n";

  for (uint32_t i = 0; i < 100000000; ++i) {
    volatile auto _ = c_long::is_power_of_2(i);
  }

  auto t4 = high_resolution_clock::now();
  cout << "c (long) : " << duration<double>(t4 - t3).count() * 1000 << "ms\n";

  return 0;
}
