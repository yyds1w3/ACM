//Thu May 28 02:04:20 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) std::cin >> x[i] >> y[i];
    if (n == 1) {
        std::cout << 1 << nl;
        return;
    }
    std::vector<int> sx = x, sy = y;
    std::sort(sx.begin(), sx.end());
    std::sort(sy.begin(), sy.end());
    i64 ans = 2e18;
    for (int i = 0; i < n; ++i) {
        int xl, xr, yd, yt;
        if (x[i] == sx[0]) {
            xl = sx[1];
        }else {
            xl = sx[0];
        }
        if (x[i] == sx[n - 1]) {
            xr = sx[n - 2];
        }else {
            xr = sx[n - 1];
        }
        if (y[i] == sy[0]) {
            yd = sy[1];
        }else {
            yd = sy[0];
        }
        if (y[i] == sy[n - 1]) {
            yt = sy[n - 2];
        }else {
            yt = sy[n - 1];
        }
        int w = xr - xl + 1;
        int h = yt - yd + 1;

        if (n - 1 < 1LL * w * h) {
            ans = std::min(ans, 1LL * w * h);
        }else {
            ans = std::min(ans, 1LL * w * h + std::min(w, h));
        }
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
