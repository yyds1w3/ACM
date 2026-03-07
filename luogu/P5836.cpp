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
const int LOG = 20;
vector<int> adj[MAXN];
int dep[MAXN];
int fa[MAXN][LOG+1];
int num[MAXN][2];
int n, m;
string s;
void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    fa[u][0] = f;
    num[u][0] = num[f][0]; num[u][1] = num[f][1];
    if (s[u-1] == 'H') num[u][0] += 1;
    if (s[u-1] == 'G') num[u][1] += 1;
    rep(i, 1, LOG) fa[u][i] = fa[fa[u][i-1]][i-1];
    for (int v : adj[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    per(i, LOG, 0) {
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    }
    if (u == v) return u;
    per(i, LOG, 0) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
void solve() {
    cin >> n >> m;
    cin >> s;
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        char p; cin >> p;
        int LCA = lca(u, v);
        int ans;
        if (p == 'H') {
            ans = num[u][0] + num[v][0] - 2 * num[LCA][0] + (s[LCA-1] == 'H');
        }else {
            ans = num[u][1] + num[v][1] - 2 * num[LCA][1] + (s[LCA-1] == 'G');
        }
        if (ans > 0) cout << 1;
        else cout << 0;
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
