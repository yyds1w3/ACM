//Wed May 27 05:14:12 PM CST 2026
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
    int t;
    std::cin >> t;
    while (t--) {
        std::string l, r;
        std::cin >> l >> r;
        int n = l.size();
        std::vector dp(n, std::vector<std::vector<int>>(2, std::vector<int>(2, -1)));
        auto dfs = [&](auto self, int i, int f1, int f2) -> int {
            if (i == n) return 0;
            if (dp[i][f1][f2] != -1) return dp[i][f1][f2];
            int ans = 1e9;
            char mn = f1 ? l[i] : '0';
            char mx = f2 ? r[i] : '9';
            for (char d = mn; d <= mx; ++d) {
                int cost = (d == l[i]) + (d == r[i]);
                int nxtf1 = f1 && (d == mn);
                int nxtf2 = f2 && (d == mx);
                ans = std::min(ans, cost + self(self, i + 1, nxtf1, nxtf2));
            }
            return dp[i][f1][f2] = ans;
        };
        std::cout << dfs(dfs, 0, 1, 1) + r.size() - l.size() << nl;

    }
}
