//Mon May 25 05:10:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
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
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> a(3, std::vector<int>(n));
        TwoSat sat(n);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cin >> a[i][j];
            }
        }
        for (int j = 0; j < n; ++j) {
            sat.addClause(std::abs(a[0][j]) - 1, a[0][j] > 0, std::abs(a[1][j]) - 1, a[1][j] > 0);
            sat.addClause(std::abs(a[0][j]) - 1, a[0][j] > 0, std::abs(a[2][j]) - 1, a[2][j] > 0);
            sat.addClause(std::abs(a[1][j]) - 1, a[1][j] > 0, std::abs(a[2][j]) - 1, a[2][j] > 0);
        }
        if (sat.satisfiable()) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
