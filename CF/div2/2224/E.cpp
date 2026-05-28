//Wed May  6 07:05:07 PM CST 2026
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
        std::vector<int> f(n), l(n);
        std::vector<std::vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            std::cin >> f[i];
            adj[f[i]].push_back(i);
        }
        for (int i = 1; i < n; ++i) {
            std::cin >> l[i];
        }
        auto dfs = [&](auto self, int u, int t) -> void {
            int sz = adj[u].size();
            for (int v : adj[u]) {
                self(self, v, (t + l[v]) % sz);
            }
        };
    }
}
