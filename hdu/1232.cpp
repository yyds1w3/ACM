//Thu Jul 30 12:10:14 PM CST 2026
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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int tot = std::accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
    }
    debug(a);
    while (q--) {
        int r;
        std::cin >> r;
        r--;
        if (a[r] == 0) std::cout << tot + 1 << nl;
        else std::cout << 0 << nl;
    }
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
}
