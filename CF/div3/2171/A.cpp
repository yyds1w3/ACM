#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using i128 = __int128;
using namespace std;
#define nl "\n"
void solve() {
    int n; cin >> n;
    if (n % 2 == 1) {cout << 0 << nl; return;}
    vector<int> dp(n+1);
    dp[2] = 1; dp[4] = 2;
    for (int i = 6; i <= n; i += 2) {
        dp[i] = dp[i-2] + 1;
        dp[i] = dp[i-4] + 1;
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
    cin >> tt;
    while (tt--) solve();
}
