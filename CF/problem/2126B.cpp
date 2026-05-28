//Tue May 19 04:07:10 PM CST 2026
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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n);
        std::vector<int> dp(n + 1);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == 0) {
                dp[i] = dp[i + 1] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] >= k) {
                ans++;
                i += k;
            }
        }
        std::cout << ans << nl;
    }
}

