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

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};
struct Qus {
    int k, u, id;
    bool operator<(const Qus& other) const {
        return k > other.k;
    }
};
struct DSU {
    std::vector<int> f, siz;
    DSU(){}
    DSU(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        if (x == f[x]) return x;
        return f[x] = find(f[x]);
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            f[rx] = ry;
            siz[ry] += siz[rx];
        }
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
    int n, q;
    std::cin >> n >> q;
    std::vector<Edge> v(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> v[i].u >> v[i].v >> v[i].w;
        v[i].u--, v[i].v--;
    }
    std::vector<Qus> qus(q);
    for (int i = 0; i < q; ++i) {
        std::cin >>qus[i].k >> qus[i].u;
        qus[i].u--;
        qus[i].id = i;
    }
    std::vector<int> ans(q);
    std::sort(v.begin(), v.end());
    std::sort(qus.begin(), qus.end());
    DSU dsu(n);
    for (int i = 0, j = 0; i < q; ++i) {
        while (j < n - 1 && v[j].w >= qus[i].k) {
            dsu.merge(v[j].u, v[j].v);
            j++;
        }
        ans[qus[i].id] = dsu.size(qus[i].u) - 1;
    }
    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << nl;
    }

}
