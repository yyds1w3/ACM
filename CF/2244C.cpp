//Wed Jul 22 07:34:21 PM CST 2026
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
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int g = std::gcd(x, y);
    for (int i = 1; i <= n; ++i) {
        if (std::abs((i - a[i])) % g != 0) {
            std::cout << "NO" << nl;
            return;
        } 
    }
    std::cout << "YES" << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
