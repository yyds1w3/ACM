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
ll a[201];
void solve() {
    ll n, k; cin >> n >> k;
    ll base = 0;
    ll temp;
    if (n > 200){
        base = n - 200; // n == 300 -> base = 100 ==> 1
        for (int i = 1; i <= n - 200; ++i) cin >> temp;// 1 ~ 100 not used
        n = 200;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll ans = -1e18;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            ans = max(ans, (base + i) * (base + j) - k * (a[i] | a[j]));
        }
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
