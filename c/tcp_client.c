#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>

#define SERVER_ADDR     "127.0.0.1"
#define SERVER_PORT     4567
#define BUFLEN          1024

void panic(const char * restrict format, ...);

int main(void) {
  int ret;

  //
  // Initialize sockaddr_in
  //
  struct sockaddr_in dest = {};
  dest.sin_family        = AF_INET;
/*dest.sin_addrret*/ ret = inet_aton(SERVER_ADDR, &dest.sin_addr);
  dest.sin_port          = htons(SERVER_PORT);
  if (!ret) {
    panic("%s is not a proper IP address", SERVER_ADDR);
  }

  //
  // Connect
  //
  const int sock = socket(AF_INET, SOCK_STREAM, 0);
  ret = connect(sock, (struct sockaddr*)&dest, sizeof dest);
  if (ret) {
    panic("Failed to connect to the %s:%d", SERVER_ADDR, SERVER_PORT);
  }

  //
  // Send message
  //
  char buffer[BUFLEN] = "안녕!";
  write(sock, buffer, strnlen(buffer, sizeof buffer - 1));

  //
  // Clean up
  //
  close(sock);
  return 0;
}

void panic(const char * restrict format, ...) {
  va_list args;
  va_start(args, format);

  fputs("\x1b[33m", stderr);
  vfprintf(stderr, format, args);
  fputs("\x1b[0m\n", stderr);

  va_end(args);
  exit(EXIT_FAILURE);
}
