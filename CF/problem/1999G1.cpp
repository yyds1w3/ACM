//Fri May 22 08:07:42 PM CST 2026
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
            int mid = (l + r) / 2;
            std::cout << "? " << mid << " " << mid << nl;
            int val;
            std::cin >> val;
            if (val > mid * mid) {
                r = mid;
            }else {
                l = mid + 1;
            }
        }
        std::cout << "! " << l << nl;
    }
}
