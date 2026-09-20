#include <bits/stdc++.h>
using i64 = long long;
// 0-index [L, R) 
// Info极值 + 单点修改 + 区间加 + 区间查询
struct MinInfo {
    int val, id;
    MinInfo() : val(1e9), id(-1) {}
    MinInfo(int val_, int id_) : val(val_), id(id_) {}
    MinInfo operator+(const MinInfo& other){
        if (val < other.val) return {val, id};
        else if (val > other.val) return {other.val, other.id};
        else return {val, std::min(id, other.id)};
    };
};
struct MaxInfo {
    int val, id;
    MaxInfo() : val(-1e9), id(-1) {}
    MaxInfo(int val_, int id_) : val(val_), id(id_) {}
    MaxInfo operator+(const MaxInfo& other){
        if (val > other.val) return {val, id};
        else if (val < other.val) return {other.val, other.id};
        else return {val, std::min(id, other.id)};
    };
};
template<class Info>
struct SegTree {
    int n;
    std::vector<int> a;
    std::vector<int> tag;
    std::vector<Info> tree;

    SegTree(int n_) : n(n_), a(n_), tag(4 * n), tree(4 * n) {}

    void pull(int u) {
        tree[u] = tree[2*u] + tree[2*u+1];
    }
    void push(int u) {
        if (tag[u]) {
            int lc = 2*u;
            int rc = 2*u+1;

            tag[lc] += tag[u];
            tag[rc] += tag[u];

            tree[lc].val = tree[lc].val + tag[u];
            tree[rc].val = tree[rc].val + tag[u];

            tag[u] = 0;
        }
    }
    // [L, R)
    void build(int u, int L, int R) {
        if (L == R - 1) {
            tree[u] = {a[L], L};
            return;
        }
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        build(lc, L, mid);
        build(rc, mid, R);
        pull(u);
    }
    void build() {
        build(1, 0, n);
    }
    void modify(int u, int L, int R, int pos, int val) {
        if (L == R - 1) {
            tree[u].val = val;
            return;
        }
        push(u);
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        if (pos < mid) modify(lc, L, mid, pos, val);
        else modify(rc, mid, R, pos, val);
        pull(u);
    }
    void modify(int pos, int val) {
        modify(1, 0, n, pos, val);
    }
    void rangeAdd(int u, int L, int R, int ql, int qr, int val) {
        if (ql <= L && R <= qr) {
            tree[u].val += val;
            tag[u] += val;
            return;
        }
        push(u);
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        if (ql < mid) rangeAdd(lc, L, mid, ql, qr, val);
        if (qr > mid) rangeAdd(rc, mid, R, ql, qr, val);
        pull(u);
    }
    void rangeAdd(int ql, int qr, int val) {
        rangeAdd(1, 0, n, ql, qr, val);
    }
    Info query(int u, int L, int R, int ql, int qr) {
        if (ql <= L && R <= qr) {
            return tree[u];
        }
        push(u);
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        Info res = {};
        if (ql < mid) res = res + query(lc, L, mid, ql, qr);
        if (qr > mid) res = res + query(rc, mid, R, ql, qr);
        return res;
    }
    Info query(int ql, int qr) {
        return query(1, 0, n, ql, qr);
    }
};
