//Fri Aug 21 09:08:04 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
std::ostream& operator<<(std::ostream& os, const Edge& rhs) {
    auto [u, v, w] = rhs;
    return os << "{" << u << "," << v << "," << w << "}";
}
const int N = 2e5;
int n;
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
    std::cin >> n;
    init(n);
    std::vector<int> a(n);
    std::vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int g = 0;
    for (int i = 0; i < n; ++i) {
        g = std::gcd(g, a[i]);
        edges.push_back({0, i, g});
    }
    g = 0;
    for (int i = n - 1; i >= 0; --i) {
        g = std::gcd(g, a[i]);
        edges.push_back({n-1, i, g});
    }
    std::sort(edges.begin(), edges.end());
    i64 ans = 0;
    for (auto [u, v, w] : edges) {
        if (!same(u, v)) {
            merge(u, v);
            ans += w;
        }
    }
    std::cout << ans << nl;
}
