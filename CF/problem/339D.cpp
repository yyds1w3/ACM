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
const int MAXN = (1 << 17) + 1;
int a[MAXN];
int tree[4 * MAXN];
#define ls (p << 1)
#define rs (p << 1 | 1)
void push_up(int p, int op) {
    if (op == 1) tree[p] = tree[ls] | tree[rs];
    else tree[p] = tree[ls] ^ tree[rs];
}
void build(int p, int l, int r, int op) {
    if (l == r) {
        tree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid, 1-op);
    build(rs, mid+1, r, 1-op);
    push_up(p, op);
}
void update(int p, int l, int r, int k, int b, int op) {
    if (l == r) {
        tree[p] = b;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) update(ls, l, mid, k, b, 1-op);
    else update(rs, mid+1, r, k, b, 1-op);
    push_up(p, op);
}
void solve() {
    int n, m; cin >> n >> m;
    int len = 1 << n;
    for (int i = 1; i <= len; ++i) cin >> a[i];
    // n & 1, root_op = | == 1;
    int op = n&1;
    build(1, 1, len, op);
    for (int i = 1; i <= m; ++i) {
        int k, b; cin >> k >> b;
        update(1, 1, len, k, b, op);
        cout << tree[1] << nl;
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
    while (tt--) solve();
}
