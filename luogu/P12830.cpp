//Fri Jun  5 04:03:29 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int MOD = 1e9 + 7;
i64 dp[2025][4];
void solve() {
    // 5 * 5 * 3 * 3 * 3 * 3;
    dp[0][0] = 8;
    dp[0][1] = 2;
    dp[0][2] = 4;
    dp[0][3] = 1;
    for (int i = 1; i < 2025; ++i) {
        dp[i][0] = (dp[i - 1][3] * 8) % MOD;
        dp[i][1] = ((dp[i - 1][2] + dp[i - 1][3]) * 2) % MOD;
        dp[i][2] = ((dp[i - 1][1] + dp[i - 1][3]) * 4) % MOD;
        dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
    }
    std::cout << std::accumulate(dp[2024], dp[2024] + 4, 0LL) % MOD << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
