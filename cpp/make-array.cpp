// Test codes for `make_array()`
//
//     g++ -std=c++14 make-array.cpp
//     ./a.out

#include <iostream>
#include <experimental/array>

using namespace std;
using namespace std::experimental;

auto main() -> int {
  decltype(auto) arr = make_array(10, 20, 30, 40, 50);

  for (auto &&elem : arr) {
    cout << elem << endl;
  }
}
