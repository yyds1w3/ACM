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
const int MAXN = 1e2 + 5;
int n, m;
ll dist[MAXN][MAXN];
void floyd(){
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
}
void solve() {
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = LINF;
        }
    }
    rep(i, 1, m) {
        ll u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    floyd();
    rep(i, 1, n) {
        rep(j, 1, n) 
            cout << dist[i][j] << " ";
        cout << nl;
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
