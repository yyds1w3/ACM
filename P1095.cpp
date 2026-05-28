//Fri Apr 17 12:00:50 PM CST 2026
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
    int m, s, t;
    std::cin >> m >> s >> t;
    std::vector<int> dp(t + 1);
    for (int i = 1; i <= t; ++i) {
        if (m >= 10) {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        }else {
            dp[i] = dp[i - 1];
            m += 4;
        }
    }
    for (int i = 1; i <= t; ++i) {
        dp[i] = std::max(dp[i], dp[i - 1] + 17);
        if (dp[i] >= s) {
            std::cout << "Yes" << nl << i << nl;
            return 0;
        }
    }
    std::cout << "No" << nl << dp[t] << nl;
    // 先处理一遍只用魔法的
    // 比如0 - 4s在回复魔法， 那么 0-3 肯定是跑步加魔法 > 纯魔法
}
