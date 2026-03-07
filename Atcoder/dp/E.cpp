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
const int MAXN = 1e2 + 5;
const int MAXV = 1e5 + 5;
ll w[MAXN], v[MAXN];
ll dp[MAXV];
void solve() {
    int n, W; cin >> n >> W;
    ll mxv = 0;
    rep(i, 1, n) {
        cin >> w[i] >> v[i];
        mxv += v[i]; 
    }
    rep(i, 1, mxv) dp[i] = LINF;
    dp[0] = 0;
    rep(i, 1, n) {
        per(j, mxv, v[i]) {
            if (dp[j-v[i]] != LINF) {
                dp[j] = min(dp[j], dp[j-v[i]] + w[i]);
            }
        }
    }
    per(i, mxv, 0) if(dp[i] <= W) {cout << i << nl; return;}
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
