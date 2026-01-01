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
const int MAXN = 1e5 + 1;
int tree[4 * MAXN];
int lazy[4 * MAXN];
int n, m;
#define ls (p << 1)
#define rs (p << 1 | 1)
void push_up(int p) {
    tree[p] = tree[ls] + tree[rs]; // 通过子节点更新本节点
}
void push_down(int p, int l, int r) {
    if (lazy[p]) { // 懒标记下传
        int mid = (l + r) >> 1;

        tree[ls] = (mid - l + 1) - tree[ls]; // 区间和 
        lazy[ls] ^= 1; // 懒标记

        tree[rs] = (r - mid) - tree[rs];
        lazy[rs] ^= 1;

        lazy[p] = 0;
    }
}
void build(int p, int l, int r) {
    lazy[p] = 0;
    if (l == r) {
        tree[p] = 0; // 默认叶节点关灯
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid); // 递归左子树
    build(rs, mid+1, r); // 递归右子树
    push_up(p); // 回溯更新节点值
}
void update(int nl, int nr, int p, int l, int r) {
    if (nl <= l && r <= nr) { // 修改区间被完全覆盖
        tree[p] = (r - l + 1) - tree[p]; // 更新节点值
        lazy[p] ^= 1; // 打懒标记
        return;
    }
    push_down(p, l, r); // 下发懒标记
    int mid = (l + r) >> 1;
    if (nl <= mid) update(nl, nr, ls, l, mid); // 递归左子树更新
    if (mid+1 <= nr) update(nl, nr, rs, mid+1, r); // 递归右子树更新
    push_up(p); // 回溯更新必要的子树
}
int query(int nl, int nr, int p, int l, int r) {
    if (nl <= l && r <= nr) { // 查询区间被完全覆盖
        return tree[p]; 
    }
    push_down(p, l, r); // 下发懒标记
    int mid = (l + r) >> 1;
    int res = 0;
    if (nl <= mid) res += query(nl, nr, ls, l, mid); // 递归查询左子树
    if (mid+1 <= nr) res += query(nl, nr, rs, mid+1, r);
    return res;
}
void solve() {
    cin >> n >> m;
    build(1, 1, n);
    while (m--) {
        int op, a, b;
        cin >> op >> a >> b;
        if (a > b) swap(a, b);
        if (op == 0) {
            update(a, b, 1, 1, n);
        }else {
            cout << query(a, b, 1, 1, n) << endl;
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
