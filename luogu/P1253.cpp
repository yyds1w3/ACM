#include <bits/stdc++.h>
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
const ll INF = 4e18; 
ll tree[4 * MAXN];
ll lazy_cov[4 * MAXN];
ll lazy_add[4 * MAXN];
ll a[MAXN];
#define ls (p << 1)
#define rs (p << 1 | 1)

void push_up(int p) {
    tree[p] = max(tree[ls], tree[rs]);
}
void push_down(int p, int l, int r) {
    if (lazy_cov[p] != INF) {

        tree[ls] = lazy_cov[p] + lazy_add[p];
        lazy_cov[ls] = lazy_cov[p] + lazy_add[p];
        lazy_add[ls] = 0;

        tree[rs] = lazy_add[p] + lazy_cov[p];
        lazy_cov[rs] = lazy_cov[p] + lazy_add[p];
        lazy_add[rs] = 0;

        lazy_cov[p] = INF;
        lazy_add[p] = 0;
    }
    else {

        tree[ls] += lazy_add[p];
        lazy_add[ls] += lazy_add[p];

        tree[rs] += lazy_add[p];
        lazy_add[rs] += lazy_add[p];

        lazy_add[p] = 0;
    }
}
void build(int p, int l, int r) {
    lazy_cov[p] = INF;
    lazy_add[p] = 0;
    if (l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    push_up(p);
}
void cov(int p, int l, int r, int nl, int nr, ll val) {
    if (nl <= l && r <= nr) {
        tree[p] = val;
        lazy_cov[p] = val;
        lazy_add[p] = 0;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (nl <= mid) cov(ls, l, mid, nl, nr, val);
    if (mid < nr) cov(rs, mid+1, r, nl, nr, val);
    push_up(p);
}
void add(int p, int l, int r, int nl, int nr, ll val) {
    if (nl <= l && r <= nr) {
        tree[p] += val;
        if (lazy_cov[p] != INF) lazy_cov[p] += val;
        else lazy_add[p] += val;
        return;
    }
    int mid = (l + r) >> 1;
    push_down(p, l, r);
    if (nl <= mid) add(ls, l, mid, nl, nr, val);
    if (mid < nr) add(rs, mid+1, r, nl, nr, val);
    push_up(p);
}
ll query_mx(int p, int l, int r, int nl, int nr) {
    if (nl <= l && r <= nr) {
        return tree[p];
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    ll res = -INF;
    if (nl <= mid) res = max(res, query_mx(ls, l, mid, nl, nr));
    if (mid < nr) res = max(res, query_mx(rs, mid+1, r, nl, nr));
    return res;
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, x; cin >> l >> r >> x;
            cov(1, 1, n, l, r, x);
        }else if (op == 2) {
            int l, r, x; cin >> l >> r >> x;
            add(1, 1, n, l, r, x);
        }else {
            int l, r; cin >> l >> r;
            cout << query_mx(1, 1, n, l, r) << "\n";
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
