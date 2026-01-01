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

const int MAXN = 2e5 + 1;
struct Node {
    int lmx, rmx, tmx, len, lv, rv;
}tree[4 * MAXN];
#define ls (p << 1)
#define rs (p << 1 | 1)
void push_up(int p) {
    tree[p].len = tree[ls].len + tree[rs].len;
    tree[p].lmx = tree[ls].lmx;
    tree[p].rmx = tree[rs].rmx;
    tree[p].lv = tree[ls].lv;
    tree[p].rv = tree[rs].rv;
    tree[p].tmx = max(tree[ls].tmx, tree[rs].tmx);
    if (tree[ls].rv != tree[rs].lv) {
        tree[p].tmx = max(tree[p].tmx, tree[ls].rmx + tree[rs].lmx);
        if (tree[ls].lmx == tree[ls].len) tree[p].lmx = tree[ls].len + tree[rs].lmx;
        if (tree[rs].rmx == tree[rs].len) tree[p].rmx = tree[rs].len + tree[ls].rmx;
    }
}
void build(int p, int l, int r) {
    if (l == r) {
        tree[p].lmx = tree[p].rmx = tree[p].tmx = tree[p].len = 1;
        tree[p].lv = tree[p].rv = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    push_up(p);
}
void update(int p, int l, int r, int x) {
    if (l == r) {
        tree[p].lv ^= 1;
        tree[p].rv ^= 1;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) update(ls, l, mid, x);
    if (mid < x) update(rs, mid+1, r, x);
    push_up(p);
}

void solve() {
    int n, q; cin >> n >> q;
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int x; cin >> x;
        update(1, 1, n, x);
        cout << tree[1].tmx << "\n";
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
