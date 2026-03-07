#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 10007;
const int MAXN = 2e5 + 5;
ll C[1005][1005];
void init() {
    C[0][0] = 1;
    rep(i, 1, 1000) {
        C[i][0] = 1;
        rep(j, 1, i) C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
    }
}
ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}
void solve() {
    int a, b, k, n, m; cin >> a >> b >> k >> n >> m;
    init();
    cout << C[k][n] * qpow(a, n, MOD) % MOD * qpow(b, m, MOD) % MOD << nl;
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
