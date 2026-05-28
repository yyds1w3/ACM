//Sat May 16 12:06:04 PM CST 2026
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
        int mx = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if (x > mx) {
                mx = x;
                cnt = 1;
            }else if (x == mx) {
                cnt++;
            }
        }
        std::cout << cnt << nl;
    }
}
