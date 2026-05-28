//Wed Apr 22 07:52:02 PM CST 2026
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
    std::vector<std::vector<std::pair<i64, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({w, v});
    }
    std::vector<i64> h(n), cnt(n), inq(n);
    std::queue<int> q;
    auto spfa = [&]() -> bool {
        for (int i = 0; i < n; ++i) {
            q.push(i);
            inq[i] = 1;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto [w, v] : adj[u]) {
                if (h[u] + w < h[v]) {
                    h[v] = h[u] + w;
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
    if (spfa()) {
        std::cout << -1 << nl;
        return 0;
    }
    for (int u = 0; u < n; ++u) {
        for (auto &[w, v] : adj[u]) {
            w += h[u] - h[v];
        }
    }
    std::vector<i64> dist(n, 2e18);
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
    auto dij = [&](int s) -> void {
        dist.assign(n, 2e18);
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto [w, v] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        i64 ans = 0;
        dij(i);
        for (int j = 0; j < n; ++j) {
            if (dist[j] == 2e18) {
                ans += (j + 1) * 1e9;
            }else {
                ans += (j + 1) * (dist[j] + h[j] - h[i]);
            }
        }
        std::cout << ans << nl;
    }
}
