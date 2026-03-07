#include <bits/stdc++.h>
#include <vector>
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
const int MAXN = 2e5 + 5;
int a[MAXN];
int pre[MAXN][2], suff[MAXN][2];
vector<int> v[2*MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 0, n+1) {
        pre[i][0] = 0;
        pre[i][1] = INF;
        suff[i][0] = 0;
        suff[i][1]= INF;
    }
    rep(i, 1, 2*n) v[i].clear();
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) {
        pre[i][0] = max(pre[i-1][0], a[i]);
        pre[i][1] = min(pre[i-1][1], a[i]);
    }
    rep(i, 1, n) cin >> a[i];
    repp(i, n, 1) {
        suff[i][0] = max(suff[i+1][0], a[i]);
        suff[i][1] = min(suff[i+1][1], a[i]);
    }
    rep(i, 1, n) {
        int mx = max(pre[i][0], suff[i][0]);
        int mn = min(pre[i][1], suff[i][1]);
        v[mn].push_back(mx);
    }
    ll ans = 0;
    int min_r = INF;
    repp(l, 2*n, 1) {
        for (int r : v[l]) min_r = min(min_r, r);
        if (min_r <= 2 * n) ans += (2*n - min_r + 1);
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
    cin >> tt;
    while (tt--) solve();
}
