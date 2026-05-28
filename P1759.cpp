//Fri Apr 17 03:58:04 PM CST 2026
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
    int m, v, n;
    std::cin >> m >> v >> n;
    std::vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i] >> c[i];
    std::vector dp(n + 2, std::vector(m + 1, std::vector<int>(v + 1, -1e9)));
    dp[n + 1].assign(m + 1, std::vector<int>(v + 1, 0));
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= v; ++k) {
                dp[i][j][k] = dp[i + 1][j][k];
                if (j >= a[i] && k >= b[i]) {
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i + 1][j - a[i]][k - b[i]] + c[i]);
                }
            }
        }
    }
    std::cout << dp[1][m][v] << nl;
    int M = m, V = v;
    std::vector<int> path;
    for (int i = 1; i <= n; ++i) {
        if (M >= a[i] && V >= b[i] && dp[i][M][V] == dp[i + 1][M - a[i]][V - b[i]] + c[i]) {
            path.push_back(i);
            M -= a[i];
            V -= b[i];
        }
    }
    for (int p : path) std::cout << p << " ";
}
