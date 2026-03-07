#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
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
#define rep(i,s,e) for (ll i = s; i <= ll(e); ++i)
#define per(i,e,s) for (ll i = e; i >= ll(s); --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
void solve() {
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    rep(i, 0, n-1) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(),a.end()), a.end());
    int m = a.size();
    vector<bool> covered(n, false);
    vector<ll> ans;
    rep(i,0,m-1){
        if(covered[i]) continue;
        ans.push_back(a[i]);
        for (ll val = a[i]; val <= k; val += a[i]) {
            auto it = lower_bound(a.begin(), a.end(), val);
            if (it == a.end() || *it != val) {
                cout << -1 << nl;
                return;
            }
            int idx = int(it-a.begin());
            covered[idx] = true;
        }
    }
    cout << ans.size() << nl;
    rep(i,0,ans.size()-1) cout << ans[i] << " ";
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
