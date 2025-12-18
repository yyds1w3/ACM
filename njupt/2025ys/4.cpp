#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
const int MAXM = 1e6 + 1;
const int MOD = 998244353;
ll d[MAXM];
ll p[MAXM];
void solve() {
  int n, m, k;
  ll t;
  cin >> n >> m >> k >> t;
  for (int i = 1; i <= m; ++i) {
    cin >> d[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> p[i];
  }
  ll ans = MOD - 1;
  for (int i = 1; i <= n; ++i) {
    debug(ans);
    ll v;
    cin >> v;
    if (i == n) {
      for (int j = 1; j <= m; ++j) {
        if (v > t && v + d[j] <= t) { // kenneg
          ans = ans * p[j] % MOD;
        } else if (v <= t && v + d[j] > t) { // keneng
          ans = ans * (MOD + 1 - p[j]) % MOD;
        }else if (v > t && d[j] > t){
          ans = 0;
        }else{
          ans = ans * (MOD - 1)% MOD;
        }
        debug(ans);
        cout << ans;
        return;
      }
    } else {
      for (int j = 1; j <= m; ++j) {
        if (v <= t && v + d[j] <= t) { // 100tongtuo
          cout << 0;
          return;
        } else if (v <= t && v + d[j] > t) { // kenneg
          ans = ans * p[j] % MOD;
        } else if (v > t && v + d[j] <= t) { // keneng
          ans = ans * (MOD + 1 - p[j]) % MOD;
        }else{
          ans = ans % MOD;
        }
      }
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef LOCAL
  if (fopen("in.txt", "r"))
    freopen("in.txt", "r", stdin);
#endif
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
