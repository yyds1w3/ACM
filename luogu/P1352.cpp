//Fri Aug  7 01:52:11 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
int dp[6001][2];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), isRoot(n, true);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[v].push_back(u);
        isRoot[u] = false;
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (isRoot[i]) {
            root = i;
            break;
        }
    }

    auto dfs = [&](auto self, int u) -> void {
        if (adj[u].empty()) {
            dp[u][1] = a[u];
            return;
        }
        int f = 0;
        for (int v : adj[u]) {
            self(self, v);
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
            f += dp[v][0];
        }
        dp[u][1] = std::max(dp[u][1], f + a[u]);
    };

    dfs(dfs, root);
    std::cout << std::max(dp[root][0], dp[root][1]) << nl;

}
