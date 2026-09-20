//Sun May 31 08:38:46 PM CST 2026
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
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n, q;
    std::cin >> n >> q;
    while (q--) {
        std::string s;
        std::cin >> s;
        if (s == "->") {
            i64 nn = n;
            i64 x, y;
            std::cin >> x >> y;
            i64 val = 0;
            while (nn) {
                i64 mid = 1LL << (nn - 1);
                i64 unit = qpow(4, nn - 1);
                if (x <= mid && y <= mid) {
                }else if (x > mid && y > mid) {
                    val += unit;
                    x -= mid;
                    y -= mid;
                }else if (x > mid && y <= mid) {
                    val += 2 * unit;
                    x -= mid;
                }else if (x <= mid && y > mid) {
                    val += 3 * unit;
                    y -= mid;
                }
                nn--;
            }
            val++;
            std::cout << val << nl;
        }else {
            i64 nn = n;
            i64 d;
            std::cin >> d;
            d--;
            i64 x = 1;
            i64 y = 1;
            while (nn) {
                i64 unit = qpow(4, nn - 1);
                i64 mid = 1LL << (nn - 1);
                if (d >= 3 * unit) {
                    y += mid;
                    d -= 3 * unit;
                }else if (d >= 2 * unit) {
                    x += mid;
                    d -= 2 * unit;
                }else if (d >= unit) {
                    x += mid;
                    y += mid;
                    d -= unit;
                }else {
                    ;
                }
                nn--;
            }
            std::cout << x << " " << y << nl;
        }
    }
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
    while (t--) solve();
}
