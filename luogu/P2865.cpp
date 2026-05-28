//Tue Apr 21 09:56:53 PM CST 2026
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
    int n, r;
    std::cin >> n >> r;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < r; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    std::vector<i64> dist1(n, INF), dist2(n, INF);
    dist1[0] = 0; // 注意次短路应该是INF
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist2[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (d + w < dist1[v]) {
                dist2[v] = dist1[v];
                dist1[v] = d + w;
                pq.push({dist1[v], v});
                pq.push({dist2[v], v});
            }else if (d + w < dist2[v] && d + w > dist1[v]) {
                dist2[v] = d + w;
                pq.push({dist2[v], v});
            }
        }
    }
    std::cout << dist2[n - 1] << nl;

}
