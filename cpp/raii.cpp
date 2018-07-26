#include <cstdio>
#include <functional>

struct RAII {
  std::function<void()> func;
  ~RAII() { func(); }
};

int main() {
  const RAII _ { [&] {
    puts("이 블럭을 탈출하는 순간, 자동으로 이 코드가 실행됩니다");
  } };

  puts("함수 본체");
}
