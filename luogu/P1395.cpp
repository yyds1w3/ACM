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
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int sz[MAXN];
int dist[MAXN];
int n;
void dfs1(int u, int fa) {
    sz[u] = 1;
    dist[u] = 0;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dist[u] += sz[v] + dist[v];
    }
}
void dfs2(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        dist[v] = dist[u] + (n - sz[v]) - sz[v]; 
        dfs2(v, u);
    }
}
void solve() {
    cin >> n;
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    int mn = INF, node = -1;
    rep(i, 1, n) {
        if (mn > dist[i]) {
            mn = dist[i];
            node = i;
        }
    }
    cout << node << " " << mn << nl;
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
