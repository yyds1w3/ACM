//Thu Apr 30 11:17:15 PM CST 2026
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
        std::vector<int> a(n), suff(n + 1);
        suff[n] = 1e9;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        for (int i = n - 1; i >= 0; --i) {
            suff[i] = std::min(suff[i + 1], a[i]);
        }

        i64 ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            ans += a[i] - suff[i];
        }
        int mx = 1;
        int cur = 1;
        for (int i = n - 1; i > 0; --i) {
            if (suff[i] == suff[i-1]) {
                cur++;
                mx = std::max(mx, cur);
            }else {
                cur = 1;
            }
        }
        std::cout << ans + mx - 1 << nl;
    }
}
