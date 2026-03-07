#include <bits/stdc++.h>
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
const int MAXN = 2e2 + 5;
int n, m;
int tim[MAXN];
ll dist[MAXN][MAXN];
void solve() {
    cin >> n >> m;
    rep(i, 0, n-1) {
        rep(j, 0, n-1) dist[i][j] = LINF;
        dist[i][i] = 0;
    }
    rep(i, 0, n-1) cin >> tim[i];
    rep(i, 1, m) {
        ll u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    int q; cin >> q;
    int k = 0;
    while (q--) {
        int x, y, t; cin >> x >> y >> t;
        while (k < n && tim[k] <= t) {
            rep(i, 0, n-1) {
                rep(j, 0, n-1) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
            k++;
        }
        if (tim[y] > t || tim[x] > t || dist[x][y] == LINF) cout << -1 << nl;
        else cout << dist[x][y] << nl;
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
