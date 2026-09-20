//Tue Aug  4 04:12:19 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[2][1<<10][1<<10];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;

    std::vector<int> mp(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == 'H') mp[i] |= (1 << j);
        }
    }
    std::vector<int> valid;
    for (int i = 0; i < (1 << m); ++i) {
        if (!((i & (i << 1)) || (i & (i << 2)))) {
            valid.push_back(i);
        }
    }
    
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    int val = 1;
    for (int i = 1; i <= n; ++i, val ^= 1) {
        memset(dp[val], -1, sizeof(dp[val]));
        for (int j : valid) { if (mp[i] & j) continue;
            for (int k : valid) { if (mp[i-1] & k) continue;
                if (j & k) continue;
                for (int kk : valid) {
                    if (j & kk) continue;
                    if (k & kk) continue;
                    if (dp[val^1][k][kk] == -1) continue;
                    dp[val][j][k] = std::max(dp[val][j][k], dp[val^1][k][kk] + __builtin_popcount(j));
                }
            }
        }
    }

    int ans = -1;
    for (int j : valid) {
        for (int k : valid) {
            ans = std::max(ans, dp[val^1][j][k]);
        }
    }
    if (ans == -1) std::cout << 0 << nl;
    else std::cout << ans << nl;
}
