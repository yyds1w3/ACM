//Mon Apr 20 08:52:25 PM CST 2026
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
    std::vector<std::vector<i64>> dist(n + 1, std::vector<i64>(n + 1, 2e18));
    for (int i = 0; i <= n; ++i) {
        dist[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        i64 a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = std::min(dist[a][b], c);
        dist[b][a] = std::min(dist[b][a], c);
    }
    int k, t;
    std::cin >> k >> t;
    for (int i = 0; i < k; ++i) {
        int d;
        std::cin >> d;
        d--;
        dist[d][n] = t;
        dist[n][d] = 0;
    }
    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            i64 x, y, cost;
            std::cin >> x >> y >> cost;
            x--, y--;
            dist[x][y] = std::min(dist[x][y], cost);
            dist[y][x] = std::min(dist[y][x], cost);
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= n; ++j) {
                    dist[i][j] = std::min({dist[i][j],
                        dist[i][x] + dist[x][y] + dist[y][j],
                        dist[i][y] + dist[y][x] + dist[x][j]});
                }
            }
        }else if (op == 2) {
            int x;
            std::cin >> x;
            x--;
            dist[x][n] = t;
            dist[n][x] = 0;
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= n; ++j) {
                    dist[i][j] = std::min({dist[i][j],
                        dist[i][x] + dist[x][n] + dist[n][j],
                        dist[i][n] + dist[n][x] + dist[x][j]});
                }
            }
        }else {
            i64 ans = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][j] < 2e18) {
                        ans += dist[i][j];
                    }
                }
            }
            std::cout << ans << nl;
        }
    }
}
