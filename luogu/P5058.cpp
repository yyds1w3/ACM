//Sat Aug 15 08:27:03 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int u, v;
    std::vector<std::vector<int>> adj(n);
    while (std::cin >> u >> v) {
        if (u == 0 && v == 0) break;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    std::vector<int> stk, dfn(n), low(n);
    int tot = 0;
    int ans = n;
    auto dfs = [&](auto self, int u, int fa) -> void {
        dfn[u] = low[u] = ++tot;
        for (int v : adj[u]) if (v != fa) {
            if (!dfn[v]) {
                self(self, v, u);
                low[u] = std::min(low[u], low[v]);
                if (u != a && u != b && low[v] >= dfn[u] && dfn[v] <= dfn[b]) {
                    ans = std::min(ans, u);
                }
            }else low[u] = std::min(low[u], dfn[v]);
        }
    };
    dfs(dfs, a, -1);
    if (ans == n) {
        std::cout << "No solution" << nl;
    }else {
        std::cout << ans + 1 << nl;
    }
}
