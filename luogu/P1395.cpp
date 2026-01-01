// 树的重心
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
const int MAXN = 5e4 + 1;
vector<int> adj[MAXN];
vector<int> ans;
int sz[MAXN];
ll dp[MAXN];
ll min_dist = -1;
ll ans_node = -1;
int n, a, b;
void dfs1(int u, int fa) {
    sz[u] = 1;
    dp[u] = 0;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v] + sz[v];
    }
}
void dfs2(int u, int fa) {
    if (min_dist == -1 || dp[u] < min_dist) {
        min_dist = dp[u];
        ans_node = u;
    } else if (dp[u] == min_dist) {
        if (u < ans_node) ans_node = u;
    }
    for (int v : adj[u]) {
        if (v == fa) continue;
        dp[v] = dp[u] - sz[v] + (n - sz[v]);
        dfs2(v, u);
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans_node << " " << min_dist << "\n";

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
