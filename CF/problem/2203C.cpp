//Tue May  5 01:34:51 PM CST 2026
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
    i64 s, m;
    std::cin >> s >> m;
    i64 ans = 0;
    for (int i = 0; i < 61; ++i) {
        i64 mask = (1LL << (i + 1)) - 1;
        i64 si = s & mask;
        i64 mi = m & mask;
        if (si > 0 && mi == 0) {
            std::cout << -1 << nl;
            return;
        }
        if (si > 0) {
            ans = std::max(ans, (si - 1) / mi + 1);
        }
    }
    std::cout << ans << nl;
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
