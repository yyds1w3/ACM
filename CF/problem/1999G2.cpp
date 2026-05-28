//Fri May 22 08:13:13 PM CST 2026
#include <bits/stdc++.h>
#define nl std::endl
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
        int l = 2, r = 999;
        while (l < r) {
            int m1 = l + (r - l) / 3;
            int m2 = l + (r - l) / 3 * 2;
            std::cout << "? " << m1 << " " << m2 << nl;
            int val;
            std::cin >> val;
            if (val == (m1 + 1) * (m2 + 1)) { // m1 >= x, m2 >= x;
                r = m1;
            }else if (val == m1 * m2) { // m1 < x m2 < x;
                l = m2 + 1;
            }else { // m2 >= x m1 < x;
                l = m1 + 1;
                r = m2;
            }
        }
        std::cout << "! " << l << nl;
    }
}
