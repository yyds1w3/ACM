//Tue Aug 18 08:23:58 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
struct Edge {
    int u, v;
    double w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
const int N = 5e2;
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
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int s;
    std::cin >> s >> n;
    init(n);
    std::vector<int> x(n), y(n);
    auto getDist = [&] (int u, int v) -> double {
        return std::hypot(x[u] - x[v], y[u] - y[v]);
    };
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    std::vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({i, j, getDist(i, j)});
        }
    }
    std::sort(edges.begin(), edges.end());
    double mx = 0;
    int tot = 0;
    for (auto [u, v, w] : edges) {
        if (!same(u, v)) {
            merge(u, v);
            tot++;
            if (tot == n - s) {
                mx = w;
                break;
            }
        }
    }
    std::cout << std::setprecision(2) << std::fixed << mx << nl;
}
