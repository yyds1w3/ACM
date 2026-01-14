#include <bits/stdc++.h>
#include <numeric>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
ll p[MAXN];
void solve() {
    ll n, x, y; string s;
    cin >> n >> x >> y >> s;
    for (int i = 0; i < n; ++i) cin >> p[i];
    if (accumulate(p, p + n, 0LL) > x + y) {cout << "NO" << nl; return;}
    if (s == string(n, '0') || s == string(n, '1')) {
        if (s == string(n, '1')) swap(x, y);
        ll need = 0;
        for (int i = 0; i < n; ++i) {
            need += p[i] / 2 + 1;
        }
        if (x < need || x < y + n) {
            cout << "NO" << nl;
            return;
        }else {
            cout << "YES" << nl;
            return;
        }
    }else {
        ll x_need = 0, y_need = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') x_need += p[i] / 2 + 1;
            else y_need += p[i] / 2 + 1;
        }
        if (x >= x_need && y >= y_need) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    cin >> tt;
    while (tt--) solve();
}
