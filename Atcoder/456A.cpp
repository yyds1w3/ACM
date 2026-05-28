//Sat May  2 07:56:18 PM CST 2026
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
    int x;
    std::cin >> x;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            for (int k = 1; k <= 6; ++k) {
                if (i + j + k == x) {
                    std::cout << "Yes" << nl;
                    return 0;
                }
            }
        }
    }
    std::cout << "No" << nl;
}
