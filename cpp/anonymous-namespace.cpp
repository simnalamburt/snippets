#include <iostream>

// Old fassioned
static int global1 = 10;

// Yeah
namespace { int global2 = 20; }

int main() {
  std::cout << global1 + global2 << std::endl;
  return 0;
}
