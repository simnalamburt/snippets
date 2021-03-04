#include <stdio.h>

int main() {
  int val = 0, ret;
  char buffer[256];

  printf("Type int: ");
  fgets(buffer, sizeof buffer, stdin);
  ret = sscanf(buffer, "%d", &val);
  while (ret != 1) {
    // STDIN was closed
    if (feof(stdin)) {
      printf("ERROR: STDIN was closed\n");
      return -1;
    }

    printf("ERROR: Value must be an integer.\nType int: ");
    fgets(buffer, sizeof buffer, stdin);
    ret = sscanf(buffer, "%d", &val);
  }

  printf("Input was %d\n", val);
}
