#include <stdio.h>

int main()
{
  puts("요즘도 변수선언을 앞에서 몰아해야하나?");
  int i=0;
  for(i=0; i<10; ++i)
  {
    printf("Yes! ");
  }
  int result = puts("");
  result *= 2;
  printf("%d", result);
  return 0;
}
