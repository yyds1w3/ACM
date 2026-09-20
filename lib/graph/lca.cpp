#include <bits/stdc++.h>
using i64 = long long;
const int N = 5200;
int n, m;
std::vector<std::vector<int>> adj(N);
int fa[N][20];
int dep[N];
void init(int n) {
    for (int i = 0; i < n; ++i) adj[i].clear();
    memset(dep, 0, sizeof(dep));
}
void dfs(int u, int p) {
    if (p == -1) {
        for (int i = 0; i < 20; ++i) fa[u][i] = u;
    }
    for (int v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        for (int i = 1; i <= 19; ++i) {
            fa[v][i] = fa[fa[v][i-1]][i-1];
        }
        dfs(v, u);
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
