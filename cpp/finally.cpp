//
// finally.cpp (?)
//

#include <iostream>
#include <functional>

using namespace std;

class RAII {
  function<void()> func;
public:
  template <typename T> RAII(T&& func) : func(func) {}
  ~RAII() { func(); }
};

int main() {
  auto x = [] {
    for (int i = 0; i < 5; ++i) {
      RAII _([&] {
        if (i != 3) {
          // error: 'continue' statement not in loop statement
          continue;
        }
      });

      return i;
    }
  }();

  cout << x << endl;
  return 0;
}
