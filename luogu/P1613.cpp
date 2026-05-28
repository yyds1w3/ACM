//Tue Apr 21 05:56:52 PM CST 2026
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
bool g[50][50][64];

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m;
    std::cin >> n >> m;
    // dist 的初始化
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));
    for (int i = 0; i < n; ++i) dist[i][i] = 0;
    // 读入数据 初始化倍增数组和dist的长为1的边
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u][v][0] = true;
        dist[u][v] = 1;
    }
    // 开始倍增建图
    for (int s = 1; s < 64; ++s) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (g[i][k][s-1] && g[k][j][s-1]) {
                        g[i][j][s] = true;
                        dist[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    std::cout << dist[0][n-1] << nl;
}
