//Fri May 22 04:53:42 PM CST 2026
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
    int n, sx, sy, ex, ey;
    std::cin >> n >> sx >> sy >> ex >> ey;
    std::vector<int> x(n), y(n);
    std::map<int, std::vector<int>> m;
    for (int i = 0; i < n; ++i) std::cin >> x[i];
    for (int i = 0; i < n; ++i) {
        std::cin >> y[i];
        m[x[i]].push_back(y[i]);
    }
    i64 dp[2] = {0};
    int j[2] = {sy, sy};
    for (auto &[x, v] : m) {
        int mn = *std::min_element(v.begin(), v.end());
        int mx = *std::max_element(v.begin(), v.end());
        int len = mx - mn;
        i64 nxt0 = std::min(dp[0] + std::abs(mx - j[0]) + len, dp[1] + std::abs(mx - j[1]) + len);
        i64 nxt1 = std::min(dp[0] + std::abs(mn - j[0]) + len, dp[1] + std::abs(mn - j[1]) + len);
        dp[0] = nxt0;
        dp[1] = nxt1;
        j[0] = mn;
        j[1] = mx;
    }
    i64 ans = std::min(dp[0] + std::abs(ey - j[0]), dp[1] + std::abs(ey - j[1])) + ex - sx;
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
