#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
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
    ll n, k; cin >> n >> k;
    for (int i = 0; i < 32; ++i) {
        ll l = k * qpow(2, i) - (qpow(2, i) - 1);
        ll r = k * qpow(2, i) + (qpow(2, i) - 1);
        if (l <= n && n <= r) {cout << i << nl; break;}
        if (l > n) {cout << "-1" << nl; break;}
    }
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
