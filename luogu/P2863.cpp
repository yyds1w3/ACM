//Thu Aug 13 09:15:38 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
// 有向图求SCC
const int N = 1e4;
int n, m;
std::vector<std::vector<int>> adj(N);
int tot = 0, top = -1, cnt = 0;
std::vector<int> dfn(N), low(N), stk(N), id(N), scc(N + 1);
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
    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (scc[i] > 1) ans++;
    }
    std::cout << ans << nl;

}
