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
    int n;
    std::vector<i64> treeD;
    std::vector<i64> treeDi;

    Fenwick(){}
    Fenwick(int n_) : n(n_) {
        treeD.assign(n + 1, 0);
        treeDi.assign(n + 1, 0);
    }
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
    i64 query(int l, int r) {
        i64 res = 0;
        for (int i = r; i > 0; i -= i & -i) {
            res += (r + 1) * treeD[i] - treeDi[i];
        }
        for (int i = l; i > 0; i -= i & -i) {
            res -= (l + 1) * treeD[i] - treeDi[i];
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
    Fenwick bit(n);
    for (int i = 0; i < n; ++i) {
        i64 x;
        std::cin >> x;
        bit.add(i, i + 1, x);
    }
    for (int i = 0; i < m; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;
            x--;
            bit.add(x, y, k);
        }else {
            int x, y;
            std::cin >> x >> y;
            x--;
            std::cout << bit.query(x, y) << nl;
        }
    }
}
