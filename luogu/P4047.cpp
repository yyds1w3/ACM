//Tue Aug 18 09:09:31 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 1e3;
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
    int u, v;
    double w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    init(n);
    std::vector<int> x(n), y(n);
    std::vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({i, j, std::hypot(x[i] - x[j], y[i] - y[j])});
        }
    }
    std::sort(edges.begin(), edges.end());
    int t = n - k;
    double mn = 0;
    for (auto [u, v, w] : edges) {
        if (t > 0) {
            if (!same(u, v)) {
                t--;
                merge(u, v);
            }
        }else {
            if (!same(u, v)) {
                mn = w;
                break;
            }
        }
    }
    std::cout << std::setprecision(2) << std::fixed << mn << nl;
}
