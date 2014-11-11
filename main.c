#include <stdio.h>


int main(void) {
  char input[1001] = {}, delims[101], *tokens[1001];

  fgets(delims, sizeof delims, stdin);
  fgets(input, sizeof input, stdin);

  int i, j, k = 1;
  tokens[0] = &input[0];
  for (i = 0; i < 1000; ++i) {
    for (j = 0; j < 100; ++j) {
      if (input[i] == delims[j]) { input[i] = 0; tokens[k] = &input[i+1]; ++k; break; }
    }
  }
  const int count = k;

  for (i = 0; i < count-2; ++i) {
    for (j = i+1; j < count-1; ++j) {
      int q = 0;
      char* temp = 0;
      while (1) {
        if (*tokens[i] > *tokens[j] && *tokens[i] - *tokens[j] != 32) { temp = tokens[i]; tokens[i] = tokens[j]; tokens[j] = temp; break; }
        else if (*tokens[i] < *tokens[j] && *tokens[j] - *tokens[i] != 32) { break; }
        else if (*tokens[i] == 0 && *tokens[j] != 0) { break; }
        else if (*tokens[j] == 0 && *tokens[i] != 0) { temp = tokens[i]; tokens[i] = tokens[j]; tokens[j] = temp; break; }
        else if (i == j) { break; }
        else { tokens[i] = tokens[i] + 1; tokens[j] = tokens[j] + 1; ++q; }
      }
      tokens[i] = tokens[i] - q; tokens[j] = tokens[j] - q;
    }
  }

  for (i = 0; i < count; ++i) {
    printf(" %s", tokens[i]);
  }

  return 0;
}
