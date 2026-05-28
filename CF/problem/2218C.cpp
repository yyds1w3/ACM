//Sun May 10 01:04:54 PM CST 2026
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
        int n;
        std::cin >> n;
        int r = 3 * n, l = 1;
        for (int i = 0; i < n; ++i) {
            std::cout << l << " " << r - 1 << " " << r << " ";
            l++;
            r-=2;
        }
        std::cout << nl;
    }
}
