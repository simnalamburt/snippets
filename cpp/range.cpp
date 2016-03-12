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

#include <chrono>
#include <iostream>

// No dependency!
namespace hyeon {
  template<typename T>
  struct Iterator {
    private: T _it;
    public: const T step;

    Iterator(T it, T step) : _it(it), step(step) { }

    bool operator!=(const Iterator<T> &right) const { return **this < *right; }
    T operator*() const { return _it; }

    Iterator<T>& operator++() { _it += step; return *this; }
  };

  template<typename T>
  struct Range {
    const T _begin, _end, _step;
    Range(T begin, T end, T step) : _begin(begin), _end(end), _step(step) { }

    Iterator<T> begin() const { return { _begin, _step }; }
    Iterator<T> end() const { return { _end, _step }; }
  };

  template<typename T>
  auto range(T begin, T end, T step = 1) -> Range<T> {
    return { begin, end, step };
  }
}

// Dependencies for dalgona::range
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

auto main() -> int {
  using namespace std;
  using namespace chrono;
  const auto now = high_resolution_clock::now;
  constexpr uint32_t begin = 23;
  constexpr uint32_t end = 300000005;
  constexpr uint32_t step = 3;

  const auto t1 = now();

  for (uint32_t i = begin; i < end; i += step) {
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

  return 0;
}

//{
//  auto && __range = range_expression ;
//  for (auto __begin = begin_expr,
//            __end = end_expr;
//            __begin != __end; ++__begin) {
//    range_declaration = *__begin;
//    loop_statement
//  }
//}
