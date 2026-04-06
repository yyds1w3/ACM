#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
struct Edge {
    int v, w;
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector adj(n, std::vector<Edge>());
    for (int i = 0; i < n - m; ++i) {
        int k, v, w;
        std::cin >> k;
        for (int j = 0; j < k; ++j) {
            std::cin >> v >> w;
            v--;
            adj[i].push_back({v, w}); 
        }
    }
    std::vector<int> money(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> money[i];
    }
    std::vector dp(n, std::vector<int>(n + 1, -1e9));
    std::vector<int> sz(n);
    auto dfs = [&] (auto self, int u) -> void {
        if (u >= n - m) {
            sz[u] = 1;
            dp[u][0] = 0;
            dp[u][1] = money[u - (n - m)];
        }else {
            sz[u] = 0;
            dp[u][0] = 0;
            for (auto [v, w] : adj[u]) {
                self(self, v);
                for (int i = sz[u] + sz[v]; i >= 1; --i) {
                    for (int k = std::max(1, i - sz[u]); k <= std::min(i, sz[v]); ++k) {
                        dp[u][i] = std::max(dp[u][i], dp[u][i - k] + dp[v][k] - w);
                    }
                }
                sz[u] += sz[v];
            }
        }
    };
    dfs(dfs, 0);
    int ans = 0;
    for (int i = n; i >= 0; --i) {
        if (dp[0][i] >= 0) {
            ans = i;
            break;
        }
    }
    std::cout << ans << nl;
}
