//Tue Aug 18 09:19:05 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
#define debugv(v, sz) std::cerr << #v << ":" << nl;\
for (int i = 0; i < sz; ++i) std::cerr << v[i] << " "; std::cerr << nl;
#define debugvv(v, sz1, sz2) std::cerr << #v << ":" << nl;\
for (int i = 0; i < sz1; ++i) {std::cerr << i << ": ";for (int j = 0; j < sz2; ++j) std::cerr << v[i][j] << " ";}
using i64 = long long;
using i128 = __int128;
const int N = 1e4;
int n, m;
std::vector<int> f(N), sz(N);
void init(int n) {
    std::iota(f.begin(), f.begin() + n, 0);
    sz.assign(n, 1);
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        f[rx] = ry;
        sz[ry] += sz[rx];
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int size(int x) {
    return sz[find(x)];
}
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
std::vector<std::vector<std::pair<int, int>>> adj(N);
int fa[N][20];
int mn[N][20];
int dep[N];
bool vis[N];
void init2(int n) {
    for (int i = 0; i < n; ++i) adj[i].clear();
    std::fill(mn[0], mn[0] + n * 20, 1e9);
    std::fill(dep, dep + n, 0);
}
void dfs(int u, int p) {
    vis[u] = true;
    if (p == -1) {
        for (int i = 0; i < 20; ++i) fa[u][i] = u;
    }
    for (auto [v, w] : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        mn[v][0] = w;
        for (int i = 1; i <= 19; ++i) {
            fa[v][i] = fa[fa[v][i-1]][i-1];
            mn[v][i] = std::min(mn[v][i-1], mn[fa[v][i-1]][i-1]);
        }
        if (!vis[v]) dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) {
        std::swap(u, v);
    }
    for (int i = 19; i >= 0; --i) {
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
int query(int u, int p) {
    if (u == p) return 1e9;
    int res = 1e9;
    for (int i = 19; i >= 0; --i) {
        if (dep[fa[u][i]] > dep[p]) {
            res = std::min(res, mn[u][i]);
            u = fa[u][i];
        }
    }
    res = std::min(res, mn[u][0]);
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    init(n);
    init2(n);
    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        edges[i] = {u, v, w};
    }
    std::sort(edges.rbegin(), edges.rend());
    for (auto [u, v, w] : edges) {
        if (!same(u, v)) {
            merge(u, v);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfs(i, -1);
    }
    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        if (!same(u, v)) {
            std::cout << -1 << nl;
        }else {
            int ff = lca(u, v);
            std::cout << std::min(query(u, ff), query(v, ff)) << nl;
        }
    }
}
