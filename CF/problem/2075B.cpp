//Thu May 28 03:04:47 PM CST 2026
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
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        if (k == 1) {
            int mx = 0;
            for (int i = 1; i < n; ++i) {
                mx = std::max(mx, a[i] + a[0]);
            }
            for (int i = 0; i < n - 1; ++i) {
                mx = std::max(mx, a[i] + a[n - 1]);
            }
            std::cout << mx << nl;
        }else {
            std::sort(a.begin(), a.end());
            std::cout << std::accumulate(a.begin() + n - k - 1, a.end(), 0LL) << nl;
        }
    }
}
