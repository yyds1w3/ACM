//Tue Aug 18 10:03:14 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> ans;
    auto dfs = [&](auto self, int u) -> void {
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            self(self, v);
        }
        ans.push_back(u);
    };
    dfs(dfs, 0);
    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        std::cout << ans[i] + 1 << nl;
    }
}
