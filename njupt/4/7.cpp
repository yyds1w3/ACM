#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

ll dp[5001]; // 100*99/2. mx_w
void solve() {
    ll n, k;
    cin >> n >> k;
    for (int v = 2; v <= n; ++v){
        ll w = v * (v - 1) / 2;
        for (ll j = w; j <= k; ++j){
            dp[j] = min(dp[j], dp[j - w] + v);
        }
    }
    cout << (dp[k] <= n ? "Yes\n" : "No\n");
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
