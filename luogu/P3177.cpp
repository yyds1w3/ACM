#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
struct Edge {
    int to, w;
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, k;
    std::cin >> n >> k;
    std::vector adj(n, std::vector<Edge>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    std::vector dp(n, std::vector<i64>(k + 1, -1));
    std::vector<int> sz(n, 0);
    auto dfs = [&] (auto self, int u, int fa) -> void {
        sz[u] = 1;
        dp[u][0] = 0;
        if (k >= 1) dp[u][1] = 0;
        for (auto [v, w] : adj[u]) {
            if (v == fa) continue;
            self(self, v, u);
            int limit = std::min(k, sz[u] + sz[v]);
            std::vector<i64> nxt(limit + 1, -1);
            for (int i = 0; i <= std::min(k, sz[u]); ++i) { // u占的黑点
                if (dp[u][i] == -1) continue;
                for (int j = 0; j <= std::min(k - i, sz[v]); ++j) { // v占的黑点
                    if (dp[v][j] == -1) continue;
                    i64 cost = 1LL * w * (1LL * j * (k - j) + 1LL * (sz[v] - j) * (n - k - sz[v] + j));
                    nxt[i + j] = std::max(nxt[i + j], dp[u][i] + dp[v][j] + cost); 
                }
            }
            sz[u] += sz[v];
            for (int i = 0; i <= limit; ++i) {
                dp[u][i] = nxt[i];
            }
        } 
    };
    dfs(dfs, 0, -1);
    std::cout << dp[0][k] << nl;
}
