//Thu Apr 23 06:35:32 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> p(n), a(n), b(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i] >> a[i] >> b[i];
        m = std::max(m, p[i] + a[i]);
    }
    std::vector<i64> pi(n + 1);
    for (int i = 0; i < n; ++i) {
        pi[i + 1] = pi[i] + b[i];
    }
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= m; ++i) {
        dp[n][i] = i;
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= m; ++j) {
            if (j <= p[i]) {
                dp[i][j] = dp[i + 1][j + a[i]];
            }else {
                dp[i][j] = dp[i + 1][std::max(0, j - b[i])];
            }
        }
    }
    int q;
    std::cin >> q;
    while (q--) {
        i64 x;
        std::cin >> x;
        if (x <= m) {
            std::cout << dp[0][x] << nl;
        }else {
            auto it = std::lower_bound(pi.begin(), pi.end(), x - m);
            if (it == pi.end()) {
                std::cout << x - pi.back() << nl;
            }else {
                int k = it - pi.begin();
                std::cout << dp[k][x - pi[k]] << nl;
            }
        }
    }

}
