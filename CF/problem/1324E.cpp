#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e3 + 5;
ll dp[MAXN][MAXN]; // dp[h][time] = good次数
int a[MAXN]; // a_i
void solve() {
    int n, h, l, r; cin >> n >> h >> l >> r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < h; ++j) {
            if (dp[i][j] == -1) continue;
            int t1 = (j + a[i]) % h;
            int c1 = (t1 >= l && t1 <= r) ? 1 : 0;
            dp[i+1][t1] = max(dp[i+1][t1], dp[i][j] + c1);
            int t2 = (j + a[i] - 1) % h;
            int c2 = (t2 >= l && t2 <= r) ? 1 : 0;
            dp[i+1][t2] = max(dp[i+1][t2], dp[i][j] + c2);
        }
    }
    ll ans = 0;
    for (int i = 0; i < h; ++i) ans = max(ans, dp[n][i]);
    cout << ans << nl;
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
