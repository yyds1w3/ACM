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
struct Fenwick {
    int n, m;
    std::vector<std::vector<std::vector<int>>> treeA;
    
    Fenwick(int n_, int m_) : n(n_), m(m_) {
        treeA.assign(n + 1, std::vector<std::vector<int>>(m + 1, std::vector<int>(101, 0)));
    }
    void add(int posX, int posY, int val, int col) {
        for (int i = posX + 1; i <= n; i += i & -i) {
            for (int j = posY + 1; j <= m; j += j & -j) {
                treeA[i][j][col] += val;
            }
        }
    }
    i64 query(int posX, int posY, int col) {
        i64 res = 0;
        for (int i = posX; i > 0; i -= i & -i) {
            for (int j = posY; j > 0; j -= j & -j) {
                res += treeA[i][j][col];
            }
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    Fenwick bit(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            bit.add(i, j, 1, a[i][j]);
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y, c;
            std::cin >> x >> y >> c;
            x--, y--;
            bit.add(x, y, -1, a[x][y]);
            a[x][y] = c;
            bit.add(x, y, 1, c);
        }else {
            int x1, x2, y1, y2, c;
            std::cin >> x1 >> x2 >> y1 >> y2 >> c;
            x1--, y1--;
            std::cout << bit.query(x2, y2, c) + bit.query(x1, y1, c) - bit.query(x1, y2, c) - bit.query(x2, y1, c) << nl;
        }
    }
}
