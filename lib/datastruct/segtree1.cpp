#include <bits/stdc++.h>

using i64 = long long;
// 区间加法 + 区间查询

struct Info {
    i64 sum;
    i64 len;

    Info(i64 sum_ = 0, i64 len_ = 0) : sum(sum_), len(len_) {}
    Info operator+(const Info& other) const {
        return Info(sum + other.sum, len + other.len);
    }
};
struct Tag {
    i64 add;

    Tag(i64 add_ = 0) : add(add_) {}
};
struct SegmentTree {
    int n;
    std::vector<Info> treeA;
    std::vector<Tag> tag;

    SegmentTree(int n_ = 0) : n(n_), treeA(4 * n), tag(4 * n) {}
    void pull(int p) {
        treeA[p] =  treeA[2 * p] + treeA[2 * p + 1];
    }
    void apply(int p, const Tag& v) {
        treeA[p].sum += v.add * treeA[p].len;
        tag[p].add += v.add;
    }
    void push(int p) {
        if (tag[p].add != 0) {
            apply(2 * p, tag[p]);
            apply(2 * p + 1, tag[p]);
            tag[p] = Tag();
        }
    }
    void build(int p, int l, int r, std::vector<i64>& a) {
        if (r - l == 1) {
            treeA[p] = Info(a[l], 1);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * p, l, mid, a);
        build(2 * p + 1, mid, r, a);
        pull(p);
    }
    void build(std::vector<i64>& a) {
        build(1, 0, n, a);
    }
    void add(int p, int l, int r, int ql, int qr, const Tag& v) {
        if (qr <= l || ql >= r) return;
        if (ql <= l && r <= qr) {
            apply(p, v);
            return;
        }
        push(p);
        int mid = (l + r) / 2;
        add(2 * p, l, mid, ql, qr, v);
        add(2 * p + 1, mid, r, ql, qr, v);
        pull(p);
    }
    void add(int ql, int qr, const Tag& v) {
        add(1, 0, n, ql, qr, v);
    }
    Info query(int p, int l, int r, int ql, int qr) {
        if (qr <= l || ql >= r) return Info();
        if (ql <= l && r <= qr) {
            return treeA[p];
        }
        push(p);
        int mid = (l + r) / 2;
        return query(2 * p, l, mid, ql, qr) + query(2 * p + 1, mid, r, ql, qr);
    }
    Info query(int ql, int qr) {
        return query(1, 0, n, ql, qr);
    }
};
