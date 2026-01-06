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
const int INF = 0x3f3f3f3f;
int n, q;
vector<int> adj[MAXN];

int fa[MAXN], sz[MAXN], dep[MAXN], son[MAXN];
int dfn[MAXN], rnk[MAXN], top[MAXN];
int tot;
int color[MAXN];
void dfs1(int u, int f) {
    fa[u] = f;
    sz[u] = 1;
    dep[u] = dep[f] + 1;
    for (int v : adj[u]) {
        if (v == f) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++tot;
    rnk[tot] = u;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : adj[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
int tree[4 * MAXN];
int col[MAXN];
#define ls (p << 1)
#define rs (p << 1 | 1)
void push_up(int p) {
    tree[p] = min(tree[ls], tree[rs]);
}
void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    push_up(p);
}
void change(int p, int l, int r, int idx, int val) {
    if (l == r) {
        tree[p] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid) change(ls, l, mid, idx, val);
    if (mid < idx) change(rs, mid+1, r, idx, val);
    push_up(p);
}
int query(int p, int l, int r, int nl, int nr) {
    if (nl <= l && r <= nr) return tree[p];
    int mid = (l + r) >> 1;
    int res = INF;
    if (nl <= mid) res = min(res, query(ls, l, mid, nl, nr));
    if (mid < nr) res = min(res, query(rs, mid + 1, r, nl, nr));
    return res;
}
int pathquery(int u) {
    int ans = -1;
    while (u) {
        int tp = top[u];
        int res = query(1, 1, n, dfn[tp], dfn[u]);
        if (res != INF) ans = rnk[res];
        u = fa[tp];
    }
    return ans;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int op, x; cin >> op >> x;
        if (op == 0) {
            if (color[x] == 0) {
                color[x] = 1;
                change(1, 1, n, dfn[x], dfn[x]);
            }
            else {
            color[x] = 0;
            change(1, 1, n, dfn[x], INF);
            }
        }else {
            cout << pathquery(x) << "\n";
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
