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
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    ll cnt = 0;
    for (int i = 1; i <= n - 1; ++i) {
        ll pre = (i == 1) ? 1 : 3 * qpow(4, i - 2);
        ll mid = 4;
        ll suf = (i == n-1) ? 1 : 3 * qpow(4, n-i-2);
        cnt += pre * mid * suf;
    }
    cout << cnt;

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
