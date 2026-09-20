//Fri May 29 04:30:52 PM CST 2026
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
void solve () {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < m; ++i) std::cin >> b[i];
    std::vector<int> pref(n), suff(n);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (p < m && a[i] >= b[p]) {
            p++;
        }
        pref[i] = p;
    }
    if (p == m) {
        std::cout << 0 << nl;
        return;
    }
    int s = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s < m && a[i] >= b[m - 1 - s]) {
            s++;
        }
        suff[i] = s;
    }
    int ans = 2e9;
    if (suff[0] == m - 1) {
        ans = std::min(ans, b[0]);
    }
    for (int i = 0; i < n; ++i) {
        if (pref[i] + (i + 1 <= n - 1 ? suff[i + 1] : 0) == m - 1) {
            ans = std::min(ans, b[pref[i]]);
        }
    }
    if (ans == 2e9) std::cout << -1 << nl;
    else std::cout << ans << nl;
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
