//Sun Aug  9 04:41:43 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[100000][101][2][2];
int nxt[101][2][2];
int sz[100000];
const int MOD = 1e9 + 7;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        dp[u][0][0][0] = dp[u][1][1][0] = 1;
        sz[u] = 1;
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            memset(nxt, 0, sizeof(nxt));
            for (int i = 0; i <= std::min(sz[u] + sz[v], k); ++i) {
                for (int j = std::max(i - sz[u], 0); j <= std::min(sz[v], i); ++j) {
                    for (int cu = 0; cu < 2; ++cu) for (int mu = 0; mu < 2; ++mu) {
                        for (int cv = 0; cv < 2; ++cv) for (int mv = 0; mv < 2; ++mv) {
                            if (cu == 0 && mv == 0) continue;
                            nxt[i][cu][mu|cv] = (nxt[i][cu][mu|cv] + 1LL * dp[u][i-j][cu][mu] * dp[v][j][cv][mv]) % MOD;
                        }
                    }
                }
            }
            for (int i = 0; i <= 100; ++i) for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k) {
                dp[u][i][j][k] = nxt[i][j][k];
            }
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, 0);
    std::cout << (dp[0][k][0][1] + dp[0][k][1][1]) % MOD << nl;
}
