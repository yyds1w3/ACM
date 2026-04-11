#include <bits/stdc++.h>
#define nl "\n"
#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 43
#define debug_range(...) 43
#endif
using i64 = long long;
using i128 = __int128;
struct query {
    int l, r, id;
    bool operator<(const query& other) const {
        return r < other.r;
    }
};
struct Fenwick {
    int n;
    std::vector<i64> treeA;
    
    Fenwick(int n_ = 0) : n(n_) {
        treeA.assign(n + 1, 0);
    }
    void add(int pos, int val) {
        for (int i = pos + 1; i <= n; i += i & -i) { 
            treeA[i] += val;
        }
    }
    // sum(pos) == S[0, pos)
    i64 sum(int pos) {
        i64 res = 0;
        for (int i = pos; i > 0; i -= i & -i) { // 这里不加1 因为我们写的开区间
            res += treeA[i];
        }
        return res;
    }
    // query[l, r) = S[0, r) - S[0, l)
    i64 query(int l, int r) {
        return sum(r) - sum(l);
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n, c, m;
    std::cin >> n >> c >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    std::vector<query> q(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].id = i;
    }
    std::sort(q.begin(), q.end());
    std::vector<int> ans(m);
    std::vector<int> lst1(c, -1), lst2(c, -1);
    Fenwick bit(n);
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        auto [l, r, id] = q[i];
        for (;idx < r; idx++) {
            int col = a[idx];
            col--;
            if (lst1[col] != -1) {
                bit.add(lst1[col], 1);
                if (lst2[col] != -1){
                    bit.add(lst2[col], -1);
                }
            }
            lst2[col] = lst1[col];
            lst1[col] = idx;
        }
        ans[id] = bit.query(l, r);
    }
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << nl;
    }
}
