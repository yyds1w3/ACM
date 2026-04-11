#include <bits/stdc++.h>
#include <vector>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }
    int ans = (1 << 30) - 1;
    for (int i = 29; i >= 0; --i) {
        int mask = ans ^ (1 << i);
        DSU dsu(n);
        for (int j = 0; j < m; ++j) {
            if ((w[j] | mask) == mask) {
                dsu.merge(u[j], v[j]);
            }
        }
        if (dsu.same(0, n-1)) {
            ans = mask;
        }
    }
    std::cout << ans << nl;
}
