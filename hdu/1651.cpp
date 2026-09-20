//Tue Jul 28 02:03:27 PM CST 2026
#include <iostream>
#include <vector>
#include <algorithm>
#define nl "\n"
using i64 = long long;
const int INF = 1e9;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, INF));
    for (int len = 1; len <= 2; ++len) {
        for (int i = 0; i + 1 < n; ++i) {
            dp[i][i + len - 1] = 0;
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + a[k] * a[i] * a[j]);
            }
        }
    }
    std::cout << dp[0][n - 1];
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
