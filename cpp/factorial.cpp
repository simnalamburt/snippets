#include <iostream>

template<int n>
struct factorial {
  static constexpr int value = n*factorial<n - 1>::value;
};

template<>
struct factorial<0> {
  static constexpr int value = 1;
};

using namespace std;

auto main() -> int {
  cout << factorial<5>::value << endl;
}
