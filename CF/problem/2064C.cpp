//Sun May 31 04:07:10 PM CST 2026
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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<i64> pref(n + 1), suff(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + (a[i] > 0 ? a[i] : 0); 
    }
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + (a[i] < 0 ? -a[i] : 0);
    }
    i64 mx = 0;
    for (int k = 0; k <= n; ++k) {
        mx = std::max(mx, pref[k] + suff[k]);
    }
    std::cout << mx << nl;
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
