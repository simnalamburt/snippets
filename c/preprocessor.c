#include <stdio.h>

#define A
// #define B

int main() {
#if !(defined(A) || defined(B))
  puts("Neither A nor B is defined");
#else
  puts("A or B are defined");
#endif
}
