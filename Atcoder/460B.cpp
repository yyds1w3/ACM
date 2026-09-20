//Sat May 30 08:04:09 PM CST 2026
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
        i64 x1, y1, r1, x2, y2, r2;
        std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        i64 dd = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        i64 rr = (r1 + r2) * (r1 + r2);
        i64 rrr = (r1 - r2) * (r1 - r2);
        if (dd <= rr && dd >= rrr) {
            std::cout << "Yes" << nl;
        }else {
            std::cout << "No" << nl;
        }
    }
}
