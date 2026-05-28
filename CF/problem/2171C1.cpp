//Sat May  2 03:45:34 PM CST 2026
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
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        int ans = 0;
        int lst = 0;
        for (int i = 0; i < n; ++i) {
            ans ^= a[i] ^ b[i];
            if (a[i] != b[i]) {
                lst = i;
            }
        }
        if (ans == 0) {
            std::cout << "Tie" << nl; 
        }else {
            if (lst & 1) {
                std::cout << "Mai" << nl;
            }else {
                std::cout << "Ajisai" << nl;
            }
        }
    }
}
