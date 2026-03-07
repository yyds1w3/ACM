#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9;
const int MAXN = 1e6 + 5;
ll a[MAXN];
void solve() {
    ll n, k; cin >> n >> k;
    if (n < k) cout << 1 << nl;
    else {
        rep(i, 0, k-1) a[i] = 1;
        a[k] = k;
        rep(i, k + 1, n) {
            a[i] = (2 * a[i-1] - a[i-k-1] + MOD) % MOD;
        }
        cout << a[n] << nl;
    }
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
