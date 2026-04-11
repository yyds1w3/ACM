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
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int m;
    std::cin >> m;
    std::vector<i64> fib(61);
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= 60; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i < m; ++i) {
        i64 u, v;
        std::cin >> u >> v;
        while (u != v) {
            if (u > v) {
                u -= *std::prev(std::lower_bound(fib.begin(), fib.end(), u));
            }else {
                v -= *std::prev(std::lower_bound(fib.begin(), fib.end(), v));
            }
        }
        std::cout << u << nl;
    }
}
