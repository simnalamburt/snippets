#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  int a = open("shared-file.c", O_RDONLY);

  if (!fork()) {
    close(a);
    return 0;
  }

  sleep(2);

  char buf[3];
  read(a, buf, sizeof buf);
  printf("%c%c%c...\n", buf[0], buf[1], buf[2]);
  return 0;
}
