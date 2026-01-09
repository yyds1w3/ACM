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
int n, m, k;
void solve() {
    cin >> n >> m >> k;
    int mx = max(k - 1, n - k);
    int mn = min(k - 1, n - k);
    int ans = 0;
    for (int d2 = 0; d2 <= mn; ++d2) {
        for (int d1 = mx; d1 >= d2; --d1) {
            if (d2 + 2 * d1 - 1 <= m) {ans = max(ans, d1 + d2 + 1); break;}
        }
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
