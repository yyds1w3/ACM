//Thu May 28 12:43:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<i64> a(n);
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<std::vector<i64>> dp(n, std::vector<i64>(2)); //dp[u][0] -> mn dp[u][1] -> mx
        dp[0][0] = dp[0][1] = a[0];
        auto dfs = [&](auto self, int u, int fa) -> void {
            for (int v : adj[u]) if (v != fa) {
                dp[v][0] = std::min(a[v]-dp[u][1], a[v]);
                dp[v][1] = std::max(a[v]-dp[u][0], a[v]);
                self(self, v, u);
            }
        };
        dfs(dfs, 0, 0);
        for (int i = 0; i < n; ++i) std::cout << dp[i][1] << " ";
        std::cout << nl;
    }
}
