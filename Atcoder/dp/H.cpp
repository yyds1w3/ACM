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
const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
char a[MAXN][MAXN];
ll dp[MAXN][MAXN];
void solve() {
    int H, W; cin >> H >> W;
    rep(i, 1, H) {
        rep(j, 1, W) {
            cin >> a[i][j];
        }
    }
    dp[0][1] = 1;
    rep(i, 1, H) {
        rep(j, 1, W) {
            if (a[i][j] == '.') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            else dp[i][j] = 0;
        }
    }
    cout << dp[H][W];

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
