//Mon Jul 27 08:16:36 PM CST 2026
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define nl "\n"
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::string s1, s2;
    while (std::cin >> s1 >> s2) {
        int n = s1.size();
        int m = s2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        std::cout << dp[n][m] << nl;
    }
}
