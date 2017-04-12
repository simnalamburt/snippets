// ```bash
// gcc   -W -Wall -pedantic long-double.c
// clang -W -Wall -pedantic long-double.c
//
// gcc   -W -Wall -pedantic -DQUADMATH -lquadmath long-double.c
// clang -W -Wall -pedantic -DQUADMATH -lquadmath long-double.c
//
// objdump -M intel intel-mnemonic -d a.out | less
// ```

#include <stdio.h>
#if !defined(__clang__) && defined(QUADMATH)
#include <quadmath.h>
#endif

int main() {
  double a = 0.333333333333333333;
  long double b = 0.333333333333333333L;
#ifdef QUADMATH
  __float128 c = 0.333333333333333333;
#endif

  printf("sizeof(double)      : %lu\n", sizeof(double));
  printf("sizeof(long double) : %lu\n", sizeof(long double));
#ifdef QUADMATH
  printf("sizeof(__float128)  : %lu\n", sizeof(__float128));
#endif
  printf("\n");
  printf("double              : %e\n", a);
  printf("long double         : %Le\n", b);
#ifdef QUADMATH
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wformat-extra-args"
  printf("long double         : %Qe\n", c);
#pragma GCC diagnostic pop
#endif
}
