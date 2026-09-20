//Sun Aug 16 12:00:34 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
struct DSU {
    std::vector<int> f, sz;
    DSU() {}
    DSU(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
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
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    DSU dsu(n);
    int a = -1, b = -1;
    std::vector<int> p(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) std::cin >> p[i];
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (!dsu.same(u, v)) {
            dsu.merge(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }else {
            a = u;
            b = v;
        }
    }
    double k;
    std::cin >> k;
    std::vector dp(n, std::vector<int>(2));
    auto dfs = [&](auto self, int u, int fa) -> void {
        dp[u][0] = 0;
        dp[u][1] = p[u];
        for (int v : adj[u]) if (v != fa){
            self(self, v, u);
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };
    int ans = 0;
    dfs(dfs, a, -1);
    ans = dp[a][0];
    dfs(dfs, b, -1);
    ans = std::max(ans, dp[b][0]);
    std::cout << std::setprecision(1) << std::fixed << ans * k << nl;
}
