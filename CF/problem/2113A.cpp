//Thu Jun 11 06:34:51 PM CST 2026
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
    int k, a, b, x, y;
    std::cin >> k >> a >> b >> x >> y;
    int c0 = 0, c1 = 0;
    if (y < x) {
        if (k >= b) {
            c1 = (k - b) / y;
        }
        k -= c1 * y;
        if (k >= b) {
            k -= y;
            c1++;
        }
        if (k >= a) {
            c0 = (k - a) / x;
        }
        if (k >= a) {
            k -= x;
            c0++;
        }
    }else {
        if (k >= a) {
            c0 = (k - a) / x;
        }
        k -= c0 * x;
        if (k >= a) {
            k -= x;
            c0++;
        } 
        if (k >= b) {
            c1 = (k - b) / y;
        }
        if (k >= b) {
            k -= y;
            c1++;
        }
    }
    std::cout << c0 + c1 << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
