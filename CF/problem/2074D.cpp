//Mon Jun  1 01:19:45 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> x(n), r(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i];
    }
    std::map<int, int> s;
    for (int i = 0; i < n; ++i) {
        for (int j = x[i] - r[i]; j <= x[i] + r[i]; ++j) {
            int dx = x[i] - j;
            i64 dy2 = 1LL * r[i] * r[i] - 1LL * dx * dx;
            int y = (int)std::sqrt(dy2);
            while (1LL * y * y > dy2) y--; 
            while (1LL * (y + 1) * (y + 1) <= dy2) y++;
            s[j] = std::max(s[j], y);
        }
    }
    i64 ans = 0;
    for (auto [x, y] : s) {
        ans += 2 * y + 1;
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
