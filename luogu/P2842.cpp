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
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
const int MAXW = 1e4 + 5;
int a[MAXN];
int dp[MAXW];
int n, w;
int f(int now) {
    if (now == 0) return 0;
    if (dp[now] != INF) return dp[now];
    rep(i, 1, n) {
        if (now >= a[i])
        dp[now] = min(dp[now], 1 + f(now - a[i])); 
    }
    return dp[now];
}
void solve() {
    cin >> n >> w;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, w) dp[i] = INF;
    cout << f(w) << nl;
};

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
