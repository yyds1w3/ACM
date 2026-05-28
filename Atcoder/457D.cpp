//Sat May  9 08:24:03 PM CST 2026
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
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    auto check = [&](i64 x) -> bool {
        i64 need = 0;
        for (int i = 0; i < n; ++i) {
            i64 diff = x - a[i];
            if (diff > 0) {
                need += (diff - 1) / (i + 1) + 1;
            } 
            if (need > k) return false;
        }
        return true;
    };
    i64 l = 0, r = 2e18;
    while (l < r) {
        i64 mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        }else {
            r = mid - 1;
        }
    }
    std::cout << l << nl;
}
