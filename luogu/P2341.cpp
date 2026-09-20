//Thu Aug 13 08:39:17 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 1e4;
// 有向图求SCC
int n, m;
std::vector<std::vector<int>> adj(N), adj2(N + 1), radj2(N + 1);
int tot = 0, top = -1, cnt = 0;
std::vector<int> dfn(N), low(N), stk(N), id(N), scc(N + 1);
std::vector<std::set<int>> ans(N + 1);
void dfs(int u) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            dfs(v);
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
            scc[cnt]++;
            if (x == u) break;
        }
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) dfs(i);
    }
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            if (id[u] != id[v]) {
                adj2[id[u]].push_back(id[v]);
                radj2[id[v]].push_back(id[u]);
            }
        }
    }
    int icnt = 0;
    int idx = -1;
    for (int i = 1; i <= cnt; ++i) {
        if (adj2[i].empty()) {
            icnt++;
            idx = i;
        }
    }
    if (icnt > 1) {
        std::cout << 0 << nl;
        return 0;
    }
    int tarvelcnt = 0;
    std::vector<int> vis(cnt + 1);
    auto dfs2 = [&](auto self, int u) -> void {
        if (vis[u]) return;
        tarvelcnt++;
        vis[u] = true;
        for (int v : radj2[u]) {
            self(self, v);
        }
    };
    dfs2(dfs2, idx);
    if (tarvelcnt == cnt) {
        std::cout << scc[idx] << nl;
    }else {
        std::cout << 0 << nl;
    }
}
