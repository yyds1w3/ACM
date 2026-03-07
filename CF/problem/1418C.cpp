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
const int MAXN = 2e5 + 5;
int a[MAXN];
int dp[MAXN][2];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = INF;
    }
    dp[0][0] = 0; dp[0][1] = INF;
    rep(i, 0, n-1) {
        if (dp[i][0] != INF) {
            dp[i+1][1] = min(dp[i+1][1], dp[i][0] + a[i+1]);
            if (i + 2 <= n) dp[i+2][1] = min(dp[i+2][1], dp[i][0] + a[i+1] + a[i+2]);
        }
        if (dp[i][1] != INF) {
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]);
            if (i + 2 <= n) dp[i+2][0] = min(dp[i+2][0], dp[i][1]);
        }
    }
    cout << min(dp[n][0], dp[n][1]) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
