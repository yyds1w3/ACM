#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
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
    std::vector dp(n, std::vector<int>(q + 1, -1));
    std::vector<int> sz(n);
    // 合并子树的后序遍历
    auto dfs = [&] (auto self, int u, int fa) -> void{
        dp[u][0] = 0;
        for (auto [v, w] : adj[u]) {
            if (v == fa) continue;
            self(self, v, u);
            sz[u] += sz[v] + 1;
            
            for (int i = std::min(q, sz[u]); i > 0; --i) { // 确保合并v子树的时候，dp[i-k-1]是未合并子树的最佳状态
                for (int k = 0; k <= std::min(i - 1, sz[v]); ++k) {
                    if (dp[u][i - k - 1] != -1 && dp[v][k] != -1) {
                        dp[u][i] = std::max(dp[u][i], dp[v][k] + dp[u][i - k - 1] + w);
                    }
                }
            }
        }   
    };
    dfs(dfs, 0, -1);
    std::cout << dp[0][q] << nl;
}
