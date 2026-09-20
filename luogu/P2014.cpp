//Sat Aug  8 03:33:35 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[301][301];
int sz[301];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    m++;
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        int k, s;
        std::cin >> k >> s;
        adj[k].push_back(i);
        a[i] = s;
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        dp[u][0] = 0;
        dp[u][1] = a[u];
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            
            for (int i = m; i >= 2; --i) {
                for (int j = 0; j <= i - 1; ++j) {
                    dp[u][i] = std::max(dp[u][i], dp[u][i-j] + dp[v][j]);
                }
            }
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, 0);
    std::cout << dp[0][m] << nl;
}
