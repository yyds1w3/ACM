//Tue Apr 21 05:29:37 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    std::vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        dist[u][v] = std::min(dist[u][v], w);
        dist[v][u] = std::min(dist[v][u], w);
    }

    int k = 0;
    int q;
    std::cin >> q;
    while (q--) {
        int u, v, tim;
        std::cin >> u >> v >> tim;
        while (k < n && t[k] <= tim) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] == INF) continue;
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
            k++;
        }
        if (t[v] > tim || t[u] > tim || dist[u][v] == INF) {
            std::cout << -1 << nl;
        }else {
            std::cout << dist[u][v] << nl;
        }
    }
}
