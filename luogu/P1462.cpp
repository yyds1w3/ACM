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
struct Edge {
    i64 to, w;
    bool operator<(const Edge& other) const {
        return w > other.w;
    }
    friend std::ostream& operator<<(std::ostream& os, const struct Edge b) {
        return os << b.to << "," << b.w;
    } 
};
const i64 INF = 2e18;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 n, m, b;
    std::cin >> n >> m >> b;
    std::vector<int> f(n);
    int mx_f = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> f[i];
        mx_f = std::max(mx_f, f[i]);
    }
    std::vector adj(n, std::vector<Edge>());
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    debug(adj);
    auto check = [&](int x) -> bool {
        std::priority_queue<Edge> pq;
        std::vector<i64> dist(n, INF);
        dist[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [u, d] = pq.top();
            pq.pop();
            if (dist[u] < d) continue;
            for (auto [v, w] : adj[u]) {
                if (f[v] > x) continue;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({v, dist[v]});
                }
            }
        }
        return dist[n - 1] <= b;
    };
    int L = std::max(f[0], f[n - 1]), R = mx_f + 1;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid)) {
            R = mid; 
        }else {
            L = mid + 1;
        }
    }
    if (L == mx_f + 1) {
        std::cout << "AFK" << nl;
    }else {
        std::cout << L << nl;   
    }
}
