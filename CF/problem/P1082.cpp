#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
void ex_gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
    }else {
        ex_gcd(b, a%b, y, x);
        y -= a / b * x;
    }
}
int inv(int a, int p) {
    int x, y;
    ex_gcd(a, p, x, y);
    return (x % p + p) % p;
}
void solve() {
    int a, b; cin >> a >> b;
    cout << inv(a, b) << nl;
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
