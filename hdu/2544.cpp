//Tue Apr 21 10:18:55 PM CST 2026
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define nl "\n"
using i64 = long long;
const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) break;
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        std::vector<int> dist(n, INF);
        dist[0] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto edge : adj[u]) {
                int w = edge.first;
                int v = edge.second;
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        std::cout << dist[n - 1] << nl;
    }
}
