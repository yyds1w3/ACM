//Sat Aug 15 04:38:40 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
// 无向图求点双连通向量和割点
struct VBCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> dfn, low, cut, stk;
    std::vector<std::vector<int>> vbcc;
    int tot;

    VBCC() {};
    VBCC(int n_) {
        init(n_);
    }
    void init(int n_) {
        n = n_;
        adj.resize(n, std::vector<int>());
        dfn.resize(n);
        low.resize(n);
        cut.resize(n);
        tot = 0;
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int u, int fa) {
        dfn[u] = low[u] = ++tot;
        stk.push_back(u);
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
                        int x = stk.back();
                        stk.pop_back();
                        comp.push_back(x);
                        if (x == v) break;
                    }
                    comp.push_back(u);
                    vbcc.push_back(comp);
                }
            }else low[u] = std::min(low[u], dfn[v]);
        }
        if (fa == -1 && child < 2) cut[u] = 0;
    }
    void work() {
        for (int i = 0; i < n; ++i) {
            if (!dfn[i]) dfs(i, -1);
        }
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int cs = 1;
    int m;
    while (std::cin >> m) {
        if (m == 0) break;
        VBCC a(2*m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            a.addEdge(u, v);
        }
        a.work();
        i64 ans1 = 1, ans2 = 0;
        for (auto vec : a.vbcc) {
            int c = 0;
            for (int p : vec) {
                if (a.cut[p]) {
                    c++;
                }
            }
            if (c == 0) {
                ans1 *= (1LL * vec.size() * (vec.size() - 1)) / 2;
                ans2 += 2;
            }
            if (c == 1) {
                ans1 *= vec.size() - 1;
                ans2 += 1;
            }
        }
        std::cout << "Case " << cs << ": " << ans2 << " " << ans1 << nl;
        cs++;
    }
}
