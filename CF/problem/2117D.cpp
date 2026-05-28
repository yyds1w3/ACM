//Wed May 27 08:29:15 PM CST 2026
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
    i64 n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 tot = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        tot += a[i];
    }
    if (tot % (n * (n + 1) / 2) == 0) {
        tot /= n * (n + 1) / 2;
    }else {
        std::cout << "NO" << nl;
        return;
    }
    i64 x = 0, y = tot;
    i64 mx = tot * n;
    i64 mn = tot;
    if (a[0] >= mn && a[0] <= mx) {
        i64 diff = mx - a[0];
        if (diff % (n - 1) != 0) {
            std::cout << "NO" << nl;
            return;
        }else {
            x += diff / (n - 1);
            y -= diff / (n - 1);
        }
    }else {
        std::cout << "NO" << nl;
        return;
    }
    for (i64 i = 1; i < n; ++i) {
        if (x * (i + 1) + y * (n - i) != a[i]) {
            std::cout << "NO" << nl;
            return;
        }
    }
    std::cout << "YES" << nl;
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
