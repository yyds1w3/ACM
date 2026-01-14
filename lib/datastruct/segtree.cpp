/**
 * Algorithm: Segtree (Range Add + Range Mul)
 * Verified: Luogu P3373
 * Complexity: O(M log N)
 * Author: Qingw
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define Open(s) freopen(s ".in", "r", stdin); freopen(s ".out", "w", stdout);

// ========================start=============================
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int MAXN = 1e5 + 5;
ll tree[4 * MAXN];
ll lazy_add[4 * MAXN], lazy_mul[4 * MAXN];
ll a[MAXN];
ll m; // 模数 P

#define ls (p << 1)
#define rs (p << 1 | 1)

void push_up(int p) {
    tree[p] = (tree[ls] + tree[rs]) % m;
}

void push_down(int p, int l, int r) {
    if (lazy_mul[p] != 1) {
        tree[ls] = (tree[ls] * lazy_mul[p]) % m;
        lazy_mul[ls] = (lazy_mul[ls] * lazy_mul[p]) % m;
        lazy_add[ls] = (lazy_add[ls] * lazy_mul[p]) % m;

        tree[rs] = (tree[rs] * lazy_mul[p]) % m;
        lazy_mul[rs] = (lazy_mul[rs] * lazy_mul[p]) % m;
        lazy_add[rs] = (lazy_add[rs] * lazy_mul[p]) % m;

        lazy_mul[p] = 1;
    }

    if (lazy_add[p] != 0) {
        int mid = (l + r) >> 1;
        tree[ls] = (tree[ls] + lazy_add[p] * (mid - l + 1)) % m;
        lazy_add[ls] = (lazy_add[ls] + lazy_add[p]) % m;

        tree[rs] = (tree[rs] + lazy_add[p] * (r - mid)) % m;
        lazy_add[rs] = (lazy_add[rs] + lazy_add[p]) % m;

        lazy_add[p] = 0;
    }
}

void build(int p, int l, int r) {
    lazy_add[p] = 0;
    lazy_mul[p] = 1;
    if (l == r) {
        tree[p] = a[l] % m;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p);
}

// 区间乘法
void mult(int p, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        tree[p] = (tree[p] * val) % m;
        lazy_mul[p] = (lazy_mul[p] * val) % m;
        lazy_add[p] = (lazy_add[p] * val) % m;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) mult(ls, l, mid, ql, qr, val);
    if (mid < qr) mult(rs, mid + 1, r, ql, qr, val);
    push_up(p);
}
void add(int p, int l, int r, int ql, int qr, ll val) {
    if (ql <= l && r <= qr) {
        tree[p] = (tree[p] + val * (r - l + 1)) % m;
        lazy_add[p] = (lazy_add[p] + val) % m;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (ql <= mid) add(ls, l, mid, ql, qr, val);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, val);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[p];
    }
    push_down(p, l, r);
    ll res = 0;
    int mid = (l + r) >> 1;
    if (ql <= mid) res = (res + query(ls, l, mid, ql, qr)) % m;
    if (mid < qr) res = (res + query(rs, mid + 1, r, ql, qr)) % m;
    return res;
}
// =====================End=================================
int main() {
    int n, q;
    cin >> n >> q >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int opt; cin >> opt;
        if (opt == 1) {
            int x, y, k; cin >> x >> y >> k;
            mult(1, 1, n, x, y, k);
        }else if (opt == 2) {
            int x, y, k; cin >> x >> y >> k;
            add(1, 1, n, x, y, k);
        }else {
            int x, y; cin >> x >> y;
            cout << query(1, 1, n, x, y) << "\n";
        }
    }
}
