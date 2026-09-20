//Thu Aug 13 06:26:01 PM CST 2026
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
    std::vector<int> dfn(n), low(n), id(n);
    std::stack<int> stk;
    int cnt = 0;
    int tot = 0;
    auto dfs = [&](auto self, int u, int fa) -> void {
        dfn[u] = low[u] = ++tot;
        stk.push(u);
        for (int v : adj[u]) if (v != fa) {
            if (!dfn[v]) {
                self(self, v, u);
                low[u] = std::min(low[u], low[v]);
            }else {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            cnt++;
            while (true) {
                int x = stk.top();
                stk.pop();
                id[x] = cnt;
                if (x == u) break;
            }
        }
    };
    dfs(dfs, 0, -1);
    int leaves = 0;
    auto tarjan = [&]() -> void {
        std::vector<int> deg(tot + 1);
        for (int u = 0; u < n; ++u) {
            for (int v : adj[u]) {
                if (id[u] != id[v]) deg[id[u]]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1) leaves++;
        }
    };
    tarjan();
    std::cout << (leaves + 1) / 2 << nl;
}
