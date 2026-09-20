//Sun Aug 16 01:32:57 PM CST 2026
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
    std::vector<std::vector<int>> adj(2 * n);
    for (int i = 0; i < m; ++i) {
        int u, a, v, b;
        std::cin >> u >> a >> v >> b;
        u--, v--;
        adj[2*u+!a].push_back(2*v+b);
        adj[2*v+!b].push_back(2*u+a);
    }
    int tot = 0, cnt = 0;
    std::vector<int> dfn(2 * n), low(2 * n), stk, id(2 * n);
    auto dfs = [&](auto self, int u) -> void {
        dfn[u] = low[u] = ++tot;
        stk.push_back(u);
        for (int v : adj[u]) {
            if (!dfn[v]) {
                self(self, v);
                low[u] = std::min(low[u], low[v]);
            }else if (!id[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            cnt++;
            while (true) {
                int x = stk.back();
                stk.pop_back();
                id[x] = cnt;
                if (x == u) break;
            }
        }
    };
    for (int i = 0; i < 2 * n; ++i) {
        if (!dfn[i]) {
            dfs(dfs, i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (id[2*i] == id[2*i+1]) {
            std::cout << "IMPOSSIBLE" << nl;
            return 0;
        }
    }
    std::cout << "POSSIBLE" << nl;
    for (int i = 0; i < n; ++i) {
        std::cout << (id[2*i+1] < id[2*i]) << " ";
    }
    std::cout << nl;

}
