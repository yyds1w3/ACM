//2026-04-09 20:59:24
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
    #endif
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> depth(n);
    int mx = 0;
    int s = -1;
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) {
            if (v == fa) continue;
            depth[v] = depth[u] + 1; 
            if (depth[v] > mx) {
                mx = depth[v];
                s = v;
            }
            self(self, v, u);
        }
    };
    dfs1(dfs1, 0, 0);
    depth.assign(n, 0);
    mx = 0;
    dfs1(dfs1, s, s);
    std::cout << mx << nl;

}
