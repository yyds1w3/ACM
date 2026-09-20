//Thu May 28 01:00:33 PM CST 2026
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
    i64 x, y, k;
    std::cin >> x >> y >> k;
    i64 g = std::gcd(x, y);
    i64 u = x / g;
    i64 v = y / g;
    auto get_min_ops = [&](i64 val) -> int {
        if (val == 1) return 0;
        std::vector<i64> divs;
        for (i64 i = 1; i * i <= val; ++i) {
            if (val % i == 0) {
                divs.push_back(i);
                if (i * i != val) {
                    divs.push_back(val / i);
                }
            }
        }
        std::sort(divs.begin(), divs.end());
        int sz = divs.size();
        std::vector<int> dp(sz, 1e9);
        dp[sz - 1] = 0;
        for (int i = sz - 1; i >= 0; --i) {
            if (dp[i] == 1e9) continue;
            for (int j = i - 1; j >= 0; --j) {
                if (divs[i] % divs[j] == 0 && divs[i] / divs[j] <= k) {
                    dp[j] = std::min(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[0] == 1e9 ? -1 : dp[0];
    };
    
    int ans1 = get_min_ops(u);
    int ans2 = get_min_ops(v);
    
    if (ans1 == -1 || ans2 == -1) {
        std::cout << -1 << nl;
    } else {
        std::cout << ans1 + ans2 << nl;
    }
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
