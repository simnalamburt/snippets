#include <stdio.h>
#include <string.h>

void measure(const char* str) {
  printf("%s : %lu\n", str, strlen(str));
}

int main(void) {
  measure("Hello, world!");
  measure("안녕");
  return 0;
}
