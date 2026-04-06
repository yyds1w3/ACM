#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
struct DSU {
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    DSU dsu(n);
    std::vector adj(n, std::vector<int>());
    std::vector<int> w(n);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        std::cin >> w[i]; 
        int v;
        std::cin >> v;
        v--;
        if (dsu.same(i, v)) {
            edges.push_back({i, v}); 
        }else {
            dsu.merge(i, v);
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
    }
    std::vector dp(n, std::vector<i64>(2));
    auto dfs = [&] (auto self, int u, int fa) -> void {
        dp[u][0] = 0;
        dp[u][1] = w[u];
        for (int v : adj[u]) {
            if (v == fa) continue;
            self(self, v, u);
            dp[u][0] += std::max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        } 
    };
    i64 ans = 0;
    for (auto [u, v] : edges) {
        i64 cur = 0;
        dfs(dfs, u, -1);
        cur = dp[u][0];
        dfs(dfs, v, -1);
        cur = std::max(cur, dp[v][0]);
        ans += cur;
    }
    std::cout << ans << nl;
}
