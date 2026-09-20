//Fri Jul 31 08:47:53 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
const int INF = 0x3f3f3f3f;
int bit[11] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int tri[59049][10];
int g[10][10];
int dp[10][59049];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    for (int i = 0; i < bit[10]; ++i) {
        int t = i;
        for (int j = 0; j < 10; ++j) {
            tri[i][j] = t % 3;
            t /= 3;
        }
    }

    int n, m;
    while (std::cin >> n >> m) {
        memset(g, 0x3f, sizeof(g));
        for (int i = 0; i < n; ++i) g[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            std::cin >> u >> v >> c;
            u--, v--;
            if (g[u][v] > c) g[u][v] = g[v][u] = c;
        }
        int ans = INF;
        memset(dp, 0x3f, sizeof(dp));
        for (int j = 0; j < n; ++j) dp[j][bit[j]] = 0;
        for (int i = 1; i < bit[n]; ++i) {
            bool ok = true;
            for (int j = 0; j < n; ++j) {
                if (tri[i][j] == 0) {
                    ok = false;
                    continue;
                }
                int l = i - bit[j];
                for (int k = 0; k < n; ++k) {
                    if (tri[l][k] > 0) {
                        dp[j][i] = std::min(dp[j][i], dp[k][l] + g[k][j]);
                    }
                }
            }
            if (ok) {
                for (int j = 0; j < n; ++j) {
                    ans = std::min(ans, dp[j][i]);
                }
            }
        }
        if (ans == INF) {
            std::cout << -1 << nl;
        }else {
            std::cout << ans << nl;
        }
    }
}
