#include <bits/stdc++.h>
#include <vector>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 1;
int a[MAXN];
vector<int> adj[MAXN];
int dp[MAXN];
int ans[MAXN];
void dfs1(int u, int fa) {
    dp[u] = a[u];
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        if (dp[v] > 0) dp[u] += dp[v];
    }
}
void dfs2(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        ans[v] = dp[v] + max(0, ans[u] - max(0, dp[v]));
        dfs2(v, u);
    }
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int c; cin >> c;
        a[i] = (c == 1 ? 1 : -1);
    } 
    for (int i = 1; i <= n - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    ans[1] = dp[1];
    dfs2(1, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i] << " ";
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
