//Sat May 30 09:36:11 PM CST 2026
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
const int MOD = 998244353;
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    // x + 10 ^ L + y == x + y
    // x * (10 ^ L - 1) == 0 (mod M);
    auto qpow = [](i64 a, i64 b) -> i128 {
        i128 res = 1;
        while (b) {
            if (b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    };
    int t;
    std::cin >> t;
    while (t--) {
        i64 n, m;
        std::cin >> n >> m;
        i64 ans = 0;
        for (int L = 1; L <= 19; ++L) {
            if (qpow(10, L-1) > n) break;
            i128 cnty = std::min((i128)n, qpow(10, L) - 1) - std::min((i128)n, qpow(10, L-1)) + 1;
            i64 val = (qpow(10, L) - 1) % m;
            i64 cntx = n / (m / std::gcd(m, val));
            ans = (ans + (cnty % MOD * cntx % MOD) % MOD) % MOD;
        }
        std::cout << ans << nl;
    }
}
