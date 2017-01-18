#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 100
#define MAXK 5000
#define INF 1000000000

#define EMPTY 0
#define LD_1ST 1
#define DEL_1ST 2
#define LD_2ND 3

using namespace std;

int dist[MAXN][MAXN];
int s[MAXK], d[MAXK];

int dp[MAXK + 1][4];

void update(int fromI, int fromSt, int toI, int toSt) {
  int src, dest;
  switch(fromSt) {
    case LD_1ST: src = s[fromI]; break;
    case LD_2ND: src = s[fromI + 1]; break;
    default: src = fromI == 0 ? 0 : d[fromI - 1];
  }
  switch(toSt) {
    case LD_1ST: dest = s[fromI]; break;
    case LD_2ND: dest = s[fromI + 1]; break;
    default: dest = d[fromI];
  }
  dp[toI][toSt] = min(
    dp[toI][toSt],
    dp[fromI][fromSt] + dist[src][dest]);
}

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
      dist[a][b] = dist[b][a] = min(dist[a][b], g);
    }

    for(int i = 0; i < k; i++) {
      scanf("%d %d\n", &s[i], &d[i]);
      s[i]--; d[i]--;
    }

    for(int l = 0; l < n; l++) {
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
        }
      }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for(int i = 0; i < k; i++) {
      update(i, EMPTY, i, LD_1ST);
      update(i, LD_1ST, i + 1, EMPTY);
      update(i, DEL_1ST, i + 1, EMPTY);

      if(i < k - 1) {
        update(i, LD_1ST, i, LD_2ND);
        update(i, DEL_1ST, i, LD_2ND);
        update(i, LD_2ND, i + 1, DEL_1ST);
      }
    }

    printf("Case #%d: %d\n", tc, dp[k][EMPTY] > INF ? -1 : dp[k][EMPTY]);
  }
  return 0;
}
