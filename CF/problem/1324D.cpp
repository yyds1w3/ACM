//Fri May 29 06:54:47 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        c[i] = a[i] - b[i];
    }
    std::sort(c.begin(), c.end());
    debug(c);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += n - (std::upper_bound(c.begin(), c.end(), -c[i]) - c.begin());
        if (c[i] > 0) {
            ans--;
        }
    }
    std::cout << ans / 2 << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    t = 1;
    while (t--) {
        solve();
    }
}
