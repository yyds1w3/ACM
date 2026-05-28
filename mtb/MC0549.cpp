//Sun Apr 26 10:57:08 AM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    int mn = 1e9, mx = 0;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        mn = std::min(x, mn);
        mx = std::max(x, mx);
    }
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        if (l > mn) {
            ans = (ans + std::min(l - 1, mx) - mn + 1) % 10007;
        }
        if (r < mx) {
            ans = (ans + mx - std::max(r + 1, mn) + 1) % 10007;
        }
    }
    std::cout << ans << nl;
}
