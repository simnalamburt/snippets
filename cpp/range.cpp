//
// 실험 결과
// ========
//
//     $ clang++ -O3 -std=c++1z range.cpp
//     $ ./a.out
//
//     for()            : 37.5555ms
//     hyeon::range()   : 37.6976ms
//     dalgona::range() : 939.455ms
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
  class Iterator {
    T _it;

  public:
    Iterator(const T& it) : _it(it) { }

    bool operator!=(const Iterator<T> &right) const { return **this != *right; }
    T operator*() const { return _it; }

    Iterator<T>& operator++() { ++_it; return *this; }
  };

  template<typename T>
  struct Range {
    const T _begin, _end;
    Range(T begin, T end) : _begin(begin), _end(end) { }

    Iterator<T> begin() const { return { _begin }; }
    Iterator<T> end() const { return { _end }; }
  };

  template<typename T>
  auto range(T begin, T end) -> Range<T> {
    return { begin, end };
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

  const auto t1 = now();

  for (uint32_t i = 0; i < 100000000; ++i) {
    const volatile auto _ = i;
  }

  const auto t2 = now();

  for (auto i : hyeon::range(0, 100000000)) {
    const volatile auto _ = i;
  }

  const auto t3 = now();

  for (auto i : dalgona::range(0, 100000000)) {
    const volatile auto _ = i;
  }

  const auto t4 = now();

  cout <<
    "for()            : " << duration<double>(t2 - t1).count() * 1000 << "ms\n"
    "hyeon::range()   : " << duration<double>(t3 - t2).count() * 1000 << "ms\n"
    "dalgona::range() : " << duration<double>(t4 - t3).count() * 1000 << "ms\n";

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
