//Tue Jul 28 03:20:31 PM CST 2026
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
int dp[2][201][201][2];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::string a, b;
    std::cin >> a >> b;
    int val = 1;
    dp[0][0][0][0] = dp[1][0][0][0] = 1;
    for (int i = 1; i <= n; ++i, val ^= 1) {
        for (int j = 1; j <= m; ++j) {
            for (int p = 1; p <= k; ++p) {
                if (a[i - 1] == b[j - 1]) {
                    dp[val][j][p][0] = (dp[val ^ 1][j][p][0] + dp[val ^ 1][j][p][1]) % MOD;
                    dp[val][j][p][1] = ((dp[val ^ 1][j-1][p-1][0] + \
                        dp[val ^ 1][j-1][p-1][1]) % MOD + dp[val ^ 1][j-1][p][1]) % MOD;
                }else {
                    dp[val][j][p][0] = (dp[val ^ 1][j][p][0] + dp[val ^ 1][j][p][1]) % MOD;
                    dp[val][j][p][1] = 0;
                }
            }
        }
    }
    std::cout << (dp[n & 1][m][k][0] + dp[n & 1][m][k][1]) % MOD << nl;
}
