//Wed May 27 06:39:57 PM CST 2026
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
        int n;
        std::cin >> n;
        i64 x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        i64 dx = x1 - x2;
        i64 dy = y1 - y2;
        std::vector<i64> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        // tot = mx + other;
        // tot - 2 * other == mx - other
        // tot - 2(tot - mx) == 2 * mx - tot;
        i64 tot = std::accumulate(a.begin(), a.end(), 0LL);
        i64 mn = std::max(0LL, 2 * *std::max_element(a.begin(), a.end()) - tot);
        i64 target = dx * dx + dy * dy;
        std::vector<i64> de = {tot, mn, target};
        if (tot * tot >= target && mn * mn <= target) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
