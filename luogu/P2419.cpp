//Wed Apr 22 06:55:45 PM CST 2026
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
    std::vector<std::vector<int>> f(n, std::vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        f[u][v] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (f[i][k] == 0) continue;
            for (int j = 0; j < n; ++j) {
                f[i][j] |= f[k][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool possible = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (!f[i][j] && !f[j][i]) {
                possible = false;
            }
        }
        if (possible) ans++;
    }
    std::cout << ans << nl;
}
