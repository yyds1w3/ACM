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
ll a[MAXN], b[MAXN];
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
void solve() {
    int n; cin >> n;
    ll M = 1;
    rep(i, 1, n) {
        cin >> a[i] >> b[i];
        M *= a[i];
    }
    ll ans = 0;
    rep(i, 1, n) {
        ll m_i = M / a[i];
        ll im_i = inv(m_i, a[i]);
        lll term = (lll)b[i] * m_i * im_i;
        ans = (ans + term) % M;
    }
    cout << (ll)ans << nl;




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
