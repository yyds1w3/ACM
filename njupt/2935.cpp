//Mon Jul 27 02:19:37 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
int dp[2][301][301][3];
i64 ans[301][301];
const int MOD = 1e9 + 7;
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    int tot = 0;
    if (s[0] == 'a') dp[0][0][0][0] = 1;
    else if (s[0] == 'b') dp[0][0][0][1] = 1;
    else if (s[0] == 'c') dp[0][0][0][2] = 1;
    else {
        tot++;
        dp[0][1][0][0] = 1;
        dp[0][0][1][1] = 1;
        dp[0][0][0][2] = 1;
    }
    for (int i = 1; i < n; ++i) {
        memset(dp[1], 0, sizeof(dp[1]));
        if (s[i] == 'a') {
            for (int j = 0; j <= 300; ++j) {
                for (int k = 0; k <= 300; ++k) {
                    dp[1][j][k][0] = (dp[0][j][k][1] + dp[0][j][k][2]) % MOD;
                }
            }
        }else if (s[i] == 'b') {
            for (int j = 0; j <= 300; ++j) {
                for (int k = 0; k <= 300; ++k) {
                    dp[1][j][k][1] = (dp[0][j][k][0] + dp[0][j][k][2]) % MOD;
                }
            }
        }else if (s[i] == 'c') {
            for (int j = 0; j <= 300; ++j) {
                for (int k = 0; k <= 300; ++k) {
                    dp[1][j][k][2] = (dp[0][j][k][0] + dp[0][j][k][1]) % MOD;
                }
            }
        }else{
            tot++;
            for (int j = 0; j <= 300; ++j) {
                for (int k = 0; k <= 300; ++k) {
                    if (j > 0) dp[1][j][k][0] = (dp[0][j - 1][k][1] + dp[0][j - 1][k][2]) % MOD;
                    if (k > 0) dp[1][j][k][1] = (dp[0][j][k - 1][0] + dp[0][j][k - 1][2]) % MOD;
                    if (tot - j - k > 0) dp[1][j][k][2] = (dp[0][j][k][0] + dp[0][j][k][1]) % MOD;
                }
            }
        }
        for (int j = 0; j <= 300; ++j) {
            for (int k = 0; k <= 300; ++k) {
                for (int l = 0; l <= 2; ++l) {
                    dp[0][j][k][l] = dp[1][j][k][l];
                }
            }
        }
    }
    for (int j = 0; j <= 300; ++j) {
        for (int k = 0; k <= 300; ++k) {
            ans[j][k] = (dp[0][j][k][0] + dp[0][j][k][1] + dp[0][j][k][2]) % MOD;
        }
    }
    for (int j = 0; j <= 300; ++j) {
        for (int k = 1; k <= 300; ++k) {
            ans[j][k] = (ans[j][k] + ans[j][k - 1]) % MOD;
        }
    }
    while (q--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x = std::min(x, tot);
        y = std::min(y, tot);

        i64 res = 0;
        for (int j = 0; j <= x; ++j) {
            int mnk = tot - j - z;
            int mxk = std::min(y, tot - j);
            if (mnk <= mxk) {
                if (mnk > 0) {
                    res = ((res + ans[j][mxk] - ans[j][mnk - 1] % MOD) + MOD) % MOD;
                }else {
                    res = (res + ans[j][mxk]) % MOD;
                }
            }
        }
        std::cout << res << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
