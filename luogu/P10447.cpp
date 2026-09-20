//Tue Jul 14 02:46:08 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int INF = 1e9;
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> w(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> w[i][j];
        }
    }
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, INF));
    dp[1][0] = 0;
    for (int i = 1; i < 1 << n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                for (int k = 0; k < n; ++k) {
                    if (k != j && ((i >> k) & 1)) {
                        dp[i][j] = std::min(dp[i][j], dp[i ^ (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    int ans = dp[(1 << n) - 1][n - 1];
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
