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
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 5e5 + 1;
ll a[MAXN];
ll cnt[MAXN];
ll sum;
ll ans;
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {cin >> a[i]; sum += a[i];}
    if (sum % 3 != 0) {cout << 0 << endl; return;}
    sum /= 3;
    ll now = 0;
    for (int i = 1; i <= n; ++i) {
        now += a[i];
        if (now == sum) cnt[i] = 1;
    }
    for (int i = 2; i <= n; ++i) cnt[i] += cnt[i-1];
    now = 0;
    for (int i = n; i >= 3; --i) {
        now += a[i];
        if (now == sum) ans += cnt[i-2];
    }
    cout << ans << endl;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
