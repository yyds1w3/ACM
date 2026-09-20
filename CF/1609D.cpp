//Sat Aug 22 03:46:39 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
const int N = 1e3;
int n, d;
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
std::ostream& operator<<(std::ostream& os, std::pair<int, int> rhs) {
    return os << '[' << rhs.first << " " << rhs.second << ']';
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    std::cin >> n >> d;
    init(n);
    int free = 0;
    for (int i = 0; i < d; ++i) {
        int ans = 0;
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        if (!same(u, v)) {
            merge(u, v);
        }else {
            free++;
        }
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                a.push_back(size(i));
            }
        }
        std::sort(a.rbegin(), a.rend());
        for (int i = 0; i < std::min((int)a.size(), 1 + free); ++i) {
            ans += a[i];
        }
        std::cout << ans - 1 << nl;
    }
}
