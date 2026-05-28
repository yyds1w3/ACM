//Wed Apr 22 05:08:19 PM CST 2026
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
    std::vector f(n, std::vector(n, std::vector<int>(n, INF)));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        f[u][v][1] = std::min(f[u][v][1], w);
    }
    for (int k = 2; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int i = 0; i < n; ++i) {
                if (f[i][u][k-1] == INF) continue;
                for (int j = 0; j < n; ++j) {
                    if (f[u][j][1] == INF) continue;
                    f[i][j][k] = std::min(f[i][j][k], f[i][u][k-1] + f[u][j][1]);
                }
            }
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        double ans = INF;
        for (int k = 1; k < n; ++k) {
            if (f[u][v][k] == INF) continue;
            ans = std::min(ans, (double)f[u][v][k] / k);
        }
        if (std::abs(ans - INF) < 1e-3) {
            std::cout << "OMG!" << nl;
        }else {
            std::cout << std::setprecision(3) << std::fixed << ans << nl;
        }
    }
}

