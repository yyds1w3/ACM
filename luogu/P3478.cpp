// 先用dfs1回溯求出子树的大小和每个节点相对于1的深度
// 初始化dp[1]
// 再用dfs2动态更新每个根节点的深度和，动态更新最大值
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
const int MAXN = 1e6 + 1;
vector<int> adj[MAXN];
int sz[MAXN], dep[MAXN];
ll dp[MAXN];
int n;
ll mx, nd;
void dfs1(int u, int fa) {
    sz[u] = 1;
    dep[u] = dep[fa] + 1;
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
        if (dp[v] > mx) {
            mx = dp[v];
            nd = v;
        }
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
    dep[0] = -1;
    dfs1(1, 0);
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[1] += dep[i];
    }
    mx = dp[1];
    nd = 1;
    dfs2(1, 0);
    cout << nd << endl;
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
