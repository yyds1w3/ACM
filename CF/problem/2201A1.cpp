//Thu Apr 30 08:17:43 PM CST 2026
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
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int ans = 0;
        for (int l = 0, r; l < n; l = r) {
            r = l + 1;
            while (r < n && a[r] >= a[l] + 1 && a[r] <= a[r - 1] + 1) {
                r++;
            }
            ans++;
        }
        std::cout << ans << nl;
    }
}
