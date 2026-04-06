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
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
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

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, k;
    std::cin >> n >> k;
    DSU dsu(3 * n);
    int cnt = 0;
    while (k--) {
        int d, x, y;
        std::cin >> d >> x >> y;
        x--, y--;
        if (x < 0 || x >= n || y < 0 || y >= n) {
            cnt++;
            continue;
        }
        if (d == 1) {
            if (dsu.same(x + n, y) || dsu.same(y + n, x)) {
                cnt++;
            }else {
                dsu.merge(x, y);
                dsu.merge(x + n, y + n);
                dsu.merge(x + 2 * n, y + 2 * n);
            }
        }else if (d == 2) {
            if (dsu.same(x, y) || dsu.same(y + n, x)) {
                cnt++;
            }else {
                dsu.merge(x, y + 2 * n);
                dsu.merge(x + n, y);
                dsu.merge(x + 2 * n, y + n);
            }
        }
    }
    std::cout << cnt << nl;
}
