//Sun Aug  9 02:16:33 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const i64 INF = 2e18;
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
i64 dp[1000001][2];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    DSU dsu(n);
    std::vector<std::vector<int>> adj(n);
    std::vector<int> a(n);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        int u, v;
        std::cin >> u >> v;
        a[i] = u;
        v--;
        if (!dsu.same(i, v)) {
            dsu.merge(i, v);
            adj[i].push_back(v);
            adj[v].push_back(i);
        }else {
            edges.push_back({i, v});
        }
    }
    auto dfs = [&](auto self, int u, int fa) -> void {
        dp[u][0] = 0;
        dp[u][1] = a[u];
        for (int v : adj[u]) if (v != fa) {
            self(self, v, u);
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    };
    i64 ans = 0;
    for (auto [u, v] : edges){
        i64 cur = -INF;
        dfs(dfs, u, -1);
        cur = std::max(cur, dp[u][0]);
        dfs(dfs, v, -1);
        cur = std::max(cur, dp[v][0]);
        ans += cur;
    }
    std::cout << ans << nl;
}
