//Mon Jun 15 02:06:16 PM CST 2026
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
    std::vector<i64> a(n), b(n), c(n);
    i64 totb = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        totb += b[i];
    }
    if (totb % (1LL * n * (n + 1) / 2) != 0) {
        std::cout << "NO" << nl;
        return;
    }
    i64 tot = totb / (1LL * n * (n + 1) / 2);
    for (int i = 0; i < n; ++i) {
        c[i] = b[i] - b[(i + n - 1) % n];
    }
    for (int i = 0; i < n; ++i) {
        i64 val = tot - c[i];
        if (val <= 0 || val % n != 0) {
            std::cout << "NO" << nl;
            return;
        }
        a[i] = val / n;
    }
    std::cout << "YES" << nl;
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
