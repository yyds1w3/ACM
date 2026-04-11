#include <bits/stdc++.h>
using ll = long long;
using i128 = __int128;
#define nl "\n"
ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = (i128)res * a % p;
        a = (i128)a * a % p;
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
    ll K, M, P, PP;
    std::cin >> K >> M;
    P = 10007 * M;
    PP = 9 * P;
    ll R = 0;
    for (int i = 0; i < K; ++i) {
        ll c, l;
        std::cin >> c >> l;
        R = ((i128)R * qpow(10, l, P) + (i128)c * ((qpow(10, l, PP) - 1 + PP) % PP / 9)) % P;
    }
    std::cout << R / M % 10007 << nl;
}
