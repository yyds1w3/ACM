//Fri May 29 06:13:25 PM CST 2026
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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(3));
    // dp 0 休息 1 健身 2 比赛
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = std::max({dp[i][0], dp[i][1], dp[i][2]});
        if (a[i] & 1) {
            dp[i + 1][1] = std::max(dp[i][0] + 1, dp[i][2] + 1);
        }
        if ((a[i] >> 1) & 1) {
            dp[i + 1][2] = std::max(dp[i][0] + 1, dp[i][1] + 1);
        }
        mx = std::max(mx, *std::max_element(dp[i + 1].begin(), dp[i + 1].end()));
    }
    std::cout << n - mx << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t = 1;
    while (t--) {
        solve();
    }
}
