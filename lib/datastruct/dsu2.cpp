#include <bits/stdc++.h>
// 带权并查集
struct DSU {
    std::vector<int> f, val; // val[x] == [rx, x)
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

