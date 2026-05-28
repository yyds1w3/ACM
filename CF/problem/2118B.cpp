//Wed May 27 07:29:53 PM CST 2026
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
        std::cout << 2 * n - 3 << nl;
        for (int i = 0; i < n; ++i) {
            // [1, i];
            if (i > 1) std::cout << i + 1 << " " << 1 << " " << i << nl;
            // [i + 1, n];
            if (i + 1 < n) std::cout << i + 1 << " " << i + 1 << " " << n << nl;
        }
    }
}
