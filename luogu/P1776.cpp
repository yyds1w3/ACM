//Thu Apr 16 09:59:20 PM CST 2026
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
    int n, W;
    std::cin >> n >> W;
    std::vector<i64> dp(W + 1);
    for (int i = 0; i < n; ++i) {
        i64 v, w, m;
        std::cin >> v >> w >> m;
        for (int k = 1; k <= m; k *= 2) {
            m -= k;
            i64 weight = w * k;
            i64 val = v * k;
            for (int j = W; j >= weight; --j) {
                dp[j] = std::max(dp[j], dp[j - weight] + val);
            }
        }
        if (m > 0) {
            i64 weight = w * m;
            i64 val = v * m;
            for (int j = W; j >= weight; --j) {
                dp[j] = std::max(dp[j], dp[j - weight] + val);
            }
        }
    }
    std::cout << dp[W] << nl;
}
