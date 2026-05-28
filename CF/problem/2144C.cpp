//Sat May  9 03:24:50 PM CST 2026
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
const int MOD = 998244353;


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
        std::vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        for (int i = 1; i <= n; ++i) std::cin >> b[i];
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
                cnt++;
            }
            if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
                cnt++;
            }
            dp[i] = (dp[i - 1] * cnt) % MOD;
        }
        std::cout << dp[n] << nl;
    }
}
