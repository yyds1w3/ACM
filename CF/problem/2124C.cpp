//Thu May 21 02:45:48 PM CST 2026
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
        std::vector<i64> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        i64 x = 1;
        auto lcm = [](i64 x, i64 y) -> i64 {
            return 1LL * x * y / std::gcd(x, y);
        };
        for (int i = 0; i < n - 1; ++i) {
            i64 g = std::gcd(a[i], a[i + 1]);
            x = std::lcm(x, a[i] / g);
        }
        std::cout << x << nl;
    }
}
