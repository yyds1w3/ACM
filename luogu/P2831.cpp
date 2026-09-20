//Tue Aug  4 02:49:33 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
#define debug(x) std::cerr << #x << ": " << x << nl; 
struct st{
    double x, y;
};
const double eps = 1e-6;
const double INF = 1e18;
int lowunbit[1<<18];
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> line(n, std::vector<int>(n));
    std::vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    auto f = [&](double a1, double b1, double c1, double a2, double b2, double c2) -> st {
        return {(c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1), (c1 * a2 - c2 * a1) / (a2 * b1 - a1 * b2)};
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (x[i] == x[j]) continue;
            auto [a, b] = f(x[i] * x[i], x[i], y[i], x[j] * x[j], x[j], y[j]);
            if (a < -eps) {
                line[i][j] |= (1 << i);
                line[i][j] |= (1 << j);
                for (int k = 0; k < n; ++k) {
                    if (std::fabs(a * x[k] * x[k] + b * x[k] - y[k]) < eps) {
                        line[i][j] |= (1 << k);
                    }
                }
            }
        }
    }
    std::vector<double> dp(1<<n, INF);
    dp[0] = 0;
    for (int S = 0; S < (1 << n) - 1; ++S) {
        int j = lowunbit[S];
        dp[S | (1 << j)] = std::min(dp[S | (1 << j)], dp[S] + 1);
        for (int k = 0; k < n; ++k) {
            dp[S | line[j][k]] = std::min(dp[S | line[j][k]], dp[S] + 1);
        }
    }
    std::cout << dp[(1 << n) - 1] << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    for (int i = 0; i < 1 << 18; ++i) {
        for (int j = 0; j < 18; ++j) {
            if (!((i >> j) & 1)) {
                lowunbit[i] = j; break;
            }
        }
    }
    int t;
    std::cin >> t;
    while (t--) solve();
}
