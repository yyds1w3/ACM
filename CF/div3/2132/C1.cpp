#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
#define nl "\n"
ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
ll f(ll x) {
    if (x == 0) return 3;
    return qpow(3, x+1) + x * qpow(3, x-1);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll ans = 0;
        while (n) {
            int x = 0;
            while (qpow(3, x) <= n) x++;
            x--;
            n -= qpow(3, x);
            ans += f(x);
        }
        cout << ans << nl;
    }
}
