//Sat May  2 05:49:40 PM CST 2026
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
        i64 n;
        std::cin >> n;
        std::vector<int> a(n);
        i64 tot = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            tot += a[i];
        }
        tot -= n;
        std::sort(a.begin(), a.end());
        i64 l = std::lower_bound(a.begin(), a.end(), 1) - a.begin();
        i64 ans = std::min(tot + 1, n - l);
        std::cout << ans << nl;
    }
}
