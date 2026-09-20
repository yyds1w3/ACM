//Sat Aug  8 08:19:53 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[100000][21];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> c(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) std::cin >> c[i];
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        dp[u][0] = c[u];
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            for (int i = 1; i <= k; ++i) {
                dp[u][i] += dp[v][i-1];
            }
        }
    };
    dfs1(dfs1, 0, 0);
    auto dfs2 = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) if (v != fa) {
            for (int i = k; i >= 1; --i) {
                dp[v][i] += dp[u][i-1] - (i >= 2 ? dp[v][i-2] : 0);
            }
            self(self, v, u);
        }
    };
    dfs2(dfs2, 0, 0);
    for (int i = 0; i < n; ++i) {
        std::cout << std::accumulate(dp[i], dp[i] + k + 1, 0) << nl;
    }
}
