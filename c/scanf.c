#include <stdio.h>

int main(void) {
  printf("Type somthing: ");

  char str1[256], str2[256], ch;
  scanf("%255s%c%255s", str1, &ch, str2);

  printf("\n");
  printf("String 1 : \"%s\"\n", str1);
  printf("Char     : '%c'\n", ch);
  printf("String 2 : \"%s\"\n", str2);
  printf("\n");

  return 0;
}

// Type somthing: asdasd asdasd
//
// String 1 : "asdasd"
// Char     : ' '
// String 2 : "asdasd"
