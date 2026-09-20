//Thu Aug  6 07:23:26 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[201][201];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n - 1; ++i) {
        dp[i][i+1] = a[i] * a[i + 1] * a[(i + 1) % (2 * n) + 1];
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= 2 * n; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j; ++k) {
                dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[k+1][j] + a[i] * a[k+1] * a[j%(2*n)+1]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = std::max(ans, dp[i][i+n-1]);
    }
    std::cout << ans << nl;
}
