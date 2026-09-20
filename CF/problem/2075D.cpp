//Thu May 28 03:35:29 PM CST 2026
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
const i64 INF = 2e18;
std::vector<std::vector<i64>> dp(63, std::vector<i64>(63, INF));
void init() {
    dp[0][0] = 0;
    for (int k = 1; k <= 20; ++k) {
        for (int i = 62; i >= 0; --i) {
            for (int j = 62; j >= 0; --j) {
                if (i >= k && dp[i - k][j] != INF) {
                    dp[i][j] = std::min(dp[i][j], dp[i - k][j] + (1LL << k));
                }
                if (j >= k && dp[i][j - k] != INF) {
                    dp[i][j] = std::min(dp[i][j], dp[i][j - k] + (1LL << k));
                }
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    init();
    int t;
    std::cin >> t;
    while (t--) {
        i64 x, y;
        std::cin >> x >> y;
        i64 ans = INF;
        for (int i = 0; i < 63; ++i) {
            for (int j = 0; j < 63; ++j) {
                if ((x >> i) == (y >> j)) {
                    ans = std::min(ans, dp[i][j]);
                }
            }
        }
        if (ans != INF) {
            std::cout << ans << nl;
        }else {
            std::cout << -1 << nl;
        }
    }
}
