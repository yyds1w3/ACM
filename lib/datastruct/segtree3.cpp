#include <bits/stdc++.h>
using i64 = long long;
// 0-index [L, R)
// 区间和 + 单点修改 + 区间加 + 区间乘 + 区间查询，全程不取模
struct SumInfo {
    i64 val;
    i64 len;   // 区间长度
    SumInfo() : val(0), len(0) {}
    SumInfo(i64 val_, i64 len_) : val(val_), len(len_) {}
    SumInfo operator+(const SumInfo& other) {
        return {val + other.val, len + other.len};
    }
};
struct Tag {
    i64 mul, add;
    Tag() : mul(1), add(0) {}
};

struct SegTree {
    int n;
    std::vector<i64> a;
    std::vector<Tag> tag;
    std::vector<SumInfo> tree;

    SegTree(int n_) : n(n_), a(n_), tag(4 * n), tree(4 * n) {}

    void pull(int u) {
        tree[u] = tree[2*u] + tree[2*u+1];
    }
    void push(int u) {
        int lc = 2*u, rc = 2*u+1;

        tag[lc].mul = tag[lc].mul * tag[u].mul;
        tag[lc].add = tag[lc].add * tag[u].mul + tag[u].add;
        tag[rc].mul = tag[rc].mul * tag[u].mul;
        tag[rc].add = tag[rc].add * tag[u].mul + tag[u].add;

        tree[lc].val = tree[lc].val * tag[u].mul + tag[u].add * tree[lc].len;
        tree[rc].val = tree[rc].val * tag[u].mul + tag[u].add * tree[rc].len;

        tag[u] = Tag();
    }
    // [L, R)
    void build(int u, int L, int R) {
        if (L == R - 1) {
            tree[u] = {a[L], 1};
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
    void modify(int u, int L, int R, int pos, i64 val) {
        if (L == R - 1) {
            tree[u] = {val, 1};
            return;
        }
        push(u);
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        if (pos < mid) modify(lc, L, mid, pos, val);
        else modify(rc, mid, R, pos, val);
        pull(u);
    }
    void modify(int pos, i64 val) {
        modify(1, 0, n, pos, val);
    }
    void rangeAdd(int u, int L, int R, int ql, int qr, i64 val) {
        if (ql <= L && R <= qr) {
            tree[u].val = tree[u].val + val * tree[u].len;
            tag[u].add = tag[u].add + val;
            return;
        }
        push(u);
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        if (ql < mid) rangeAdd(lc, L, mid, ql, qr, val);
        if (qr > mid) rangeAdd(rc, mid, R, ql, qr, val);
        pull(u);
    }
    void rangeAdd(int ql, int qr, i64 val) {
        rangeAdd(1, 0, n, ql, qr, val);
    }
    void rangeMul(int u, int L, int R, int ql, int qr, i64 val) {
        if (ql <= L && R <= qr) {
            tree[u].val = tree[u].val * val;
            tag[u].mul = tag[u].mul * val;
            tag[u].add = tag[u].add * val;
            return;
        }
        push(u);
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        if (ql < mid) rangeMul(lc, L, mid, ql, qr, val);
        if (qr > mid) rangeMul(rc, mid, R, ql, qr, val);
        pull(u);
    }
    void rangeMul(int ql, int qr, i64 val) {
        rangeMul(1, 0, n, ql, qr, val);
    }
    SumInfo query(int u, int L, int R, int ql, int qr) {
        if (ql <= L && R <= qr) {
            return tree[u];
        }
        push(u);
        int mid = (L + R) >> 1, lc = 2*u, rc = 2*u+1;
        SumInfo res = {};
        if (ql < mid) res = res + query(lc, L, mid, ql, qr);
        if (qr > mid) res = res + query(rc, mid, R, ql, qr);
        return res;
    }
    i64 query(int ql, int qr) {
        return query(1, 0, n, ql, qr).val;
    }
};
