// gcc -Wall -pedantic long-double.c && objdump -M intel intel-mnemonic -d a.out  | less

#include <stdio.h>

int main() {
  double a = 0.333333333333333333;
  long double b = 0.333333333333333333L;
  printf("sizeof(double)      : %lu\n", sizeof(double));
  printf("sizeof(long double) : %lu\n", sizeof(long double));
  printf("\n");
  printf("double              : %e\n", a);
  printf("long double         : %Le\n", b);
}
