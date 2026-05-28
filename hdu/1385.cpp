//Tue Apr 21 04:51:38 PM CST 2026
#include <iostream>
#include <vector>
#include <algorithm>
#define nl "\n"
using i64 = long long;
const i64 INF = 2e18;

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;

    while (std::cin >> n) {

        std::vector<std::vector<i64>> dist(n, std::vector<i64>(n)), nxt(n, std::vector<i64>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                i64 w;
                std::cin >> w;
                if (w == -1) {
                    dist[i][j] = INF;
                    nxt[i][j] = -1;
                }else {
                    dist[i][j] = w;
                    nxt[i][j] = j;
                }
            }
        }
        std::vector<i64> b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] == INF) continue;
                    if (i == j || i == k || j == k) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j] + b[k]) {
                        dist[i][j] = dist[i][k] + dist[k][j] + b[k];
                        nxt[i][j] = nxt[i][k];
                    }else if (dist[i][j] == dist[i][k] + dist[k][j] + b[k]) {
                        nxt[i][j] = std::min(nxt[i][j], nxt[i][k]);
                    }
                }
            }
        }
        int u, v;
        while (std::cin >> u >> v) {
            if (u == -1 && v == -1) break;
            u--, v--;
            std::cout << "From " << u + 1 << " to " << v + 1 << " :" << nl;
            std::cout << "Path: " << u + 1;
            for (int cur = u; cur != v; cur = nxt[cur][v]) {
                std::cout << "-->" << nxt[cur][v] + 1;
            }
            std::cout << nl;
            if (dist[u][v] < INF) {
                std::cout << "Total cost : " << dist[u][v] << nl; 
            }else {
                std::cout << -1 << nl;
            }
            std::cout << nl;
        }
    }
}
