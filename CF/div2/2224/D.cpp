//Wed May  6 04:00:49 PM CST 2026
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
const i64 MOD = 998244353;

// 单点修改 + 区间查询
// 假设原数组是a
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
    void update(int pos, int val) {
        int x = val - query(pos, pos + 1);
        for (int i = pos + 1; i <= n; i += i & -i) {
            treeA[i] += x;
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
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
i64 inv(i64 a) {
    return qpow(a, MOD - 2) % MOD;
}

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
        std::vector<i64> a(n), b(n), c;
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c.push_back(a[i] * b[j]);
            }
        }
        std::sort(c.begin(), c.end());
        c.erase(std::unique(c.begin(), c.end()), c.end());
        Fenwick bit(c.size() + 1);
        auto getRank = [&](i64 x) -> int {
            return std::lower_bound(c.begin(), c.end(), x) - c.begin();
        };
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int rank = getRank(a[i] * b[j]);
                ans = (ans + i * n - bit.sum(rank + 1)) % MOD; // tot - [0, rank] -> [rank + 1, mx]
            }
            for (int j = 0; j < n; ++j) {
                int rank = getRank(a[i] * b[j]);
                bit.add(rank, 1);
            }
        }
        auto d = a;
        std::sort(d.begin(), d.end());
        d.erase(std::unique(d.begin(), d.end()), d.end()); // mx 2000;
        Fenwick bit2(a.size() + 1);
        auto getRank2 = [&](i64 x) -> int {
            return std::lower_bound(d.begin(), d.end(), x) - d.begin();
        };
        for (int i = 0; i < n; ++i) {
            int rank = getRank2(a[i]);
            ans = (ans - n * (i - bit2.sum(rank + 1))) % MOD;
            bit2.add(rank, 1);
        }
        ans = (ans % MOD + MOD) % MOD;
        std::cout << ans * inv(n) % MOD * inv(n - 1) % MOD << nl;
    }
}
