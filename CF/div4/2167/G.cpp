//Wed May 13 04:49:43 PM CST 2026
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

// 单点修改 + 区间查询
// 假设原数组是a
struct Fenwick {
    int n;
    std::vector<i64> treeA;
    
    Fenwick(int n_ = 0) : n(n_) {
        treeA.assign(n + 1, 0);
    }
    void add(int pos, i64 val) {
        for (int i = pos + 1; i <= n; i += i & -i) { 
            treeA[i] = std::max(treeA[i], val);
        }
    }
    // sum(pos) == S[0, pos)
    i64 sum(int pos) {
        i64 res = 0;
        for (int i = pos; i > 0; i -= i & -i) { // 这里不加1 因为我们写的开区间
            res = std::max(res, treeA[i]);
        }
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("sout.txt", "w", stdout);
    #endif
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n), c(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        auto val = a;
        std::sort(val.begin(), val.end());
        val.erase(std::unique(val.begin(), val.end()), val.end());
        auto getRank = [&](int x) -> int {
            return std::lower_bound(val.begin(), val.end(), x) - val.begin();
        };
        i64 tot = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> c[i];
            tot += c[i];
        }
        Fenwick bit(val.size());
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            int rank = getRank(a[i]);
            i64 dp = bit.sum(rank + 1) + c[i]; // [0, rank]
            bit.add(rank, dp);
            ans = std::max(ans, dp);
        }
        std::cout << tot - ans << nl;
    }
}
