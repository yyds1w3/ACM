//Mon Jun 15 07:08:47 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
struct DSU {
    std::vector<int> f, siz, cntA;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
        cntA.assign(n, 0);
    }
    int find(int x) {
        if (f[x] == x) return x;
        return f[x] = find(f[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            f[rx] = ry;
            siz[ry] += siz[rx];
            cntA[ry] += cntA[rx];
        }
    }
    int size(int x) {
        return siz[find(x)];
    }
    int cnta(int x) {
        return cntA[find(x)];
    }
};
void solve() {
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector<int> a(n), b(m), c(n + m);
    DSU dsu(n + m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
        c[i + n] = b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(c.begin(), c.end());
    for (int i = 0, j = 0; i < n + m && j < n; ++i) {
        if (c[i] == a[j]) {
            dsu.cntA[i]++;
            j++;
        }
    }
    std::vector<i64> pi(n + m + 1);
    for (int i = 0; i < n + m; ++i) {
        pi[i + 1] = pi[i] + c[i];
    }
    std::vector<std::pair<int, int>> d(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> d[i].first;
        d[i].second = i;
    }
    std::sort(d.begin(), d.end());
    std::vector<std::pair<int, int>> gaps;
    for (int i = 0; i < n + m - 1; ++i) {
        gaps.push_back({c[i + 1] - c[i], i});
    }
    std::sort(gaps.begin(), gaps.end());
    std::vector<i64> ans(q);
    i64 cur = std::accumulate(a.begin(), a.end(), 0LL);
    int idx = 0;
    for (int i = 0; i < q; ++i) {
        int k = d[i].first;
        while (idx < (int)gaps.size() && gaps[idx].first <= k) {
            int u = gaps[idx].second;
            int v = u + 1;
            u = dsu.find(u);
            v = dsu.find(v);
            if (u != v) {
                cur -= pi[u + 1] - pi[u + 1 - dsu.cnta(u)];
                cur -= pi[v + 1] - pi[v + 1 - dsu.cnta(v)];
                dsu.merge(u, v);
                cur += pi[v + 1] - pi[v + 1 - dsu.cnta(v)];
                idx++;
            }
        }
        ans[d[i].second] = cur;
    }
    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << nl;
    }

}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
