#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 300
#define MAXM 300
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

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
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
      for(int j = i; j <= n; j++) {
        int cost = 0;
        for(int k = 0; k <= m && j + k <= n; k++) {
          dp[i + 1][j + k] = min(
            dp[i + 1][j + k],
            dp[i][j] + cost + k * k);

          if(k < m) cost += c[i][k];
        }
      }
    }
    printf("Case #%d: %d\n", tc, dp[n][n]);
  }
  return 0;
}
