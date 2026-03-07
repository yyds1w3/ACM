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
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
ll phi(ll m) {
    ll res = m;
    for (ll i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            res = res / i * (i - 1);
            while (m % i == 0) m /= i;
        }
    }
    if (m > 1) res = res / m * (m - 1);
    return res;
}
ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void solve() {
    ll a, m;
    scanf("%lld %lld", &a, &m);
    ll phi_m = phi(m);
    ll b = 0;
    bool f = false;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        b = b * 10 + (ch - '0');
        if (b >= phi_m) {
            f = true;
            b %= phi_m;
        }
        ch = getchar();
    }
    if (f == true) b += phi_m;
    printf("%lld\n", qpow(a, b, m));
    // 1. b < phi(m)
    //
    // 2. b >= phi(m)
    //
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
