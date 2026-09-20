//Thu Aug 13 09:36:37 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 100;
// 有向图求SCC
int n;
std::vector<std::vector<int>> adj(N), adj2(N + 1);
int tot = 0, top = -1, cnt = 0;
std::vector<int> dfn(N), low(N), stk(N), id(N), scc(N + 1), in(N + 1), out(N + 1);
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
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int v;
        while (std::cin >> v) {
            if (v == 0) break;
            v--;
            adj[i].push_back(v);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int v : adj[i]) {
            if (id[i] != id[v]) {
                adj2[id[i]].push_back(id[v]);
                in[id[v]]++;
                out[id[i]]++;
            }
        }
    }
    if (cnt == 1) {
        std::cout << 1 << nl << 0 << nl;
        return 0;
    }
    int p = 0, q = 0;
    for (int i = 1; i <= cnt; ++i) {
        if (in[i] == 0) p++;
        if (out[i] == 0) q++;
    }
    std::cout << p << nl << std::max(p, q) << nl;
}
