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

constexpr int MOD = 9901;
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
i64 inv(i64 a) {
    a = (a % MOD + MOD) + MOD;
    return qpow(a, MOD - 2);
}
i64 prod(i64 p, i64 e) {
    p = (p % MOD + MOD) % MOD;
    if (p == 1) return (e + 1) % MOD;
    return ((1 - qpow(p, e + 1)) % MOD + MOD) * inv(1 - p) % MOD;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int a, b;
    std::cin >> a >> b;
    i64 ans = 1;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            i64 cnt = 0;
            while (a % i == 0) {
                cnt++;
                a /= i;
            }
            ans = ans * prod(i, cnt * b) % MOD;
        }
    }
    if (a > 1) {
        ans = ans * prod(a, b) % MOD;
    }
    std::cout << ans << nl;
}
