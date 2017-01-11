#include <cstdio>
#include <cmath>

#define R 50

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int p, x, y; scanf("%d %d %d\n", &p, &x, &y);

    int dist2 = (x - R) * (x - R) + (y - R) * (y - R);
    double angle = atan2(x - R, y - R) / (2 * M_PI);
    if(angle < 0) angle++;

    printf("Case #%d: %s\n", tc,
           dist2 > R * R || angle * 100 > p ? "white" : "black");
  }
  return 0;
}
