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
struct Edge {
    ll to, w;
};
vector<Edge> adj[MAXN];
ll sz[MAXN];
ll ans;
int n;
void dfs(int u, int fa) {
    sz[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        ans += w * abs((n - sz[v]) - sz[v]);
    }
}
void solve() {
    cin >> n;
    rep(i, 1, n-1) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0);
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
