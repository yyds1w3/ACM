//Mon Apr 27 09:58:27 AM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--;
            // dv <= du + w;
            // du <= dv - w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, -w});
        }
        std::vector<int> dist(n + 1), cnt(n + 1), inq(n + 1);
        std::queue<int> q;
        for (int i = 0; i <= n; ++i) {
            q.push(i);
            inq[i] = 1;
        }
        bool f = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n + 1) {
                        f = false;
                        break;
                    }
                    if (!inq[v]) {
                        inq[v] = 1;
                        q.push(v);
                    }
                }
            }
            if (!f) break;
        }
        if (!f) {
            std::cout << "false" << nl;
        }else {
            std::cout << "true" << nl;
        }
    }
}
