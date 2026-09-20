//Sat Sep  5 09:41:14 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}
const int N = 5e5;
std::vector<int> f(N), sz(N);
void initDSU(int n) {
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
    int u, v;
    initDSU(N);
    bool ok = true;
    int cnt = 0;
    int target = 0;
    std::vector<bool> vis(N);
    while (std::cin >> u >> v) {
        if (u == -1 && v == -1) break;
        if (u == 0 && v == 0) {
            if ((target == 0) || (ok && target - cnt == 1)) {
                std::cout << "Yes" << nl;
            }else {
                std::cout << "No" << nl;
            }
            initDSU(N);
            ok = true;
            cnt = 0;
            target = 0;
            vis.assign(N, false);
            continue;
        }
        u--, v--;
        if (same(u, v)) {
            ok = false;
        }else {
            merge(u, v);
            cnt++;
        }
        if (!vis[u]) {
            vis[u] = true;
            target++;
        }
        if (!vis[v]) {
            vis[v] = true;
            target++;
        }
    }
}
