#include <bits/stdc++.h>
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
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int dp[MAXN];
int sz[MAXN];
int n;
int mn = INF;
int node = INF;
void dfs1(int u, int fa) {
    sz[u] = 1;
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += sz[v] + dp[v];
    }
}

void dfs2(int u, int fa) {
    if (dp[u] < mn) {
        mn = dp[u];
        node = u;
    }else if (dp[u] == mn) {
        node = min(node, u);
    }
    for (int v : adj[u]) {
        if (v == fa) continue;
        dp[v] = dp[u] + (n - sz[v]) - sz[v];
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
