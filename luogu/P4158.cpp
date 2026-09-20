//Tue Jul 28 08:14:40 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector<std::string> s(n);
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<std::vector<int>> pi(n, std::vector<int>(m + 1));

    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        for (int j = 0; j < m; ++j) {
            a[i][j] = s[i][j] - '0';
            pi[i][j + 1] = pi[i][j] + a[i][j];
        }
    }
    auto f = [&](int i, int l, int r) -> int {
        int k = pi[i][r] - pi[i][l - 1];
        return std::max(k, r - l + 1 - k);
    };
    
    std::vector<int> dp(t + 1);
    for (int i = 0; i < n; ++i) {
        std::vector<std::vector<int>> dpp(m + 1, std::vector<int>(m + 1));

        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= j; ++k) {
                for (int p = k - 1; p < j; p++) {
                    dpp[j][k] = std::max(dpp[j][k], dpp[p][k - 1] + f(i, p + 1, j));
                }
            }
        }
        for (int v = t; v >= 0; --v) {
            for (int x = 1; x <= std::min(m, v); ++x) {
                dp[v] = std::max(dp[v], dp[v - x] + dpp[m][x]);
            }
        }
    }
    std::cout << dp[t] << nl;
    
}
