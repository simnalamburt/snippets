// dd if=/dev/zero of=input bs=1 count=200M

#include <malloc.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main() {
  int fd = open("input", O_NONBLOCK | O_RDONLY);

  int opt = 1;
  ioctl(fd, FIONBIO, &opt);

  int req = 1024 * 1024 * 200;
  void* mem = malloc(req);
  int cnt = read(fd, mem, req);
  printf("reqeusted = %d\n", req);
  printf("    count = %d\n", cnt);

  free(mem);
  close(fd);
}
