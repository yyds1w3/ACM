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
struct Info {
    int u, v, t;
    bool operator<(const Info & other) const {return t < other.t;}
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int N, M;
    std::cin >> N >> M;
    DSU dsu(N);
    std::vector<Info> A(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i].u >> A[i].v >> A[i].t;
        A[i].u--;
        A[i].v--;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < M; ++i) {
        auto [u, v, t] = A[i];
        if (u > v) std::swap(u, v);
        dsu.merge(u, v);
        if (dsu.size(0) == N) {
            std::cout << t << nl;
            return 0;
        }
    }
    std::cout << -1 << nl;
}
