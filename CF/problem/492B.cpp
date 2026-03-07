#include <bits/stdc++.h>
#include <iomanip>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
#define repp(i,e,s) for (int i = e; i >= s; --i) 
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
    int n, l; cin >> n >> l;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    double mx = 0;
    rep(i, 1, n-1) {
        mx = max(mx, (double)a[i+1] - a[i]);
    }
    mx /= 2;
    mx = max(mx, (double)l - a[n]);
    mx = max(mx, (double)a[1]);
    cout << setprecision(9) << fixed <<mx << nl;
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
