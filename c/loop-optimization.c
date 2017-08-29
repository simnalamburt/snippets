//
// 함수 fn 안에 있는 O(n)짜리 루프문이, 불과 `-O1`짜리 옵션에서도 최적화되어
// O(1)이 된다. 아래와 같이 테스트하면 된다.
//
//     clang -O1 loop-optimization.s
//     ./a.out
//
// Clang 3.0 (2011-12-01)에서도 재현됨을 확인하였다. 그 이전버전으로는 못해봄.
//
// Reference:
//   https://godbolt.org/g/8QXXJT
//   https://twitter.com/summerlight00/status/902273076309630976
//
#include <stdio.h>

int fn(int y, int x) {
  int sum = 0;
  for (int i = y; i != x; ++i) {
    sum += i * i;
  }
  return sum;
}

int main() {
  int a, b;
  printf("두 정수를 입력해주세요. (예시: 100 200)\n> ");
  scanf("%d%d", &a, &b);
  printf("결과: %d\n", fn(a, b));
}
