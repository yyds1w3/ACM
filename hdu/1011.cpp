//Fri Aug  7 08:27:48 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[100][101];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    while (std::cin >> n >> m) {
        if (n == -1 && m == -1) {
            break;
        }
        std::vector<int> a(n), b(n);
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (m == 0) {
            std::cout << 0 << nl;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        auto dfs = [&](auto self, int u, int fa) -> void {
            int cost = (a[u] + 19) / 20;
            for (int i = cost; i <= m; ++i) {
                dp[u][i] = b[u];
            }
            for (int v : adj[u]) if (v != fa) {
                self(self, v, u);
                for (int j = m; j >= cost; --j) {
                    for (int k = 1; k <= j - cost; ++k) {
                        dp[u][j] = std::max(dp[u][j], dp[u][j-k] + dp[v][k]);
                    }
                }
            }
        };
        dfs(dfs, 0, 0);
        std::cout << dp[0][m] << nl;
    }
}
