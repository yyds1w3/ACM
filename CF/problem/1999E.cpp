//Fri May 22 07:42:08 PM CST 2026
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
    std::vector<int> dp(2e5 + 1);
    for (int i = 1; i <= 2e5; ++i) {
        int temp = i;
        int ans = 0;
        while (temp) {
            temp /= 3;
            ans++;
        }
        dp[i] = ans;
    }
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        int ans = 2 * dp[l];
        for (int i = l + 1; i <= r; ++i) {
            ans += dp[i];
        }
        std::cout << ans << nl;
    }
}
