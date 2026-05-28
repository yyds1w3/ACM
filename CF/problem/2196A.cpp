//Fri May  1 04:58:07 PM CST 2026
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
        i64 x, y;
        std::cin >> x >> y;
        i64 sx = std::min(x - x % 2, (y - y % 3) * 2 / 3);
        i64 sy = sx * 3 / 2;
        i64 len1 = x - sx;
        i64 len2 = y - sy;
        i64 len11 = x - 2;
        i64 len22 = y - 3;
        if (len1 >= len2 && len11 <= len22) {
            std::cout << "Bob" << nl;
        }else {
            std::cout << "Alice" << nl;
        }
    }
}
