#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// 杨辉三角
ll C[5005][5005];
void init(int n, int mod){
    for (int i = 0; i <= n; ++i){
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j){
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}
// 预处理阶乘法
const int MAXN = 2e6 + 1;
const int MOD = 1e5 + 7;
ll fact[MAXN], invFact[MAXN];
ll qpow(ll a, ll b){
    ll ans = 1;
    a %= MOD;
    while (b){
        if (b & 1) ans = (ans + a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
void init(int n){
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i % MOD;
    invFact[n] = qpow(fact[n], MOD-2);
    for (int i = n-1; i >= 0; --i) invFact[i] = invFact[i+1] * (i + 1) % MOD;
}
ll comb(int n, int m){
    if (m < 0 || m > n) return 0;
    return fact[n] * invFact[m] % MOD * invFact[n-m] % MOD;
}

