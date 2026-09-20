//Mon Jun  1 08:39:07 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
struct DSU {
    std::vector<int> f, siz;
    int cnt = 0;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cnt = n;
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
        if (rx != ry) {
            f[rx] = ry;
            siz[ry] += siz[rx];
            cnt--;
        }
    }
    int size(int x) {
        return siz[find(x)];
    }
};
void solve() {
    int n, m1, m2;
    std::cin >> n >> m1 >> m2;
    std::vector<std::pair<int, int>> adj1(m1);
    DSU dsu1(n), dsu2(n);
    for (int i = 0; i < m1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj1[i] = {u, v};
    }
    for (int i = 0; i < m2; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        dsu2.merge(u, v);
    }
    int ans = 0;
    for (auto [u, v] : adj1) {
        if (!dsu2.same(u, v)) {
            ans++;
        }else {
            dsu1.merge(u, v);
        }
    }
    std::cout << ans + dsu1.cnt - dsu2.cnt << nl;

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
