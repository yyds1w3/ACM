//Tue Jul 28 04:33:45 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
i64 dp[2][3];
const int INF = 1e9;
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < 3; ++i) dp[0][i] = INF;
    dp[0][a[0] + 1] = 0;
    int val = 1;
    for (int i = 1; i < n; ++i, val ^= 1) {
        for (int j = 0; j < 3; ++j) {
            if (a[i] == -1) {
                dp[val][0] = dp[val ^ 1][0];
                dp[val][1] = INF;
                dp[val][2] = dp[val ^ 1][2] + 2;
            }else if (a[i] == 0) {
                dp[val][0] = dp[val ^ 1][0] + 1;
                dp[val][1] = std::min(dp[val ^ 1][0], dp[val ^ 1][1]);
                dp[val][2] = dp[val ^ 1][2] + 1;
            }else {
                dp[val][0] = dp[val ^ 1][0] + 2;
                dp[val][1] = dp[val ^ 1][0] + 1;
                dp[val][2] = std::min({dp[val ^ 1][0], dp[val ^ 1][1], dp[val ^ 1][2]});
            }
        }
    }
    i64 ans = std::min({dp[(n - 1) & 1][0], dp[(n - 1) & 1][1], dp[(n - 1) & 1][2]});
    if (ans >= INF) {
        std::cout << "BRAK" << nl;
    }else {
        std::cout << ans << nl;
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
