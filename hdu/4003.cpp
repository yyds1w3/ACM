//Sat Aug  8 11:50:06 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[10000][11];
const int INF = 0x3f3f3f3f;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, s, K;
    while (std::cin >> n >> s >> K) {
        s--;
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        memset(dp, 0, sizeof(dp));
        auto dfs = [&](auto self, int u, int fa) -> void {
            for (auto [v, w] : adj[u]) if (v != fa) {
                self(self, v, u);

                for (int j = K; j >= 0; --j) {
                    int res = dp[u][j] + dp[v][0] + 2 * w;
                    for (int k = 1; k <= j; ++k) {
                        res = std::min(res, dp[u][j-k] + dp[v][k] + k * w);
                    }
                    dp[u][j] = res;
                }
            }
        };
        dfs(dfs, s, s);
        std::cout << dp[s][K] << nl;
    }
}
