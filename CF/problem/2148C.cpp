//Wed May 13 06:11:11 PM CST 2026
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
    // 0 1 2 3 4; 
    // 0 1 0 1 0;
    // == des - start 1 -> 0 2 -> 2 3 -> 2 4 -> 4 /2 * 2;
    // != des - start 1 -> 1 2 -> 1 3 -> 3 -1 /2 * 2 + 1;
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        int lst = 0, lstd = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int b, c;
            std::cin >> b >> c;
            if (c != lstd) {
                ans += (b - lst - 1) / 2 * 2 + 1;
            }else {
                ans += (b - lst) / 2 * 2;
            }
            lst = b;
            lstd = c;
        }
        if (lst < m) ans += m - lst;
        std::cout << ans << nl;
    }
}
