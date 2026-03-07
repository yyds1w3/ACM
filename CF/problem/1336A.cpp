#include <bits/stdc++.h>
#include <functional>
#include <numeric>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= e; ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int depth[MAXN];
int sz[MAXN];
ll val[MAXN];
void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    val[u] = depth[u] - sz[u];
}
void solve() {
    int n, k; cin >> n >> k;
    rep(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    sort(val + 1, val + 1 + n, greater<int>());
    ll ans = 0;
    rep(i, 1, k) ans += val[i];
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
