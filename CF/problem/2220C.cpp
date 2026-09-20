//Sat May 30 04:09:59 PM CST 2026
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
void solve() {
    int p, q;
    std::cin >> p >> q;
    i64 S = p + 2 * q;
    i64 target = 2 * S + 1;
    for (int A = 3; A * A <= target; A += 2) {
        if (target % A == 0) {
            i64 B = target / A;
            i64 n = (A - 1) / 2;
            i64 m = (B - 1) / 2;
            if (q <= std::min(n * (m + 1), m * (n + 1))) {
                std::cout << n << " " << m << nl;
                return;
            }
        }
    }
    std::cout << -1 << nl;
}
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
        solve();
    }
}
