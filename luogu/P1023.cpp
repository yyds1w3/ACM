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
#define rep(i,s,e) for (ll i = s; i <= (ll)e; ++i)
#define per(i,e,s) for (ll i = e; i >= (ll)s; --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
int a[MAXN];
void solve() {
    int yq, cb, xs; cin >> yq >> cb >> xs;
    int dj, xsl;
    int cur_p = cb, cur_xsl = xs;
    a[cb] = xs;
    int mx_p = 0;
    while (cin >> dj >> xsl && !(dj == -1 && xsl == -1)) {
        int dec = (xsl - cur_xsl) / (dj - cur_p);
        rep(i, cur_p+1, dj) {
            a[i] = (cur_xsl) + dec*(i-cur_p);
        }
        cur_p = dj;
        cur_xsl = xsl;
        mx_p = max(mx_p, dj);
    }
    int dec; cin >> dec;
    while (cur_xsl > dec) {
        cur_p++; cur_xsl -= dec;
        a[cur_p] = cur_xsl;
        mx_p = max(cur_p, mx_p);
    }
    int down = -1e9, up = 1e9;
    rep(i, cb, mx_p) {
        if (i == yq) continue;
        double num = (double)(i - cb) * a[i] - (double)(yq - cb) * a[yq];
        double den = (double)(a[yq] - a[i]);
        if (a[yq] > a[i]) {
            down = max(down, (int)ceil(num / den));
        }else {
            up = min(up, (int)floor(num / den));
        }
    }
    if (down <= up) {
        if (down > 0) cout << down << nl;
        else if (up < 0) cout << up << nl;
        else cout << 0 << nl;
    }
    else cout << "No Solution" << nl;
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
