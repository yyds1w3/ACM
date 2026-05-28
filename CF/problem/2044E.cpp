//Thu May 14 07:13:54 PM CST 2026
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
        i64 k, l1, r1, l2, r2;
        std::cin >> k >> l1 >> r1 >> l2 >> r2;
        if (k == 1) {
            i64 L = std::max(l1, l2);
            i64 R = std::min(r1, r2);
            std::cout << R - L + 1 << nl;
        }else {
            i64 M = 1;
            i64 ans = 0;
            while (M <= r2) {
                i64 L = (l2 - 1) / M + 1;
                i64 R = r2 / M;
                L = std::max(L, l1);
                R = std::min(R, r1);
                if (L <= R) {
                    ans += R - L + 1;
                }
                M *= k;
            }
            std::cout << ans << nl;
        }
    }
}
