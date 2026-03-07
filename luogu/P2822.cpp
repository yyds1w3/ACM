#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e3 + 5;
int C[MAXN][MAXN];
int pre[MAXN][MAXN];
int k, n, m;
void init() {
    C[0][0] = 1;
    rep(i, 1, 2000) {
        C[i][0] = 1;
        rep(j, 1, i) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % k;
        }
    }
    rep(i, 1, 2000) {
        rep(j, 1, 2000) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (j <= i && C[i][j] == 0);
        }
    }
}
void solve() {
    cin >> n >> m;
    cout << pre[n][m] << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt >> k;
    init();
    while (tt--) solve();
}
