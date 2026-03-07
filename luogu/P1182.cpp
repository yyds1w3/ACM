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
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
ll a[MAXN];
int n, m;
bool check(ll x) {
    int now = 0;
    int seg = 1;
    rep(i, 1, n) {
        if (now + a[i] <= x) {
            now += a[i];
        }else {
            seg++;
            now = a[i];
        }
    }
    return seg <= m;
}
void solve() {
    cin >> n >> m;
    ll l = 0, r = 0;
    rep(i, 1, n) {
        cin >> a[i];
        r += a[i];
        l = max(l, a[i]);
    }
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;        
        }else {
            l = mid + 1;
        }
    }
    cout << l << nl;
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
