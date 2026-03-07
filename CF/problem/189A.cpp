#include <bits/stdc++.h>
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
const int MAXN = 1e5 + 5;
int dp[MAXN];
void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    fill(dp + 1,dp + 1 + n, -INF);
    dp[0] = 0;
    rep(i, 1, n) {
        if (i >= a && dp[i-a] != -INF) {dp[i] = max(dp[i-a] + 1, dp[i]);}
        if (i >= b && dp[i-b] != -INF) {dp[i] = max(dp[i-b] + 1, dp[i]);}
        if (i >= c && dp[i-c] != -INF) {dp[i] = max(dp[i-c] + 1, dp[i]);}
    }
    cout << dp[n] << nl;
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
