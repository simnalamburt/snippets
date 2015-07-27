#include <sys/types.h>
#include <utime.h>

int main() {
  struct utimbuf buf;
  buf.actime = 0;
  buf.modtime = 0;

  int ret = utime("utime.c", &buf);
  if (ret) {
    perror("utime");
    exit(1);
  }

  return 0;
}
