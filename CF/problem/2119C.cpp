//Tue May 26 08:56:49 PM CST 2026
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
    i64 n, l, r, k;
    std::cin >> n >> l >> r >> k;
    if (n & 1LL) {
        std::cout << l << nl;
        return;
    }
    if (n < 4) {
        std::cout << -1 << nl;
        return;
    }
    int w = 63 - __builtin_clzll(l);
    i64 aim = 1LL << (w + 1);
    if (aim > r) {
        std::cout << -1 << nl;
    }else {
        if (k <= n - 2) {
            std::cout << l << nl;
        }else {
            std::cout << aim << nl;
        }
    }
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
