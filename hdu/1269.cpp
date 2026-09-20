//Thu Aug 13 07:12:37 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
        }
        int tot = 0, top = -1, cnt = 0;
        std::vector<int> dfn(n), low(n), stk(n), id(n);
        auto dfs = [&](auto self, int u) -> void {
            dfn[u] = low[u] = ++tot;
            stk[++top] = u;
            for (int v : adj[u]) {
                if (!dfn[v]) {
                    self(self, v);
                    low[u] = std::min(low[u], low[v]);
                }else if (!id[v]){
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (low[u] == dfn[u]) {
                cnt++;
                while (top >= 0) {
                    int x = stk[top--];
                    id[x] = cnt;
                    if (x == u) break;
                }
            }
        };
        dfs(dfs, 0);
        if (cnt == 1 && tot == n) {
            std::cout << "Yes" << nl;
        }else {
            std::cout << "No" << nl;
        }
    }
    
}
