#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;

void solve() {
    int n; cin >> n;
    ll ml = 2e9, lc = 0, mr = 0, rc = 0;
    ll tot = 2e9;
    for (int i = 1; i <= n; ++i) {
        ll l,r,c; cin >> l >> r >> c;
        if (l < ml) {
            ml = l;
            lc = c;
            tot = 2e9;
        }else if (l == ml) {
            lc = min(lc, c);
        }
        if (r > mr) {
            mr = r;
            rc = c;
            tot = 2e9;
        }else if (r == mr) {
            rc = min(rc, c);
        }
        if (l == ml && r == mr) {
            tot = min(c, tot);
        }
        cout << min(lc + rc, tot) << endl;
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
    while (tt--) {
        solve();
    }
    return 0;
}
