
#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;

const int MOD = 9901;
ll qpow(ll a, ll b){
    ll res = 1;
    a %= MOD;
    while(b){
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
ll inv(ll a){
    return qpow(a, MOD - 2);
}
// 1 + p^1 + ... + p^n(共n+1项) == 1 * (1 - p^n) * inv(1 - p)
ll sum_geometric(ll p, ll n){
    if ((p - 1) % MOD == 0){
        return (n + 1) % MOD;
    }
    return (((1 - qpow(p, n+1)) % MOD) + MOD) * (inv((1 - p) % MOD) + MOD) % MOD;
}
void solve() {
    int a, b;
    cin >> a >> b;
    if (a == 0){cout << 0 << endl; return;}
    if (a == 1){cout << 1 << endl; return;}
    if (b == 0){cout << 1 << endl; return;}
    ll ans = 1;
    for (int i = 2; i * i <= a; ++i){
        if (a % i == 0){
            ll cnt = 0;
            while (a % i == 0){
                cnt++;
                a /= i;
            }
            ans = (ans * sum_geometric(i, cnt * b)) % MOD;
        }
    }
    debug(ans, a, b);
    if (a > 1){
        ans = ans * sum_geometric(a, b) % MOD;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
