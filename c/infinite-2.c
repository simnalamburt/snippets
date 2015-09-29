//
// 무한루프 끝내기!
//
//
// $ clang -O1 infinite-2.c
// boom!
//
// $ clang -O3 infinite-2.c
// boom!
//
//
// Tested with:
//   Apple LLVM 7.0.0
//
// Reference:
//   http://blog.regehr.org/archives/140
//

#include <stdio.h>

int loop(void) {
  const int MAX = 10000000;
  int a = 1, b = 1, c = 1;

  while (1) {
    if (a*a*a == b*b*b + c*c*c) { return 1; }
    a++;
    if (a > MAX) {
      a = 1;
      b++;
    }
    if (b > MAX) {
      b = 1;
      c++;
    }
    if (c > MAX) {
      c = 1;
    }
  }

  return 0;
}

int main(void) {
  loop();
  printf("boom!\n");

  return 0;
}
