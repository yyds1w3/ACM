// Mon Dec 15 08:49:40 PM CST 2025
// 学到了lca的简单写法, 利用了dfs来遍历树得到深度和宽度
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
struct Node{
    int l;
    int r;
    int fa;
}tree[101];
int n;
int depth[101];
int width_cnt[101];
int max_depth, max_width;
void dfs(int root, int fa){
    if (root == 0) return;
    depth[root] = depth[fa] + 1;
    debug(root, depth[root]);
    max_depth = max(max_depth, depth[root]);
    max_width = max(max_width, ++width_cnt[depth[root]]);
    dfs(tree[root].l, root);
    dfs(tree[root].r, root);
}
int lca(int u, int v){
    while(depth[u] > depth[v]) u = tree[u].fa;
    while(depth[v] > depth[u]) v = tree[v].fa;
    // ensure the same height
    while(u != v){
        u = tree[u].fa;
        v = tree[v].fa;
    }
    return u;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        int u, v;
        cin >> u >> v;
        if (tree[u].l) {
            tree[u].r = v;
            tree[v].fa = u;
        }
        else{
            tree[u].l = v;
            tree[v].fa = u;
        }
    }
    dfs(1, 0);
    int x, y, ans = 0;
    cin >> x >> y;
    int LCA = lca(x, y);
    ans += (depth[x] - depth[LCA]) * 2 + (depth[y] - depth[LCA]);
    cout << max_depth << "\n" << max_width << "\n" << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    if (fopen("in.txt", "r")) {
        freopen("in.txt", "r", stdin);
    }
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
#ifdef LOCAL
    auto _clock_end = chrono::high_resolution_clock::now();
    cerr << "Run Time: " 
         << chrono::duration_cast<chrono::milliseconds>(_clock_end - _clock_start).count() 
         << " ms" << endl;
#endif
    return 0;
}
