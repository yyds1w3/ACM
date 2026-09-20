//Sat Sep  5 03:15:30 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cout << #x << ": " << x << nl 
#define debugv(v, sz) do{std::cout << #v << "[]:" << nl;\
for (int i = 0; i < sz; ++i) std::cout << v[i] << " "; std::cout << nl;}while(0)
#define debugvv(v, sz1, sz2) do{std::cout << #v << "[][]:" << nl;\
for (int i = 0; i < sz1; ++i) {std::cout << i << ":";for (int j = 0; j < sz2; ++j) std::cout << v[i][j] << " "; std::cout<<nl;}}while(0)
using i64 = long long;
using i128 = __int128;
struct Node {
    i64 d, u, use;
    bool operator<(const Node& other) const {
        return d > other.d;
    }
};
std::ostream& operator<<(std::ostream& os, Node& rhs) {
    return os << "[" << "," << "]";
}
const int N = 5000;
const i64 INF = 2e18;
i64 dist[N][N + 1];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
    }
    // {d, u};
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>,std::greater<std::pair<i64, int>>> pq;
    for (int i = 0; i < n; ++i) for (int j = 0; j <= n; ++j) {
        dist[i][j] = INF;
    }
    dist[0][0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u][0]) continue;
        for (auto [v, w] : adj[u]) {
            if (w > 0) {
                if (dist[v][0] > dist[u][0] + w) {
                    dist[v][0] = dist[u][0] + w;
                    pq.push({dist[v][0], v});
                }
            }
        }
    }
    i64 ans = 0;
    for (int i = 0; i < n; ++i) ans += dist[i][0];
    std::cout << ans << nl;

    for (int k = 1; k <= n; ++k) {
        for (int u = 0; u < n; ++u) {
            dist[u][k] = dist[u][k - 1];
        }
        for (int u = 0; u < n; ++u) {
            for (auto [v, w] : adj[u]) {
                if (w == 0) {
                    dist[v][k] = std::min(dist[v][k], dist[u][k-1]);
                }
            }
        }
        for (int u = 0; u < n; ++u) {
            pq.push({dist[u][k], u});
        }
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u][k]) continue;
            for (auto [v, w] : adj[u]) {
                if (w > 0) {
                    if (dist[v][k] > dist[u][k] + w) {
                        dist[v][k] = dist[u][k] + w;
                        pq.push({dist[v][k], v});
                    }
                }
            }
        }
        ans = 0;
        for (int u = 0; u < n; ++u) {
            ans += dist[u][k];
        }
        std::cout << ans << nl;
    }
}
