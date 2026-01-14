#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
#define nl "\n"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using lll = __int128;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
ll tree[4 * MAXN];
ll a[MAXN];

#define ls (p << 1)
#define rs (p << 1 | 1)

void push_up(int p) {
    tree[p] = min(tree[ls], tree[rs]);
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p);
}
void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
        a[idx] = val;
        tree[p] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (l <= idx && idx <= mid) update(ls, l, mid, idx, val);
    if (mid < idx && idx <= r) update(rs, mid+1, r, idx, val);
    push_up(p);
}

ll query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[p];
    }
    ll res = LINF;
    int mid = (l + r) >> 1;
    if (ql <= mid) res = min(res, query(ls, l, mid, ql, qr));
    if (mid < qr) res = min(res, query(rs, mid + 1, r, ql, qr));
    return res;
}

void solve() {
    int n; cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int type; cin >> type;
        if (type == 1) {
            int idx, val; cin >> idx >> val;
            update(1, 1, n, idx, val);
        }else {
            int l, r; cin >> l >> r;
            int L = 0, R = r - l;
            while (L < R) {
                int mid = (L + R + 1) >> 1;
                if (query(1, 1, n, l, l + mid) >= mid) {
                    L = mid;
                }else R = mid - 1;
            }
            if (query(1, 1, n, l, l + L) == L) cout << 1 << nl;
            else cout << 0 << nl;
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
    cin >> tt;
    while (tt--) solve();
}
