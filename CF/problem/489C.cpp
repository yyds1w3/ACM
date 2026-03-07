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
const int MAXN = 1e3 + 5;
int a[MAXN];
void solve() {
    int m, s; cin >> m >> s;
    if (s == 0) {
        if (m == 1) cout << "0 0" << nl;
        else cout << "-1 -1" << nl;
        return;
    }
    if (s > 9 * m) {
        cout << "-1 -1" << nl;
        return;
    }
    int ss = s;
    a[1] = 1; s -= 1;
    per(i, m, 2) {
        a[i] = min(9, s);
        s -= a[i];
    }
    a[1] += max(s, 0);
    rep(i, 1, m) cout << a[i];
    cout << " ";
    rep(i, 1, m) {
        a[i] = min(9, ss);
        cout << a[i];
        ss -= a[i];
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
