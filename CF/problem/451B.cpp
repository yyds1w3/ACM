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
const int MAXN = 1e5 + 5;
int a[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) cin >> a[i];
    int s = 1, e = 1;
    bool f1 = true;
    rep(i, 1, n-1) {
        if (a[i+1] <= a[i] && f1) {
            e = i+1;
            s = i;
            f1 = false;
        }
        if (a[i+1] <= a[i] && !f1) {
            e = i+1;
        }
        if (a[i+1] > a[i] && !f1) break;
        debug(s, e, i);
    }
    if (s > 1) {
        if (a[e] < a[s-1]) {
            cout << "no" << nl;
            return;
        }
    }
    if (e < n) {
        if (a[s] > a[e+1]) {
            cout << "no" << nl;
            return;
        }
    }
    rep(i, e+1, n-1) {
        if (a[i+1] < a[i]) {
            cout << "no" <<nl;
            return;
        }
    }
    cout << "yes" << nl;
    cout << s << " " << e << nl;
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
