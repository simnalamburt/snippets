#include <stdio.h>
#include <string.h>

int main() {
  char input[] = "&foo&bar&";

  // Split input by & with strtok_r
  char *saveptr;
  char *token = strtok_r(input, "&", &saveptr);
  while (token != NULL) {
    printf("\"%s\"\n", token);
    token = strtok_r(NULL, "&", &saveptr);
  }
}
