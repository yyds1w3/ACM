//Sun May 24 03:10:18 PM CST 2026
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
const int P = 998244353;

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
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        i64 dp1 = 0, dp2 = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                dp1 = (dp1 + 1) % P;
            }else if (a[i] == 2) {
                dp2 = (dp2 + dp1 + dp2) % P;
            }else {
                ans = (ans + dp2) % P;
            }
        }
        std::cout << ans << nl;
    }
}
