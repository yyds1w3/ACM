//Thu May 14 04:23:26 PM CST 2026
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
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            a[i]--;
        }
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        std::vector<int> ans(n);
        std::vector<int> cnt(n);
        auto dfs = [&](auto self, int u, int p) -> void {
            for (int v : adj[u]) if (p != v) {
                if (a[u] == a[v]) ans[a[u]] = 1;
                self(self, v, u);
            }
            for (int v : adj[u]) {
                cnt[a[v]]++;
                if (cnt[a[v]] == 2) {
                    ans[a[v]] = 1;
                }
            }
            for (int v : adj[u]) {
                cnt[a[v]]--;
            }
        };
        dfs(dfs, 0, 0);
        for (int i = 0; i < n; ++i) {
            std::cout << ans[i];
        }
        std::cout << nl;
    }
}
