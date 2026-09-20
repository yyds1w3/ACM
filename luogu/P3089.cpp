//Tue Aug 11 07:51:20 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#define debug(x) std::cerr << #x << ": " << x << nl; 
using i64 = long long;
using i128 = __int128;
i64 dp[1000][1000];
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::pair<int, i64>> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i].first >> a[i].second;
    auto f = [&]() -> i64 {
        i64 res = 0;
        memset(dp, 0, sizeof(dp));
        for (int j = 0; j < n; ++j) {
            i64 mx = 0;
            int k = j;
            for (int i = j; i < n; ++i) {
                while (k >= 0 && a[i].first - a[j].first >= a[j].first - a[k].first) {
                    mx = std::max(mx, dp[j][k]);
                    k--;
                }
                dp[i][j] = mx + a[i].second;
                if (i == j) mx = dp[i][j];
                res = std::max(res, dp[i][j]);
            }
        }
        return res;
    };
    i64 ans = 0;
    std::sort(a.begin(), a.end());
    ans = f();
    int x = a.back().first;
    for (int i = 0; i < n; ++i) {
        a[i].first = x - a[i].first;
    }
    std::sort(a.begin(), a.end());
    ans = std::max(ans, f());
    std::cout << ans << nl;
}
