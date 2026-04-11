// 2026-04-07 20:46
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
    int n, m, s;
    std::cin >> n >> m >> s;
    s--;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> depth(n);
    std::vector<std::vector<int>> f(n, std::vector<int>(20, s));
    auto dfs = [&](auto self, int fa, int u) -> void {
        for (int v : adj[u]) {
            if (v == fa) continue;
            depth[v] = depth[u] + 1;
            f[v][0] = u;
            for (int k = 1; k < 20; ++k) {
                f[v][k] = f[f[v][k - 1]][k - 1];
            }
            self(self, u, v);
        }
    };
    dfs(dfs, s, s);

    auto lca = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) {
            std::swap(u, v);
        }
        for (int k = 19; k >= 0; k--) {
            if (depth[f[u][k]] >= depth[v]) {
                u = f[u][k];
            }
        }
        if (u == v) {
            return u;
        }
        for (int k = 19; k >= 0; k--) {
            if (f[u][k] != f[v][k]) {
                u = f[u][k];
                v = f[v][k];
            }
        }
        return f[u][0];
    };
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        std::cout << lca(u, v) + 1 << nl;
    }
}
