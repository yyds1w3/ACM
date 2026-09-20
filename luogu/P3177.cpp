//Sun Aug  9 03:06:35 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
i64 dp[2000][2001];
int sz[2000];
const i64 INF = 2e18;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int i = 2; i <= k; ++i) dp[u][i] = -INF;
        dp[u][0] = dp[u][1] = 0;
        sz[u] = 1;
        for (auto [v, w] : adj[u]) if (v != fa) {
            self(self, v, u);
            for (int i = std::min(k, sz[u] + sz[v]); i >= 0; --i) {
                for (int j = std::max(0, i - sz[u]); j <= std::min(sz[v], i); ++j) { // i - j <= sz[u]
                    int h1 = k - j, h2 = j;
                    int b1 = n - sz[v] - h1, b2 = sz[v] - h2;
                    dp[u][i] = std::max(dp[u][i], dp[u][i - j] + dp[v][j] + w * (1LL * h1 * h2 + b1 * b2));
                }
            } 
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, 0);
    std::cout << dp[0][k] << nl;
}
