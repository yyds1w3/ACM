//Tue May 19 12:12:47 PM CST 2026
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
        i64 ans = 0;
        int dan = 0, tuan = 0, cha = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if (x == 1) dan++;
            else {
                tuan++;
                ans += x;
                cha += x / 2 - 1;
            }
        }
        if (tuan == 1) {
            ans += std::min(cha + 1, dan);
        }else {
            ans += std::min(cha, dan);
        }
        if (ans < 3) {
            std::cout << 0 << nl;
        }else {
            std::cout << ans << nl;
        }
    }
}
