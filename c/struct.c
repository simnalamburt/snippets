#include <stdio.h>

// 24bytes
struct Student {
  const char *name; // 8bytes
  double gpa;       // 8bytes
  long student_id;  // 8bytes

  // No method
  // No inherience
  // No overloading
  // No overriding
  // Nothing
};

int main() {
  struct Student hyeonkim = {
    "김지현",
    4.3,
    201311392,
  };

  // Original form
  printf("name: %s\n", hyeonkim.name);
  printf("gpa:  %lf\n", hyeonkim.gpa);
  printf("id:   %ld\n", hyeonkim.student_id);
  printf("\n");

  long address_of_hyeonkim = &hyeonkim;

  // type of pointer should be same with original data type
  struct Student *pointer_of_hyeonkim = address_of_hyeonkim;

  // WRONG!!! But compile will be silently success without error
  int *wrong_pointer = address_of_hyeonkim;

  // Retrieving the address and declaring the pointer at the same time
  struct Student *pointer = &hyeonkim;

  /* JAVA
  printf("name: %s\n", pointer.name);
  printf("gpa:  %lf\n", pointer.gpa);
  printf("id:   %ld\n", pointer.student_id);
  printf("\n");
  */

  // Reading structs with pointer
  printf("name: %s\n", (*pointer).name);
  printf("gpa:  %lf\n", (*pointer).gpa);
  printf("id:   %ld\n", (*pointer).student_id);
  printf("\n");

  // Reading structs with pointer in simpler form
  printf("name: %s\n",  pointer->name);
  printf("gpa:  %lf\n", pointer->gpa);
  printf("id:   %ld\n", pointer->student_id);
  printf("\n");
}
