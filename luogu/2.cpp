//Fri Jul 31 08:06:41 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
int dp[101][200][200]; // dp[i][x][y];
int mp[101][11];
int sta[200];
int cntLine(int i, int x) {
    int ans = 0;
    for (int j = 0; j < 10; ++j) {
        if ((x >> j) & mp[i][j]) ans++;
    }
    return ans;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int M = 0;
    for (int i = 0; i < (1 << 10); ++i) {
        if (!((i & (i >> 2)) || (i & (i << 2)))) sta[M++] = i;
    }
    int n, m;
    while (std::cin >> n >> m) {
        memset(dp, 0, sizeof(dp));
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cin >> mp[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < M; ++j) {
                int x = sta[j];
                for (int k = 0; k < M; ++k) {
                    int y = sta[k];
                    if (i == 0) {
                        dp[i][j][k] = cntLine(i, x);
                        ans = std::max(ans, dp[i][j][k]);
                        continue;
                    }
                    if ((x & (y >> 1)) || (x & (y << 1))) continue;
                    int tmp = 0;
                    for (int p = 0; p < M; ++p) {
                        int z = sta[p];
                        if ((y & (z >> 1)) || (y & (z << 1))) continue;
                        if (x & z) continue;
                        tmp = std::max(tmp, dp[i - 1][k][p]);
                    }
                    dp[i][j][k] = tmp + cntLine(i, x);
                    ans = std::max(ans, dp[i][j][k]);
                }
            }
        }
        std::cout << ans << nl;
    }
}
