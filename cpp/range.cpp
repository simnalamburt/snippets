//
// 실험 결과
// ========
//
//     $ clang++ -O3 -std=c++1z range.cpp
//     $ ./a.out
//
//     for()            : 61.1005ms
//     hyeon::range()   : 62.5964ms
//     dalgona::range() : 1216.04ms
//
// Reference: https://twitter.com/simnalamburt/status/708524123660623872
//
// ### 이유
// 1.  불필요한 메모리 alloc이 성능저하의 제일 큰 원인
// 2.  Step도 저렇게 구현하지 않아도 됨
//

//
// No dependency!
//
namespace hyeon {
  template<typename T>
  class Iterator {
    T _it;
  public:
    const T step;

    Iterator(T it, T step) : _it(it), step(step) { }
    auto operator!=(const Iterator<T> &right) const { return **this < *right; }
    auto operator*() const { return _it; }
    auto operator++() { _it += step; return *this; }
  };

  template<typename T>
  struct Range {
    const T _begin, _end, _step;
    auto begin() const { return Iterator<T>{ _begin, _step }; }
    auto end() const { return Iterator<T>{ _end, _step }; }
  };

  template<typename T>
  auto range(T begin, T end, T step = 1) {
    return Range<T>{ begin, end, step };
  }
}

//
// Dependencies for dalgona::range
//
#include <vector>
#include <type_traits>
#define DX_MSG_NONINTEGRAL "IntT must be an integral type."
namespace dalgona
{
  template <typename IntT> std::vector<IntT> range(IntT to);
  template <typename IntT> std::vector<IntT> range(IntT from, IntT to, IntT step=1);

  template <typename IntT> std::vector<IntT> range(IntT to)
  {
    static_assert(std::is_integral<IntT>::value, DX_MSG_NONINTEGRAL);
    return range((IntT)0, to);
  }

  template <typename IntT> std::vector<IntT> range(IntT from, IntT to, IntT step)
  {
    static_assert(std::is_integral<IntT>::value, DX_MSG_NONINTEGRAL);

    std::vector<IntT> vec(0);

    if (step == 0) return vec;

    if (step > 0) for (IntT i = from; i < to; i += step)
      vec.push_back(i);
    else for (IntT i = from; i > to; i += step)
      vec.push_back(i);

    return vec;
  }
}

//
// Benchmark
//
#include <chrono>
#include <iostream>
auto main() -> int {
  using namespace std;
  using namespace chrono;

  constexpr auto begin = 23, end = 300000005, step = 3;
  constexpr auto now = high_resolution_clock::now;

  const auto t1 = now();

  for (auto i = begin; i < end; i += step) {
    const volatile auto _ = i;
  }

  const auto t2 = now();

  for (auto i : hyeon::range(begin, end, step)) {
    const volatile auto _ = i;
  }

  const auto t3 = now();

  for (auto i : dalgona::range(begin, end, step)) {
    const volatile auto _ = i;
  }

  const auto t4 = now();

  const auto ms = [](auto param) { return duration<double>(param).count() * 1000; };
  cout <<
    "for()            : " << ms(t2 - t1) << "ms\n"
    "hyeon::range()   : " << ms(t3 - t2) << "ms\n"
    "dalgona::range() : " << ms(t4 - t3) << "ms\n";
}
