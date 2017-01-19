#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 2000
#define MAXR 2000
#define MOD 1000000007

using namespace std;

typedef long long ll;

int r[MAXN];

int cumsum[MAXR + 1];

inline ll madd(ll a, ll b) { return (a + b) % MOD; }
inline ll mmul(ll a, ll b) { return (a * b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

ll minv(ll a) { return mpow(a, MOD - 2); }

vector<ll> _mfactMem(1, 1);
ll mfact(ll a) {
  if(a >= MOD) return 0;
  while(a >= _mfactMem.size())
    _mfactMem.push_back(mmul((ll) _mfactMem.size(), _mfactMem.back()));
  return _mfactMem[a];
}

ll mcomb(ll n, ll k) {
  if (n == 0 && k == 0) return 1;
  ll ni = n % MOD, ki = k % MOD;
  if (ni < ki) return 0;
  ll comb = mmul(mfact(ni), mmul(minv(mfact(ki)), minv(mfact(ni - ki))));
  return mcomb(n / MOD, k / MOD) * comb;
}

int solve(int n, int m) {
  if(n == 1) return m;
  memset(cumsum, 0, sizeof(cumsum));

  int spaces = m - 1, maxR = 0;
  for (int i = 0; i < n; i++) {
    spaces -= r[i] * 2;
    cumsum[r[i]]++;
    maxR = max(maxR, r[i]);
  }
  for (int i = 1; i <= maxR; i++) {
    cumsum[i] += cumsum[i - 1];
  }

  int res = 0;
  if(spaces >= 0) {
    res = (int) madd(res, mmul(mcomb(spaces + n, spaces), mfact(n)));
  }

  for(int side = 1; side <= maxR; side++) {
    int spaces2 = spaces + side;
    if(spaces2 >= 0) {
      res = (int) madd(res, mmul(
        2 * (n - cumsum[side - 1]),
        mmul(mcomb(spaces2 + n - 1, spaces2), mfact(n - 1))));
    }
  }

  for(int left = 1; left <= maxR; left++) {
    for(int right = 1; right <= maxR; right++) {
      int spaces2 = spaces + left + right;

      int leftComb = n - cumsum[left - 1];
      int rightComb = n - cumsum[right - 1];
      (left < right ? leftComb : rightComb)--;

      if(spaces2 >= 0) {
        res = (int) madd(res, mmul(
          mmul(leftComb, rightComb),
          mmul(mcomb(spaces2 + n - 2, spaces2), mfact(n - 2))));
      }
    }
  }
  return res;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m; scanf("%d %d\n", &n, &m);
    for(int i = 0; i < n; i++)
      scanf("%d\n", &r[i]);

    printf("Case #%d: %d\n", tc, solve(n, m));
  }
  return 0;
}
