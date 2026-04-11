#include <bits/stdc++.h>
#include <vector>
using ll = long long;
using i128 = __int128;
#define nl "\n"
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, M; std::cin >> N >> M;
    std::vector<int> deg(N);
    DSU dsu(N);
    for (int i = 0; i < M; ++i) {
        int u, v; std::cin >> u >> v;
        u--, v--;
        deg[u]++;
        deg[v]++;
        dsu.merge(u, v);
    }
    for (int i = 0; i < N; ++i) {
        if (!dsu.same(0, i) || deg[i] != 2) {
            std::cout << "No" << nl;
            return 0;
        }
    }
    std::cout << "Yes" << nl;
}
