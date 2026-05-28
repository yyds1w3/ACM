// Mon May 25 04:55:26 PM CST 2026

#include <bits/stdc++.h>
using i64 = long long;

struct TwoSat {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<bool> ans;
    TwoSat(int n_) : n(n_), adj(2 * n_), ans(n_) {}
    // u == f || v == g;
    void addClause(int u, bool f, int v, bool g) {
        adj[2 * u + !f].push_back(2 * v + g); // u != f ==> v == g;
        adj[2 * v + !g].push_back(2 * u + f); // v != g ==> u == f;
    }
    bool satisfiable() {
        std::vector<int> dfn(2 * n, -1), low(2 * n, -1), tag(2 * n, -1);
        std::vector<int> stk;
        int cur = 0, cnt = 0;
        auto tarjan = [&](auto self, int x) -> void {
            dfn[x] = low[x] = cur++;
            stk.push_back(x);
            for (int v : adj[x]) {
                if (dfn[v] == -1) {
                    self(self, v);
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
                }while (x != y);
                cnt++;
            }
        };
        for (int i = 0; i < 2 * n; ++i) {
            if (dfn[i] == -1) tarjan(tarjan, i);
        }
        for (int i = 0; i < n; ++i) {
            if (tag[2 * i] == tag[2 * i + 1]) return false;
            ans[i] = tag[2 * i] > tag[2 * i + 1]; // 真编号小选真, 假编号小选假
        }
        return true;
    }
    std::vector<bool> answer() {return ans;}
};
