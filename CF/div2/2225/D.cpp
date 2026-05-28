//Tue Apr 21 11:25:32 PM CST 2026
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
const i64 MOD = 998244353;


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
        i64 n, x;
        std::cin >> n >> x;
        // 1 2 3 4 5 6 7 
        // 1 3 0 4 1 7 0
        // l [0, x-1]
        // r [x, n]
        i64 l0 = x / 4;
        i64 r0 = (n + 1) / 4 - l0;
        i64 l1 = x / 2 - l0;
        i64 r1 = ((n + 1) / 2 - x / 2) - r0;
        l0 += 1;
        l0 %= MOD;
        l1 %= MOD;
        r0 %= MOD;
        r1 %= MOD;
        i64 ans = (l0 * r0 % MOD + l1 * r1 % MOD) % MOD;
        std::cout << ans << nl;
    }
}
