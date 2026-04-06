#include <bits/stdc++.h>
#include <ostream>
using i64 = long long;
using i128 = __int128;
#define nl "\n"
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
        std::function<void(int, int, int)> build = [&] (int p, int l, int r) {
            if (r - l == 1) {
                info[p] = Info(init_vec[l], 1);
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
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
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    SegTree seg(a);
    for (int i = 0; i < m; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            i64 x, y, k;
            std::cin >> x >> y >> k;
            seg.rangeAdd(x - 1, y, k);
        }else if (op == 2) {
            int x, y;
            std::cin >> x >> y;
            std::cout << seg.query(x - 1, y) << nl;
        }
    }
}
