//     cond ? a : b = expr;
//
// 위와 같은 코드를 짜면
//
// C에서는 아래와 같이 평가되지만
//
//     (cond ? a : b) = expr;
//
// C++에서는 아래와 같이 평가된다.
//
//     cond ? a : (b = expr);
//
// 그래서 아래 코드는 C로 컴파일될때와 C++로 컴파일될때의 동작이 다르다.

#include <stdio.h>
#include <stdbool.h>

int main() {
  char a, b;

  a = 'a', b = 'b';
  printf("a = %c   b = %c\n", a, b);

  true ? a : b = 'X';
  puts("true ? a : b = 'X'");

  printf("a = %c   b = %c\n", a, b);

  puts("");

  a = 'a', b = 'b';
  printf("a = %c   b = %c\n", a, b);

  false ? a : b = 'X';
  puts("false ? a : b = 'X'");

  printf("a = %c   b = %c\n", a, b);
}
