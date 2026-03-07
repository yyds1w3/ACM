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
int a[MAXN], b[MAXN];
int pre[MAXN];
ll query(int l, int r) { 
    return pre[r] - pre[l-1];
}
void solve() {
    int n, q; cin >> n >> q;
    rep(i, 1, n+1) pre[i] = 0;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
    per(i, n+1, 2) pre[i-1] = max({pre[i], a[i-1], b[i-1]});
    rep(i, 2, n) pre[i] += pre[i-1];
    rep(i, 1, q) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << " "; 
    }
    cout << nl;
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
