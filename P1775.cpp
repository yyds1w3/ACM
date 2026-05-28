//Fri Apr 17 03:03:55 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i) dp[i][i] = 0;
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            int weight = a[j] - a[i - 1];
            for (int mid = i; mid < j; ++mid) {
                dp[i][j] = std::min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + weight);
            }
        }
    }
    std::cout << dp[1][n] << nl;
}
