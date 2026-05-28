//Sun May 17 07:44:19 PM CST 2026
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
        int l, r;
        std::cin >> l >> r;
        int n = r - l + 1;
        std::vector<int> a(n);
        while (r >= 0) {
            int k = 0;
            while ((1 << k) <= r) {
                k++;
            }
            for (int i = r; i >= (1 << k) - 1 - r; --i) {
                a[i] = (1 << k) - 1 - i;
            }
            r = (1 << k) - 1 - r - 1;
        }
        std::cout << 1LL * n * (n - 1) << nl;
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << nl;
    }
}
