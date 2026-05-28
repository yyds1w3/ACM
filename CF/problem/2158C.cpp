//Wed May  6 10:12:46 PM CST 2026
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
        int n, k;
        std::cin >> n >> k;
        std::vector<i64> a(n), b(n);
        std::vector<i64> L(n), R(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) L[i] = a[i];
            else L[i] = std::max(L[i - 1], 0LL) + a[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) R[i] = a[i];
            else R[i] = std::max(R[i + 1], 0LL) + a[i];
        }
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];
        }
        i64 ans = -2e18;
        if (k & 1) {
            for (int i = 0; i < n; ++i) {
                ans = std::max(ans, L[i] + R[i] - a[i] + b[i]);
            }
        }else {
            for (int i = 0; i < n; ++i) {
                ans = std::max(ans, L[i]);
            }
        }
        std::cout << ans << nl;
    }
}
