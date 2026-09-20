//Wed Jun 10 10:06:48 PM CST 2026
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    std::vector<int> c(2 * n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
        c[i + n] = b[i];
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    i64 ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        int p = c[i];
        int c0 = a.end() - std::lower_bound(a.begin(), a.end(), p);
        int c1 = b.end() - std::lower_bound(b.begin(), b.end(), p);
        if (c1 - c0 <= k) {
            ans = std::max(ans, 1LL * c1 * p);
        }
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
