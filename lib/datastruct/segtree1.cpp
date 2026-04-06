#include <bits/stdc++.h>
using i64 = long long;
struct Info {
    i64 val;
    i64 len;
    Info() : val(0), len(0) {}
    Info(i64 _v, i64 _len) : val(_v), len(_len) {}
    friend Info operator+(const Info& a, const Info& b) {
        return Info(a.val + b.val, a.len + b.len);
    }
    friend std::ostream& operator<<(std::ostream& os, const Info& rhs) {
        return os << rhs.val;
    }
};
struct SegTree {
    int n;
    std::vector<i64> tag;
    std::vector<Info> info;
    SegTree(int _n) : n(_n), tag(4 * n), info(4 * n) {}
    SegTree(const std::vector<i64>& init_vec) {
        n = init_vec.size();
        tag.assign(4 * n, 0);
        info.resize(4 * n);
        auto build = [&] (auto& self, int p, int l, int r) {
            if (r - l == 1) {
                info[p] = Info(init_vec[l], 1);
                return;
            }
            int m = (l + r) / 2;
            self(self, 2 * p, l, m);
            self(self, 2 * p + 1, m, r);
            pull(p);
        };
        build(build, 1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void add(int p, i64 v) {
        tag[p] += v;
        info[p].val += v * info[p].len;
    }
    void push(int p) {
        if (tag[p]) {
            add(2 * p, tag[p]);
            add(2 * p + 1, tag[p]);
            tag[p] = 0;
        }
    }
    void rangeAdd(int p, int l, int r, int x, int y, i64 v) {
        if (x <= l && y >= r) {
            return add(p, v);
        }
        if (x >= r || y <= l) {
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeAdd(2 * p, l, m, x, y, v);
        rangeAdd(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeAdd(int x, int y, i64 v) {
        rangeAdd(1, 0, n, x, y, v);
    }
    Info query(int p, int l, int r, int x, int y) {
        if (x <= l && y >= r) {
            return info[p];
        }
        if (x >= r || y <= l) {
            return Info();
        }
        int m = (l + r) / 2;
        push(p);
        return query(2 * p, l, m, x, y) + query(2 * p + 1, m, r, x, y);
    }
    Info query(int x, int y) {
        return query(1, 0, n, x, y);
    }
    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v; 
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        }else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int x, const Info& v) {
        modify(1, 0, n, x, v);
    }
};
