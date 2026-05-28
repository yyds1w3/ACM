//Wed Apr 22 07:10:19 PM CST 2026
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
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            std::cin >> u >> v >> w;
            u--, v--;
            if (w >= 0) {
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
            else adj[u].push_back({v, w});
        }
        auto spfa = [&]() -> bool {
            std::vector<int> dist(n, INF), cnt(n), inq(n);
            std::queue<int> q;
            q.push(0);
            inq[0] = 1;
            dist[0] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                inq[u] = 0;
                for (auto [v, w] : adj[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        cnt[v] = cnt[u] + 1;
                        if (cnt[v] >= n) return true;
                        if (!inq[v]) {
                            inq[v] = 1;
                            q.push(v);
                        }
                    }
                }
            }
            return false;
        };
        if (spfa()) {
            std::cout << "YES" << nl;
        }else {
            std::cout << "NO" << nl;
        }
    }
}
