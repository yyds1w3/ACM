#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;

// ==========================Start=======================================
const int MAXN = 1e5 + 5;
int n, m, r, p;
int w[MAXN];
vector<int> adj[MAXN];

// HLD
int fa[MAXN], dep[MAXN], sz[MAXN], son[MAXN];
int top[MAXN], dfn[MAXN], rnk[MAXN]; // top-->当前节点所在的重链的链头 dfn-->门牌号 rnk-->门牌号对应的原节点编号
int tot; // 门牌号计数器
void dfs1(int u, int f) {
    fa[u] = f;
    dep[u] = dep[f] + 1;
    sz[u] = 1;
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
    if (!son[u]) return;
    dfs2(son[u], t); // 重儿子延续父亲的重链
    for (int v : adj[u]) { // 轻儿子自己修重链
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
// Seg Tree 维护dfn
struct Node {
    int l, r;
    ll val, tag;
}tree[4 * MAXN];
#define ls k << 1
#define rs k << 1 | 1
void push_up(int k) {
    tree[k].val = (tree[ls].val + tree[rs].val) % p;
}
void push_down(int k) {
    if (tree[k].tag){
        int mid = (tree[k].r + tree[k].l) >> 1;                                  
        tree[ls].val = (tree[ls].val + tree[k].tag * (mid - l + 1)) % p;
        tree[ls].tag = (tree[ls].tag + tree[k].tag) % p;
        tree[rs].val = (tree[rs].val + tree[k].tag * (r - mid)) % p;
        tree[rs].tag = (tree[rs].val + tree[k].tag) % p;
        tree[k].tag = 0;
    }
}
void build(int k, int l, int r) {
    tree[k].l = l; tree[k].r = r;
    if (l == r) {
        tree[k].val = w[rnk[l]] % p;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    push_up(k);
}
void update(int k, int nl, int nr, int val) {
    if (nl <= tree[k].l && tree[k].r <= nr) {
        tree[k].val = (tree[k].val + (ll)val * (tree[k].r - tree[k].l + 1)) % p;
        tree[k].tag = (tree[k].tag + (ll)val) % p;
        return;
    }

}
// ==========================End=========================================

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    for (int i = 1; i <= m; ++i) {
        int opt, x, y, z;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> z;
            path_add(x, y, z);
        }else if (opt == 2) {
            cin >> x >> y;
            cout << path_query(x, y) << "\n";
        }else if (opt == 3) {
            cin >> x >> z;
            subtree_add(x, z);
        }else {
            cin >> x;
            cout << subtree_query(x) << "\n";
        }
    }
}
