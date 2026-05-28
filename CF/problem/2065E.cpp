//Thu May 14 03:54:42 PM CST 2026
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
    int n, m, k;
    std::cin >> n >> m >> k;
    if (std::abs(n - m) > k || k > std::max(n, m)) {
        std::cout << -1 << nl;
        return;
    }
    if (n >= m) {
        n -= k;
        for (int i = 0; i < k; ++i) {
            std::cout << 0;
        }
        while (n > 0) {
            std::cout << 1 << 0;
            n--;
            m--;
        }
        while (m > 0) {
            std::cout << 1;
            m--;
        }
        std::cout << nl;
    }else {
        m -= k;
        for (int i = 0; i < k; ++i) {
            std::cout << 1;
        }
        while (m > 0) {
            std::cout << 0 << 1;
            m--;
            n--;
        }
        while (n > 0) {
            std::cout << 0;
            n--;
        }
        std::cout << nl;
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
