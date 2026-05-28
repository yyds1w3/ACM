//Thu Apr 23 01:33:14 PM CST 2026
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
const int INF = 1e9;
struct Point {
    int u, d, k;
    bool operator<(const Point& other) const {
        return d > other.d;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m, K, s, t;
    std::cin >> n >> m >> K >> s >> t;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    std::vector<std::vector<int>> dist(n, std::vector<int>(K + 1, INF));
    std::priority_queue<Point> pq;
    dist[s][0] = 0;
    pq.push({s, 0, 0});
    while (!pq.empty()) {
        auto [u, d, k] = pq.top();
        pq.pop();
        if (d > dist[u][k]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u][k] + w < dist[v][k]) {
                dist[v][k] = dist[u][k] + w;
                pq.push({v, dist[v][k], k});
            }
            if (k == K) continue;
            if (dist[u][k] < dist[v][k + 1]) {
                dist[v][k + 1] = dist[u][k];
                pq.push({v, dist[v][k + 1], k + 1});
            }
        }
    }
    int min_cost = INF;
    for (int i = 0; i <= K; ++i) {
        min_cost = std::min(min_cost, dist[t][i]);
    }
    std::cout << min_cost << nl;
}
