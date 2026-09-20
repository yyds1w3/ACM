//Sun Aug 16 03:49:07 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 1000;
int n, m;
int tot, cnt, top = -1;
std::vector<std::vector<int>> adj(2*N);
std::vector<int> dfn(2*N), low(2*N), stk(2*N), id(2*N);
void dfs(int u) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;
    for (int v : adj[u]) {
        if (!dfn[v]) {
            dfs(v);
            low[u] = std::min(low[u], low[v]);
        }else if (!id[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        cnt++;
        while (true) {
            int x = stk[top--];
            id[x] = cnt;
            if (x == u) break;
        }
    }
}
void init(int n) {
    tot = cnt = 0;
    top = -1;
    for (int i = 0; i < 2 * n; ++i) adj[i].clear();
    for (int i = 0; i < 2 * n; ++i) dfn[i] = low[i] = id[i] = 0;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    while (std::cin >> n >> m) {
        init(n);
        for (int i = 0; i < m; ++i) {
            int u, v, c1, c2;
            std::cin >> u >> v >> c1 >> c2;
            adj[2*u+c1].push_back(2*v+!c2);
            adj[2*v+c2].push_back(2*u+!c1);
        }
        for (int i = 0; i < 2 * n; ++i) {
            if (!dfn[i]) dfs(i);
        }
        bool f = true;
        for (int i = 0; i < n; ++i) {
            if (id[2*i] == id[2*i+1]) {
                f = false;
            }
        }
        if (f) {
            std::cout << "YES" << nl;
        }else std::cout << "NO" << nl;
    }
}
