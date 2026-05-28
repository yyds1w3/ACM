//Fri Apr 17 02:43:32 PM CST 2026
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
const int MOD = 1e5 + 3;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, k;
    std::cin >> n >> k;
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= std::min(i, k); ++j) {
            dp[i] += dp[i - j];
            dp[i] %= MOD;
        }
    }
    std::cout << dp[n] << nl;
}
