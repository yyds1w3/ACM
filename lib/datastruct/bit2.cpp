// 2026-04-02 17:22
#include <bits/stdc++.h>

using i64 = long long;

// 区间修改 + 单点查询
struct Fenwick {
    int n;
    std::vector<i64> treeD;

    Fenwick(int n_ = 0) : n(n_){
        treeD.assign(n + 1, 0);
    }
    // [l, r), d[l]++, d[r]--;
    void add(int l, int r, int val) {
        for (int i = l + 1; i <= n; i += i & -i) {
            treeD[i] += val;
        }
        for (int i = r + 1; i <= n; i += i & -i) {
            treeD[i] -= val;
        }
    }
    // query[pos] == a[pos] = d[1] + d[2] + ... d[pos]
    i64 query(int pos) {
        i64 res = 0;
        for (int i = pos + 1; i > 0; i -= i & -i) {
            res += treeD[i];
        }
        return res;
    }

};
