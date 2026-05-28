//Wed May 13 03:54:27 PM CST 2026
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
        int n, k;
        std::cin >> n >> k;
        std::vector<std::vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        std::vector<int> sz(n, 1);
        i64 ans = 0;
        // 只要sz >= k, 那么这个子树就一定可以有u为lca的贡献 
        auto dfs = [&](auto self, int u, int p) -> void {
            for (int v : g[u]) if (v != p) {
                self(self, v, u);
                sz[u] += sz[v];
            }
            // 当r是u
            ans++;
            // 当r在u的上方
            if (sz[u] >= k) ans += n - sz[u];
            // 当r是v
            for (int v : g[u]) if (v != p) {
                if (n - sz[v] >= k) {
                    ans += sz[v];
                }
            }
        };
        dfs(dfs, 0, 0);
        std::cout << ans << nl;
    }
}
