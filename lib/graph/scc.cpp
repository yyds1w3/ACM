// Mon May 25 04:06:07 PM CST 2026

#include <bits/stdc++.h>
using i64 = long long;

struct SCC {
    int n;
    int cur, cnt;
    std::vector<std::vector<int>> adj;
    std::vector<int> dfn, low, tag;
    std::vector<int> stk;

    SCC() {}
    SCC(int n_) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        cur = cnt = 0;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        tag.assign(n, -1);
        stk.clear();
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void dfs(int x) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (int v : adj[x]) {
            if (dfn[v] == -1) {
                dfs(v);
                low[x] = std::min(low[x], low[v]);
            }else if (tag[v] == -1) {
                low[x] = std::min(low[x], dfn[v]);
            }
        }
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                tag[y] = cnt;
                stk.pop_back();
            }while (y != x);
            cnt++;
        }
    }
    std::vector<int> work() {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return tag;
    }
};

