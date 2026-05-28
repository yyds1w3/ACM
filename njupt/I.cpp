//Thu May 21 09:14:14 AM CST 2026
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
const i64 INF = 1e18;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> s(k), d(n);
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < k; ++i) {std::cin >> s[i]; s[i]--;}
    for (int i = 0; i < n; ++i) std::cin >> d[i];
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    std::priority_queue<std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<std::pair<i64, int>>> pq;
    std::vector<int> cnt(n);
    std::vector<i64> dist(n, INF);
    for (int i = 0; i < k; ++i) {
        dist[s[i]] = 0;
        cnt[s[i]] = d[s[i]];
        pq.push({0, s[i]});
    }
    while (!pq.empty()) {
        auto [di, u] = pq.top();
        pq.pop();
        cnt[u]++;
        if (cnt[u] == d[u] + 1) {
            dist[u] = di;
            for (auto [w, v] : adj[u]) {
                pq.push({dist[u] + w, v});
            }
        }
    }
    if (dist[0] != INF) {
        std::cout << dist[0] << nl;
    }else {
        std::cout << -1 << nl;
    }
}
