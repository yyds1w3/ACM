//Mon Apr 27 08:46:39 AM CST 2026
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

struct DSU {
    std::vector<int> f, val;
    DSU(int n = 0) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        val.assign(n, 0);
    }
    int find(int x) {
        if (f[x] == x) return x;
        int root = find(f[x]);
        val[x] += val[f[x]];
        return f[x] = root;
    }
    // 将x合并到y的集合, x比y大v
    // 只更新了val[rx], 故查询x的时候要先find[x]
    void merge(int x, int y, int v) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            f[rx] = ry;
            val[rx] = val[y] + v - val[x];
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y); 
    }
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
        int n, m; 
        std::cin >> n >> m;
        DSU dsu(n + 1);
        bool f = true;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            // u = 1, v = 2, w = 3;
            // [0, 2) == 3
            // [0, 0) != [2, 2)
            // [0, 2) = 3
            u--;
            if (!dsu.same(u, v)) { // val[u] = [ru, u) val[v] = [rv, v)
                dsu.merge(v, u, w); // [u, v) = w;
            }else {
                // 执行过same(即两个find, 可以查询)
                if (dsu.val[v] - dsu.val[u] != w) {  // [r, v) - [r, u) == [u, v)
                    f = false;
                }
            }
        }
        if (f) {
            std::cout << "true" << nl;
        }else {
            std::cout << "false" << nl;
        }
    }
}
