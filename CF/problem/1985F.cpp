//Fri May 22 09:07:46 PM CST 2026
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
        i64 h, n;
        std::cin >> h >> n;
        std::vector<i64> a(n), c(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> c[i];
        auto check = [&](i64 x) -> bool {
            i64 res = 0;
            for (int i = 0; i < n; ++i) {
                res += a[i] + (x - 1) / c[i] * a[i];
                if (res >= h) return true;
            }
            return false;
        };
        i64 l = 1, r = 4e10;
        while (l < r) {
            i64 mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        std::cout << l << nl;
    }
}
