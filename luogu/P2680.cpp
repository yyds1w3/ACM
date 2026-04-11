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
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<int> dist(n);
    std::vector<int> depth(n);
    std::vector<std::vector<int>> f(n, std::vector<int>(20));
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        for (auto [v, w] : adj[u]) {
            if (v == fa) continue;
            dist[v] = dist[u] + w;
            depth[v] = depth[u] + 1;
            f[v][0] = u;
            for (int k = 1; k < 20; ++k) {
                f[v][k] = f[f[v][k-1]][k-1];
            }
            self(self, v, u);
        }
    };
    dfs1(dfs1, 0, 0);
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
    std::vector<std::pair<int, int>> plans(m);
    std::vector<int> plans_dist(m);
    std::vector<int> plans_lca(m);
    int mx_dist = 0;
    
    for (int i = 0; i < m; ++i) {
        std::cin >> plans[i].first >> plans[i].second;
        plans[i].first--, plans[i].second--;
        plans_lca[i] = lca(plans[i].first, plans[i].second); 
        plans_dist[i] = dist[plans[i].first] + dist[plans[i].second] - 2 * dist[plans_lca[i]];
        mx_dist = std::max(mx_dist, plans_dist[i]);
    }
    std::vector<int> diff(n); 
    auto check = [&](int time) -> bool {
        int cnt = 0;
        int mx = 0;
        std::fill(diff.begin(), diff.end(), 0); 
        
        for (int i = 0; i < m; ++i) {
            if (plans_dist[i] > time) {
                cnt++;
                mx = std::max(mx, plans_dist[i]);
                diff[plans[i].first]++;
                diff[plans[i].second]++;
                diff[plans_lca[i]] -= 2;
            }
        }
        if (cnt == 0) return true;
        
        auto dfs2 = [&](auto self, int u, int fa) -> bool {
            for (auto [v, w] : adj[u]) {
                if (v == fa) continue;
                if (self(self, v, u)) {
                    return true;
                }
                diff[u] += diff[v];
            }
            if (u != 0 && diff[u] == cnt) {
                if (mx - (dist[u] - dist[f[u][0]]) <= time) {
                    return true;
                }
            }
            return false;
        };
        return dfs2(dfs2, 0, 0);
    };
    int l = 0, r = mx_dist;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << nl;
}
