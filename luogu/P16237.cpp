//2026-04-11 15:02:20
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
    std::vector<int> f, mnn;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        mnn.assign(n, 0);
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        mnn[ry] = std::min(mnn[rx], mnn[ry]) + 1;
        mnn[rx] = mnn[ry];
        if (rx != ry) {
            f[rx] = ry;
        }
    }
    int size(int x) {
        return mnn[find(x)];
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    int tot = n;
    DSU dsu(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        if (!dsu.same(u, v)) {
            tot--;
        }
        dsu.merge(u, v);
    }
    int mn = 0;
    for (int i = 0; i < n; ++i) {
        mn = std::max(mn, dsu.mnn[i]);
    }
    std::cout << tot - 1 << " " << mn + 1 << nl;
}
