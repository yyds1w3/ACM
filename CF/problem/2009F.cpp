//Tue May 19 08:26:50 PM CST 2026
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
        int n, q;
        std::cin >> n >> q;
        std::vector<i64> a(2 * n);
        i64 tot = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            tot += a[i];
        }
        std::vector<i64> pi(2 * n + 1);
        for (int i = 0; i < 2 * n; ++i) {
            pi[i + 1] = pi[i] + a[i % n];
        }
        // [0, x)
        auto f = [&](i64 x) -> i64 {
            // x --> len;
            // pi[4] = a[0, 4)
            // pi[s + len] - pi[s] = a[s, s + len)
            int s = x / n;
            int len = x % n;
            i64 res = s * tot + pi[s + len ] - pi[s];
            return res;
        };
        while (q--) {
            i64 l, r;
            std::cin >> l >> r;
            std::cout << f(r) - f(l - 1) << nl;
        }
    }
}
