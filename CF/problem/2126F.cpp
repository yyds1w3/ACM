//Tue May 19 05:30:55 PM CST 2026
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
        int n, q;
        std::cin >> n >> q;
        std::vector<int> a(n);
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        std::map<std::pair<int, int>, int> edges;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n - 1; ++i) {
            int u, v, c;
            std::cin >> u >> v >> c;
            u--, v--;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
            edges[{u, v}] = c;
            edges[{v, u}] = c;
        }
        i64 ans = 0;
        std::vector<std::map<int, i64>> dp(n);
        std::vector<int> fa(n);
        auto dfs = [&](auto self, int u, int p) -> void {
            fa[u] = p;
            for (auto [v, c] : adj[u]) if (v != p) {
                if (a[u] != a[v]) ans += c;
                dp[u][a[v]] += c;
                self(self, v, u);
            }
        };
        dfs(dfs, 0, 0);
        while (q--) {
            int u, x;
            std::cin >> u >> x;
            u--;
            if (a[u] == x) {
                std::cout << ans << nl;
                continue;
            }
            // child 
            ans += dp[u][a[u]];
            ans -= dp[u][x];
            // fa
            if (u != 0) {
                int c = edges[{fa[u], u}];
                if (a[fa[u]] == a[u]) {
                    ans += c;
                }else if (a[fa[u]] == x) {
                    ans -= c;
                }
                dp[fa[u]][a[u]] -= c;
                dp[fa[u]][x] += c;
            }
            
            a[u] = x;
            std::cout << ans << nl;
        }
    }
}
