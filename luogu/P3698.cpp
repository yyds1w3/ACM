//Sat Aug  8 08:48:10 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[100][101][2];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int i = 0; i <= m; ++i) {
            dp[u][i][0] = dp[u][i][1] = 1;
        }
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            for (int i = m; i >= 1; --i) {
                for (int j = 0; j <= i; ++j) {
                    if (i-j-2>=0) dp[u][i][0] = std::max(dp[u][i][0], dp[u][i-j-2][0] + dp[v][j][1]);
                    if (i-j-1>=0) dp[u][i][0] = std::max(dp[u][i][0], dp[u][i-j-1][1] + dp[v][j][0]);
                    if (i-j-2>=0) dp[u][i][1] = std::max(dp[u][i][1], dp[u][i-j-2][1] + dp[v][j][1]);
                }
            }
        }
    };
    dfs(dfs, 0, -1);
    std::cout << std::max(dp[0][m][0], dp[0][m][1]) << nl;
}
