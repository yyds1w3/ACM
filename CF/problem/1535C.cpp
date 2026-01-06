#include <bits/stdc++.h>
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

void solve() {
    string s; cin >> s;
    int dp0 = 0, dp1 = 0;
    int n_dp0 = 0, n_dp1 = 0;
    ll ans = 0;
    for (char c : s) {
        if (c == '0') {
            n_dp0 = dp1 + 1;
            n_dp1 = 0;
        }else if (c == '1') {
            n_dp1 = dp0 + 1;
            n_dp0 = 0;
        }else {
            n_dp0 = dp1 + 1;
            n_dp1 = dp0 + 1;
        }
        dp0 = n_dp0;
        dp1 = n_dp1;
        ans += max(dp0, dp1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
