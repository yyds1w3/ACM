#include <bits/stdc++.h>

using i64 = long long;

// 二维的单点修改 + 区间查询
struct Fenwick {
    int n, m;
    std::vector<std::vector<i64>> treeA;

    Fenwick(int n_ = 0, int m_ = 0) : n(n_), m(m_) {
        treeA.assign(n + 1, std::vector<i64>(m + 1));
    }
    void add(int posX, int posY, i64 val) {
        for (int i = posX + 1; i <= n; i += i & -i) {
            for (int j = posY + 1; j <= m; j += j & -j) {
                treeA[i][j] += val;
            }
        }
    }
    i64 sum(int posX, int posY) {
        i64 res = 0;
        for (int i = posX; i > 0; i -= i & -i) {
            for (int j = posY; j > 0; j -= j & -j) {
                res += treeA[i][j];
            }
        }
        return res;
    }
    i64 query(int posX1, int posY1, int posX2, int posY2) {
        return sum(posX2, posY2) - sum(posX1, posY2) - sum(posX2, posY1) + sum(posX1, posY1);
    }
};
