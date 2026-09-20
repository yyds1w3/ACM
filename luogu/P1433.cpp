//Fri Jul 31 09:33:35 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
const double INF = 1e18;
double dp[1<<15][15];
double getDist(double x1, double y1, double x2, double y2) {
    return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<double> x(n), y(n);
    std::vector<std::vector<double>> g(n, std::vector<double>(n, INF));
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; ++i) g[i][i] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = getDist(x[i], y[i], x[j], y[j]);
            if (d < g[i][j]) g[i][j] = g[j][i] = d;
        }
    }
    
    double ans = INF;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; ++i) dp[1<<i][i] = getDist(0, 0, x[i], y[i]);
    for (int i = 1; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                int l = i - (1 << j);
                for (int k = 0; k < n; ++k) {
                    if ((l >> k) & 1) {
                        dp[i][j] = std::min(dp[i][j], dp[l][k] + g[k][j]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ans = std::min(ans, dp[(1 << n) - 1][i]);
    }
    std::cout << std::setprecision(2) << std::fixed << ans << nl;

}
