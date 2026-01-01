#include <bits/stdc++.h>
#include <utility>
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
int tree[4 * MAXN];
int lazy[4 * MAXN];
int L, T, O;
#define ls (p << 1)
#define rs (p << 1 | 1)
void push_up(int p) {
    tree[p] = tree[ls] | tree[rs];
}
void push_down(int p) {
    if (lazy[p]) {
        tree[ls] = (1 << lazy[p]);
        lazy[ls] = lazy[p];

        tree[rs] = (1 << lazy[p]);
        lazy[rs] = lazy[p];

        lazy[p] = 0;
    }
}
void build(int p, int l, int r) {
    lazy[p] = 0;
    if (l == r) {
        tree[p] = 1 << 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    push_up(p);
}
void cov(int p, int l, int r, int nl, int nr, int val) {
    if (nl <= l && r <= nr) {
        tree[p] = (1 << val);
        lazy[p] = val;
        return;
    }
    push_down(p);
    int mid = (l + r) >> 1;
    if (nl <= mid) cov(ls, l, mid, nl, nr, val);
    if (mid < nr) cov(rs, mid+1, r, nl, nr, val);
    push_up(p);
}
int query(int p, int l, int r, int nl, int nr) {
    if (nl <= l && r <= nr) {
        return tree[p];
    }
    push_down(p);
    int res = 0;
    int mid = (l + r) >> 1;
    if (nl <= mid) res |= query(ls, l, mid, nl, nr);
    if (mid < nr) res |= query(rs, mid+1, r, nl, nr);
    return res;
}

void solve() {
    cin >> L >> T >> O;
    build(1, 1, L);
    for (int i = 1; i <= O; ++i) {
        char op; cin >> op;
        if (op == 'C') {
            int A, B, C; cin >> A >> B >> C;
            if (A > B) swap(A, B);
            cov(1, 1, L, A, B, C);
        }else {
            int A, B; cin >> A >> B;
            if (A > B) swap(A, B);
            int ans = query(1, 1, L, A, B);
            // int cnt = 0;
            // for (int i = 1; i <= 30; ++i){
            //     if (ans & (1 << i)) cnt++;
            // }
            // cout << cnt << "\n";
            cout << __builtin_popcount(ans) << "\n";
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
