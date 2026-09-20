//Fri Aug  7 10:14:20 AM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
using i64 = long long;
using i128 = __int128;
#define debug(x) std::cerr << #x << ": " << x << nl; 
struct egg {
    int x, y, v;
    bool operator<(const egg& other) const {
        return x < other.x;
    }
};
const i64 INF = 2e18;
i64 dp[1002][1002][2];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n, x0;
    std::cin >> n >> x0;
    std::vector<egg> a(n+1);
    a[0] = {x0, 0, 0};
    for (int i = 1; i <= n; ++i) std::cin >> a[i].x;
    for (int i = 1; i <= n; ++i) std::cin >> a[i].y;
    for (int i = 1; i <= n; ++i) std::cin >> a[i].v;
    std::sort(a.begin(), a.end());
    std::vector<i64> pref(n+1);
    i64 totY = 0;
    for (int i = 0; i <= n; ++i) {
        pref[i] = (i > 0 ? pref[i-1] : 0) + a[i].v;
        totY += a[i].y;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (a[i].x == x0 && !a[i].y && !a[i].v) dp[i][i][0] = dp[i][i][1] = 0;
    }

    auto costV = [&](int l, int r) -> i64 {
        return pref[n] - pref[r] + (l > 0 ? pref[l-1] : 0);
    };
    for (int len = 2; len <= n + 1; ++len) {
        for (int i = 0; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            dp[i][j][0] = std::min({dp[i][j][0],
                                    dp[i+1][j][0] + costV(i+1, j) * (a[i+1].x-a[i].x),
                                    dp[i+1][j][1] + costV(i+1, j) * (a[j].x - a[i].x)});
            dp[i][j][1] = std::min({dp[i][j][1],
                                    dp[i][j-1][0] + costV(i, j-1) * (a[j].x-a[i].x),
                                    dp[i][j-1][1] + costV(i, j-1) * (a[j].x-a[j-1].x)});
        }
    }
    totY -= std::min(dp[0][n][0], dp[0][n][1]);
    std::cout << std::setprecision(3) << std::fixed << totY / 1000.0 << nl;
}
