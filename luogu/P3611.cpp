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
int dist[MAXN][MAXN];
void solve() {
    int n; cin >> n;
    rep(i, 1, n) rep(j, 1, n) cin >> dist[i][j];
    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                dist[i][j] = dist[i][j] | (dist[i][k] & dist[k][j]);
            }
        }
    }
    rep(i, 1, n) {
        rep(j, 1, n){
            cout << dist[i][j] << " ";
        }
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
