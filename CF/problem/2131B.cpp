//Fri May 15 08:20:35 PM CST 2026
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
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                if (i != n - 1) std::cout << 3 << " ";
                else std::cout << 2 << " ";
            }else {
                std::cout << -1 << " ";
            }
        }
        std::cout << nl;
    }
}
