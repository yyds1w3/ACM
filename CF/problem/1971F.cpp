//Mon May 25 02:55:19 PM CST 2026
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
        int r;
        std::cin >> r;
        i64 ans = 0;
        for (int i = 0; i <= r; ++i) {
            int y1 = sqrtl(1LL * (r + 1) * (r + 1) - 1LL * i * i);
            int y2 = sqrtl(1LL * r * r - 1LL * i * i);
            if (y1 > 0 && 1LL * y1 * y1 + 1LL * i * i == 1LL * (r + 1) * (r + 1)) {
                y1--;
            }
            if (y2 > 0 && 1LL * y2 * y2 + 1LL * i * i == 1LL * r * r) {
                y2--;
            }
            ans += 4 * (y1 - y2);
        }
        if (r == 0) ans += 1;
        std::cout << ans << nl;
    }
}
