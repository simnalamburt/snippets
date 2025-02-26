#include <stdbool.h>
#include <stdio.h>

char DAT_140003000[] = {
  0xac, 0xf3, 0x0c, 0x25, 0xa3, 0x10, 0xb7, 0x25,
  0x16, 0xc6, 0xb7, 0xbc, 0x07, 0x25, 0x02, 0xd5,
  0xc6, 0x11, 0x07, 0xc5, 0x00,
};

int main() {
  char input[21] = {};
  for (int idx = 0; idx < 21; ++idx) {
    for (int c = 0; c < 256; ++c) {
      if ((char)(c * -5) == DAT_140003000[idx]) {
        input[idx] = c;
        printf("%s\n", input);
        break;
      }
    }
  }
}
