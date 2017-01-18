#include <algorithm>

#define MAXN 300
#define MAXM 300

using namespace std;

int c[MAXN][MAXM];

int dp[MAXN + 1][MAXN + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m; scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        scanf("%d", &c[i][j]);
      }

      sort(c[i], c[i] + m);
      for(int j = 1; j < m; j++) {
        c[i][j] += c[i][j - 1];
      }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
      for(int j = i; j <= n; j++) {
        for(int k = 0; k <= m && j + k <= n; k++) {
          int cost = k == 0 ? 0 : c[i][k - 1];

          dp[i + 1][j + k] = min(
            dp[i + 1][j + k],
            dp[i][j] + cost + k * k);
        }
      }
    }
    printf("Case #%d: %d\n", tc, dp[n][n]);
  }
  return 0;
}
