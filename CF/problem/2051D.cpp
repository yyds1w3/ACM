//Wed Jun 10 09:48:13 PM CST 2026
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
    i64 n, x, y;
    std::cin >> n >> x >> y;
    std::vector<i64> a(n);
    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    i64 ll = sum - y;
    i64 rr = sum - x;
    std::sort(a.begin(), a.end());
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        int i1 = std::lower_bound(a.begin() + i + 1, a.end(), ll - a[i]) - a.begin();
        int i2 = std::upper_bound(a.begin() + i + 1, a.end(), rr - a[i]) - a.begin();
        ans += i2 - i1;
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
