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
const int MAXN = 3e6 + 5;
void ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1;
        y = 0;
    }else {
        ex_gcd(b, a % b, y, x);
        y -= a / b * x;
    }
}
ll inv(ll a, ll m) {
    ll x, y;
    ex_gcd(a, m, x, y);
    return (x % m + m) % m;
}
ll fact[MAXN], invfact[MAXN];
void solve() {
    ll n, p; cin >> n >> p;
    fact[0] = 1;
    rep(i, 1, n) {
        fact[i] = fact[i-1] * i % p;
    }
    invfact[n] = inv(fact[n], p);
    per(i, n-1, 1) invfact[i] = invfact[i+1] * (i+1) % p;
    rep(i, 1, n) {
        ll invi = invfact[i] * fact[i-1] % p;
        cout << invi << nl;
    }
    
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
