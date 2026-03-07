#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (long long i = s; i <= (long long)e; ++i)
#define per(i,e,s) for (long long i = e; i >= (long long)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 666623333;
const int MAXN = 1e6 + 5;
bool not_prime[MAXN];
ll primes[MAXN], cnt;
ll phi[MAXN], rem[MAXN];
void sieve(int k) {
    not_prime[0] = not_prime[1] = true;
    rep(i, 2, k) {
        if (!not_prime[i]) primes[++cnt] = i;
        rep(j, 1, cnt) {
            if (1LL * i * primes[j] > k) break;
            not_prime[i * primes[j]] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
void solve() {
    ll l, r; cin >> l >> r;
    sieve(1000000);
    rep(i, 0, r-l) {
        phi[i] = l + i;
        rem[i] = l + i;
    }
    rep(i, 1, cnt) {
        ll p = primes[i];
        if (p * p > r) break;
        for (int j = (p - l % p) % p; j <= r - l; j += p) {
            phi[j] = phi[j] / p * (p - 1);
            while (rem[j] % p == 0) rem[j] /= p;
        }
    }
    ll ans = 0;
    rep(i, 0, r-l) {
        if (rem[i] > 1) phi[i] = phi[i] / rem[i] * (rem[i] - 1);
        ans = (ans + (l+i - phi[i]) % MOD) % MOD;
    }
    cout << ans << nl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) solve();
}
