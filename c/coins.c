#include <stdio.h>

int coins[101] = { 0 };
int dp[101][5001] = {{ 0 }};

int main() {
  int count;
  scanf("%d", &count);
  for (int _ = 0; _ < count; ++_) {
    int value, coin_count;
    scanf("%d %d", &value, &coin_count);
    for (int i = 0; i < coin_count; ++i) { scanf("%d", &coins[i]); }

    for (int i = 0; i <= coin_count; ++i) { dp[i][0] = 1; }
    for (int j = 0; j <= value; ++j) { dp[0][j] = 0; }
    for (int i = 1; i <= coin_count; ++i) {
      for (int j = 1; j <= value; ++j) {
        dp[i][j] = j < coins[i - 1] ?
          dp[i - 1][j] :
          (dp[i][j - coins[i - 1]] + dp[i - 1][j]) % 1000000007;
      }
    }

    printf("%d\n", dp[coin_count][value]);
  }

  return 0;
}
