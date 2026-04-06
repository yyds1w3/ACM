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
    std::vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {
        return siz[find(x)];
    }
};
struct st {
    int a, b, c;
    bool operator<(const st& other) const {
        return c > other.c;
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
    DSU dsu(2 * n);
    std::vector<st> v(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].a--, v[i].b--;
    }
    std::sort(v.begin(), v.end());
    for (int i = 0; i < m; ++i) {
        auto [a, b, c] = v[i];
        if (!dsu.same(a, b)) {
            dsu.merge(a + n, b);
            dsu.merge(b + n, a);
        }else {
            std::cout << c << nl;
            return 0;
        }
    }
    std::cout << 0 << nl;
}
