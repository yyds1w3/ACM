//Thu Aug 13 05:59:24 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
int n = 1000;
int tot;
std::vector<std::vector<int>> adj(n);
std::vector<int> cut(n);
std::vector<int> dfn(n), low(n);
void dfs(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    for (int v : adj[u]) if (v != fa) {
        if (!dfn[v]) {
            dfs(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u]) cut[u]++;
        }else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (u != 0) cut[u] += 1;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int u, v;
    while (std::cin >> u >> v) {
        if (u == 0) {
            dfs(0, -1);
            for (int i = 0; i < 1000; ++i) adj[i].clear();
            continue;
        }
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
