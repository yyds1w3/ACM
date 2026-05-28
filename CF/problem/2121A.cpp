//Tue May 26 07:17:59 PM CST 2026
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
        int n, s;
        std::cin >> n >> s;
        int mn = 1e9;
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            mx = std::max(mx, x);
            mn = std::min(mn, x);
        }
        std::cout << std::min(std::abs(s-mn), std::abs(s-mx)) + mx - mn << nl;
    }
}
