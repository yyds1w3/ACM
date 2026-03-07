#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define ctz(x) __builtin_ctz(x)
#define ctzll(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(x)
#define clzll(x) __builtin_clzll(x)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
int lg2(int x) {return 31 - clz(x);}
int lg2(ll x) {return 63 - clzll(x);}
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
struct st {
    ll mon, fac;
    bool operator<(const st& other) const {return mon < other.mon;}
}a[MAXN];
void solve() {
    int n, d; cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i].mon >> a[i].fac;
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    ll mx = 0;
    for (int l = 1, r = 1; r <= n; ++r) {
        ans += a[r].fac;
        while (a[r].mon >= a[l].mon + d) {
            ans -= a[l].fac;
            l++;
        }               
        mx = max(mx, ans);
    }
    cout << mx << nl;
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
