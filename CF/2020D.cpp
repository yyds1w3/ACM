//Mon Aug 24 06:31:51 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct st {
};
std::ostream& operator<<(std::ostream& os, st& rhs) {
    return os;
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
void solve() {
    int n, m;
    std::cin >> n >> m;
    init(n);
    std::vector<int> a(m), d(m), k(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> a[i] >> d[i] >> k[i];
        a[i]--;
    }
    int ans = n;
    for (int x = 1; x <= 10; ++x) {
        std::vector<int> diff(n + 1);
        for (int i = 0; i < m; ++i) {
            if (d[i] == x) {
                diff[a[i]]++;
                diff[a[i] + k[i] * x]--;
            }
        }
        for (int i = x; i < n; ++i) {
            diff[i] += diff[i - x];
        }
        for (int i = 0; i < n; ++i) {
            if (diff[i] && !same(i, i + x)) {
                merge(i, i + x);
                ans--;
            }
        }

    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
