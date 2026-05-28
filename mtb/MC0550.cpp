//Sun Apr 26 11:33:05 AM CST 2026
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
    int n, q;
    std::cin >> n >> q;
    int ans = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ans += a[i];
    }
    std::sort(a.begin(), a.end());
    int idx = 0;
    while (q--) {
        int x;
        std::cin >> x;
        if (x == 1) {
            std::cout << ans << nl;
            continue;
        }
        for (int i = idx; i < n; ++i) {
            ans -= a[i] - a[i] / x;
            a[i] /= x;
            if (a[i] == 0) {
                idx++;
            }
        }
        std::cout << ans << nl;
    }
}
