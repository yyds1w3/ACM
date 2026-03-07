#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (ll)e; ++i)
#define per(i,e,s) for (ll i = e; i >= (ll)s; --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 5e3 + 5;
void solve() {
    int l, n; cin >> l >> n;
    int mn = 0, mx = 0;
    rep(i, 1, n) {
        int x; cin >> x;
        mn = max(mn, min(l+1-x, x));
        mx = max(mx, max(l+1-x, x));
    }
    cout << mn << " " << mx << nl;
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
