//Sun Apr 26 10:04:52 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> dfn(n), low(n);
    int timer = 0;
    std::vector<std::pair<int, int>> bridges;
    auto dfs = [&](auto self, int u, int fa) -> void {
        dfn[u] = low[u] = ++timer;
        for (int v : adj[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                self(self, v, u);
                low[u] = std::min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    bridges.push_back({std::min(u, v), std::max(u, v)});
                }
            }else {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    };
    dfs(dfs, 0, 0);
    std::sort(bridges.begin(), bridges.end());
    for (auto [u, v] : bridges) {
        std::cout << u+1 << " " << v+1 << nl;
    }
}
