//Mon Jun  1 07:13:17 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<std::vector<int>> dp(n / 2, std::vector<int>(2));
    // 无后效性
    // dp[i][] 考虑[0, i], 不考虑i+1
    for (int i = 1; i < n / 2; ++i) {
        int pl = a[i - 1], pr = a[n - i];
        int cl = a[i], cr = a[n - i - 1];
        int c00 = (pl == cl) + (pr == cr);
        int c10 = (pr == cl) + (pl == cr);
        int c01 = (pl == cr) + (pr == cl);
        int c11 = (pr == cr) + (pl == cl);
        dp[i][0] = std::min(dp[i - 1][0] + c00, dp[i - 1][1] + c10);
        dp[i][1] = std::min(dp[i - 1][0] + c01, dp[i - 1][1] + c11);
    }
    int ans = std::min(dp[n / 2 - 1][0], dp[n / 2 - 1][1]);
    if (n % 2 == 0) {
        ans += (a[n / 2 - 1] == a[n / 2]);
    }else {
        ans += ((a[n / 2] == a[n / 2 - 1]) + (a[n / 2] == a[n / 2 + 1]));
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
