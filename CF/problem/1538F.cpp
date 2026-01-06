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
int wei(int x) {
    int res = 1;
    while (x /= 10) res++;
    return res;
}
ll qpow(int base, int p) {
    ll res = 1;
    while (p) {
        if (p & 1) res *= base;
        base *= base;
        p >>= 1;
    }
    return res;
}
void solve() {
    int l, r; cin >> l >> r;
    int wr = wei(r);
    ll ans = 0;
    for (int p = 2; p <= wr; ++p) {
        ans += (r / qpow(10, p-1) - l / qpow(10, p-1)); 
    }
    ans += r - l ;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
