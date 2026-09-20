//Sat Aug 15 03:24:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
// 有向图求SCC
const int N = 4000;
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
    std::cin >> n;
    std::map<std::string, int> mp;
    for (int i = 0; i < n; ++i) {
        std::string g, b;
        std::cin >> g >> b;
        mp[g] = i;
        mp[b] = i;
    }
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        std::string g, b;
        std::cin >> g >> b;
        adj[mp[b]].push_back(mp[g]);
    }
    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        if (scc[id[i]] == 1) std::cout << "Safe" << nl;
        else std::cout << "Unsafe" << nl;
    }
}
