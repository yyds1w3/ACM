//Tue May 19 01:57:06 PM CST 2026
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
        int n, a, b;
        std::cin >> n >> a >> b;
        i64 ans;
        if (b < 3 * a) {
            ans = 1LL * n / 3 * b + std::min(1LL * (n % 3) * a, (i64)b);
        }else {
            ans = 1LL * n * a;
        }
        std::cout << ans << nl;
    }
}
