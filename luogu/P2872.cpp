//Tue Aug 18 07:30:58 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 1e3;
int n, m;
std::vector<int> f(N), sz(N);
std::vector<i64> x(N), y(N);
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
double getDist(int u, int v) {
    if (same(u, v)) return 0;
    return std::sqrtl((x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    init(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        merge(u, v);
    }
    double tot = 0;
    std::vector<double> d(n);
    d[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (!same(0, i)) {
            d[i] = getDist(0, i);
        }
    }
    std::vector<bool> vis(n);
    vis[0] = true;
    for (int i = 1; i < n; ++i) {
        int u = -1;
        double mndist = 1e18;
        for (int j = 1; j < n; ++j) {
            if (!vis[j]) {
                if (d[j] < mndist) {
                    u = j;
                    mndist = d[j];
                }
            }
        }
        if (u != -1) {
            vis[u] = true;
            tot += mndist;
            for (int i = 0; i < n; ++i) {
                d[i] = std::min(d[i], getDist(u, i));
            }
        }
    }
    std::cout << std::setprecision(2) << std::fixed << tot << nl;
}
