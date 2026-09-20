//Fri May 29 06:40:13 PM CST 2026
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
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    // 0 x 1 1 2 2;
    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(3));
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = *std::max_element(dp[i].begin(), dp[i].end());
        dp[i + 1][1] = std::max(dp[i][0], dp[i][2]) + a[i];
        dp[i + 1][2] = std::max(dp[i][0], dp[i][1]) + b[i];
    }
    std::cout << std::max(dp[n][1], dp[n][2]) << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
