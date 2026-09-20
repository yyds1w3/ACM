//Wed Aug  5 03:49:03 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

const int MOD = 1e6 + 3;
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    int m = s[0].size();
    std::vector<std::vector<int>> match(m, std::vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '?') {
                for (int c = 0; c < 26; ++c) {
                    match[j][c] |= (1 << i);
                }
            } else {
                match[j][s[i][j] - 'a'] |= (1 << i);
            }
        }
    }
    std::vector<std::vector<int>> dp(2, std::vector<int>(1 << n, 0));
    int val = 0;
    dp[val][(1 << n) - 1] = 1;

    for (int i = 0; i < m; ++i, val ^= 1) {
        std::fill(dp[val ^ 1].begin(), dp[val ^ 1].end(), 0);
        for (int j = 0; j < (1 << n); ++j) {
            if (dp[val][j] == 0) continue;
            for (int p = 0; p < 26; ++p) {
                int nxt = j & match[i][p];
                dp[val ^ 1][nxt] = (dp[val ^ 1][nxt] + dp[val][j]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j < (1 << n); ++j) {
        if (__builtin_popcount(j) == k) {
            ans = (ans + dp[val][j]) % MOD;
        }
    }
    
    std::cout << ans << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
