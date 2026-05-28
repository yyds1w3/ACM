//Sun Apr 26 10:29:30 AM CST 2026
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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    while (q--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--;
            for (int i = l; i < r; ++i) {
                a[i] += x;
            } 
        }else if (op == 2) {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--;
            for (int i = l; i < r; ++i) {
                a[i] = std::min(a[i], x);
            }
        }else {
            int l, r;
            std::cin >> l >> r;
            l--;
            int ans = 0;
            for (int i = l; i < r; ++i) {
                ans += a[i];
            }
            std::cout << ans << nl;
        }
    }
}
