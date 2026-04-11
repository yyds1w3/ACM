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
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const{
        return w > other.w;
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
    std::priority_queue<Edge> pq;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        pq.push({u, v, w});
    }
    DSU dsu(n);
    int ans = 0;
    while (!pq.empty()) {
        auto [u, v, w] = pq.top();
        pq.pop();

        if (!dsu.same(u, v)) {
            dsu.merge(u, v);
            ans += w;
            if (dsu.size(v) == n) {
                std::cout << ans << nl;
                return 0;
            }
        }
    }
    std::cout << "orz" << nl;
}
