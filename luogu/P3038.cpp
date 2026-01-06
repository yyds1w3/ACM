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
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int n, m;

int fa[MAXN], sz[MAXN], dep[MAXN], son[MAXN];
int top[MAXN], dfn[MAXN], rnk[MAXN];
int tot;
void dfs1(int u, int f) {
    fa[u] = f;
    sz[u] = 1;
    dep[u] = dep[f] + 1;
    for (int v : adj[u]) {
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (!son[u]) return; // 叶节点了
    dfs2(son[u], t);
    for (int v : adj[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
struct Node {
    int l, r;
    ll val, tag;
}tree[4 * MAXN];
#define ls (p << 1)
#define rs (p << 1 | 1)
void push_up(int p) {
    tree[p].val = tree[ls].val + tree[rs].val;
}
void push_down(int p) {
    if (tree[p].tag) {
        int l = tree[p].l, r = tree[p].r;
        int mid = (l + r) >> 1;
        tree[ls].val += tree[p].tag * (mid - l + 1);
        tree[ls].tag += tree[p].tag;
        tree[rs].val += tree[p].tag * (r - mid);
        tree[rs].tag += tree[p].tag;
        tree[p].tag = 0;
    }
}
void build(int p, int l, int r) {
    tree[p].l = l; tree[p].r = r;
    tree[p].tag = 0;
    if (l == r) {
        tree[p].val = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    push_up(p);
}
void update(int p, int nl, int nr, int val) {
    if (nl <= tree[p].l && tree[p].r <= nr) {
        tree[p].val += val * (tree[p].r - tree[p].l + 1);
        tree[p].tag += val;
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (nl <= mid) update(ls, nl, nr, val);
    if (mid < nr) update(rs, nl, nr, val);
    push_up(p);
}
ll query(int p, int nl, int nr) {
    if (nl <= tree[p].l && tree[p].r <= nr) {
        return tree[p].val; 
    }
    push_down(p);
    ll res = 0;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (nl <= mid) res += query(ls, nl, nr);
    if (mid < nr) res += query(rs, nl, nr);
    return res;
}
void pathadd(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, dfn[top[x]], dfn[x], 1);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, dfn[x]+1, dfn[y], 1);
}
ll pathquery(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    return query(1, dfn[x], dfn[x]);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        char op; int u, v; cin >> op >> u >> v;
        if (op == 'P') {
            pathadd(u, v);
        }else {
            cout << pathquery(u, v) << "\n";
        }
    }
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
