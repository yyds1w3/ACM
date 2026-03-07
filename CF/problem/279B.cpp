#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
ll pre[MAXN];

void solve() {
    ll n, t; cin >> n >> t;
    rep(i, 1, n) {
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    int ans = 0;
    for (int l = 1, r = 0; r <= n; ++r) {
        while (pre[r] - pre[l-1] > t) l++;
        ans = max(ans, r - l + 1);
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
    // cin >> tt;
    while (tt--) solve();
}
