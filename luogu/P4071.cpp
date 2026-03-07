#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll fact[MAXN];
ll invfact[MAXN];
ll D[MAXN];
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
    }else {
        exgcd(b, a % b, y, x);
        y -= a/b * x;
    }
}
ll inv(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}
ll C(ll n, ll m) {
    return fact[n] * invfact[n-m] % MOD * invfact[m] % MOD;
}
void solve() {
    ll n, m; cin >> n >> m;
    cout << C(n, m) * D[n-m] % MOD << nl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    fact[0] = 1;
    rep(i, 1, 1000000) fact[i] = fact[i-1] * i % MOD; 
    invfact[1000000] = inv(fact[1000000], MOD);
    per(i, 999999, 0) invfact[i] = invfact[i+1] * (i+1) % MOD;
    ll sum_k = 0;
    rep(i, 0, 1000000) {
        ll term = invfact[i];
        if (i % 2 == 1) sum_k = (sum_k - term + MOD) % MOD; // i:1 sum_k:0 i:2 sum_k=inv(2)....
        else sum_k = (sum_k + term + MOD) % MOD;
        D[i] = fact[i] * sum_k % MOD;

    }
    while (tt--) solve();
}
