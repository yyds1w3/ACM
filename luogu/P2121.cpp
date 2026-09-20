//Tue Aug 18 09:03:26 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 1e5;
int n, m;
std::vector<int> f(N), sz(N);
void init(int n) {
    std::iota(f.begin(), f.begin() + n, 0);
    sz.assign(n, 1);
}
int find(int x) {
    if (f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        f[rx] = ry;
        sz[ry] += sz[rx];
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}
int size(int x) {
    return sz[find(x)];
}
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    init(n);
    std::vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w});
    }
    std::sort(edges.rbegin(), edges.rend());
    i64 ans = 0;
    for (auto [u, v, w] : edges) {
        if (!same(u, v) && k > 0) {
            merge(u, v);
            ans += w;
            k--;
        }
    }
    std::cout << ans << nl;
}
