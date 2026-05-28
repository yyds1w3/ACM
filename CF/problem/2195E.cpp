//Tue May  5 08:32:56 PM CST 2026
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
const int MOD = 1e9 + 7;

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
        int n;
        std::cin >> n;
        std::vector<int> L(n + 1), R(n + 1), fa(n + 1);
        std::vector<i64> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> L[i] >> R[i];
            if (L[i] != 0) {
                fa[L[i]] = i;
                fa[R[i]] = i;
            }
        }
        fa[1] = 0;
        auto dfs = [&](auto self, int u) -> void {
            if (L[u] != 0) {
                self(self, L[u]);
                self(self, R[u]);
                dp[u] = (dp[L[u]] + dp[R[u]] + 4) % MOD;
            }
        };
        dfs(dfs, 1);
        std::vector<i64> ans(n + 1);
        auto dfs2 = [&](auto self, int u) -> void {
            ans[u] = (ans[fa[u]] + dp[u] + 1) % MOD;
            if (L[u] != 0) {
                self(self, L[u]);
                self(self, R[u]);
            }
        };
        dfs2(dfs2, 1);
        for (int i = 1; i <= n; ++i) {
            std::cout << ans[i] << " ";
        }
        std::cout << nl;
    }
}
