//Fri May  8 05:33:35 PM CST 2026
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
        std::vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) std::cin >> a[i];
        std::vector<i64> ans(n);
        for (int i = 0; i < 2 * n; ++i) {
            ans[0] += (i & 1) ? a[i] : -a[i];
        }
        if (n > 1) {
            ans[1] = a[2 * n - 1] - a[0];
            for (int i = 1; i < 2 * n - 1; ++i) {
                ans[1] += (i & 1) ? -a[i] : a[i];
            }
        }
        for (int k = 2; k < n; ++k) {
            ans[k] = ans[k - 2] + 2 * (a[2 * n - k] - a[k - 1]);
        }
        for (int k = 0; k < n; ++k) {
            std::cout << ans[k] << " ";
        }
        std::cout << nl;
    }
}
