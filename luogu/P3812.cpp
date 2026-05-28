//Mon Apr 27 06:53:02 PM CST 2026
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
    int n;
    std::cin >> n;
    std::vector<i64> d(50);
    for (int i = 0; i < n; ++i) {
        i64 x;
        std::cin >> x;
        for (int j = 49; j >= 0; --j) {
            if ((x >> j) & 1) {
                if (d[j] == 0) {
                    d[j] = x;
                    break;
                }else {
                    x ^= d[j];
                }
            }
        }
    }
    i64 ans = 0;
    for (int i = 49; i >= 0; --i) {
        if ((ans ^ d[i]) > ans) {
            ans ^= d[i];
        }
    }
    std::cout << ans << nl;
}
