//Wed Jul 22 07:48:18 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n), b(m), s(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    m = b.size();
    i64 ans = s[n] - s[b[m - 1]];
    for (int i = m - 1; i >= 0; --i) {
        if (i == 0) ans += std::abs(s[b[i]]);
        else ans += std::abs(s[b[i]] - s[b[i - 1]]);
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
