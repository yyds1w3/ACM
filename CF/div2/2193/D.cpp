#include <algorithm>
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
const int MAXN = 2e5 + 5;
ll a[MAXN], b[MAXN];
int n;
void solve() {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    rep(i, 1, n) {
        cin >> b[i];
        b[i] += b[i-1];
    }
    ll mx = 0;
    rep(i, 1, n) {
        ll need = b[i];
        if (need > n) break;
        ll diff = a[n-need+1];
        mx = max(mx, diff * i);
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
