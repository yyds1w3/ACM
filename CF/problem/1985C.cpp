//Fri May 22 08:35:30 PM CST 2026
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
        int n;
        std::cin >> n;
        std::vector<i64> a(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        i64 mx = 0;
        i64 sum = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            mx = std::max(mx, a[i]);
            if (i == 0) {
                if (a[i] == 0) ans++;
            }else {
                if (mx * 2 == sum) ans++;
            }
        }
        std::cout << ans << nl;
    }
}
