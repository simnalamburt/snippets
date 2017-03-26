#include <stdio.h>

int main() {
  int a = 10;
  int &b = a;
  const int &c = a;

  int *B = &a;
  const int *C = &a;

  auto print = [&]{
    printf("a: %d    b: %d   c : %d   B : %d   C : %d\n",
        a, b, c, *B, *C);
  };

  print();

  a *= 2;
  print();

  a += 3;
  print();

  b -= 5;
  print();

  *B -= 5;
  print();
}
