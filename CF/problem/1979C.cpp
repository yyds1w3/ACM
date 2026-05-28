//Sat May 23 06:52:44 PM CST 2026
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
        std::vector<i64> k(n);
        for (int i = 0; i < n; ++i) std::cin >> k[i];
        i64 M = 1;
        for (int i = 0; i < n; ++i) {
            M = std::lcm(M, k[i]);
        }
        i64 S = 0;
        for (int i = 0; i < n; ++i) {
            S += M / k[i];
        }
        if (S < M) {
            for (int i = 0; i < n; ++i) {
                std::cout << M / k[i] << " ";
            }
            std::cout << nl;
        }else {
            std::cout << -1 << nl;
        }
    }
}
