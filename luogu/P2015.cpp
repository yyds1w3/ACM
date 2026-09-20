//Fri Aug  7 01:39:14 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[100][101];
int sz[100];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto [v, w] : adj[u]) if (v != fa) {
            self(self, v, u);
            sz[u] += sz[v] + 1;
            for (int j = std::min(q, sz[u]); j >= 1; j--) {
                for (int k = 0; k <= std::min(sz[v], j - 1); ++k) {
                    dp[u][j] = std::max(dp[u][j], dp[u][j-k-1] + dp[v][k] + w);
                }
            }
        }
    };
    dfs(dfs, 0, 0);
    std::cout << dp[0][q] << nl;
}
