#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
#define repp(i,e,s) for (int i = e; i >= s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
ll f(ll x) {
    if (x == 0) return 0;
    return 64 - __builtin_clzll(x);
}
void solve() {
    int n; cin >> n;
    ll ans = 0;
    ll tp = -INF;
    rep(i, 1, n) {
        ll x; cin >> x;
        tp = max(tp, x);
        ans = max(ans, f(tp - x));
    }
    cout << ans << nl;
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
