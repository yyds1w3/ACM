//Tue Aug  4 04:54:08 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 

const int MOD = 1e8;
int dp[2][1<<12];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            std::cin >> x;
            if (x == 0) a[i] |= (1 << j);
        }
    }
    std::vector<int> valid;
    for (int i = 0; i < (1 << m); ++i) {
        if (!(i & (i << 1))) valid.push_back(i);
    }

    dp[0][0] = 1;
    int val = 1;
    for (int i = 1; i <= n; ++i, val ^=1) {
        memset(dp[val], 0, sizeof(dp[val]));

        for (int j : valid) { if (j & a[i]) continue;
            for (int k : valid) { if (k & a[i-1]) continue;
                if (j & k) continue;
                dp[val][j] = (dp[val][j] + dp[val ^ 1][k]) % MOD;
            }
        }
    }
    i64 ans = 0;
    for (int j : valid) {
        ans = (ans + dp[val^1][j]) % MOD;
    }
    std::cout << ans << nl;
}
