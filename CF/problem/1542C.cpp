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
const int MOD = 1e9 + 7;
void solve() {
    ll n; cin >> n;
    ll ans = n % MOD, Lcm = 1;
    for (ll x = 1;; x++) {
        ll g = gcd(Lcm, x);
        if (Lcm > n / (x / g)) break;
        Lcm = Lcm * (x / g);
        ans = (ans + n / Lcm) % MOD;
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
