//2026-04-10 16:29:39
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
constexpr i64 MOD = 998244353;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    #endif
    int T;
    std::cin >> T;
    while (T--) {
        int x, y;
        std::cin >> x >> y;
        if (x <= y) {
            std::cout << 1 << nl;
        }else {
            std::cout << qpow(2, x - y - 1) * (y + 1) % MOD << nl;
        }
    }
}
