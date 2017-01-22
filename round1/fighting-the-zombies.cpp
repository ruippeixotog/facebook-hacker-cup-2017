#include <algorithm>
#include <cstdio>
#include <vector>

#define MAXN 50

using namespace std;

int n, r;
int x[MAXN], y[MAXN];

vector<pair<int, int>> rect;

bool inside(int i, int x0, int y0) {
  return x[i] >= x0 && x[i] <= x0 + r && y[i] >= y0 && y[i] <= y0 + r;
}

int zombiesIn(int x0, int y0, int x1, int y1) {
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(inside(i, x0, y0) || inside(i, x1, y1)) cnt++;
  }
  return cnt;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d %d\n", &n, &r);
    for(int i = 0; i < n; i++)
      scanf("%d %d\n", &x[i], &y[i]);

    rect.clear();
    for(int i = 0; i < n; i++) {
      for(int j = i; j < n; j++) {
        rect.push_back({ min(x[i], x[j]), min(y[i], y[j]) });
      }
    }

    int best = 0;
    for(int i = 0; i < rect.size(); i++) {
      for(int j = i; j < rect.size(); j++) {
        best = max(best, zombiesIn(
          rect[i].first, rect[i].second,
          rect[j].first, rect[j].second));
      }
    }
    printf("Case #%d: %d\n", tc, best);
  }
  return 0;
}
