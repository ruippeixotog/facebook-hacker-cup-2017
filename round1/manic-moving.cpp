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

#define MAXN 100
#define MAXK 5000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef long double ld;

int dist[MAXN][MAXN];
int s[MAXK], d[MAXK];

int dp[MAXK + 1][4];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m, k; scanf("%d %d %d\n", &n, &m, &k);

    memset(dist, 0x3f, sizeof(dist));
    for(int i = 0; i < n; i++)
      dist[i][i] = 0;

    for(int i = 0; i < m; i++) {
      int a, b, g; scanf("%d %d %d\n", &a, &b, &g);
      a--; b--;
      dist[a][b] = min(dist[a][b], g);
      dist[b][a] = min(dist[b][a], g);
    }

    for(int i = 0; i < k; i++) {
      scanf("%d %d\n", &s[i], &d[i]);
      s[i]--; d[i]--;
    }

    for(int k = 0; k < n; k++) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          if(dist[i][j] > dist[i][k] + dist[k][j]) {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
      }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < k; i++) {
      dp[i][1] = min(
        dp[i][1],
        dp[i][0] + dist[i == 0 ? 0 : d[i - 1]][s[i]]);

      dp[i + 1][0] = min(
        dp[i + 1][0],
        dp[i][1] + dist[s[i]][d[i]]);

      dp[i + 1][0] = min(
        dp[i + 1][0],
        dp[i][2] + dist[i == 0 ? 0 : d[i - 1]][d[i]]);

      if(i < k - 1) {
        dp[i][3] = min(
          dp[i][3],
          dp[i][1] + dist[s[i]][s[i + 1]]);

        dp[i][3] = min(
          dp[i][3],
          dp[i][2] + dist[i == 0 ? 0 : d[i - 1]][s[i + 1]]);

        dp[i + 1][2] = min(
          dp[i + 1][2],
          dp[i][3] + dist[s[i + 1]][d[i]]);
      }
    }

    printf("Case #%d: %d\n", tc, dp[k][0] > INF ? -1 : dp[k][0]);
  }
  return 0;
}
