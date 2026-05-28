//Sat Apr 25 10:44:07 PM CST 2026
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
        bool f = false;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            if (x == 100) {
                f = true;
            }
        }
        if (f) std::cout << "Yes" << nl;
        else std::cout << "No" << nl;
    }
}
