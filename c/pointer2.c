#include <stdio.h>

// 64bit CPU
//= 64bit address space
//= [0, 18446744073709551616)

int main() {
  // 4 bytes = 32bits
  int variable = 42;
  printf("variable: %d\n", variable);
  // 0 <= address of 'variable' < 18446744073709551616

  // 8 bytes = 64bits
  //
  // Address without type information
  long address = &variable;

  // long decimal
  printf("long address: %ld\n", address);

  // Pointer is just an address with
  // "type" information of original value
  int* pointer = address;

  printf("int* pointer: %ld\n", pointer);

  // *address = 124;
  *pointer = 124;

  printf("variable: %d\n", variable);
}







