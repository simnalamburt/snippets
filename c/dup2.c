#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  int fd1, fd2, fd3;
  char c1, c2, c3;
  char *fname = argv[1];

  fd1 = open(fname, O_RDONLY, 0);
  fd2 = open(fname, O_RDONLY, 0);
  fd3 = open(fname, O_RDONLY, 0);

  dup2(fd2, fd3);

  read(fd1, &c1, 1);
  read(fd2, &c2, 1);
  read(fd3, &c3, 1);

  printf("c1 = %c, c2 = %c, c3 = %c\n", c1, c2, c3);
  return 0;
}
