//Thu Apr 23 10:25:28 PM CST 2026
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
    std::string t;
    std::cin >> n >> t;
    int c0 = 1, c1 = 0;
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        if (t[i] == '0') {
            zeros++;
        }
        if (zeros & 1) c1++;
        else c0++;
    }
    i64 ans = (i64)(c0 - 1) * c0 / 2 + (i64)(c1 - 1) * c1 / 2;
    std::cout << ans << nl;
}
