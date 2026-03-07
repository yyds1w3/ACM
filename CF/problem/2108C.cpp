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
#define rep(i,s,e) for (int i = s; i <= (e); ++i)
#define per(i,e,s) for (ll i = e; i >= (s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void solve() {
    int n; cin >> n;
    vector<int> a;
    a.push_back(-INF);
    rep(i, 1, n) {
        int x; cin >> x;
        if (a.back() != x) a.push_back(x); 
    }
    a.push_back(-INF);
    int ans = 0;
    rep(i, 1, (int)a.size()-1) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) ans++;
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
