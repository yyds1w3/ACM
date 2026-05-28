//Tue May 19 07:12:12 PM CST 2026
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
        int x, y, k;
        std::cin >> x >> y >> k;
        int tx, ty;
        if (x > 0) {
            tx = (x - 1) / k + 1;
        }else {
            tx = 0;
        }
        if (y > 0) {
            ty = (y - 1) / k + 1;
        }else {
            ty = 0;
        }
        if (tx <= ty) {
            std::cout << 2 * ty << nl;
        }else {
            std::cout << 2 * tx - 1 << nl;
        }
    }
}
