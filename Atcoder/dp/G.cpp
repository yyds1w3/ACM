#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
#define rep(i,s,e) for (int i = s; i <= (int)e; ++i)
#define per(i,e,s) for (int i = e; i >= (int)s; --i) 
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int memo[MAXN];
int dfs(int u) {
    if (memo[u] != -1) return memo[u];
    int mx = 0;
    for (int v : adj[u]) {
        mx = max(mx, dfs(v) + 1);
    }
    return memo[u] = mx;
}
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    rep(i, 1, n) memo[i] = -1;
    rep(i, 1, n) dfs(i);
    int ans = 0;
    rep(i, 1, n) ans = max(ans, memo[i]);
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
