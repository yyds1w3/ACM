// 树上差分
// 差分要从下往上想， 回溯
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
int depth[MAXN];
int up[MAXN][25];
int diff[MAXN];
int ans;
void init(int u, int fa) {
    depth[u] = depth[fa] + 1;
    up[u][0] = fa;
    for (int i = 1; i <= 20; ++i) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v == fa) continue;
        init(v, u);
    }
}
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 20; i >= 0; --i) {
        if (depth[up[u][i]] >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 20; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
void sum(int u, int fa) {
    for (int v : adj[u]) {
        if (v == fa) continue;
        sum(v, u);
        diff[u] += diff[v];
    }
    ans = max(ans, diff[u]);
}
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init(1, 0);
    for (int i = 1; i <= k; ++i) {
        int s, t; cin >> s >> t;
        diff[s]++;
        diff[t]++;
        diff[lca(s, t)]--;
        diff[up[lca(s, t)][0]]--;
    }
    sum(1, 0);
    cout << ans << endl;
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
