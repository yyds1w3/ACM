//Thu Aug  6 04:45:56 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[250][250];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, a[i]);
        dp[i][i] = a[i];
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                if (dp[i][k] == dp[k+1][j] && dp[i][k] != 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i][k] + 1);
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
    }
    std::cout << ans << nl;

}
