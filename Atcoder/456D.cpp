//Sun May  3 12:08:49 PM CST 2026
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

const i64 MOD = 998244353;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<i64> dp(3);
    for (int i = 0; i < n; ++i) {
        int c = s[i] - 'a';
        dp[c] = (dp[0] + dp[1] + dp[2] + 1) % MOD;
    }
    i64 ans = 0;
    for (int i = 0; i < 3; ++i) {
        ans = (ans + dp[i]) % MOD;
    }
    std::cout << ans << nl;
}
