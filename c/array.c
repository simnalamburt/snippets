#include <stdio.h>

int main() {
  int array[10] = { 1, 2, 3, [6] = 101, 102, 103 };
  printf("array[10] = { %d", array[0]);
  for (int i = 1; i < 10; ++i) { printf(", %d", array[i]); }
  printf(" }\n");

  void* p1 = array + 1;
  void* p2 = &array[1];
  return 0;
}
