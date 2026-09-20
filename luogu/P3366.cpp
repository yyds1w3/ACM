//Tue Aug 18 04:22:46 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
const int N = 5e3;
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
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--, edges[i].v--;
    }
    std::sort(edges.begin(), edges.end());
    init(n);
    i64 tot = 0;
    for (auto [u, v, w] : edges) {
        if (!same(u, v)) {
            merge(u, v);
            tot += w;
        }
    }
    if (size(0) == n) {
        std::cout << tot << nl;
    }else {
        std::cout << "orz" << nl;
    }
}
