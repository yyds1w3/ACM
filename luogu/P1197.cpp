#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;

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
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            f[rx] = ry;
            siz[ry] += siz[rx];
            return true;
        }
        return false;
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int k;
    std::cin >> k;
    std::vector<int> b(k);
    std::vector<bool> broken(n);
    for (int i = 0; i < k; ++i) {
        std::cin >> b[i];
        broken[b[i]] = true;
    }
    DSU dsu(n);
    int cnt = n - k;
    for (int u = 0; u < n; ++u) {
        if (broken[u]) continue;
        for (int v : adj[u]) {
            if (broken[v]) continue;
            if (dsu.merge(u, v)) {
                cnt--;
            }
        }
    }
    std::vector<int> ans(k + 1);
    ans[k] = cnt;
    for (int i = k - 1; i >= 0; --i) {
        int u = b[i];
        broken[u] = false;
        cnt++;
        for (int v : adj[u]) {
            if (broken[v]) continue;
            if (dsu.merge(u, v)) {
                cnt--;
            }
        }
        ans[i] = cnt;
    }
    for (int i = 0; i <= k; ++i) {
        std::cout << ans[i] << nl;
    }
}
