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
int cnt[MAXN];
void solve() {
    int n; cin >> n;
    int mx = 0;
    rep(i, 1, n) {
        int x; cin >> x;
        cnt[x]++;
        mx = max(mx, x);
    }
    int ans = 1;
    rep(g, 2, mx) {
        int tot = 0;
        for (int j = g; j <= mx; j += g) {
            tot += cnt[j]; 
        }
        ans = max(ans, tot);
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
