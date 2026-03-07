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
void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
    }else {
        exgcd(b, a%b, y, x);
        y -= a/b * x;
    }
}
void solve() {
    ll x, y, m, n, l; cin >> x >> y >> m >> n >> l;
    // (m-n)*t + k*l = y-x
    ll A = m - n;
    ll B = l;
    ll C = y-x;
    if (A < 0) {A = -A; C = -C;}
    ll t, k;
    exgcd(A, B, t, k);
    ll g = gcd(A, B);
    if (C % g != 0) cout << "Impossible" << nl;
    else {
        ll mod = B / g; // x解的周期性
        ll ft = t * (C / g); // ax + by = g; 这是exgcd的解， 故要扩大C/g倍
        ll ans = (ll)((ft % mod + mod) % mod);
        cout << ans << nl;
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
