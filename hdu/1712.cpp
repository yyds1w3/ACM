//Mon Jul 27 07:44:55 PM CST 2026
#include <iostream>
#include <vector>
#include <algorithm>
#define nl '\n'
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    while (true) {
        int n, m;
        std::cin >> n >> m;
        if (n == 0 && m == 0) break;
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                std::cin >> a[i][j];
            }
        }
        std::vector<int> dp(m + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= 0; --j) {
                for (int k = 0; k <= j; ++k) {
                    dp[j] = std::max(dp[j - k] + a[i][k], dp[j]);
                }
            }
        }
        std::cout << dp[m] << nl;
    }
}
