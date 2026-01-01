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
ll tree[4 * MAXN];
ll lazy[4 * MAXN];
ll a[MAXN];
ll b[MAXN];

#define ls (p << 1)
#define rs (p << 1 | 1)

void push_up(int p) {
    tree[p] = tree[ls] + tree[rs];
}

void push_down(int p, int l, int r) {
    if (lazy[p]) {
        int mid = (l + r) >> 1;
        tree[ls] += lazy[p] * (mid - l + 1);
        lazy[ls] += lazy[p];
        tree[rs] += lazy[p] * (r - mid);
        lazy[rs] += lazy[p];
        lazy[p] = 0;
    }
}

void build(int p, int l, int r) {
    lazy[p] = 0;
    if (l == r) {
        tree[p] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    push_up(p);
}

// 这里的 val 使用 ll 类型
void add(int p, int nl, int nr, int l, int r, ll val) {
    if (nl <= l && r <= nr) {
        tree[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (nl <= mid) add(ls, nl, nr, l, mid, val);
    if (mid < nr) add(rs, nl, nr, mid + 1, r, val); // 注意：这里是 mid < nr 也就是 nr > mid
    push_up(p);
}

ll query(int p, int nl, int nr, int l, int r) {
    if (nl <= l && r <= nr) {
        return tree[p];
    }
    ll res = 0;
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (nl <= mid) res += query(ls, nl, nr, l, mid);
    if (mid < nr) res += query(rs, nl, nr, mid + 1, r);
    return res;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    
    // 读入原数组并构造差分数组
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    
    build(1, 1, n);
    
    for (int i = 1; i <= m; ++i) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r;
            ll k, d; // 使用 long long
            cin >> l >> r >> k >> d;
            
            // 1. 修改起点 b[l]
            add(1, l, l, 1, n, k);
            
            // 2. 修改中间段 b[l+1...r] (只有当 l < r 时才存在中间段)
            if (l < r) {
                add(1, l + 1, r, 1, n, d);
            }
            
            // 3. 修改终点后一位 b[r+1] (需要减去末项)
            if (r < n) {
                ll last_val = k + (ll)(r - l) * d;
                add(1, r + 1, r + 1, 1, n, -last_val);
            }
            
        } else {
            int p;
            cin >> p;
            // 【修复】一定要输出答案！
            cout << query(1, 1, p, 1, n) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
