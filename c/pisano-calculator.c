#include <stdio.h>
#include <stdint.h>

typedef uint64_t u64;

int main() {
  u64 MOD;
  scanf("%lld", &MOD);

  if (MOD < 2) {
    printf("2 이상의 자연수를 입력해야합니다.\n");
    return -1;
  }

  u64 a = 1, b = 1, c;
  printf("fibo(0) %% %llu = 0\n", MOD);
  printf("fibo(1) %% %llu = 1\n", MOD);
  for (u64 i = 2;; ++i) {
    if (i % 10000000 == 0) {
      printf("fibo(%llu) %% %llu = %llu\n", i, MOD, b);
    }
    if (a == 0 && b == 1) {
      printf("\n%llu로 나눴을때의 피사노 주기: %llu\n", MOD, i - 1);
      return 0;
    }

    c = (a + b) % MOD;
    a = b;
    b = c;
  }
}
