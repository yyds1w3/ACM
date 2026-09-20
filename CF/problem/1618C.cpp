//Mon Jun 15 01:03:02 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    bool f = true;
    i64 g = 0;
    for (int i = 0; i < n; i += 2) {
        g = std::gcd(g, a[i]);
    }
    for (int i = 1; i < n; i += 2) {
        if (a[i] % g == 0) {
            f = false;
        }
    }
    if (f) {
        std::cout << g << nl;
        return;
    }
    f = true;
    g = 0;
    for (int i = 1; i < n; i += 2) {
        g = std::gcd(g, a[i]);
    }
    for (int i = 0; i < n; i += 2) {
        if (a[i] % g == 0) {
            f = false;
        }
    }
    if (f) {
        std::cout << g << nl;
    }else {
        std::cout << 0 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
