#include <bits/stdc++.h>

using i64 = long long;

// 二维 + 区间修改 + 区间查询
struct Fenwick {
    int n, m;
    std::vector<std::vector<i64>> treeD;
    std::vector<std::vector<i64>> treeDi;
    std::vector<std::vector<i64>> treeDj;
    std::vector<std::vector<i64>> treeDij;

    Fenwick(int n_, int m_) : n(n_), m(m_) {
        treeD.assign(n + 1, std::vector<i64>(m + 1));
        treeDi.assign(n + 1, std::vector<i64>(m + 1));
        treeDj.assign(n + 1, std::vector<i64>(m + 1));
        treeDij.assign(n + 1, std::vector<i64>(m + 1));
    }
    void _add(int posX, int posY, i64 val) {
        for (int i = posX + 1; i <= n; i += i & -i) {
            for (int j = posY + 1; j <= m; j += j & -j) {
                treeD[i][j] += val;
                treeDi[i][j] += val * (posX + 1);
                treeDj[i][j] += val * (posY + 1);
                treeDij[i][j] += val * (posX + 1) * (posY + 1);
            }
        }
    }
    void add(int posX1, int posY1, int posX2, int posY2, i64 val) {
        _add(posX1, posY1, val);
        _add(posX2, posY2, val);
        _add(posX1, posY2, -val);
        _add(posX2, posY1, -val);
    }
    i64 _query(int posX1, int posY1) {
        i64 res = 0;
        for (int i = posX1; i > 0; i -= i & -i) {
            for (int j = posY1; j > 0; j -= j & -j) {
                res += (posX1 + 1) * (posY1 + 1) * treeD[i][j]
                        - (posY1 + 1) * treeDi[i][j]
                        - (posX1 + 1) * treeDj[i][j]
                        + treeDij[i][j];
            }
        }
        return res;
    }
    i64 query(int posX1, int posY1, int posX2, int posY2) {
        return _query(posX2, posY2) + _query(posX1, posY1) - _query(posX1, posY2) - _query(posX2, posY1);
    }
};
