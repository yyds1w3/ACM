#include <bits/stdc++.h>
#include <queue>
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
void solve() {
    ll n, x; cin >> n >> x;
    ll free = 0;
    ll mx = -LINF;
    rep(i, 1, n) {
        ll a, b, c; cin >> a >> b >> c;
        free += (b-1)*a;
        mx = max(mx, a*b-c);
    }
    if (free >= x) cout << 0 << nl;
    else if (mx <= 0) cout << -1 << nl;
    else cout << (x - free + mx - 1) / mx << nl;
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
