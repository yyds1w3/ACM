//Sun Aug  9 04:10:29 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[10000][20];
const int INF = 1e9;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i){
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int i = 1; i < 20; ++i) dp[u][i] = i;
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            for (int i = 1; i < 20; ++i) {
                int tmp = INF;
                for (int j = 1; j < 20; ++j) {
                    if (i == j) continue;
                    tmp = std::min(tmp, dp[v][j]);
                }
                dp[u][i] += tmp;
            }
        }
    };
    dfs(dfs, 0, 0);
    std::cout << *std::min_element(dp[0] + 1, dp[0] + 20) << nl;
}
