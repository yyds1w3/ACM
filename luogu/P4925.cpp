#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
i64 qpow(i64 a, i64 b, i64 p) {
    i64 res = 1;
    a %= p;
    while (b){
        if (b & 1) res = res * a % p; 
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    i64 k, l, p, s, w;
    std::cin >> k >> l >> p >> s >> w;
    k %= p;
    if (l == 1) {
        if (s) std::cout << 1 << nl;
        else std::cout << k;
    }
    i64 ans = 1;
    if (s) ans = ans * (k - 1) % p;
    else ans = ans * k * (k - 1) % p;
    k -= 2;
    ans = (ans * qpow(k, l-2, p)) % p;
    std::cout << ans << nl;
    return 0;
}
