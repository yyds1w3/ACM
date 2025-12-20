#include <bits/stdc++.h>
#include <cstring>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
ll a[121][121];
ll dp[121];
void solve() {
    ll n, mx = -0x3f3f3f3f;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            a[i][j] = a[i-1][j] + a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int k = i; k <= n; ++k){
            memset(dp, 0, sizeof(dp));
            for (int j = 1; j <= n; ++j){
                ll val = a[k][j] - a[i-1][j];
                dp[j] = max(val, dp[j-1] + val);
                mx = max(dp[j], mx);
            }
        }
    }
    cout << mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
