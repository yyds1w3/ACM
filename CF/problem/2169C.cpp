//Sat May  2 07:03:24 PM CST 2026
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
        // (r - l + 1) * (r + l)
        // r^2 + r - (l^2 - l);
        // r^2 + r - pi[r] - (l^2 - l - pi[l-1]);
        std::vector<i64> a(n + 1), pi(n + 1);
        std::vector<i64> L(n + 1);
        L[0] = 1e18;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        i64 ans = 0;
        for (int i = 1; i <= n; ++i) {
            pi[i] = pi[i - 1] + a[i];
            L[i] = std::min(L[i - 1], 1LL * i * i - i - pi[i - 1]);
            i64 R = 1LL * i * i + i - pi[i];
            ans = std::max(ans, R - L[i]);
        }
        std::cout << ans + pi[n] << nl;


    }
}
