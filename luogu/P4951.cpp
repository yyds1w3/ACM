//Tue Aug 18 04:32:22 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
struct Edge {
    int u, v, c, t;
};
const int N = 400;
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
    int n, m, f;
    std::cin >> n >> m >> f;
    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        int u, v, c, t;
        std::cin >> u >> v >> c >> t;
        u--, v--;
        edges[i] = {u, v, c, t};
    }
    auto check = [&](double x) -> bool {
        std::sort(edges.begin(), edges.end(), [&](const Edge& lhs, const Edge& rhs){
            return lhs.t * x + lhs.c < rhs.t * x + rhs.c;
        });
        init(n);
        double tot = 0;
        for (int i = 0; i < m; ++i) {
            if (!same(edges[i].u, edges[i].v)) {
                merge(edges[i].u, edges[i].v);
                tot += x * edges[i].t + edges[i].c;
                if (tot > f) {
                    return false;
                }
            }
        }
        return true;
    };
    double l = 0, r = 2e9;
    for (int i = 0; i < 80; ++i) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    std::cout << std::setprecision(4) << std::fixed << l << nl;
}
