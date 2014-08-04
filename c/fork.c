#include <stdio.h>
#include <unistd.h>

int main(void)
{
  printf("(%d) 포크 전\n", getpid());
  fork();
  printf("(%d) 포크 후\n", getpid());

  return 0;
}
