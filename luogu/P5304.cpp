//Thu Apr 23 02:30:16 PM CST 2026
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
const i64 INF = 2e18;


int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::vector<std::pair<int, i64>>> adj1(n), adj2(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            i64 w;
            std::cin >> u >> v >> w;
            u--, v--;
            if (u == v) continue; 
            adj1[u].push_back({v, w});
            adj2[v].push_back({u, w});
        }
        std::vector<int> citys(k);
        for (int i = 0; i < k; ++i) {
            std::cin >> citys[i];
            citys[i]--;
        }
        std::vector<i64> dist1(n, INF), dist2(n ,INF), cols1(n, -1), cols2(n, -1);
        auto dij1 = [&]() -> void {
            std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
            for (int i = 0; i < k; ++i) {
                int u = citys[i];
                dist1[u] = 0;
                cols1[u] = u;
                pq.push({0, u});
            }
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist1[u]) continue;
                for (auto [v, w] : adj1[u] ) {
                    if (dist1[u] + w < dist1[v]) {
                        dist1[v] = dist1[u] + w;
                        cols1[v] = cols1[u];
                        pq.push({dist1[v], v});
                    }
                }
            }
        };
        auto dij2 = [&]() -> void {
            std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
            for (int i = 0; i < k; ++i) {
                int u = citys[i];
                dist2[u] = 0;
                cols2[u] = u;
                pq.push({0, u});
            }
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if (d > dist2[u]) continue;
                for (auto [v, w] : adj2[u] ) {
                    if (dist2[u] + w < dist2[v]) {
                        dist2[v] = dist2[u] + w;
                        cols2[v] = cols2[u];
                        pq.push({dist2[v], v});
                    }
                }
            }
        };
        dij1();
        dij2();
        i64 ans = INF;
        for (int u = 0; u < n; ++u) {
            for (auto [v, w] : adj1[u]) {
                if (cols1[u] == -1 || cols2[v] == -1) continue;
                if (cols1[u] != cols2[v]) {
                    ans = std::min(ans, dist1[u] + dist2[v] + w);
                }
            }
        }
        std::cout << ans << nl;
    }
}
