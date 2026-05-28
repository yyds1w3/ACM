//Tue May 19 08:01:23 PM CST 2026
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
        i64 n, k;
        std::cin >> n >> k;
        // k k+1 ... k+n-1;
        i64 target = (k + k + n - 1) * n / 2;
        int l = 1, r = n;
        i64 ans = 2e18;
        while (l <= r) {
            i64 m = (l + r) / 2;
            // k+m ... k+n-1;
            i64 cur = (k + m + k + n - 1) * (n - m);
            ans = std::min(ans, std::abs(target - cur));
            if (cur < target) {
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        std::cout << ans << nl;
    }
}
