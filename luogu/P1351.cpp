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
const int MOD = 1e4 + 7;
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int w[MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n) cin >> w[i];
    ll mx = 0;
    ll tot = 0;
    rep(u, 1, n) {
        ll sum_w = 0;
        ll sum_sqw = 0;
        ll mx1 = 0;
        ll mx2 = 0;
        for (int v : adj[u]) {
            if (w[v] > mx1) {
                mx2 = mx1;
                mx1 = w[v];
            }else if (w[v] > mx2) {
                mx2= w[v];
            }
            sum_w = (sum_w + w[v]) % MOD;
            sum_sqw = (sum_sqw + w[v] * w[v]) % MOD;
        }
        mx = max(mx, mx1 * mx2);
        tot = (tot + (sum_w * sum_w - sum_sqw)) % MOD;
    }
    cout << mx << " " << tot << nl;
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
