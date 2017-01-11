#include <algorithm>
#include <cstdio>

#define MAXN 100

using namespace std;

int w[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d\n", &w[i]);

    sort(w, w + n);

    int cnt = 0, st = 0, end = n - 1;
    while(st <= end) {
      int top = w[end--], mult = 1;
      while(st <= end && top * mult < 50) { st++; mult++; }
      if(top * mult >= 50) cnt++;
    }
    printf("Case #%d: %d\n", tc, cnt);
  }
  return 0;
}
