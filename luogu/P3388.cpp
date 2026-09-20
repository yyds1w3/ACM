//Thu Aug 13 08:24:28 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 2e4;
int n, m;
int tot;
int root;
std::vector<bool> cut(N);
std::vector<int> dfn(N), low(N);
std::vector<std::vector<int>> adj(N);
void dfs(int u, int fa) {
    if (fa == -1) root = u;
    dfn[u] = low[u] = ++tot;
    int child = 0;
    for (int v : adj[u]) if (v != fa) {
        if (!dfn[v]) {
            child++;
            dfs(v, u);
            low[u] = std::min(low[u], low[v]);
            if (u != root && low[v] >= dfn[u]) cut[u] = true;
        }else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (u == root && child >= 2) cut[u] = true;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) dfs(i, -1);
    }
    int ans = std::accumulate(cut.begin(), cut.end(), 0);
    std::cout << ans << nl;
    for (int i = 0; i < n; ++i) {
        if (cut[i]) std::cout << i + 1 << " ";
    }
    std::cout << nl;
}
