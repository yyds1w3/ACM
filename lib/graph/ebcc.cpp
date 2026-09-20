#include <bits/stdc++.h>
using i64 = long long;
// 不支持重边的EBCC
const int N = 1000;
int n, m;
int tot, cnt, top = -1;
std::vector<std::vector<int>> adj(N), adj2(N+1);
std::vector<int> dfn(N), low(N), stk(N), id(N);
void init(int n) {
    tot = cnt = 0;
    top = -1;
    adj.assign(n, std::vector<int>());
    dfn.assign(n, 0);
    low.assign(n, 0);
    id.assign(n, 0);
}
void dfs(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;
    for (int v : adj[u]) if (v != fa) {
        if (!dfn[v]) {
            dfs(v, u);
            low[u] = std::min(low[u], low[v]);
        }else {
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

