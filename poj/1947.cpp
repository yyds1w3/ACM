//Fri Aug  7 07:21:12 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 

int dp[150][151];
int sz[150];
const int INF = 0x3f3f3f3f;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, p;
    std::cin >> n >> p;
    std::vector<std::vector<int>> adj(n);
    std::vector<bool> isRoot(n, true);
    for (int i = 1; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        isRoot[v] = false;
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (isRoot[i]) {
            root = i;
            break;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    auto dfs = [&](auto self, int u) -> void {
        sz[u] = 1;
        dp[u][1] = 0;
        for (int v : adj[u]) {
            self(self, v);
            for (int j = sz[u] + sz[v]; j >= 1; --j) {
                dp[u][j] = dp[u][j] + 1;
                for (int k = std::max(1, j - sz[u]); k <= std::min(j-1, sz[v]); ++k) {// k <= sz[v] j - k <= sz[u]
                    dp[u][j] = std::min(dp[u][j], dp[u][j-k] + dp[v][k]);
                }
            }
            sz[u] += sz[v];
        }
    };
    dfs(dfs, root);
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (isRoot[i]) {
            ans = std::min(ans, dp[i][p]);
        }else {
            ans = std::min(ans, dp[i][p] + 1);
        }
    }
    std::cout << ans << nl;
    
}
