//Wed Jun 10 10:36:39 PM CST 2026
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
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<std::pair<int, int>> a;
    a.push_back({m, m});
    while (q--) {
        int x;
        std::cin >> x;
        std::vector<std::pair<int, int>> nxt;
        for (auto [l, r] : a) {
            if (l < x) {
                nxt.push_back({l, std::min(r, x - 1) + 1});
            }
            if (r > x) {
                nxt.push_back({std::max(x + 1, l) - 1, r});
            }
            if (l <= x && x <= r) {
                nxt.push_back({1, 1});
                nxt.push_back({n, n});
            }
        }
        a.clear();
        std::sort(nxt.begin(), nxt.end());
        for (auto [l, r] : nxt) {
            if (a.empty() || a.back().second < l) {
                a.push_back({l, r});
            }else {
                a.back().second = r;
            }
        }
        int ans = 0;
        for (auto [l, r] : a) {
            ans += r - l + 1;
        }
        std::cout << ans << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
