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
int a[MAXN];
ll suf[MAXN + 1];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    suf[n+1] = 0;
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i+1] - a[i];
    }
    ll ans = -0x3f3f3f3f;
    ll pre = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, pre + suf[i + 1]);
        if (i == 1) pre += a[i];
        else pre += abs(a[i]);
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
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
