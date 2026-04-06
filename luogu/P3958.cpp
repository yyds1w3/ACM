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
struct Point {
    int x, y, z;
};
i128 dist(Point p1, Point p2){
    auto [x1, y1, z1] = p1;
    auto [x2, y2, z2] = p2;
    return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2) + 1LL * (z1 - z2) * (z1 - z2);
}
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
void solve() {
    i64 n, h, r;
    std::cin >> n >> h >> r;
    std::vector<Point> v(n + 2);
    DSU dsu(n + 2);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i + 2].x >> v[i + 2].y >> v[i + 2].z;
    }
    for (int i = 2; i < n + 2; ++i) {
        for (int j = 0; j < i; ++j) {
            if (j == 0) {
                if (v[i].z <= r) {
                    dsu.merge(0, i);
                }
            }else if (j == 1) {
                if (v[i].z + r >= h) {
                    dsu.merge(1, i);
                }
            }else {
                if (dist(v[i], v[j]) <= (i128)4 * r * r) {
                    dsu.merge(j, i);
                }
            }
            if (dsu.same(0, 1)) {
                std::cout << "Yes" << nl;
                return;
            }
        }
    }
    std::cout << "No" << nl;
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
