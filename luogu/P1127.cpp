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
const int MAXN = 2e5 + 5;
int w[MAXN], v[MAXN];
ll cnt[MAXN], vs[MAXN];
int l[MAXN], r[MAXN];
ll n, m, s;
ll mn = LINF;
ll check(int x) {
    rep(i, 1, n) {
        cnt[i] = cnt[i-1] + (w[i] >= x);
        vs[i] = vs[i-1] + (w[i] >= x) * v[i];
    }
    ll ans = 0;
    rep(i, 1, m) {
        ans += (cnt[r[i]] - cnt[l[i]-1]) * (vs[r[i]] - vs[l[i]-1]);
    }
    return ans;
}
void solve() {
    cin >> n >> m >> s;
    rep(i, 1, n) cin >> w[i] >> v[i];
    rep(i, 1, m) cin >> l[i] >> r[i];
    int wl = 0, wr = 1000000;
    while (wl < wr) {
        int mid = (wl + wr) >> 1;
        ll Y = check(mid);
        if (abs(Y - s) < mn) mn = abs(Y - s);
        if (Y > s) {
            wl = mid+1;
        }else wr = mid;
    }
    cout << min(mn, abs(check(wl) - s));
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
