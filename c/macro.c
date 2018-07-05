#define ADD(a, b) (a+b)
#define PLUS ADD

#define FOO(...) __VA_ARGS__
#define BAR FOO

#include <stdio.h>

int main() {
  printf("%d\n", PLUS(1, 2));
  printf("%d %d %d\n", BAR(100, 200, 300));
}
