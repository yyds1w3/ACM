//Fri Aug  7 08:04:37 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[100][201][2];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, K;
    while (std::cin >> n >> K) {
        std::vector<int> a(n);
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        auto dfs = [&](auto self, int u, int fa) -> void {
            for (int i = 0; i <= K; ++i) {
                dp[u][i][0] = dp[u][i][1] = a[u];
            }
            for (int v : adj[u]) if (v != fa) {
                self(self, v, u);
                
                for (int j = K; j >= 0; --j) {
                    for (int k = 1; k <= j; ++k) {
                        if (k >= 2) dp[u][j][0] = std::max(dp[u][j][0], dp[u][j-k][0] + dp[v][k-2][0]);
                        if (k >= 2) dp[u][j][1] = std::max(dp[u][j][1], dp[u][j-k][1] + dp[v][k-2][0]);
                        if (k >= 1) dp[u][j][1] = std::max(dp[u][j][1], dp[u][j-k][0] + dp[v][k-1][1]);
                    }
                }
            }
        };
        dfs(dfs, 0, 0);
        std::cout << std::max(dp[0][K][0], dp[0][K][1]) << nl;
    }
}
