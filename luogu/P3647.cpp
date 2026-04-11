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
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, 1e9));
    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        dist[u][v] = std::min(dist[u][v], w);
        dist[v][u] = std::min(dist[v][u], w);
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << dist[i][j] << " ";
        }
        std::cout << nl;
    }
}
