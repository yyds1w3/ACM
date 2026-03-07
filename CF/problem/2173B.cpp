#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    ll mx = 0, mn = 0;
    rep(i, 1, n) {
        ll mxa = mx - a[i];
        ll mxb = b[i] - mn;
        ll mna = mn - a[i];
        ll mnb = b[i] - mx;
        mx = max(mxa, mxb);
        mn = min(mna, mnb);
    }
    cout << mx << nl;

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
