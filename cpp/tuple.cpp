// clang++ -std=c++17 tuple.cpp

#include <cstdio>
#include <tuple>

using namespace std;

int main() {
  // 만드는법
  tuple yey { 3.14, "Hello, world!", nullptr };

  // Destruct
  auto [pi, msg, ptr] = yey;

  printf("pi   : %lf\n", pi);
  printf("msg  : %s\n", msg);
  printf("ptr  : %p\n", ptr);

  // 일부만 고치기
  get<1>(yey) = "Yo";

  // 일부만 가져오기
  auto msg2 = get<1>(yey);

  printf("msg2 : %s\n", msg2);
}
