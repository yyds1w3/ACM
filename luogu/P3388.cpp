//Sun Apr 26 10:20:44 PM CST 2026
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
    std::vector<int> dfn(n), low(n);
    std::vector<bool> isCut(n);
    int timer = 0;
    auto dfs = [&](auto self, int u, int fa, int root) -> void {
        dfn[u] = low[u] = ++timer;
        int child = 0;
        for (int v : adj[u]) {
            if (v == fa) continue;
            if (!dfn[v]) {
                child++;
                self(self, v, u, root);
                low[u] = std::min(low[u], low[v]);
                if (u != root && low[v] >= dfn[u]) {
                    isCut[u] = true;
                }
            }else {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (u == root && child >= 2) {
            isCut[u] = true; 
        }
    };
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            dfs(dfs, i, i, i);
        }
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) {
        if (isCut[i]) {
            tot++;
        }
    }
    std::cout << tot << nl;
    for (int i = 0; i < n; ++i) {
        if (isCut[i]) {
            std::cout << i + 1 << " ";
        }
    }
}
