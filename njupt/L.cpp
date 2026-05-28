//Wed May 20 06:59:11 PM CST 2026
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
i64 MOD = 998244353;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
i64 inv(i64 a) {
    return qpow(a, MOD - 2);
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int m, p, q;
        std::cin >> m >> p >> q;
    }
    std::cout << inv(2) << nl;
}
