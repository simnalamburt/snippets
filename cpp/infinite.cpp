//
// 무한루프를 끝내기
//
//
// $ clang++ -O1 infinite.cpp
// boom!
//
// $ clang++ -O3 infinite.cpp
// boom!
//
//
// Tested with:
//   LLVM 3.0
//   LLVM 3.5.0
//   Apple LLVM 7.0.0
//
// Reference:
//   http://rosaec.snu.ac.kr/publish/2014/techmemo/ROSAEC-2014-002.pdf
//

#include <iostream>

void foo() { while (1) { } }

void bar() {
  foo();
  for (int i = 0; i < 100; ++i) { }
}

int main() {
  using namespace std;

  bar();
  cout << "boom!" << endl;
}
