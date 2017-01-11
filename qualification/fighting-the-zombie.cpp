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

#define MAXS 10
#define MAXX 20
#define MAXY 20

using namespace std;

typedef long long ll;
typedef long double ld;

ld dp[MAXX + 1][MAXX * MAXY + 1];

int x[MAXS], y[MAXS], z[MAXS];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int h, s; scanf("%d %d\n", &h, &s);
    for(int i = 0; i < s; i++) {
      scanf("%dd%d", &x[i], &y[i]);

      int uz;
      if(scanf("+%d", &uz) == 1) z[i] = uz;
      else if(scanf("-%d", &uz) == 1) z[i] = -uz;
      else z[i] = 0;
    }

    ld best = 0.0;
    for(int i = 0; i < s; i++) {
      memset(dp, 0, sizeof(dp));
      dp[0][0] = 1.0;

      for(int j = 0; j < x[i]; j++) {
        for(int k = j; k <= j * y[i]; k++) {
          for(int l = 1; l <= y[i]; l++) {
            dp[j + 1][k + l] += dp[j][k] / (ld) y[i];
          }
        }
      }

      ld prob = 0.0;
      for(int j = max(x[i], h - z[i]); j <= x[i] * y[i]; j++) {
        prob += dp[x[i]][j];
      }
      best = max(best, prob);
    }

    printf("Case #%d: %.10Lf\n", tc, best);
  }
  return 0;
}
