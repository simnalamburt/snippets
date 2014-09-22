#include <stdio.h>
#include <stdbool.h>

int main()
{
  // cond && cmd
  // do cmd if cond is true
  printf(" true && cmd");  true && printf(" : evaluated"); putchar('\n');
  printf("false && cmd"); false && printf(" : evaluated"); putchar('\n');

  // cond || cmd
  // do cmd if cond is false
  printf(" true || cmd");  true || printf(" : evaluated"); putchar('\n');
  printf("false || cmd"); false || printf(" : evaluated"); putchar('\n');
  return 0;
}
