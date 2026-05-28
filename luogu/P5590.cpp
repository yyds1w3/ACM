//Tue Apr 28 10:14:18 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> edges(m);
    std::vector<std::vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        // 9 >= v - u >= 1
        edges[i] = {u, v};
        adj[u].push_back({v});
        radj[v].push_back({u});
    }
    auto bfs = [&](int s, std::vector<std::vector<int>>& adj) {
        std::vector<bool> vis(n);
        std::queue<int> q;
        q.push(s);
        vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return vis;
    };
    auto vis1 = bfs(0, adj);
    auto vis2 = bfs(n-1, radj);
    if (!vis1[n-1]) {
        std::cout << -1 << nl;
        return 0;
    }
    std::vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        vis[i] = vis1[i] & vis2[i];
    }
    std::vector<std::vector<std::pair<int, int>>> Adj(n);
    for (auto [u, v] : edges) {
        if (vis[u] && vis[v]) {
            Adj[u].push_back({v, 9});
            Adj[v].push_back({u, -1});
        }
    }
    std::vector<i64> dist(n), cnt(n), inq(n);
    std::queue<int> q;
    auto spfa = [&]() -> bool {
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                q.push(i);
                dist[i] = 0;
                inq[i] = 1;
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto [v, w] : Adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n) return true;
                    if (!inq[v]) {
                        q.push(v);
                        inq[v] = true;
                    }
                }
            }
        }
        return false;
    };
    if (spfa()) {
        std::cout << -1 << nl;
    }else {
        std::cout << n << " " << m << nl;
        for (auto [u, v] : edges) {
            if (vis[u] && vis[v]) {
                std::cout << u + 1 << " " << v + 1 << " " << dist[v] - dist[u] << nl;
            }else {
            std::cout << u + 1 << " " << v + 1 << " " << 1 << nl;
            }
        }
    }
}
