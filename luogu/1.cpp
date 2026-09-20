//Sat Aug  1 06:28:19 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const i64 INF = 1e18;
struct st {
    int v;
    i64 d;
    int mask;
    bool operator<(const struct st other) const {
        return d > other.d;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;
    while (T--) {
        int n, m, k, t;
        std::cin >> n >> m >> k >> t;
        
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        std::vector<int> pot(k);
        std::map<int, int> mp;
        std::vector<int> req(k);
        
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        for (int i = 0; i < k; ++i) {
            std::cin >> pot[i];
            pot[i]--;
            mp[pot[i]] = i;
        }
        
        for (int i = 0; i < t; ++i) {
            int u, v;
            std::cin >> u >> v;
            u--, v--;
            req[mp[v]] |= (1 << mp[u]);
        }
        
        std::priority_queue<st> pq;
        std::vector<std::vector<i64>> dist(n, std::vector<i64>(1 << k, INF));
        
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        
        while (!pq.empty()) {
            auto [u, d, mask] = pq.top();
            pq.pop();
            if (d > dist[u][mask]) continue;
            for (auto [v, w] : adj[u]) {
                int nxt_mask = mask;
                if (mp.count(v)) {
                    int idx = mp[v];
                    if ((mask & req[idx]) != req[idx]) {
                        continue;
                    }
                    nxt_mask |= (1 << idx);
                }
                if (dist[u][mask] + w < dist[v][nxt_mask]) {
                    dist[v][nxt_mask] = dist[u][mask] + w;
                    pq.push({v, dist[v][nxt_mask], nxt_mask});
                }
            }
        }
        i64 ans = INF;
        for (int i = 0; i < (1 << k); ++i) {
            ans = std::min(ans, dist[n - 1][i]);
        }
        if (ans == INF) {
            std::cout << "impossible" << nl;
        } else {
            std::cout << ans << nl;
        }
    }
    return 0;
}
