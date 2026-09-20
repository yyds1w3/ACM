//Sat Jul 25 08:37:56 PM CST 2026
#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#endif
using i64 = long long;
using i128 = __int128;
const int MOD = 998244353;
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
i64 inv(i64 x) {
    return qpow(x, MOD - 2);
}
void solve() {
    int n;
    std::cin >> n;
    i64 B = 0;
    for (int i = 1; i <= n; ++i) {
        B = (B + inv(i)) % MOD;
    }
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i){
        std::cin >> a[i];
    }
    i64 P = B;
    i64 ans = P * a[1] % MOD;
    for (int i = 2; i <= n; ++i) {
        B = ((B - inv(i - 1) - inv(n - i + 2)) % MOD + MOD) % MOD;
        P = (P + B) % MOD;
        ans = (ans + P * a[i] % MOD) % MOD;
    }
    std::cout << ans << nl;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    solve();
}
