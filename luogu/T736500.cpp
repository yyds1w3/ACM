//Sat May 30 02:14:53 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    i64 tot = std::accumulate(a.begin(), a.end(), 0LL);
    while (m--) {
        int k;
        std::cin >> k;
        i64 mn = 0, mx = 0;
        i64 dp0 = 0, dp1 = 0;
        for (int i = 0; i < n; ++i) {
            i64 d = (a[i] ^ k) - a[i];
            dp0 = std::min(d, dp0 + d);
            dp1 = std::max(d, dp1 + d);
            mn = std::min(mn, dp0);
            mx = std::max(mx, dp1);
        }
        std::cout << tot + mn << " " << tot + mx << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    solve();
}
