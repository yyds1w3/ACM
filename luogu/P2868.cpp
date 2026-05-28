//Wed Apr 22 04:43:43 PM CST 2026
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


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
#endif
    int n, m;
    std::cin >> n >> m;
    std::vector<int> f(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i];
    }
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    auto spfa = [&](double x) -> bool {
        std::vector<double> dist(n);
        std::vector<int> cnt(n), inq(n);
        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i);
            inq[i] = 1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto [v, w] : adj[u]) {
                double wei = x * w - f[v];
                if (dist[u] + wei< dist[v]) {
                    dist[v] = dist[u] + wei;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n) return true;
                    if (!inq[v]) {
                        inq[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
        return false;
    };
    double l = 0, r = 1000;
    for (int i = 0; i < 30; ++i) {
        double mid = (l + r) / 2;
        if (spfa(mid)) {
            l = mid;
        }else {
            r = mid;
        }
    }
    std::cout << std::setprecision(2) << std::fixed << l << nl;
}
