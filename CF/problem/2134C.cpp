//Mon May 18 03:19:28 PM CST 2026
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
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                if (a[i] < a[i - 1]) {
                    int diff = a[i - 1] - a[i];
                    a[i - 1] -= diff;
                    ans += diff;
                }
                if ((i + 1 < n) && (a[i] < a[i + 1] + a[i - 1])) {
                    int diff = a[i + 1] + a[i - 1] - a[i];
                    a[i + 1] -= diff;
                    ans += diff;
                }
            }
        }
        std::cout << ans << nl;
    }
}
