//Sat Aug  8 03:17:09 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[16000];
const int INF = 2147483647;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> dp[i];
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = -INF;
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            if (dp[v] > 0) {
                dp[u] += dp[v];
            }
            ans = std::max(ans, dp[u]);
        }
    };
    dfs(dfs, 0, 0);
    std::cout << ans << nl;
}
