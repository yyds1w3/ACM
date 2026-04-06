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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<std::vector<double>> dp((1 << n), std::vector<double>(n, 1e9));

    auto getDist= [](double x1, double y1, double x2, double y2) -> double {
        return std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };
    std::vector<double> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = getDist(x[i], y[i], 0.0, 0.0);
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!((mask >> i) & 1)) continue;
            for (int j = 0; j < n; ++j) {
                if ((mask >> j) & 1) continue;
                int nxMask = mask | (1 << j);
                double d = getDist(x[i], y[i], x[j], y[j]);
                dp[nxMask][j] = std::min(dp[nxMask][j], dp[mask][i] + d);
            }
        }
    }
    double ans = 1e9;
    for (int i = 0; i < n; ++i) {
        ans = std::min(ans, dp[(1 << n) - 1][i]);
    }
    std::cout << std::setprecision(2) << std::fixed << ans << nl;
}
