//Fri May 29 08:46:01 AM CST 2026
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
    // 0-31 c0
    // c0 > n ==> ans;
    // c0 = n ==> ans;
    // c0 < n ==> n - c0 && n >= 2 奇数 +2 * lowbit / 偶数 lowbit * n - c0;
    int t;
    std::cin >> t;
    while (t--) {
        int n, x;
        std::cin >> n >> x;
        int c0 = 0;
        i64 ans = 0;
        for (int i = 0; i < 31; ++i) {
            if ((x >> i & 1)) {
                ans += (1 << i);
                c0++;
            }
        }
        if (c0 >= n) {
            std::cout << ans << nl;
        }else {
            if (n == 1) {
                std::cout << -1 << nl;
            }else{
                int rem = n - c0;
                if (rem & 1) {
                    if (x >= 2) {
                        ans += rem + 1;
                    }else {
                        ans += rem + 3;
                    }
                }else {
                    ans += rem;
                }
                std::cout << ans << nl;
            }
        }
    }
}
