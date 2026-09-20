//Mon Jul 27 06:48:53 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
double dp[2002][5002][2][2];
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(n + 1), c(n + 1), d(n + 1), e(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i] >> p[i];
    }
    for (int i = n; i >= 1; --i) {
        double x = p[i] * 1.0 / 100;
        double y = 1.0 - x;
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {
                    double res = -2e18;
                    if (j + b[i] <= m) {
                        res = std::max(res, dp[i + 1][j + b[i]][1][l] * x + dp[i + 1][j + b[i]][k][1] * y + a[i]);
                    }
                    if (k && l) {
                        if (j + d[i] + e[i] <= m) {
                            res = std::max(res, dp[i + 1][j + d[i] + e[i]][0][0] + c[i]);
                        }
                    }else {
                        if (j + d[i] <= m) {
                            res = std::max(res, dp[i + 1][j + d[i]][1][l] * x + dp[i + 1][j + d[i]][k][1] * y + c[i]);
                        }
                    }
                    dp[i][j][k][l] = res;
                }
            }
        }
    }
    if (dp[1][0][0][0] < 0) std::cout << -1 << nl;
    else std::cout << std::setprecision(6) << std::fixed << dp[1][0][0][0] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
