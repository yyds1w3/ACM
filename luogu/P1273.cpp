//Fri Aug  7 02:37:39 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const int INF = 1e9;
int dp[3000][3001];
int sz[3000];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    std::vector<int> money(m);
    for (int u = 0; u < n - m; ++u) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            int v, w;
            std::cin >> v >> w;
            v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> money[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = -INF;
        }

    }
    
    auto dfs = [&](auto self, int u, int fa) -> void {
        if (u >= n - m) {
            sz[u] = 1;
            dp[u][1] = money[u-(n-m)];
            return;
        }
        for (auto [v, w] : adj[u]) if (v != fa) {
            self(self, v, u);
            for (int j = sz[u] + sz[v]; j >= 1; --j) {
                for (int k = std::max(1, j - sz[u]); k <= std::min(j, sz[v]); ++k) { // k <= sz[v], j - k <= sz[u]
                        dp[u][j] = std::max(dp[u][j], dp[u][j-k] + dp[v][k] - w);
                }
            }
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, 0);
    for (int j = m; j >= 0; --j) {
        if (dp[0][j] >= 0) {
            std::cout << j << nl;
            return 0;
        }
    }

}
