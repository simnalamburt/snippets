//
// Fixed-point combinator example with C++14
// ========
//
// ```console
// $ g++ -std=c++14 y-combinator.cpp
// $ ./a.out
// fact(15) = 1307674368000
// gcd(135, 225) = 45
// ```
//
// ###### Reference
// - http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
//

#include <iostream>
#include <functional>

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
  using std::cout;
  using std::endl;
  using u64 = unsigned long long;

  auto factorial = y([](auto factorial, u64 n) -> u64 {
    return n == 0 ? 1 : n * factorial(n - 1);
  });

  auto gcd = y([](auto gcd, u64 lhs, u64 rhs) -> u64 {
    return rhs == 0 ? lhs : gcd(rhs, lhs % rhs);
  });

  cout << "fact(15) = " << factorial(15) << endl;
  cout << "gcd(135, 225) = " << gcd(135, 225) << endl;
  return 0;
}
