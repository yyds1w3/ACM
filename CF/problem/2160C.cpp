//Mon May  4 08:08:33 PM CST 2026
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

void solve() {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << "YES" << nl;
        return;
    }
    int x = 31 - __builtin_clz(n);
    int y = __builtin_ctz(n);
    x -= y;
    n >>= y;
    for (int i = 0; i <= x / 2; ++i) {
        if (((n >> i) & 1) != ((n >> (x - i)) & 1)) {
            std::cout << "NO" << nl;
            return;
        }
    }
    if (x % 2 == 0) {
        if ((n >> (x / 2)) & 1) {
            std::cout << "NO" << nl;
            return;
        } 
    }
    std::cout << "YES" << nl;
}

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
        solve();
    }
}
