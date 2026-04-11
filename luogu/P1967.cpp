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
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};
struct DSU {
    int n;
    std::vector<int> fa;
    DSU (int n_) : n(n_) {
        fa.assign(n, 0);
        std::iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] == x) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return false;
        fa[rx] = ry;
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<Edge> a(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].u--, a[i].v--;
    }
    std::sort(a.begin(), a.end());
    DSU dsu(n);
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        auto [u, v, w] = a[i];
        if (dsu.merge(u, v)) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    std::vector<int> depth(n + 1);
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(20, n)), minW(n + 1, std::vector<int>(20, 1e9));
    
    auto dfs = [&](auto self, int u, int fa, int w) -> void {
        f[u][0] = fa;
        minW[u][0] = w;
        for (int i = 1; i < 20; ++i) {
            f[u][i] = f[f[u][i-1]][i-1];
            minW[u][i] = std::min(minW[u][i-1], minW[f[u][i-1]][i-1]);
        }
        for (auto [v, w] : adj[u]) {
            if (v == fa) continue;
            depth[v] = depth[u] + 1;
            self(self, v, u, w);
        }
    };
    for (int i = 0; i < n; ++i) {
        int root = dsu.find(i);
        if (depth[root] == 0) {
            depth[root] = 1;
            dfs(dfs, root, n, 1e9);
        }
    }
    auto query = [&](int u, int v) -> int {
        int res = 1e9;
        if (depth[u] < depth[v]) {
            std::swap(u, v);
        }
        for (int k = 19; k >= 0; --k) {
            if (depth[f[u][k]] >= depth[v]) {
                res = std::min(res, minW[u][k]);
                u = f[u][k];
            }
        }
        if (u == v) {
            return res;
        }
        for (int k = 19; k >= 0; --k) {
            if (f[u][k] != f[v][k]) {
                res = std::min({res, minW[u][k], minW[v][k]});
                u = f[u][k];
                v = f[v][k];
            }
        }
        return std::min({res, minW[u][0], minW[v][0]});
    };
    int q;
    std::cin >> q;
    while(q--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        if (!dsu.same(u, v)) {
            std::cout << -1 << nl;
        }else {
            std::cout << query(u, v) << nl;
        }
    }
}
