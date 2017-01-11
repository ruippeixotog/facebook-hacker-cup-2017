#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int p, x, y; scanf("%d %d %d\n", &p, &x, &y);

    int dist2 = (x - 50) * (x - 50) + (y - 50) * (y - 50);
    double angle = atan2(x - 50, y - 50) / (2 * M_PI);
    if(angle < 0) angle++;

    printf("Case #%d: %s\n", tc,
           dist2 > 50 * 50 || angle * 100 > p ? "white" : "black");
  }
  return 0;
}
