#include <algorithm>
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
const int MAXN = 1e5 + 1;
int n, k;
vector<int> adj[MAXN];
int fa[MAXN], h[MAXN];
int mx_dist, endpoint;
void dfs1(int u, int f, int d) { // 求最远的点， 两次就可以求出直径的两个端点
    fa[u] = f;
    if (d > mx_dist) {
        mx_dist = d;
        endpoint = u;
    }
    for (int v : adj[u]) {
        if (v == f) continue;
        dfs1(v, u, d+1);
    }
}
void dfs2(int u, int f) { // 求出以u为根的子树的高度
    h[u] = 0;
    for (int v : adj[u]) {
        if (v == f) continue;
        dfs2(v, u);
        h[u] = max(h[u], h[v] + 1);
    }
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mx_dist = -1;
    dfs1(1, 0, 0);
    int A = endpoint;
    mx_dist = -1;
    dfs1(A, 0, 0);
    int B = endpoint;

    vector<int> path;
    int curr = B;
    while (curr != 0) {
        path.push_back(curr);
        curr = fa[curr];
    }
    int root = path[path.size() / 2];
    dfs2(root, 0);
    
    vector<int> all_h;
    for (int i = 1; i <= n; ++i) {
        all_h.push_back(h[i]);
    }
    sort(all_h.begin(), all_h.end(), [](int a, int b) {return a > b;});
    cout << all_h[k] + 1 << endl;
    
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
