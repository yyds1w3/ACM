//Wed Apr 15 04:44:38 PM CST 2026
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
        i64 a, b, c;
        std::cin >> a >> b >> c;
        i64 ans = 0;
        if (a >= c + 2 * b) {
            // ans = 3 * (a + b + c) - 2 * c - 2 * b - (a - 2 * b - c - 1);
            // ans = 2 * a + c + b + 2 * b + c + 1;
            ans = 2 * a + 3 * b + 2 * c + 1;
        }else {
            // ans = 3 * (a + b + c) - (2 * std::min(a, c)) - (a - std::min(a, c));
            ans = 2 * a + 3 * b  + 3 * c - std::min(a, c);
        }
        std::cout << ans << nl;
    }
}
