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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    std::vector<i64> dp(n);
    std::vector<i64> w(n);
    for (int i = 1; i < n; ++i) {
        int u;
        std::cin >> u;
        u--;
        adj[u].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i];
    }
    auto dfs = [&] (auto self, int u) -> void {
        for (auto v : adj[u]) {
            self(self, v);
        }
        std::sort(adj[u].begin(), adj[u].end(), [&](int x, int y) {
            return dp[x] - w[x] > dp[y] - w[y];
        });
        i64 cur = 0;
        i64 mx = 0;
        for (int v : adj[u]) {
            mx = std::max(mx, cur + dp[v]);
            cur += w[v];
        }
        dp[u] = std::max(mx, cur + w[u]);
    };
    dfs(dfs, 0);
    for (int i = 0; i < n; ++i) {
        std::cout << dp[i] << " ";
    }
}
