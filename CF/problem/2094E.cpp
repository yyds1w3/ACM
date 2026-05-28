//Thu May 14 12:36:47 PM CST 2026
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
        std::vector<int> a(n);
        std::vector<int> w(30);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            for (int j = 0; j < 30; ++j) {
                w[j] += (a[i] >> j) & 1;
            }
        }
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            i64 cur = 0;
            for (int j = 0; j < 30 ;++j) {
                if ((a[i] >> j) & 1) {
                    cur += 1LL * (n - w[j]) * (1 << j);
                }else {
                    cur += 1LL * w[j] * (1 << j);
                }
            }
            ans = std::max(ans, cur);
        }
        std::cout << ans << nl;
    }
}
