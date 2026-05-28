//Mon Apr 27 07:40:54 PM CST 2026
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
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> d(n);
    for (int i = 0; i < m; ++i) {
        i64 x = 0;
        char c;
        for (int j = 0; j < n; ++j) {
            x <<= 1;
            std::cin >> c;
            if (c == 'O') {
                x += 0;
            }else {
                x += 1;
            }
        }
        for (int j = n - 1; j >= 0; --j) {
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
    int p = n - std::count(d.begin(), d.end(), 0LL);
    int ans = 1;
    for (int i = 0; i < p; ++i) {
        ans = (2 * ans) % 2008;
    }
    std::cout << ans << nl;
}
