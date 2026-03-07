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
const int MAXN = 101;
int n, m;
ll dist[MAXN][MAXN];
void solve() {
    cin >> n >> m;
    rep(i, 1, n) {
        rep(j, 1, n) dist[i][j] = dist[j][i] = LINF;
        dist[i][i] = 0;
    }
    rep(i, 1, m) {
        ll u, v, w; cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[u][v], w);
    }
    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ll ans = LINF;
    rep(u, 1, n) {
        rep(v, u+1, n) {
            ll curr = 0;
            rep(i, 1, n) {
                rep(j, i+1, n) {
                    curr += min({dist[i][j], dist[i][u] + dist[v][j], dist[i][v] + dist[u][j]});
                }
            }
            ans = min(ans, curr);
        }
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
    // cin >> tt;
    while (tt--) solve();
}
