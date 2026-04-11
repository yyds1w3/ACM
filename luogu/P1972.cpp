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
    friend std::ostream& operator<<(std::ostream& os, const query& rhs){
        return (os << rhs.l << " " << rhs.r << " " << rhs.id);
    }
};
struct Fenwick {
    int n;
    std::vector<int> treeA;
    Fenwick(int n_ = 0) : n(n_) {
        treeA.assign(n + 1, 0);
    }
    void add(int pos, int val) {
        for (int i = pos + 1; i <= n; i += i & -i) {
            treeA[i] += val;
        }
    }
    int query(int pos) {
        int res = 0;
        for (int i = pos; i > 0; i -= i & -i) {
            res += treeA[i];
        }
        return res;
    }
};
int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    if (fopen("in.txt", "r")) freopen("in.txt", "r", stdin);
    #endif
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    std::vector<query> q(m);
    for (int i = 0; i < m; ++i)  {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    std::sort(q.begin(), q.end(), [](const query& lhs, const query& rhs){
        return lhs.r < rhs.r;
    });
    std::map<int, int> pos;
    int idx = 0;
    Fenwick bit(n);
    std::vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        auto [l, r, id] = q[i];
        l--;
        while (idx < r) {
            auto it = pos.find(a[idx]);
            if (it != pos.end()) {
                bit.add(it->second, -1);
            }
            bit.add(idx, 1);
            pos[a[idx]] = idx;
            idx++;
        }
        ans[id] = bit.query(r) - bit.query(l);
    }
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << nl;
    }
}
