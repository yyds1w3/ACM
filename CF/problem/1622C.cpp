#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
const int MAXN = 2e5 + 1;
ll a[MAXN];
ll pre[MAXN];
void solve() {
    ll n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i];
    ll ans = 1e18;
    if (pre[n] <= k) {
        cout << 0 << "\n";
        return;
    }
    for (ll y = 0; y < n; ++y) {
        ll sum = pre[n - y] + y * a[1];
        if (sum <= k) ans = min(ans, y);
        else ans = min(ans, y + (sum - k - 1) / (y + 1) + 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
