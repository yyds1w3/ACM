//Wed Aug 12 09:15:06 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
int fa[70000][20];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj1(n + 1), adj2(n + 1);
    std::vector<int> in(n + 1);
    for (int i = 1; i <= n; ++i) {
        int v;
        while (std::cin >> v) {
            if (v == 0) break;
            adj1[v].push_back(i);
            in[i]++;
        }
    }
    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            adj1[0].push_back(i);
            in[i]++;
        }
    }
    std::vector<int> depth(n + 1);
    auto lca = [&](int u, int v) -> int{
        if (depth[u] < depth[v]) std::swap(u, v);
        for (int i = 19; i >= 0; --i) {
            if (depth[fa[u][i]] >= depth[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 19; i >= 0; --i) {
            if (fa[u][i] != fa[v][i]) {
                u = fa[u][i];
                v = fa[v][i];
            }
        }
        return fa[u][0];
    };
    q.push(0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 20; ++j) {
            fa[i][j] = -1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj1[u]) {
            in[v]--;
            if (fa[v][0] == -1) fa[v][0] = u;
            else fa[v][0] = lca(fa[v][0], u);
            if (in[v] == 0) {
                q.push(v);
                for (int i = 1; i <= 19; ++i) {
                    fa[v][i] = fa[fa[v][i-1]][i-1];
                }
                adj2[fa[v][0]].push_back(v);
                depth[v] = depth[fa[v][0]] + 1;
            }
        }
    }
    std::vector<int> sz(n + 1, 1);
    auto dfs = [&](auto self, int u) -> void {
        for (int v : adj2[u]) {
            self(self, v);
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0);
    for (int i = 1; i <= n; ++i) {
        std::cout << sz[i] - 1 << nl;
    }
}
