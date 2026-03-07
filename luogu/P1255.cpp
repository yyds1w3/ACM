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
const int MOD = 1e9 + 7;
const int MAXN = 5e3 + 5;
int dp[2][MAXN];
int temp[MAXN];
void add() {
    rep(i, 1, MAXN - 1) temp[i] = dp[1][i];
    rep(i, 1, MAXN - 1) {
        dp[1][i] += dp[0][i];
        if (dp[1][i] >= 10) {
            dp[1][i+1] += dp[1][i] / 10;
            dp[1][i] %= 10;
        }
    }
    rep(i, 1, MAXN - 1) dp[0][i] = temp[i];
}
int wei() {
    per(i, MAXN-1, 1) if (dp[1][i] != 0) return i;
    return 0;
}
void solve() {
    int n; cin >> n;
    dp[0][1] = dp[1][1] = 1;
    rep(i, 2, n) add();
    int w = wei();
    per(i, w, 1) cout << dp[1][i];
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
