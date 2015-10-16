//
// 모 해 ACM ICPC 지역예선의 D 문제
//
// 입력 예시
//
//     3
//     3 4
//     6 2
//     3 9
//

#include <stdio.h>

void print(size_t x, size_t y) {
  printf("(%lu,%lu)\n", x, y);
}

int main() {
  size_t count;
  scanf("%lu", &count);

  for (size_t _ = 0; _ < count; ++_) {
    size_t width, height;
    scanf("%lu %lu", &width, &height);
    printf("1\n");

    print(0, 0);
    for (size_t y = 0; y < height; ++y) {
      if (y % 2 == 0) {
        for (size_t x = 1; x < width; ++x) { print(x, y); }
      } else {
        for (size_t x = width - 1; x > 0; --x) { print(x, y); }
      }
    }

    for (size_t y = height - 1; y > 0; --y) {
      print(0, y);
    }
  }

  return 0;
}
