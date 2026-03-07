#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 5e3 + 5;
ll a[MAXN];
void solve() {
    int n; cin >> n;
    int mx = 0;
    rep(i, 1, n) {
        int x; cin >> x;
        a[x]++;
        mx = max(mx, x);
    }
    ll ans = 0;
    per(i, mx, 2) {
        if (a[i] >= 2) {
            ll g1 = (a[i]-1) * (a[i]) / 2 % MOD;
            rep(j, 1, i / 2) {
                if (j != i-j) ans = (ans + g1 * a[j] * a[i-j]) % MOD;
                else ans = (ans + g1 * (a[j] * (a[j]-1) / 2)) % MOD;
            }
        }
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
