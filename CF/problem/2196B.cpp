//Thu May 21 07:46:12 PM CST 2026
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
        std::vector<i64> a(n + 1);
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        int B = 500;
        i64 ans = 0;
        // a[i] * a[j] == j - i  j = i + a[i] * x <= n
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= B) {
                for (int x = 1; a[i] * x + i <= n; ++x) {
                    if (a[a[i] * x + i] == x) ans++;
                }
                for (int x = 1; -a[i] * x + i >= 1; ++x) {
                    if (a[-a[i] * x + i] == x) ans++;
                }
            }else {
                for (int x = 1; a[i] * x + i <= n && x < B; ++x) {
                    if (a[i + a[i] * x] == x) ans++;
                }
            }
        }
        std::cout << ans << nl;
    }
}
