// dsu on tree 树上启发式合并
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
vector<int> adj[MAXN];
int sz[MAXN], son[MAXN], col[MAXN]; // sz-->子树大小 son-->重儿子 col-->颜色
int cnt[MAXN]; // 每个节点计数它的最多颜色的个数
ll ans[MAXN]; // 每个节点的颜色编号之和
ll sm, mx, son_node; // 当前节点的sm(ans), mx(cnt), son_node(son)
void dfs1(int u, int fa) { // 遍历adj来初始化子树的大小和重儿子
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}
// 1 添加 -1 删除
void update(int u, int fa, int val) {
    int c = col[u]; // 取颜色
    if (val == -1) {
        cnt[c]--;
    }else {
        cnt[c]++;
        if (cnt[c] > mx) {
            mx = cnt[c];
            sm = c;
        }else if (cnt[c] == mx) {
            sm += c;
        }
    }
    for (int v : adj[u]) {
        if (v == fa || v == son_node) continue; // 只处理轻儿子(加和删)
        update(v, u, val);
    }
}
void dfs2(int u, int fa, bool keep) {
    for (int v : adj[u]) { // 先暴力处理轻儿子
        if (v == fa || v == son[u]) continue;
        dfs2(v, u, 0);
    }
    if (son[u]) {
        dfs2(son[u], u, 1); // 处理重儿子
        son_node = son[u];
    }
    update(u, fa, 1); // 加上该节点的颜色
    son_node = 0; // 
    ans[u] = sm; // 
    if (!keep) { // 如果是轻儿子, 需要清空
        update(u, fa, -1);
        sm = 0;
        mx = 0;
    }
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> col[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0, 1);
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
    while (tt--) {
        solve();
    }
    return 0;
}
