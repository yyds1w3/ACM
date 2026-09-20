//Mon Aug 17 07:58:14 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
const int N = 5e5;
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
    std::string col1, col2;
    std::map<std::string, int> mp;
    std::vector<int> deg(N);
    int tot = -1;
    init(N);
    while (std::cin >> col1 >> col2) {
        if (mp.count(col1) == 0) {
            mp[col1] = ++tot;
        }
        if (mp.count(col2) == 0) {
            mp[col2] = ++tot;
        }
        int u = mp[col1];
        int v = mp[col2];
        deg[u]++;
        deg[v]++;
        merge(u, v);
    }
    int odd = 0;
    for (int i = 0; i <= tot; ++i) {
        if (deg[i] & 1) {
            odd++;
        }
    }
    if (!(odd == 0 || odd == 2) || (size(0) != tot+1 && tot != -1)) {
        std::cout << "Impossible" << nl;
    }else{
        std::cout << "Possible" << nl;
    }

}
