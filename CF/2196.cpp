//Fri Aug  7 04:29:38 PM CST 2026
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define nl "\n"
using i64 = long long;

#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[10000][2];
int id[10000];
int up[10000];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    while (std::cin >> n) {
        memset(dp, 0, sizeof(dp));
        memset(id, -1, sizeof(id));
        memset(up, 0, sizeof(up));
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (int u = 1; u < n; ++u) {
            int v, w;
            std::cin >> v >> w;
            v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        auto dfs1 = [&](auto self, int u, int fa) -> void {
            for (auto [v, w] : adj[u]) if (v != fa) {
                self(self, v, u);
                int len = dp[v][0] + w;
                if (len > dp[u][0]) {
                    id[u] = v;
                    dp[u][1] = dp[u][0];
                    dp[u][0] = len;
                }else if (len > dp[u][1]) {
                    dp[u][1] = len;
                }
            }
        };
        dfs1(dfs1, 0, 0);
        auto dfs2 = [&](auto self, int u, int fa) -> void {
            for (auto [v, w] : adj[u]) if (v != fa) {
                if (v == id[u]) {
                    up[v] = w + std::max(up[u], dp[u][1]);
                }else {
                    up[v] = w + std::max(up[u], dp[u][0]);
                }
                self(self, v, u);
            }
        };
        dfs2(dfs2, 0, 0);
        for (int i = 0; i < n; ++i) {
            std::cout << std::max(dp[i][0], up[i]) << nl;
        }
    }
}

