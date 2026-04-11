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

struct Point {
    int u;
    i64 d;
    bool operator<(const Point& other) const {
        return d > other.d;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int n, m, s;
    std::cin >> n >> m >> s;
    s--;
    std::vector<std::vector<std::pair<int,int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
    }
    std::vector<i64> dist(n, 2e18);
    dist[s] = 0;
    std::priority_queue<Point> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        auto [u, d] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << dist[i] << " ";
    }
}
