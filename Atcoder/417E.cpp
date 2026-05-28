//Thu Apr 23 07:57:51 PM CST 2026
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
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, x, y;
        std::cin >> n >> m >> x >> y;
        x--, y--;
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) std::sort(adj[i].begin(), adj[i].end());
        std::vector<bool> vis(n);
        std::vector<int> ans;
        vis[x] = true;
        ans.push_back(x);
        auto dfs = [&](auto self, int u) -> bool {
            if (u == y) return true;
            for (int v : adj[u]) {
                if (vis[v]) continue;
                vis[v] = true;
                ans.push_back(v);
                if (self(self, v)) return true;
                ans.pop_back();
            }
            return false;
        };
        dfs(dfs, x);
        for (int v : ans) {
            std::cout << v + 1 << " ";
        } 
        std::cout << nl;
    }
}
