//Sat May 30 12:20:01 PM CST 2026
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
void solve() {
    int n;
    std::cin >> n;
    std::vector<int> g(n), s(n);
    std::vector<std::string> gg(n), ss(n);
    std::vector<std::string> a;
    for (int i = 0; i < n; ++i) {
        std::cin >> gg[i] >> ss[i];
        a.push_back(gg[i]);
        a.push_back(ss[i]);
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < n; ++i) {
        g[i] = std::lower_bound(a.begin(), a.end(), gg[i]) - a.begin();
        s[i] = std::lower_bound(a.begin(), a.end(), ss[i]) - a.begin();
    }
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n));
    // dp[mask][i];
    for (int i = 0; i < n; ++i) dp[1 << i][i] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!dp[mask][i]) continue;
            for (int j = 0; j < n; ++j) {
                if ((mask >> j) & 1) continue;
                if (g[j] == g[i] || s[j] == s[i]) {
                    dp[mask | (1 << j)][j] |= dp[mask][i];
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (dp[mask][i]) {
                ans = std::max(ans, __builtin_popcount(mask));
            }
        }
    }
    std::cout << n - ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
}
