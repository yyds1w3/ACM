//Thu Jun 18 01:40:29 PM CST 2026
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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> h(n), x(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }
    auto check = [&](int times) -> int {
        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            int need = (h[i] - 1) / times + 1;
            if (need > m) continue;
            v.push_back({x[i] - (m - need), 1});
            v.push_back({x[i] + (m - need) + 1, -1});
        }
        std::sort(v.begin(), v.end());
        int sum = 0;
        for (auto [pos, val] : v) {
            sum += val;
            if (sum >= k) {
                return true;
            }
        }
        return false;
    };
    int l = 1, r = 2e9;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            r = mid;
        }else {
            l = mid + 1;
        }
    }
    if (l != 2e9) {
        std::cout << l << nl;
    }else {
        std::cout << -1 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
