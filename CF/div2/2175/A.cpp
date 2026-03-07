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
const int MAXN = 1e2 + 5;
int a[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int sz = unique(a + 1, a + 1 + n) - (a+1);
    debug(sz);
    cout << *lower_bound(a + 1, a + 1 + sz, sz) << nl;
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
