#include <bits/stdc++.h>
using i64 = long long;
const int N = 1000;
int n, m;
int tot, top = -1;
std::vector<std::vector<int>> adj(N), vbcc;
std::vector<int> dfn(N), low(N), stk(N), cut(N);
void init(int n) {
    tot = 0, top = -1;
    adj.assign(n, std::vector<int>());
    vbcc.clear();
    dfn.assign(n, 0);
    low.assign(n, 0);
}
void dfs(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;
    int child = 0;
    for (int v : adj[u]) if (v != fa) {
        if (!dfn[v]) {
            child++;
            dfs(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                cut[u]++;
                std::vector<int> comp;
                while (true) {
                    int x = stk[top--];
                    comp.push_back(x);
                    if (x == v) break;
                }
                comp.push_back(u);
                vbcc.push_back(comp);
            }
        }else {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (fa == -1 && child < 2) cut[u] = 0;
}

