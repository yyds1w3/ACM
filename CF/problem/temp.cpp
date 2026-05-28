//Wed Apr 15 10:50:47 PM CST 2026
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
    freopen("sout.txt", "w", stdout);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> E(n + 1);
    i64 invM = qpow(m, MOD - 2);
    for (int i = n - 1; i >= 0; --i) {
        i64 sum = 0;
        for (int j = 1; j <= m; ++j) {
            int nxt = std::min(i + j, n);
            sum = (sum + E[nxt]) % MOD;
        }
        E[i] = (1 + invM * sum) % MOD;
    }
    std::cout << E[0] << nl;
    return 0;
}
