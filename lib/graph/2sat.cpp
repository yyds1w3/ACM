#include <bits/stdc++.h>
using i64 = long long;
const int N = 1000;
int n, m;
int tot, cnt, top = -1;
std::vector<std::vector<int>> adj(2*N);
std::vector<int> dfn(2*N), low(2*N), stk(2*N), id(2*N);
void init(int n) {
    tot = cnt = 0;
    top = -1;
    adj.assign(2*n, std::vector<int>());
    dfn.assign(2*n, 0);
    low.assign(2*n, 0);
    id.assign(2*n, 0);
}
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
