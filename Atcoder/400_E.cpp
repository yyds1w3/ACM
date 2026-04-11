#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using lll = __int128;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
int a[MAXN];
void solve() {
    rep(i, 2, 1000000) {
        if (a[i] == 0) for (int j = i; j <= 1000000; j += i) a[j]++;
    }
    vector<ll> ans;
    rep(i, 2, 1000000) {
        if (a[i] == 2) ans.push_back(i * i);
    }
    int t; cin >> t;
    while (t--) {
        ll q; cin >> q;
        cout << *prev(upper_bound(ans.begin(), ans.end(), q)) << nl;
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
