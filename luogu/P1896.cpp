//Tue Aug  4 07:17:31 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
i64 dp[2][82][1<<9];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, K;
    std::cin >> n >> K;
    std::vector<int> valid;
    for (int i = 0; i < (1 << n); ++i) {
        if (!(i & (i >> 1))) {
            valid.push_back(i);
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int val = 1;
    for (int i = 0; i < n; ++i, val ^= 1) {
        memset(dp[val], 0, sizeof(dp[val]));
        for (int j : valid) {
            int nd = __builtin_popcount(j);
            for (int k : valid) {
                if (j & k) continue;
                if (j & (k >> 1)) continue;
                if (j & (k << 1)) continue;
                for (int g = nd; g <= K; ++g) {
                    dp[val][g][j] += dp[val^1][g-nd][k];
                }
            } 
        }
    }
    i64 ans = 0;
    for (int j : valid) {
        ans += dp[val^1][K][j];
    }
    std::cout << ans << nl;
}
