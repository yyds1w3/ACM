//Sat May 23 07:25:21 PM CST 2026
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
        int n, x, y;
        std::cin >> n >> x >> y;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        std::map<std::pair<int, int>, int> m;
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += m[{(x - a[i] % x) % x, a[i] % y}];
            m[{a[i] % x, a[i] % y}]++;
        }
        std::cout << ans << nl;
    }
}
