#include <bits/stdc++.h>
#include <iomanip>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 3e3 + 5;
double p[MAXN];
double dp[MAXN][MAXN]; 
void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> p[i];
    dp[0][0] = 1;
    rep(i, 1, n) {
        rep(j, 0, i-1) {
            dp[i][j+1] += dp[i-1][j] * p[i];
            dp[i][j] += dp[i-1][j] * (1 - p[i]);
        }
    }
    double ans = 0;
    rep(i, (n+1)/2, n) ans += dp[n][i];
    cout << setprecision(10) << fixed << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
