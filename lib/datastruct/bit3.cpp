#include <bits/stdc++.h>
using i64 = long long;

// 区间查询 + 区间修改
struct Fenwick {
    int n;
    std::vector<i64> treeD; 
    std::vector<i64> treeDi;
    
    Fenwick(int n_ = 0) : n(n_) {
        treeD.assign(n + 1, 0);
        treeDi.assign(n + 1, 0);
    };
    // add[l, r)
    void add(int l, int r, i64 val) {
        for (int i = l + 1; i <= n; i += i & -i) {
            treeD[i] += val;
            treeDi[i] += val * (l + 1);
        }
        for (int i = r + 1; i <= n; i += i & -i) {
            treeD[i] -= val;
            treeDi[i] -= val * (r + 1);
        }
    }
    // query[l, r) 求d 和 di 的前缀和再相减
    i64 query(int l, int r) {
        i64 res = 0;
        // [0, r)
        for (int i = r; i > 0; i -= i & -i) {
            res += (r + 1) * treeD[i] - treeDi[i];
        }
        // [0, l)
        for (int i = l; i > 0; i -= i & -i) {
            res -= (l + 1) * treeD[i] - treeDi[i];
        }
        return res;
    }
};
