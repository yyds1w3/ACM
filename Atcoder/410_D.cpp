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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> adj(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    std::vector<std::vector<bool>> vis(n, std::vector<bool>(1024));
    auto dfs = [&](auto self, int u, int val) -> void {
        vis[u][val] = true;
        for (auto [v, w] : adj[u]) {
            int nx_val = val ^ w;
            if (vis[v][nx_val] == true) continue;
            self(self, v, nx_val);
        }
    };
    dfs(dfs, 0, 0);
    for (int i = 0; i < 1024; ++i) {
        if (vis[n - 1][i] == true) {
            std::cout << i << nl;
            return 0;
        }
    }
    std::cout << -1 << nl;

}
