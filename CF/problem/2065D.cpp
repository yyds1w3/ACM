//Thu May 14 03:20:36 PM CST 2026
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
        int n, m;
        std::cin >> n >> m;
        std::vector<std::pair<i64, i64>> a;
        for (int i = 0; i < n; ++i) {
            i64 cur1 = 0;
            i64 cur2 = 0;
            for (int j = 0; j < m; ++j) {
                i64 x;
                std::cin >> x;
                cur1 += x;
                cur2 += 1LL * (m - j) * x;
            }
            a.push_back({cur1, cur2});
        }
        std::sort(a.begin(), a.end());
        // m m-1 
        // 2m 2m-1
        // 3m 3m-1
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            auto [cur1, cur2] = a[i];
            ans += 1LL * m * i * cur1 + cur2;
        }
        std::cout << ans << nl;
    }
}
