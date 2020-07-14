#include <stdio.h>

static const char* LEFT_HALF = ""; // "▎"

int main() {
  //
  // 16 color
  //
  printf("16 color:\n");
  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 8; ++x) {
      int color = x + 8*y;
      printf("\x1b[48;5;%dm  ", color);
    }
    printf("\x1b[0m\n");
  }
  printf("\n");

  //
  // 256 color
  //
  printf("256 color:\n");
  for (int g = 0; g < 6*3; ++g) {
    for (int R = 0; R < 6; ++R) {
      for (int B = 0; B < 6; ++B) {
        int G = g / 3;
        int show = g % 3 == 1;
        int color = 16 + 36*R + 6*G + B;
        int fg = color <= 21 ? 246 : 16;
        printf("\x1b[38;5;%d;48;5;%dm", fg, color);
        if (show) {
          printf(" %03d ", color);
        } else {
          printf("     ");
        }
        printf("");
      }
      printf("\x1b[0m ");
    }
    printf("\n");
  }
  printf("\n");

  //
  // 24-bit color
  //
  printf("24-bit color:\n");
  for (int g = 0; g < 6*3; ++g) {
    for (int r = 0; r < 6; ++r) {
      for (int b = 0; b < 6*5*2; b += 2) {
        int R = 256 * r / 6;
        int G = 256 * g / 18;
        int B0 = 256 * b / 48;
        int B1 = 256 * (b+1) / 48;
        printf("\x1b[38;2;%d;%d;%d;48;2;%d;%d;%dm%s", R, G, B0, R, G, B1, LEFT_HALF);
        printf("");
      }
      printf("\x1b[0m ");
    }
    printf("\n");
  }
  printf("\n");



  //
  // 16 color
  //
  int color_codes[4] = {0, 8, 7, 15};
  int counts[4] = {7, 8, 8, 3};
  printf("    16 color: ");
  for (int i = 0; i < 4; ++i) {
    printf("\x1b[48;5;%dm", color_codes[i]);
    for (int j = 0; j < counts[i]; ++j) {
      printf("     ");
    }
  }
  printf("\x1b[0m\n");

  //
  // 256 color
  //
  printf(
    "   256 color: "
    "\x1b[48;5;16m 016 ");
  for (int color = 232; color < 256; ++color) {
    int fg = color >= 245 ? 238 : 249;
    printf("\x1b[38;5;%d;48;5;%dm %03d ", fg, color, color);
  }
  printf(
    "\x1b[48;5;231m 231 "
    "\x1b[0m\n");

  //
  // 24-bit color
  //
  printf(
    "24-bit color: "
    "\x1b[48;2;0;0;0m ");
  for (int a = 0; a < 256; a += 2) {
    int b = a + 1;
    printf("\x1b[38;2;%d;%d;%d;48;2;%d;%d;%dm%s", a, a, a, b, b, b, LEFT_HALF);
  }
  printf("\x1b[48;2;255;255;255m "
    "\x1b[0m\n");
}
