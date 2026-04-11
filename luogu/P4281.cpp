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
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> depth(n);
    std::vector<std::vector<int>> f(n, std::vector<int>(20));
    auto dfs = [&](auto self, int u, int fa) -> void {
        for (int v : adj[u]) {
            if (v == fa) continue;
            depth[v] = depth[u] + 1;
            f[v][0] = u;
            for (int k = 1; k < 20; ++k) {
                f[v][k] = f[f[v][k-1]][k-1];
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 0, 0);
    auto lca = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) {
            std::swap(u, v);
        }
        for (int k = 19; k >= 0; --k) {
            if (depth[f[u][k]] >= depth[v]) {
                u = f[u][k];
            }
        }
        if (u == v) return u;
        for (int k = 19; k >= 0; --k) {
            if (f[u][k] != f[v][k]) {
                u = f[u][k];
                v = f[v][k];
            }
        }
        return f[u][0];
    };
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--, y--, z--;

        int l1 = lca(x, y);
        int l2 = lca(x, z);
        int l3 = lca(y, z);
        int p = l1;
        if (depth[l2] > depth[p]) p = l2;
        if (depth[l3] > depth[p]) p = l3;
        auto dis = [&](int u, int v) -> int {
            return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        };
        std::cout << p + 1 << " " << dis(x, p) + dis(y, p) + dis(z, p) << nl;
    }
}
