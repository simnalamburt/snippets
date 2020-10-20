#include <stdio.h>

// Anonimous union in return type
union {
  int binary;
  float ieee754;
} getPI() {
  return (typeof(getPI())){ .ieee754 = 3.141592 };
}

// Anonimous union in parameter type
void foo(union { int binary; float ieee754; } param) {
}

int main() {
  // Anonimous union declaration
  union {
    int binary;
    float ieee754;
  } var;

  // Compound literal
  var = (typeof(var)){ .ieee754 = 3.141592 };

  // Anonimous union initialization
  union {
    int binary;
    float ieee754;
  } init = { .ieee754 = 3.141592 };

  // Storing returned anonoymous union
  typeof(getPI()) another = getPI();

  printf("%x\n", var.binary);
}
