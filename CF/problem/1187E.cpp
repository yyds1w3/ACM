#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using i128 = __int128;
const int MAXN = 2e5 + 1;
int n;
ll mx;
ll dp[MAXN];
int sz[MAXN];
vector<int> adj[MAXN];
void dfs1(int u, int fa) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}
void dfs2(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        dp[v] = dp[u] + n - 2 * sz[v];
        mx = max(mx, dp[v]);
        dfs2(v, u);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[1] += sz[i];
    }
    mx = dp[1];
    dfs2(1, 0);
    cout << mx << '\n';
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
