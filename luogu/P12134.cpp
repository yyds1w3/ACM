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
const int MAXN = 1e5 + 5;
int a[MAXN];
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    ll now = 0, ans = LINF;
    sort(a + 1, a + 1 + n);
    rep(i, 2, m) {
        now += a[i] * a[i] - a[i-1] * a[i-1]; 
    }
    int l = 1;
    ans = min(ans, now);
    while (l + m - 1 < n) {
        now += a[l+m] * a[l+m] - a[l+m-1] * a[l+m-1] - a[l+1] * a[l+1] + a[l] * a[l];
        ans = min(ans, now);
        l++;
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
