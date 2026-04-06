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
    std::vector<int> f, siz, val;
    DSU(){}
    DSU(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        val.assign(n, 0);
    }
    int find(int x) {
        if (f[x] == x) return x;
        int root = find(f[x]);
        val[x] += val[f[x]];
        return f[x] = root;
    }
    bool merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return false;
        f[rx] = ry;
        val[rx] = siz[ry];
        siz[ry] += siz[rx];
        return true;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool size(int x) {
        return siz[find(x)];
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int T;
    std::cin >> T;
    DSU dsu(3e4);
    while (T--) {
        char op;
        std::cin >> op;
        if (op == 'M') {
            int i, j;
            std::cin >> i >> j;
            dsu.merge(i, j);
        }else if (op == 'C') {
            int i, j;
            std::cin >> i >> j;
            if (!dsu.same(i, j)) {
                std::cout << -1 << nl;
            }else {
                std::cout << std::abs(dsu.val[j] - dsu.val[i]) - 1 << nl;
            }
        }
    }
}
