//Fri May 22 08:44:07 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#define dl "-------------\n";
#else
#define debug(...) 43
#define debug_range(...) 43
#define dl 43
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
        i64 x, y, z;
        i64 k;
        std::cin >> x >> y >> z >> k;
        i64 ans = 0;
        for (i64 i = 1; i <= x; ++i) {
            if (k % i != 0) continue;
            for (i64 j = 1; j <= y; ++j) {
                if (k % (i * j) != 0) continue;
                i64 u = k / i / j;
                if (u > z) continue;
                ans = std::max((x - i + 1) * (y - j + 1) * (z - u + 1), ans);
            }
        }
        std::cout << ans << nl;
    }
}
