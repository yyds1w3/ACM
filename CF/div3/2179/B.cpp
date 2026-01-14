#include <bits/stdc++.h>
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
ll a[MAXN];
void solve() {
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans += abs(a[i] - a[i-1]);
    }
    ans -= a[1];
    debug(ans);
    ll mn = LINF;
    for (int i = 2; i <= n - 1; ++i) {
        mn = min(mn, abs(a[i+1] - a[i-1]) - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i])); 
        debug(mn);
    }
    mn = min(mn, -abs(a[2] - a[1]));
    debug(mn);
    mn = min(mn, -abs(a[n] - a[n-1]));
    debug(mn);
    cout << ans + mn << nl;
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
