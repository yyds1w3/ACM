//Fri Aug  7 09:25:43 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[201][202];
int sz[201];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;
        std::vector<std::vector<int>> adj(n + 1);
        std::vector<int> a(n + 1);
        for (int u = 1; u <= n; ++u) {
            int v;
            std::cin >> v >> a[u];
            adj[v].push_back(u);
        }
        memset(dp, 0, sizeof(dp));
        auto dfs = [&](auto self, int u) -> void {
            sz[u] = 1;
            for (int i = 1; i <= m; ++i) dp[u][i] = a[u];
            for (int v : adj[u]) {
                self(self, v);
                for (int j = sz[u] + sz[v]; j >= 2; --j) {
                    for (int k = 0; k <= std::min(j-1, sz[v]); ++k) {
                        dp[u][j] = std::max(dp[u][j], dp[u][j-k] + dp[v][k]);
                    }
                }
                sz[u] += sz[v];
            }
        };
        dfs(dfs, 0);
        std::cout << dp[0][m + 1] << nl;
    }

}
