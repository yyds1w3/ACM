#include <bits/stdc++.h>
#ifdef LOCAL
#include "basic/debug.h"
#else
#define debug(...) 42
#endif
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using namespace std;
#define nl "\n"
#define rep(i,s,e) for (ll i = s; i <= (ll)e; ++i)
#define per(i,e,s) for (ll i = e; i >= (ll)s; --i) 
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
struct ScanLine {
    ll x;
    ll y1, y2;
    int mark;

    bool operator<(const ScanLine& other) const {return x < other.x;}
}; // 扫描线，从左往右，这条线有长度 
vector<ScanLine> lines;
ll y[2*MAXN], tot; // 用于线段树的（离散后）原数组，

struct Node { // 区块 , N个矩形，2N个y值，2N-1个区块
    int l, r; // 区块的左右边界
    int cnt; // 计数
    ll len; // 区块长度
}tree[MAXN * 8];
#define ls (p << 1)
#define rs (p << 1 | 1)
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].cnt = 0;
    tree[p].len = 0; // 刚开始的长度为0， 需要叶节点来pushup更新
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
}
void pushup(int p) {
    if (tree[p].cnt > 0) { // 这个区间有cnt, 至少被一个矩形完整覆盖过
        tree[p].len = y[tree[p].r + 1] - y[tree[p].l];
    }else { // 这个区间没有cnt
        if (tree[p].l == tree[p].r) tree[p].len = 0; // 如果区间是叶节点
        else tree[p].len = tree[ls].len + tree[rs].len; 
    }
}
void update(int p, int ql, int qr, int val) {
    if (ql <= tree[p].l && tree[p].r <= qr) {
        tree[p].cnt += val;
        pushup(p);
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (ql <= mid) update(ls, ql, qr, val);
    if (mid < qr) update(rs, ql, qr, val);
    pushup(p);
}
void solve() {
    int N; cin >> N;
    rep(i, 1, N) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int x11 = min(x1, x2), x22 = max(x1, x2);
        int y11 = min(y1, y2), y22 = max(y1, y2);
        lines.push_back({x11, y11, y22, 1});
        lines.push_back({x22, y11, y22, -1});
        y[++tot] = y11;
        y[++tot] = y22;
    }
    sort(lines.begin(), lines.end());
    sort(y + 1, y + 1 + tot);
    tot = unique(y + 1, y + 1 + tot) - (y + 1);
    build(1, 1, tot-1);
    ll ans = 0;
    rep(i, 0, lines.size()-2) {
        int ql = lower_bound(y + 1, y + 1 + tot, lines[i].y1) - y;
        int qr = lower_bound(y + 1, y + 1 + tot, lines[i].y2) - y;
        update(1, ql, qr-1, lines[i].mark);
        ans += tree[1].len * (lines[i+1].x - lines[i].x);
    }
    cout << ans << nl;

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
